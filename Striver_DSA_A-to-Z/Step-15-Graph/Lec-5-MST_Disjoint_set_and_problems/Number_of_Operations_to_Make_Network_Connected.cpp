/*

//  1319. Number of Operations to Make Network Connected


//  Problem Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;



class DSU {
private: 
    vector<int> parent, size;
public: 
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]);   // path compression
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
    int getSize(int x) {
        return size[ultPar(x)];
    }
};


class Solution {
public:
    int makeConnected(int V, vector<vector<int>>& edges) {
        
        // Connect nodes & form componenets:
        DSU ds(V);
        int eEdge = 0;
        for(auto &it: edges) {
            if(ds.ultPar(it[0]) == ds.ultPar(it[1])) eEdge++;    // Count extra edges

            ds.Union(it[0], it[1]); // connect components
        }

        // Count total Components: 
        int tComp = 0;
        for(int i = 0; i < V; i++) {
            if(ds.ultPar(i) == i) tComp++;
        }

        return (eEdge >= (tComp - 1)) ? tComp - 1 : -1;
    }
};