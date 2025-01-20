/*

//  2661. First Completely Painted Row or Column


//  Problem Statement: 
    -> You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].
    -> Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].
    -> Return the smallest index i at which either a row or a column will be completely painted in mat.



// Example:
    Example 1:
        Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
        Output: 2
        Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].

    Example 2:
        Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
        Output: 3
        Explanation: The second column becomes fully painted at arr[3].



// Observations: 
    -> We are given matrix & array, 
    -> We need to paint matrix cell, according to the array element.
    -> at any movement when any row OR any column is completely painted, we can return that minimum index.


    // BruteForce Solution:
        -> use paint grid to track the painted cells.
        -> At any movement any row or any column is painted, we can return true;
        -> we need to return that index.

        -> For painting that particular element from array, we have to traverse all the way to that value, & then paint.
            ->  We can write independent function for that 
        -> For checking wether any row || any column is completely painted, we will have to visit the matrix at every steps.
        -> & at any movement we encounter with the given condition, we will return that minimum index.
        -> Complexity will be higher, but it will work.
            -> TC: O((n*m) * (n*m)) => O(n^2 * m^2)
            -> SC: O(n*m)






*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;



// BruteForce Solution:
class Solution {
private:
    bool checkMat(vector<vector<bool>> &painted){   // TC: O(n*m)
        int n = painted.size();
        int m = painted[0].size();

        // check every row:
        for(int i=0;i<n;i++){
            bool checkFlag = true;
            for(int j=0;j<m;j++){
                if(painted[i][j] == false){
                    checkFlag = false;
                }

            }
            if(checkFlag){
                return 1;   // found one row, that contains all true:
            }
        }

        // check every col:
        for(int i=0;i<m;i++){
            bool checkFlag = true;
            for(int j=0;j<n;j++){
                if(painted[j][i] == false){
                    checkFlag = false;
                }
            }
            if(checkFlag){
                return 1;   // found one row, that contains all true:
            }
        }

        return 0;   // else return false;
    }
    void painted(vector<vector<int>>& mat, vector<vector<bool>> &paint, int value){ // TC: O(n*m)
        int n = mat.size();
        int m = mat[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == value){
                    paint[i][j] = true;
                    return; // return back
                }
            }
        }
    }
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) { // TC: O((n*m) * (n*m))
        int arrSize = arr.size();
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> paint(n, vector<bool> (m, false));   // this will contains the information of every painted cells

        int minIdx = -1;
        for(int i=0;i<arrSize;i++){ // TC: O(n*m)
            int value = arr[i];  // element to paint
            
            // TC: O(n*m)
            painted(mat, paint, value);   // paint that particular element

            // TC: O(n*m)
            if(checkMat(paint)){    // if any row || any column is painted, return true.
                minIdx = i;
                break;
            }

        }

        return minIdx;
    }
};