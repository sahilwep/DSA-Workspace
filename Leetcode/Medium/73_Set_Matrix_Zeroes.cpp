/*

//  73. Set Matrix Zeroes


//  Problem Statement: 
    -> Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
    -> You must do it in place.
 

// Example:

    Example 1:

        Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
        Output: [[1,0,1],[0,0,0],[1,0,1]]

    Example 2:

        Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
        Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


// Complexity: 
    -> TC: O(m * n)
    -> SC: O(m * n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        set<int> sRow;
        set<int> sCol;

        // Store location of every row & col where we have '0' in it.
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    sRow.insert(i);
                    sCol.insert(j);
                }
            }
        }

        // now overwrite rows:
        for(auto it: sRow){
            for(int i=0;i<m;i++){
                matrix[it][i] = 0;
            }
        }

        // now Overwrite cols:
        for(auto it: sCol){
            for(int i=0;i<n;i++){
                matrix[i][it] = 0;
            }
        }
    }
};