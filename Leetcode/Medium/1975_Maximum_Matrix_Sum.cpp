/*

// 1975. Maximum Matrix Sum

// Problem Statement:
    * You are given an n x n integer matrix. You can do the following operation any number of times:
    * Choose any two adjacent elements of matrix and multiply each of them by -1.
    * Two elements are considered adjacent if and only if they share a border.
    * Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.


// Example:

    Example 1:
        Input: matrix = [[1,-1],[-1,1]]
        Output: 4
        Explanation: We can follow the following steps to reach sum equals 4:
        - Multiply the 2 elements in the first row by -1.
        - Multiply the 2 elements in the first column by -1.

    Example 2:
        Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
        Output: 16
        Explanation: We can follow the following step to reach sum equals 16:
        - Multiply the 2 last elements in the second row by -1.


// Observation: 
    
    Example 1:
        Initial:
            [1, -1]             [1,   1]            [1, 1]
            [-1, 1]     =>      [-1, -1]    =>      [1, 1]
            Negative count = 2 (even)
        Final:
            [1, 1]
            [1, 1]
        
    Example 2:
        Initial:
            [1,   2,  3]        [1,   2,  3]
            [-1, -2, -3]    =>  [-1,  2,  3]
            [1,   2,  3]        [1,   2,  3]
            Negative Count = 3 (odd)
        Final:
            [1,   2,  3]
            [-1,  2,  3]
            [1,   2,  3]


    -> Negative number can be propagate very easily, by simply selecting two consecutive element & multiply them with '-1'
    -> Negative Numbers Count:
        -> Odd => 1 negative numbers always remains.
        -> Even => no negative numbers will be there
    
    -> For odd negative count -> Make the smallest number to be negative, so that in whole sum it has very less impact.


*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll ans = 0;
        int negCnt = 0;
        int smallestNum = INT_MAX;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(abs(matrix[i][j]) < smallestNum){    // getting the smallest value from the matrix
                    smallestNum = abs(matrix[i][j]);
                }

                if(matrix[i][j] < 0) negCnt++;          // counting negative values in matrix
                ans += abs(matrix[i][j]);               // calculating absolute sum
            }
        }

        if(negCnt % 2 != 0){    // if negative count is odd:
            ans = ans -  2 * smallestNum;   // 2*smallest, because(first we will remove that from whole sum & then subtract again because thats the smallest number)
        }

        return ans; // else negative count is even, return absolute sum
    }
};