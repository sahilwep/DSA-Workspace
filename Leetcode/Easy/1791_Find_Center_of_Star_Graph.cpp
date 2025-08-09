/*

//  1791. Find Center of Star Graph


//  Problem Statement: 
    -> There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.
    -> You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.

 
// Example: 

    Example 1:
        Input: edges = [[1,2],[2,3],[4,2]]
        Output: 2
        Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.

    Example 2:
        Input: edges = [[1,2],[5,1],[1,3],[1,4]]
        Output: 1

// Observations: 
    -> If we Carefully look on the graph, star center node has exactly (n - 1) connected nodes
    -> In other words, Given graph is undirected, means find the node which has exactly (n - 1) neighbors..


// Complexity: 
    -> TC: O(N)
    -> SC: O(N), Because we are bound that this graph is star graph, & only one node has (n - 1) size & rest of them were in very less numbers...


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// ---------------- Newer Version: More logical & stable ----------------
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int V = 0;
        for(auto& it: edges) {
            V = max({it[0], it[1], V});
        }

        // Build Adj list: 
        vector<vector<int>> adj(V + 1); // total size of adj list:
        for(auto& it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // Find the node which has exactly V - 1 NODES:
        for(int i = 1; i < V + 1; i++) {
            if(adj[i].size() == V - 1) return i;
        }

        return -1;  // Given graph is not Star-Graph.
    }
};


// ----------------- Older Version Naive Impl.-----------------
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        n++;    // increment n by 1, because for x node, we have (x - 1) edges.

        vector<vector<int>> adj(n + 1); // initialization by (n + 1), because of 1 based indexing

        // Build Adj list: 
        for(auto &it: edges) {
            int u = it[0], v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Iterate in adj list & find the node which has exactly (n - 1) neighbors.
        for(int i = 1; i < n + 1; i++) {
            if(adj[i].size() == n-1) return i;
        }

        return -1;  // given graph is not in star from.
    }
};

