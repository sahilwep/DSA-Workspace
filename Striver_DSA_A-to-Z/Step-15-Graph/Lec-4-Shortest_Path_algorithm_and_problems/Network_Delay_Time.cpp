/*

//  Network Delay Time

//  Problem Link: https://leetcode.com/problems/network-delay-time/description/

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    typedef pair<int, int> pr;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Build Graph adj list: 
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto &it: times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Process Dijkstra's
        vector<int> time(n + 1, INT_MAX);
        priority_queue<pr, vector<pr>, greater<>> pq;

        time[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {
            auto [timeToReach, node] = pq.top();
            pq.pop();

            for(auto &[v, wt]: adj[node]) {
                int newTime = timeToReach + wt;
                if(newTime < time[v]) {
                    time[v] = newTime;
                    pq.push({newTime, v});
                }
            }
        }
        
        int maxTime = *max_element(begin(time) + 1, end(time));
        return (maxTime == INT_MAX) ? -1 : maxTime;
    }
};