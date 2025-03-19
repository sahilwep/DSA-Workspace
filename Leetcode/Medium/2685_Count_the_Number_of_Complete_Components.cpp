/*

//  2685. Count the Number of Complete Components


//  Problem Statement: 
    -> You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.
    -> Return the number of complete connected components of the graph.
    -> A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
    -> A connected component is said to be complete if there exists an edge between every pair of its vertices.



// Example:

    Example 1:
        Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
        Output: 3
        Explanation: From the picture above, one can see that all of the components of this graph are complete.

    Example 2:
        Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
        Output: 1
        Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
 

// Complete Graph:
    -> A complete graph is a graph in which each vertex is connected to every other vertex.


// Observations: 
    -> Given n total number of nodes starting with '0' to 'n-1' & given edges[] {node[x], node[y]} => x-------y
    -> Undirected edges.
    -> We are given graph in multiple components..
    -> We need to count total number of components whose making complete graph.


    // BruteForce Solution: 
        -> As we are given graph in multiple components & we need to check the number of components whose making complete graph.
        -> We will have to find the total number of components, & also store every components belonging nodes in separate list.
        -> Then iterate in every components & check whether every nodes are connected to every-other nodes or not?
        -> If every nodes connected to every-other nodes, then include that graph components as complete graph, & Return total number of Complete graph.
        

        // Approach:
            -> First build adj list from the given edges.
            -> Secondly using any traversal algorithm BFS/DFS we will find the total number of components & the nodes that belongs in every components, & store them in list.
            -> After that, Iterate in every components & find whether every nodes has direct edge with every other node or not?

            // Complexity Analysis:
                -> TC: O(E) + O(V + 2E) + O(C * v^3)
                    -> O(E): for Iterating & balding adj list.
                    -> O(V + 2E): Iterations in Graph & finding the total number of components.
                    -> O(C): Get every Component:
                        -> O(V * V): Checking every node with every other node.
                            -> O(V): for checking direct connections.

                -> SC: O(V + E)
                    -> for building adj list.
        

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BruteForce Solutions: Using BFS/DFS & Checking directly Connected nodes
class Solution {
private:
    // Function to return total number of elements belonging in every components:
    vector<int> totalComp(int node, vector<vector<int>> &adj, vector<int> &vis) {       // TC: O(V + 2E)
        vector<int> nodesInComponent;
        queue<int> q;

        vis[node] = 1;
        q.push(node);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            nodesInComponent.push_back(node);

            for(auto &it: adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return nodesInComponent;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        // Build Graph Adj list from given edges:
        vector<vector<int>> adj(n); // 0-based undirected & un-weighted graph.
        for(auto &it: edges) {  // TC: O(E)
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }


        // Finding Total Number of components & Storing all the nodes of that Components in every individual list:
        vector<vector<int>> comp;   // This will store all the individual components in 2-D Matrix.
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++) {    // TC: O(V)
            if(!vis[i]) {
                comp.push_back({totalComp(i, adj, vis)});
            }
        }

        // Now Get Every components & check whether every nodes has directed edge with ever other node in a components or not?
        int totalComponents = comp.size();  // Total Components of graph
        
        int completeGraph = 0;    // Store total Number of valid Complete graph.
        for(int i = 0; i < totalComponents; i++) {  // Get every Components:    TC: O(C * (V * V * (V)))


            // For every components: Check wether every nodes directly connected with every other nodes or not => Conditions for Complete graph.
            bool isCompValid = true;    // flag which will help us to exit if any node is violating the Complete graph case.
            for(int x = 0; x < comp[i].size(); x++) {   // for every node
                for(int y = x + 1; y < comp[i].size(); y++) {   // check every other node.
                    
                    int u = comp[i][x];     // node 'u'
                    int v = comp[i][y];     // node 'v'

                    // Check If node 'u' is directly connected with node 'v': {using adj list we can check the directly connected edge for u & v}
                    bool isFound = false;   // flag which will help us to exit once we found the node 'u' & 'v' connection dependency.

                    for(int r = 0; r < adj[u].size(); r++) {    // Now Iterate in adj[u] & Check whether 'v' exist or not or vice versa, because it's undirected graph.
                        if(adj[u][r] == v) {    // for every adj[u] {checking all the nodes & comparing it with 'v'}
                            isFound = true;     // if found, mark as true & exit
                            break;
                        }
                    }

                    // Check if we found node 'u' has direct edge with 'v' or not?
                    if(!isFound) {  // if not, mark flag "isComponentValid == false" & exit from that components.
                        isCompValid = false;
                        break;
                    }
                }

                // Break out from the iteration if this Components is not valid:
                if(!isCompValid) {
                    break;
                }
            }

            // Now Count the Valid Complete Graph Components:
            if(isCompValid) {
                completeGraph++;
            }
        }

        return completeGraph;
    }
};