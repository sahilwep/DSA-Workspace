/*

//  1579. Remove Max Number of Edges to Keep Graph Fully Traversable


//  Problem Statement: 
    - Alice and Bob have an undirected graph of n nodes and three types of edges:
        - Type 1: Can be traversed by Alice only.
        - Type 2: Can be traversed by Bob only.
        - Type 3: Can be traversed by both Alice and Bob.
    - Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.
    - Return the maximum number of edges you can remove, or return -1 if Alice and Bob cannot fully traverse the graph.

// Example:

    Example 1:
        Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
        Output: 2
        Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.

    Example 2:
        Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
        Output: 0
        Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.

    Example 3:
        Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
        Output: -1
        Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.


// Constraints:

    1 <= n <= 1e5
    1 <= edges.length <= min(1e5, 3 * n * (n - 1) / 2)
    edges[i].length == 3
    1 <= type[i] <= 3
    1 <= u[i] < v[i] <= n
    All tuples (type[i], u[i], v[i]) are distinct.

// Observation:
    - Given Undirected graph, with three type of edges:
        - Type 1: only alice can traverse
        - Type 2: only bob can traverse
        - Type 3: Alice and bob both can traverse.
    - We have to return the minimum number of edges so that alice and bob both can traverse, or return -1, if they were not able to travel on the nodes.

    // DSU Approach:
        - Type 3 edges can be traversed by both alice and bob, so first process that edge.
            - Build 2 graph, one for alice, & one for bob,
            - It can be possible that there may be duplicate of type3 edges.
            
        - Once we have Two graph with Fully type_3 Traversable:
            - Now we will start connecting the alice & count the extra edges.
            - Similarly, we will count for bob.

        - Lastly, we have go check each node for alice & bob is traversable or not?
            - If any alice or bob is not able to traverse on all the node, then return -1
            - else return number of removable edges.

        // Complexity:
            - TC: O(V + E)
            - SC: O(V)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class DSU {
private:
    vector<int> size, parent;
public:
    DSU (int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]); // path compression.
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;  // already connected.
        
        // Connect smaller group to larger one.
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        // Step 1: First get the graph with type3 only:
        int extra = 0;
        DSU ds1(n + 2);
        for(auto &it: edges) {  // TC: O(E)
            int type = it[0], u = it[1], v = it[2];
            if(type == 3) {
                // counting extra edge in type3 also important.
                if(ds1.ultPar(u) == ds1.ultPar(v)) {  
                    extra++;
                } else {
                    ds1.Union(u, v);
                }
            }
        }

        DSU ds2 = ds1;  // construct identical type3 for bob.
        
        // ALICE: Get the connection with alice_type1 & type3
        for(auto &it: edges) {  // TC: O(E)
            int type = it[0], u = it[1], v = it[2];
            if(type == 1) {
                if(ds1.ultPar(u) == ds1.ultPar(v)) {
                    extra++;
                } else {
                    ds1.Union(u, v);
                }
            }
        }

        // BOB: Get the connection with bob_type2 & type3
        for(auto &it: edges) {  // TC: O(E)
            int type = it[0], u = it[1], v = it[2];
            if(type == 2) {  // bob:
                if(ds2.ultPar(u) == ds2.ultPar(v)) {
                    extra++;
                } else {
                    ds2.Union(u, v);
                }
            }
        }

        // Last check if, all nodes (1 to n) are rechable to alice and simillalry with bob:
        for(int i = 1; i <= n; i++) {   // O(V)
            if(ds1.ultPar(i) != ds1.ultPar(1)) return -1;
            if(ds2.ultPar(i) != ds2.ultPar(1)) return -1;
        }

        return extra;   // Extra edge from alice & bob
    }
};