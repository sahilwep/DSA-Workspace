/*

//   G-13. Distance of nearest cell having 1

//  Problem statement:
    * Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
    * The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, 
    * and i2, j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.


// Example:
    Example 1:
        Input: 
        grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
        Output: 
        {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
        Explanation: 
        The grid is-
        0 1 1 0 
        1 1 0 0 
        0 0 1 1 
        - 0's at (0,0), (0,3), (1,2), (1,3), (2,0) and (2,1) are at a distance of 1 from 1's at (0,1), (0,2), (0,2), (2,3), (1,0) and (1,1) respectively.

    Example 2:
        Input: 
        grid = {{1,0,1},{1,1,0},{1,0,0}}
        Output: 
        {{0,1,0},{0,0,1},{0,1,2}}
        Explanation: 
        The grid is-
        1 0 1
        1 1 0
        1 0 0
        - 0's at (0,1), (1,2), (2,1) and (2,2) are at a  distance of 1, 1, 1 and 2 from 1's at (0,0), (0,2), (2,0) and (1,1) respectively.


// Approach:
    -> We will use two matrix:
        -> visited: to maintain the record of visited nodes.
        -> dist: final matrix that will contains the distance of cell having '1'.
    
    -> Initialize the BFS queue with all cells containing 1, & mark these cells as visited and initialize their distance as '0'
    -> keep removing every node from queue until queue is not empty:
        -> extract every node row, col, & step information..
        -> Update their distance in dist matrix.
        -> Check all possible 4 direction, & if any of the node is not is not visited, push that node into queue, with adding 1 extra step.
    
    -> Last return the dist matrix.


// Complexity:
    * TC: O(n*m)
    * AS: O(n*m)


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the distance of the nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();           // Number of rows in the grid.
        int m = grid[0].size();        // Number of columns in the grid.

        vector<vector<int>> vis(n, vector<int>(m, 0));      // `vis` is a matrix to keep track of visited cells to avoid processing them multiple times.
        vector<vector<int>> dist(n, vector<int>(m, 0));    // `dist` is a matrix to store the distance of each cell from the nearest 1.

        // Queue to facilitate BFS traversal.
        // Each element in the queue is a pair: 
        //   - First: a pair of integers representing the cell's row and column indices.
        //   - Second: the current distance of the cell from the nearest 1.
        queue<pair<pair<int, int>, int>> q;

        // Initialize the BFS queue with all cells containing 1.
        // Mark these cells as visited and initialize their distance as 0.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({{i, j}, 0});  // Push cell coordinates and distance 0.
                    vis[i][j] = 1;        // Mark this cell as visited.
                } else {
                    vis[i][j] = 0;        // Unvisited cells will remain 0 in `vis`.
                }
            }
        }

        // Define all possible moves in 4 directions: up, down, left, and right.
        int delRow[] = {-1, +1, 0, 0};  // Row changes for the 4 directions.
        int delCol[] = {0, 0, -1, +1};  // Column changes for the 4 directions.

        // Start BFS traversal.
        while (!q.empty()) {
            // Extract the front element of the queue.
            int row = q.front().first.first;  // Current cell's row index.
            int col = q.front().first.second; // Current cell's column index.
            int step = q.front().second;      // Current distance from the nearest 1.
            q.pop();                          // Remove the front element from the queue.

            // Update the distance matrix for the current cell.
            dist[row][col] = step; 

            // Traverse all 4 possible directions from the current cell.
            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];   // Calculate the new row index.
                int nCol = col + delCol[i];   // Calculate the new column index.

                // Check if the new position is within bounds and not visited.
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && vis[nRow][nCol] == 0) {
                    vis[nRow][nCol] = 1;              // Mark the new cell as visited.
                    q.push({{nRow, nCol}, step + 1}); // Push the new cell into the queue with incremented distance.
                }
            }
        }

        return dist; // Return the final distance matrix after BFS traversal.
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
        cout << "~" << "\n";
    }

    return 0;
}