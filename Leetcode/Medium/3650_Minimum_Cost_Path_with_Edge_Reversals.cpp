/*

//  3650. Minimum Cost Path with Edge Reversals


//  Problem Statement: 
    - You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.
    - Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and immediately traverse it.
    - The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.
    - Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.

 
// Example:
    Example 1:
        Input: n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]
        Output: 5
        Explanation:
            Use the path 0 → 1 (cost 3).
            At node 1 reverse the original edge 3 → 1 into 1 → 3 and traverse it at cost 2 * 1 = 2.
            Total cost is 3 + 2 = 5.

    Example 2:
        Input: n = 4, edges = [[0,2,1],[2,1,1],[1,3,1],[2,3,3]]
        Output: 3
        Explanation:
            No reversal is needed. Take the path 0 → 2 (cost 1), then 2 → 1 (cost 1), then 1 → 3 (cost 1).
            Total cost is 1 + 1 + 1 = 3.


// Observations:
    - we are given n nodes from 0 to n - 1 and directed edges {u, v, wt}
    - we need to reach from 0 to n - 1 in minimum cost.
    - cost to reach node u to v if we have directed edge path is wt
    - If we don't have directed edge from u to v then the cost to reach u to v is 2 * wt of v to u.
    - we need to reach with minimum cost
    - Reaching with minimum cost we can use dijkstra's
    - It's just when we build graph adj list, we will make additional edge with 2 * wt cost.
    - Example:

            n = 2
            edges: [[0,1,13],[1,0,1]]

                        13
                    --------->[1]
                   /          /
                [0]<----------
                        1


        // Complexity: 
            - TC: O(E * logV)
            - SC: O(V)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        // Build Graph adj list:
        vector<vector<pair<int, int>>> adj(n);
        for(auto &it: edges) {
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});

            adj[v].push_back({u, 2 * wt});  // reverse travel cost 
        }

        // Process Dijkstra's:
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        pq.push({0, 0});    // cost, node
        dist[0] = 0;

        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if(cost > dist[node]) continue;

            // Explore adj nodes:
            for(auto [v, wt]: adj[node]) {
                int newCost = cost + wt;

                if(newCost < dist[v]) {
                    dist[v] = newCost;
                    pq.push({newCost, v});
                }

            }
        }
        
        return (dist[n - 1] == INT_MAX) ? -1 : dist[n - 1];
    }
};