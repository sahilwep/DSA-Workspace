/*

//  Number Of Enclaves


//  Problem Statement: 
    * You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
    * A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
    * Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.


Example 1:
    Input:
    grid[][] = {{0, 0, 0, 0},
                {1, 0, 1, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0}}
    Output:
    3
    Explanation:
    0 0 0 0
    1 0 1 0
    0 1 1 0
    0 0 0 0
    The highlighted cells represents the land cells.

Example 2:
    Input:
    grid[][] = {{0, 0, 0, 1},
                {0, 1, 1, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 1},
                {0, 1, 1, 0}}
    Output:
    4
    Explanation:
    0 0 0 1
    0 1 1 0
    0 1 1 0
    0 0 0 1
    0 1 1 0
    The highlighted cells represents the land cells.



*/

#include <bits/stdc++.h>
using namespace std;

// DFS Approach:
class Solution_DFS {
private:
    vector<int> delRow = {-1, +1, 0, 0};
    vector<int> delCol = {0, 0, -1, +1};
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis){
        vis[row][col] = 1;  // mark as visited

        int n = grid.size();
        int m = grid[0].size();

        // iterate in all possible 4 directions:
        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            // Check bound, is-land, not-visited yet
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && !vis[nRow][nCol]){
                dfs(nRow, nCol, grid, vis);
            }
        }
    }
public:
    int numberOfEnclaves(vector<vector<int>> &grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        // Iterate in first & last row:
        for(int i=0;i<m;i++){
            // first row:
            if(grid[0][i] == 1 && !vis[0][i]){
                dfs(0, i, grid, vis);
            }
            // last row:
            if(grid[n-1][i] == 1 && !vis[n-1][i]){
                dfs(n-1, i, grid, vis);
            }
        }

        // Iterate in first & last col:
        for(int i=0;i<n;i++){
            // first col:
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(i, 0, grid, vis);
            }
            // last col:
            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                dfs(i, m-1, grid, vis);
            }
        }

        // Last check for unvisited 1's & count them:
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};




// BFS Approach:
class Solution_BFS {
private:
    vector<int> delRow = {-1, +1, 0, 0};
    vector<int> delCol = {0, 0, -1, +1};
    void bfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;    // use queue DS -> queue<row, col>
        q.push({row, col});         // push the given nodes:
        vis[row][col] = 1;          // mark that given node as visited

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // iterate & check in all the 4-directions;
            // Check Bound, is-land, not-visited Yet
            for(int i=0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && !vis[nRow][nCol]){
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        // Iterate in first & last row:
        for(int i=0;i<m;i++){
            // first row:
            if(grid[0][i] == 1 && !vis[0][i]){
                bfs(0, i, grid, vis);
            }
            // last row:
            if(grid[n-1][i] == 1 && !vis[n-1][i]){
                bfs(n-1, i, grid, vis);
            }
        }

        // Iterate in first & last col:
        for(int i=0;i<n;i++){
            // first col:
            if(grid[i][0] == 1 && !vis[i][0]){
                bfs(i, 0, grid, vis);
            }
            // last col:
            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                bfs(i, m-1, grid, vis);
            }
        }

        // Last check for unvisited 1's & count them:
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};




int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution_BFS obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    
    cout << "~" << "\n";
    }
}
