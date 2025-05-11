/*

//  Shortest Path in Undirected Graph


//  Problem Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1


// Observations:
    -> Given adj list
    -> with edge weights = 1 for all the edges
    -> find the shortest distance from source to all vertices
    -> If there's no shortest path -> place -1


    // Approach: 
        -> Given edge weights = 1, which is constant throughout -> We can use BFS
        -> Or we can also use Dijkstra's but it's makes no sens because edge weights are constant throughout..
        -> So we will use BFS.

        // BFS Approach: 
            -> Perform simple BFS to find the shortest path..

        // Complexity:
            -> TC: O(V + 2E)
            -> SC: O(V + 2E)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V = adj.size();
        vector<int> ans;
        
        queue<pair<int, int>> q;
        vector<int> dist(V, INT_MAX);
        
        q.push({0, src});
        dist[src] = 0;
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int cost = it.first, node = it.second;
            
            for(auto &it: adj[node]) {
                if(cost + 1 < dist[it]) {
                    dist[it] = cost + 1;
                    q.push({cost + 1, it});
                }
            }
        }
        
        for(int i = 0; i < V; i++) if(dist[i] == INT_MAX) dist[i] = -1;
        
        return dist;
    }
};