/*

//  1260. Shift 2D Grid


//  Problem Statement: 
    - Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.
    - In one shift operation:
        - Element at grid[i][j] moves to grid[i][j + 1].
        - Element at grid[i][n - 1] moves to grid[i + 1][0].
        - Element at grid[m - 1][n - 1] moves to grid[0][0].
    - Return the 2D grid after applying shift operation k times.


// Example:
    Example 1:
        Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
        Output: [[9,1,2],[3,4,5],[6,7,8]]

    Example 2:
        Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
        Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]

    Example 3:
        Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
        Output: [[1,2,3],[4,5,6],[7,8,9]]



// Observations:
    - for grid n * m
    - get the cell number from row and col
        cell no = row * m + col

    - increment the cell number by the k position
        new cell no = (cell no + k) % (n * m)   -> we will round it so that, by addition we don't want to go out of bound..

    - now, get the row, col from the cell number
        row = cellNo / m
        col = cellNo % m
    


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Approach:
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n, vector<int> (m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cellNo = i * m + j; // get cell no

                int newCellNo = (cellNo + k) % (n * m);     // get new cell no and round it by the grid size.

                // Get the current row, col:
                int row = newCellNo / m;
                int col = newCellNo % m;

                // Place the value at the intended position:
                ans[row][col] = grid[i][j];

            }
        }


        return ans;
    }
};



// Bruteforce approach:
class Solution {
private:
    int n, m;
    void moveByOne(vector<vector<int>>& grid) {

        int last = grid[n - 1][m - 1];
        vector<vector<int>> ans(n, vector<int> (m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(j < m - 1) {
                    ans[i][j + 1] = grid[i][j];
                } else {
                    if(i < n - 1) {
                        ans[i + 1][0] = grid[i][j];
                    }
                }
            }
        }

        ans[0][0] = last;
        grid = ans;
    }
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        while(k--) {
            moveByOne(grid);
        }

        return grid;
    }
};