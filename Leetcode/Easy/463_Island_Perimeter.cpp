/*

//  463. Island Perimeter


//  Problem Statement: 
    -> You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
    -> Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
    -> The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.


// Example:
    Example 1:
        Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
        Output: 16
        Explanation: The perimeter is the 16 yellow stripes in the image above.

    Example 2:
        Input: grid = [[1]]
        Output: 4

    Example 3:
        Input: grid = [[1,0]]
        Output: 4


// Observations:
    -> If we observe This Question carefully, we need to find the Perimeter..
    -> Perimeter, are only those part of the cell, which are strongly connected to water or the boundary of the Grid.
    -> So, we need to Every possible direction, when we are moving, it they were water, or boundary cell.
    -> We just need to modify the traversal algorithm a bit..
    -> We can solve this by BFS/DFS any..

    // Approach: 
        -> When we are checking the bound, if they were out of the range, we need to count them as well.
        -> When we are checking the cells, if they were water, we need to count them as well..
        -> Rest wor, conventional DFS/BFS implementations..

    
    
// key-Finding: 
    -> Whenever, we have given some sort of grid, where we need to find the island, water, or anything...
    -> If we are Using any traversal algorithm like BFS/DFS, Make sure to treat that grid as Multiple component of graph..
    -> Because, this will make sure to traverse all possible cells, if they are not strongly connected..


// Complexity: 
    -> TC: O(n * m)
        -> Because, at max we are traversing every cell of grid only once..
    -> SC: O(n * m)
        -> We are using visited array which will cost of size (n * m), Auxilary space.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;

class Solution {
private:
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    // Directions: (0, 0):      left,    right,     up,     down
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;  // mark as visited:

        int ans = 0;
        // Check All possible Directions of grid:
        for(int i=0;i<4;i++){
            int r_ = row + dir[i][0];
            int c_ = col + dir[i][1];

            // Check the Possible valid Boundary:
            if(r_ >= 0 && r_ < n && c_ >= 0 && c_ < m){
                if(grid[r_][c_] == 1){  // if we are having Land, we can go for possible traversal to explore the next nodes..
                    if(!vis[r_][c_]){
                        ans += dfs(r_, c_, grid, vis);
                    }
                }
                else{   // else if we have water encounter, we will count as well..
                    ans += 1;
                }
            }
            else{   // if Traversal going to visit the boundary, we will count that as well.
                ans += 1;
            }
        }

        return ans;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0)); // visited grid, to restrict us from re-visiting the same cell


        int ans = 0;
        // Iterations, for multiple Components:
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int tempAns = dfs(i, j, grid, vis);
                    ans += tempAns; // we need to count all possible perimeters.
                }
            }
        }

        return ans; // return answer
    }
};