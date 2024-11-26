/*

//  1861. Rotating the Box


//  Problem Statement:
    * You are given an m x n matrix of characters box representing a side-view of a box. 
    * Each cell of the box is one of the following:
            A stone '#'
            A stationary obstacle '*'
            Empty '.'

    * The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. 
    * Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. 
    * Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.
    * It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.
    * Return an n x m matrix representing the box after the rotation described above.


// Observation: 
    * Given grid has size: NxM.
        -> To Flip this 90 degree, create temporary grid of size: MxN

    * After flip:
        -> From the previous arrangement, we need to move all the elements downwards.

            '*' Obstacle are fixed, we can move down.
            '#' elements are not fixed, we can move downwards, but if we encounter any other element, we need to break out.
            '.' represent empty box, we can move downwards.

// Time Complexity: 
    * TC: O(n^2*m)
        -> O(n*m) => matrix iteration
        -> O(n) => For every element, we have iterated to whole row of matrix.


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to move every given element downwards;
    void moveToBottom(vector<vector<char>> &t, int row, int col){
        int n = t.size();   // row range of given matrix

        for(int i=row+1;i<n;i++){   // NOTE: Start iteration, just after the current row:
            if(t[i][col] == '#' || t[i][col] == '*'){   // if we encounter with any obstacle or element, we will break out..
                break;
            }
            if(t[i][col] == '.'){   // else:
                t[i-1][col] = '.';  // reset previous occupied block, as empty
                t[i][col] = '#';    // updating new empty block, as occupied.
            }
        }

    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {  // Driver function:
        int n = box.size();
        int m = box[0].size();

        vector<vector<char>> t(m, vector<char> (n));    // temp grid to compute result:

        // filling the arrangement into temp matrix, with 90 degree flip:
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // for 90 degree rotation, we have have subtract i with row, so that we can get correct mirror image.
                t[j][n-i-1] = box[i][j];
            }
        }


        // Now, we need to move every element towards bottom: 
        for(int i=m-1;i>=0;i--){    // started iteration from last, so that we can get the correct arrangement.
            for(int j=n-1;j>=0;j--){
                if(t[i][j] == '#'){
                    moveToBottom(t, i, j);  // whenever we encounter with any element, we will call function which will move elements downwards.
                }
            }
        }
        
        return t;   // return customized grid.
    }
};