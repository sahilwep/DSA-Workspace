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
        


    // DSU Approach: 
        // Why DSU ?
            -> Because graph is distributed in multiple components.
            -> And we need to check for the conditions of complete graph, where we can process ever edges & count the number of available edge for every components.
            -> Also for every components, we can easily get the size, how many nodes they have?.

            // Approach:
                -> First Connect all the node & form graph components.
                -> Store the informations of ultimate parent, size of every components, & required edges they need for every components(with using summations formula).
               
                    // How to find number of required graph for every component:
                        -> Let's say a component size is '4', in other words it has 4 nodes
                            -> We need to find every node connected with every other nodes.
                                Component[x] = {1, 2, 3, 4}, size = 4

                                pairs: (1, 2), (1, 3), (1, 4), (2, 3), (2, 4), (3, 4) => Total 6 edges required

                        // We can get this computation with summations formula:
                            -> summations of '1' to 'n' = n * (n + 1) / 2
                            -> summations of '0' to 'n' = (n-1) * n / 2

                                -> More Example:

                                        for '3' node = {1, 2, 3} => 3 (required)
                                        for '4' node = {1, 2, 3, 4} => 6 (required)
                                        for '5' node = {1, 2, 3, 4, 5} => 10 (required)
                                        for '6' node = {1, 2, 3, 4, 5, 6} => 15 (required)

                -> Once again, iterate in edge list & store the number of available edge in graph for every components by getting the details of every ultimate parent.
                -> Last iterate in ultimate parent list & compare the available edge & required edge & store the details of complete graph.
                    -> Comparing Conditions: 
                        if(availableEdge == requiredEdge) => CompleteGraph
                        Because for complete graph, there will exactly be same number of required & available edge.

        // Complexity:
            -> TC: O(N + E)
            -> SC: O(N), N = total number of edges.

        
// NOTE: Given graph is 0-based indexed.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// DSU Approach:
class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = ultPar(parent[node]); // path compression.
    }
    void Union(int u, int v) {
        int ulp_u = ultPar(u);
        int ulp_v = ultPar(v);
        
        if(ulp_u == ulp_v) return;
        
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);      // declare disjoint of size 'n'

        // Connect nodes & form components.
        for(auto &edge: edges) {    // TC: O(E))
            int u = edge[0], v = edge[1];
            ds.Union(u, v); // TC: O(1)
        }

        // Now get the size of every components with corresponding to their ultimate parent, parallel store the required size for every components.
        map<int, int> compSize;     // For every component size
        map<int, int> reqEdge;      // Store required edge for every components.
        map<int, int> avlEdge;      // Store available edge for every components.
        vector<int> ultimatePar;    // Store Ultimate parent of every components.

        for(int i = 0; i < n; i++) {    // TC: O(n)
            if(ds.parent[i] == i) {    // find the ultimate parent:
                compSize[i] = ds.size[i];   // store size of every component    
                reqEdge[i] = (((ds.size[i] - 1) * (ds.size[i]) ) / 2);  // Store the number of edge required for every edge.    // TC: O(1)
                avlEdge[i] = 0; // Default initialization with '0', in order to handel the components, were they have single node.
                ultimatePar.push_back(i);   // store ultimate parent of every components.
            }
        }

        // Now Store the available edge for every ultimate parent:
        for(auto &edge: edges) {    // TC: O(E * (1))
            int u = edge[0], v = edge[1];

            int ulp = ds.ultPar(u); // find ultimate parent of any node (u, v), because the both belong to same components & they both have same ultimate parent.       TC: O(alpha(n)) with inverse Ackermann Function => O(4) => O(1)

            avlEdge[ulp]++;   // increment 1 edge for this ultimate parent availableEdge map:
        }

        // Now Compare the available edge with required ones by iterating in ultimate Parent & store number of complete graph:
        int completeGraph = 0;
        for(auto &ulp: ultimatePar) {   // O(n), in worse case.
            // Conditions for complete graph:
            int req = reqEdge[ulp];
            int avl = avlEdge[ulp];

            // If number of required edge in component is equal to number of available edge in component, then increment the count of complete graph.
            if(req == avl) {
                completeGraph++;
            }
        }

        return completeGraph;
    }
};


/* --------------------------------------------------------------------------------------------------------------------------------- */


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