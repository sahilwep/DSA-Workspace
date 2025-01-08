/*

//  G-25. Find Eventual Safe States - BFS - Topological Sort 



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


        //  In a directed graph:
            -> Eventual safe nodes are those nodes that can only reach terminal nodes (nodes with no outgoing edges) or other safe nodes.
            -> A node is unsafe if it is part of or can lead to a cycle.



// Key Intrusion: Reverse Topological Sort

    -> The algorithm employs a reverse approach:
    
        // Reversing the Graph:
            -> To simplify determining safe nodes, the edges of the graph are reversed. In the reversed graph:
                -> Terminal nodes in the original graph become sources (indegree = 0).
                -> Traversing from these sources backward allows us to mark all nodes that eventually lead to terminal nodes.

        // Indegree Concept:
            -> Indegree represents the number of incoming edges for a node.
            -> Nodes with an indegree of 0 are safe terminal nodes in the reversed graph.

        // Queue-Based Processing:
            -> A queue is used to perform a breadth-first traversal (BFS) of the reversed graph.
            -> Starting with nodes that have indegree 0, the algorithm processes and reduces the indegree of their neighbors:
                -> If a neighbor's indegree becomes 0, it is added to the queue, as it can only lead to safe nodes.

        // Safety Propagation:
            -> By iteratively processing nodes with indegree 0, the algorithm effectively propagates safety backward.
            -> This ensures all nodes leading to terminal nodes are marked as safe.

        // Sorting the Results:
            -> Sorting ensures the safe nodes are returned in ascending order, as required.



// Approach:
    -> We know that how we can find a cycle usign BFS, We will use TopoSort for that.
    -> Safe node -> Nodes ends at terminal node
    -> Initially Reverse all the edges
    -> Now apply TopoSort:
        -> Get all the nodes with indegree = 0
        -> do removal of edges on adjacent nodes
        -> Figure out indegree -> Anyone with indegree = 0, will be considered as terminal node
        -> Apply TopoSort
            -> Define queue DS
            -> Initially Putup that node that has indegree = 0
            -> while queue is not empty:
                -> get the node store it in safeNode result
                -> iterate that node adjacent nodes
                    -> decrement indegree of that adjacent node.
                    -> if it's become 0, put it into queue.
            -> last sort that safeNodes & return the result.


// Complexity:
    -> TC: O(V + E)
    -> SC: O(V + E)


*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // Step 1: Reverse the graph and calculate the indegree of each node
        // adjRev will store the reversed graph where edges point in the opposite direction.
        vector<int> adjRev[V]; // Adjacency list for the reversed graph
        vector<int> indegree(V, 0); // Stores the indegree (number of incoming edges) for each node
        
        // Iterate through the original adjacency list to reverse the edges
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                adjRev[it].push_back(i); // Reverse the edge: i -> it becomes it -> i
                indegree[i]++; // Increment indegree for node i
            }
        }
        
        // Step 2: Identify terminal nodes (nodes with indegree 0)
        queue<int> q; // Queue to process nodes with indegree 0
        vector<int> safeNodes; // Vector to store eventual safe nodes
        
        // Push all nodes with indegree 0 into the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Step 3: Perform a reverse topological sort
        while (!q.empty()) {
            int node = q.front(); // Get the front node from the queue
            q.pop(); // Remove the node from the queue
            safeNodes.push_back(node); // Mark the node as safe
            
            // Reduce the indegree of all adjacent nodes in the reversed graph
            for (auto it : adjRev[node]) {
                indegree[it]--; // Decrement indegree of the adjacent node
                if (indegree[it] == 0) { // If indegree becomes 0, add it to the queue
                    q.push(it);
                }
            }
        }
        
        // Step 4: Sort the list of safe nodes in ascending order
        // Sorting ensures the result is returned in the required order
        sort(safeNodes.begin(), safeNodes.end());
        
        // Step 5: Return the list of safe nodes
        return safeNodes;
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
        cout << endl << "~" << "\n";
    }
}

