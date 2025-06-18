/*

//  79. Word Search

//  Problem Statement: 
    -> Given an m x n grid of characters board and a string word, return true if word exists in the grid.
    -> The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring.
    -> The same letter cell may not be used more than once.

// Example:

    Example 1:
        Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
        Output: true

    Example 2:
        Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
        Output: true

    Example 3:
        Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
        Output: false



// Approach:
    -> we will start with starting character of string from matrix:
    -> We will take string characters one by one & try to match with every characters of string.
    -> We can use any traversal algorithm like DFS or BFS
    -> use position pointer to match every characters of string, & if position pointer reaches to last index of string, means we have successfully matches all the characters of string -> In this case return true.


// Complexity:
    -> TC: O(n*m)
    -> SC: O(n*m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// DFS Solution: 
/*

    -> BFS Fails here, because bfs will not backtrack if the solution fails.

        [["A","B","C","E"]
        ,["S","F","E","S"]
        ,["A","D","E","E"]]

    "ABCESEEEFS"

*/
class Solution {
private: 
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    bool dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis, int pos, string& word) {
        if(pos == word.size() - 1) return true; // reaches to end

        vis[row][col] = 1;

        for(int i = 0; i < 4; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];

            if(isValid(r, c) && !vis[r][c]) {
                if(board[r][c] == word[pos + 1]) {
                    if(dfs(r, c, board, vis, pos + 1, word)) return true;
                }
            }
        }

        vis[row][col] = 0;  // mark as unvisited, while backtracking.

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && word[0] == board[i][j]) {
                    if(dfs(i, j, board, vis, 0, word)) return true;
                }
            }
        }

        return false;
    }
};


// DFS Approach:
class Solution {
private:
    int delRow[4] = {-1, +1, 0, 0};
    int delCol[4] = {0, 0, -1, +1};
    bool solve(int row, int col, vector<vector<char>>& board, string word, int pos, vector<vector<int>>& vis){
        // Base case: if we have reaches till the word size, means we have successfully match all the characters.
        if(pos == word.size()-1) return true;
        
        vis[row][col] = 1;  // mark that path as visited
        
        int n = board.size();
        int m = board[0].size();
        
        // Check adjacent nodes:
        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            // Check valid range:
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m){
                // Check node not-visited & next element of string:
                if(!vis[nRow][nCol] && board[nRow][nCol] == word[pos+1]){
                    if(solve(nRow, nCol, board, word, pos+1, vis) == true) return true;   // if this call return true, return true to parent.              
                }
            }
        }

        vis[row][col] = 0;  // unmark that path, so that next time we can visit again, if we won't found the string.
        return false;       // return false for not found
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
    
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        // Traverse every element of board:
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j] == word[0]){
                    if(solve(i, j, board, word, 0, vis)) return true;
                }
            }
        }

        return false;
    }
};