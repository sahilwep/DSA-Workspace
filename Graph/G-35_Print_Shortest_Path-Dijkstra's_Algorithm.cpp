/*

// G-35. Print Shortest Path - Dijkstra's Algorithm


// Problem Statement: 
    -> You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest weight path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.
    -> The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.
    -> Note: The driver code here will first check if the weight of the path returned is equal to the sum of the weights along the nodes on that path, if equal it will output the weight of the path, else -2. In case the list contains only a single element (-1) it will simply output -1. 



// Examples :

    Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
    Output: 5
    Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5. 

    Input: n = 2, m= 1, edges = [[1, 2, 2]]
    Output: 2
    Explanation: Shortest path from 1 to 2 is by the path 1 2 whose weight is 2. 

    Input: n = 2, m= 0, edges = [ ]
    Output: -1
    Explanation: Since there are no edges, so no answer is possible.


// Approach:

    // Dijkstra's Algorithm for Shortest Distance:
        -> We use Dijkstra's algorithm to compute the shortest distance from the source node to all other nodes in the graph.
        -> The algorithm employs a priority queue (min-heap) to always process the node with the smallest known distance first, ensuring efficient updates to adjacent nodes.

    // Maintaining a Parent Array for Path Construction:
        -> Alongside the distance array, we maintain a parent array to store the immediate predecessor (parent) of each node on its shortest path from the source.
        -> Whenever the distance to a node is updated (i.e., a shorter path is found), we also update its parent to reflect the node from which it was reached.

    // Path Construction Using Backtracking:
        -> Once we have the shortest distance to the destination node, we backtrack through the parent array starting from the destination node.
        -> By iteratively following the parent of each node, we construct the path from the destination node back to the source.

    // Reversing the Path for Ordered Output:
        -> Since the path is constructed in reverse order (from destination to source), we reverse it at the end to get the path in the correct sequence (from source to destination).

    // Edge Case:
        -> If the distance to the destination node remains INT_MAX, it indicates that the destination is unreachable from the source. In such cases, we return {-1} as the result.




// Complexity:
    -> TC: O(m* log(n))
    -> SC: O(n)
    


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Convert edges into graph adjacency list:
        int V = n;
        vector<pair<int, int>> adj[V+1]; // Declare adjacency list with size V+1, as vertices are from 1 to n.
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int dist = it[2];
            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }
        
        // Apply Dijkstra's algorithm:
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Declare priority queue.
        vector<int> distance(V+1, INT_MAX); // Distance array initialized with INT_MAX.
        vector<int> parent(V+1); // Parent array to store the parent of each node.
        
        for (int i = 1; i <= V; i++) parent[i] = i; // Initialize each node's parent to itself.
        distance[1] = 0; // Set the distance of the source node (1) to 0.
        pq.push({0, 1}); // Push the source node (distance = 0, node = 1) into the priority queue.
        
        while (!pq.empty()) { // While the priority queue is not empty:
            auto it = pq.top(); // Get the top node pair from the priority queue.
            int dist = it.first, node = it.second;
            pq.pop(); // Remove the top node pair from the priority queue.
            
            // Explore the adjacent nodes:
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int weight = it.second;
                
                // Check if the current path to the adjacent node is shorter:
                if (dist + weight < distance[adjNode]) {
                    distance[adjNode] = dist + weight; // Update the distance of the adjacent node.
                    pq.push({distance[adjNode], adjNode}); // Push the updated distance and node into the priority queue.
                    parent[adjNode] = node; // Update the parent of the adjacent node to the current node.
                }
            }
        }
        
        // Check if the destination node is reachable:
        if (distance[n] == INT_MAX) { // If the destination node (n) is unreachable:
            return {-1}; // Return a list containing -1.
        }
        
        // Backtrack the parent array to construct the path:
        vector<int> path; // Vector to store the path.
        int node = n; // Start from the destination node.
        while (parent[node] != node) { // Traverse back until we reach the source node.
            path.push_back(node); // Add the current node to the path.
            node = parent[node]; // Move to the parent of the current node.
        }
        
        path.push_back(1); // Add the source node to the path.
        path.push_back(distance[V]); // According to the question, add the distance of 'n' at the end.
        reverse(path.begin(), path.end()); // Reverse the path, as it was constructed backward.
        return path; // Return the final path.
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans <<  "~" << endl;
    }
}