/*

//  1254. Number of Closed Islands

//  Problem Statement: 
    -> Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
    -> Return the number of closed islands.



// Example:

    Example 1:

        Input: grid = [[1,1,1,1,1,1,1,0],
                    [1,0,0,0,0,1,1,0],
                    [1,0,1,0,1,1,1,0],
                    [1,0,0,0,0,1,0,1],
                    [1,1,1,1,1,1,1,0]]
        Output: 2
        Explanation: Islands in gray are closed because they are completely surrounded by water (group of 1s).

    Example 2:

        Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
        Output: 1

    Example 3:

        Input: grid = [[1,1,1,1,1,1,1],
                    [1,0,0,0,0,0,1],
                    [1,0,1,1,1,0,1],
                    [1,0,1,0,1,0,1],
                    [1,0,1,1,1,0,1],
                    [1,0,0,0,0,0,1],
                    [1,1,1,1,1,1,1]]
        Output: 2


// Observations: 
    -> Closed islands are those islands, which were totally surrounded by water fro all the outer directions, (left, right, up, down).
    -> The island that were the part of the boundary cells we can't consider them as closed islands, because, they were not closed by water..
    -> So, initially we need to find those island that were part of the boundary cells, & mark them as visited, & make sure to mark as visited to all possible island that were connected to the boundary cell.
    -> Now at last, we can run any traversal algorithm, & count the number of call we are running from the parent calls, That were our number of closed islands.


// Approach:
    -> First we need to make sure to mark all boundary islands as visited, so that we can count the correct number of closed islands.
    -> We can use any traversal algorithm like BFS/DFS, & perform the visiting of every possible island.


// Complexity: 
    -> TC: O(n * m), because at-max max we are visiting every cell only once.
    -> SC: O(n * m), because of visited grid, & stack can have at max O(n * m) calls in worse case....


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    // Directions: (0, 0)      left,    right,    up,       down
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    int n, m;   // grid, dimensions
    bool validBound(int row, int col){  // Function to compute the valid bound.
        if(row >= 0 && row < n && col >= 0 && col < m) return 1;
        else return 0;
    } 
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis) {   // DFS, mark all possible Islands.
        vis[row][col] = 1;  // mark that current called cell as visited.

        // Explore adjacent cells & mark them as visited:
        for(int i = 0; i < 4; i++) {
            int r_ = row + dir[i][0];
            int c_ = col + dir[i][1];

            // Check bound, not visited & island:
            if(validBound(r_, c_) && !vis[r_][c_] && !grid[r_][c_]) {
                dfs(r_, c_, grid, vis); // get for another calls.
            }
        }
    }
    void bfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis) {   // BFS Impl: O(n * m)
        vis[row][col] = 1;

        queue<pair<int, int>> q;
        q.push({row, col});

        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            // Traverse all possible directions: 
            for(int i=0;i<4;i++){
                int r_ = row + dir[i][0];
                int c_ = col + dir[i][1];

                // Check bound, not-yet visited, & land:
                if(validBound(r_, c_) && !vis[r_][c_] && !grid[r_][c_]){
                    vis[r_][c_] = 1;    // mark as visited
                    q.push({r_, c_});   // push the coordinates into the queue.
                }
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0)); // visited will restrict to revisiting the same cell

        // Initial Configurations:  mark all corner island as visited:
        for(int i=0;i<n;i++){   // for row:
            if(grid[i][0] == 0 && !vis[i][0]){  // first column:
                dfs(i, 0, grid, vis);
                // bfs(i, 0, grid, vis);
            }

            if(grid[i][m-1] == 0 && !vis[i][m-1]){  // last column:
                dfs(i, m-1, grid, vis);
                // bfs(i, m-1, grid, vis);
            }
        }
        for(int i=0;i<m;i++){   // for col:
            if(grid[0][i] == 0 && !vis[0][i]){  // first row:
                dfs(0, i, grid, vis);
                // bfs(0, i, grid, vis);
            }

            if(grid[n-1][i] == 0 && !vis[n-1][i]){  // last row:
                dfs(n-1, i, grid, vis);
                // bfs(n-1, i, grid, vis);
            }
        }


        // Now, check for closed islands:
        int closedIsland = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0 && !vis[i][j]){  // if cell were the land & not-yet visited:
                    dfs(i, j, grid, vis);
                    // bfs(i, j, grid, vis);
                    closedIsland++; // everytime, whenever dfs get called we will increment the closedIsland.
                }
            }
        }

        return closedIsland;
    }
};