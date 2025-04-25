/*

//  1786. Number of Restricted Paths From First to Last Node


//  Problem Statement: 
    -> There is an undirected weighted connected graph. You are given a positive integer n which denotes that the graph has n nodes labeled from 1 to n, and an array edges where each edges[i] = [ui, vi, weighti] denotes that there is an edge between nodes ui and vi with weight equal to weighti.
    -> A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that z0 = start and zk = end and there is an edge between zi and zi+1 where 0 <= i <= k-1.
    -> The distance of a path is the sum of the weights on the edges of the path. Let distanceToLastNode(x) denote the shortest distance of a path between node n and node x. A restricted path is a path that also satisfies that distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1.
    -> Return the number of restricted paths from node 1 to node n. Since that number may be too large, return it modulo 109 + 7.

// Example: 

    Example 1:
        Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
        Output: 3
        Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The three restricted paths are:
        1) 1 --> 2 --> 5
        2) 1 --> 2 --> 3 --> 5
        3) 1 --> 3 --> 5

    Example 2:
        Input: n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
        Output: 1
        Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The only restricted path is 1 --> 3 --> 7.


// Observations: 
    -> Problem is saying that first we have computed the shortest path from n to every other node.
    -> Then we have to find the all possible path from 1 to n, with one conditions:
               u -------> v
            dist[u] > dist[v]
        -> dist = the distance we have computed from n to all nodes
        -> we will start from 1 & to to n
        -> every path is counted if dist[u] > dist[v]

    -> When we observe this question more carefully,
        -> while we are finding all the possible path using dfs,
        -> we endup computing same path again and again...
        -> This boils down to recomputation of sub-problem again & again -> DP hint
        -> Yes we can simply apply dp concept for all the shortest path for every node....

    // Dijkstra's Approach: 
        -> First find the shortest path from n to every other nodes.
        -> Then explore all possible path from 1 to all n
            -> Count the total number of path 
                -> Every path is counted if dist[u] > dist[v]
                -> this will be our restricted path..


    // Complexity: 
        -> TC: O((E * log(V)) + (V + E))
            -> O(E * log(V))    => Dijkstra's Complexity
            -> (V + E)          => for DFS with memoization
        -> SC: O(V + E)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    int mod = 1e9 + 7;
    vector<int> t;  // memo-table
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src, int n) { // dijkstra's Solution
        
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {
            auto[cost, node] = pq.top();
            pq.pop();

            if(dist[node] < cost) continue; // skip expensive cost, if cheaper already computed.

            for(auto &[v, wt]: adj[node]) {
                if(cost + wt < dist[v]) {
                    dist[v] = cost + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
    int dfs(int node, int dst, vector<vector<pair<int, int>>>& adj, vector<int>& dist) {    // dfs to find all possible path from src to dst.
        if(node == dst) return 1;   // reaches at destination return 1

        // Check in DP memo table: 
        if(t[node] != -1) return t[node];

        // Now compute answer: 
        int ans = 0;
        for(auto &[v, wt]: adj[node]) {
            // if next adjacent node is lesser, we can traverse on that => we can go u ----> v if (dist[u] > dist[v])
            if(dist[node] > dist[v]) {  
                ans = (ans + dfs(v, dst, adj, dist)) % mod;
            }
        }

        return t[node] = (ans % mod);   // store answer in DP memo-table
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        // Build Adj list: 
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto &it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Now get shortest distance from n to all other nodes, with dijkstra's
        vector<int> dist = dijkstra(adj, n, n + 1);

        // Now run dfs & find the restricted path from 1.
        t.resize(n + 2, -1);   // initialize dp table
        int restPath = dfs(1, n, adj, dist); 

        return restPath;
    }
};