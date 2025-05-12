/*

//  Shortest path in Directed Acyclic Graph


//  Problem Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    void topo(int node, vector<vector<pair<int, int>>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        
        for(auto &it: adj[node]) {
            if(!vis[it.first]) {
                topo(it.first, adj, vis, st);
            }
        }
        
        st.push(node);
    }
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Build adj list: 
        vector<vector<pair<int, int>>> adj(V);
        for(auto &it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        // find topoSort linear ordering: 
        stack<int> st;
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                topo(i, adj, vis, st);
            }
        }
        
        // Process Shortest path:
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            for(auto &it: adj[node]) {
                int v = it.first, wt = it.second;
                
                if(dist[node] != INT_MAX && dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        for(int i = 0; i < V; i++) {
            if(dist[i] == INT_MAX) dist[i] = -1;
        }
        
        return dist;
    }
};