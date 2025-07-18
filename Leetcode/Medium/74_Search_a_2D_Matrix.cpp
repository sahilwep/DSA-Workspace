/*

//  74. Search a 2D Matrix


//  Problem Statement: 
    -> You are given an m x n integer matrix matrix with the following two properties:
        -> Each row is sorted in non-decreasing order.
        -> The first integer of each row is greater than the last integer of the previous row.
    -> Given an integer target, return true if target is in matrix or false otherwise.
    -> You must write a solution in O(log(m * n)) time complexity.

 
// Example: 
    Example 1:
        Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
        Output: true

    Example 2:
        Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
        Output: false

// Observations: 
    -> We are given 2D grid & we need to find wether the target value exist or not?
    -> return true if it's exist : else return false.


    // Approach 1: Naive: 
        -> Implement (n * m) Iterations solutions.

        // Complexity: 
            -> TC: O(n * m)
            -> SC: O(1)

    // Approach 2: BruteForce: 
        -> Iterate every row & for every row implement binary seach
        
        // Complexity: 
            -> TC: O(n * log m)
            -> SC: O(1)
            

    // Approach 3: Better: 
        -> Implement binary seach for every row & for every row implement binary seach
        
        // Complexity: 
            -> TC: O(log n * log m)
            -> SC: O(1)

    // Approach 3: Efficient: 
        -> Round the Seach range into (n * m)
        -> Apply binary seach in search range (0...(n*m-1))            
        -> Conversion Logic: 

            For matrix of size n * m
                
                Range:
                    low = 0, high = n * m - 1
                    mid/CellNo = low - (high - low) / 2


                If we have given row & column, Convert it to cellNo:
                    - cellNo = row * m + col;


                If we have given cellNo, Convert it to row & col
                    - row = cellno / m;
                    - col = cellNo % m;

        // Complexity: 
            -> TC: O(log(n * m))
            -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient: TC: O(log(n * m))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {    // TC: O(log(n * m))
        int n = matrix.size(), m = matrix[0].size();

        // Flatten the matrix approach:
        int low = 0;
        int high = n * m - 1;

        while(low <= high) {    // TC: O(log(n * m))
            int mid = low + (high - low) / 2;   // consider this as cellNo after in flatten matrix

            int row = mid / m;
            int col = mid % m;

            if(matrix[row][col] == target) return true;

            if(matrix[row][col] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};


// Better Solution: O(log n * log m)
class Solution {
private: 
    int n, m;
    bool isFound(vector<vector<int>>& matrix, int& target, int i) {      // TC: O(log m)
        int low = 0;
        int high = m - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(matrix[i][mid] == target) return true;
            
            if(matrix[i][mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        n = matrix.size(), m = matrix[0].size();

        int low = 0;
        int high = n - 1;

        while(low <= high) {    // TC: O(logn * log m)
            int mid = low + (high - low) / 2;

            if(isFound(matrix, target, mid)) {  // TC: O(log m)
                return true;
            } else {
                // Two possibility: Correct row either above or down:
                // fetch the start end value of row:
                int startVal = matrix[mid][0];
                int endVal = matrix[mid][m-1];

                if(target < startVal) {
                    high = mid - 1;
                } else if(target > endVal) {
                    low = mid + 1;
                } else {
                    break;  // not found on current row
                }
            }
        }

        return false;   // not found
    }
};


// BruteForce: TC: O(n * log m)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        for(int i = 0; i < n; i++) {    // TC: O(n * logM)
            // Do the binary search: 
            int low = 0;
            int high = m - 1;

            while(low <= high) {
                int mid = low + (high - low) / 2;

                if(matrix[i][mid] == target) return true;
                
                if(matrix[i][mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;   // not found
    }
};


// Naive: TC: O(n * m)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == target) return true;
            }
        }
        return false;
    }
};