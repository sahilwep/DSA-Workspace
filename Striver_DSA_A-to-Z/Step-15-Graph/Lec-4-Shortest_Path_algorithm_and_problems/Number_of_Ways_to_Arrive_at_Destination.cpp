/*

//  1976. Number of Ways to Arrive at Destination


//  Problem Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/



// Observations: 
    -> Given weighted undirected edges
    -> find the total number of ways to reach destination n-1 with shortest distance possible..
    -> src = 0, & dst = n-1


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private: 
    typedef long long ll;
    typedef pair<ll, int> pr;
    int mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Build graph adj list: 
        vector<vector<pair<int, int>>> adj(n);
        for(auto &it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Process Dijkstra's
        priority_queue<pr, vector<pr>, greater<>> pq;
        vector<ll> dist(n, LLONG_MAX);
        vector<ll> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if(dist[node] < cost) continue; // skip unsual iterations..

            for(auto &[v, wt]: adj[node]) {
                ll newCost = wt + cost;
                if(newCost < dist[v]) {
                    dist[v] = newCost;
                    ways[v] = ways[node];
                    pq.push({dist[v], v});
                } else if(newCost == dist[v]) {
                    ways[v] = (ways[v] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};