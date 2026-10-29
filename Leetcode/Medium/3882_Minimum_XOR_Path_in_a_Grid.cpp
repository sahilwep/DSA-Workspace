/*

//  3882. Minimum XOR Path in a Grid



//  Problem Statement: 
    - You are given a 2D integer array grid of size m * n.
    - You start at the top-left cell (0, 0) and want to reach the bottom-right cell (m - 1, n - 1).
    - At each step, you may move either right or down.
    - The cost of a path is defined as the bitwise XOR of all the values in the cells along that path, including the start and end cells.
    - Return the minimum possible XOR value among all valid paths from (0, 0) to (m - 1, n - 1).

    
 
// Example:
    Example 1:
        Input: grid = [[1,2],[3,4]]
        Output: 6
        Explanation:
            There are two valid paths:
                (0, 0) → (0, 1) → (1, 1) with XOR: 1 XOR 2 XOR 4 = 7
                (0, 0) → (1, 0) → (1, 1) with XOR: 1 XOR 3 XOR 4 = 6

            The minimum XOR value among all valid paths is 6.

    Example 2:
        Input: grid = [[6,7],[5,8]]
        Output: 9
        Explanation:
            There are two valid paths:
                (0, 0) → (0, 1) → (1, 1) with XOR: 6 XOR 7 XOR 8 = 9
                (0, 0) → (1, 0) → (1, 1) with XOR: 6 XOR 5 XOR 8 = 11
            The minimum XOR value among all valid paths is 9.

    Example 3:
        Input: grid = [[2,7,5]]
        Output: 0
        Explanation:
            There is only one valid path:
                (0, 0) → (0, 1) → (0, 2) with XOR: 2 XOR 7 XOR 5 = 0
            The XOR value of this path is 0, which is the minimum possible.

 




// Observations:
    - given 2d grid of n x m
    - start = (0, 0), and end = (n - 1, m - 1)
    - each step you may move: right, down
    - the cost of a path is defined as the bitwise XOR of all the values in the cells along that path including that start and end cells.
    - return the minimum possible XOR values among all valid path from start to end.

    // Approach:
        - write simple recursive dfs solution, to explore right and down.
        - and try fetching the value that is minimum:
            - we have base case:
                when we reach to destination:
                    return the XOR taken in whole path.
            - We have decision tree:
                right:
                down:

        - Here, it's different than the traditional recursive solution, because, we will try making XOR during all the path traversal,
            - Our traditional solution looks like:

                        int solve(row, col, grid) {
                            if(row == n - 1 && col == m - 1) return grid[row][col];

                            // Down:
                            int down = grid[row][col];
                            if(row + 1 < n) {
                                down ^= solve(row + 1, col, grid);
                            }

                            // right:
                            int right = grid[row][col];
                            if(col + 1 < m) {
                                right ^= solve(row, col + 1, grid);
                            }

                            return min(down, right);
                        }

                    - Here, we used to take XOR, and computing the minimum value at every state..
                    - This solution calculates the XOR of paths recursively, 
                    - but each recursive call returns only one value: the minimum XOR among paths from that cell to the destination.   
                    - That is where information gets lost.
                    - This fails because it takes minimum value to-early.

            - this is why we maintain temp variable, which will store the XOR till reaching the destinations.
            - Here, temp carries the XOR accumulated from the starting cell to the current cell.

        - THis solution gives TLE:
            - writing the memoization:
                - variable values: 
                    n, m, temp
                    1 <= n, m, <= 1000
                    1 <= temp <= 1024, because XOR can reach to maximum value only, which is 1023, for grid[i][j]

                
                    // Complexity:
                        - TC: O(n * m * temp)
                        - SC: O(n * m * temp)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    int n, m;
    vector<vector<vector<int>>> dp;
    int solve(int row, int col, int temp, vector<vector<int>>& grid) {
        temp ^= grid[row][col];                         // include current cell XOR in path.

        if(row == n - 1 && col == m - 1) return temp;   // return the XOR made in path while reaching to destinations.

        // check in memo-table:
        if(dp[row][col][temp] != -1) {
            return dp[row][col][temp];
        }

        // right:
        int right = (col + 1 < m) ? solve(row, col + 1, temp, grid) : INT_MAX;

        // Down:
        int down = (row + 1 < n) ? solve(row + 1, col, temp, grid) : INT_MAX;

        return dp[row][col][temp] = min(right, down);
    }
public:
    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        dp.resize(n + 1, vector<vector<int>> (m + 1, vector<int> (1024, -1)));

        return solve(0, 0, 0, grid);
    }
};


