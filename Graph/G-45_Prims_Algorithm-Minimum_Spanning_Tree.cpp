/*

//   G-45. Prim's Algorithm - Minimum Spanning Tree


//  Problem Statement: 
    -> Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. 
    -> The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. 
    -> Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.


// Example: 

    // Example 1:

        Input:
            3 3
            0 1 5
            1 2 3
            0 2 1

                             [0]
                            /   \
                           /     \
                        5 /       \ 1
                         /         \
                       [1]---------[2]
                            3

        Output: 4


                             [0]
                               \
                                \
                                 \ 1
                                  \
                       [1]---------[2]
                            3

        Explanation: The Spanning Tree resulting in a weight of 4 is shown above.

    // Example 2:

        Input: 
            2 1
            0 1 5
        Output: 5 

                            [0]
                            /
                          / 5
                        /
                      [1]

        Explanation: Only one Spanning Tree is possible which has a weight of 5.



// Approach:
    -> We use Prim's Algorithm to find the Minimum Spanning Tree (MST) of a graph.
    -> A priority queue (min-heap) is used to always pick the smallest weight edge first.
    -> A visited array is maintained to track nodes that have been included in the MST.
    -> The algorithm starts from node 0 and processes the minimum weighted adjacent nodes first.
    -> It follows a greedy approach, ensuring that at every step, the minimum weight edge is chosen.


// Intrusion:
    -> Start with node 0, push it into the priority queue with weight 0.
    -> Process nodes in increasing weight order using the priority queue.
    -> Skip a node if it has already been visited.
    -> Add the edge weight to the total MST weight and mark the node as visited.
    -> Push all adjacent nodes (that are unvisited) into the priority queue.
    -> Repeat this until all nodes are included in the MST.
    -> If storing the MST, keep track of the edges included in it.
    -> Finally, return the total weight of the MST, and if needed, print the edges.


    
// Complexity:
    -> TC: O(E * log(E))
    -> SC: O(E), Storing all the edges into priority queue in worse case.
    
// Quick NOTES:
    -> This is greedy approach:
    -> Every node we will process only ones.
    -> from there we will choose only those edge which has minimum weight & sum up in our MST SUM OR STORE THAT EDGE INTO OUR RESULT 
    -> Visited array will help us to visit every node only ones.
    -> priority queue will always give the smallest weight.



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// When we only need to find the MST Weight:
class Solution {
private:
    typedef pair<int, int> pr;  // {weight, node}
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {

        priority_queue<pr, vector<pr>, greater<>> pq;  // Min-heap to get the smallest weight edge
        vector<int> vis(V, 0); // Keeps track of visited nodes
        int mstWt = 0; // Total weight of the MST
        
        // Start from node 0: {weight, {node, parent}}
        pq.push({0, 0});
        // NOTE: We will not mark visited the first source here, because if we mark them visited here, algorithm logic will not proceed.. 
        

        while(!pq.empty()) {
            auto it = pq.top(); // get the top value from the priority queue.
            pq.pop();   // remove that top values from priority queue
            
            int wt = it.first;  // get the edge weight.
            int node = it.second;   // get the node
            
            // If node is already visited, skip it because we are visiting every node only ones.
            if (vis[node]) continue;

            // Mark node as visited and add its weight to MST total weight
            vis[node] = 1;  // making them visit will make sure will not visit this node again.
            mstWt += wt;    // adding that edge weight value into our MST Sum result.
            

            // Explore adjacent_nodes / neighbors
            for(auto &it: adj[node]) {
                int adjNode = it[0];    // get the node value
                int edWt = it[1];       // get the edge weight from "node" ----> "adjNode"
            
                // Push only unvisited nodes into the priority queue to proceed our algorithm further..
                if(!vis[adjNode]) {
                    pq.push({edWt, adjNode});
                }
            }
        }
        
        return mstWt;   // last return the mst Weight.
    }
};


// If we want to MST Edges:
class Solution {
private:
    typedef pair<int, pair<int, int>> ppr;  // {weight, {node, parent}}
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {

        priority_queue<ppr, vector<ppr>, greater<>> pq; // Min-heap to get the smallest weight edge
        vector<int> vis(V, 0);  // Keeps track of visited nodes
        vector<pair<int, int>> mst; // Stores the edges in the MST
        int mstWt = 0; // Total weight of the MST
        

        // Start from node 0: {weight, {node, parent}}
        pq.push({0, {0, -1}});
        

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int wt = it.first;
            int node = it.second.first;
            int parent = it.second.second;
            
            // If node is already visited, skip it
            if(vis[node]) continue;
            
            // Mark node as visited and add its weight to MST total weight
            vis[node] = 1;
            mstWt += wt;

            // Store the edge in MST (except the starting node)
            if(parent != -1) {
                mst.push_back({node, parent});
            }
            
            // Explore adjacent nodes
            for(auto &it: adj[node]) {
                int adjNode = it[0];
                int edWt = it[1];

                // Push only unvisited nodes into the priority queue
                if(!vis[adjNode]) {
                    pq.push({edWt, {adjNode, node}});
                }
            }
        }
        
        // Print the edges in the MST
        cout << "Edges in the Minimum Spanning Tree:\n";
        for (const auto &[u, v] : mst) {
            cout << u << " --- " << v << endl;
        }
        
        return mstWt;
    }
};