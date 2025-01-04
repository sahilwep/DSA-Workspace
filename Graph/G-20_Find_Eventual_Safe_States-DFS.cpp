/*

//  G-20. Find Eventual Safe States - DFS


//  Problem Statement:
    -> There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
    -> A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
    -> Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.



// Example:
    Example 1:
        Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
        Output: [2,4,5,6]
        Explanation: The given graph is shown above.
        Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
        Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

    Example 2:
        Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
        Output: [4]
        Explanation:
        Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.



// Observations:
    -> A node is a terminal node, that has outgoing degree = 0
    -> Safe node is a node that reaches to terminal node & have no-cycle occurred.
    -> In simple word safe node is a node that leads to terminal node & there is other path found in between that leads to cycle.
    -> Anyone that are the part of cycle can never be safe node.
        
        // Example:

            [1]---->[2]------>[3]----->[4]
                      ↑        |        |
                     [8]       ↓        ↓
                     |  ↖     [7]----->[5]---->[6]
                     ↓    \
                    [9]-->[10]

            Input:
                    [0]----->[1]
                    | ↖     / | 
                    |   \ /   |     [6]
                    ↓ ↙   \   ↓
                    [2]     [3]
                     |
                     ↓
                    [5]<----[4]


            Output:
                2 4 5 6
            Explanation:
                The given graph is shown above.
                Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them. 
                Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

        // Conclusion:
            -> Anyone that who is a part of cycle can never be safe node.
            -> Anyone that leads to a cycle can never be safe node.
            -> Everyone else can be safe node.
            -> The whole problem can be solve by figuring out which node is the part of cycle & which node that leads to a cycle.

// Approach:
    -> We know that how we can find a cycle usign DFS
        -> We maintain two things "visited" & 'pathVisited' & solve the problem
    -> Using Same thing we can modify a bit to find the solution.
    -> When recursive call ends and will not fall into any cycle, we will store that node as safe node.
    -> When we get the cycle we directly return without unmark the pathVisited for that node.
    -> And anytime a node leads to that path, that will immediately know & mark themself as not safe node.

// Complexity:
    -> TC: O(V + 2E)
    -> SC: O(V + 2E)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    // Helper function to perform DFS and determine if the current node is part of a cycle.
    bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis, vector<int> &check) {
        vis[node] = 1;      // Mark the node as visited.
        pathVis[node] = 1;  // Mark the node as visited in the current path.
        check[node] = 0;    // Assume the node is not safe initially.

        // Traverse all adjacent nodes of the current node.
        for (auto it : adj[node]) {
            // If the adjacent node is not visited, perform DFS recursively.
            if (!vis[it]) {
                // If a cycle is detected during DFS, mark the current node as unsafe and return true.
                if (dfs(it, adj, vis, pathVis, check) == true) {
                    check[node] = 0; // Mark the node as not safe.
                    return true;    // Indicate a cycle is found.
                }
            }
            // If the adjacent node is visited and is part of the current path, a cycle is detected.
            else if (pathVis[it]) {
                check[node] = 0; // Mark the node as not safe.
                return true;    // Indicate a cycle is found.
            }
        }

        // If no cycle is detected, mark the current node as safe.
        check[node] = 1;
        pathVis[node] = 0;  // Unmark the node from the current path.
        return false;       // No cycle found.
    }

public:
    // Function to return a list of nodes that are eventually safe.
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);      // Keeps track of visited nodes.
        vector<int> pathVis(V, 0);  // Keeps track of nodes visited in the current DFS path.
        vector<int> check(V, 0);    // Records whether each node is safe or not.

        // Iterate through all nodes to handle multiple connected components in the graph.
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                // Perform DFS for unvisited nodes to check their safety.
                dfs(i, adj, vis, pathVis, check);
            }
        }

        // Collect all safe nodes into the result vector.
        vector<int> safeNode;
        for (int i = 0; i < V; i++) {
            if (check[i] == 1) {
                safeNode.push_back(i); // Add safe nodes to the result.
            }
        }

        return safeNode; // Return the list of safe nodes.
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
        cout << "~" << "\n";
    }
}