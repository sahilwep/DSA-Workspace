/*

//  1886. Determine Whether Matrix Can Be Obtained By Rotation


//  Problem Statement: 
    - Given two n x n binary matrices mat and target, 
    - return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

 
// Example:
    Example 1:
        Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
        Output: true
        Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.

    Example 2:
        Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
        Output: false
        Explanation: It is impossible to make mat equal to target by rotating mat.

    Example 3:
        Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
        Output: true
        Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.




// Observation:
    - We are given matrix mat & target
    - we need to rotate the mat 90-degree until mat is not equal to target.
    - if we rotate mat to 90-degree 3 times we will have unique configurations, on 4th rotations, we will move back to the original mat.
    - After every rotation, we will check with target.


    // Complexity:
        - TC: O(n * m)
        - SC: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    int n;
    bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] != target[i][j]) return false;
            }
        }

        return true;
    }
    void rotate90(vector<vector<int>>& grid) {  // function to rotate the matrix by 90-degree.
        
        vector<vector<int>> temp(n, vector<int> (n));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temp[i][j] = grid[j][n - i - 1];
            }
        }

        grid = temp;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();

        if(isEqual(mat, target)) return true;   // alreay equal.

        for(int times = 0; times < 3; times++) {
            // Rotate 90 & check:
            rotate90(mat);

            if(isEqual(mat, target)) return true;
        }

        return false;   // not possible
    }
};