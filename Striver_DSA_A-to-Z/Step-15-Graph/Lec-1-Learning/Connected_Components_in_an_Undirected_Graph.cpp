/*

// Problem Statement: Connected Components in an Undirected Graph

// Problem link: https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1


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
        return parent[node] = ultPar(parent[node]); // path compression
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;  // already connected
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
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        
        DSU ds(V);
        // Connect the component:
        for(auto &it: edges) {
            int u = it[0], v = it[1];
            ds.Union(u, v); // connect the nodes
        }
        
        // Store ultimate nodes Components:
        map<int, set<int>> mp;
        for(int i = 0; i < V; i++) {
            // Store nodes in their ultimate parent.
            mp[ds.ultPar(i)].insert(i);
        }
        
        // Build answer: 
        vector<vector<int>> ans;
        for(auto &it: mp) {
            auto key = it.first;
            auto val = it.second;
            vector<int> temp(begin(val), end(val));
            ans.push_back({temp});
        }
        
        return ans;
    }
};