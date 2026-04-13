/*

//  1568. Minimum Number of Days to Disconnect Island


//  Problem Statement: 
    - You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.
    - The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
    - In one day, we are allowed to change any single land cell (1) into a water cell (0).
    - Return the minimum number of days to disconnect the grid.

//  Example:

    Example 1:
        Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
        Output: 2
        Explanation: 

                0   1   1   0           0   1   0   0
                0   1   1   0   ->      0   0   1   0
                0   0   0   0           0   0   0   0

            We need at least 2 days to get a disconnected grid.
            Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.

    Example 2:
        Input: grid = [[1,1]]
        Output: 2
        Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.



// Observations:
    - Given n x n grid with 1 = land, and 0 = water.
    - island is 4 directionally connected in group of lands.
    - grid is said to be connected if we have exactly one island, otherwise is said disconnected.
    - In one day we are allowed to change any single land cell '1' into a water cell '0'
    - Return the minimum number of days to disconnected the grid.

    // Visualization:
        Grid:
            0   0   0   0
            0   1   1   0
            0   1   1   0
            0   1   1   0
            0   1   1   0
            0   0   0   0

        Output:
            0   0   0   0
            0   1   1   0
            0   0   0   0
            0   1   1   0
            0   1   1   0
            0   0   0   0

        - We have to achieve the configurations of grid, where we can have atleast 2 island
        - If grid have multiple components, there's no need to disconnect anything, we are good with that.
        - If grid contains single island, we just need to separate the island in a way so that we will remove minimal as possible.

        // More Observations:
            - Using DSU we can find out how many connected component we have initially
            - If we have more have atleast 2 islands, don't need to disconnect anything.
            - If we have to single island:
                - We need to find the minimum separation of island so that we can separate into two components.
            - DSU will help us to find the multiple components.
                - But problem is not finding the multiple components, it more the number of removal.
            - SCC will help us to 
                - Using SCC we can find the Separations points which will break the graph, but it's working more on directed graph, and solving in grid make it's complex.
            
            - If we already have the multiple components, we don't need to disconnected anything => '0'
            - If we we have single components:
                - We just need to find the single cell which will break the graph into multiple components.
                - Eg:
                    - here we just need to separate the single middle one to disconnect

                                        1                   1
                                    1   1   1               1
                                        1                   1

                - Other Possibility:
                    - Let's say we have this:
                        - We just need to separate this single component into two:

                            1   1   1   1               1   1   1   1
                            1   1   1   1               1   1   1   1
                            1   1   1   1       =>      1   1   1   0
                            1   1   1   1               1   1   0   1

                        - Just two cell configured and we are done..

            - Conclusion:
                - If already separated: 0
                - If Single:
                    - Check single breakout point: if found return '1'
                    - Else return 2
            
            // Approach:
                - Initially using DFS we can find the total number of components.
                - If we have more than '1' island or 0 island: return '0'
                - If we have exactly '1' island:
                    - We have two case: 
                        - Case 1: single cell removal will make grid into two island.
                            - First convert, every land cell into water & check total number of component
                            - If we are able to make atleast 2 island, return 1
                            - Or if if we have '0' island then also return 1
                            - we can use (n^2 * m^2), because the constrains are less (1 <= m, n <= 30)
                        - Case 2: two cells are converted.
                            - Now, we need exactly '2' cell's to convert single components into two.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    int n, m;   // grid dimensions, 
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // dir: left, right, above, below
    bool isValidDir(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}    // finding valid directions.
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {   // TC: O(n * m)
        vis[row][col] = 1;

        // Explore in all 4 directions:
        for(int i = 0; i < 4; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];

            if(isValidDir(r, c) && grid[r][c] == 1 && vis[r][c] == 0) {
                dfs(r, c, grid, vis);
            }
        }
    }
    int totalComponent(vector<vector<int>>& grid) { // TC: O(n * m), because using visited

        int comp = 0;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == 0) {
                    dfs(i, j, grid, vis);
                    comp++;
                }
            }
        }

        return comp;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        // Check Total numbers of islands:      TC: O(n * m)
        int comp = totalComponent(grid);

        if(comp == 0) return 0; // no island found.
        if(comp > 1) return 0;  // we already have multiple islands.

        // We have single Island, now find the separation points:
        // Case 1: Single separation point: make every 1's as 0's and try counting the connected islands.       TC: O(n^ * m^2)
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0; // make the current cell as '0'
                    
                    // Now find if we have more than two component or not?
                    int comp = totalComponent(grid);
                    if(comp == 0) return 1;     // comp == '0', we need to remove that island, NO ISLAND
                    if(comp > 1) return 1;      // We found the loose separation point.
                    
                    grid[i][j] = 1; // revert it back to original cell
                }
            }
        }
        
        // Now, we don't have single separation point, we can need 2 cells to disconnect.
        return 2;
    }
};