/*

//  1091. Shortest Path in Binary Matrix


//  Problem Statement: 
    -> Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
    -> A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
        -> All the visited cells of the path are 0.
        -> All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
    -> The length of a clear path is the number of visited cells of this path.

    
// Example: 
    Example 1:
        Input: grid = [[0,1],[1,0]]
        Output: 2

    Example 2:
        Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
        Output: 4

    Example 3:
        Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
        Output: -1


// Observation: 
    -> Simillar as binary maze Type problem:
    -> We are given source & destination path.
    -> We can move in all 8 directions.
    -> for every steps to adjacent cost '1'
    -> We can use dijkstra algorithm to solve this question.
    -> Since the cost for every adjacent is '1', no need to use priority queue, instead we can use queue.

    -> Since, we need to traverse in all eight directions: 

                                        (-1, -1)   (-1, 0)   (-1, 1)
                                                \     |    /
                                        (0, -1) <- (0, 0) -> (0, 1)
                                                /     |    \
                                        (1, -1)    (1, 0)    (1, 1)
                    Traverse:
                        row => -1 to +1
                        col => -1 to +1


// Edge case: 
    -> Check valid source point
    -> Check if we are at destination.
    
    

// Complexity: 
    -> TC: O(n * m)
    -> SC: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/*
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Edge Cases:
        if(grid[0][0] == 1) return -1;  // Check the case if starting node is not valid:
        // also check if start & end is same:
        if(0 == n-1 && 0 == m-1) return 1;  // return 1 as steps.


        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        queue<pair<int, pair<int, int>>> q;

        int srcRow = 0;
        int srcCol = 0;

        q.push({1, {srcRow, srcCol}});
        dist[srcRow][srcCol] = 1;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int steps = it.first;
            int curRow = it.second.first;
            int curCol = it.second.second;

            // Now traverse in all 8 directions:
            for(int row = -1; row <= +1; row++){
                for(int col = -1; col <= +1; col++){
                    int nRow = curRow + row;
                    int nCol = curCol + col;

                    // Now check valid bound, valid grid cell, & lesser distance:
                    if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && 
                        grid[nRow][nCol] == 0 && steps + 1 < dist[nRow][nCol] ){

                            dist[nRow][nCol] = steps + 1;    // update distance

                            if(nRow == n-1 && nCol == m-1) return steps + 1;    // if we are at destination, return the (steps + 1) shorter path for destination.
                            q.push({steps+1, {nRow, nCol}});    // push into queue.
                        }
                }
            }
        }

        return -1;
    }
};