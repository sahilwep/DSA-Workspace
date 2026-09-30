/*

//  934. Shortest Bridge


//  Problem Statement: 
    - You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
    - An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
    - You may change 0's to 1's to connect the two islands to form one island.
    - Return the smallest number of 0's you must flip to connect the two islands.

//  Example:

    Example 1:
        Input: grid = [[0,1],[1,0]]
        Output: 1

    Example 2:
        Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
        Output: 2

    Example 3:
        Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
        Output: 1




// Observations:
    - given n x m binary matrix grid where 1 = land, 0 = water.
    - island is 4 directionally connected of 1's not connected to any ohter 1's.
        - there are exactly two island in grid.
    - you may change 0's to 1's to connect the two island to form one island.
    - return the smallest number of 0's you must flip to connect the two islands.
    - Example:

            0   [1]
            1   0

                    we require '1'
        
            0   1   0
            0   0   0
            0   0   1

                    we require '2'

            1   1   1   1   1
            1   0   0   0   1
            1   0   1   0   1
            1   0   0   0   1
            1   1   1   1   1

                    we require '1'
        
    // Approach:    
        - We need to find the minimum distance to reach from one island to another.
        - We will start any one of the island:
            - we will push all the nodes into queue, 
            - so that we can process BFS and find the minimum distance, 
            - as moving cost is 1, and thought it's constant, So BFS will be Optimal choice to find the minimum distance.
            - We can use any BFS/DFS to push all those nodes from first island into queue.
        - Once we will have the queue filled with all the first island nodes:
            - we will process BFS level-wise:
                - and we will travel on path '0', and grow our BFS-level
                - and once we hit any '1' that is not yet visited, means it's the part of second island.
                - we will immediately return the answer.
                
        // Complexity:
            - TC: O(n * m)
            - SC: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    int n, m;   // grid dimensions.
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};    // dir: left, right, above, below.
    bool isValidDim(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        vis[row][col] = 1;
        q.push({row, col});

        // Explore adj neighbors:
        for(auto &[x, y]: dir) {
            int r = row + x;
            int c = col + y;

            if(isValidDim(r, c) && grid[r][c] == 1 && !vis[r][c]) {
                dfs(r, c, vis, grid, q);
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Start from any island: and push all the cells into queue:
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            bool flag = false;
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    dfs(i, j, vis, grid, q);    // run only once.
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }

        // Now process BFS to find the min-Distance:
        int lvl = 0;
        while(!q.empty()) {
            int size = q.size();
            cout << lvl << endl;

            while(size--) {
                auto [row, col] = q.front();
                q.pop();

                // Explore adjacent neighbors:
                for(auto &[x, y]: dir) {
                    int r = row + x;
                    int c = col + y;

                    if(isValidDim(r, c) && !vis[r][c]) {
                        
                        // Find the destinations:
                        if(grid[r][c] == 1) {
                            return lvl; // total number of grid cells:
                        }

                        // else travel on '0', and expand BFS lvls
                        if(grid[r][c] == 0) {
                            q.push({r, c});
                            vis[r][c] = 1;
                        }
                    }
                }
            }

            lvl++;
        }   

        return -1;  // island not found.
    }
};