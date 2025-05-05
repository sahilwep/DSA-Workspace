/*

//  547. Number of Provinces

// Problem link:    https://leetcode.com/problems/number-of-provinces/description/


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
    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n + 1);  // 1-based indexing

        // Connect the components: 
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {    // undirected node
                if(grid[i][j]) {
                    ds.Union(i+1, j+1);
                }
            }
        }

        // Count the total number of components:
        int comp = 0;
        for(int i = 1; i <= n; i++) {
            if(ds.ultPar(i) == i) comp++;
        }

        return comp;
    }
};