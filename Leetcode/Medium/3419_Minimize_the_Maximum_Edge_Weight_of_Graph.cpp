/*

//  3419. Minimize the Maximum Edge Weight of Graph


//  Problem Statement: 
    -> You are given two integers, n and threshold, as well as a directed weighted graph of n nodes numbered from 0 to n - 1. 
    -> The graph is represented by a 2D integer array edges, where edges[i] = [Ai, Bi, Wi] indicates that there is an edge going from node Ai to node Bi with weight Wi.
    -> You have to remove some edges from this graph (possibly none), so that it satisfies the following conditions:
        -> Node 0 must be reachable from all other nodes.
        -> The maximum edge weight in the resulting graph is minimized.
        -> Each node has at most threshold outgoing edges.
    -> Return the minimum possible value of the maximum edge weight after removing the necessary edges. If it is impossible for all conditions to be satisfied, return -1.

    
    
// Example: 
    Example 1:
        Input: n = 5, edges = [[1,0,1],[2,0,2],[3,0,1],[4,3,1],[2,1,1]], threshold = 2
        Output: 1
        Explanation: Remove the edge 2 -> 0. The maximum weight among the remaining edges is 1.

    Example 2:
        Input: n = 5, edges = [[0,1,1],[0,2,2],[0,3,1],[0,4,1],[1,2,1],[1,4,1]], threshold = 1
        Output: -1
        Explanation: It is impossible to reach node 0 from node 2.

    Example 3:
        Input: n = 5, edges = [[1,2,1],[1,3,3],[1,4,5],[2,3,2],[3,4,2],[4,0,1]], threshold = 1
        Output: 2
        Explanation: Remove the edges 1 -> 3 and 1 -> 4. The maximum weight among the remaining edges is 2.

    Example 4:
        Input: n = 5, edges = [[1,2,1],[1,3,3],[1,4,5],[2,3,2],[4,0,1]], threshold = 1
        Output: -1



// Observations: 

    -> We are given a directed graph with weighted edges. The goal is to remove some edges such that:
        -> Each node has at most 'threshold' outgoing edges.
        -> Every node can still reach node '0' (i.e., node 0 must be reachable from all other nodes).
        -> Among the remaining edges, the maximum edge weight used in this setup should be minimized.

        // Key Observations:
            1. Node '0' should be reachable from all nodes. So, we invert the edges and ensure a path from every node to 0.
            2. The edge removals must ensure:
                - The reachability condition.
                - No node has more than 'threshold' outgoing edges.
            3. We are minimizing the **maximum edge weight** used in the final valid configuration.
            4. Prim's-like approach is attempted here with a greedy selection of lowest weight edges while satisfying out-degree constraints.

    // MST Prim's Approach:
        -> We construct an inverted graph, since the problem wants all nodes to "reach" node 0.
        -> We use a "Prim's-algorithm-like greedy approach" to select low-weight edges that help cover all nodes while obeying the degree constraint.
        -> We use a priority queue (min-heap) to always pick the lowest-weight available edge.
        -> We track how many edges are selected from each node (via `deg`) to ensure we never exceed the threshold.
        -> The variable `ans` keeps track of the **maximum weight** among the chosen edges — we want to minimize this.


// Complexity:
    -> TC: O(m * log m)
        -> Total pushes into the heap: O(m)
        -> Each heap operation: O(log m))
    -> SC: O(n + m)
        -> N = total nodes

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// MST Approach:
class Solution {
private: 
    typedef pair<int, int> pr;
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        
        // Build inverted adj list: 
        vector<vector<pair<int, int>>> adj(n);
        for(auto &it: edges) {
            adj[it[1]].push_back({it[0], it[2]});   // Revert directed edge
        }

        // Prim's-like implementation.
        vector<int> vis(n, 0);
        vector<int> deg(n, 0);

        priority_queue<pr, vector<pr>, greater<>> pq;
        pq.push({0, 0});    // structure: <cost, src>

        int ans = 0;

        while(!pq.empty()) {
            auto [edgeWt, node] = pq.top();
            pq.pop();

            if(vis[node]) continue;

            if(deg[node] < threshold) {
                deg[node]++;
                ans = max(ans, edgeWt);
                vis[node] = 1;
            }
            else continue;

            // Explore adjacent nodes: 
            for(auto [v, wt]: adj[node]) {
                if(!vis[v]) {
                    pq.push({wt, v});
                }
            }
        }

        // Unreachable node check: 
        for(auto &it: vis) if(it == 0) return -1;    // not reachable

        return ans;        
    }
};
