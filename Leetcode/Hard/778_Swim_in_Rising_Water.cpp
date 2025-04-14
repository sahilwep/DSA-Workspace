/*

//  778. Swim in Rising Water


//  Problem Statement: 
    -> You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
    -> The rain starts to fall. At time t, the depth of the water everywhere is t. 
    -> You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. 
    -> Of course, you must stay within the boundaries of the grid during your swim.
    -> Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).
 
// Example:
    Example 1:
        Input: grid = [[0,2],[1,3]]
        Output: 3
        Explanation:
        At time 0, you are in grid location (0, 0).
        You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
        You cannot reach point (1, 1) until time 3.
        When the depth of water is 3, we can swim anywhere inside the grid.

    Example 2:
        Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
        Output: 16
        Explanation: The final route is shown.
        We need to wait until time 16 so that (0, 0) and (4, 4) are connected.


// Observations: 
    -> We are given a grid of size n x n
    -> We need to find the shortest time to reach the destinations (n-1, n-1) from (0, 0)
    -> Every cell of grid[i][j] has some elevation at point (i, j)
    -> Rain start fall, At time 't' depth of water at every cell is 't'
    -> We can explore in all 4 directions, if and only if the elevations of both the adjacent cells individually at most 't'.
    -> We can swim infinite distance in zero time, within the grid boundary.
    -> Return the least time to reach the destinations (n-1, n-1) from (0, 0).


    // key Observations: 
        -> The higher the elevation of a cell, the longer you must wait to step into it.
        -> You must find a path from (0, 0) to (n-1, n-1) such that the "maximum elevation"
        -> along the path is minimized — since that determines how long you must wait.
        -> This is similar to Dijkstra’s algorithm: process cells with the "lowest elevation cost" first.

    // Dijkstra's Solution: 

            Input: grid = [[0,2],[1,3]]
            Output: 3

                    [0,2]
                    [1,3]
                
                -> Starting point: (0, 0)
                -> t = 0 it fills
                -> To move (0, 1) we need to wait for the time t = 2, so that current cell will be filled, & we can move to the (0, 1)
                -> OR to move (1, 0), we need to wait for the time t = 1, so that the curent cell will be filled, & we can move to the (1, 0).
                -> Next when we are at (0, 1) || (1, 0) -> to move (1, 1) we need to wait at max t = 3 so that the curent cell will be filled & we can travel to the next position...


        -> In Simple If we observe, we need to only consider the height of every cells from the starting point..
        -> Height elevations should be minimum...
        -> Dijkstra's will help to find the destinations with the minimum elevations of height during the all possible path.
        -> Process only minimum elevations among all the path taken:
            -> Dijkstra's min heap Structure:  <Height, <row, col>> 
            -> Consideration factor = height

        -> Process dijkstra's for grid & build answer.


        // Complexity: 
            -> TC:  O(n^2 * log(n)) 
            -> SC: O(n^2)




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Dijkstra's Solution:
class Solution {
private:
    using Cell = pair<int, pair<int, int>>; // <elevation, <row, col>>
    int n;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // Left, Right, Up, Down
    bool isValid(int r, int c) { return (r >= 0 && r < n && c >= 0 && c < n);}   // Check if the given cell is within grid bounds
public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        
        priority_queue<Cell, vector<Cell>, greater<>> pq;               // Min-heap to process cells by the minimum elevation required to reach them
        vector<vector<int>> minElevation(n, vector<int>(n, INT_MAX));   // Stores the minimum time (elevation) required to reach each cell

        // Start from the top-left cell
        pq.push({grid[0][0], {0, 0}});
        minElevation[0][0] = grid[0][0];

        while(!pq.empty()) {
            auto [currentElevation, pos] = pq.top();
            pq.pop();

            int row = pos.first;
            int col = pos.second;

            if(row == n - 1 && col == n - 1) return currentElevation;   // If we reached the bottom-right cell, return the elevation required to get here

            // Explore the 4-directionally adjacent cells
            for(int i = 0; i < 4; ++i) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(isValid(r, c)) {
                    int nextElevation = max(currentElevation, grid[r][c]);  // Elevation needed to move to the next cell

                    // If this path offers a lower elevation path to the cell, process it
                    if (nextElevation < minElevation[r][c]) {
                        minElevation[r][c] = nextElevation;

                        pq.push({nextElevation, {r, c}});
                    }
                }
            }
        }

        return -1;  // Should never be reached if the input guarantees a path
    }
};
