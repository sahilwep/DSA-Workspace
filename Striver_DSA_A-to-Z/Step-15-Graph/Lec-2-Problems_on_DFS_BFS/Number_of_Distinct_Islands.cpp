/*

//  Number of Distinct Islands

//  Problem link: https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1


// Observations:
    -> We will have to store the shape of unique island.
    -> And from that we will have to return the distinct island..


    // Approach: 
        -> Island are grid[i][j] = 1
        -> Store the shape coordinate int the set.
        -> shape should be build upon the coordinates
        -> We can store the shape for every island by subtracting from their base coordinates..
        

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private: 
    int n, m;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // up, down, left right
    bool isValid(int r, int c) { return (r >= 0 && r < n && c >= 0 && c < m);}
    void dfs(int row, int col, int bRow, int bCol, vector<vector<int>> &grid, vector<vector<int>>& vis, vector<pair<int, int>>& shape) {
        vis[row][col] = 1;
        
        shape.push_back({(bRow - row), (bCol - col)});  // store shape, by subtracting from the base
        
        // Explore 4 directions: 
        for(int i = 0; i < 4; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];
            
            if(isValid(r, c) && grid[r][c] && !vis[r][c]) {
                dfs(r, c, bRow, bCol, grid, vis, shape);
            }
        }
    }
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        set<vector<pair<int, int>>> ans;
            
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] && !vis[i][j]) {
                    vector<pair<int, int>> shape;
                    dfs(i, j, i, j, grid, vis, shape);
                    ans.insert(shape);
                }
            }
        }
        
        return ans.size();
    }
};