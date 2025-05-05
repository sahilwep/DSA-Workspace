/*

//  DFS of graph:

//  Problem Link: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    vector<int> ans;
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        ans.push_back(node);
        
        for(auto &it:adj[node]) if(!vis[it]) dfs(it, adj, vis);
    }
public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        
        vector<int> vis(n, 0);
        dfs(0, adj, vis);
        return ans;
    }
};