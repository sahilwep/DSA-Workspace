/*

//  1582. Special Positions in a Binary Matrix


//  Problem Statement: 
    - Given an m x n binary matrix mat, return the number of special positions in mat.
    - A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

 
// Example:
    Example 1:
        Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
        Output: 1
        Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.

    Example 2:
        Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
        Output: 3
        Explanation: (0, 0), (1, 1) and (2, 2) are special positions.


// Observations:
    - We are given matrix that contains '0' and '1'
    - for every '1', we need to check if all rows & cols has not other '1' then we can say it's special positions.
    - We need to return the total number of special positing.


    // BruteForce Approach:
        - For every '1' check in that whole row & cols
        - If it has not more than one 1's then include in answer.
        - we will have to return all the counts.

        // Complexity:
            - TC: O(n * m * (n + m))
            - SC: O(1)

    // Optimization:
        - Instead of checking every time the whole row & cols for every '1's
        - we can prestore, how many 1's are there in every row & cols.
        - This way, we can directly check how many '1' are there for every rows and cols.
        - For every 1's cell, if have only single '1's in rows & cols, then we can include that into our answer.
        - and last we can return the total special positions.
    
    // Complexity:
        - TC: O(n * m)
        - SC: O(n + m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Solution: TC: O(n * m)
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // PreProcess every row & col details:
        vector<int> rows(n, 0), cols(m, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        // Calculate answer:
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    // For every cell check if we have clean path or not?
                    if(rows[i] == 1 && cols[j] == 1) ans++; // for that cell whole rows & cols we need exactly one 1's
                }
            }
        }

        return ans;
    }
};

// BruteForce Solution:
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    int oneCnt = 0;
                    // Check in that column:
                    for(int k = 0; k < n; k++) {
                        if(mat[k][j] == 1) oneCnt++;
                    }

                    if(oneCnt > 1) break;

                    // Check in that row:
                    for(int k = 0; k < m; k++) {
                        if(mat[i][k] == 1) oneCnt++;
                    }

                    if(oneCnt > 2) break;

                    ans++;
                }
            }
        }

        return ans;
    }
};