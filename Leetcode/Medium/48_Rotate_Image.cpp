/*

//  48. Rotate Image


//  Problem Statement:
    -> You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
    -> You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.


// Example:

    Example 1:
        Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
        Output: [[7,4,1],[8,5,2],[9,6,3]]

    Example 2:
        Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
        Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]


// BruteForce Solution: 
    -> Get the crosspending index & store it in temp matrix, at last update original matrix with temp matrix value.




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BruteForce Solution:
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> temp(n, vector<int> (n, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[i][j] = matrix[n-j-1][i];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = temp[i][j];
            }
            cout << endl;
        }
    }
};