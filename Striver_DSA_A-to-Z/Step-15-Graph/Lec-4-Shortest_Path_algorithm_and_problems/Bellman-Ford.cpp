/*

//  Bellman-Ford

//  Problem Link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1


// Observations: 
    -> Given weighted edges with negative values..
    -> find return the shortest distance from source
    -> If graph contains any negative cycle return "-1"

    
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        
        // Process V - 1 times:
        vector<int>  dist(V, 1e8);
        dist[src] = 0;
        
        for(int i = 0; i < V - 1; i++) {
            for(auto &it: edges) {
                int u = it[0], v = it[1], wt = it[2];
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Process 1 more time for cycle check: 
        for(auto &it: edges) {
            int u = it[0], v = it[1], wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};
            }
        }
        
        return dist;
    }
};