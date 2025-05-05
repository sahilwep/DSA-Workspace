/*

//  Undirected Graph Cycle

//  Problem Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class DSU {
private: 
    vector<int> parent, size;
public: 
    DSU(int n) {
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
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        DSU ds(V);
        for(auto &it: edges) {
            int u = it[0], v = it[1];
            
            if(ds.ultPar(u) == ds.ultPar(v)) return true;   // cycle found
            
            ds.Union(u, v);
        }
        
        return false;    // no cycle found
    }
};