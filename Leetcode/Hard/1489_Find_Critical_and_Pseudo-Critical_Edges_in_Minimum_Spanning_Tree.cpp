/*

//  1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree


//  Problem Statement: 
    - Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.
    - Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.
    - Note that you can return the indices of the edges in any order.

    
// Example:
    Example 1:
        Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
        Output: [[0,1],[2,3,4,5]]

    Example 2:
        Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
        Output: [[],[0,1,2,3]]
        Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.


// Observations:
    - Given a graph n nodes
        - given edges, {u, v, wt}
    - We have to find all the Critical & pseudo-critical edges from the graph MST.


    // DSU Approach:
        - Kruskal's algorithm will help us to find the MST form the graph.
        - Once we find the MST, we need to find all edges which are critical or pseudo-critical to mst
            - Critical: Without this edge, MST will increase
            - Pseudo-critical: Without this edge, there will not be any effect.
        - Firstly, find the MST using DSU
        - Secondly, we will iterate into edges & for every edge:
            - Run MST with force including that edge, and even after including if MST stays same call Pseudo Critical.
            - Run MST with discarding that edge, if mst increases means it's critical.
        
        // Complexity:
            - TC: O(E * logE)
            - SC: O(V + E)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class DSU {
private:
    vector<int> size, parent;
public:
    DSU (int n) {
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

        // Connect smaller group to larger ones:
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
private:
    int findMst(vector<vector<int>>& edges, int idx, int n, bool isForced) {

        // Connect the components:
        DSU ds(n + 1);
        int mst = 0;
        int edgeCnt = 0;    // this will check if we have multiple components

        // Check if it's Force Include: include this initially
        if(isForced) {
            int wt = edges[idx][0], u = edges[idx][1], v = edges[idx][2];
            ds.Union(u, v);
            mst += wt;
            edgeCnt++;
        }

        for(int i = 0; i < edges.size(); i++) {
            if(i == idx) continue;  // skip the given edge

            int wt = edges[i][0], u = edges[i][1], v = edges[i][2];
            if(ds.ultPar(u) == ds.ultPar(v)) continue;  // skip already connected comp.
            
            ds.Union(u, v);
            mst += wt;
            edgeCnt++;
        }

        return (edgeCnt == n - 1) ? mst : INT_MAX;  // mst for n node will always have n - 1 edges
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& oldEdge) {
        
        // Build Sorted edge list:
        vector<vector<int>> edges;
        for(int i = 0; i < oldEdge.size(); i++) {
            int u = oldEdge[i][0], v = oldEdge[i][1], wt = oldEdge[i][2];
            edges.push_back({wt, u, v, i});    // insert with weight as considerations factor.
        }

        sort(begin(edges), end(edges)); // sort them.
        
        
        // Find MST & the edges that are not contributing in MST:
        int mst = findMst(edges, -1, n, false);   // find the mst with given edges:


        vector<vector<int>> ans(2);     // ans[0] = critical, ans[1] = pseudo
        for(int i = 0; i < edges.size(); i++) {

            // Check critical case:
            int newMst1 = findMst(edges, i, n, false);
            if(newMst1 > mst) {         // Without this edge mst will increases
                ans[0].push_back(edges[i][3]);    // critical edge, insert the original edge index
                continue;
            }

            // Pseudo critical:
            int newMst2 = findMst(edges, i, n, true);
            if(newMst2 == mst) {        // even after including, if mst stays same: pseudo critical.
                ans[1].push_back(edges[i][3]);    // pseudo critical edge,  insert the original edge index
            }

            // else: this current edge has no-contribution on MST.
        }

        return ans;
    }
};