/*

//  685. Redundant Connection II DSU Approach


//  Problem Statement: 
    -> In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.
    -> The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. 
    -> The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.
    -> The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.
    -> Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. 
    -> If there are multiple answers, return the answer that occurs last in the given 2D-array.


// Example: 
    Example 1:

        Input: edges = [[1,2],[1,3],[2,3]]
        Output: [2,3]

    Example 2:
        Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
        Output: [4,1]


// Why DSU?
    -> We are given a list of edges and need to process them in order to construct a graph.
    -> To identify a redundant edge that creates a cycle, DSU helps efficiently manage disjoint sets (components).
    -> DSU will assist in merging nodes and detecting cycles when an edge connects two nodes already in the same component.

    
DSU Approach:
    -> The core idea is to detect the one extra edge that violates the tree property.
    -> There are two major cases:
        1. A node has two parents (i.e., indegree > 1).
        2. There is a cycle due to the added edge.
    // For case 1:
        -> Identify the node with two parents.
        -> Record both the conflicting edges (let's call them `cand1` and `cand2`).
        -> Temporarily invalidate the second incoming edge so we can check if removing it solves the problem.
    // For case 2:
        -> Perform DSU union operations on the valid edges.
        -> If a union fails (i.e., `u` and `v` already share the same root), then that edge is the one forming a cycle.

    // Final Logic:
        -> If a cycle is detected and a node had two parents:
            -> The first incoming edge (`cand1`) is the culprit.
        -> If a cycle is detected but no node had two parents:
            -> The edge that triggered the failed union is the culprit.
        -> If no cycle is detected and a node had two parents:
            -> The second incoming edge (`cand2`) is the culprit.


// Complexity: 
    -> TC: O(V + E)
    -> SC: O(V)

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
        if(parent[node] == node) return node;
        return parent[node] = ultPar(parent[node]);
    }
    bool Union(int u_, int v_) {    // modified Union to detect redundant edge for components
        int u = ultPar(u_);
        int v = ultPar(v_);

        if(u == v) return true; // return true for Redundant edge find

        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        }
        else {
            parent[v] = u;
            size[u] += size[v];
        }
        return false;   // false no redundant edge find.
    }
};


class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        DSU ds(V + 1);

        // Step 1: Find the valid Candidate/node which has two parent & store those edges: Calculating indegree of node which has more than 1 parent.
        vector<int> parent(V + 1, 0);
        vector<int> cand1, cand2;
        for(auto &edge: edges) {
            int u = edge[0], v = edge[1];
            if(parent[v] == 0) {    // setting up parent for every node
                parent[v] = u;
            }
            else {  // if someone already has parent set:
                cand1 = {parent[v], v}; // previous edge
                cand2 = {u, v};         // current edge

                edge[1] = -1;            // marking 'v' for this one is invalid, because we don't wan't to process them..
            }
        }


        // Step 2: Now Perform DSU & find Redundant Edge: 
        for(auto &edge: edges) {
            int u = edge[0], v = edge[1];
            if(v == -1) continue;   // skip the edge which we marked invalid
            
            if(ds.Union(u, v)) {    // If We got Redundant:
                // If cand1 is empty, no node with two parent, means have just found the redundant edge and that will the problem, so return the edge, which is {u, v}.
                if(cand1.empty()) {
                    return {u, v};
                }
                return cand1;   // else return "candidate 1"
            }
        }

        return cand2;   // If no redundant edge is detected, then candidate 2 is the problem:
    }
};
