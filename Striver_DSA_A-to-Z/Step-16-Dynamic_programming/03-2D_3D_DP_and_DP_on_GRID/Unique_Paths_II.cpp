/*

//  63. Unique Paths II


//  Problem Statement: 
    - You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
    - An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
    - Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
    - The testcases are generated so that the answer will be less than or equal to 2 * 109.

 
// Example:
    Example 1:
        Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
        Output: 2
        Explanation: There is one obstacle in the middle of the 3x3 grid above.
        There are two ways to reach the bottom-right corner:
        1. Right -> Right -> Down -> Down
        2. Down -> Down -> Right -> Right

    Example 2:
        Input: obstacleGrid = [[0,1],[0,0]]
        Output: 1



// Observations:
    - we have to reach from (0, 0) to (n - 1, m - 1)
    - we can only move right, or down
    - the given grid has obstacle
    - we need to find all the possible unique ways so that we can reach to destinations..

    // Approach:
        - We can use recursive solution to find the total number of path, as we have two options either go to down, or right.
        - Recursive solution will let's us know, with how many unique path we can reach to (n-1, m-1)
            // Function signature:
                - we will have to return total number of path, so, we will return with int type.
                - {row, col} these two values are changing in range (0 <= row <= n - 1) & (0 <= col <= m - )

                int solve(row, col, grid) {
                    ...
                }
            
            // Base conditions:
                - If we reach at destinations, i.e (n - 1, m - 1) return '1'
                if(row == n - 1 && col == m - 1) return 1;

            // Decision tree:
                - initially path = 0;
                - we can only explore if grid path has no-obstacle & it's lies in valid index.
                // right:
                    - if (col + 1 < m && grid[row][col] == 0): we can explore in right directions, (col + 1) used to check valid next index for col
                        path += solve(row, col + 1, grid);
            
                // down:
                    - if (row + 1 < n  && grid[row][col] == 0): we can explore in right directions, (row + 1) used to check valid next index for col
                        path += solve(row + 1, col, grid);
                    
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
                    if(j + 1 < m && grid[i][j + 1] == 0) right = t[i][j + 1]
                    if(i + 1 < n && grid[i + 1][j] == 0) down = t[i + 1][j];

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


// Tabulations Solution:
class Solution {
private:
    int n, m;
    typedef long long ll;
    vector<vector<ll>> t;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Case: if starting || ending position has obstacle.
        if(grid[0][0] == 1) return 0;
        if(grid[n-1][m-1] == 1) return 0;

        t.resize(n + 1, vector<ll> (m + 1, 0));

        // Fill the base case:
        t[n - 1][m - 1] = 1;    
        
        // Start from the last cell:
        for(int i = n - 1; i >= 0; i--) { 
            for(int j = m - 1; j >= 0; j--) {
                if(i == n - 1 && j == m - 1) continue;  // skip, to prevent overwriting the base case.

                ll right = (j + 1 < m && grid[i][j + 1] == 0) ? t[i][j + 1] : 0; // explore right
                ll down = (i + 1 < n && grid[i + 1][j] == 0) ?  t[i + 1][j] : 0; // explore down

                t[i][j] = right + down;
            }
        }

        return (int)t[0][0]; // starting point.
    }
};


// Memoization: Simple version
class Solution {
private:
    int n, m;
    vector<vector<int>> t;
    int solve(int row, int col, vector<vector<int>>& grid) {
        if(row == n - 1 && col == m - 1) return 1;    // found valid path.

        if(t[row][col] != -1) return t[row][col];

        int path = 0;
        // Right:
        if(col + 1 < m && grid[row][col + 1] == 0) {
            path += solve(row, col + 1, grid);
        }

        // down:
        if(row + 1 < n && grid[row + 1][col] == 0) {
            path += solve(row + 1, col, grid);
        }

        return t[row][col] = path;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();

        // Case: if starting || ending position has obstacle.
        if(obstacleGrid[0][0] == 1) return 0;
        if(obstacleGrid[n-1][m-1] == 1) return 0;

        t.resize(n + 1, vector<int> (m + 1, -1));

        return solve(0, 0, obstacleGrid);
    }
};


// Memoization Solution: More Refined Version:
class Solution {
private:
    int n, m;
    vector<vector<int>> t;
    int dir[2][2] = {{0, 1}, {1, 0}};   // right, down
    bool isValidDim(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    int solve(int row, int col, vector<vector<int>>& grid) {
        if(row * m + col == n * m - 1) return 1;    // found valid path.

        if(t[row][col] != -1) return t[row][col];

        int path = 0;
        for(int i = 0; i < 2; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];

            if(isValidDim(r, c) && grid[r][c] == 0)  {  // is valid dim & path to travel
                path += solve(r, c, grid);
            }
        }

        return t[row][col] = path;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();

        // Case: if starting || ending position has obstacle.
        if(obstacleGrid[0][0] == 1) return 0;
        if(obstacleGrid[n-1][m-1] == 1) return 0;

        t.resize(n + 1, vector<int> (m + 1, -1));

        return solve(0, 0, obstacleGrid);
    }
};

// Recursive Solution:
class Solution {
private:
    int n, m;
    int dir[2][2] = {{0, 1}, {1, 0}};   // right, down
    bool isValidDim(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    int solve(int row, int col, vector<vector<int>>& grid) {
        if(row * m + col == n * m - 1) return 1;    // found valid path.

        int path = 0;
        for(int i = 0; i < 2; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];

            if(isValidDim(r, c) && grid[r][c] == 0)  {  // is valid dim & path to travel
                path += solve(r, c, grid);
            }
        }

        return path;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();

        // Case: if starting || ending position has obstacle.
        if(obstacleGrid[0][0] == 1) return 0;
        if(obstacleGrid[n-1][m-1] == 1) return 0;

        return solve(0, 0, obstacleGrid);
    }
};