/*

//  CSES: Shortest Routes II

//  Problem Statement: 
    -> There are n cities and m roads between them. 
    -> Your task is to process q queries where you have to determine the length of the shortest route between two given cities.

    // Input
        -> The first input line has three integers n, m and q: the number of cities, roads, and queries.
        -> Then, there are m lines describing the roads. Each line has three integers a, b and c: there is a road between cities a and b whose length is c. All roads are two-way roads.
        -> Finally, there are q lines describing the queries. Each line has two integers a and b: determine the length of the shortest route between cities a and b.
    // Output
        -> Print the length of the shortest route for each query. If there is no route, print -1 instead.
    
    // Constraints
        1 <= n <= 500
        1 <= m <= n^2
        1 <= q <= 10^5
        1 <= a,b <= n
        1 <= c <= 10^9

// Example
    Input:
        4 3 5
        1 2 5
        1 3 9
        2 3 3
        1 2
        2 1
        1 3
        1 4
        3 2

    Output:
        5
        5
        8
        -1
        3
    Explanation:

                            5
                    [1]-----------[2]
                      \           /
                       \9        /3
                        \       /
                         \     /
                          \[3]/

                            1 2 => 5
                            2 1 => 5
                            1 3 => 8
                            1 4 => -1
                            3 2 => 3


// Observations: 
    -> given 'n' nodes, 'e' edge & 'q' queries
    -> nodes are indexed from 1 to n inclusive.
    -> Edges: {u, v, wt} => undirected weighted graph.
    -> Given q queries: {u, v}, find the shortest distance b/w u, v

// Approach: 
    // Dijkstra's Solution:
        -> Find multiSource shortest path using dijkstra's & return the answer for each query.
        -> Strange that it's gave TLE.

        // Solution 1 Optimized
            // Complexity: 
                -> TC: O(Q * (E + N) log N)
                -> SC: O(N^2 + (N + E))
        
        // Solution 1 Normal:
            // Complexity: 
                -> TC: O(N * (E + N) log N)
                -> SC: O(N^2 +(N + E))

    // Floyd Warshall: 
        -> This got accepted, Better than Dijkstra's
            -> Even though Dijkstra's algorithm has a better theoretical complexity for single-source (O((N + E) log N)), 
            -> the total work done across many sources and queries can easily exceed Floyd-Warshall's O(N³) when:
                -> Q (number of queries) is large
                -> N (number of nodes) is not huge
                -> or if you're not optimizing repeated Dijkstra calls
            -> So yes — Floyd-Warshall can be a surprisingly effective weapon in the right scenario. It's one of those rare cases where the old-school brute-force approach shines in practice

        // Complexity: 
            -> TC: O(n^3 + Q)
            -> SC: O(n^2)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;

// ------------------------------------------------------- Floyd Warshall Accepted -------------------------------------------------------

class Solution {
public: 
    void solve(vector<vector<ll>>& edges, vector<vector<ll>>& queries, int n, int e) {
        
        // Initial Configurations: 
        vector<vector<ll>> mat(n, vector<ll> (n, LLONG_MAX));
        for(int i = 0; i < n; i++) mat[i][i] = 0;   // setting same node values as '0'
        for(auto &it: edges) {                      // setting edges weights to matrix:
            ll u = it[0], v = it[1], wt = it[2];
            
            mat[u][v] = min(mat[u][v], wt);
            mat[v][u] = min(mat[v][u], wt);
        }
        
        
        // Flood Warshall:
        for(int k = 0; k < n; k++) {
            for(int u = 0; u < n; u++) {
                for(int v = 0; v < n; v++) {
                    if(mat[u][k] < LLONG_MAX && mat[k][v] < LLONG_MAX) {
                        mat[u][v] = min(mat[u][v], mat[u][k] + mat[k][v]);
                    }
                }
            }
        }
        
        // Process Query:
        for(auto &it: queries) {
            int u = it[0], v = it[1];
            
            ll ans = mat[it[0]][it[1]];
            if(ans == LLONG_MAX) cout << -1 << endl;
            else cout << ans << endl;
        }
    }
};


// -------------------------------------------- Dijkstra's Solution (TLE) ------------------------------------------------------

// Optimized Solution 1: Only build path if it's not there
class Solution {
private: 
    vector<ll> dijkstra(int src, vector<vector<pair<ll, ll>>>& adj, int n) {
        
        vector<ll> dist(n, LLONG_MAX);
        priority_queue<pr, vector<pr>, greater<>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if(dist[node] < cost) continue;

            for(auto &[v, wt]: adj[node]) {
                ll newCost = wt + cost;
                if(newCost < dist[v]) {
                    dist[v] = newCost;
                    pq.push({newCost, v});
                }
            }
        }

        return dist;
    }
public: 
    void solve(vector<vector<ll>>& edges, vector<vector<ll>>& queries, int n, int e) {
        // Build Adj list:
        vector<vector<pr>> adj(n);
        for(auto &it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Build MultiSource shortest path using Dijkstra's
        // Process Query:
        vector<vector<ll>> mat(n);
        for(auto &it: queries) {
            int u = it[0], v = it[1];
            
            // Only build path if it's not build already:
            if(mat[u].size() == 0) {
                mat[u] = dijkstra(u, adj, n);
            }
            
            ll ans = mat[it[0]][it[1]];
            if(ans == LLONG_MAX) cout << -1 << endl;
            else cout << ans << endl;
        }

    }
};


// Solution 1: Build multisource path using dijkstra's
class Solution {
private: 
    vector<ll> dijkstra(int src, vector<vector<pair<ll, ll>>>& adj, int n) {
        
        vector<ll> dist(n, LLONG_MAX);
        priority_queue<pr, vector<pr>, greater<>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if(dist[node] < cost) continue;

            for(auto &[v, wt]: adj[node]) {
                ll newCost = wt + cost;
                if(newCost < dist[v]) {
                    dist[v] = newCost;
                    pq.push({newCost, v});
                }
            }
        }

        return dist;
    }
public: 
    void solve(vector<vector<ll>>& edges, vector<vector<ll>>& queries, int n, int e) {
        // Build Adj list:
        vector<vector<pr>> adj(n);
        for(auto &it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Build MultiSource shortest path using Dijkstra's
        vector<vector<ll>> mat;
        for(int i = 0; i < n; i++) {
            mat.push_back(dijkstra(i, adj, n));
        }

        // Process Query:
        for(auto &it: queries) {
            ll ans = mat[it[0]][it[1]];
            if(ans == LLONG_MAX) cout << -1 << endl;
            else cout << ans << endl;
        }

    }
};

int main() {
    int n, e, q;
    cin >> n >> e >> q;
    vector<vector<ll>> edges;
    vector<vector<ll>> queries;
    for(int i = 0; i < e; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u - 1, v - 1, wt});    // making 0-based index
    }

    for(int i = 0; i < q; i++) {
        ll u, v;
        cin >> u >> v;
        queries.push_back({u-1, v-1});
    }

    Solution obj;
    obj.solve(edges, queries, n, e);

    return 0;
}