/*

//  2658. Maximum Number of Fish in a Grid


//  Problem Statement: 
    -> You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:
        -> A land cell if grid[r][c] = 0, or
        -> A water cell containing grid[r][c] fish, if grid[r][c] > 0.
    -> A fisher can start at any water cell (r, c) and can do the following operations any number of times:
        -> Catch all the fish at cell (r, c), or
        -> Move to any adjacent water cell.
    -> Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.
    -> An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

 
// Example: 

    Example 1:

        Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
        Output: 7
        Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.

    Example 2:

        Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
        Output: 1
        Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish. 


// Observations:
    -> we are given grid that represent some land & water with some fish..
    -> If grid[i][j] == 0, considered as land, except considered as number of fish in that water.
    -> We need to find the maximum number of fish we can collect by traversing the grid.
    -> We can move in all four directions(left, right, up, down)
    -> If we start with the grid cell which has no land & start collecting fish until we won't collect them all..
    -> & Compare it with all possible collections, then we can have the maximum collected fish at last.



// DFS Solution: 
    -> We need to treat this as multiple component, because the land, can divide it into multiple islands..
    -> we can start traversing in grid, while we check if grid cell has not yet visited & it's not the land, then we can call for dfs & get the fish from all the adjacent cells..
    -> At last we will return the maximum collections only..

    // Complexity:
        -> TC: O(n * m), because with visited grid, at max for every cell we are visiting only once.
        -> SC: O(n * m), calls in stack in worse case.


// BFS Solution: 
    -> We need to treat this as multiple component, because the land, can divide it into multiple islands..
    -> we can start traversing in grid, while we check if grid cell has not yet visited & it's not the land, then we can add it into answer & push that coordinates into queue, & mark that cell as visited.
    -> At last we will return the maximum collections only..

    // Complexity:
        -> TC: O(n * m), at max we are visiting every cell only once.
        -> SC: O(n * m), at worse we can have all cells in grid...


*/

#include<bits/stdc++.h>
using namespace std;

// Improved DFS: 
class Solution {
private: 
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) { return (r >= 0 && r < n && c >= 0 && c < m);}
    int fishCnt(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int ans = grid[row][col];

        for(int i = 0; i < 4; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];

            if(isValid(r, c) && !vis[r][c] && grid[r][c] > 0) {
                ans += fishCnt(r, c, grid, vis);
            }
        }

        return ans;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        int maxFish = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] && !vis[i][j]) {
                    maxFish = max(maxFish, fishCnt(i, j, grid, vis));
                }
            }
        }

        return maxFish;
    }
};


// DFS Solution:
class Solution {
private:
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};   // possible directions
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;  // mark that current cell as visited.
        int totalFish = grid[row][col]; // get the current cell fish as totalFish for now..

        // Iterate in all possible Directions:
        for(int i=0;i<4;i++){
            int r_ = row + dir[i][0];
            int c_ = col + dir[i][1];

            // Check valid bound, not visited yet & it should not be water.
            if(r_ >= 0 && r_ < n && c_ >= 0 && c_ < m && !vis[r_][c_] && grid[r_][c_] != 0){
                totalFish += dfs(r_, c_, grid, vis);    // call dfs & get the answer & add it to totalFish.
            }
        }

        return totalFish;   // return totalFish for dfs calls.
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<int, int>> q;

        // NOTE: We are calling dfs multiple times, because we are assuming this as multiple componenet, because if grid cells are not connected, we may need to call dfs for multiple times.
        // Check for maximum TotalFish:
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // If cell is not yet visited & it's not land, then call for dfs:
                if(!vis[i][j] && grid[i][j] > 0){
                    int tempAns = dfs(i, j, grid, vis); // call dfs & get the temporary answer
                    ans = max(ans, tempAns);    // compare it with all the possible finding.
                }
            }
        }
        
        return ans; // return answer.
    }
};



// BFS Solution:
class Solution {
private:
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};   // possible directions
    int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        
        // Initially Configurations:
        vis[row][col] = 1;      // mark that cell as visited
        q.push({row, col});     // push that starting cell into queue.
        int totalFish = grid[row][col]; // add that cell value into totalFish count.
        
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            // Check Adjacent cells:
            for(int i=0;i<4;i++){
                int r_ = row + dir[i][0];
                int c_ = col + dir[i][1];

                // Check valid bound, not yet visited, & not land:
                if(r_ >= 0 && r_ < n && c_ >= 0 && c_ < m && !vis[r_][c_] && grid[r_][c_] > 0){
                    totalFish += grid[r_][c_];  // add that grid value into total fish count
                    vis[r_][c_] = 1;            // mark that cell as visited
                    q.push({r_, c_});           // push it into queue.
                }
            }
        }

        return totalFish;   // returning the totalFish count
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<int, int>> q;

        // NOTE: We are calling bfs multiple times, because we are assuming this as multiple componenet, because if grid cells are not connected, we may need to call bfs for multiple times.
        // Check for maximum TotalFish:
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // If cell is not yet visited & it's not land, then call for dfs:
                if(!vis[i][j] && grid[i][j] > 0){
                    int tempAns = bfs(i, j, grid, vis); // call bfs & get the temporary answer
                    ans = max(ans, tempAns);    // compare it with all the possible finding.
                }
            }
        }
        
        return ans; // return answer.
    }
};