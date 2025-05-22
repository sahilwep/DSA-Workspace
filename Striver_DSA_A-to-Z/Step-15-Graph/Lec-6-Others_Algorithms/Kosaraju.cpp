/*

//  Strongly Connected Component -> Kosaraju


//  Problem Link: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// Kosaraju:

    // SCC: 
        -> A Component is called SCC only if for every possible pair of vertices (u, v) inside that component, u is reachable from v & v is reachable from u.
        -> A Component containing single vertices is always a SCC.
        -> Any SCC more than one vertices known as cycle in graph.
        -> SCC valid in Directed graph only.
        
        
    // Algorithm:
        -> Sort all the nodes according to their finishing Time:
            -> We will start dfs from node '0' & while backtracking in dfs call we will store node in stack data structure.
            -> The node in last SCC will finish first and be sorted in the last of the stack.
            -> After Completing all the node stack will storing all the nodes according to their Finishing times.

        -> Reverse all the edges of entire graph:
            -> reverse the given adj list from 'u' -----> 'v' to 'v' -----> 'u'

        -> Perfrom the DFS & count the number of Different DFS Calls, this much will be our total SCC in given graph.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private: 
    // Function used to compute the finishing time
    void dfs1(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for(auto &it: adj[node]) if(!vis[it]) dfs1(it, adj, vis, st);
        st.push(node);
    }
    // Normal DFS traversal logic:
    void dfs2(int node, vector<vector<int>>& adj, vector<int>& vis) {
            vis[node] = 1;
            for(auto &it: adj[node]) if(!vis[it]) dfs2(it, adj, vis);
    }
public:
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();

        // Step 1: Compute Finishing time:
        vector<int> vis1(V, 0);
        stack<int> st;
        for(int i = 0; i < V; i++) {
            if(!vis1[i]) {
                dfs1(i, adj, vis1, st);
            }
        }

        // Step 2: Reverse the graph:
        vector<vector<int>> adjRev(V);
        for(int i = 0; i < V; i++) {
            for(auto &it: adj[i]) {
                adjRev[it].push_back(i);
            }
        }

        // Step 3: Compute SCC by calling normal DFS
        vector<int> vis2(V, 0);
        int scc = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();

            if(!vis2[node]) {
                dfs2(node, adjRev, vis2);
                scc++;
            }
        }

        return scc;
    }
};
