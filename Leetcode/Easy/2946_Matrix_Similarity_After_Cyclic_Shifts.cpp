/*

// 2946. Matrix Similarity After Cyclic Shifts
 

//  Problem Statement: 
    - You are given an m x n integer matrix mat and an integer k. The matrix rows are 0-indexed.
    - The following proccess happens k times:
        - Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left.
        - Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right.
    - Return true if the final modified matrix after k steps is identical to the original matrix, and false otherwise.

 
// Example:
    Example 1:
        Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 4
        Output: false

    Example 2:
        Input: mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2
        Output: true


    Example 3:
        Input: mat = [[2,2],[2,2]], k = 3
        Output: true
        Explanation: As all the values are equal in the matrix, even after performing cyclic shifts the matrix will remain the same.

        
// Observations:
    - We have to rotate whole matrix k times:
    - In each rotations:
        - every even index elements rotate left side
        - every odd index elements rotate right side.


    // Complexity:
        - TC: O(n * m * k)
        - SC: O(n * m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    int n, m;
    bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& grid) { // Function to check if rotated ones is equal to original
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] != grid[i][j]) return false;
            }
        }

        return true;
    }
    void rotate(vector<vector<int>>& grid) {    // function to rotate grid
        // Rotate even to left & odd to right
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {    // even: rotate the current row to left
                int temp = grid[i][0];
                for(int j = 0; j < m - 1; j++) {
                    grid[i][j] = grid[i][j + 1];
                }
                grid[i][m - 1] = temp;
            } else {    // odd: rotate the current row to right
                int temp = grid[i][m - 1];
                for(int j = m - 1; j > 0; j--) {
                    grid[i][j] = grid[i][j - 1];
                }
                grid[i][0] = temp;
            }
        }
    }
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        n = mat.size();
        m = mat[0].size();

        vector<vector<int>> grid = mat;
        while(k--) {    
            rotate(grid);   // rotate k times.
        }

        if(isEqual(mat, grid)) return true;

        return false;
    }
};