/*

//  64. Minimum Path Sum


//  Problem Statement: 
    - Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
    - Note: You can only move either down or right at any point in time.

 
// Example: 
    Example 1:
        Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
        Output: 7
        Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

    Example 2:
        Input: grid = [[1,2,3],[4,5,6]]
        Output: 12

    
// Observations:
    - We have to start from (0, 0) & reach (n - 1, m - 1)
    - We can either travel right || OR || down
    - We need to choose the minimum sum during the path, by reaching destinations..

    // Recursive Solution:
        - Recursion helps to travel from (0, 0) to (n - 1, m - 1) & during the travel, we can accumulate the path sum..
        // Function Signature:
            - we need to return min-sum => int return type
            - every time row & col fo the grid change.

                    solve(int row, int col, vector<vector>>& grid) {
                        ...
                    }

        // base case:
            if(row == n - 1 && col == m - 1) {
                return grid[row][col];      // as we reach to destinations, we need to return the last cell value, so that we can add that into our sum..
            }

        // Decision Tree:
            - From every state/Recursive call we have two choices:
            - Either go right

                if(col + 1 < m) {
                    right = grid[row][col] + solve(row, col + 1, grid);
                }

            - Either go down

                if(row + 1 < n) {
                    down = grid[row][col] + solve(row + 1, col, grid);
                }

            - Last we have to choose what is the min-options for this current state | OR | what's the min-values we have gotten from the future calls.

                return min(right, down);

        // Complexity:
            - TC: O(2^(n * m))  -> For choices..
            - SC: O(n * m)      -> for depth of stack..
            - Falls into TLE


        // Optimization: 
            - Memoize the current solution.
            - Variable values:
                row, col
                    0 <= row <= n
                    0 <= col <= m
            - Memo-table of size (n * m)
            - For every transition/recursive calls check in memo-table:
                if(t[row][col] != SOME_DEFAULT_VAL) return t[row][col];
            - Store the answer in memo-table before returning..
                return t[row][col] = ans;

            // Complexity:
                - TC: O(n * m)
                - SC: O(n * m)


        // Tabulations:
            - Removing Recursive calls Completely:
            // DP State:
                row, col
                    0 <= row <= n
                    0 <= col <= m

            // DP Transitions:

                int right = (col + 1 < m) ? grid[row][col] + t[row][col + 1] : INT_MAX;
                int down = (row + 1 < n) ? grid[row][col] + t[row + 1][col] : INT_MAX;

                t[row][col] = min(right, down);

            // Iterations:
                n - 1 <= i <= 0
                m - 1 <= j <= 0

            // Base case:
                t[n-1][m-1] = grid[n-1][m-1]

            - last return at the t[0][0] value

            // Complexity:
                - TC: O(n * m)
                - SC: O(n * m)




// Extra:
    - This problem can also be solved using Dijkstra's
    - Solution: LC: 64      ->      https://github.com/sahilwep/DSA-Workspace/blob/main/Leetcode/Medium/64_Minimum_Path_Sum.cpp


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
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        t.resize(n + 1, vector<int> (m + 1, 0));
        
        t[n-1][m-1] = grid[n-1][m-1];   // fill the base case:
        for(int row = n - 1; row >= 0; row--) {
            for(int col = m - 1; col >= 0; col--) {
                if(row == n - 1 && col == m - 1) continue;  // skip, prevent overwriting base case.

                int right = (col + 1 < m) ? grid[row][col] + t[row][col + 1] : INT_MAX;
                int down = (row + 1 < n) ? grid[row][col] + t[row + 1][col] : INT_MAX;

                t[row][col] = min(right, down);
            }
        }

        return t[0][0];     // return starting point as our answer.
    }
};

// Memoization:
class Solution {
private:
    int n, m;
    vector<vector<int>> t;
    int solve(int row, int col, vector<vector<int>>& grid) {
        if(row == n - 1 && col == m - 1) {  // reached destinations.
            return grid[row][col];
        }

        // Check in Memo-table:
        if(t[row][col] != -1) {
            return t[row][col];
        }

        // Go-Right:
        int right = (col + 1 < m) ? grid[row][col] + solve(row, col + 1, grid) : INT_MAX;

        // Go-Down:
        int down = (row + 1 < n) ? grid[row][col] + solve(row + 1, col, grid) : INT_MAX;

        return t[row][col] =  min(right, down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        t.resize(n + 1, vector<int> (m + 1, -1));

        return solve(0, 0, grid);
    }
};

// Recursive Solution:
class Solution {
private:
    int n, m;
    int solve(int row, int col, vector<vector<int>>& grid) {
        if(row == n - 1 && col == m - 1) {  // reached destinations.
            return grid[row][col];
        }

        // Go-Right:
        int right = (col + 1 < m) ? grid[row][col] + solve(row, col + 1, grid) : INT_MAX;

        // Go-Down:
        int down = (row + 1 < n) ? grid[row][col] + solve(row + 1, col, grid) : INT_MAX;

        return min(right, down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        return solve(0, 0, grid);
    }
};


// ---------------------- Graph Dijkstra's Solution ------------------------------


// Graph Solution:
class Solution {
private: 
    typedef pair<int, pair<int, int>> ppr;
    int n, m;
    int dir[2][2] = {{0, 1}, {1, 0}};   // right, down
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
public:
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        priority_queue<ppr, vector<ppr>, greater<>> pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while(!pq.empty()) {
            auto [cost, cor] = pq.top();
            pq.pop();

            int row = cor.first;
            int col = cor.second;

            if(row == n - 1 && col == m - 1) return cost;
            if(cost > dist[row][col]) continue;

            for(int i = 0; i < 2; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];
                
                if(isValid(r, c)) {
                    int newCost = cost + grid[r][c];

                    if(newCost < dist[r][c]) {
                        dist[r][c] = newCost;
                        pq.push({newCost, {r, c}});
                    }
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};
