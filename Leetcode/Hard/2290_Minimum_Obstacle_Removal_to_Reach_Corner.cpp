/*

//  2290. Minimum Obstacle Removal to Reach Corner


//  Problem Statement: 
    -> You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:
        -> 0 represents an empty cell,
        -> 1 represents an obstacle that may be removed.
    -> You can move up, down, left, or right from and to an empty cell.
    -> Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).

// Example: 
    Example 1:
        Input: grid = [[0,1,1],[1,1,0],[1,1,0]]
        Output: 2
        Explanation: We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).
        It can be shown that we need to remove at least 2 obstacles, so we return 2.
        Note that there may be other ways to remove 2 obstacles to create a path.

    Example 2:
        Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
        Output: 0
        Explanation: We can move from (0, 0) to (2, 4) without removing any obstacles, so we return 0.


// Observations: 
    -> We are given grid of dimensions (n x m)
    -> given grid has two value 1, & 0, representing 1 = obstacle, & 0 = clear path.
    -> We need to reach from source (0, 0) to destinations(n-1, m-1) by minimum removal of obstacle.
    -> We need to return total number of obstacle that we have removed during the journey.

    // Key Observations: 
        -> If given grid has already clear path given, then there's no need of removing any obstacle -> we can directly return '0' as removing cost.
        -> Else we can try for removing cells & finding the minimum removal.
        
// Solutions: 
    -> First we will check wether the given grid has any path to reach the destinations or not?
        -> We can check this with using any bfs/dfs traversal.
    -> IF path contains any obstacle => we are required to remove the obstacle from the path.
    -> We can apply Dijkstra's solution with considerations factor "obstacle removal"
        -> Instead of maintaining the "distance" grid, we will maintain the "removal" grid
            -> This will let us know the minimum obstacle removed from starting source point to reaching every cell of grid.
    -> Priority queue will process minimum obstacle removed cost first..
    -> And we only need to compare the newCost with the old ones in removal grid & update our answer
    -> At any movement we reach last cell of grid => return the minimum cost.


// Complexity: 
    -> TC: O(N * M * (Log(N + M)))
    -> SC: O(N * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private: 
    typedef pair<int, pair<int, int>> ppr;
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    bool isPathPossible(vector<vector<int>>& grid) {    // BFS Function: 
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));

        q.push({0, 0});
        vis[0][0] = 1;

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            if(row == (n-1) && col == (m-1)) return true;

            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                // In valid bound, not yet visited, & valid path
                if(isValid(r, c) && !vis[r][c] && !grid[r][c]) {
                    vis[r][c] = 1;

                    q.push({r, c});
                }
            }
        }

        return false;
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        // First check wether we can reach the destinations without doing any configurations or not?
        if(isPathPossible(grid)) return 0;  // '0' is the cost to reach destinations.

        // Dijkstra's Implementations:
        // Else will will required to do some configurations:
        vector<vector<int>> removed(n, vector<int> (m, INT_MAX));   // this will help to find the minimum removed in order to reach destinations with minimum removal.
        priority_queue<ppr, vector<ppr>, greater<>> pq;

        // Edge case: if starting cell has obstacles:
        if(grid[0][0] == 1) {   // if starting cell has barrier:
            pq.push({1, {0, 0}});
            removed[0][0] = 1;
        } else {
            pq.push({0, {0, 0}});
            removed[0][0] = 0;
        }

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int prevRemoved = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == (n-1) && col == (m-1)) return prevRemoved;

            // Explore all 4 directions: 
            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(isValid(r, c)) {
                    int newRemoved = prevRemoved + grid[r][c];  // calculate the required obstacle need to remove to get in this current cell

                    if(newRemoved < removed[r][c]) {    // compare cost with previous stored ones & store the shortest.
                        removed[r][c] = newRemoved;

                        pq.push({newRemoved, {r, c}});
                    }
                }
            }
        }

        return removed[n-1][m-1];   // return the removal cost from last cell of the grid.
    }
};