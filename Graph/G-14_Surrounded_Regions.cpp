/*

//  G-14. Surrounded Regions


//  Problem Statement:
    -> Given a matrix mat where every element is either 'O' or 'X'. Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.
    -> A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.


// Examples:

    Input: mat = 
        [['X', 'X', 'X', 'X'], 
        ['X', 'O', 'X', 'X'], 
        ['X', 'O', 'O', 'X'], 
        ['X', 'O', 'X', 'X'], 
        ['X', 'X', 'O', 'O']]
    Output: 
        [['X', 'X', 'X', 'X'], 
        ['X', 'X', 'X', 'X'], 
        ['X', 'X', 'X', 'X'], 
        ['X', 'X', 'X', 'X'], 
        ['X', 'X', 'O', 'O']]
    Explanation: We only changed those 'O' that are surrounded by 'X'

    Input: mat = 
        [['X', 'O', 'X', 'X'], 
        ['X', 'O', 'X', 'X'], 
        ['X', 'O', 'O', 'X'], 
        ['X', 'O', 'X', 'X'], 
        ['X', 'X', 'O', 'O']]
    Output: 
        [['X', 'O', 'X', 'X'], 
        ['X', 'O', 'X', 'X'], 
        ['X', 'O', 'O', 'X'], 
        ['X', 'O', 'X', 'X'], 
        ['X', 'X', 'O', 'O']]
    Explanation: There's no 'O' that's surround by 'X'.

    Input: mat = 
        [['X', 'X', 'X'], 
        ['X', 'O', 'X'], 
        ['X', 'X', 'X']]
    Output: 
        [['X', 'X', 'X'], 
        ['X', 'X', 'X'], 
        ['X', 'X', 'X']]
    Explanation: There's only one 'O' that's surround by 'X'.


// Observation:
    -> If someone is on the boundary, that is where he cannot be covered.
    -> 'O' are bound to be surrounded by 'X' then only we can fill it with 'X'
    -> If set of 'X' is connected by a boundary, it cannot be surrounded by 'X'.


    // Approach:
        -> If we start with boundary 0's and traverse all the connected 0's, & mark then they will not be converted, then our job is done.
        -> Create a temporary matrix & assume all the value are convertble, so fill it with 'X'.
        -> Iterate in boundary & use dfs and mark all the connected nodes with '0's


// Complexity:
    TC: O(n * m)
    SC: O(n * m) 


// Extra: Approach 2
    -> We can solve this question without using "temp" matrix, we can use original "mat" & we will use "vis"
    -> We can use condition that during the traversal if any element is not yet visited & it's 'O's then mark that element as changeable
    -> at the end we can directly overwrite the original matrix with condition : if(!vis[i][j] && mat[i][j] == 0) mat[i][j] = 'X'



// Advance DSU Approach: 
    -> replace all O's with X, if O's are surrounded by X in all 4 directions.
    -> Using DSU:
        -> Connect all the components:
        -> Make two group: Valid & Invalid
            -> Valid Group contains all the border touching O's, because at worse it can have only 3 direction surrounded.
            -> Invalid Group contains all the 0's surrounded by X in all 4 directions.
        -> At last replace all the O's whose lies in Invalid group

        // Complexity:
            -> TC: O(n * m)
            -> SC: O(n * m)


*/


#include <bits/stdc++.h>
using namespace std;


// DSU Based Solution:
class DSU {
private: 
    vector<int> size, parent;
public:
    DSU (int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]);
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};


class Solution {
private: 
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // left, right, up, down
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
public:
    vector<vector<char>> fill(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        // Step 1: Connect all the components:
        DSU ds(n * m);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'O') { // for every O's
                    int cellNo = i * m + j;
                    
                    // Connect with all the adjacent cells:
                    for(int k = 0; k < 4; k++) {
                        int r = i + dir[k][0];
                        int c = j + dir[k][1];
                        
                        if(isValid(r, c) && grid[r][c] == 'O') {
                            int adjCellNo = r * m + c;
                            
                            ds.Union(cellNo, adjCellNo);
                        }
                    }
                    
                }
            }
        }
        
        
        // Step 2: Get the details of Invalid & Valid cells:
        unordered_set<int> valid, invalid;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'O') { // for every O's
                    int cellNo = i * m + j;
                    int uPar = ds.ultPar(cellNo);
                    
                    invalid.insert(uPar);
                    
                    // If we are at boundary of grid: insert as valid cells
                    if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                        valid.insert(uPar);
                    }
                }
            }
        }
        
        // Step 3: Filter Out Invalid:
        for(auto& it: valid) {
            if(invalid.count(it)) {
                invalid.erase(it);
            }
        }
        
        // Step 4: Now Overwrite the invalid Cell's with 'X':
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'O') {
                    int cellNo = i * m + j;
                    int uPar = ds.ultPar(cellNo);
                    
                    if(invalid.count(uPar)) {   // if that cell is invalid: overwrite it with "X"
                        grid[i][j] = 'X';
                    }
                }
            }
        }
        
        return grid;    // last return the grid
    }
};


// DFS Based Solution:
class Solution {
private:
    void dfs(int row, int col, vector<vector<char>> &mat, vector<vector<char>> &temp, vector<vector<int>> &vis){
        vis[row][col] = 1;      // mart that current node as visited
        temp[row][col] = 'O';   // mark that node as not possible to convert
        
        int n = mat.size();
        int m = mat[0].size();
        
        int delRow[] = {-1, +1, 0, 0};
        int delCol[] = {0, 0, -1, +1};
        
        // iterate in all 4 directions:
        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            // checking valid range, valid values, & not-visited yet
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && mat[nRow][nCol] == 'O' && !vis[nRow][nCol]){
                dfs(nRow, nCol, mat, temp, vis);
            }
        }
    }
public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat.size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<vector<char>> temp(n, vector<char> (m, 'X')); // create temp mat, & fill all with default value 'X'
        
        
        // Iterate in corners & mark all 'O's as not replicable
        // first & last row:
        for(int i=0;i<m;i++){
            // first row:
            if(mat[0][i] == 'O' && !vis[0][i]){
                dfs(0, i, mat, temp, vis);
            }
            // last row:
            if(mat[n-1][i] == 'O' && !vis[n-1][i]){
                dfs(n-1, i, mat, temp, vis);
            }
        }
        
        // First & last Col:
        for(int i=0;i<n;i++){
            // first row:
            if(mat[i][0] == 'O' && !vis[i][0]){
                dfs(i, 0, mat, temp, vis);
            }
            // last row:
            if(mat[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(i, m-1, mat, temp, vis);
            }
        }
        
        return temp;    // last return modified matrix
    }
};


// DFS Based Solution 2:
class Solution_Approach_2 {
private:
    void dfs(int row, int col, vector<vector<char>> &mat, vector<vector<int>> &vis){
        vis[row][col] = 1;      // mart that current node as visited
        
        int n = mat.size();
        int m = mat[0].size();
        
        int delRow[] = {-1, +1, 0, 0};
        int delCol[] = {0, 0, -1, +1};
        
        // iterate in all 4 directions:
        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            // checking valid range, valid values, & not-visited yet
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && mat[nRow][nCol] == 'O' && !vis[nRow][nCol]){
                dfs(nRow, nCol, mat, vis);
            }
        }
    }
public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat.size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));

        // Iterate in corners & mark all 'O's as not replacable
        // first & last row:
        for(int i=0;i<m;i++){
            // first row:
            if(mat[0][i] == 'O' && !vis[0][i]){
                dfs(0, i, mat, vis);
            }
            // last row:
            if(mat[n-1][i] == 'O' && !vis[n-1][i]){
                dfs(n-1, i, mat, vis);
            }
        }
        
        // First & last Col:
        for(int i=0;i<n;i++){
            // first row:
            if(mat[i][0] == 'O' && !vis[i][0]){
                dfs(i, 0, mat, vis);
            }
            // last row:
            if(mat[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(i, m-1, mat, vis);
            }
        }
        
        // last mark the elelement that can be changeable
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;    // last return modified matrix
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(mat);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}