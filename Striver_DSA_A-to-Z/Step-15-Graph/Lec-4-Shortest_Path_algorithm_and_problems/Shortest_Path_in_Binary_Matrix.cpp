/*

//  Shortest Path in Binary Matrix

//  Problem Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private: 
    typedef pair<int, pair<int, int>> ppr;
    int n;
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < n);}
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>> vis(n, vector<int> (n, 0));
        queue<ppr> q;

        q.push({1, {0, 0}});
        vis[0][0] = 1;

        while(!q.empty()) {
            auto [lvl, cor] = q.front();
            q.pop();

            int row = cor.first, col = cor.second;
            if((row * n + col) == (n * n - 1)) return lvl;

            for(int i = -1; i <= +1; i++) {
                for(int j = -1; j <= +1; j++) {
                    int r = row + i;
                    int c = col + j;

                    if(isValid(r, c) && grid[r][c] == 0 && !vis[r][c]) {
                        vis[r][c] = 1;
                        q.push({lvl + 1, {r, c}});
                    }
                }
            }
        }
        
        return -1;
    }
};