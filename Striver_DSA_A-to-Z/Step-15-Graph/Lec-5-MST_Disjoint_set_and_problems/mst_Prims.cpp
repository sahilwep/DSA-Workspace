/*

//  MST Prims


//  Problem Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    typedef pair<int, int> pr;
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        
        // Prim's Algorithm:
        int mstWt = 0;
        priority_queue<pr, vector<pr>, greater<>> pq;
        
        vector<int> vis(V, 0);
        pq.push({0, 0});
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int cost = it.first;
            int node = it.second;
            
            if(vis[node]) continue;
            
            vis[node] = 1;
            mstWt += cost;
            
            // Explore adj nodes: 
            for(auto &it: adj[node]) {
                int v = it[0], wt = it[1];
                if(!vis[v]) {
                    pq.push({wt, v});
                }
            }
        }
        
        return mstWt;
    }
};