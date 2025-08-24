/*

// 1162. As Far from Land as Possible


// Problem Statement:
    -> Given an n x n grid containing only values 0 and 1, where:
        -> 0 represents water
        -> 1 represents land
    -> Find a water cell such that its distance to the nearest land cell is maximized, and return the distance.
    -> If no land or water exists in the grid, return -1.
    -> The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.


// Example:
    Example 1:
        Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
        Output: 2
        Explanation: The cell (1,1) is as far as possible from all the land with distance 2.

    Example 2:
        Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
        Output: 4
        Explanation: The cell (2,2) is as far as possible from all the land with distance 4.


// Approach:
    -> Use a multi-source BFS (Breadth-First Search) approach.
    -> Push all land cells into the queue as the starting points.
    -> Perform BFS to update distances for water cells.
    -> The maximum distance encountered during BFS traversal is our answer.

    
// Complexity:
    -> TC: O(n^2), Each cell is processed once in BFS.
    -> SC: O(n^2), Queue and visited array store all cells in the worst case.

*/

#include <bits/stdc++.h>
using namespace std;


// BFS - level By level style processing:
/*

// Observations:
    -> multi-source BFS
    -> Return the max level it can reach.

*/

class Solution {
private: 
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
public:
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        // Initially push all the 1's into queue:
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            bool isLvlFound = false;

            while(size--) { // process every level one-by-one:
                auto [row, col] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int r = row + dir[i][0];
                    int c = col + dir[i][1];

                    if(isValid(r, c) && grid[r][c] == 0 && !vis[r][c]) {
                        vis[r][c] = 1;
                        q.push({r, c});
                        isLvlFound = true;
                    }
                }
            }

            if(isLvlFound) level++;
        }

        return (level == 0) ? -1 : level;   // if level is '0 return -1 : else return max lvl
    }
};


// BFS Old Style: 
class Solution {
private:
    int n;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) { return (r >= 0 && r < n && c >= 0 && c < n);}
public:
    int maxDistance(vector<vector<int>>& grid) {

        n = grid.size();
        queue<pair<int, pair<int, int>>> q; // {distance, {row, col}}
        vector<vector<int>> vis(n, vector<int>(n, 0)); // Visited array

        // Push all land cells into the queue and mark them visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({0, {i, j}}); // Land cells start with distance 0
                    vis[i][j] = 1;
                    grid[i][j] = 0; // Overwrite land with 0 (will hold distances during BFS)
                }
            }
        }

        int maxDist = -1; // Store the maximum distance found
        
        // Perform BFS to propagate distances to water cells
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int step = it.first; // Current distance from the nearest land cell
            int row = it.second.first;
            int col = it.second.second;

            maxDist = max(maxDist, step); // Update max distance
            
            // Explore 4 possible directions
            for (int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                // If the new cell is valid, not visited, and is water (0)
                if (isValid(r, c) && !vis[r][c] && grid[r][c] == 0) {
                    vis[r][c] = 1; // Mark as visited

                    grid[r][c] = step + 1; // Update grid with distance value

                    q.push({step + 1, {r, c}}); // Push next cell into queue
                }
            }
        }

        // If maxDist is 0, it means there's no valid water cell, return -1
        return (maxDist == 0) ? -1 : maxDist;
    }
};
