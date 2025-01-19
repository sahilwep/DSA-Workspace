/*

//  407. Trapping Rain Water II


//  Problem Statement: 
    -> Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.


// Example:
    Example 1:
        Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
        Output: 4
        Explanation: After the rain, water is trapped between the blocks.
        We have two small ponds 1 and 3 units trapped.
        The total volume of water trapped is 4.

    Example 2:
        Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
        Output: 10



     Problem: Trapping Rain Water II (2D version)
    
// Observation:
    -> The input is an m x n integer matrix `heightMap` representing the height of each unit cell in a 2D elevation map.
    -> We need to return the volume of water that can be trapped after raining.

    Example:
        Input: heightMap = [[1,4,3,1,3,2], [3,2,1,3,2,4], [2,3,3,2,3,1]]
        Output: 4
        Explanation: After the rain, water is trapped between the blocks in two ponds of volumes 1 and 3, totaling 4.

// Approach:
    -> Consider each cell in the matrix as a building block, and water can be trapped inside based on the height of the surrounding boundary cells.
    -> The core idea is to calculate the trapped water for cells **inside the boundary** while ensuring water flows to the **minimum height** of its adjacent boundary cells.

// Steps:
    1. Boundary cells can never trap water. These will form the initial boundary.
    2. Use a **min-heap (priority queue)** to process cells in increasing order of their height.
    3. Push all boundary cells into the heap, marking them as visited.
    4. Process each cell in the heap:
        -> For each cell, calculate the water trapped based on the difference between the current cell's height and its adjacent cells.
        -> Push unvisited neighbors into the heap, updating their heights to the maximum of the current boundary height and the neighbor's original height.
        -> Mark the neighbor as visited to avoid reprocessing.

// Complexity:
    -> TC:  O(n * m * log(n * m)) because we process every cell exactly once and each heap operation takes O(log(n * m)).
    -> SC:  O(n * m) for the visited array and heap storage.



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
    typedef pair<int, pair<int, int>> pp; 
    
    // Directions to traverse the neighbors: up, down, left, right
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // Step 1: Handle edge cases
        int n = heightMap.size();    // Number of rows
        int m = heightMap[0].size(); // Number of columns
        if (n <= 2 || m <= 2) return 0; // No space for water to be trapped

        // Priority queue (min-heap) to store boundary cells
        priority_queue<pp, vector<pp>, greater<>> boundaryCell;

        // Visited array to track processed cells
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Step 2: Push all boundary cells into the heap
        // Process leftmost and rightmost columns
        for (int row = 0; row < n; row++) {
            for (int col : {0, m - 1}) { // First and last column
                boundaryCell.push({heightMap[row][col], {row, col}});
                visited[row][col] = true; // Mark as visited
            }
        }

        // Process topmost and bottommost rows
        for (int col = 0; col < m; col++) {
            for (int row : {0, n - 1}) { // First and last row
                if (!visited[row][col]) { // Avoid duplicate entries
                    boundaryCell.push({heightMap[row][col], {row, col}});
                    visited[row][col] = true; // Mark as visited
                }
            }
        }

        // Step 3: Process cells in the heap to calculate trapped water
        int water = 0; // Total trapped water

        while (!boundaryCell.empty()) {
            // Extract the cell with the smallest height
            pp p = boundaryCell.top();
            boundaryCell.pop();

            int height = p.first;             // Current cell height
            int row = p.second.first;         // Row index
            int col = p.second.second;        // Column index

            // Explore all 4 neighbors (up, down, left, right)
            for (vector<int> d : dir) {
                int i_ = row + d[0];          // Neighbor row
                int j_ = col + d[1];          // Neighbor column

                // Check if the neighbor is valid and not yet visited
                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && !visited[i_][j_]) {
                    // Calculate trapped water for the neighbor
                    // Water trapped = max(0, boundary height - neighbor height)
                    water += max(height - heightMap[i_][j_], 0);

                    // Update neighbor's height and push into the heap
                    // The new height is the maximum of the current boundary height and the neighbor's height
                    boundaryCell.push({max(height, heightMap[i_][j_]), {i_, j_}});
                    visited[i_][j_] = true; // Mark as visited
                }
            }
        }

        return water; // Return the total trapped water
    }
};

