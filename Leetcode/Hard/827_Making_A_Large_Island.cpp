/*

//  827. Making A Large Island


//  Problem Statement: 
    -> You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
    -> Return the size of the largest island in grid after applying this operation.
    -> An island is a 4-directionally connected group of 1s.
 

// Example:
    Example 1:
        Input: grid = [[1,0],[0,1]]
        Output: 3
        Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

    Example 2:
        Input: grid = [[1,1],[1,0]]
        Output: 4
        Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

    Example 3:
        Input: grid = [[1,1],[1,1]]
        Output: 4
        Explanation: Can't change any 0 to 1, only one island with area = 4.

 
// Observations: 
    -> We are given a grid where 1-> land & 0-> water
    -> We can change at-max one water cell to land..
    -> We need to find the maximum area of land by converting one water to land


// BruteForce Solution:
    -> Try converting each water cell ('0') to land ('1') one by one.
    -> For each conversion, run a full DFS to compute the largest connected island.
    -> Restore the cell back to water after computation.
    -> TC: O(n^4) due to repeated DFS calls for each cell.

// Better Solution:
    -> Compute the largest island without flipping any water cell.
    -> Iterate through all water cells ('0') and try flipping them to land ('1').
    -> For each flip, compute the maximum island area by running DFS.
    -> Restore the cell back to water after checking.
    -> TC: O(n^3) due to running DFS multiple times.

// Efficient Solution:
    -> First, mark and store all islands using unique IDs and their respective areas using DFS.
    -> Iterate through all water cells ('0') and check their adjacent island IDs.
    -> Sum up the areas of unique neighboring islands to compute the largest possible island.
    -> Use an unordered_set to ensure each island contributes only once.
    -> TC: O(n^2) as each cell is processed at most twice.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Solution:
class Solution {
private:
    // Directions for moving in 4 possible ways: left, right, up, down.
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int n;  // Grid size

    // Helper function to check if a cell is within grid boundaries.
    bool isValid(int row, int col) {
        return (row >= 0 && row < n && col >= 0 && col < n);
    }

    // DFS function to compute the area of an island, marking cells with a unique ID.
    int maxArea(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int uniqueId) {
        grid[row][col] = uniqueId;  // Assign unique ID to the island.
        vis[row][col] = 1;  // Mark as visited.
        int area = 1;

        // Explore all four possible directions.
        for (int i = 0; i < 4; i++) {
            int r_ = row + dir[i][0];
            int c_ = col + dir[i][1];

            // If valid and part of the island (grid value = 1), continue DFS.
            if (isValid(r_, c_) && grid[r_][c_] == 1 && !vis[r_][c_]) {
                area += maxArea(r_, c_, grid, vis, uniqueId);
            }
        }
        return area;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));  // Visited grid.
        unordered_map<int, int> mp;  // Map to store island ID and its area.
        int uniqueId = 2;  // Start unique IDs from 2 (0 & 1 are reserved for water and land).
        int maxIslandSize = 0; // Stores the largest island area found initially.

        // Step 1: Identify and mark all islands with unique IDs and compute their areas.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int area = maxArea(i, j, grid, vis, uniqueId);
                    mp[uniqueId] = area;  // Store island area.
                    maxIslandSize = max(maxIslandSize, area);  // Track largest island size.
                    uniqueId++;  // Increment unique ID for next island.
                }
            }
        }

        int ans = maxIslandSize; // Initialize answer with max island found without changes.

        // Step 2: Try converting each '0' to '1' and compute the largest possible island.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {  // Consider converting this water cell to land.
                    unordered_set<int> uniqueIslands; // Store unique island IDs in 4 directions.
                    for (int k = 0; k < 4; k++) {
                        int r_ = i + dir[k][0];
                        int c_ = j + dir[k][1];
                        if (isValid(r_, c_) && grid[r_][c_] > 1) {
                            uniqueIslands.insert(grid[r_][c_]);
                        }
                    }
                    
                    // Calculate the new potential island size.
                    int newIslandSize = 1; // Include the converted land cell.
                    for (int id : uniqueIslands) {
                        newIslandSize += mp[id]; // Add sizes of unique neighboring islands.
                    }
                    ans = max(ans, newIslandSize); // Update max island size.
                }
            }
        }
        
        return ans; // Return the largest possible island size.
    }
};


// Better Solution: 
class Solution {
private:
    vector<vector<int>> dir = {{0, -1},{0, 1}, {-1, 0}, {1, 0}};
    int n;
    bool isValid(int row, int col){
        return (row >= 0 && row < n && col >= 0 && col < n);
    }
    int maxArea(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int area = 1;

        for(int i=0;i<4;i++){
            int r_ = row + dir[i][0];
            int c_ = col + dir[i][1];

            if(isValid(r_, c_) && grid[r_][c_] == 1 && !vis[r_][c_]){
                area += maxArea(r_, c_, grid, vis);
            }
        }

        return area;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();

        // Precompute the maxArea without changing any '0' to '1' & calculate max-Area:
        int ans = 0;
        vector<vector<int>> vis(n, vector<int> (n, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int tempAns = maxArea(i, j, grid, vis);
                    ans = max(tempAns, ans);
                }
            }
        }


        // Now check-only when we got '0', just change it to '1', & compute max-Area:
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    grid[i][j] = 1; // change that grid cell as land:

                    vis = vector<vector<int>> (n, vector<int> (n, 0));  // reset the visited:
                    
                    int tempAns = maxArea(i, j, grid, vis);
                    ans = max(ans, tempAns);

                    grid[i][j] = 0; // reset that cell as water
                } 
            }
        }

        return (ans == 0) ? n*n : ans;
    }   
};


// BruteForce Solution:
class Solution {
private:
    vector<vector<int>> dir = {{0, -1},{0, 1}, {-1, 0}, {1, 0}};
    int n;
    bool isValid(int row, int col){
        return (row >= 0 && row < n && col >= 0 && col < n);
    }
    int maxArea(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int area = 1;

        for(int i=0;i<4;i++){
            int r_ = row + dir[i][0];
            int c_ = col + dir[i][1];

            if(isValid(r_, c_) && grid[r_][c_] == 1 && !vis[r_][c_]){
                area += maxArea(r_, c_, grid, vis);
            }
        }

        return area;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();


        int ans = 0;
        bool isWater = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    vector<vector<int>> vis(n, vector<int> (n, 0));
                    isWater = true;
                    grid[i][j] = 1;
                         for(int i_=0;i_<n;i_++){
                            for(int j_=0;j_<n;j_++){
                                if(!vis[i_][j_] && grid[i_][j_] == 1){
                                    int tempAns = maxArea(i_, j_, grid, vis);
                                    ans = max(ans, tempAns);
                                }
                            }
                        }
                    grid[i][j] = 0;

                } 
            }
        }

        if(isWater == 0) return n*n;

        return ans;
    }   
};