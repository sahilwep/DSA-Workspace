/*

// Directed Graph Cycle


//  Problem Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;
         
        for(auto &it: adj[node]) {
             if(!vis[it]) {
                if(dfs(it, adj, vis, pathVis)) return true;
            } 
            else if (pathVis[it]) {
                return true;    // cycle found
            }
        }

        pathVis[node] = 0;
        return false;
    }
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        // Build Adj list: 
        vector<vector<int>> adj(V);
        for(auto &it: edges) {
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                if(dfs(i, adj, vis, pathVis)) return true;
            }
        }
        
        return false;
    }
};

