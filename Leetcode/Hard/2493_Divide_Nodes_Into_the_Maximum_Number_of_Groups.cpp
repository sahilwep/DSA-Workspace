/*

//  2493. Divide Nodes Into the Maximum Number of Groups

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
    -> We can't merge adjacent nodes into one group.
    -> We can merge nodes that are not directly adjacent.
    -> The problem involves properties of bipartite graphs.
    -> First, we need to check whether the given graph is bipartite.
    -> If it is not bipartite, then forming such group configurations is impossible.
    -> Otherwise, we proceed to find the maximum possible groupings.



// Approach:
    1. Check for Bipartite:
       - Use BFS to check if the graph is bipartite.
       - If it is not bipartite, return `-1` as a valid configuration is not possible.
    
    2. Find Maximum Groups in Each Component:
       - Since the graph may have multiple components, we analyze each separately.
       - We need to determine the maximum number of groups possible within each component.
    
    3. Level-Order Traversal to Find Max Groups:
       - Use BFS to determine the max depth/level from different starting nodes.
       - Since the starting node affects the depth, we run BFS from every node in each component to get the best possible depth.
    
    4. Combine Results from All Components:
       - Sum up the best group sizes from all components to get the final result.
    

// Complexity:
    -> TC: O(V * (V + E))
    -> SC: O(V + E)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    // Function to check whether the graph is bipartite using BFS
    bool isBipartite(int node, vector<vector<int>> &adj, vector<int> &colors) { // TC: O(V + 2E)
        queue<int> q;
        q.push(node);
        colors[node] = 0;  // Start coloring with '0'

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto &neighbor : adj[curr]) {  // Explore adjacent nodes
                if (colors[neighbor] == -1) {  // If not yet colored
                    colors[neighbor] = !colors[curr]; // Assign opposite color
                    q.push(neighbor);
                } else if (colors[neighbor] == colors[curr]) {  // If colors match, it's not bipartite
                    return false;
                }   
            }
        }
        return true;    
    }

    // Function to determine the number of levels in BFS traversal from a given node
    int bfs_(int startNode, vector<vector<int>> &adj, int n) {  
        vector<int> visited(n+1, 0);
        queue<int> q;
        q.push(startNode);
        visited[startNode] = 1;
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front();
                q.pop();
                for (auto &neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = 1;
                        q.push(neighbor);
                    }
                }
            }
            level++;  // Increase level after processing all nodes at current depth
        }
        return level;
    }

    // Alternative BFS function to track levels using queue
    int bfs(int startNode, vector<vector<int>> &adj, int n) {    
        vector<int> visited(n+1, 0);
        queue<pair<int, int>> q;  // Stores (node, level)
        q.push({startNode, 1});  // Start BFS at level 1
        visited[startNode] = 1;
        int lastLevel = 1;

        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();
            lastLevel = level;  // Track last known level

            for (auto &neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push({neighbor, level + 1});
                }
            }
        }
        return lastLevel;
    }

    // Function to get the maximum level from all nodes in a connected component, it's just another dfs to get the maximum group by exploring all the nodes in every single components..
    int getMaxFromEachComp(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &level) {
        int maxGroup = level[node];  // Start with the current node's max level
        vis[node] = 1;  // Mark node as visited

        for (auto &neighbor : adj[node]) {  // Explore all adjacent nodes
            if (!vis[neighbor]) {
                maxGroup = max(getMaxFromEachComp(neighbor, adj, vis, level), maxGroup);
            }
        }
        return maxGroup;
    }

public:
    int magnificentSets(int n, vector<vector<int>>& edges) { // TC: O( V * (V + 2E))
        // Build adjacency list (1-based index), TC: O(E)
        vector<vector<int>> adj(n+1);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 1: Check if graph is bipartite, TC: O(V + 2E)
        vector<int> colors(n+1, -1);
        for (int i = 1; i <= n; i++) {
            if (colors[i] == -1) {
                if (!isBipartite(i, adj, colors)) {
                    return -1;  // If not bipartite, return -1
                }
            }
        }

        // Step 2: Find max level for each node, TC: O(V * (V + 2E))
        vector<int> level(n+1, 0);
        for (int i = 1; i <= n; i++) {
            level[i] = bfs(i, adj, n);  // Compute max BFS level for each node
        }

        // Step 3: Find the maximum groups in each component, TC: O(V + 2E), each node visited only once.
        int maxGroups = 0;
        vector<int> vis(n+1, 0);
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                maxGroups += getMaxFromEachComp(i, adj, vis, level);
            }
        }

        return maxGroups;  // Return the sum of max groups from all components
    }
};
