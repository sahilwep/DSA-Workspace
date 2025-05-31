/*

//  329. Longest Increasing Path in a Matrix


//  Problem Statement: 
    -> Given an m x n integers matrix, return the length of the longest increasing path in matrix.
    -> From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
 


// Example: 
    Example 1:
        Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
        Output: 4
        Explanation: The longest increasing path is [1, 2, 6, 9].

    Example 2:
        Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
        Output: 4
        Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

    Example 3:
        Input: matrix = [[1]]
        Output: 1




// Observations: 
    -> We are given a grid of numbers
    -> We have to return the length of longest increasing number.
    -> If we observe bit carefully, it's very-simple:
        -> From every coordinates run any traversal BFS/DFS & try getting the maximum path as possible.

    -> (Overlapping Subproblems == DP) Yes, while we are traversing for path, some path which are already checked, being checked again & again..
    -> Using memoization on BFS || DFS will solve our overlapping issue, & we can solve our problem in very efficient complexity..


// Complexity: 
    -> TC: O(n * m)
    -> SC: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    vector<vector<int>> t;
    int dfs(int row, int col, vector<vector<int>>& grid) {
        if(t[row][col] != -1) return t[row][col];   // Checking from memo-table & returning answer directly..
        
        int pathCnt = 1;    // path count from each cell, 1, because of self counting..

        int tempAns = 0;
        for(int i = 0; i < 4; i++) {    // iterate in all 4 directions
            int r = row + dir[i][0];
            int c = col + dir[i][1];


            if(isValid(r, c)) {   // within valid bound & not yet visited:

                if(grid[r][c] > grid[row][col]) {   // if value is strictly grater than the previous cell:
                    tempAns = max(tempAns, dfs(r, c, grid));   // get maximum from all the directions..
                }
            }
        }

        pathCnt += tempAns; // get the maximum finding from all the directions & add it to the pathCount

        return t[row][col] = pathCnt;   // store in dp table & return our answer.
    }
public:
    int longestIncreasingPath(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        t.resize(n, vector<int> (m, -1));

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j, grid));    // get the maximum among all the calls
            }
        }

        return ans;
    }
};