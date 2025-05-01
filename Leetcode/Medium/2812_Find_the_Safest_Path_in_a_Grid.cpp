/*

//  2812. Find the Safest Path in a Grid


//  Problem Statement: 
    -> You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:
        -> A cell containing a thief if grid[r][c] = 1
        -> An empty cell if grid[r][c] = 0

    -> You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.
    -> The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.
    -> Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).
    -> An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.
    -> The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.

        
// Example:
    Example 1:
        Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
        Output: 0

    Example 2:
        Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
        Output: 2

    Example 3:
        Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
        Output: 2



// Observations: 
    -> You are given a grid of size n x n, containing values 0 and 1.
    -> 1 represents a cell with a thief.
    -> 0 represents a free cell you can walk through.
    -> You must travel from the top-left (0, 0) to the bottom-right (n-1, n-1).
    
    -> The "safeness factor" of a path is the "minimum Manhattan distance" from any cell in that path to the nearest thief.
    -> Your task is to return the **maximum safeness factor** among all valid paths from (0, 0) to (n-1, n-1).


    // Intuition and Approach:
        1. Preprocessing - BFS from all thieves:
            -> Treat all thief cells (1's) as sources and perform multi-source BFS.
            -> This assigns each cell its minimum Manhattan distance to the nearest thief.

        2. Path Finding using Max-Heap (Modified Dijkstra):
            -> Use a max-heap to prioritize paths with the maximum minimum safeness factor.
            -> At each step, track the minimum safeness value along the current path.
            -> The first time you reach (n-1, n-1), that path is guaranteed to have the maximum possible safeness factor due to greedy max-heap.


    // Complexity:
        // TC:
            -> BFS: O(n²)
            -> Priority Queue traversal: O(n² * log(n²)) ~ O(n² log n)
        // SC:
            - O(n²) for visited, distance, and queue/heap storage



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;



// Improved MultiSource BFS-Dijkstra's Approach:
class Solution {
private: 
    int n;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < n);}
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        // Early exit if starting or ending point is occupied by a thief
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;

        // Step 1: Multi-source BFS to calculate min distance from any cell to nearest thief
        vector<vector<int>> distance(n, vector<int>(n, 0));
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    visited[i][j] = 1;
                    q.push({0, {i, j}});
                }
            }
        }

        while (!q.empty()) {
            auto [dist, coord] = q.front();
            q.pop();

            int row = coord.first;
            int col = coord.second;
            distance[row][col] = dist;

            for (int d = 0; d < 4; ++d) {
                int newRow = row + dir[d][0];
                int newCol = col + dir[d][1];

                if (isValid(newRow, newCol) && !visited[newRow][newCol]) {
                    visited[newRow][newCol] = 1;
                    q.push({dist + 1, {newRow, newCol}});
                }
            }
        }

        // Step 2: Max-heap to find path with maximum safeness factor
        priority_queue<pair<int, pair<int, int>>> pq; // {minSafenessSoFar, {row, col}}

        vector<vector<int>> seen(n, vector<int>(n, 0));
        pq.push({distance[0][0], {0, 0}});
        seen[0][0] = 1;

        while (!pq.empty()) {
            auto [minSafenessSoFar, coord] = pq.top();
            pq.pop();

            int row = coord.first;
            int col = coord.second;

            // Reached destination
            if (row == n - 1 && col == n - 1) {
                return minSafenessSoFar;
            }

            for (int d = 0; d < 4; ++d) {
                int newRow = row + dir[d][0];
                int newCol = col + dir[d][1];

                if (isValid(newRow, newCol) && !seen[newRow][newCol]) {
                    seen[newRow][newCol] = 1;
                    int newMinSafeness = min(minSafenessSoFar, distance[newRow][newCol]);
                    pq.push({newMinSafeness, {newRow, newCol}});
                }
            }
        }

        return 0; // No valid path
    }
};


// MultiSource BFS-Dijkstra's Approach: naive implementation
class Solution {
private: 
    int n;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // Directions: left, right, up, down
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < n);}
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        // Edge case: when starting or ending cell contains a thief
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return 0;

        // Step 1: Multi-source BFS to calculate distance from each cell to the nearest thief
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<vector<int>> temp(n, vector<int>(n, 0));
        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    vis[i][j] = 1;
                    q.push({0, {i, j}});
                }
            }
        }

        while (!q.empty()) {
            auto [lvl, cor] = q.front();
            q.pop();

            int row = cor.first;
            int col = cor.second;

            temp[row][col] = lvl;

            for (int i = 0; i < 4; ++i) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if (isValid(r, c) && !vis[r][c]) {
                    vis[r][c] = 1;
                    q.push({lvl + 1, {r, c}});
                }
            }
        }

        // Reset visited matrix for path traversal
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                vis[i][j] = 0;
            }
        }

        // Step 2: Max-heap to find safest path with maximum safeness factor
        priority_queue<pair<int, pair<int, pair<int, int>>>> pq;
        pq.push({temp[0][0], {temp[0][0], {0, 0}}}); // {maxSafeness, minCellSoFar, {row, col}}
        vis[0][0] = 1;

        while (!pq.empty()) {
            auto [safeness, other] = pq.top();
            pq.pop();

            int minCellSoFar = other.first;
            int row = other.second.first;
            int col = other.second.second;

            // If reached destination, return the min safeness value along this path
            if ((row * n + col) == (n * n - 1)) return minCellSoFar;

            for (int i = 0; i < 4; ++i) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if (isValid(r, c) && !vis[r][c]) {
                    int newMinCellSoFar = min(minCellSoFar, temp[r][c]);
                    int newSafeness = max(safeness, temp[r][c]);

                    vis[r][c] = 1;
                    pq.push({newSafeness, {newMinCellSoFar, {r, c}}});
                }
            }
        }

        return 0; // No valid path found
    }
};
