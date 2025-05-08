/*

//  Directed Graph Cycle


//  Problem Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> adj(V);
        vector<int> id(V, 0);
        for(auto &it: edges) {
            adj[it[0]].push_back(it[1]);
            id[it[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++) if(!id[i]) q.push(i);
        
        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            cnt++;
            
            for(auto &it: adj[node]) {
                id[it]--;
                if(!id[it]) q.push({it});
            }
        }
        
        return (cnt == V) ? false : true;
    }
};