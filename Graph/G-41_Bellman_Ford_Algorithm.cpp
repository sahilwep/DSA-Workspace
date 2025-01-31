/*

//  G-41. Bellman Ford Algorithm



//  Problem Statement: 
    -> Given a weighted and directed graph of V vertices and E edges, find the shortest distance of all the vertices from the source vertex (src) and return a list of integers where the ith integer denotes the distance of the ith node from the source node. If a vertex can't be reached from src, then mark the distance as 10^8.
    -> Note: If the graph contains a negative cycle, return an array consisting of only -1.



// Examples:

    Input: edges = [[0,1,9]], src = 0
    Output: [0, 9]
    Explanation: Shortest distance of all nodes from the source is printed.

    Input: edges = [[0,1,5], [1,0,3], [1,2,-1], [2,0,1]], src = 2
    Output: [1, 6, 0]
    Explanation: For nodes 2 to 0, we can follow the path: 2 → 0. This has a distance of 1. For nodes 2 to 1, we can follow the path: 2 → 0 → 1, which has a distance of 1 + 5 = 6.



// Observations: 
    -> Bellman-Ford works for graphs containing negative-weight edges, unlike Dijkstra’s algorithm, which fails in such cases.
    -> It helps detect negative cycles in a graph.
    -> It is a single-source shortest path algorithm that uses edge relaxation repeatedly.



// Introduction:
    -> The Bellman-Ford algorithm is used to find the shortest path from a single source to all other vertices in a weighted graph.
    -> It can handle graphs with negative weight edges, which makes it more versatile than Dijkstra’s algorithm.
    -> However, its time complexity is O(V * E), which is less efficient than Dijkstra’s O((V + E) logV) using a priority queue.



// Why do we iterate exactly (V-1) times?
    -> A graph can have at most (V-1) edges in the longest simple path (without cycles).
    -> In each iteration, we relax all edges, gradually propagating the shortest path information.
    -> By the (V-1)th iteration, all shortest paths will be found if no negative cycles exist.



// What is a Negative Cycle?
    -> A negative cycle is a cycle in a graph where the sum of edge weights is negative.
    -> If a graph contains a negative cycle, the shortest path problem becomes undefined because we can reduce the path weight indefinitely by traversing the cycle repeatedly.
    -> The Bellman-Ford algorithm detects negative cycles in an additional (V-th) iteration by checking if further relaxation is possible. If it is, then a negative cycle exists.



// Approach:
    1. Initialize all distances from the source to all vertices as infinity (10^8), except the source itself (0).
    2. Perform (V-1) iterations, relaxing all edges in each iteration.
    3. If an edge relaxation improves the distance to a vertex, update it.
    4. Perform one additional iteration to check for negative cycles.
    5. If relaxation still occurs, return [-1], indicating a negative cycle.
    6. Otherwise, return the final distance array.


// Complexity:
    -> Time Complexity: O(V * E) (since we iterate over all edges V-1 times)
    -> Space Complexity: O(V) (to store distances)


*/


#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        for(int i = 0; i < V - 1; i++) { // runs exactly 'V-1' times
            for(auto &it: edges) {   // iterates through all edges
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                // If distance is in range & new distance is shorter, update it
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {   
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Nth relaxation to check for negative cycle:
        for(auto &it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};    // return -1 if a negative cycle is detected
            }
        }
        
        return dist;
    }
};
