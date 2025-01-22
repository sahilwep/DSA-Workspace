/*

//  1631. Path With Minimum Effort


//  Problem Statement: 
    -> You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). 
    -> You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
    -> A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
    -> Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

// Example: 
    Example 1:
        Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
        Output: 2
        Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
        This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

    Example 2:
        Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
        Output: 1
        Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

    Example 3:
        Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
        Output: 0
        Explanation: This route does not require any effort

// Observations: 

    -> We are given source node as (0, 0) top left starting cell.
    -> dest = (n-1, m-1) -> bottom right most cell
    -> for every cell we are given height of the building.
    -> we need to find the minimum effort for the path.
    -> for every path, we are either climbing up or going down.
    -> for moving once cell to another cell, we will take the absolute difference b/w their height.
    -> so, we need to choose such path which will gives us minimum efforts..


        Example: 

            [[1,2,2],
             [3,8,2],
             [5,3,5]]

                src = (0, 0), dest = (n-1, m-1)

                Now there can be many possible path:
                let's take one of them:
                    1 -> 2 -> 2 -> 2 -> 5
                     \  / \  / \  / \  /    -> Take absolute diff b/w all the heights:
                      1    0    0    3      -> '3' is the maximum effort taken in this particular path.

                
                let's take another one: 

                    1 -> 3 -> 8 -> 2 -> 5
                    \  / \  / \  /  \  /    -> Take absolute diff b/w all the heights:
                     2    5    6     3      -> '6' is the maximum effort taken in this path.
                    

                let's take one more: 
                    
                    1 -> 3 -> 5 -> 3 -> 5
                    \  / \  / \  /  \  /    -> Take absolute diff b/w all the heights:
                     2    2    2     2      -> '2' is the maximum effort taken in this path.
                    
                
                Now, there can be many possible path....
                We have to choose those path, which computes the minimum effort:
                among these three path, the minimum effort was '2', so we return '2'
                This is what we have to find.


    // Approach: 
        -> We will use Dijkstra's algorithm to solve this problem.
        -> As we needed to find the minimum effort from two given point, Dijkstra's will help us in that.
        -> dijkstra's will select the minimum effort found among all possible path.
        -> We will use priority heap to implement the dijkstra's algorithm.
        -> We will maintain for 

            // We have to move in all the directions.

                              (-1, 0) 
                                 |
                    (0, -1) <- (0, 0) -> (0, 1)
                                 |
                               (1, 0)

// Complexity: 
    -> TC: O(n * m * log(n * m))
    -> SC: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;



// Dijkstra's Based Solution:
class Solution {
private:
    typedef pair<int, pair<int, int>> ppr;
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    // Directions from (0, 0):  left     right    up      down
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<ppr, vector<ppr>, greater<>> pq; // to compute the minimum effort
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));  // store the distance from source to every other nodes.

        pq.push({0, {0, 0}});   // insert source node with effort as '0', because it's starting & to reach starting we are already there, so effort is none.
        dist[0][0] = 0; // mark source distance from source is '0'

        // Dijkstra's Logic:
        while(!pq.empty()){
            auto it = pq.top(); // get top data from pq
            pq.pop();   // remove that

            int effort = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1) return effort; // if we are at desired destinations, return that effort to reach.

            for(int i=0;i<4;i++){   // explore all possible 4 directions:
                int r_ = row + dir[i][0];   // new row   
                int c_ = col + dir[i][1];   // new col

                // Check for valid bound:
                if(r_ >= 0 && r_ < n && c_ >= 0 && c_ < m){
                    int newEffort = max(abs(heights[row][col] - heights[r_][c_]), effort);  // that's the new effort, we are getting on that path, by getting the diff b/w two adjacent cell, & past maximum.

                    // if new Effort is lesser than the new cell distance, update that.
                    if(newEffort < dist[r_][c_]){
                        dist[r_][c_] = newEffort;   // update

                        pq.push({newEffort, {r_, c_}}); // push that into priority queue
                    }
                }
            }
        }

        return heights[n-1][m-1];
    }
};