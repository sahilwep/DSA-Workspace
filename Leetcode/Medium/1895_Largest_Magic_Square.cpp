/*

//  1895. Largest Magic Square


//  Problem Statement: 
    - A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.
    - Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.

 
// Example:
    Example 1:
        Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
        Output: 3
        Explanation: The largest magic square has a size of 3.
        Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
        - Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
        - Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
        - Diagonal sums: 5+4+3 = 6+4+2 = 12

    Example 2:
        Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
        Output: 2


// Observations:
    - from every possible cell[i][j]:
        - we will try to generate all possible square
        - We will check valid squares or not?
        - That's the very bruteforce approach.

    // Complexity:
        - TC: O(n * m * min(n, m)^3)
        - SC: O(n + m)
            - accepted because constrains is( 1 <= n, m <= 50), which goes up till 3e8


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BruteForce Approach:
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) { // O(n * m * min(n, m)^3)
        int n = grid.size();
        int m = grid[0].size();

        int maxSide = 1;    // 1x1 is always magic square.

        for(int i = 0; i < n; i++) {// O(n)
            for(int j = 0; j < m; j++) {// O(m)
                // Now from the current cell: generate all possible square cells:
                int K = min(n - i, m - j); // we need to make length of square exactly same in row & cols

                for(int len = 2; len <= K; len++) { // min length of square is '2'  // O(len * (len^2))
                    vector<int> rowSum(len, 0), colSum(len, 0);
                    // rows & cols sums: // O(len^2)
                    for(int r = 0; r < len; r++) {  // O(len)
                        for(int c = 0; c < len; c++) {  // O(len)
                            rowSum[r] += grid[i + r][j + c];
                            colSum[c] += grid[i + r][j + c];
                        }
                    }

                    // Check rows & cols sums:
                    int target = rowSum[0];
                    bool ok = true;
                    for(int s = 0; s < len; s++) {
                        if(rowSum[s] != target || colSum[s] != target) {
                            ok = false;
                            break;
                        }
                    }

                    if(!ok) continue;

                    // Calculate diagonals:
                    int d1 = 0, d2 = 0;
                    for(int t = 0; t < len; t++) {
                        d1 += grid[i + t][j + t];               // main diagonal
                        d2 += grid[i + t][j + len - 1 - t];    // anti diagonal
                    }

                    if(d1 != target || d2 != target) continue;

                    // Store the maximum side:
                    maxSide = max(maxSide, len);
                }
            }
        }

        return maxSide;
    }
};