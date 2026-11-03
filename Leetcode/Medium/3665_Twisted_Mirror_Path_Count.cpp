/*

//  3665. Twisted Mirror Path Count


//  Problem Statement: 




// Observations:
    - given grid of dimension n x m
    - 0 = empty cell
    - 1 = mirror

    - robot start from (0, 0) and wanted to reach at (n - 1, m - 1)
    - we can only move right and down.
        - if we attempts to move into mirror cell, it is reflected before entering the cell.
            - if it tries to move right into the mirror: it is turned down and moved into the new cell directly below the mirror.
            - If it tries to move down into a mirror, it turned right and moved into the cell to right of the mirror.
    
    - if this reflection would cause the robot to move outside the grid boundaries, the path is considered invalid, and should not be counted.
    
    - Return the number of unique valid path from (0, 0) to (n - 1, m - 1).

    - Since the answer may be very large return it modulo 1e9 + 7.

    - NOTE: if a reflection moves the robot into a mirror cell, the robot is immediately reflected again based on the direction it used to enter that mirror. 
        - If it entered while moving right, it will be turned down,
        - If it entered while moving down, it will be turned right.
        - This process will continue until either the last cell is reached, the robot moves out of the bounds of the robot moves to a non-mirror cell.




    // Approach:
        - We will start from (0, 0) and try reaching to destinations: (n - 1, m -1)
        - and we will have to count the total number of path to visit the destinations.
        - we can write the recursive solution: 
        - We can write a recursive function which return the integer as total number of path:
            int solve(row, col, grid) {
            
            }

            - base case:
                - if row == n -1 && col == m - 1:
                    - 1 path found: return 1.
            
            - Decision Tree:
                path = 0;

                // Two choices: right & down:
                // right:
                if(col + 1 < m) {
                    // check cell value:
                    if(grid[row][col + 1] == 0) {   // empty cell:
                        path += solve(row, col + 1, grid);
                    } else { // cell is mirror: now check down side:
                        if(row + 1 < n) {
                            path += solve(row + 1, col + 1, grid);
                        }
                    }
                }

                // down:
                if(row + 1 < n) {
                    // check cell value:
                    if(grid[row + 1][col] == 0) {   // empty cell:
                        path += solve(row + 1, col, grid);
                    } else {    // cell is mirror: now check the right cell:
                        if(col + 1 < m) {
                            path += solve(row + 1, col + 1, grid);
                        }
                    }
                }


                return path;


        - That's all for now, let's try to implement, later on we can optimize..
        - One thing we miss judge is that we will continue travel on the 1's until we not reach to the cell where value is '0':
        
        
        - NOTE: In that case our above solution is wrong:

        - We will have to write a solution that maintain the direction where we are moving, and also move accordingly..
        - So, this time we will maintain he value which is dir: 
            - dir = 0, 1:
                0 = right
                1 = down
            - and for every cell:
                - we will check the cell value:
                    if cell values is: 
                        - grid[i][j] = 0: now we are free from the direction: we can move in right and down:
                        - grid[i][j] = 1:
                            we will have to continue moving on the cell until we not reach to the grid[i][j] = 0;

            - solution falls into tle:
                we will have to memoize this as subproblems are recomputing:
                - variable values:
                    row, col, dir:

                    2 <= row <= n
                    2 <= col <= m
                    0 <= dir <= 2

                    dp table of dimension n * m * dir



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    vector<vector<vector<int>>> t;
    int n, m;
    int mod = 1e9 + 7;
    int solve(int row, int col, int dir, vector<vector<int>>& grid) {
        // base case: 
        if(row >= n || col >= m) return 0;          // no-path to explore
        if(row == n - 1 && col == m - 1) return 1;  // reach to destination.

        // Check in dp table:
        if(t[row][col][dir] != -1) {
            return t[row][col][dir];
        }

        // Decision tree:
        int path = 0;

        // Check the cell value:
        if(grid[row][col] == 0) {   // we can move freely: two choices: right and down:
            // right:
            path = (path + solve(row, col + 1, 0, grid)) % mod;

            // down:
            path = (path + solve(row + 1, col, 1, grid)) % mod;

        } else {    // we are following the previous path:
            if(dir == 0) {  // last move was right, means we will have to go down:
                path = (path + solve(row + 1, col, 1, grid)) % mod;   // change the direction, as we wer going to down.
            } else {    // last move was down, means we will have to go right:
                path = (path + solve(row, col + 1, 0, grid)) % mod;   // change the direction, as we are moving to right.
            }
        }

        return t[row][col][dir] = path;
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        t.resize(n + 1, vector<vector<int>> (m + 1, vector<int> (2, -1)));

        return solve(0, 0, 0, grid);
    }
};