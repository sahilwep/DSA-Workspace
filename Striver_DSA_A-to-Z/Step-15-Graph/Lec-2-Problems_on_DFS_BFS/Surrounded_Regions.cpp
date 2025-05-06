/*

//  130. Surrounded Regions


//  Problem Link: https://leetcode.com/problems/surrounded-regions/description/


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;

        for(int i = 0; i < 4; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];
            
            if(isValid(r, c) && grid[r][c] == 'O' && !vis[r][c]) {
                dfs(r, c, grid, vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if(grid[i][j] == 'O' && !vis[i][j]) {
                        dfs(i, j, grid, vis);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'O' && !vis[i][j]) {
                    grid[i][j] = 'X';
                }
            }
        }
    }
};