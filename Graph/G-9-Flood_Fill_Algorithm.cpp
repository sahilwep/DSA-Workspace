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