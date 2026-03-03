/*

//  1536. Minimum Swaps to Arrange a Binary Grid


//  Problem Statement: 
    - Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.
    - A grid is said to be valid if all the cells above the main diagonal are zeros.
    - Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.
    - The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).

 
// Example:
    Example 1:
        Input: grid = [[0,0,1],[1,1,0],[1,0,0]]
        Output: 3

    Example 2:  
        Input: grid = [[0,1,1,0],[0,1,1,0],[0,1,1,0],[0,1,1,0]]
        Output: -1
        Explanation: All rows are similar, swaps have no effect on the grid.

    Example 3:
        Input: grid = [[1,0,0],[1,1,0],[1,1,1]]
        Output: 0



// Observations:
    - A grid is said to be valid if all the cells above the diagonals are 0's.
    
        - Valid grid:
                1   0   0
                1   1   0
                0   1   1
                
        - Invalid Grid:
                1   1   0
                1   0   1
                0   0   1

    - In Every step we can swap any two adjacent rows.
    - We need to return the minimum step so that we can make our grid valid.


    // Key-Observations 1:
        - We need to make sure that for every row the Diagonal above cells are 0's
        - For every row:
                ReqZeroes = n - row - 1
                This much zeroes we required so that we can say the row is valid for making grid valid.

    // Key-Observations 2:
        - If we observe carefully, every rows, trailing zeroes which we needed.
        - So if we count the number of trailing zeroes for every rows, we can find out which rows has how much trailing zeros.
        - and accordingly, we can swap.

    - In Single Step We can swap any two adjacent rows.
    
    // Approach:
        - Now we have List of all rows of trailing zeroes.
        - For every rows: 
            - we can calculate how much trailing zeroes we required: "n - row - 1"
            - we can count if current row has enough trialing zeroes or not?
            - If it's continue - skip
            - Else:
                - Check in the list of trailing zeroes, if we had any any nearby row which has >= trailingZeroes.
                - If we dont' => return '-1' impossible to make grid valid.
                - else:
                    Count the number of step to make grid valid:
        - last return the step.

    // Complexity:
        - TC: O(n^2)
        - SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    int n;
    int cntTrailingZeros(vector<vector<int>>& grid, int i) {    // Function to count the trailing zeroes in current zeroes,  TC: O(n)

        int zeroCnt = 0;
        for(int j = n - 1; j >= 0; j--) {
            if(grid[i][j] == 1) {
                break;
            }
            zeroCnt++;
        }

        return zeroCnt;
    }
    void swapRows(vector<vector<int>>& grid, int idx1, int idx2) {      // function to swap the two rows from grid,  TC: O(n)
        for(int i = 0; i < n; i++) {
            swap(grid[idx1][i], grid[idx2][i]);
        }
    }
public:
    int minSwaps(vector<vector<int>>& grid) {
        n = grid.size();

        // For every row count the number of trailing zeroes:
        vector<int> trailingZeroes(n, 0);
        for(int i = 0; i < n; i++) {
            trailingZeroes[i] = cntTrailingZeros(grid, i);
        }
        
        // Now Check for every row how much zeroes needed & can we build our grid valid or not?
        int step = 0;
        for(int i = 0; i < n; i++) {
            int reqZeroes = n - i - 1;                  // this much trailing zeroes we required
            int zeroCnt = cntTrailingZeros(grid, i);    // this much trailing zeroes we have

            if(reqZeroes <= zeroCnt) continue;          // if it's satisfied, skip


            // Find the nearest cell which has enough zero to make grid valid.
            int rowIdx = -1;
            for(int r = i + 1; r < n; r++) {
                if(trailingZeroes[r] >= reqZeroes) {
                    rowIdx = r;
                    break;
                }
            }

            if(rowIdx == -1) return -1;    // if not found return '-1', impossible to make grid valid

            // Count the number of swaps we required:
            while(rowIdx > i) {
                swapRows(grid, rowIdx, rowIdx - 1);                         // swap adjacent rows
                swap(trailingZeroes[rowIdx], trailingZeroes[rowIdx - 1]);   // swap adjacent trailing zeroesCnt.
                
                step++;         // Count 1-steps for every swap.
                rowIdx--;       // decrement the row so that we can look over next rows..
            }
        }

        return step;
    }
};