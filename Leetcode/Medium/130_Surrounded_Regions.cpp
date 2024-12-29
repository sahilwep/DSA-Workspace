/*

//  130. Surrounded Regions

//  Problem Statement: 
    -> You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
        -> Connect: A cell is connected to adjacent cells horizontally or vertically.
        -> Region: To form a region connect every 'O' cell.
        -> Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.

    -> To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 
// Example:
    Example 1:
        Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
        Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
        Explanation: In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

    Example 2:
        Input: board = [["X"]]
        Output: [["X"]]


// Observation:
    -> If someone is on the boundary, that is where he cannot be covered.
    -> 'O' are bound to be surrounded by 'X' then only we can fill it with 'X'
    -> If set of 'X' is connected by a boundary, it cannot be surrounded by 'X'.


    // Approach:
        -> If we start with boundary 0's and traverse all the connected 0's, & mark then they will not be converted, then our job is done.
        -> Create a temporary matrix & assume all the value are convertble, so fill it with 'X'.
        -> Iterate in boundary & use dfs and mark all the connected nodes with '0's


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<char>>& temp, vector<vector<int>>& vis){
        vis[row][col] = 1;      // mart that current node as visited
        temp[row][col] = 'O';   // mark that node as not possible to convert
        
        int n = board.size();
        int m = board[0].size();
        
        int delRow[] = {-1, +1, 0, 0};
        int delCol[] = {0, 0, -1, +1};
        
        // iterate in all 4 directions:
        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            // checking valid range, valid values, & not-visited yet
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && board[nRow][nCol] == 'O' && !vis[nRow][nCol]){
                dfs(nRow, nCol, board, temp, vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<char>> temp(n, vector<char> (m, 'X'));
        vector<vector<int>> vis(n, vector<int> (m, 0));

        // Iterate in corners & mark all 'O's as not replicable
        // first & last row:
        for(int i=0;i<m;i++){
            // first row:
            if(board[0][i] == 'O' && !vis[0][i]){
                dfs(0, i, board, temp, vis);
            }
            // last row:
            if(board[n-1][i] == 'O' && !vis[n-1][i]){
                dfs(n-1, i, board, temp, vis);
            }
        }
        
        // First & last Col:
        for(int i=0;i<n;i++){
            // first row:
            if(board[i][0] == 'O' && !vis[i][0]){
                dfs(i, 0, board, temp, vis);
            }
            // last row:
            if(board[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(i, m-1, board, temp, vis);
            }
        }
        
        board = temp;   // last assign temp value to board
    }
};