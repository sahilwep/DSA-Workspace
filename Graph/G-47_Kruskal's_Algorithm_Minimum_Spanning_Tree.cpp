/*

//   G-47. Kruskal's Algorithm - Minimum Spanning Tree - C++


//  Problem Statement: 
    -> Given a weighted, undirected, and connected graph with V vertices and E edges, the task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph using Kruskal's Algorithm. The graph is represented as an edge list edges[][], where edges[i] = [u, v, w] denotes an undirected edge between u and v with weight w.


// Example: 
    Input: V = 3, E = 3, edges[][] = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
    Output: 4
        Explanation: The Spanning Tree resulting in a weight of 4 is shown above.
    
    Input: V = 2, E = 1, edges = [[0, 1, 5]]
    Output: 5 
        Explanation: Only one Spanning Tree is possible which has a weight of 5.
    


// kruskal's algorithm MST: 
    // What is Kruskal's Algorithm:
        -> Kruskal's algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a connected, undirected, weighted graph by iteratively adding edges with the smallest weights, ensuring no cycles are formed. 

    // Approach:
        -> Build edge_List: with considering factor as edges_weight
        -> Sort them based on edge_weight
        -> Process edge_list:
            -> If both node has not the same componenets -> then only connect (u, v) with DSU.
            -> & Add their weight in MST.

    // How DSU will help us to find the MST:
        -> With DSU we can have informations of two connected nodes whether they belongs in same components or not in O(1) constant time.
        -> While forming MST -> We only choose those edges which has less edge weight connecting tow nodes.
        -> With sorting first & then processing it with DSU will help us to know the MST weight of the MST Graph.
        

    // Complexity: 
        -> TC: O(V * log(V) + O(V * O(1))) => O(V * log(V))
        -> SC: O(V) -> for sparse graph



*/


#include <bits/stdc++.h>
using namespace std;


// DisjointSet: Union by size:
class DisjointSet {
private:
    vector<int> parent, size;
public: 
    DisjointSet(int n) {
        size.resize(n + 1, 1);      // initially every components treated as individual.
        
        // everyone parents are themselves.
        parent.resize(n + 1, 0);
        for(int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
    }
    // Find ultimate parent:
    int findUltParent(int node) {
        // base case:
        if(parent[node] == node) {  // when any node pointing itself => return case, we have successfully find the ultimate parent.
            return node;    
        }
        
        // Recursive case: 
        return parent[node] = findUltParent(parent[node]);     // Using path compression which will give us O(1) constant time while we find any "node" in future.
    }
    // unionFind By Size:
    void unionBySize(int u, int v) {
        int ult_u = findUltParent(u);   // find ultimate parent of 'u'
        int ult_v = findUltParent(v);   // find ultimate parent of 'v'
        
        // Check whether they were in same component or not?
        if(ult_u == ult_v)  return;     // for same components don't do anything.
        
        // If they were in different components: connect them together => smaller to larger: By Size:
        if(size[ult_u] < size[ult_v]) { // size of ultimate parent of u is smaller than size of ultimate parent of v => connect ultimate parent 'u' to ultimate parent of 'v' & add overall size of ultimate parent of size 'v' by adding size of 'u' into it..
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u]; // increment size of larger node, as smaller added into it.
        } 
        else {  // ultimate parent of v size is lesser than the ultimate parent of size u: connect v to u & increment the size of 'u'
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];

        }   // NOTE: Equality case handled here because => In equality case we can connect anyone to anyone.
    }
};


class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &givenEdges) { // TC: O(V * log(V))
        // form edges with considering factors as weight:
        vector<pair<int, pair<int, int>>> edges;    // structure => <wt, <u, v>>
        
        for(auto &it: givenEdges) {
            edges.push_back({it[2], {it[0], it[1]}});
        }
        
        // Sort them: TC: O(V * log(V)) 
        sort(begin(edges), end(edges)); // sorting on the basis of weight. 
        
        // Process Edges & Find MST: 
        int mst = 0;
        DisjointSet ds(V);  // Initialize DSU of size 'V' vertices, NOTE 0 -> based indexing
        for(auto &i: edges) {   // O(V * O(1))
            int wt = i.first;
            int u = i.second.first;
            int v = i.second.second;
            
            // Find ultimate parents of (u, v):  O(1)
            int ult_u = ds.findUltParent(u);    // find ultimate parent of u
            int ult_v = ds.findUltParent(v);    // find ultimate parent of v
            
            // Process MST only if they were not in the same components:
            if(ult_u != ult_v) {    // O(1)
                ds.unionBySize(u, v);   // connect these two components into single components by unionBySize
                mst += wt;  // Only add those edge weight which is being initially in different components.
            }
        }
        
        return mst;
    }
};
