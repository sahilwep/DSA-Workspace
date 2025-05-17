/*

//  City With the Smallest Number of Neighbors at a Threshold Distance

//  Problem Link:   https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/0
  

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Floyd Warshall Solution: 
class Solution {
public:
    int findCity(int n, int m, vector<vector<int>>& edges, int disThr) {
        
        // Build Graph adj Matrix: 
        vector<vector<int>> mat(n, vector<int> (n, INT_MAX));
        for(auto &it: edges) {
            int u = it[0], v = it[1], wt = it[2];
            mat[u][v] = wt;
            mat[v][u] = wt;
        }
        
        // Build Multi-source distance using Floyd Warshall: 
        for(int k = 0; k < n; k++) {
            for(int u = 0; u < n; u++) {
                for(int v = 0; v < n; v++) {
                    if(mat[u][k] != INT_MAX && mat[k][v] != INT_MAX) {
                        mat[u][v] = min(mat[u][v], mat[u][k] + mat[k][v]);
                    }
                }
            }
        }
        
        // Process distance threshold: 
        vector<int> city(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if( i != j && mat[i][j] <= disThr) {
                    city[i]++;
                }
            }
        }
        
        // Now get the minimum city with maximum numbered:
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(city[i] <= city[ans]) {
                ans = i;
            }
        }
    
        return ans;
    }
};

// Dijkstra's based Solution:
class Solution {
private: 
    vector<int> dijkstra(int src, vector<vector<pair<int, int>>>& adj, int n) {
        
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int cost = it.first, node = it.second;
            
            for(auto &i: adj[node]) {
                int v = i.first, wt = i.second;
                int newCost = cost + wt;
                if(newCost < dist[v]) {
                    dist[v] = newCost;
                    pq.push({newCost, v});
                }
            }
        }
        
        return dist;
    }
public:
    int findCity(int n, int m, vector<vector<int>>& edges, int disThr) {
        
        // Build Graph adj list: 
        vector<vector<pair<int, int>>> adj(n);
        for(auto &it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        // Build Multi-source distance: 
        vector<vector<int>> mat(n);
        for(int i = 0; i < n; i++) {
            mat[i] = dijkstra(i, adj, n);
        }
        
        // Process distance threshold: 
        vector<int> city(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if( i != j && mat[i][j] <= disThr) {
                    city[i]++;
                }
            }
        }
        
        // Now get the minimum city with maximum numbered:
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(city[i] <= city[ans]) {
                ans = i;
            }
        }
    
        return ans;
    }
};
