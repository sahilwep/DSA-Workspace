/*

// 994. Rotting Oranges



// Problem Statement:
    * You are given an m x n grid where each cell can have one of three values:
        0 representing an empty cell,
        1 representing a fresh orange, or
        2 representing a rotten orange.

    * Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
    * Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
    * If this is impossible, return -1.



// Observation:
    0 => empty cell
    1 => fresh orange
    2 => rotten orange

    -> we need to check whether it' possible rotten all fresh orange in minimum second...
    -> If it's possible that we can mark all fresh orange to rotten, we will return that minimum time, else we will return '-1'
    -> from any given nodes we can move in all 4 direction(up, down, left, right)
    
    -> For moving nodes one by one, it's better to use BFS -> Level wise traversal.
    
    -> We need to start filling all the neighbour of rotten at same time, 
        -> means, initially we need to get all the location of rotten oranges..
    
    -> Then we start iterate all the rotten neighbors at the same time.


// Complexity:
    * TC: O(n*m)
    * AS: O(n*m)


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Step 1: Get all the rotten oranges form grid:
        queue<pair<pair<int, int>, int>> q; // queue used to maintain get all the location of rotten oranges.
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int freshCnt = 0;   // variable use to check whether we are able to mark all fresh 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){        // if we got any rotten oranges:
                    q.push({{i, j}, 0});    // pushing nodes location with time, initally time is 0
                    vis[i][j] = 2;          // marking rotten in visited array also.
                }else{
                    vis[i][j] = 0;          // else marking all with '0'
                }
                if(grid[i][j] == 1){        // if we got any fresh orange
                    freshCnt++;             // increment fresh count
                }
            }
        }

        /*     possible '4' direction:   
                                (row-1, col)
                                        |
                (row, col-1) <- (row, col) -> (row, col+1)
                                        |
                                (row+1, col)
        */
        int delRow[] = {-1, +1, 0, 0};
        int delCol[] = {0, 0, -1, +1};


        // Step 2: Mark all the neighbours of rotten in minimal time:
        int tm = 0;                 // variable to maintian minimum time to mark all the rotten oranges
        int freshPushedCnt = 0;     // varaible that count all the fresh oranges which pushed into queue
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int timE = q.front().second;

            tm = max(tm, timE);     // get the maximum time.
            q.pop();                // removing element from the queue


            // mark all the fresh oranges in all '4' direction:
            for(int i=0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                vis[nRow][nCol] == 0 && grid[nRow][nCol] == 1){
                    q.push({{nRow, nCol}, timE + 1});   // insert fresh oranges in queue, for furthe checkups
                    freshPushedCnt++;                   // as we have pushed fresh orange into queue, let's increment the counter, so that in last we can compare whether all the oranges are rotten or not?
                    vis[nRow][nCol] = 1;                // mark that fresh oranges as 1 in visited matrix.
                }
            }
        }


        if(freshCnt != freshPushedCnt) return -1;       // if all the oranges are not rotten

        return tm; // return minimum time
    }
};