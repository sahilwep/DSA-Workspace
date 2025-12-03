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
    - we are starting from [0][0]
    - we need to reach [n-1][m-1], bottom right
    - There is an obstacle in a path representing '1'
    - Empty path represent as '0'
    - we need to return total number of unique path / total number of ways..

    // We can write the recursive solutions, then we cna memoize that solutions, and then we can optimize further, by tabulations...

        // valid move:
            - First check either we are in correct bound (0 - (n - 1) && (0 - (m - 1))
                - If we are then, move right and move down
                - store their ways.
            - Ways is counted once we reach to target locations:
                - if(row == n - 1 && col == m - 1) return 1;    -> return 1 as 1 ways to reach vis this path...
        
        // Memoization: 
            - row & col are the two value which are varying..
            - Make a dp table of these values..
            - Store the subproblems & then return that directly without going into recursive calls..
            
        // Complexity: 
            - TC: O(n * m)
            - SC: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Dp Solution: 
class Solution {
private: 
    int mod = 2 * 1e9;
    int n, m;
    vector<vector<int>> t;
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    int solve(int row, int col, vector<vector<int>>& grid) {
        if(row == n - 1 && col == m - 1) {
            return 1;   // return 1 as ways.
        }

        if(t[row][col] != -1) return t[row][col];

        int ways = 0;
        if(isValid(row, col)) {
            if(row + 1 < n && grid[row + 1][col] == 0) {
                ways = (ways + solve(row + 1, col, grid)) % mod;  // down
            }
            if(col + 1 < m && grid[row][col + 1] == 0) {
                ways = (ways + solve(row, col + 1, grid)) % mod;  // right
            }
        }

        return t[row][col] = ways;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        n = obstacleGrid.size();
        m = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1) return 0;
        if(obstacleGrid[n-1][m-1] == 1) return 0;

        t.resize(n + 1, vector<int> (m + 1, - 1));

        return solve(0, 0, obstacleGrid);
    }
};


// Graph Solution:
class Solution {
private: 
    typedef pair<int, int> pr;
    int n, m;
    int dir[2][2] = {{0, 1}, {1, 0}}; 
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if(row == n - 1 && col == m - 1)  { // if reaches to destinations:
            return 1;
        }

        vis[row][col] = 1;  // mark as visited
        int path = 0;

        for(int i = 0; i < 2; i++) {    // Iterate in only 2 directions: right & down
            int r = row + dir[i][0];
            int c = col + dir[i][1];

            if(isValid(r, c) && !vis[r][c] && !grid[r][c]) {
                path += dfs(r, c, grid, vis);
            }
        }

        vis[row][col] = 0;  // backtrack
        return path;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;

        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        return dfs(0, 0, grid, vis);
    }
};
