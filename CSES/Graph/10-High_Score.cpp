/*

//  CSES: High Score

//  Problem Statement: 
        -> You play a game consisting of n rooms and m tunnels. Your initial score is 0, and each tunnel increases your score by x where x may be both positive or negative. 
        -> You may go through a tunnel several times.
        -> Your task is to walk from room 1 to room n. What is the maximum score you can get?
    // Input
        -> The first input line has two integers n and m: the number of rooms and tunnels. The rooms are numbered 1,2,\dots,n.
        -> Then, there are m lines describing the tunnels. Each line has three integers a, b and x: the tunnel starts at room a, ends at room b, and it increases your score by x. All tunnels are one-way tunnels.
        -> You can assume that it is possible to get from room 1 to room n.
    // Output
        -> Print one integer: the maximum score you can get. However, if you can get an arbitrarily large score, print -1.

Constraints
    1 <= n <= 2500
    1 <= m <= 5000
    1 <= a,b <= n
    -10^9 <= x <= 10^9

// Example
    Input:
        4 5
        1 2 3
        2 4 -1
        1 3 -2
        3 4 7
        1 4 4

    Output: 5

// Observations: 
    -> Given n nodes 1 based indexing
    -> given m edges => edge[u, v, wt] => u -------> v directed weighted edge
    -> NOTE: edge weight can have negative values..
    -> We need to find the shortest path from 1 to n.
    -> Shortest path we use dijkstra's but the problem here is the negative edge weights, which can be solve using the bellman ford approach.

    // Bellman Ford Approach: 
        -> Find the shortest path from source
        -> Find negative cycle in graphs, if there is negative cycle 
        -> the maximum score you can get. However, if you can get an arbitrarily large score, print -1.
        -> Instead of finding the smaller value as our considerations factor, we will take maximum value as our considerations factor.

    // Complexity: 
        -> TC: O(n * E)
        -> SC: O(n)


*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = -1e18;   // negative infinity

class Solution {
public: 
    void solve(vector<vector<ll>>& edges, int n, int e) {
        
        // Bellman Ford: 
        vector<ll> dist(n, INF);
        dist[0] = 0;
        
        // Process (n - 1) time for every edges:
        for(int i = 0; i < n - 1; i++) {
            for(auto &it: edges) {
                int u = it[0], v = it[1], wt = it[2];
                
                // We are checking the maximum score we can obtain:
                if(dist[u] != INF && dist[u] + wt > dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Step to detect positive cycle affecting the path to node n:
        vector<bool> affected(n, false);
        for(int i = 0; i < n; i++) {
            for(auto &it: edges) {
                int u = it[0], v = it[1];
                ll wt = it[2];
                if(dist[u] != INF && dist[u] + wt > dist[v]) {
                    dist[v] = dist[u] + wt;
                    affected[v] = true;
                }
                if(affected[u]) affected[v] = true;
            }
        }
        
        if(affected[n-1]) {
            cout << -1 << endl;
        } else {
            cout << dist[n-1] << endl;
        }
    }
};

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<ll>> edges;
    vector<vector<ll>> queries;
    for(int i = 0; i < e; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u - 1, v - 1, wt});    // making 0-based index
    }

    Solution obj;
    obj.solve(edges, n, e);

    return 0;
}