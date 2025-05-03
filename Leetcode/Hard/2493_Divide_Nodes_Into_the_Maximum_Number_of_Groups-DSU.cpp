/*

//  2493. Divide Nodes Into the Maximum Number of Groups-DSU:


//  Problem Statement: 
    -> You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.
    -> You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.
    -> Divide the nodes of the graph into m groups (1-indexed) such that:
        -> Each node in the graph belongs to exactly one group.
        -> For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
    -> Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.

 
// Example:
    Example 1:
        Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
        Output: 4
        Explanation: As shown in the image we:
            - Add node 5 to the first group.
            - Add node 1 to the second group.
            - Add nodes 2 and 4 to the third group.
            - Add nodes 3 and 6 to the fourth group.
            We can see that every edge is satisfied.
            It can be shown that that if we create a fifth group and move any node from the third or fourth group to it, at least on of the edges will not be satisfied.

    Example 2:

        Input: n = 3, edges = [[1,2],[2,3],[3,1]]
        Output: -1
        Explanation: If we add node 1 to the first group, node 2 to the second group, and node 3 to the third group to satisfy the first two edges, we can see that the third edge will not be satisfied.
            It can be shown that no grouping is possible.


// Observations: 
    -> Given edges & n nodes
    -> First we need to find the bipartite conditions
    -> second we need to get the maximum level we can get from every nodes..
    -> NOTE: graph is distributed in multiple components.

    // DSU Approach: 
        -> Bipartite Check => DSU
        -> Get level for every nodes => BFS
        -> From every components get the maximum level & sums up..


    // Complexity: 
        ->  O(n² + E * α(n))
            O(E * α(n))  → DSU for bipartite check
            + O(E)       → Build adjacency list
            + O(n²)      → BFS from each node
            + O(V + E)   → Final DFS traversal
            
        -> SC: O(n + E)
            -> 

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class DSU {
private: 
    vector<int> parent, size;
public: 
    DSU (int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]);
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;
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
private: 
    int bfs(int node, vector<vector<int>>& adj, int n) {

        queue<pair<int, int>> q;
        vector<int> vis(n + 1, 0);

        vis[node] = 1;
        q.push({1, node});

        int maxLvl = 1;
        while(!q.empty()) {
            auto [lvl, node] = q.front();
            q.pop();

            maxLvl = max(maxLvl, lvl);

            for(auto &it: adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push({lvl + 1, it});
                }
            }
        }

        return maxLvl;
    }
    int getMaxLvl(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& level) {   // dfs to get maximum level from every components:
        
        int maxInGrp = level[node];  // get node from maximum
        vis[node] = 1;

        for(auto &it: adj[node]) {
            if(!vis[it]) {
                maxInGrp = max(maxInGrp, getMaxLvl(it, adj, vis, level));
            }
        }

        return maxInGrp;
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        
        // Step 1: Check Bi-partite:
        DSU ds(n + 1 + 501);    // create DSU with buffer point
        for(auto &it: edges) {
            int u = it[0], v = it[1];

            if(ds.ultPar(u) == ds.ultPar(v)) {
                return -1;  // bi-partite fails here.
            }

            // Bi-partite creations: 501 is the buffer point, constrains (1 >= n >= 500)
            ds.Union(u, v + 501);   // G1
            ds.Union(u + 501, v);   // G2
        }

        // Step 2: Check maximum level we can distribute: 
        // Build adj list: 
        vector<vector<int>> adj(n + 1);
        for(auto &it: edges) {  // undirected graph:
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);    
        }

        
        // Find the level for every node:
        vector<int> level(n + 1); 
        for(int i = 1; i <= n; i++) {
            level[i] = bfs(i, adj, n);  // get the maximum from every possible node for every node
        }

        // From every components, find the maximum level:
        vector<int> vis(n + 1, 0);
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                ans += getMaxLvl(i, adj, vis, level);
            }
        }

        return ans;
    }
};