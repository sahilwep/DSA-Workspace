/*

//  778. Swim in Rising Water

//  Problem Link: https://leetcode.com/problems/swim-in-rising-water/

// Observations: 
    -> given grid of dimensions n x n
    -> begin point = (0, 0) & end point = (n - 1, n - 1)
    -> 4 directions iterations
    -> return the path that contains minimum elevations to the destinations points..
    

*/
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    int n;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < n);}
    typedef pair<int, pair<int, int>> ppr;
public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();

        vector<vector<int>> elevation(n, vector<int> (n, INT_MAX));
        priority_queue<ppr, vector<ppr>, greater<>> pq;

        elevation[0][0] = 0;
        pq.push({grid[0][0], {0, 0}});
        
        while(!pq.empty()) {
            auto [currEliv, cor] = pq.top();
            pq.pop();

            int row = cor.first, col = cor.second;

            if(row == n - 1 && col == n - 1) return currEliv;

            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(isValid(r, c)) {
                    int newEliv = max(grid[r][c], currEliv);

                    if(newEliv < elevation[r][c]) {
                        elevation[r][c] = newEliv;
                        pq.push({newEliv, {r, c}});
                    }
                }
            }
        }

        return elevation[n-1][n-1];
    }
};
