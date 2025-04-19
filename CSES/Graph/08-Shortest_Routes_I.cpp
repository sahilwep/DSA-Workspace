/*

//  CSES: Shortest Routes I


//  Problem Statement: 
    -> There are n cities and m flight connections between them. 
    -> Your task is to determine the length of the shortest route from Syrjälä to every city.
    
    Input
        The first input line has two integers n and m: the number of cities and flight connections. 
        The cities are numbered 1,2,...,n, and city 1 is Syrjälä.
        After that, there are m lines describing the flight connections. 
        Each line has three integers a, b and c: a flight begins at city a, ends at city b, and its length is c. Each flight is a one-way flight.
        You can assume that it is possible to travel from Syrjälä to all other cities.
    Output
        Print n integers: the shortest route lengths from Syrjälä to cities 1,2,...,n.

// Constraints
    1 <= n <= 10^5
    1 <= m <= 2 * 10^5
    1 <= a,b <= n
    1 <= c <= 10^9

    Example
        Input:
            3 4
            1 2 6
            1 3 2
            3 2 3
            1 3 4

        Output:
            0 5 2


// Observations: 
    -> Given n Nodes of 1 based indexing (1 --- n)
    -> Given m Edges: 
        edges[i] = {u, v, wt}
    
    -> We need to find the shortest distance from src 1 to all the dst.


    // Dijkstra's Approach: 
        -> Source = 1;
        -> considerations factor = wt
        -> return dist, as shortest distance from source.

    // Complexity: 
        -> TC: O(E + log(V))
        -> AS: O(V)


*/ 
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pr;

 
class Solution {
private:
public: 
    void solve(vector<vector<ll>>& edges, int n, int m) {
        // Build adj list: 
        vector<vector<pair<ll, ll>>> adj(n + 1);
        for(auto &it: edges) {  // directed edges:
            adj[it[0]].push_back({it[1], it[2]});
        }
 
        // Dijkstra's impl.
        vector<ll> dist(n + 1, LLONG_MAX);
        priority_queue<pr, vector<pr>, greater<>> pq;
 
        pq.push({0, 1});
        dist[1] = 0;
        
        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();
            
            if(dist[node] < cost) continue;
 
            for(auto &[v, wt]: adj[node]) {
                ll newCost = (ll)wt + cost;
 
                if(newCost < dist[v]) {
                    dist[v] = newCost;
 
                    pq.push({newCost, v});
                }
            }
        }
 
        for(int i = 1; i <= n; i++) {
            cout << dist[i] << " ";
        }
    }
 
};
 
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> edges;
    for(int i = 0; i < m; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }
 
    Solution obj;
    obj.solve(edges, n, m);
 
    return 0;
}