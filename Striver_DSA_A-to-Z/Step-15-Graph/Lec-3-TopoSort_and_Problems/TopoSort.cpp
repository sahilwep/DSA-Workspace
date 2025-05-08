/*

// TopoSort / Kahn's Algorithm: 

//  Problem Link: https://www.geeksforgeeks.org/problems/topological-sort/1


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Build adj list: 
        vector<vector<int>> adj(V);
        vector<int> id(V, 0);
        for(auto &it: edges) {
            adj[it[0]].push_back(it[1]);
            id[it[1]]++;;
        }
        
        // Process TopoSort:
        queue<int> q;
        for(int i = 0; i < V; i++) if(!id[i]) q.push(i);
        
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto &v: adj[node]) {
                id[v]--;
                if(!id[v]) q.push(v);
            }
        }
        
        return topo;
    }
};
