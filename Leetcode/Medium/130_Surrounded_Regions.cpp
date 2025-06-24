/*

//  130. Surrounded Regions

//  Problem Statement: 
    -> You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
        -> Connect: A cell is connected to adjacent cells horizontally or vertically.
        -> Region: To form a region connect every 'O' cell.
        -> Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.

    -> To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 
// Example:
    Example 1:
        Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
        Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
        Explanation: In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

    Example 2:
        Input: board = [["X"]]
        Output: [["X"]]


// Observation:
    -> If someone is on the boundary, that is where he cannot be covered.
    -> 'O' are bound to be surrounded by 'X' then only we can fill it with 'X'
    -> If set of 'X' is connected by a boundary, it cannot be surrounded by 'X'.


    // Approach:
        -> If we start with boundary 0's and traverse all the connected 0's, & mark then they will not be converted, then our job is done.
        -> Create a temporary matrix & assume all the value are convertble, so fill it with 'X'.
        -> Iterate in boundary & use dfs and mark all the connected nodes with '0's

        // Complexity: 
            -> TC: O(n)
            -> SC: O(n)
    

    // DSU Approach: 
        -> Connect Components
        -> Get the details of every components & invalid ones
        -> filter out invalid components
        -> Now overwrite the valid ones with 'X'

        // Complexity: 
            -> TC: O(n)
            -> SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// DSU Solution: TC: O(n * m)
class DSU {
private: 
    vector<int> size, parent;
public: 
    DSU (int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]); // path compression
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;  // already connected
        // connect smaller comp to larger ones: 
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
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) { return (r >= 0 && r < n && c >= 0 && c < m);};
public:
    void solve(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();

        // Connect the nodes & form connected components:
        DSU ds(n * m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'O') {
                    int cellNo = i * m + j; // get the cell no

                    // explore in all 4 directions: 
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

        // Get The details of all & invalid Components: 
        unordered_set<int> comp;
        unordered_set<int> invalidComp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'O') {
                    int cellNo = i * m + j;         // get the cell no
                    int par = ds.ultPar(cellNo);    // get their ultimate parent
                    comp.insert(par);               // store that into total components
                    
                    // get the invalid component details:
                    if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                        invalidComp.insert(par);
                    }
                }
            }
        }

        // Now Filter out invalid components from total valid components: 
        unordered_set<int> valid;
        for(auto &val: comp) {
            if(!invalidComp.count(val)) {
                valid.insert(val);
            }
        }

        // Now Overwrite The Original Grid with Valid cells:
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'O') {
                    int cellNo = i * m + j;
                    int par = ds.ultPar(cellNo);

                    // this cell lies in valid comp: overwrite it.
                    if(valid.count(par)) {
                        grid[i][j] = 'X';
                    }
                }
            }
        }

        // Now all done.
    }
};


class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<char>>& temp, vector<vector<int>>& vis){
        vis[row][col] = 1;      // mart that current node as visited
        temp[row][col] = 'O';   // mark that node as not possible to convert
        
        int n = board.size();
        int m = board[0].size();
        
        int delRow[] = {-1, +1, 0, 0};
        int delCol[] = {0, 0, -1, +1};
        
        // iterate in all 4 directions:
        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            // checking valid range, valid values, & not-visited yet
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && board[nRow][nCol] == 'O' && !vis[nRow][nCol]){
                dfs(nRow, nCol, board, temp, vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<char>> temp(n, vector<char> (m, 'X'));
        vector<vector<int>> vis(n, vector<int> (m, 0));

        // Iterate in corners & mark all 'O's as not replicable
        // first & last row:
        for(int i=0;i<m;i++){
            // first row:
            if(board[0][i] == 'O' && !vis[0][i]){
                dfs(0, i, board, temp, vis);
            }
            // last row:
            if(board[n-1][i] == 'O' && !vis[n-1][i]){
                dfs(n-1, i, board, temp, vis);
            }
        }
        
        // First & last Col:
        for(int i=0;i<n;i++){
            // first row:
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i, 0, board, temp, vis);
            }
            // last row:
            if(board[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(i, m-1, board, temp, vis);
            }
        }
        
        board = temp;   // last assign temp value to board
    }
};