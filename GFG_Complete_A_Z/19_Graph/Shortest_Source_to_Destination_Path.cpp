/*

//  Shortest Source to Destination Path

//  Problem Statement: 
    -> Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
    -> Note: You can only move left, right, up and down, and only through cells that contain 1.

// Example: 
    Example 1:

        Input:
            N=3, M=4
            A=[[1,0,0,0], 
            [1,1,0,1],
            [0,1,1,1]]
            X=2, Y=3 
        Output: 5
        Explanation: The shortest path is as follows: (0,0)->(1,0)->(1,1)->(2,1)->(2,2)->(2,3).

    Example 2:

        Input:
            N=3, M=4
            A=[[1,1,1,1],
            [0,0,0,1],
            [0,0,0,1]]
            X=0, Y=3
        Output: 3
        Explanation: The shortest path is as follows: (0,0)->(0,1)->(0,2)->(0,3).

    Your Task: You don't need to read input or print anything. Your task is to complete the function shortestDistance() which takes the integer N, M, X, Y, and the 2D binary matrix A as input parameters and returns the minimum number of steps required to go from (0,0) to (X, Y).If it is impossible to go from (0,0) to (X, Y),then function returns -1. If value of the cell (0,0) is 0 (i.e  A[0][0]=0) then return -1.

// Observations: 
    -> Given grid
    -> n x m
    -> 4 directions traversal
    -> move only if we have 1 in cell
    -> start from (0, 0) and reach x, y
    -> return the shortest path
    -> if it's not possible, return -1

    // Approach: 
        -> perfrom level order traversal to solve this question
        -> Why we choose LOT ?
            -> It's because the cost to go from one cell to another is 1, and throughout it constant, so BFS will give the shortest path
        -> it's just we have to tell the number of level it required to reach destinations.


// Complexity: 
    -> TC: O(n * m)     
    -> AS: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private: 
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
public:
    int shortestDistance(int N, int M, vector<vector<int>> grid, int dstRow, int dstCol) {
        n = grid.size(), m = grid[0].size();
        
        // Edge case: 
        if(dstRow == 0 && dstCol == 0) return 0;
        if(grid[dstRow][dstCol] == 0 || grid[0][0] == 0) return -1;
        
        
        // LOT: 
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<int, pair<int, int>>> q;
        
        q.push({0, {0, 0}});    // src cost, sorCoordinates
        vis[0][0] = 1;
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int step = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if(row == dstRow && col == dstCol) return step;
            
            // Explore all 4 directions: 
            for(int i = 0 ; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];
                
                if(isValid(r, c) && !vis[r][c] && grid[r][c]) {
                    vis[r][c] = 1;
                    q.push({step + 1, {r, c}});
                }
            }
        }
        
        
        return -1;  // not possible to reach that locations..
    }
};
