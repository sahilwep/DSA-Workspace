/*

//  Path With Minimum Effort

//  Problem Link: https://leetcode.com/problems/path-with-minimum-effort/


*/
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private: 
    typedef pair<int, pair<int, int>> ppr;
    int n, m;
    bool isValid(int r, int c){return (r >= 0 && r < n && c >= 0 && c < m);}
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size(), m = heights[0].size();
        
        // Dijkstra's impl...
        vector<vector<int>> effort(n, vector<int> (m, INT_MAX));
        priority_queue<ppr, vector<ppr>, greater<>> pq;

        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            auto [eff, cor] = pq.top();
            pq.pop();

            int row = cor.first, col = cor.second;

            // Check destinations: 
            if(row == n - 1 && col == m - 1) return eff;

            // Explore 4 directions: 
            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                // within valid bound:
                if(isValid(r, c)) { 
                    // Get the maximum absolute diff among the two reidge..
                    int newEff = max(abs(heights[row][col] - heights[r][c]), eff);
                    
                    // Get the minimum path among all the path
                    if(newEff < effort[r][c]) {
                        effort[r][c] = newEff;
                        pq.push({newEff, {r, c}});
                    }
                }
            }
        }

        return effort[n-1][m-1];
    }
};