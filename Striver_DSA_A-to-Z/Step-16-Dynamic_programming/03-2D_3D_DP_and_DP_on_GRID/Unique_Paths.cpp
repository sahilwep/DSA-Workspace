/*

//  62. Unique Paths

//  Problem Statement: 
    - There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
    - Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
    - The test cases are generated so that the answer will be less than or equal to 2 * 109.

 
// Example:
    Example 1:
        Input: m = 3, n = 7
        Output: 28

    Example 2:
        Input: m = 3, n = 2
        Output: 3
        Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
        1. Right -> Down -> Down
        2. Down -> Down -> Right
        3. Down -> Right -> Down


// Observations:
    - we have to reach from (0, 0) to (n - 1, m - 1)
    - we can only move right, or down
    - we need to find all the possible unique ways so that we can reach to destinations..

    // Approach:
        - We can use recursive solution to find the total number of path, as we have two options either go to down, or right.
        - Recursive solution will let's us know, with how many unique path we can reach to (n-1, m-1)
            // Function signature:
                - we will have to return total number of path, so, we will return with int type.
                - {row, col} these two values are changing in range (0 <= row <= n - 1) & (0 <= col <= m - )

                int solve(row, col) {
                    ...
                }
            
            // Base conditions:
                - If we reach at destinations, i.e (n - 1, m - 1) return '1'
                if(row == n - 1 && col == m - 1) return 1;

            // Decision tree:
                - initially path = 0;
                // right:
                    - if (col + 1 < m): we can explore in right directions, (col + 1) used to check valid next index for col
                        path += solve(row, col + 1);
            
                // down:
                    - if (row + 1 < n): we can explore in right directions, (row + 1) used to check valid next index for col
                        path += solve(row + 1, col);
                    
                - last return the path

            // Complexity:
                - TC: O(2^(n * m)) -> two branches to explore for every cell.
                - SC: O(n * m)  -> Depth of recursive calls.
                - This solution falls into TLE, because of time constrains & subproblem computed multiple times..

        // Optimization: memoization
            - We can use memoization to improve the time-complexity of the solution.
            - Variable values:
                0 <= row <= n - 1
                0 <= col <= m - 1
            - make a memo-table of size (n * m) to store the subproblem answers.
            - for every subproblem, make sure to check if it's exist in memo-table or not?
                - if it does exist, return directly.
                - else explore the solution, and save in memo-table before returning..
            
            // Complexity:
                - TC: O(n * m)
                - SC: O(n * m)

        // Tabulations:
            - Convert the recursive solution into tabulations, by removing the recursion completely..
            // Dp State:

                0 <= row <= n - 1
                0 <= col <= m - 1
                
            // Dp transitions:
                    if(j + 1 < m) right = t[i][j + 1]
                    if(i + 1 < n) down = t[i + 1][j];

                t[i][j] = left + down;

            // base case:
                t[n - 1][m - 1] = 1;    // the destinations cell.

            // Loop ranges:
                 n - 1 <= i <= 0
                 m - 1 <= j <= 0
                 
            - NOTE: Make sure to skip when (i == n - 1 && j == m - 1), because to prevent the overwriting the base case..

            // Complexity:
                - TC: O(n * m)
                - SC: O(n * m)


// Extra:
    - This problem can also be solved using Graph DFS
    - because, in Graph we can explore in right, & down directions & find the total number of unique path to reach destinations.
    - The recursive solution, is DFS version of the grid..


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Tabulations:
class Solution {
private:
    int n, m;
    vector<vector<int>> t;
public:
    int uniquePaths(int n_, int m_) {
        n = n_;
        m = m_;

        t.resize(n + 1, vector<int> (m + 1, 0));
        // base case:
        t[n - 1][m - 1] = 1;    // mark them as 1, as it's reaches to bottom-right

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                
                if(i == n - 1 && j == m - 1) continue;  // that's the base case, which we don't wanted to overwrite.

                int path = 0;
                if(j + 1 < m)  path += t[i][j + 1];
                if(i + 1 < n) path += t[i + 1][j];


                t[i][j] = path;
            }
        }

        return t[0][0];     // return the starting point.
    }
};


// Memoization: Simple version
class Solution {
private:
    int n, m;
    vector<vector<int>> t;
     int solve(int row, int col) {
        if(row == n - 1 && col == m - 1) return 1;  // reached destination

        if(t[row][col] != -1) return t[row][col];

        int path = 0;
        // Explore right
        if(col + 1 < m) {
            path += solve(row, col + 1);
        }

        // Explore down:
        if(row + 1 < n) {
            path += solve(row + 1, col);
        }

        return t[row][col] = path;
    }
public:
    int uniquePaths(int n_, int m_) {
        n = n_;
        m = m_;

        t.resize(n + 1, vector<int> (m + 1, -1));

        return solve(0, 0);
    }
};


// Memoization: Better version
class Solution {
private:
    int n, m;
    vector<vector<int>> t;
    int dir[2][2] = {{0, 1}, {1, 0}};   // right & down
    bool isValidDim(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    int solve(int row, int col) {
        if(row == n - 1 && col == m - 1) return 1;  // reached destination

        if(t[row][col] != -1) {
            return t[row][col];
        }

        int path = 0;
        for(int i = 0; i < 2; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];

            if(isValidDim(r, c)) {
                path += solve(r, c);
            }
        }

        return t[row][col] = path;
    }
public:
    int uniquePaths(int n_, int m_) {
        n = n_;
        m = m_;

        t.resize(n + 1, vector<int> (m + 1, -1));

        return solve(0, 0);
    }
};


// Recursive Solution:
class Solution {
private:
    int n, m;
    int dir[2][2] = {{0, 1}, {1, 0}};   // right & down
    bool isValidDim(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    int solve(int row, int col) {
        if(row == n - 1 && col == m - 1) return 1;  // reached destination

        int path = 0;
        for(int i = 0; i < 2; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];

            if(isValidDim(r, c)) {
                path += solve(r, c);
            }
        }

        return path;
    }
public:
    int uniquePaths(int n_, int m_) {
        n = n_;
        m = m_;


        return solve(0, 0);
    }
};