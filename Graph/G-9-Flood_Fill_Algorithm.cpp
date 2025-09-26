/*

// Flood Fill Algorithm:

// Problem Statement: 
    * You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].
    * To perform a flood fill:
        * Begin with the starting pixel and change its color to color.
        * Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
        * Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
        * The process stops when there are no more adjacent pixels of the original color to update.

    * Return the modified image after performing the flood fill.

// Example:
    Input: 
        sr = 1, sc = 1, color = 2
        image = [[1,1,1]
                ,[1,1,0]
                ,[1,0,1]], 

    Output: [[2,2,2]
            ,[2,2,0]
            ,[2,0,1]]


//  Visualization:
    -> we will be given starting (row, col) of grid, & the color in which we need to color that node...
    -> We need to color all the nodes, that are touching the given nodes, in all possible 4 directions..
    -> We can use DFS, which will help us to color all the adjacent touching nodes, in all 4 direction(up, down, left, right).


// Complexity:
    * TC: O(n*m) 
    * AS: O(n*m)


*/

#include<bits/stdc++.h>
using namespace std;


// Improved: We don't need visited array, because original color & new color are different
class Solution {
private:
    int n, m;   // dimensions
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // right, left, up,  down
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}   // func to check valid bound.
    void fill(int row, int col, int color, int orgClr, vector<vector<int>> &grid) {
        grid[row][col] = color;

        for(int i = 0; i < 4; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];

            if(isValid(r, c) && grid[r][c] == orgClr) {
                fill(r, c, color, orgClr, grid);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        n = grid.size(), m = grid[0].size();

        if(grid[sr][sc] == color) return grid;  // no need to color that..

        int orgClr = grid[sr][sc];
        fill(sr, sc, color, orgClr, grid);

        return grid;
    }
};



// ------------------------------------ Clean With Visited array ------------------------------------
class Solution {    // BFS
private: 
    int n, m;   // grid dimensions
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}   // checks valid bound of grid
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // left, right, up, down
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size(), m = image[0].size();

        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<int, int>> q;
        int orgClr = image[sr][sc];

        q.push({sr, sc});
        vis[sr][sc] = 1;

        while(!q.empty()) { 
            auto [row, col] = q.front();
            q.pop();

            image[row][col] = color;

            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(isValid(r, c) && image[r][c] == orgClr && !vis[r][c]) {
                    vis[r][c] = 1;
                    q.push({r, c});
                }
            }
        }

        return image;
    }
};

class Solution {    // DFS
private: 
    int n, m;   // grid dimensions
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}   // checks valid bound of grid
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // left, right, up, down
    void fill(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int orgClr, int color) {
        grid[row][col] = color;
        vis[row][col] = 1;

        for(int i = 0; i < 4; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];

            if(isValid(r, c) && grid[r][c] == orgClr && !vis[r][c]) {
                fill(r, c, grid, vis, orgClr, color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size(), m = image[0].size();

        int orgClr = image[sr][sc];
        vector<vector<int>> vis(n, vector<int> (m, 0));
        fill(sr, sc, image, vis, orgClr, color);

        return image;
    }
};



// ------------------------------------ Old Solution ------------------------------------
// Using DFS to color all the nodes that are touched with the given node
void dfs(int row, int col, int newColor, vector<vector<int>> &res, vector<vector<int>> &image, int delRow[], int delCol[], int iniColor){
    res[row][col] = newColor;  // first mark given node with given color.

    // getting size of grid:
    int n = image.size();
    int m = image[0].size();
    

    // Check all the 4 direction & call dfs:
    for(int i=0;i<4;i++){
        // getting the new row & col:
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        // checking if they were in range & no yet colored?
        if( nRow >= 0  && nRow < n && nCol >= 0 && nCol < m && 
        image[nRow][nCol] == iniColor && res[nRow][nCol] != newColor){
            dfs(nRow, nCol, newColor, res, image, delRow, delCol, iniColor);
        }
    }
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int iniColor = image[sr][sc];   // initial color of given nodes

    vector<vector<int>> res = image;    // create a copy of image
    
    // all 4 direction:
    /*       

                            (row-1, col)
                                    |
            (row, col-1) <- (row, col) -> (row, col+1)
                                    |
                            (row+1, col)
        -> Possible coordinates of {row, col}
    */
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};

    dfs(sr, sc, color, res, image, delRow, delCol, iniColor);   // calling dfs

    return res; // returning new result image
}