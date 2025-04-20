/*

//  2642. Design Graph With Shortest Path Calculator


//  Problem Statement: 
    There is a directed weighted graph that consists of n nodes numbered from 0 to n - 1. The edges of the graph are initially represented by the given array edges where edges[i] = [fromi, toi, edgeCosti] meaning that there is an edge from fromi to toi with the cost edgeCosti.
    Implement the Graph class:
        Graph(int n, int[][] edges) initializes the object with n nodes and the given edges.
        addEdge(int[] edge) adds an edge to the list of edges where edge = [from, to, edgeCost]. It is guaranteed that there is no edge between the two nodes before adding this one.
        int shortestPath(int node1, int node2) returns the minimum cost of a path from node1 to node2. If no path exists, return -1. The cost of a path is the sum of the costs of the edges in the path.


// Example: 
    Input
        ["Graph", "shortestPath", "shortestPath", "addEdge", "shortestPath"]
        [[4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]], [3, 2], [0, 3], [[1, 3, 4]], [0, 3]]
        Output
        [null, 6, -1, null, 6]

    Explanation
        Graph g = new Graph(4, [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]);
        g.shortestPath(3, 2); // return 6. The shortest path from 3 to 2 in the first diagram above is 3 -> 0 -> 1 -> 2 with a total cost of 3 + 2 + 1 = 6.
        g.shortestPath(0, 3); // return -1. There is no path from 0 to 3.
        g.addEdge([1, 3, 4]); // We add an edge from node 1 to node 3, and we get the second diagram above.
        g.shortestPath(0, 3); // return 6. The shortest path from 0 to 3 now is 0 -> 1 -> 3 with a total cost of 2 + 4 = 6.

// Approach: 
    -> Implement given graph.
    -> Implement edge add function
    -> Implement dijkstra's


// Complexity: 
    -> TC: O(N + E) + O(1) + O(E + log(V))
    -> SC: O(V + E)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Graph {
public:
    vector<vector<pair<int, int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {  // O(N + E)
        adj.resize(n);
        for(auto &it: edges) {  // directed weighted graph:
            adj[it[0]].push_back({it[1], it[2]});
        }
    }
    void addEdge(vector<int> edge) {    // O(1)
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    int shortestPath(int src, int dst) {    // O(E + log(V))
        int n = adj.size();

        // Dijkstra's impl.
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;   // <cost, node>

        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if(node == dst) {
                return cost;
            }

            if(dist[node] < cost) continue; // skip wasteful checks

            // Explore adj nodes: 
            for(auto &[v, wt]: adj[node]) {
                int newCost = cost + wt;
                if(newCost < dist[v]) {
                    dist[v] = newCost;
                    pq.push({newCost, v});
                }
            }
        }

        return -1;  // destinations not found
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */