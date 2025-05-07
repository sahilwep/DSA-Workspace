/*

//  3341. Find Minimum Time to Reach Last Room I


//  Problem Statement: 
    -> There is a dungeon with n x m rooms arranged as a grid.
    -> You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. 
    -> Moving between adjacent rooms takes exactly one second.
    -> Return the minimum time to reach the room (n - 1, m - 1).
    -> Two rooms are adjacent if they share a common wall, either horizontally or vertically.

 
// Example: 

    Example 1:
        Input: moveTime = [[0,4],[4,4]]
        Output: 6
        Explanation:
            The minimum time required is 6 seconds.

                At time t == 4, move from room (0, 0) to room (1, 0) in one second.
                At time t == 5, move from room (1, 0) to room (1, 1) in one second.

    Example 2:
        Input: moveTime = [[0,0,0],[0,0,0]]
        Output: 3
        Explanation:
            The minimum time required is 3 seconds.
                At time t == 0, move from room (0, 0) to room (1, 0) in one second.
                At time t == 1, move from room (1, 0) to room (1, 1) in one second.
                At time t == 2, move from room (1, 1) to room (1, 2) in one second.

    Example 3:
        Input: moveTime = [[0,1],[1,2]]
        Output: 3


// Observations: 
    -> From the given question it's clear that we will have to use dijkstra's for shortest distance..
    -> It's just we have to figure how's the dijkstra's will be implemented..

    // Key Observations: 
        -> We have to return the minimum time to reach the last room 
        -> In other word, we have to arrive at the last cell of grid in minium time.
            -> Whatever path we will took, there should have minimum time among all the path..
            -> Also, we have to add 1 everytime we move from one cell to adjacent cell.

        // Example: 
            Input: moveTime = [[0,4],[4,4]]
            Output: 6


                          0   1
                         _______
                      0 | 0 | 4 |
                        |-------|
                      1 | 4 | 2 |
                        ---------

            Using Dijkstra's, we will maintain one grid distance with inital value INT_MAX
                        
                Path 1: (0, 0) -> (0, 1) -> (1, 1)

                        base:
                            row = 0
                            col = 0

                        Adj:
                            row = 0
                            col = 1

                            dist[row][col] = max(base, adj) + 1
                            & compare with current adj[row][col] & update



                Path 2: (0, 0) -> (1, 0) -> (1, 1)
                For path 2, will use simillar approach....


// Complexity: 
    -> TC: O((n * m) * log(n * m))
        -> n = grid.size(), m = grid[0].size
    -> SC: O(n * m)


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
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        // Dijkstra's impl.
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        priority_queue<ppr, vector<ppr>, greater<>> pq;

        dist[0][0] = 0;
        pq.push({0,{0, 0}});

        while(!pq.empty()) {
            auto [cost, cor] = pq.top();
            pq.pop();

            int row = cor.first, col = cor.second;
            
            // Return if it's reaches destinations:
            if(row == n - 1 && col == m - 1) return cost;


            // Explore in all 4 directions: 
            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(isValid(r, c)) { // within grid boundary:
                    // Get the maximum from the path & add 1 to it for moving adjacent cost..
                    int newCost = max(dist[row][col], grid[r][c]) + 1;

                    // Compare New Cost with previous ones & update if it's cheaper: 
                    if(newCost  < dist[r][c]) {
                        dist[r][c] = newCost;
                        pq.push({newCost, {r, c}});
                    }
                }
            }
        }

        return 0;
    }
};