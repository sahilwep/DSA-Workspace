/*

//  Dijkstra Algorithm

//  Problem Link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private: 
    typedef pair<int, int> pr;
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // Build Graph adj list: 
        vector<vector<pr>> adj(V);
        for(auto &it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector<int> dist(V, INT_MAX);
        set<pr> st;
        
        dist[src] = 0;
        st.insert({0, src});  // <cost, source>
        
        while(!st.empty()) {
            auto it = *st.begin();  // get the front element from set
            int cost = it.first;
            int node = it.second;
            st.erase(it);
            
            
            for(auto &i: adj[node]) {
                int v = i.first, wt = i.second;
                int newCost = cost + wt;
                
                if(newCost < dist[v]) {
                    dist[v] = newCost;
                    st.insert({newCost, v});
                }
            }
        }
        
        for(auto &it: dist) if(it == INT_MAX) it = -1;
        
        return dist;
    }
};