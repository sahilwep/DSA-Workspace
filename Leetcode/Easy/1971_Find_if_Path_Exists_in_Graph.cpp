/*

//  1971. Find if Path Exists in Graph


//  Problem Statement: 
    -> There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). 
    -> The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
    -> You want to determine if there is a valid path that exists from vertex source to vertex destination.
    -> Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
 

// Example: 
    Example 1:
        Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
        Output: true
        Explanation: There are two paths from vertex 0 to vertex 2:
        - 0 → 1 → 2
        - 0 → 2

    Example 2:
        Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
        Output: false
        Explanation: There is no path from vertex 0 to vertex 5.

 
// Approach: 
    -> Use DSU to track the components.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class DSU {
private: 
    vector<int> size, parent;
public: 
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = ultPar(parent[node]); // path compression
    }
    void Union(int u, int v) {
        int ulp_u = ultPar(u);
        int ulp_v = ultPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        DSU ds(n);

        for(auto &it: edges) {
            ds.Union(it[0], it[1]);
        }

        return (ds.ultPar(src) == ds.ultPar(dst));
    }
};