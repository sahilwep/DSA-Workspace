/*

//  1072. Flip Columns For Maximum Number of Equal Rows

// Problem Statement:
    * You are given an m x n binary matrix matrix.
    * You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).
    * Return the maximum number of rows that have all values equal after some number of flips.


 
// Exapmle:

    Example 1:
        Input: matrix = [[0,1],[1,1]]
        Output: 1
        Explanation: After flipping no values, 1 row has all values equal.

    Example 2:
        Input: matrix = [[0,1],[1,0]]
        Output: 2
        Explanation: After flipping values in the first column, both rows have equal values.

    Example 3:
        Input: matrix = [[0,0,0],[0,0,1],[1,1,0]]
        Output: 2
        Explanation: After flipping values in the first two columns, the last two rows have equal values.



// Observations: 

    [0,0,0]
    [0,0,1]
    [1,1,0]
    
    -> For each row, if we have same row, means we can flip the cols bits, we can make our answer...
    -> For each row, if we have inverted, row, & if we flip the cols bits, we can make our answer...

    In Simple word, Pick each row:
        -> Check for same row?
        -> Check for inverted row?



// Bruteforce Approach:
    -> iterate in matrix:
        -> create temp row, invert or every row
        -> Compare that inverted row with ever row & normal with every row, if they were same, count that...
    -> Now, return the maximum count, as answer... 



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    // BruteForce Solution: TC: O(n * (m + (n*m))) => O(n*(n*m))
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int ans = 0;

        for(auto &it: matrix){  // O(n)
            // Create inverted:
            vector<int> inverted(m); // O(m)
            for(int col=0;col<m;col++){
                inverted[col] = (it[col] == 0) ? 1 : 0; // store inverted value, or we can also use this logic to store inverted value (inverted[col] = 1 - it[col]) 
            }

            int cnt = 0;
            for(auto &row: matrix){     // iterate in matrix & compare row with inverted one => O(n*m), n for row & m for every cols.
                if(row == inverted || row == it){   // comparision happen with entire vector, which takes O(m)
                    cnt++;  // increment cnt if we found any row equal to row itself, or inverted row.
                }
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};