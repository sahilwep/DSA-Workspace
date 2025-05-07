/*

//  785. Is Graph Bipartite?


//  Problem Link:  https://leetcode.com/problems/is-graph-bipartite/


// Observations: 
    -> given graph undirected
    -> node from 0 to n - 1
    -> given graph adj list:
        -> Build edges
    -> No two adjacent nodes should be in same group.
    -> if this conditions is not satisfies -> return false
    -> else return true.


    // DSU Approach: 
        -> Build 2 groups for graph
        -> At any movement tow nodes fallen in same group -> return false



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
        return parent[node] = ultPar(parent[node]); // path compression..
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
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        // Build Edges: 
        set<pair<int, int>> edges;
        for(int i = 0; i < n; i++) {
            for(auto &j: graph[i]) {
                edges.insert({min(i, j), max(i, j)});
            }
        }

        // Build Components & check:
        DSU ds(n + n);  // 2 * n -> because at max we can have this much node in our DSU

        for(auto &[u, v]: edges) {
            // At any movement two distinct groups node falls into same group -> return false
            if(ds.ultPar(u) == ds.ultPar(v)) return false;

            // Build 2 Groups:
            ds.Union(u, v + n);     // G1
            ds.Union(u + n, v);     // G2
        }


        return true;    // graph is bi-partite
    }
};