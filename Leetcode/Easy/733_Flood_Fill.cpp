/*

//  733. Flood Fill


// Problem Statement:
    -> You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

    -> To perform a flood fill:

        -> Begin with the starting pixel and change its color to color.
        -> Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
        -> Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
        -> The process stops when there are no more adjacent pixels of the original color to update.

    -> Return the modified image after performing the flood fill.


// Example:
    Example 1:
        Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
        Output: [[2,2,2],[2,2,0],[2,0,1]]
        Explanation:
            From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
            Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.

    Example 2:
        Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
        Output: [[0,0,0],[0,0,0]]
        Explanation:
            The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.


// Approach:
    -> We are given row, col of grid, we need to fill it with given color.
    -> we can use any BFS or DFS
    -> last we need to return modified image.

    -> while we use bfs or dfs, we can iterate in all 4 direction, because we have to mark it will given color.
    -> For comparision we need to original color.
    -> while using the bfs / dfs -> We will iterate in all 4 direction.

        // all 4 directions:    

                                (row-1, col)
                                     |
                (row, col-1) <- (row, col) -> (row, col+1)
                                     |
                                (row+1, col)

            -> Iterate using:
                delRow[] = {-1, +1, 0, 0}
                delCol[] = {0, 0, -1, +1}



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// --------- Newer Version Efficient Impl.---------------------------
class Solution {    // DFS
private: 
    int n, m;   // grid dimensions
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}   // checks valid bound of grid
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // directions: left, right, up, down
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




class Solution {    // BFS V1: More Precise & Clear Level processing
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

        int lvl = 0;
        while(!q.empty()) { // processing every level-by-level:
            int size = q.size();
            bool isLvlFound = false;

            while(size--) {
                auto [row, col] = q.front();
                q.pop();

                image[row][col] = color;

                for(int i = 0; i < 4; i++) {
                    int r = row + dir[i][0];
                    int c = col + dir[i][1];

                    if(isValid(r, c) && image[r][c] == orgClr && !vis[r][c]) {
                        vis[r][c] = 1;
                        q.push({r, c});
                        isLvlFound = true;
                    }
                }
            }

            if(isLvlFound) lvl++;
        }

        return image;
    }
};


class Solution {    // BFS V2: Simple & Sleek.
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


// --------- Old Version Naive Implementation -----------------------
// BFS Approach:
class Solution_BFS {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> tempImage = image;          // temporary image grid
        vector<vector<int>> vis(n, vector<int> (m, 0)); // visited matrix
        int orColor = image[sr][sc];                    // original color

        queue<pair<int, int>> q;    // using queue DS: queue<row, col>
        q.push({sr, sc});           // push given node in queue
        vis[sr][sc] = 1;            // mark it as visited
        tempImage[sr][sc] = color;  // mark that new tempImage with given color
        

        int delRow[] = {-1, +1, 0, 0};
        int delCol[] = {0, 0, -1, +1};

        while(!q.empty()){  // while queue is not empty
            // get the front element & remove element from queue.
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // iterate in all the 4 direction & mark it with given color:
            for(int i=0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                // Check for valid range, not filled with color:
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && 
                !vis[nRow][nCol] && tempImage[nRow][nCol] == orColor){
                    vis[nRow][nCol] = 1;            // mark that node as visited
                    tempImage[nRow][nCol] = color;  // mark that node with given color
                    q.push({nRow, nCol});           // push that element into queue.
                }
            }
        }

        return tempImage; // return new constructed image
    }
};



// DFS Approach:
class Solution {
private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int orgColor, vector<vector<int>> &vis){
        vis[sr][sc] = 1;        // mark that current node as visited
        image[sr][sc] = color;  // mark that current node with given color

        int n = image.size();
        int m = image[0].size();

        int delRow[] = {-1, +1, 0, 0};
        int delCol[] = {0, 0, -1, +1};
        // iterate in all 4 directions:
        for(int i=0;i<4;i++){
            int nRow = sr + delRow[i];
            int nCol = sc + delCol[i];

            // Check valid range & not filled with color:
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && image[nRow][nCol] == orgColor){
                dfs(image, nRow, nCol, color, orgColor, vis);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> tempImage = image;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int orgColor = image[sr][sc];

        dfs(tempImage, sr, sc, color, orgColor, vis);

        return tempImage;
    }
};