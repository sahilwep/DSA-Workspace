/*

//  Cheapest Flights Within K Stops


//  Problem Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private: 
    typedef pair<int, pair<int, int>> ppr;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build adj list: 
        vector<vector<pair<int, int>>> adj(n);
        for(auto &it: flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Process Dijkstra's: 
        vector<int> dist(n, INT_MAX);
        priority_queue<ppr, vector<ppr>, greater<>> pq;

        dist[src] = 0;
        pq.push({0, {0, src}}); // Structure: <stops, cost, node>

        while(!pq.empty()) {
            auto [stops, oth] = pq.top();
            pq.pop();

            int cost = oth.first, node = oth.second;

            // Explore adj node: 
            for(auto [v, wt]: adj[node]) {
                int newCost = cost + wt;
                if(newCost < dist[v] && stops <= k)  {
                    dist[v] = newCost;
                    pq.push({stops + 1, {newCost, v}});
                }
            }
        }

        return (dist[dst] != INT_MAX) ? dist[dst] : -1;
    }
};