/*

//  Minimum Spanning Tree

//  Problem Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class DSU {
private: 
    vector<int> parent, size;
public:
    DSU (int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]);
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        // Build edges in sorted order with considerations factor weights:
        set<pair<int, pair<int, int>>> edges;
        for(int i = 0; i < V; i++) {
            for(auto &it: adj[i]) {
                int j = it[0], wt = it[1];
                edges.insert({wt, {min(i, j), max(i, j)}});
            }
        }
        
        // Find MST:
        DSU ds(V);
        int mstWt = 0;
        for(auto it: edges) {
            int wt = it.first, u = it.second.first, v = it.second.second;
            
            if(ds.ultPar(u) == ds.ultPar(v)) continue;
            
            ds.Union(u, v);
            mstWt += wt;
        }
        
        return mstWt;
    }
};
