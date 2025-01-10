/*

//  G-27. Shortest Path in Directed Acyclic Graph - Topological Sort

//  Problem Statement:
    -> Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.
    -> Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.


// Examples :

    Input: V = 4, E = 2, edges = [[0,1,2], [0,2,1]]
    Output: [0, 2, 1, -1]
    Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.

    Input: V = 6, E = 7, edges = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]
    Output: [0, 2, 3, 6, 1, 5]
    Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3. Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6. Shortest path from 0 to 4 is 0->4 with edge weight 1.Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.



// Intrusion: 
    // Why TopoSort ?
        -> Linear Ordering:
            ->Topological sorting provides a linear ordering of vertices such that for every directed edge ( u-->v ), vertex ( u ) comes before ( v ) in the ordering.
            -> This property is essential for processing nodes in a way that ensures all dependencies (incoming edges) of a node are processed before the node itself.

    // Efficient Distance Calculation:
        -> In a DAG, once we have the topological order, we can process each vertex and update the shortest path distances to its adjacent vertices.
        -> By processing nodes in topological order, we ensure that when we process a node, all nodes that can reach it have already been processed. This guarantees that we have the shortest distance to the current node before we try to update the distances to its neighbors.


    // Efficient Distance Calculation:
        -> In a DAG, once we have the topological order, we can process each vertex and update the shortest path distances to its adjacent vertices.
        -> By processing nodes in topological order, we ensure that when we process a node, all nodes that can reach it have already been processed. This guarantees that we have the shortest distance to the current node before we try to update the distances to its neighbors.


// Steps Involved in  Code:

    // Topological Sort:
        -> We perform a Depth-First Search (DFS) to generate a topological sort of the graph. This ensures that each node is processed only after all nodes that can reach it have been processed.
        -> The nodes are pushed onto a stack in the order of their finishing times in the DFS, which gives the topological order when popped from the stack.

    // Shortest Path Calculation:
        -> Initialize the distance to the source node (node 0) as 0 and all other nodes as a large value (infinity).
        -> Process each node in topological order. For each node, update the distances to its adjacent nodes if a shorter path is found through the current node.
        -> This ensures that by the time we process a node, we have already found the shortest path to it, and we can use this information to update the shortest paths to its neighbors.



// Approach: 
    1. Perform a Topological Sort on the Directed Acyclic Graph (DAG).
    2. Process nodes from the stack in topological order and relax the edges:
        - Declare a distance array initialized with infinity (`INT_MAX`).
        - Set the distance of the source node to 0 because the distance from the source to itself is logically 0.
        - For each node popped from the stack:
            - Traverse its adjacent nodes and calculate the distance to these nodes by adding the edge weight to the current node's distance.
            - Update the distance of the adjacent node in the distance array with the minimum of its current distance and the newly calculated distance.
        - Repeat these steps until the stack is empty.
    3. Convert all distances that remain `INT_MAX` (unreachable nodes) to `-1`.
    4. The distance array will contain the shortest distances from the source node to all other nodes.



// Complexity:
    // Time Complexity:
        - Topological Sort: O(V + E)
        - Relaxation: O(V + E)
        - Total: O(V + E)

    // Space Complexity:
        - O(V + E) for the adjacency list and O(V) for the auxiliary data structures.

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    void topoSort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st){  // dfs solution
        vis[node] = 1;
        
        for(auto it: adj[node]){
            int v = it.first;
            if(!vis[v]){
                topoSort(v, adj, vis, st);
            }
        }
        
        st.push(node);  // at end push that element into stack
    }
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Create Graph:
        vector<pair<int, int>> adj[V];
        for(int i=0;i<E;i++){   // iterate to number of edges
            // node is from u -----> v
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        
        // Find The topoSort:
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topoSort(i, adj, vis, st);
            }
        }
        
        // Now empty stack & process distance vector:
        vector<int> dis(V, INT_MAX);    // this stores all the distance
        dis[0] = 0; // this is our source node, as we are given source node is '0'
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            // We need all the adjacent node:
            for(auto it: adj[node]){
                int v = it.first;   // adjacent node
                int wt = it.second; // adjacent node weight.
                
                // We need to relax it:
                if( dis[node] != INT_MAX && dis[node] + wt < dis[v]){    // if dis of source node + weight is lesser than the previous weight of adjacent node weight: update
                    dis[v] = dis[node] + wt;    // update it with new smallest weight
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(dis[i] == INT_MAX) dis[i] = -1;
        }
        
        return dis;
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}