/*

//  1293. Shortest Path in a Grid with Obstacles Elimination


//  Problem Statement: 
    -> You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.
    -> Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. 
    -> If it is not possible to find such walk return -1.


// Observations: 
    -> Given grid of dimensions of n x m
    -> grid has 1's & 0's represent 0 = freepath, 1 = blockage
    -> we are also given an integer 'k' represent the number of blockage we can remove from the grid.
    -> We need to traverse from (0, 0) to {(n-1), (m-1)} & find the shortest distance possible by removing the cells optimally.
    -> we can remove at max 'k' blockage in a way to reaching destinations.
    -> If there's no way we can reach destinations return '-1'

    // BFS Approach: 
        -> We can start from the '0th' cell & try to iterate in all possible directions & try to reach destinations with optimally remove the cells.
        -> We can maintain the removal[] vector instead of visited[], because it may be possible that we are visiting same cells so that we can get the optimal cost..
        -> This is why we can initialize the removal[] with maximum value & iterate & check least possible cost to reach the destinations cell.


// Complexity: 
    -> TC: O(n * m)
    -> SC: O(n * m)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// BFS Solution:
class Solution {
private:   
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; 
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();

        vector<vector<int>> removal(n, vector<int> (m, INT_MAX));   // maintain a vector that represent the number of removal we can apply every cell
        queue<pair<int, pair<int, pair<int, int>>>> q;

        // Edge case: if entry point has blockage
        if(grid[0][0] == 1 && k > 0)  {
            grid[0][0] = 0;     // making that cell clear
            k--;    // decrement k as we have used to clear cell
        }

        q.push({0, {0, {0, 0}}});    // <removeAllowed, < steps, <row, col>>
        removal[0][0] = 0;          // initial removal for source = 0

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int canRemove = it.first;
            int steps = it.second.first;
            int row = it.second.second.first;
            int col = it.second.second.second;

            // Check the destinations: 
            if(row == n - 1 && col == m - 1) return steps;

            // Explore all 4 directions: 
            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(isValid(r, c)) {
                    int newRemoval = canRemove + grid[r][c];    // new removal cost will be previous + current cell value, if it's '0 = free' || '1 = occupied' will be computed accordingly..
                    
                    // Check if current Removal cost is lesser than the previous ones or not & check the 'k' factor
                    if(newRemoval < removal[r][c] && newRemoval <= k) {
                        removal[r][c] = newRemoval;

                        q.push({newRemoval, {steps + 1, {r, c}}});   
                    }
                }
            }
        }

        return -1;  // not able to traverse to end.
    }
};