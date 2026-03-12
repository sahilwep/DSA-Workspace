/*

//  3600. Maximize Spanning Tree Stability with Upgrades


//  Problem Statement: 
    - You are given an integer n, representing n nodes numbered from 0 to n - 1 and a list of edges, where edges[i] = [ui, vi, si, musti]:
        - ui and vi indicates an undirected edge between nodes ui and vi.
        - si is the strength of the edge.
        - musti is an integer (0 or 1). If musti == 1, the edge must be included in the spanning tree. These edges cannot be upgraded.
    - You are also given an integer k, the maximum number of upgrades you can perform. Each upgrade doubles the strength of an edge, and each eligible edge (with musti == 0) can be upgraded at most once.
    - The stability of a spanning tree is defined as the minimum strength score among all edges included in it.
    - Return the maximum possible stability of any valid spanning tree. If it is impossible to connect all nodes, return -1.
    - Note: A spanning tree of a graph with n nodes is a subset of the edges that connects all nodes together (i.e. the graph is connected) without forming any cycles, and uses exactly n - 1 edges.

    
// Example:
    Example 1:
        Input: n = 3, edges = [[0,1,2,1],[1,2,3,0]], k = 1
        Output: 2
        Explanation:
            Edge [0,1] with strength = 2 must be included in the spanning tree.
            Edge [1,2] is optional and can be upgraded from 3 to 6 using one upgrade.
            The resulting spanning tree includes these two edges with strengths 2 and 6.
            The minimum strength in the spanning tree is 2, which is the maximum possible stability.

    Example 2:
        Input: n = 3, edges = [[0,1,4,0],[1,2,3,0],[0,2,1,0]], k = 2
        Output: 6
        Explanation:
            Since all edges are optional and up to k = 2 upgrades are allowed.
            Upgrade edges [0,1] from 4 to 8 and [1,2] from 3 to 6.
            The resulting spanning tree includes these two edges with strengths 8 and 6.
            The minimum strength in the tree is 6, which is the maximum possible stability.

    Example 3:
        Input: n = 3, edges = [[0,1,1,1],[1,2,1,1],[2,0,1,1]], k = 0
        Output: -1
        Explanation: All edges are mandatory and form a cycle, which violates the spanning tree property of acyclicity. Thus, the answer is -1.

        


// Observations:
    - we are given list of edges{u, v, wt, includeFactor}
    - includeFactor:
        1 : must be included in mst, and these edges can't be upgraded
        0 : can be included, and can be upgraded.
    - Given 'k', maximum number of upgrades we can perform, and we can perform only once to every eligible edge.
    - Stability of spanning tree determined by minimum strength score among all the edges included in it.
    - We have to return the maximum possible stability of any valid given spanning tree.
    - If it's impossible to connect all the nodes, return '-1'

    // key Points:
        - When it's MST, we have Prims and kruskal's(dsu) 
        - We will use DSU to connect the components:
        - edges with factor = '1' must be included, we can't skip that
            - while connecting '1's if any two nodes that is already connected return '-1' conditions of cycle.
        - edges with factor = '0' we have options:
            - Either we can reject
            - Or we can include, but make sure that it should have as max as edges weight so that we can have maximum stability at last.
        - With Upgrading:
            - While upgrading edges with factor = '0'
            - once we have list of edges that contributed to MST, we will updated the 'k' lowest value edges weight.

    // Approach:
        - First get all the upgradable edges "factor = 0"
            - Sort them in decreasing fashion.
                - this will make sure connect we will connect max_values nodes.
        
        - Now Connect the necessary nodes, factor = 1
            - During connection if any nodes that has redundant connection return '-1', as forming cycle.
            - Make sure to store the minimum_weight from this groups of connections.
        
        - After that Connect the Upgradable nodes:
            - skip redundant connected nodes.
            - Store all the weight of connected nodes.

        - Check if every nodes from "0 to n-1" are connected together
            - If not, return '-1', making multiple graph components.
        
        - Now we have list of upgradable nodes:
            - double the 'k' min-weights.

        - At last, we will get teh minimum among the NecessaryMinimum & UpgradableNodes.

        - return minNode.


        // Complexity:
            - TC: O(m * logm)   -> with sorting
            - SC: O(n + m) 
                - n = total number of nodes
                - m = total number of edges


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;



class DSU {
private:
    vector<int> size, parent;
public:
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]); // path  compression.
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;  // already connected

        // Connect lower group to higher group.
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
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        
        // Create a info of edges that are upgradable:
        vector<pair<int, int>> info;
        for(int i = 0; i < edges.size(); i++) {
            int factor = edges[i][3];
            int wt = edges[i][2];
            if(factor == 0) {   // upgradable edges
                info.push_back({wt, i});    // weight, index
            }
        }

        sort(rbegin(info), rend(info));   // sort in decreasing way


        // First connect all the factor = '1' nodes:
        DSU ds(n);
        int minWtFromMustEdges = INT_MAX;
        for(auto i: edges) {
            int u = i[0], v = i[1], wt = i[2], factor = i[3];
            if(factor == 1) {
                if(ds.ultPar(u) == ds.ultPar(v)) return -1; // already connected forming cycle

                // connect edges & store minWtFromMustEdges
                minWtFromMustEdges = min(wt, minWtFromMustEdges);
                ds.Union(u, v);
                continue;
            }
        }

        // Now connect upgradable edges & store min:
        vector<int> upgradableEdges;
        for(auto [wt, i]: info) {
            int u = edges[i][0], v = edges[i][1], factor = edges[i][3];

            if(factor == 1) continue;   // skip not upgradable edges

            // Normal edges factor = '0':            
            if(ds.ultPar(u) == ds.ultPar(v)) continue;  // skip already connected edges

            ds.Union(u, v);
            upgradableEdges.push_back(wt);
        }

        // Check if we have every node connected each other or not?
        for(int i = 0; i < n; i++) {
            if(ds.ultPar(0) != ds.ultPar(i)) return -1;     // not connected nodes
        }

        // Now update k wt from edge factor '0'
        int i = upgradableEdges.size() - 1;
        while(k-- && i >= 0) {
            upgradableEdges[i] *= 2;
            i--;
        }

        // Now get the min among updated and not Updated
        int minWt = minWtFromMustEdges;
        for(auto &it: upgradableEdges) {
            minWt = min(minWt, it);
        }

        return minWt;
    }
};