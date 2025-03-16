/*

//  1319. Number of Operations to Make Network Connected


//  Problem Statement: 
    -> There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. 
    -> Any computer can reach any other computer directly or indirectly through the network.
    -> You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
    -> Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

// Example: 

    Example 1:
        Input: n = 4, connections = [[0,1],[0,2],[1,2]]
        Output: 1
        Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

    Example 2:
        Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
        Output: 2

    Example 3:
        Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
        Output: -1
        Explanation: There are not enough cables.



// Observations: 
    -> Given 0-based indexing
    -> Given connected edges b/w two computer..
    -> We can remove one edges from any two nodes which are connected even after removed.
    -> and with that extra edge, we can connect one computer which were not connected directly or indirectly.
    -> In Simple:
        -> We exactly need (totalComponents - 1) edges to connect all the components in a single components.
        -> And also we need to check whether we have enough extraEdges, means "extraEdges >= (totalComponents - 1)".
        
        // Why DSU & how it can help to achieve the given configurations:
            -> DSU will helps us to find if there is extraEdge in a components, By finding Ultimate parent:
                -> If two nodes already found in a single component, means they have same parent, & if we try to connect same tow nodes with some edges, then they both have same parent, that can be count as extra edges
                -> DSU will help us to find whether the two nodes have same parent or not?
    
            -> How DSU will helps us to know the number of total Components
                -> With iterating in parent, we can find the total number of ultimate parent, & those much is our total number of components in graph.
                -> We can iterate & find the node whose parent are node itself, considered as Ultimate parent.

    
    -> We are given graph with n vertices and m edges.
    -> NOTE: We need to make sure, extra number of edges should be there so that we can remove them and connect all the components together, 
        -> If number of extraEdges is lesser than the required edges to connect all components them it's not possible to connect all components together.



// Complexity: 
    -> TC: O(N + E)
        -> N = total number of computers
        -> E = total number of wires.
    -> SC: O(1), IF we consider DSU Outside the considerations Solution Implementations, else O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// DSU:
class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet (int n) {
        parent.resize(n + 1);
        size.resize(n + 1);

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

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }   
    }
};


// Solution:
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& edges) {
        
        DisjointSet ds(n);

        // Form all the components & count Extra edges:
        int extraEdg = 0;
        for(auto &it: edges) {
            int u = it[0];
            int v = it[1];
            
            if(ds.findUltPar(u) != ds.findUltPar(v)) {
                ds.unionBySize(u, v);
            }else {
                extraEdg++;
            }
        }

        // Count Total Number of Ultimate Parent:
        int totalCmp = 0;
        for(int i = 0; i < n; i++) {
            if(ds.parent[i] == i) totalCmp++;
        }

        return (extraEdg >= totalCmp - 1) ? totalCmp - 1 : -1;
    }
};