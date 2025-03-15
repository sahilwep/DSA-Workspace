/*


//   G-49. Number of Operations to Make Network Connected - DSU


//  Problem Statement: 
    -> You are given a graph with n vertices (0 to n-1) and m edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation. Find the minimum number of operations that will be required to connect the graph.
    -> If it is not possible to connect the graph, return -1.


// Example:

    Example 1: 
        Input:
            n = 4
            m = 3
            Edges = [ [0, 1] , [0, 2] , [1, 2] ]
        Output: 1
        Explanation: Remove edge between vertices 1 and 2 and add between vertices 1 and 3.

    Example 2:
        Input:
            n = 6
            m = 5
            Edges = [ [0,1] , [0,2] , [0,3] , [1,2] , [1,3]]
            Output: 2
        Explanation: Remove edge between (1,2) and(0,3) and add edge between (1,4) and (3,5)


// Observations:
    -> We are given graph with n vertices and m edges.
    -> We can remove one edge from any two nodes & connect two components with that removed edge.
    -> We need to find minimum edges, so that we can connect all the components all together.
    -> NOTE: We need to make sure, extra number of edges should be there so that we can remove them and connect all the components together, 
        -> If number of extraEdges is lesser than the required edges to connect all components them it's not possible to connect all components together.
    -> We exactly need (totalComponents - 1) edges to connect all the components in a single components.
    -> And also we need to check whether we have enough extraEdges, means "extraEdges >= (totalComponents - 1)".
    
    // Why DSU & how it can help to achieve the given configurations:
        -> DSU will helps us to find if there is extraEdge in a components, By finding Ultimate parent:
            -> If two nodes already found in a single component, means they have same parent, & if we try to connect same tow nodes with some edges, then they both have same parent, that can be count as extra edges
            -> DSU will help us to find whether the two nodes have same parent or not?

        -> How DSU will helps us to know the number of total Components
            -> With iterating in parent, we can find the total number of ultimate parent, & those much is our total number of components in graph.
            -> We can iterate & find the node whose parent are node itself, considered as Ultimate parent.
         
    // Complexity:
        -> TC: O(n + E),
            -> n = total nodes
            -> E = total number of edges.
        -> SC: O(1)

    

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// DisjointSet
class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
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
        }else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] = size[ulp_v];
        }
    }
};

class Solution {
public:
    int Solve(int n, vector<vector<int>>& edge) {
        
        // Given n-vertices
        DisjointSet ds(n);
        
        // We required exactly {x = (totalComp - 1)}  edge to connect all components together:
        // Also we need (extraEdge >= x), then only we can connect all components together, because as per the given constrains, we can only joint two component together if we can remove extra edge from any valid component.
        
        int extraEdge = 0;
        for(auto &it: edge) {   // O(edgSize)
            int u = it[0];
            int v = it[1];
            
            int ulp_u = ds.findUltPar(u);   // O(1)
            int ulp_v = ds.findUltPar(v);   // O(1)
            
            if(ulp_u != ulp_v) {
                ds.unionBySize(u, v);   // O(1)
            }
            else {
                extraEdge++;
            }
        }
        
        int totalComp = 0;
        for(int i = 0; i < n; i++) {    // O(n)
            if(ds.parent[i] == i) totalComp++;
        }
        
        return (extraEdge >= totalComp - 1) ? totalComp - 1 : -1;
    }
};