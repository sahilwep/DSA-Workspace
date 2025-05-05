/*

//  733. Flood Fill

//  https://leetcode.com/problems/flood-fill/description/


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    int n, m;   // dimensions
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // dir: left, right, up, down
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}   // Valid Grid bound Checks
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int clr, int origClr) {
        vis[row][col] = 1;
        grid[row][col] = clr;

        for(int i = 0; i < 4; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];

            if(isValid(r, c) && grid[r][c] == origClr && !vis[r][c]) {
                dfs(r, c, grid, vis, clr, origClr);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size(), m = image[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        int origClr = image[sr][sc];
        
        dfs(sr, sc, image, vis, color, origClr);

        return image;
    }
};