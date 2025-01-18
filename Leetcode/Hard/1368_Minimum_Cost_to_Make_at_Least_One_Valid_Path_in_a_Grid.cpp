/*

//  1368. Minimum Cost to Make at Least One Valid Path in a Grid


//  Problem Statement: 
    -> Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:
        -> '1' which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
        -> '2' which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
        -> '3' which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
        -> '4' which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])

    -> Notice that there could be some signs on the cells of the grid that point outside the grid.
    -> You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.
    -> You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.
    -> Return the minimum cost to make the grid have at least one valid path.

 

// Example:

    Example 1:
        Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
        Output: 3
        Explanation: You will start at point (0, 0).
            The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
            The total cost = 3.

    Example 2:
        Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
        Output: 0
        Explanation: You can follow the path from (0, 0) to (2, 2).

    Example 3:
        Input: grid = [[1,2],[4,3]]
        Output: 1



// Observations:
    -> We need to find all possible paths from the start to the destination.
    -> For each path, calculate the cost, and among all paths, choose the one with the minimum cost.
    

// BruteForce Solution -> DFS Backtrack Approach:
    -> Use a backtracking approach to explore all possible paths recursively. This is implemented using a DFS function.
    -> This approach will result in TLE (Time Limit Exceeded) for large grids, as it explores all possible paths.

    // Complexity
        -> TC =  O(4^n×m)
            -> '4' is direction which we are try to visit in every decision tree.
            -> (n*m) grid, which we visit in every possible cases.
        -> SC =  O(n×m)



// Efficient Solution -> Dijkstra Approach: 
    -> We will use plain dijkstra with some modification.
    -> We need to traverse in grid direction, so we will use those modification according to our needs.
    -> also we need minimum cost, so we will observe where we need to change our direction in order to get the minimum cost.
    
    // Complexity:
        -> TC: O((n * m) * log(n * m))
        -> SC: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;



// Efficient Solution -> Dijkstra Approach: 
class Solution {
private:
    // Directions for moving in the grid: right, left, down, and up
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();    // Number of rows in the grid
        int m = grid[0].size(); // Number of columns in the grid

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq; // declare min heap or integers
        vector<vector<int>> result(n, vector<int> (m, INT_MAX));   // this will store result.

        pq.push({0, 0, 0});  // push starting values into queue: cost, srcRow, srcCol
        result[0][0] = 0; // this is the cost of reaching source node.

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            // Get the current values:
            int currCost = curr[0]; // current Cost
            int currRow = curr[1];  // current row
            int currCol = curr[2];  // current col

            if(currRow == n-1 && currCol == m-1) return result[n-1][m-1];   // this will return once we reach to last node, stops further exploration.

            // Check Possible directions:
            for(int i = 0; i < 4 ; i++){
                int nRow = currRow + dir[i][0]; // new row
                int nCol = currCol + dir[i][1]; // new col

                // Check if the new cell (nRow, nCol) is within bounds:
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m ) {
                    int gridDir = grid[currRow][currCol];   // this is the current grid direction, where it's saying to go..
                    int dirCost = (gridDir - 1 != i) ? 1 : 0;   // if we are not getting the same direction as our direction want to go, then add '1', else add '0'
                    int newCost = currCost + dirCost;   // this will our new cost for next move..

                    if(newCost < result[nRow][nCol]){   // if new cost is less than the current grid cost.
                        result[nRow][nCol] = newCost;   // update with new lesser cost.
                        pq.push({newCost, nRow, nCol}); // push that into priority queue.
                    }
                }
            }
        }

        return result[n-1][m-1];    // return the minimum cost of result to reach last cell of grid.
    }
};


// BruteForce Solution -> DFS Backtrack Approach:
class Solution {
private:
    // Directions for moving in the grid: right, left, down, and up
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 
    int n, m; // Grid dimensions

    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>> &vis, int cost){
        // Base case: If we have reached the destination cell, return the current cost
        if (row == n - 1 && col == m - 1) {
            return cost;
        }

        vis[row][col] = true;   // Mark the current cell as visited to avoid revisiting during this path
        int minCost = INT_MAX; // Initialize the minimum cost to the largest possible value

        // Explore all possible directions (right, left, down, up)
        for (int i = 0; i < 4; i++) {
            int i_ = row + dir[i][0]; // Calculate the new row index
            int j_ = col + dir[i][1]; // Calculate the new column index

            // Check if the new cell (i_, j_) is within bounds and has not been visited
            if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && !vis[i_][j_]) {

                // // Calculate extraCost logic 1: Explained View
                // int extraCost = 0;
                // if(grid[row][col] == 1 && i != 0 ||
                //    grid[row][col] == 2 && i != 1 ||
                //    grid[row][col] == 3 && i != 2 ||
                //    grid[row][col] == 4 && i != 3 ){
                //     extraCost = 1;  // mark extra cost take as '1'
                // }

                // Calculate ExtraCost logic 2: Shorter logic
                int extraCost = (grid[row][col] - 1 != i) ? 1 : 0;  // Calculate the extra cost for deviating from the intended direction
                int nextCost = cost + extraCost;    // The new cost includes the current cost and the extra cost for this step
                minCost = min(minCost, dfs(i_, j_, grid, vis, nextCost));   // Recursively explore the next cell and update the minimum cost
            }
        }

        vis[row][col] = false; // In DFS, we explore all possible paths recursively. When backtracking, unmarking a cell as visited (i.e., setting vis[row][col] = false) ensures that we can revisit this cell through other paths if needed. This is necessary because:
        return minCost; // Return the minimum cost among all possible paths from the current cell
    }
public:
    int minCost(vector<vector<int>>& grid) {
        n = grid.size();    // Number of rows in the grid
        m = grid[0].size(); // Number of columns in the grid

        vector<vector<bool>> vis(n, vector<bool>(m, false));    // Visited array to track the cells visited during a path

        return dfs(0, 0, grid, vis, 0); // Start exploring from the top-left corner with an initial cost of 0, { Structure: dfs(startRow, startCol, grid, visited, cost)}
    }
};