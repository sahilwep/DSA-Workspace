/*

//  1926. Nearest Exit from Entrance in Maze


//  Problem Statement:
    * You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). 
    * You are also given the entrance of the maze, where entrance = [entrance_row, entrance_col] denotes the row and column of the cell you are initially standing at.
    * In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. 
    * Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.
    * Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.



//  Example:

    Example 1:
        Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
        Output: 1
        Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
        Initially, you are at the entrance cell [1,2].
        - You can reach [1,0] by moving 2 steps left.
        - You can reach [0,2] by moving 1 step up.
        It is impossible to reach [2,3] from the entrance.
        Thus, the nearest exit is [0,2], which is 1 step away.

    Example 2:
        Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
        Output: 2
        Explanation: There is 1 exit in this maze at [1,2].
        [1,0] does not count as an exit since it is the entrance cell.
        Initially, you are at the entrance cell [1,0].
        - You can reach [1,2] by moving 2 steps right.
        Thus, the nearest exit is [1,2], which is 2 steps away.

    Example 3:
        Input: maze = [[".","+"]], entrance = [0,0]
        Output: -1
        Explanation: There are no exits in this maze.



// Approach:
    // Problem Overview:
        -> The problem is to find the shortest path from the entrance of the maze to the nearest exit. 
        -> The shortest path implies using a Breadth-First Search (BFS) traversal technique, which processes nodes level by level.

    // Why BFS?
        -> BFS is ideal for finding the shortest path in an unweighted grid-like structure since it explores all nodes at the current "distance" (or level) before moving to the next level. 
        -> This ensures that the first exit found is the one with the minimum steps.

    // Core Idea:
        -> Treat the maze as a grid where:
            -> Walls ('+') are impassable.
            -> Open cells ('.') are navigable.
            -> The entrance and exits are boundaries or specific points in the grid.
        -> The BFS ensures that we process all possible paths step by step, and when we reach an exit, the current step count is the shortest path.

    // Steps in the Algorithm:
        -> Initialization:
            -> Start BFS from the given entrance.
            -> Use a queue to store the coordinates of cells to be processed.
            -> Maintain a visited array (or modify the maze directly) to mark cells that have already been explored, avoiding revisiting them.
        -> BFS Traversal:
            -> For every cell at the current BFS level:
                -> Explore all valid neighbors (up, down, left, right).
                -> If a neighbor is a valid exit and not the entrance, return the current step count incremented by 1.
                -> Otherwise, mark the neighbor as visited and add it to the queue for further processing.
            -> After processing all cells at the current level, increment the step count.
        -> Exit Condition:
            -> The BFS stops when an exit is found. If no exit is reachable after processing all cells, return -1.

    // Key BFS Modification:
        -> In BFS, multiple paths from the current level are processed simultaneously, and they all contribute to the same step count. 
        -> This ensures that the shortest path is calculated correctly.

    // Edge Cases:
        -> The entrance itself is on the boundary but is not considered an exit.
        -> All paths may be blocked by walls ('+').
        -> The maze may have no valid exits ('.') except for the entrance.


// Complexity:
    * TC: O(n*m)
    * AS: O(n*m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int n = maze.size();
        int m = maze[0].size();

        vector<vector<char>> vis = maze;    // maintain visited matrix, to traverse in correct given path.

        queue<pair<int, int>> q;    // using queue ds: queue<pair<row, col>>
        q.push({e[0], e[1]});   // pushing given entrance coordinates in queue
        vis[e[0]][e[1]] = '/';  // Mark the entrance as visited to avoid revisiting


        // Valid 4 direction:
        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};


        int step = 0;
        while(!q.empty()){
            int size = q.size();    // Number of elements at the current BFS level

            // Process all nodes at the current BFS level
            for(int i=0;i<size;i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();    // Remove the current cell from the queue

                // Iterate over all 4 possible directions
                for(int i=0;i<4;i++){
                    // Calculate new row & col
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];

                    // Check if the new cell is within bounds, a free path ('.'), and unvisited
                    if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && maze[nRow][nCol] == '.' && vis[nRow][nCol] != '/'){

                        // Check if the new cell is an exit and not the entrance
                        if(nRow == 0 || nRow == n-1 || nCol == 0 || nCol == m-1){
                            return step + 1;    // Add 1 because we are moving to the next level
                        }

                         // Mark the cell as visited and add it to the queue
                        vis[nRow][nCol] = '/';
                        q.push({nRow, nCol});
                    }

                }
            }
            step++; // Increment step after processing all nodes at the current level, because we can have multiple path going from the current level...
        }

        return -1;  // else return '-1'
    }
};