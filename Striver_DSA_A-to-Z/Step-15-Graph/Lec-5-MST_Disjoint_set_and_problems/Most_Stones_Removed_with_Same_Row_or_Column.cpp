/*

//  947. Most Stones Removed with Same Row or Column

//  Problem Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/



// Observations: 
    -> Given stones coordinate.
    -> a stone can be removed if it's share same row or same col with other stones.
    -> We have to return the maximum number of stones that we can remove..


    // DSU Approach: 
        -> Form components
        -> Total stones that can be removed is: totalStones - totalComponents
        -> Given coordinates of stones
        -> same row / col should be connected..


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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        
        // Edge point for DSU as per constrains => 1e4 + 1
        // Form components: 
        DSU ds(2 * (1e4 + 1));
        set<int> validComp;
        for(auto &it: stones) {
            int u = it[0], v = it[1] + (1e4 + 1);
            ds.Union(u, v);
            validComp.insert(u);
        }

        // Now count total number of components: 
        int comp = 0;
        for(auto &it: validComp) {
            if(ds.ultPar(it) == it) {
                comp++;
            }
        }
        
        return n - comp;
    }
};