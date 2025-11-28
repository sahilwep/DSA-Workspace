/*

//  62. Unique Paths

//  Problem Statement: 
    - There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
    - Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
    - The test cases are generated so that the answer will be less than or equal to 2 * 109.
 

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

// Graph Solution: 
    - Initially i think to solve this problem using graph, & solved, but falls into TLE.
    - Then, i looked for DP solution, as we are recomputing the subproblems...

// Observations: 
    - we are starting from [0][0]
    - we need to reach [n-1][m-1], bottom right
    - we can only take either right, or bottom..
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

// Memoization Solution: 
class Solution {
private: 
    int mod = 2 * 1e9;
    int n, m;
    vector<vector<int>> t;
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    int solve(int row, int col) {
        if(row == n - 1 && col == m - 1) {
            return 1;   // return 1 as ways.
        }

        if(t[row][col] != -1) return t[row][col];

        int ways = 0;
        if(isValid(row, col)) {
            ways = (ways + solve(row + 1, col)) % mod;  // down
            ways = (ways + solve(row, col + 1)) % mod;  // right
        }

        return t[row][col] = ways;
    }
public:
    int uniquePaths(int n_, int m_) {
        n = n_;
        m = m_;

        t.resize(n + 1, vector<int> (m + 1, - 1));

        return solve(0, 0);
    }
};

// Recursive Solution:
class Solution {
private: 
    int mod = 2 * 1e9;
    int n, m;
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    int solve(int row, int col) {
        if(row == n - 1 && col == m - 1) {
            return 1;   // return 1 as ways.
        }

        int ways = 0;
        if(isValid(row, col)) {
            ways = (ways + solve(row + 1, col)) % mod;  // down
            ways = (ways + solve(row, col + 1)) % mod;  // right
        }

        return ways;
    }
public:
    int uniquePaths(int n_, int m_) {
        n = n_;
        m = m_;

        return solve(0, 0);
    }
};


// Graph Solution (DFS)
class Solution {
private:
    int n, m;
    int dir[2][2] = {{0, 1}, {1, 0}};   // right, down
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if(row == n - 1 && col == m - 1) return 1;

        vis[row][col] = 1;
        int path = 0;

        for(int i = 0; i < 2; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];

            if(isValid(r, c) && !vis[r][c]) {
                path += dfs(r, c, grid, vis);
            }
        }
        vis[row][col] = 0;

        return path;
    }
public:
    int uniquePaths(int n_, int m_) {
        n = n_, m = m_;
        
        vector<vector<int>> grid(n, vector<int> (m, 0));
        vector<vector<int>> vis(n, vector<int> (m, 0));

        return dfs(0, 0, grid, vis);
    }
};