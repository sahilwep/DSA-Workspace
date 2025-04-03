/*

//  2368. Reachable Nodes With Restrictions DSU Solution

//  Problem Statement: 
    -> There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
    -> You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.
    -> Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.
    -> Note that node 0 will not be a restricted node.

// Example: 

    Example 1:
        Input: n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
        Output: 4
        Explanation: The diagram above shows the tree.
        We have that [0,1,2,3] are the only nodes that can be reached from node 0 without visiting a restricted node.

    Example 2:
        Input: n = 7, edges = [[0,1],[0,2],[0,5],[0,4],[3,2],[6,5]], restricted = [4,2,1]
        Output: 3
        Explanation: The diagram above shows the tree.
        We have that [0,5,6] are the only nodes that can be reached from node 0 without visiting a restricted node.


// Observations: 
    -> Given edge list of undirected graph.
    -> given restricted nodes.
    -> return the number of nodes reachable from the node '0'
    -> NOTE: node 0 is not considered as restricted.

    // Approach: 
        -> build adj list
        -> Query from restricted list => unordered_set<int>
        -> start graph traversal from '0' & count the number of node which are reachable & not lies in range restricted zones..

    // Example: 
        I/p: 
            n = 14
            edges = [[0,1],[0,4],[0,8],[1,2],[1,3],[4,5],[5,6],[6,7],[8,9],[9,10],[10,12],[12,13],[9,11]]
            restricted = [4,10,11]
        O/p: 6


    // DSU Approach:
        -> Insert all restricted into set for O(1) operations.
        -> Merge edges nodes together -> by checking that both the nodes should not be the part of "restricted"
        -> This will from multiple component of graph
        -> We will get our answer by simply getting the ultPar of '0',  In other words we have to find the size of components where (node = 0) falls.
        -> return that component size..
        
        -> In Other words, if we watch carefully these restricted nods work as breaking point of graph, means for single given component, these edge used to break into multiple components..

// Complexity: 
    -> TC: O(V + E) => near about O(V), because we are certain that we will have (V - 1) edges only
    -> SC: O(V) => For DSU

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// DSU Solution: 
class DSU {
public:
    vector<int> size, parent;
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = ultPar(parent[node]);     // path compression
    }
    void Union(int u, int v) {
        int ulp_u = ultPar(u);
        int ulp_v = ultPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& res) { // TC: O(V + E)

        unordered_set<int> st(begin(res), end(res));    // store in set to get values in O(1) operations..
        
        DSU ds(n);  

        // Process Edges & from Components: 
        for(auto &it: edges) {  // TC: O(E)
            int u = it[0], v = it[1];

            // Skip Restricted Nodes:
            if(!st.count(u) && !st.count(v)) {  // if both the values are not the part of the restricted, then only merge them.
                ds.Union(u, v);
            }
        }

        // Get the ultimate parent of node '0'
        int ultParOfNodeZero = ds.ultPar(0);

        // Count total number of nodes which falls into this zero groups:
        int zeroCompSize = 0;
        for(int i = 0; i < n; i++) {    // TC: O(V)
            if(ds.ultPar(i) == ultParOfNodeZero) zeroCompSize++;
        }


        return zeroCompSize;
    }
};

