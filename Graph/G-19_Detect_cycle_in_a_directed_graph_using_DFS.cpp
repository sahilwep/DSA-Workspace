/*

//  G-19. Detect cycle in a directed graph using DFS


//  Problem Statement: 
    -> Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
    -> The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i. 
    -> Specifically, adj[i][j] represents an edge from vertex i to vertex j.

    // Example:

            [1]---->[2]------>[3]----->[4]
                      ↑        |        |
                     [8]       ↓        ↓
                     |  ↖     [7]----->[5]---->[6]
                     ↓    \
                    [9]-->[10]

            -> Here we have cycle in [8]->[9]->[10]->[8] Path.
            -> else we don't have cycle anywhere.


// Observations:
    -> On the same path the node has to be visited again, then only we can say that it has a cycle.

// Approach:
    -> For directed Graph:
    -> We will use two visited array, one is the visited array itself, and other one is path visited.
    -> Traverse dfs & mark visited & pathVisited during traversal
    -> Once the traversal of a path is done & there has been no cycle found, before returning unmark the pathVisited.
    -> During returning, we will check for visited & pathVisited,
    -> If any node is visited, but it's not the path visited return false, because that's the new another path we are traversing.
    -> But If any node is visited, and their pathVisited is also marked as true, then return true, because that's the cycle case.


// Observations:
    -> In a directed graph, a cycle is present only if a node is revisited on the same DFS path.
    -> Using a single visited array is insufficient; we need to differentiate between nodes visited in the current DFS path and those visited in other paths.


// Approach:
    1. Graph Type: This solution specifically addresses cycle detection in directed graphs.
    2. Data Structures:
       -> Use two arrays:
          - `vis`: Tracks if a node has been visited during any traversal.
          - `pathVis`: Tracks nodes visited during the current DFS path.
    3. Traversal Logic:
       -> Perform a DFS traversal from each unvisited node to explore all connected components of the graph.
       -> Mark a node as visited in both `vis` and `pathVis` when entering it.
    4. Cycle Detection:
       -> For each adjacent node:
          - If the node is unvisited (`!vis`), recursively perform DFS for it. If a cycle is detected in the recursive call, return `true`.
          - If the node is already visited (`vis`) **and is part of the current DFS path (`pathVis`)**, a cycle is detected. Return `true`.
    5. Backtracking:
       -> After exploring all adjacent nodes, backtrack by unmarking the current node in `pathVis` before returning.
       -> This ensures the current path is correctly updated when the recursion stack unwinds.
    6. Disconnected Components:
       -> Iterate through all nodes in the graph. If a node is unvisited, start a DFS from it to handle disconnected components.
    7. Final Output:
       -> If a cycle is detected in any DFS traversal, return `true`.
       -> If all nodes are traversed without detecting a cycle, return `false`.


// Key Edge Cases:
    -> A graph with multiple disconnected components, Check for multiple components.
    -> A graph with no edges or a single node pointing to itself (self-loop).

// Complexity:
    -> Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
    -> Space Complexity: O(V) for the `vis` and `pathVis` arrays, plus the recursive call stack.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis ){
        vis[node] = 1;      // mark current node as visited 
        pathVis[node] = 1;  // mark current node as visited for temporary path.
        
        // Traverse for adjacent nodes:
        for(auto it: adj[node]){
            // If this adjacent node is not visited:
            if(!vis[it]){
                if(dfsCheck(it, adj, vis, pathVis) == true) return true; // if this adjacent node go across & finds a cycle then return true, if this doesn't then we will keep on doing for next adjacent nodes.
            }
            // If the node has been previously visited, but it has to be visited on the same path: then also return true that we have found cycle.
            else if(pathVis[it]){   // condition: if(vis[it] == 1 && pathVis[it] == 1) return true for cycle found.
                return true;
            }
        }
        
        // Backtracking: Remove the current node from the path before returning.
        pathVis[node] = 0;  // whenever we are going back, make sure this current node is unmarked, as visiting has beed done.
        return false;       // return false saying there is no cycle.
        
        
    }
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> vis(V, 0);      // maintain the visited nodes.
        vector<int> pathVis(V, 0);  // maintain the path of visited array for every root
        
        // Checking for multiple Components:
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfsCheck(i, adj, vis, pathVis) == true) return true;   // if this return a cycle return true.
            }
        }
        
        return false;   // else there is no cycle.
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
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}