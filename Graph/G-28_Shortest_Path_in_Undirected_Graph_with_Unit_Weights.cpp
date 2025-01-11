/*

//  G-28. Shortest Path in Undirected Graph with Unit Weights 


//  Problem Statement
    -> You are given an adjacency matrix, adj of Undirected Graph having unit weight of the edges, 
    -> find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.


// Examples:
    Input: adj[][] = [[1, 3], [0, 2], [1, 6], [0, 4], [3, 5], [4, 6], [2, 5, 7, 8], [6, 8], [7, 6]], src = 0
    Output: 0 1 2 1 2 3 3 4 4

    Input: adj[][] = [[3], [3], [0, 1]], src = 3
    Output: 1 1 -1 0


// Approach:
    1. Use Breadth-First Search (BFS) to calculate the shortest paths in the graph.
    2. Initialize:
        - A distance vector `dis` with `INT_MAX` to represent initially unreachable nodes.
        - The distance to the source node (`src`) is set to `0`.
    3. Start BFS traversal from the source:
        - Use a queue to process nodes level by level.
        - For each node, traverse its neighbors and update their distances if a shorter path is found.
    4. After BFS:
        - Replace all distances still equal to `INT_MAX` (unreachable nodes) with `-1`.
    5. Return the distance vector.


// Why BFS?
    BFS is used because it ensures that each node is visited in order of increasing distance in an unweighted graph, guaranteeing the shortest path to each node.
    We are using queue, because Since it is increasing by 1 the queue will always store the source with distance 0, & next node come at distance 1, & then next of next node come at distance 2..
    So we can say the edge weight is increasing by 1, So if we look at the queue it is always sorted, because first the source then the next node then the next of next node...


// Intrusion: How the Code Works

    Input Reading:
        The input graph is read as an adjacency list representation for efficiency.
        The source node is taken as input for BFS traversal.

    BFS Traversal:
        Starts from the source node with a distance of 0.
        For each node, its neighbors are explored, and their distances are updated if a shorter path is found.

    Unreachable Nodes:
        After BFS, nodes still marked as INT_MAX are replaced with -1.

    Output:
        The shortest distances to all nodes are printed.


// Complexity: 
    -> TC: O(V + E)
    -> SC: O(V + E)

*/
#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    // Function to find the shortest path from the source node to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V = adj.size(); // Number of vertices in the graph

        // Distance vector to store the shortest distance from src to each node.
        // Initialized to INT_MAX to represent nodes that are initially unreachable.
        vector<int> dis(V, INT_MAX);

        // Queue for BFS traversal
        queue<int> q;

        // Set the distance of the source node to 0 and push it to the queue
        dis[src] = 0;
        q.push(src);

        // BFS traversal to calculate the shortest paths
        while (!q.empty()) {
            int node = q.front(); // Get the front element in the queue
            q.pop(); // Remove it from the queue

            // Traverse all neighbors of the current node
            for (auto it : adj[node]) {
                // If a shorter path to the neighbor is found
                if (dis[node] + 1 < dis[it]) {
                    dis[it] = dis[node] + 1; // Update the distance
                    q.push(it); // Add the neighbor to the queue for further traversal
                }
            }
        }

        // Replace distances of unreachable nodes (still INT_MAX) with -1
        for (int i = 0; i < V; i++) {
            if (dis[i] == INT_MAX) {
                dis[i] = -1; // Mark unreachable nodes
            }
        }

        return dis; // Return the distance array
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n" << cout << "~\n";
    }
}