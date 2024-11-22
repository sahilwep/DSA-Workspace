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
    -> TC: O(n)*O(n*m) = O(n^2*m)



// Efficient Solution:
    -> From bruteforce Solution, we can optimize by using map to store the entire row pattern, 
    -> next time when we have same row present, we can simply increase the count of that pattern..

    // Generating Pattern: 
        -> either we can generate inverted & normal row into string & then compare & store, 
        -> or we can simply store the pattern, because pattern for same string & inverted are same:
            -> Example:
                    1 0 0 1 0   -> Normal
                    0 1 1 0 1   -> Inverted

                -> If we observe pattern:
                    -> Take first character & generate pattern:
                        1 0 0 1 0   -> Normal
                        -
                        take this first character as 'o', & whenever we have some character which is equal to first character we will mark it as 'o', else we will mark it as 'z'

                    -> Similary, if we generate pattern for inverted:d
                        0 1 1 0 1   -> Inverted
                        _
                        take this first character as 'o', & whenever we have some character which is equal to first character we will mark it as 'o', else we will mark it as 'z'

                    -> Pattern:
                        [1] 0 0 1 0     => ozzoz
                         o

                        [0] 1 1 0 1     => ozzoz
                         o

                -> This is how we can generate pattern for normal & inverted one & store the frequency count..
        -> At the end we can return the maximum count from the map.

        -> TC: O(n*m) + O(n) + O(n) ≈ O(n*m)
        -> AS: O(n*m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Efficient Solution: O(n*m)
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        unordered_map<string, int> mp;  // AS: O(n*m)

        for(auto &row: matrix){ // O(n)
            // Generate pattern for normal & inverted one:
            string rowPattern = "";
            int firstVal = row[0];
            for(int col=0;col<m;col++){ // O(m)
                rowPattern += (row[col] == firstVal) ? 'o' : 'z';
            }

            mp[rowPattern]++;   // Now Store that pattern count in map
        }

        int maxCnt = 0;
        for(auto i: mp){ // Iterate in map & check maximum count & return => O(n)
            if(i.second > maxCnt){
                maxCnt = i.second;
            }
        }

        return maxCnt;
    }
    
    // BruteForce Solution: TC: O(n * (m + (n*m))) => O(n*(n*m))
    int maxEqualRowsAfterFlips_Brute(vector<vector<int>>& matrix) {
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