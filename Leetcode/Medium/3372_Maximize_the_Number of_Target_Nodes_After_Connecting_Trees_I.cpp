/*

//  3372. Maximize the Number of Target Nodes After Connecting Trees I


//  Problem Statement: 
    -> There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] and [0, m - 1], respectively.
    -> You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree. You are also given an integer k.
    -> Node u is target to node v if the number of edges on the path from u to v is less than or equal to k. Note that a node is always target to itself.
    -> Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the first tree if you have to connect one node from the first tree to another node in the second tree.
    -> Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.


// Example: 

    Example 1:
        Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2
        Output: [9,7,9,8,8]
        Explanation:
            For i = 0, connect node 0 from the first tree to node 0 from the second tree.
            For i = 1, connect node 1 from the first tree to node 0 from the second tree.
            For i = 2, connect node 2 from the first tree to node 4 from the second tree.
            For i = 3, connect node 3 from the first tree to node 4 from the second tree.
            For i = 4, connect node 4 from the first tree to node 4 from the second tree.

    Example 2:
        Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]], k = 1
        Output: [6,3,3,3,3]
        Explanation: For every i, connect node i of the first tree with any node of the second tree.



// Observations: 
    -> Question is very jumbled, let's simplify:
        -> You are given two trees (which are just connected graphs with no cycles).
            -> The first tree has n nodes and is described by edges1.
            -> The second tree has m nodes and is described by edges2.
            -> You are also given an integer k.

        -> Now, for each node in the first tree, you can temporarily connect it to one node in the second tree (only one extra edge is added). Then you ask:
        -> How many nodes in this combined graph (both trees + this one extra edge) are reachable from that node within k or fewer steps?
        -> In other words, you try all possible nodes in the second tree to connect with that node from the first tree, and you choose the one that gives you the maximum number of reachable nodes within k steps.
        -> You must repeat this for every node in the first tree, one at a time, and reset after each one.

        -> Example Summary (first one):
            -> You try connecting node 0 from the first tree to every node in the second tree.
            -> You see how many nodes become “target nodes” (within k=2 distance).
            -> You choose the best connection that gives the highest number of targets.
            -> Store this number in the answer for node 0.
            -> Then do the same for node 1, and so on… 



// Solution: 
    -> We are given a parameter k, which represents the maximum allowed distance to count neighboring nodes in a tree. 
    -> The problem involves two trees, and we are supposed to use k as a constraint to count how many nodes can be reached from each node in Tree 1, and how many nodes can be reached from any node in Tree 2.
    
    ->  Step 1: Focus on Tree 1 (High Priority)
        -> Tree 1 is the main focus.
        -> For every node in Tree 1, we count how many nodes (including itself) are reachable within a distance of k.
        -> This is done using DFS/BFS, which explores nodes up to distance k.
        -> These values are stored in a list so we can use them later to build our final result.

    ->  Step 2: Process Tree 2 (Global Best Option)
        -> Tree 2 is not restricted to a specific starting node. That means we are allowed to connect Tree 1 to any node in Tree 2 to get the best result.
        -> So, we try starting from each node in Tree 2 and compute how many nodes (including itself) are reachable within distance k - 1.
            -> The reason we use k - 1 here is because connecting Tree 1 to Tree 2 costs 1 edge, so we effectively lose 1 move.
        -> For each starting node in Tree 2, we do a DFS/BFS to count reachable nodes within the range.
        -> We keep track of the maximum number of reachable nodes found from any node in Tree 2.

    ->  Step 3: Combine Results
        -> Now for every node in Tree 1, we simply add:
            -> The number of reachable nodes within k in Tree 1, and
            -> The maximum number of reachable nodes within k-1 in Tree 2 (the best Tree 2 choice).
        -> The sum becomes the final answer for that node, assuming we connect Tree 1's node to the best possible node in Tree 2.

    -> This solution gives us the maximum total reachable nodes we can achieve by Starting at a node in Tree 1, Connecting it to the best node in Tree 2, And exploring both trees within the allowed distance k (adjusted to k-1 for Tree 2 due to the connecting edge).


// Complexity: 
    -> TC: O(n^2 + m^2)
    -> SC: O(n^2 + m^2)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    // DFS to count the number of node within k-constrains...
    int dfs(int node, vector<vector<int>>& adj, vector<int>& vis, int k) { // TC: O(V)
        vis[node] = 1;
        int adjNodesCnt = 1;

        for(auto &it: adj[node]) {
            if(!vis[it] && k > 0) { // adj-neighbors should not be visited & should be grater than 'k'
                adjNodesCnt += dfs(it, adj, vis, k-1);
            }
        }

        return adjNodesCnt;
    }
    // BFS Implementation to count the number of node within k-constrains...
    int bfs(int node, vector<vector<int>>& adj, vector<int>& vis, int k) {  // TC: O(V)
        queue<pair<int, int>> q;

        vis[node] = 1;
        q.push({k, node});

        int totalNode = 0;
        while(!q.empty()) {
            auto [cnt, node] = q.front();
            q.pop();

            totalNode++;

            for(auto &it: adj[node]) {
                if(!vis[it] && cnt > 0) {
                    vis[it] = 1;
                    q.push({cnt - 1, it});
                }
            }
        }

        return totalNode;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {

        // Edge case: if k == 0
        if(k == 0){
            vector<int> ans(edges1.size() + 1, 1);
            return ans;
        }
        
        // Build Graph adjacency list for Tree 1:   // TC: O(n)
        int n = edges1.size() + 1;
        vector<vector<int>> adj1(n);
        for(auto &it: edges1) {
            int u = it[0], v = it[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }


        // Build Graph adjacency list for Tree 2:   // TC: O(m)
        int m = edges2.size() + 1;
        vector<vector<int>> adj2(m);
        for(auto &it: edges2) {
            int u = it[0], v = it[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        // Get the adjacent Maximum node count from Tree 2 within range "k - 1", by checking all the nodes from Tree 2:
        int maxAdjTree2 = 0;
        for(int i = 0; i < m; i++) {    // TC: O(m * m)
            vector<int> vis(m, 0);
            maxAdjTree2 = max(maxAdjTree2, dfs(i, adj2, vis, k-1));
        }

        // Build "adjacent neighbors count within k" list for every node of Tree 1: 
        vector<int> adjTree1(n);
        for(int i = 0; i < n; i++) {    // TC: O(n * n)
            vector<int> vis(n, 0);
            adjTree1[i] = dfs(i, adj1, vis, k);
            // adjTree1[i] = bfs(i, adj1, vis, k);
        }

        // Build Answer:
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = adjTree1[i] + maxAdjTree2;
        }

        return ans;
    }
};