/*

//  G-38. Cheapest Flights Within K Stops


//  Problem Statement: 
    -> There are n cities connected by some number of flights. 
    -> You are given an array flights where flights[i] = [from[i], to[i], price[i]] indicates that there is a flight from city from[i] to city toi with cost price[i].
    -> You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops.
    ->  If there is no such route, return -1.


// Example:   
    Example 1:
        Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
        Output: 700
        Explanation:
        The graph is shown above.
        The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
        Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

    Example 2:
        Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
        Output: 200
        Explanation:
        The graph is shown above.
        The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

    Example 3:
        Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
        Output: 500
        Explanation:
        The graph is shown above.
        The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.


// Observations: 
    -> we are given flights[] => {source, dest, price}
    -> We are given source node, destinations node.
    -> We are given directed graph.
    -> We are given at-most 'k' stops it can take.
    -> We need to find the shortest path to reach the destination with exactly 'k' stops.
    -> In simple we need to fine the shortest distance to destinations in exactly 'k' steps.
    -> If there is no such route, return '-1'
    -> We can use dijkstra's algorithm to solve this problem.
        -> We will use priority queue:
            -> Structure: {k-value, {node, price}}
            -> We are considering k-value as priority to process first, because we are bounded to have certain stops only.
            -> Price factors will be adjust according to the k-value...
        -> We will use distance array to maintain the shortest distance to every node.
        -> Rest perform simple dijkstra's format.
    
    // Complexity:
        -> TC: O(E * log(V * k))
        -> SC: O(E + (V * k))


// Extra-Observations: 
    -> If we carefully observe, k-factor say stops, will increment by '1' as it takes any stops.
    -> In simple k-factor increment as constant, which wont' effect much..
    -> If we carefull observe, it increment as level-wise BFS increment to find the path.
    -> If we won't use dijkstra's solution, then any way it will work..
    -> Also the complexity will be decreased, if we used plain BFS with queue.

    // Complexity: 
        -> TC: O(E + (V * k))
        -> SC: O(E + (V * k))


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Normal Dijkstra's Based Solution: 
class Solution {
private:
    typedef pair<int, pair<int, int>> ppr;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        // Edge Case 
        if(src == dst) return 0;    // if source & destinations are same return '0' cost required to reach there.

        // Graph adj list formations for directed weighted graph:
        vector<vector<pair<int, int>>> adj(n);
        for(auto &it: flights) {
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
        }

        // Process Dijkstra's Algorithm:
        priority_queue<ppr, vector<ppr>, greater<>> pq;
        vector<int> dist(n, INT_MAX);

        pq.push({0, {0, src}});  // insertion of source node:
        dist[src] = 0;

        int minCost = INT_MAX;
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int stops = it.first;
            int cost = it.second.first;
            int node = it.second.second;

            // Check for answer:
            if(node == dst && stops <= (k + 1)){
                // Store minimum as possible:
                minCost = min(minCost, cost);
            }

            // Explore adjNodes:
            for(auto [v, wt]: adj[node]) {
                if(cost + wt < dist[v]) {
                    dist[v] = cost + wt;

                    pq.push({stops + 1, {cost + wt, v}});
                }
            }
        }

        return (minCost == INT_MAX) ? -1 : minCost;  // if there's no any route return -1, else return minCost
    }
};


// Optimized Dijkstra's Based Solution: 
class Solution {
private:
    typedef pair<int, pair<int, int>> ppr;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Convert flights into adj list:
        vector<vector<pair<int, int>>> adj(n);
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Dijkstra's Algorithm:
        priority_queue<ppr, vector<ppr>, greater<>> pq; // structure {k, {node, dist}}
        vector<int> dist(n, INT_MAX);   // maintain distance vector to store the shortest path of every node according to stops-factor

        pq.push({0, {src, 0}}); // push Initial source stops, with node & dist 
        dist[src] = 0;  // mark source distance as '0'

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // Explore adjacent nodes:
            for(auto [v, edgeWt]: adj[node]){
                int newCost = cost + edgeWt;    // get the newCost to reach from node --> v.
                if(newCost < dist[v] && stops <= k){    // check if newCost is less than the previous one, && stops is less or equal to 'k'
                    dist[v] = newCost;  // update new cost.

                    pq.push({stops + 1, {v, newCost}}); // push new path into priority queue.
                }
            }
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst]; // return destination cost.
    }
};


// BFS Based Solution: 
class Solution {
private:
    typedef pair<int, pair<int, int>> ppr;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Convert flights into adj list:
        vector<vector<pair<int, int>>> adj(n);
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<ppr> q; // Structure: {k, {node, dist}}
        vector<int> dist(n, INT_MAX);   // maintain distance vector to store the shortest path of every node according to stops-factor

        q.push({0, {src, 0}}); // push Initial source stops, with node & dist 
        dist[src] = 0;  // mark source distance as '0'

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // Explore adjacent nodes:
            for(auto [v, edgeWt]: adj[node]){
                int newCost = cost + edgeWt;    // get the newCost to reach from node --> v.
                if(newCost < dist[v] && stops <= k){    // check if newCost is less than the previous one, && stops is less or equal to 'k'
                    dist[v] = newCost;  // update new cost.

                    q.push({stops + 1, {v, newCost}}); // push new path into  queue.
                }
            }
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst]; // return destination cost.
    }
};