/*

//  994. Rotting Oranges


//  Problem Link:   https://leetcode.com/problems/rotting-oranges/


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private: 
    typedef pair<int, pair<int, int>> ppr;
    int n, m;   // dimensions
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // dir: left, right, up, down
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}   // Valid Grid bound Checks
public:
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        // Multi-source BFS:
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<ppr> q;
        int freshCnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {   // rotten oranges
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
                if(grid[i][j] == 1) {   // fresh orange:
                    freshCnt++;
                }
            }
        }

        int rotted = 0;
        int maxLvl = 0;
        while(!q.empty()) {
            auto [lvl, cor] = q.front();
            q.pop();

            int row = cor.first, col = cor.second;
            maxLvl = max(lvl, maxLvl);

            // Explore all 4 directions:
            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                // valid bound & fresh orange & not yet visited
                if(isValid(r, c) && grid[r][c] == 1 && !vis[r][c]) {
                    rotted++;
                    q.push({lvl + 1, {r, c}});
                    vis[r][c] = 1;
                }
            }
        }
        
        // Rotted count check:
        if(rotted != freshCnt) return -1;

        return maxLvl;
    }
};