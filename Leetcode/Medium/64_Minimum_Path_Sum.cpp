/*

//  64. Minimum Path Sum

//  Problem Statement: 
    -> Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
    -> Note: You can only move either down or right at any point in time.

 
// Example: 

    Example 1:
        Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
        Output: 7
        Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

    Example 2:
        Input: grid = [[1,2,3],[4,5,6]]
        Output: 12

// Observations: 
    -> We have to minimize the path sum/cost from (0, 0) to (n-1, m-1)
    -> We can use Dijkstra's


    
// Complexity: 
    -> TC: O((n * m) * (log(n * m)))
    -> SC: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    typedef pair<int, pair<int, int>> ppr;
    int n, m;
    int dir[2][2] = {{0, 1}, {1, 0}};   // right, down
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
public:
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        priority_queue<ppr, vector<ppr>, greater<>> pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while(!pq.empty()) {
            auto [cost, cor] = pq.top();
            pq.pop();

            int row = cor.first;
            int col = cor.second;

            if(row == n - 1 && col == m - 1) return cost;
            if(cost > dist[row][col]) continue;

            for(int i = 0; i < 2; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];
                
                if(isValid(r, c)) {
                    int newCost = cost + grid[r][c];

                    if(newCost < dist[r][c]) {
                        dist[r][c] = newCost;
                        pq.push({newCost, {r, c}});
                    }
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};