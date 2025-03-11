/*

//  695. Max Area of Island

//  Problem Statement: 
    -> You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
    -> The area of an island is the number of cells with a value 1 in the island.
    -> Return the maximum area of an island in grid. If there is no island, return 0.



// Example: 
    Example 1:
        Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],
                      [0,0,0,0,0,0,0,1,1,1,0,0,0],
                      [0,1,1,0,1,0,0,0,0,0,0,0,0],
                      [0,1,0,0,1,1,0,0,1,0,1,0,0],
                      [0,1,0,0,1,1,0,0,1,1,1,0,0],
                      [0,0,0,0,0,0,0,0,0,0,1,0,0],
                      [0,0,0,0,0,0,0,1,1,1,0,0,0],
                      [0,0,0,0,0,0,0,1,1,0,0,0,0]]
        Output: 6
        Explanation: The answer is not 11, because the island must be connected 4-directionally.

    Example 2:
        Input: grid = [[0,0,0,0,0,0,0,0]]
        Output: 0


// Observations:
    -> We are given 2-d grid, representing some island & waters..
    -> We need to find the islands which has maximum area.
    -> Area is calculated by the number of cells that island possesses..

// Approach:
    -> We can use any DFS/BFS traversal algorithm to fine solution:
    -> Whenever we encounter with any island, we will use Traversal algorithm.
    -> The length it returns, will be our temporary answer until we not explored all the islands.
    -> At last we will return the maximum length of island among all the temporary solution..


// Complexity: 
    -> TC: O(n * m), At max, we are traversing every cell's only once.
    -> SC: O(n * m), because of recursive calls / or queue will store that much cells in worse case..



// ------------------------------------------------------------------------

// BFS implementations: 
    -> Count total number of valid coordinates pushed into queue.
    -> Only valid coordinates will be pushed into the queue.
    // Complexity: 
        -> TC: O(n * m)
        -> SC: O(n * m)

        
// New DFS Implementations: 
    -> Count total number of valid recursive branch get called with DFS.
    -> Every branch will return 1, because for every branch we set "answer = 1".
    // Complexity:  
        -> TC: O(n * m)
        -> SC: O(n * m)


// ------------------------------------------------------------------------

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;



// BFS Implementations: Count total number of valid coordinates pushed into queue.
class Solution {
private: 
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    // coordinates:    left     right   up      down
    bool isValid(int r, int c) { return (r >= 0 && r < n && c >= 0 && c < m);}
    int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        
        int area = 0;


        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            // Total number of times every cells pushed into the queue is our total area.
            area++; // count every cell pushed into queue.

            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];
                
                if(isValid(r, c) && !vis[r][c] && grid[r][c]) {
                    vis[r][c] = 1;

                    q.push({r, c});
                }
            }
        }

        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j]) {
                    maxArea = max(maxArea, solve(i, j, grid, vis));
                }
            }
        }

        return maxArea;
    }
};



// New DFS Implementations: Count total number of valid branch get called with DFS
class Solution {
private: 
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    // coordinates:    left     right   up      down
    bool isValid(int r, int c) { return (r >= 0 && r < n && c >= 0 && c < m);}
    int solve(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis) {
        vis[row][col] = 1;
        int ans = 1;    // for every called branch we set answer value = 1

        for(int i = 0; i < 4; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];

            if(isValid(r, c) && !vis[r][c] && grid[r][c]) { // whenever we have valid constrains:
                ans += solve(r, c, grid, vis);  // call new Branch and add that branch into our parent answer.
            }
        }

        return ans; // last return answer
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j]) {
                    maxArea = max(maxArea, solve(i, j, grid, vis));
                }
            }
        }

        return maxArea;
    }
};



// OLD Naive DFS Solution:
class Solution {
private:
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int dfs(int row, int col, vector<vector<int>>& grid){   // TC: O(n * m)
        int n = grid.size();
        int m = grid[0].size();

        int ans = grid[row][col];
        grid[row][col] = 0; // mark as visited, by overwriting the original grid cell as '0'

        // Traverse in all 4-directions:
        for(int i=0;i<4;i++){
            int r_ = row + dir[i][0];
            int c_ = col + dir[i][1];

            // Check bound, & land:
            if(r_ >= 0 && r_ < n && c_ >= 0 && c_ < m && grid[r_][c_] == 1){
                ans += dfs(r_, c_, grid);
            }
        }

        return ans;
    }
    int bfs(int row, int col, vector<vector<int>>& grid){   // TC: O(n * m)
        int n = grid.size();
        int m = grid[0].size();

        int ans = grid[row][col];
        queue<pair<int, int>> q;

        grid[row][col] = 0;
        q.push({row, col});

        while(!q.empty()){
            auto [row, col] = q.front();    // get the coordinates from the front of the queue.
            q.pop();    // remove that item from queue.


            // Check adjacent cells:
            for(int i=0;i<4;i++){
                int r_ = row + dir[i][0];
                int c_ = col + dir[i][1];

                // Check valid bound & is-land:
                if(r_ >= 0 && r_ < n && c_ >= 0 && c_ < m && grid[r_][c_] == 1){
                    ans += grid[r_][c_];    // include in answer
                    grid[r_][c_] = 0;   // mark that as visited, by overwriting the original grid cell as '0'
                    q.push({r_, c_});   // push that coordinates into queue.
                }
            }
        }

        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // For multiple Component:
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){    // when-ever we encounter with land:
                    // int tempAns = dfs(i, j, grid);
                    int tempAns = bfs(i, j, grid);
                    ans = max(ans, tempAns);    // ans, will be the maximum among all the temp-answers..
                }
            }
        }

        return ans;
    }
};