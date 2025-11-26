/*

//  2435. Paths in Matrix Whose Sum Is Divisible by K


//  Problem Statement: 
    - You are given a 0-indexed m x n integer matrix grid and an integer k. You are currently at position (0, 0) and you want to reach position (m - 1, n - 1) moving only down or right.
    - Return the number of paths where the sum of the elements on the path is divisible by k. Since the answer may be very large, return it modulo 10e9 + 7.


// Example: 
    Example 1:
        Input: grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
        Output: 2
        Explanation: There are two paths where the sum of the elements on the path is divisible by k.
        The first path highlighted in red has a sum of 5 + 2 + 4 + 5 + 2 = 18 which is divisible by 3.
        The second path highlighted in blue has a sum of 5 + 3 + 0 + 5 + 2 = 15 which is divisible by 3.

    Example 2:
        Input: grid = [[0,0]], k = 5
        Output: 1
        Explanation: The path highlighted in red has a sum of 0 + 0 = 0 which is divisible by 5.

    Example 3:
        Input: grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
        Output: 10
        Explanation: Every integer is divisible by 1 so the sum of the elements on every possible path is divisible by k.



// Observations:
    - we are at (0, 0), we need to reach at (n - 1, m - 1)
    - we are allowed to move down & right only.
    - after reaching to the path (n - 1, m - 1), if sum of the values are divisible by 'k'
    - we can return that path as our answer.

    // Approach: 
        - recursively try all possible path
        - when we reach destinations, just check wether the sum is divisible by 'k'
            - if it's divisible by 'k' consider that path into our answer...

            // Complexity: 
                - TC: O(2^(n + m))
                - SC: O(n + m)
                    => here, TC =  2^(N + m) not 2^(n * m), because we are only moving down & right, depth of the calls will be (n + m), because we are moving right & down....

        - Solution was correct, but falls into TLE
        - Now we need to optimize this..

        // we can memoize this solution: 
            - varying parameters: n, m, sum
            - But if we consider sum, the table become very big range, because constrains: 1e5 * 1e5, so we will take remainder of that..
            - k => (sum % k) -> say remainder
                - as we are rounding it with 'k'
                - remainder value will range within 'k'.
            - So, new variable parameters: n, m, r, where r = remainder


        // Complexity: 
            - TC: O(n * m * k)
            - SC: O(n * m * k)


--------------------------- Extra ---------------------------

        - Conceptually, we can take third dimensions of our dp table as "sum"
        - but it become so large that it can't fit in our given time & space constrains..
        - Explanations:
            Constrains:
                m == grid.length
                n == grid[i].length
                1 <= m, n <= 5 * 1e4
                1 <= m * n <= 5 * 1e4       <- Grid size (n * m) 50,000, This much we can have at worse case.
                0 <= grid[i][j] <= 100
                1 <= k <= 50


                    Example:
                        m = 1
                        n = 50,000

                        Or:
                        
                        m = 250
                        n = 200

                        As long as:
                            m * n ≤ 50000   <- Important one, keep this in mind..

                        Worst-case number of cells = 50,000.
                        Worst-case cell value = 100.
                        So maximum possible path length (down or right only):
                            maxSteps = m + n − 2 ≤ 50,000 − 2 ≈ 49,998
                        Worst-case sum of a single path:

                            maxSum = 49,998 * 100 ≈ 5,000,000

                                    49,998 -> this much cells we can have 

                        Now imagine your DP table if “sum” is the third dimension
                        
                        Your DP state: dp[row][col][sum]

                            Worst-case size: 

                                rows ≈ 1
                                cols ≈ 50,000
                                    (or any arrangement that multiplies to 50k)
                                grid[row][col] = 100
                                

                            sum = 50,000 * 100 = 5,000,000
                            sum dimension = 5,000,000 (5 million)

                            Total DP states: 1 * 50,000 * 5,000,000 = 250,000,000,000
                            That is 250 billion DP states

                        Now memory:
                            each DP entry = int = 4 bytes

                        Memory needed: 250,000,000,000 * 4 = 1,000,000,000,000 bytes = 1 terabyte

                -> This is why we are rounding the sum with given 'k' & only maintaining remainder, because we are checking it's divisible by 'k' or not?
                -> at last when (remainder == 0) & when we reach to the last cell, we return that path as valid..
                -> This way we manage to bound the third dimensions of dp table within given 'k'
                -> worse case, k = 50
                    50,000 * 50 = 25,00,000 = 25 * 1e5 = 2.5 * 1e6
                    which is a good & valid range to be consider in given space constrains...


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Memoization:
class Solution {
private: 
    int n, m;
    int mod = 1e9 + 7;
    int k;
    vector<vector<vector<int>>> dp;
    int solve(int row, int col, vector<vector<int>>& grid, int rem) {
        rem = (rem + grid[row][col]) % k;   // round the sum value with k & get remainder..

        // Base case:
        if(row == n - 1 && col == m - 1) {  // reach last block
            if(rem == 0) return 1;  // got valid path.
            else return 0;  // no valid path
        }

        // Check in memo-table:
        if(dp[row][col][rem] != -1) {
            return dp[row][col][rem];
        }

        // Decision Tree:
        int path = 0;
        if(row + 1 < n) {   // move down:
            path = (path + solve(row + 1, col, grid, rem)) % mod;
        }
        if(col + 1 < m) {   // move right:
            path = (path + solve(row, col + 1, grid, rem)) % mod;
        }

        return dp[row][col][rem] = path;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k_) {
        n = grid.size();
        m = grid[0].size();
        k = k_;

        dp.resize(n + 1, vector<vector<int>> (m + 1, vector<int> (k + 1, -1)));

        return solve(0, 0, grid, 0);
    }
};


// Recursive Solution:
class Solution {
private: 
    int n, m;
    int mod = 1e9 + 7;
    int k;
    int solve(int row, int col, vector<vector<int>>& grid, int sum) {
        sum += grid[row][col];  // current grid into sum

        // Base case:
        if(row == n - 1 && col == m - 1) {  // reach last block
            if(sum % k == 0) return 1;  // got valid path.
            else return 0;  // no valid path
        }

        // Decision Tree:
        int path = 0;
        if(row + 1 < n) {   // move down:
            path = (path + solve(row + 1, col, grid, sum)) % mod;
        }
        if(col + 1 < m) {   // move right:
            path = (path + solve(row, col + 1, grid, sum)) % mod;
        }

        return path;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k_) {
        n = grid.size();
        m = grid[0].size();
        k = k_;

        return solve(0, 0, grid, 0);
    }
};