/*

//  542. 01 Matrix


//  Problem Link: https://leetcode.com/problems/01-matrix/description/ 


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private: 
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    typedef pair<int, pair<int, int>> ppr;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        
        // Nearest '0' for each cell:
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<ppr> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!grid[i][j]) {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()) {
            auto [lvl, cor] = q.front();
            q.pop();

            int row = cor.first, col = cor.second;
            grid[row][col] = lvl;

            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(isValid(r, c) && grid[r][c] == 1 && !vis[r][c]) {
                    vis[r][c] = 1;
                    q.push({lvl + 1, {r, c}});
                }
            }
        }

        return grid;
    }
};