/*

//  2368. Reachable Nodes With Restrictions


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

// Observation: 
    -> From the given edges, & given restricted node, we need to count the total number of nodes that are reachable from node '0'

    // Approach:
        -> With using any traversal algorithm like BFS/DFS we can count the total number of nodes that are reachable from source '0', which were not lies in restricted zone.
        

// Complexity: 
    -> TC: O(V + 2E)
    -> SC: O(V)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BFS Approach: 
class Solution {
private: 
    unordered_set<int> st;
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        for(auto &it: restricted) st.insert(it);

        // Build Adj list: 
        vector<vector<int>> adj(n);

        for(auto &it: edges) {  // unidrected graph
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // LOT Approach: 
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        int ans = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto &it: adj[node]) {
                if(!vis[it] && st.find(it) == st.end()) {  // not yet visited & also it should not be the part of restricted..
                    vis[it] = 1;
                    ans++;  // count the answer
                    q.push(it);
                }
            }
        }

        return ans;
    }
};


// DFS Approach: 
class Solution {
private:
    unordered_set<int> st;
    int solve(int node, vector<vector<int>> &adj, vector<int> &vis, unordered_set<int> &st) {
        // Check for restricted nodes:
        if(st.find(node) != st.end()) return 0; // if node is restricted return count as '0'
        
        vis[node] = 1;
        int totalNode = 1;
        
        for(auto &it: adj[node]) {
            if(!vis[it]) {
                totalNode += solve(it, adj, vis, st);   // sum up all the nodes that were lies in path from '0'
            }
        }

        return totalNode;
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& rest) {
        
        unordered_set<int> st(begin(rest), end(rest));  // using unordered_set to lookup restricted nodes in O(1) time

        // Build Adj list:
        vector<vector<int>> adj(n);
        
        for(auto &it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);

        return solve(0, adj, vis, st);  // single call from '0' will return the total number of safe nodes..
    }
};