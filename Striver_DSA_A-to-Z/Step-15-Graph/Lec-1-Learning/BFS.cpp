/*

//  BFS of graph

// Problem Link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/0

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        
        vector<int> ans;
        queue<int> q;
        vector<int> vis(n, 0);
        
        q.push(0);
        vis[0] = 1;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto &it: adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return ans;
    }
};