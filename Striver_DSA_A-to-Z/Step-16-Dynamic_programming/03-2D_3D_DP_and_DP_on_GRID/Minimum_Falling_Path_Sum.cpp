/*

//  931. Minimum Falling Path Sum


//  Problem Statement: 
    - Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
    - A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 
// Example:
    Example 1:
        Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
        Output: 13
        Explanation: There are two falling paths with a minimum sum as shown.

    Example 2:
        Input: matrix = [[-19,57],[-40,-5]]
        Output: -59
        Explanation: The falling path with a minimum sum is shown.


// Observations:
        - we have given grid of size n * m
        - We have to start from the first row, & reach to the last row.
        - from every cell either we can go bottom_left, bottom, bottom_right
        - we need to travel in a way so that the sum of the value in path is minimum.
        - We can start anywhere from the first row.
        - Using recursion we can start from first for every index & try to find the minSum solution:

            // Recursive Solution:
                - This will help us to explore from every possible path:
                - we can travel bottom_left, bottom, bottom_right, in simple we have 3 choices..
                - we need min_sum value from the function.
                
                // Function Signature:
                    int solve(int currLvl, int idx, vector<vector<int>>& grid) {
                        ...
                    }

                // Base case:
                    - when we reaches to last row, i.e (currLvl == n - 1)
                    
                        if(currLvl == n - 1) {
                            return t[currLvl][idx];
                        }

                // Decision tree:
                    - From every cell, we have 3 choices, bottom_left, bottom, bottom_right
                    - at last we need to return minimum among them by adding the current level cell value into our sum:

                        int bottom_left = (idx - 1 >= 0) ? solve(currLvl + 1, idx - 1, grid) : INT_MAX;
                        int bottom = solve(currLvl + 1, idx, grid);
                        int bottom_right = (idx + 1 <= n -1) ? solve(currLvl + 1, idx + 1, grid) : INT_MAX;

                        int ans = grid[currLvl][idx] + min({bottom_left, bottom, bottom_right});
                        return ans;

            // Controller code:
                - we have to start looking from every col of first row:
                for(int i = 0; i < m; i++) {    
                    ans = min(ans, solve(0, i, grid))
                }

            - This falls int TLE:
                - TC: O(3^(n * m))
                - TC: O(n * m)

        // Memoization:
            - We can use memoization approach to prevent subproblem being recomputed again-n-again..
            - Variables values:
                    0 <= currLvl <= n - 1
                    0 <= idx <= m - 1

            - memo-table size = (n * m)
            - check in memo-table before going into the decision tree
            - store the answer for every subproblem..

            // Complexity:  
                - TC: O(m * (n * m))
                - SC: O(n * m)


        // Tabulations:
            - We can Convert our current memoized solution into tabulations, by simply observing the behaviors.
            // DP State:

                    0 <= currLvl <= n - 1
                    0 <= idx <= m - 1

            // DP Transitions:
                    
                        b_left = (idx - 1 >= 0) ? t[currLvl + 1][idx - 1] : INT_MAX;
                        b = t[currLvl + 1][idx];
                        b_right = (idx + 1 <= n - 1) ? t[currLvl + 1][idx + 1]: INT_MAX;

                    t[currLvl][idx] = grid[currLvl][idx] + min({b_left, b, b_right});

            NOTE: In Tabulation we are doing bottom-up, we are finding our answer in reverse order..
            
            // base case:
                - last row should be filled with the same value as grid[n - 1][i] has.
                for(int i = 0; i < m; i++) {
                    t[n - 1][i] = grid[n - 1][i];
                }

            // Iterations definations:
                - we just fill our (n - 1)th lvl/row
                - Now currLvl goes like: (n - 2 <= currLvl <= 0)
                - we will explore from every row from start: (0 <= idx <= m - 1)
                - For every curr_value, which is t[currLvl][idx]
                - we will get the min from these bottom values..

                            [curr_Value]
                            /     |     \
                     [b_left]    [b]    [b_right]

                     t[currLvl][idx] = grid[currLvl][idx] + min({b_left, b, b_right})

                - This will make sure that it will choose only min_value from the down three options, for the current cell.
                
            // Answer: 
                - At the end our DP-table first row contains the min_Possible sum.
                - because we are traveling backwords, & everytime we-move we make sure to choose only the min_options from 3 choices.
                - So, logically first row will conattins the value i.e the minimum, we just have to iterate in first row of dp-table & find that.

                    int ans = *min_element(begin(t[0]), end(t[0]));
                    

            // Complexity:
                - TC: O(n * m)
                - SC: O(n * m)

                

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Optimized Tabulations:
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> t(n, vector<int>(m, 0));

        // Base case: fill last row initially:
        for(int j = 0; j < m; j++) {
            t[n - 1][j] = grid[n - 1][j];
        }

        // Fill DP table bottom-up:
        for(int currLvl = n - 2; currLvl >= 0; currLvl--) { // starting from second last-row:
            for(int idx = 0; idx < m; idx++) {  // start for every row:

                // Compute the bottom 3 cells for every t[currLvl][idx]
                int b_left  = (idx - 1 >= 0) ? t[currLvl + 1][idx - 1] : INT_MAX;
                int b = t[currLvl + 1][idx];
                int b_right = (idx + 1 < m) ? t[currLvl + 1][idx + 1] : INT_MAX;

                // Store the minimum:
                t[currLvl][idx] = grid[currLvl][idx] + min({b_left, b, b_right});
            }
        }

        // Result = min element from the first row
        return *min_element(t[0].begin(), t[0].end());
    }
};


// Tabulations: No-optimization, just copy-pate of memoization logic, i just transform memoization with Tabulations..
class Solution {
private:
    int n, m;
    vector<vector<int>> t;
private:
    int solve(int col, vector<vector<int>>& grid) {

        vector<vector<int>> t(n + 1, vector<int> (m + 1, 1e4 + 1));

        // Fill Base case:
        for(int i = 0; i < m; i++) {
            t[n - 1][i] = grid[n - 1][i];
        }

        for(int currLvl = n - 2; currLvl >= 0; currLvl--) {
            for(int idx = m - 1; idx >= 0; idx--) {

                int b_left = (idx - 1 >= 0) ? t[currLvl + 1][idx - 1] : 1e4 + 1;
                int b = t[currLvl + 1][idx];
                int b_right = (idx + 1 <= m - 1) ? t[currLvl + 1][idx + 1] : 1e4 + 1;

                t[currLvl][idx] = grid[currLvl][idx] + min({b_left, b, b_right});
            }
        }

        return t[0][col];
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        // In first row, we have to try for every col-idx:
        int minSum = INT_MAX;
        for(int i = 0; i < m; i++) {
            // Calculate:
            minSum = min(minSum, solve(i, matrix));
        }

        return minSum;
    }
};

// Memoization:
class Solution {
private:
    int n, m;
    vector<vector<int>> t;
    int solve(int currLvl, int idx, vector<vector<int>>& grid) {
        if(currLvl == n - 1)  { // base case: reaches to last level => return value.
            return grid[currLvl][idx];
        }

        if(t[currLvl][idx] != INT_MAX) return t[currLvl][idx];

        // Decision tree: Safe path to explore
        int b_left = (idx - 1 >= 0) ? solve(currLvl + 1, idx - 1, grid) : INT_MAX;
        int b = solve(currLvl + 1, idx, grid);
        int b_right = (idx + 1 <= m - 1) ? solve(currLvl + 1, idx + 1, grid) : INT_MAX;

        int pathSum = grid[currLvl][idx] + min({b_left, b, b_right});
        return  t[currLvl][idx] = pathSum;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        // In first row, we have to try for every col-idx:
        int minSum = INT_MAX;
        for(int i = 0; i < m; i++) {
            t.assign(n + 1, vector<int> (m + 1, INT_MAX));  // Assign memo-table for every start
            minSum = min(minSum, solve(0, i, matrix));
        }

        return minSum;
    }
};

// Recursive Solution:
class Solution {
private:
    int n, m;
    int solve(int currLvl, int idx, vector<vector<int>>& grid) {
        if(currLvl == n - 1)  { // base case: reaches to last level => return value.
            return grid[currLvl][idx];
        }

        // Decision tree: Safe path to explore
        int b_left = (idx - 1 >= 0) ? solve(currLvl + 1, idx - 1, grid) : INT_MAX;
        int b = solve(currLvl + 1, idx, grid);
        int b_right = (idx + 1 <= m - 1) ? solve(currLvl + 1, idx + 1, grid) : INT_MAX;

        int pathSum = grid[currLvl][idx] + min({b_left, b, b_right});
        return pathSum;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        // In first row, we have to try for every col-idx:
        int minSum = INT_MAX;
        for(int i = 0; i < m; i++) {
            minSum = min(minSum, solve(0, i, matrix));
        }

        return minSum;
    }
};