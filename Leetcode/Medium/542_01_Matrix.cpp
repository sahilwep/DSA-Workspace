/*

//  542. 01 Matrix

// Problem Statement:
    * Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
    * The distance between two adjacent cells is 1.

 

// Example:
    Example 1:
        Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
        Output: [[0,0,0],[0,1,0],[0,0,0]]

    Example 2:
        Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
        Output: [[0,0,0],[0,1,0],[1,2,1]]


// Approach:
    -> We will use two matrix:
        -> visited: to maintain the record of visited nodes.
        -> dist: final matrix that will contains the distance of cell having '1'.
    
    -> Initialize the BFS queue with all cells containing 1, & mark these cells as visited and initialize their distance as '0'
    -> keep removing every node from queue until queue is not empty:
        -> extract every node row, col, & step information..
        -> Update their distance in dist matrix.
        -> Check all possible 4 direction, & if any of the node is not is not visited, push that node into queue, with adding 1 extra step.
    
    -> Last return the dist matrix.


// Complexity:
    * TC: O(n*m)
    * AS: O(n*m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<vector<int>> dist(n, vector<int> (m, 0));

        // Initialize the BFS, with all cells containing '0', & mark them as visited
        queue<pair<pair<int, int>, int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){         // found all the '0's
                    q.push({{i, j}, 0});    // push into queue, with default distance as '0'
                    vis[i][j] = 1;          // mark them as visited
                }else{
                    vis[i][j] = 0;          // else mark them as unvisited
                }
            }
        }

        


        // Possible 4 direction indices:
        int delRow[] = {-1, +1, 0, 0};
        int delCol[] = {0, 0, -1, +1};


        // check & traverse until queue is not empty:
        while(!q.empty()){
            // extract current row, col, step, & pop out that element
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();    // remove element from queue

            dist[row][col] = step;  // update current element distance


            // iterate in all 4 direction & check:
            for(int i=0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                // check the new row & col is in valid bound & that node is not yet visited:
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && vis[nRow][nCol] == 0){
                    vis[nRow][nCol] = 1;    // mark as visited
                    q.push({{nRow, nCol}, step+1}); // push that node position with one extra step
                }
            }
        }


        return dist;
    }
};