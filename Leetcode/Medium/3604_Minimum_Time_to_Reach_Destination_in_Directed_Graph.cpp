/*

//  3604. Minimum Time to Reach Destination in Directed Graph


//  Problem Statement: 
    - You are given an integer n and a directed graph with n nodes labeled from 0 to n - 1. This is represented by a 2D array edges, where edges[i] = [ui, vi, starti, endi] indicates an edge from node ui to vi that can only be used at any integer time t such that starti <= t <= endi.
    - You start at node 0 at time 0.
    - In one unit of time, you can either:
        - Wait at your current node without moving, or
        - Travel along an outgoing edge from your current node if the current time t satisfies starti <= t <= endi.
    - Return the minimum time required to reach node n - 1. If it is impossible, return -1.


// Example:

    Example 1:
        Input: n = 3, edges = [[0,1,0,1],[1,2,2,5]]
        Output: 3
        Explanation:
            The optimal path is:
                At time t = 0, take the edge (0 → 1) which is available from 0 to 1. You arrive at node 1 at time t = 1, then wait until t = 2.
                At time t = 2, take the edge (1 → 2) which is available from 2 to 5. You arrive at node 2 at time 3.
            Hence, the minimum time to reach node 2 is 3.

    Example 2:
        Input: n = 4, edges = [[0,1,0,3],[1,3,7,8],[0,2,1,5],[2,3,4,7]]
        Output: 5
        Explanation:
            The optimal path is:
                Wait at node 0 until time t = 1, then take the edge (0 → 2) which is available from 1 to 5. You arrive at node 2 at t = 2.
                Wait at node 2 until time t = 4, then take the edge (2 → 3) which is available from 4 to 7. You arrive at node 3 at t = 5.
            Hence, the minimum time to reach node 3 is 5.

    Example 3:
        Input: n = 3, edges = [[1,0,1,3],[1,2,3,5]]
        Output: -1
        Explanation: Since there is no outgoing edge from node 0, it is impossible to reach node 2. Hence, the output is -1.

 

// Observations:
    - Given integer n, and directed graph with n nodes label from 0 to n - 1.
    - given edges: {u, v, startTime, endTime}
    - you start at node 0 at time 0
    - in one unit time you can either:
        - wait at your current node without moving or,
        - travel along an outgoing edge from you current node if the current time t satisfies:
            strati <= t <= end
    - return the minimum time required to reach node n - 1, if it's impossible return -1    

    // Example:
        Input: n = 4, edges = [[0,1,0,3],[1,3,7,8],[0,2,1,5],[2,3,4,7]]


            [0]
            / \
           /   \
         /      \
        [1]     [2]
         \      /
           \   /
            [3]


        - Let's try finding out the cost:

        src = 0, dst = 3
        starting cost: 0

                    [0]
                0  /   \  1
                3 /     \ 5
                [1]     [2]

            cost = max(prevCost, startTime);
                Now, this cost should be less than the endTime:
                    if(cost < endTime && cost < dist[v]) {
                        // we can move:
                            moveCost = 1 + cost;    // 1 is added, because this is the cost to travel on the edge.
                    }
                 
                             (0, 3)
                    [0]------------->[1]    
                        prevCost = 0
                        cost = max(startTime, prevCost)
                        cost = 0

                        cost < endTime
                         0   <  3

                        we can move:
                                if(cost < dist[v]) {
                                    moveCost = 1 + cost;    // this is the moving cost for the edge.
                                    dist[v] = newCost;
                                    q.push(newCost);
                                }

                    - Similarly, with this edge:

                            0 (1, 5)
                    [0]------------>[2]     cost = max(0, 1)
                                            cost = 1

                            cost < endTime
                            1 < 5
                            : we can move:
                                moveCost = 1 + cost
                                moveCost = 1 + 1 = 2
                    
                    ...
                    similarly we will travel all the edges..


            - One thing we can observe:

                currCost = max(previousCost, currentStart)
                currCost should less than or equal to the endTime:
                    -> if its' valid:
                        -> we can move this with adding 1, as travel cost on this edge.
                            moveCost = 1 + currCost;


        // Dijkstra's Solution:
            - Dijkstra's will help us to process the shortest always.
            - Using dijkstra's we can find the path with minCost.
            
            // Complexity:
                - TC: O(E + log (V))
                - SC: O(V)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    typedef pair<int, int> pr;  // cost, node
public:
    int minTime(int n, vector<vector<int>>& edges) {

        // Build Directed Graph adj list:
        vector<vector<vector<int>>> adj(n);
        for(auto &i: edges) {
            int u = i[0], v = i[1], s = i[2], e = i[3];
            adj[u].push_back({v, s, e});
        }

        // Process Dijkstra's:
        priority_queue<pr, vector<pr>, greater<>> pq;
        vector<int> dist(n, INT_MAX);

        pq.push({0, 0});
        dist[0] = 0;


        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            // Explore adj-Nodes:
            for(auto &i: adj[node]) {
                int v = i[0], s = i[1], e = i[2];
                
                // To move next, we will have to take (prevCost or currStart), whosoever is max, as newCost for next move:
                int newCost = max(cost, s);

                if(newCost <= e && newCost < dist[v]) {
                    // + 1 for current moving cost:
                    dist[v] = newCost + 1;
                    pq.push({newCost + 1, v});
                } 
            }
        }

        return (dist[n - 1] == INT_MAX) ? -1 : dist[n - 1];
    }
};