/*

//  G-48. Number of Provinces - Disjoint Set



//  Problem Statement: 
    -> Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.
    -> Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.


// Example:
    Example 1:
        Input:
            [[1, 0, 1],
            [0, 1, 0],
            [1, 0, 1]]

        Output: 2
        Explanation: The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.

    Example 2:
        Input:
        [[1, 1],
        [1, 1]]

        Output: 1

// Observations: 
    -> Given undirected graph.
    -> 1-based indexing.
    -> We need to find the number of provinces.


    // Why DSU ?
        -> DSU will helps to find the total number of connected components, with findUltParent() functions.

    // DSU Approach:
        -> Implement DSU
        -> Process matrix: connect nodes together by calling unionBySize
        -> Last count the number of ultimate parent, either use set & store total number of unique parent, OR use counter & check ultimate parent with node which has parent itself.

    // Complexity:
        -> TC: O(V^2)
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Disjoint Set Implementations:
class DisjointSet {
private:
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        
        for(int i = 0; i < n + 1; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUltPar(int node) {
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = findUltPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUltPar(u);
        int ulp_v = findUltPar(v);
        
        if(ulp_v == ulp_u) return;
        
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};


class Solution {
public:
    int numProvinces(vector<vector<int>> adj, int V) {
        
        DisjointSet ds(V);
        
        // Build Disjoint set: connect nodes:
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(adj[i][j] == 1){
                    ds.unionBySize(i + 1, j + 1);  // 1-based indexing
                }
            }
        }


        /*
        // OR Either process only half of the matrix, because it's undirected graph:
        for(int i = 0; i < V; i++) {
            for(int j = i + 1; j < V; j++) {
                if(adj[i][j] == 1){
                    ds.unionBySize(i + 1, j + 1);  // 1-based indexing
                }
            }
        }
        */

        
        // Find parent:
        int cnt = 0;
        for(int i = 1; i < V + 1; i++) {    // 1-based indexing
            if(ds.findUltPar(i) == i) { // if the parent of a node is node itself, means it's the ultimate parent:
                cnt++;
            }
        }
        
        return cnt;
    }
};