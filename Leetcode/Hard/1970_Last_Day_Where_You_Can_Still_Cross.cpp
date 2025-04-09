/*

//  1970. Last Day Where You Can Still Cross


//  Problem Statement: 
    -> There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.
    -> Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).
    -> You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).
    -> Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.


// Example: 

    Example 1:

        Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
        Output: 2
        Explanation: The above image depicts how the matrix changes each day starting from day 0.
        The last day where it is possible to cross from top to bottom is on day 2.

    Example 2:

        Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
        Output: 1
        Explanation: The above image depicts how the matrix changes each day starting from day 0.
        The last day where it is possible to cross from top to bottom is on day 1.

    Example 3:

        Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
        Output: 3
        Explanation: The above image depicts how the matrix changes each day starting from day 0.
        The last day where it is possible to cross from top to bottom is on day 3.


// Observations: 
    -> We are given 1-based index grid, with all cells = '0' initially.
    -> We are also given some query cells => denotes we have to overwrite grid with ''1''
    -> We need to return the lastDay/lastQuery on which we can move from first row to last Row.

    // BruteForce Approach: 
        -> Get the query & process it.
        -> Alongside on every query check whether we can reach from first row to last row or not with any BFS/DSF traversal..
        -> Gives TLE, because for every query we are iterating that.

        // Complexity:
            -> TC: O((n * m) * (n * m)) => (n^2 * m^2)
            -> SC: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;



// BruteForce Solution: TLE
class Solution {
private:
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    bool canGo(vector<vector<int>> &grid) { // This function will try to check, wether we can go from first row to last row?
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));

        for(int i = 0; i < m; i++) {
            if(!grid[0][i]) {
                q.push({0, i});
                vis[0][1] = 1;
            }
        }

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            if(row == n - 1) return true;

            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(isValid(r, c) && !vis[r][c] && !grid[r][c]) {
                    vis[r][c] = 1;

                    q.push({r, c});
                }
            }
        }

        return false;   // can't reach that positions.
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n = row, m = col;
        vector<vector<int>> grid(n, vector<int> (m, 0));

        int lastDay = 0;
        for(auto &it: cells) {
            int i = it[0] - 1, j = it[1] - 1;
            grid[i][j] = 1; // mark that cell as true; 
            
            // Now check in grid whether it's possible to reach last row:
            if(canGo(grid)) lastDay++;
            else break;
        }


        return lastDay;
    }
};