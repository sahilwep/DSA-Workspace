/*

//  2497. Maximum Star Sum of a Graph


//  Problem Statement: 
    -> There is an undirected graph consisting of n nodes numbered from 0 to n - 1. You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node.
    -> You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
    -> A star graph is a subgraph of the given graph having a center node containing 0 or more neighbors. In other words, it is a subset of edges of the given graph such that there exists a common node for all edges.
    -> The image below shows star graphs with 3 and 4 neighbors respectively, centered at the blue node.
    -> The star sum is the sum of the values of all the nodes present in the star graph.
    -> Given an integer k, return the maximum star sum of a star graph containing at most k edges.

 
// Example: 
    Example 1:
        Input: vals = [1,2,3,4,10,-10,-20], edges = [[0,1],[1,2],[1,3],[3,4],[3,5],[3,6]], k = 2
        Output: 16
        Explanation: The above diagram represents the input graph.
        The star graph with the maximum star sum is denoted by blue. It is centered at 3 and includes its neighbors 1 and 4.
        It can be shown it is not possible to get a star graph with a sum greater than 16.

    Example 2:
        Input: vals = [-5], edges = [], k = 0
        Output: -5
        Explanation: There is only one possible star graph, which is node 0 itself.
        Hence, we return -5.


// Observations: 
    -> We are given 'k' which says at max we can include only 'k' neighbors for every node
    -> Also we need to be greedy while includeing neighbors..
    // Solution: 
        -> build Graph adj list => Structure: {u1 : (value[v1], v1), (value[v2], v2),...(value[vn], vn)}
        -> Sort in decreasing order.
        -> Only include positive neighbors.


// Complexity: 
    -> TC: O(m + Summations_(d_i * log(d_i) + n * k))
        -> Build adjacency list -O(m) 
        -> Main loop over all nodes: O(n + Summations(d_i * log d_i) + n * k)
        -> In worst case (complete graph) = O(m + n^2 * log(n))
    -> SC: 
        -> O(n + m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        
        // Build adj list: structure => {u1 : (value[v1], v1), (value[v2], v2),...(value[vn], vn)}
        int n = vals.size();

        vector<vector<pair<int, int>>> adj(n);
        for(auto &it: edges) {
            adj[it[0]].push_back({vals[it[1]], it[1]});
            adj[it[1]].push_back({vals[it[0]], it[0]});
        }


        // Calculate maximum Sum:
        int maxSum = INT_MIN;
        for(int i = 0; i < n; i++) {    // for all node[i]

            int tempSum = vals[i];  // include middle start node value
            sort(rbegin(adj[i]), rend(adj[i]));   // sort in decreasing order, as we need to include maximum values.

            // Check adjacent node of 'i':
            for(int j = 0; (j < k) && (j < adj[i].size()); j++) {
                auto it = adj[i][j];
                if(it.first > 0) {  // only add positive neighbors
                    tempSum += it.first;
                }
            }

            maxSum = max(maxSum, tempSum);  // get maximum sum among all the possible nodes checks
        }
        
        return maxSum;
    }
};