/*

//  G-11. Detect a Cycle in an Undirected Graph using DFS


// Problem Statement: 
    * Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, 
    * check whether the graph contains any cycle or not. The Graph is represented as an adjacency list, 
    * where adj[i] contains all the vertices that are directly connected to vertex i.

    * NOTE: The adjacency list represents undirected edges, meaning that if there is an edge between vertex i and vertex j, both j will be adj[i] and i will be in adj[j].


// Example:
    Input: adj = [[1], [0,2,4], [1,3], [2,4], [1,3]] 
    Output: 1
    Explanation: 1->2->3->4->1 is a cycle.

    Input: adj = [[], [2], [1,3], [2]]
    Output: 0
    Explanation: No cycle in the graph.



//  Observations: 

    -> For this given Problem, we are usign DFS: dfs goes depth wise

                           [2]---------------[5]
                          /                     \
                        /                        \
                     [1]                          [7]
                       \                          /
                         \                      /
                          [3]-----------------[6]
                           |
                           |
                          [4]


    // Adj List:
        1 -> {2, 3}
        2 -> {1, 5}
        3 -> {1, 4, 6}
        4 -> {4}
        5 -> {2, 7}
        6 -> {3, 7}
        7 -> {5, 6}

    -> In DFS, if we started from a node, & coming back to the same node, that means we would have a cycle for sure.

            -> let say source node is '1'
                    dfs(node, parent)
                    dfs(1, -1), initially parent is '-1' for source node

                                                    dfs(1, -1)
                                                    /        \
                                             dfs(2, 1)       dfs(3, 1)
                                             /                    ..
                                         dfs(5, 1)
                                        /
                                    dfs(7, 5)
                                    /
                                dfs(6, 7)
                                /
                            dfs(3, 6)
                            /       \
                        dfs(4, 3)   dfs(1, 3)-> This is already visited, return true, & then whole call above return true.
                          |
                        false

            -> When there is no node further to move, return false
            -> When we got same starting node, we will return true for cycle.

            -> If any node that is not visited, by chance return true -> we will return true.
            -> If any node that is visited already, & that is not the parent, then we say cycle found, & return true also.


// Complexity:

    * TC: O(n + 2E) + O(n)
        -> For every node, we are traversing all it's adjacent nodes.
        -> Adjacent node are degree, & the summation of adjacent node is summation of degree -> 2E in undirected graph.
        -> O(n), for component thing, that we are running in for loop, because in worse case every node are single, & we may need to run for all nodes...
    * AS: O(n)


// NOTE: 
    -> In case of connected component, we need to check all the component of graph.
    -> We say a graph to have a cycle if any of the component have cycle.
    -> For every, call, if we are visiting any node, that are already visited, it has to be non-parent, then only we can say it's cycle.


*/


#include <bits/stdc++.h>

using namespace std;class Solution {
private:
    bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis) {
        // Mark the current node as visited.
        vis[node] = 1;

        // Iterate over all adjacent nodes of the current node.
        for(auto adjacentNode : adj[node]) {
            // Case 1: If the adjacent node is not visited, perform DFS on it.
            if(!vis[adjacentNode]) {
                if(dfs(adjacentNode, node, adj, vis) == true) {    // If a cycle is found during the DFS traversal, propagate the result upwards.
                    return true;
                }
            }
            // Case 2: If the adjacent node is already visited and it's not the parent, it indicates a cycle.
            else if(adjacentNode != parent) {
                return true;
            }
        }

        return false;   // If no cycle is found in this DFS path, return false.
    }

public:
    bool isCycle(vector<vector<int>> &adj) {
        int V = adj.size();          // Number of vertices in the graph.
        vector<int> vis(V, 0);       // Visited array initialized to 0 for all nodes.

        // Traverse all nodes to handle disconnected components.
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {   // If the node is unvisited, start a DFS from it.
                if(dfs(i, -1, adj, vis)) {  // Pass -1 as the parent for the starting node of a new component.
                    return true;    // If a cycle is detected, return true.
                }
            }
        }

        return false;   // If no cycle is detected in any component, return false.
    }
};



int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if(ans) cout << "1\n";
        else cout << "0\n";
        cout << "~" << "\n";
    }
    return 0;
}