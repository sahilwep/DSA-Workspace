/*

//  3342. Find Minimum Time to Reach Last Room II

//  Problem Statement: 
    -> There is a dungeon with n x m rooms arranged as a grid.
    -> You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.
    -> Return the minimum time to reach the room (n - 1, m - 1).
    -> Two rooms are adjacent if they share a common wall, either horizontally or vertically.

 
// Example: 
    Example 1:
        Input: moveTime = [[0,4],[4,4]]
        Output: 7
        Explanation:
            The minimum time required is 7 seconds.
                At time t == 4, move from room (0, 0) to room (1, 0) in one second.
                At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.

    Example 2:
        Input: moveTime = [[0,0,0,0],[0,0,0,0]]
        Output: 6
        Explanation:
            The minimum time required is 6 seconds.
                At time t == 0, move from room (0, 0) to room (1, 0) in one second.
                At time t == 1, move from room (1, 0) to room (1, 1) in two seconds.
                At time t == 3, move from room (1, 1) to room (1, 2) in one second.
                At time t == 4, move from room (1, 2) to room (1, 3) in two seconds.

    Example 3:
        Input: moveTime = [[0,1],[1,2]]
        Output: 4



// Observations: 
    -> From the given question it's clear that we will have to use dijkstra's for shortest distance..
    -> It's just we have to figure how's the dijkstra's will be implemented..

    // Key Observations: 
        -> We have to return the minimum time to reach the last room 
        -> In other word, we have to arrive at the last cell of grid in minium time.
            -> Whatever path we will took, there should have minimum time among all the path..

        -> for moving one cell to another cost will be flipped at every steps from (1 & 2)
            -> In simple, If we have 5 cell in our path form (0, 0) to (n-1, m-1)

                [0]-----1----->[1]----2---->[2]-----1---->[3]----2---->[4]

            -> Cost from one cell to another cell will be flipping...

        // Approach 1: 
            -> We can maintain one extra variable in our priority queue "flag" which will tell us about the cellMovingCost
            -> we can keep on changing flag from (0-1) & (1-0) for every steps & counting the cost accordingly.

        // Approach 2:
            -> We are working in 2D matrix:

                          0         1       2
                    0 | (0, 0) | (0, 1) | (0, 2) |
                    1 | (1, 0) | (1, 1) | (1, 2) |
                    2 | (2, 0) | (2, 1) | (2, 2) |


            -> For every cell:  (row, col) will be unique: 
            -> We can get movement Cost with this formula:

                    movementCost = (row + col) % 2  + 1

                -> Let's see with an example: 

                    From moving any one cell to any other cell:

                        Vertically:

                            (0, 1) => ((0 + 1) % 2) + 1 => 2
                            (1, 1) => ((1 + 1) % 2) + 1 => 1
                        
                        Or Horizontally

                            (0, 1) -> (0, 2) 
                                ((0 + 1) % 2) + 1 => 2
                                ((0 + 2) % 2) + 1 => 1

                -> We can compute the cost with our original value (row, col)          


// Complexity: 
    -> TC: O((n * m) * log(n * m))
        -> n = grid.size(), m = grid[0].size
    -> SC: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Approach 2: Using Coordinates logic
class Solution {
private:    
    typedef pair<int, pair<int, int>> ppr;
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return ( r >= 0 && r < n && c >= 0 && c < m);}
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        priority_queue<ppr, vector<ppr>, greater<>> pq;

        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        

        while(!pq.empty()) {
            auto [cost, cor] = pq.top();
            pq.pop();

            int row = cor.first, col = cor.second;

            if((row * m + col) == ((n * m) - 1)) break;

            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];
                
                if(isValid(r, c)) {
                    int pathCost = ((row + col) % 2) + 1;

                    int newCost = max(dist[row][col], grid[r][c]) + pathCost;

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




// Approach 1: Maintaining one extra flag to compute cellMovingCost
class Solution {
private:    
    typedef pair<int, pair<int, pair<int, int>>> ppr;
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return ( r >= 0 && r < n && c >= 0 && c < m);}
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        priority_queue<ppr, vector<ppr>, greater<>> pq;

        dist[0][0] = 0;
        pq.push({0, {0, {0, 0}}});  // Structure: <cost, <flag, <row, col>>>
        

        while(!pq.empty()) {
            auto [cost, oth] = pq.top();
            pq.pop();

            int flag = oth.first;
            int row = oth.second.first, col = oth.second.second;

            if(row == n - 1 && col == m - 1) break; // reach at destinations return answer

            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];
                
                if(isValid(r, c)) {
                    int cellMovingCost = (flag == 0) ? 1 : 2; // get the flag value & from there compute the cost.

                    // get new cost: from previous computed & current:
                    int newCost = max(dist[row][col], grid[r][c]) + cellMovingCost;

                    if(newCost < dist[r][c]) {  // check cheapest cost for dist:
                        dist[r][c] = newCost;

                        pq.push({newCost, {!flag, {r, c}}});
                    }
                }
            }
        }

        return dist[n-1][m-1];  // return answer
    }
};