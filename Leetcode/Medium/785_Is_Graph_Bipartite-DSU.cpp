/*

//  785. Is Graph Bipartite? DSU


//  Problem Statement: 
    -> There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:
        -> There are no self-edges (graph[u] does not contain u).
        -> There are no parallel edges (graph[u] does not contain duplicate values).
        -> If v is in graph[u], then u is in graph[v] (the graph is undirected).
        -> The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
    -> A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
    -> Return true if and only if it is bipartite.

// Example: 

    Example 1:

        Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
        Output: false
        Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.

    Example 2:

        Input: graph = [[1,3],[0,2],[1,3],[0,2]]
        Output: true
        Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.


// Observation: 
    -> We are given a 'n' size graph adj list[] which forms undirected graph of total number of vertices = 'n'
    -> We need to find whether the given graph is bipartite or not?

    // Bipartite Graph: 
        -> No Two adjacent nodes having same group/colors.

    // BruteForce BFS/DFS Approach: 
        -> Using any traversal algorithm we can find the adjacent node that are having same colors.
        -> TC: O(V + 2E) => For undirected graph:

    // DSU Approach:
        // Why DSU ?
            -> DSU will helps us to know the relations b/w to connected nodes.
            -> With Few modifications we can Distribute adjacent nodes into two different groups.
                // Group Range: 
                    -> Group Range 1: (0 - (n-1))
                    -> Group Range 2: (n - (2 * (n - 1)))

                -> In Simple we are creating a buffer zone that acts as we have two groups.

        -> Before processing graph nodes with DSU, first we need to convert given adj list into edges list.
        -> this edges list should not contains any duplicate, means {(2,1) & (1, 2)}, we will store every edge only once.
        -> Afterwards, we can process every edge & check their ultimate parent & accordingly merge using DSU.
        -> IF any two node have same ultimate parent, means they are directly already in same group & we are trying to process it again, means There is a violations of bipartite -> return false
        -> else if all the node are processed without violating the Bipartite rules -> return true.
        -> TC: O(N)

        // Visualization: 
            Example: [[1,2,3],[0,2],[0,1,3],[0,2]], Vertices/size = 4

                -> Convert this adj list into edges list:

                        [[0, 1], [0, 2], [0, 3], [2, 3], [2, 1]]

                -> As size is '4', create a buffer zone of '4'
                -> And split every edges into two groups:

                        [0, 1]:
                                    u = 0, v = 1

                                    checks: (ulp_u = 0  !=  ulp_v = 1)

                                    Split it into two groups: "(u, v + n) & (v, u + n)" => This will split '0' & '1' into tow diffent group, & with using buffer space with 'n' we can generate any random unique pair that connects with these two..

                                    Two Groups:

                                        (0, 5)
                                        (1, 4) 

                                    -> Take union:

                                    [0]             [1]
                                    /               /
                                 [5]              [4]

                        [0, 2]:     
                                    -> Same steps that we are doing above:
                                            u = 0, v = 2
                                            (ulp_u = 0 != ulp_v = 2) 
                                            Groups:
                                                (0, 6)
                                                (2, 4)

                                    [0]              [1]
                                    / \              / \
                                 [5]  [6]          [4]  [2]
                        
                        [0, 3]: 
                                            u = 0, v = 3
                                            (ulp_u = 0 != ulp_v = 3) 
                                            Groups:
                                                (0, 7)
                                                (3, 4)

                                    [0]                [1]
                                     |                  |
                                ----------         ----------
                                |    |   |         |    |   |
                               [5]  [6] [7]       [4]  [2]  [3]
                        
                        
                        [2, 3]: 

                                            u = 2, v = 3
                                            (ulp_u = 1  ==  ulp_v = 1)  => Same ultimate parent, 
                                            -> If we look the graph above (2, & 3) lies in same group
                                            -> And from this given edge (2,3) means that there is an edge that connect (2, 3), and they already grouped in same group. How it can be possible to group two adjacent nodes that lies in same group, So the condition of bipartite is Violated (no two adjacent group lies in same group)

                                -> Return False

                // NOTE: If all the edges processed safely then only we can say the graph is bi-partite.


// Complexity:
    -> TC: O(V + E)
    -> SC: O(2*V) = O(V)

    
// Extra:
    -> DFS/BFS Solutions also gives O(V + 2E) complexity which is nearly same, but Using DSU it can be helpful when we have dynamic graph, where components of graph is changing frequently..

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = ultPar(parent[node]);
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
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        // Convert given graph adj list into edges stored uniquely (No-duplicate edge in list):
        set<pair<int, int>> edges;
        for(int i = 0; i < V; i++) {    // TC: O(V)
            for(int j = 0; j < graph[i].size(); j++) {
                int u = i;
                int v = graph[i][j];
                edges.insert({min(u, v), max(u, v)});   // this will make sure the (smallestNode, largestNode) inserted into set, & if it's already exist, then skipped
            }
        }

        // Now Process With DSU: 
        DSU ds(2 * V); // Create two groups with size (V, V)


        for(auto &it: edges) { // Iterate in Edges TC: O(E)
            int u = it.first, v = it.second;

            // Find ultimate parent of u & v:
            int ulp_u = ds.ultPar(u);
            int ulp_v = ds.ultPar(v);

            // Check if they belong to same group already, if then return false else merge them..
            if(ulp_u == ulp_v)  return false;

            // Create Group Pairs & marge them:
            ds.Union(u, v + V);     // u in Group 1
            ds.Union(v, u + V);     // v in Group 2
        }

        return true;    // If all the edge processed Without Violating bipartite conditions, return true.
    }
};