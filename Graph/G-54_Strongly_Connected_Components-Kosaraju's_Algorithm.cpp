/*

//  G-54. Strongly Connected Components - Kosaraju's Algorithm


//  Problem Statement: 
    -> Given an adjacency list, adj of Directed Graph, Find the number of strongly connected components in the graph.
 

// Examples :
    Input: adj[][] = [[2, 3], [0], [1], [4], []]

                    [0]---------->[3]
                   ↗ ↑             |
                  /  |             |
                /    |             ↓
              /      |            [4]
            /        |  
          [1]<------[2]     

    Output: 3


                    [0]---------->[3]
                   ↗ ↑             |
                  /  |             |
                /    |             ↓
              /      |            [4]
            /        |  
          [1]<------[2]     

                SCC1: (0, 1, 2)
                SCC2: (3)
                SCC3: (4)

    Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.

    Input: adj[][] = [[1], [2], [0]]
    Output: 1

    Explanation: All of the nodes are connected to each other. So, there's only one SCC.


// Kosaraju's Algorithm:
    

        [0]<-----[2]----->[3]----->[4]---->[7]
         |      ↗                   |  ↖    ↑
         |    /                     |    \  |
         ↓  /                       ↓     \ |
        [1]                        [5]---->[6]


        SCC1: (0, 2, 1)
        SCC2: (3)
        SCC3: (4, 5, 6)
        SCC3: (7)

            [SCC1]---e1--->[SCC2]---e2--->[SCC3]---e3--->[SCC4]

                    e1 => (2, 3)
                    e2 => (3, 4)
                    e3 => (4, 7) && (6, 7)


    // SCC: 
        -> A Component is called SCC only if for every possible pair of vertices (u, v) inside that component, u is reachable from v & v is reachable from u.
        -> A Component containing single vertices is always a SCC.
        -> Any SCC more than one vertices known as cycle in graph.
        -> SCC valid in Directed graph only.

    // Observations:
        -> By the Definations within each SCC, every node is reachable
            -> If we start DFS from a node of SCC1 we can visit all the node of SCC1 & via edge e1 we can visit SCC2.
            -> Similarly we can travel from SCC2 to SCC3 via e2 & SCC3 to SCC4 via e3
            -> But, If we reverse the e1, e2 & e3, the graph look something like this:

        
                [0]<-----[2]<----[3]<------[4]<----[7]
                 |      ↗                   |  ↖    |
                 |    /                     |    \  |
                 ↓  /                       ↓     \ ↓
                [1]                        [5]---->[6]

            -> Now If we start dfs from '0' we only Visit SCC1, and if we start dfs with '3' we only visit SCC2
            -> Similarly, for every node we visit their SCC part.
        -> So If we reverse the whole graph edge it will not effect SCC Components, Because SCC has Cycle if it's has more than 1 node.
        -> After that with simply iterating DFS one more time we can count total SCC
        -> But we need to store the Finishing Time for every node.

    // Algorithm:
        -> Sort all the nodes according to their finishing Time:
            -> We will start dfs from node '0' & while backtracking in dfs call we will store node in stack data structure.
            -> The node in last SCC will finish first and be sorted in the last of the stack.
            -> After Completing all the node stack will storing all the nodes according to their Finishing times.

        -> Reverse all the edges of entire graph:
            -> reverse the given adj list from 'u' -----> 'v' to 'v' -----> 'u'

        -> Perfrom the DFS & count the number of Different DFS Calls, this much will be our total SCC in given graph.


// Intrusion: 
    -> For SCC graph, we have special property, in every SCC we can visit any two pairs of nodes from anywhere in that SCC.
    -> first get the finishing time of every node in that graph with normal dfs storing nodes in stack while backtracking.
    -> Reverse all the edge of graph, this will not affect cycles, in other words not effect SCC.
    -> Now again run DFS from the finishing time & count total number of SCC.


// Complexity: 
    -> TC: O(V + E) -> For DFS
    -> SC: O(V + E) -> For Reversed adj list

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    void dfs1(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {   // DFS to store the finishing time of every node
        vis[node] = 1;
        for(auto &it: adj[node]) if(!vis[it]) dfs1(it, adj, vis, st);
        
        st.push(node);
    }
    void dfs2(int node, vector<vector<int>>& adj, vector<int> &vis) {   // normal DFS to visit every node of the graph Components:
        vis[node] = 1;
        for(auto &it: adj[node]) if(!vis[it]) dfs2(it, adj, vis);
    }
public:
    int kosaraju(vector<vector<int>> &adj) {    
        int V = adj.size();
        
        // First get the Finishing Time of Ever Node with dsf1
        stack<int> st;
        vector<int> vis1(V, 0);
        for(int i = 0; i < V; i++) {
            if(!vis1[i]) {
                dfs1(i, adj, vis1, st);
            }
        }
        
        // Now Reverse the Graph:
        vector<vector<int>> adjRev(V);
        for(int u = 0; u < V; u++) {
            for(auto &v: adj[u]) {
                adjRev[v].push_back(u);
            }
        }
        
        // Get the number of SCC: 
        int scc = 0;
        vector<int> vis2(V, 0);
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