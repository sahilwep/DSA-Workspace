/*

//  1462. Course Schedule IV


//  Problem Statement: 
    -> There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.
        -> For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
    -> Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.
    -> You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.
    -> Return a boolean array answer, where answer[j] is the answer to the jth query.

 

// Example: 

    Example 1:
        Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
        Output: [false,true]
        Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
        Course 0 is not a prerequisite of course 1, but the opposite is true.

    Example 2:
        Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
        Output: [false,false]
        Explanation: There are no prerequisites, and each course is independent.

    Example 3:
        Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
        Output: [true,true]


// Observations: 
    1. Dependencies:
        -> The prerequisites define a directed graph where an edge (a -> b) means "a must be completed before b."

    2. Indirect Dependencies:
        -> If course 'a' is a prerequisite for course 'b', and course 'b' is a prerequisite for course 'c', then course 'a' is also a prerequisite for course 'c'.
        -> This implies transitive closure in the graph.

    3. Key Subtasks:
        -> Determine if a path exists from course 'u' to course 'v' in the graph for each query.
        -> Ensure we account for direct and indirect dependencies.


// Approach:
    1. Graph Representation:
        -> Represent the prerequisites as a directed graph using an adjacency list.

    2. Topological Sort:
        -> Use Kahn's Algorithm to obtain the topological order of the graph.
        -> This gives a linear ordering of courses based on their dependencies.

    3. Reachability Check:
        -> Use Depth-First Search (DFS) to determine if a path exists from course 'u' to course 'v'.

    4. Query Answering:
        -> For each query [u, v]:
            -> Ensure 'u' appears before 'v' in the topological order (a prerequisite cannot appear after its dependent).
            -> Check if 'v' is reachable from 'u' in the graph.


// Edge Cases:
    1. No prerequisites: If `prerequisites` is empty, all queries will return false.
    2. Cycles in the Graph: If the graph contains cycles, the problem guarantees it is invalid input, as it would contradict the topological ordering.
    3. Independent Nodes: If a course is not connected to any other course, queries involving that course will always return false unless it queries itself.

// Complexity:
    -> TC: O(V + E + (Q * V))
        -> O(V + E) -> For directed graph, to perform topo-sort
        -> O(V) -> For DFS
        -> O(Q * V) -> For every queries, we are usign DFS
                -> V = vertices
                -> E = directed edges
                -> Q = queries.size()
    
    -> SC: O(V + E)
        -> For every Edges, we have this much node in queue.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function to perform DFS and check if 'dest' is reachable from 'node'
    bool dfs(int node, int dest, vector<int> &vis, vector<vector<int>> &adj) {  // TC: O(V), in worse case, it will visit all the nodes..
        vis[node] = 1; // Mark the current node as visited
        if (node == dest) return true; // If the destination node is found, return true

        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (dfs(neighbor, dest, vis, adj)) return true; // Recursively check the neighbors
            }
        }
        return false; // Destination not reachable from this node
    }

public:
    vector<bool> checkIfPrerequisite(int V, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) { // TC: O(V + E + (Q * V))
        int qSize = queries.size();
        vector<bool> ans(qSize, false); // Initialize the answer array with false

        // Edge case: If there are no prerequisites, all answers remain false
        if (prerequisites.empty()) return ans;

        // Step 1: Build adjacency list for the graph
        vector<vector<int>> adj(V);
        for (auto &edge : prerequisites) {
            adj[edge[0]].push_back(edge[1]);
        }

        // Step 2: Perform Topological Sort using Kahn's Algorithm: O(V + E), directed graph.
        vector<int> indegree(V, 0); // Initialize indegree array
        for (int i = 0; i < V; i++) {
            for (auto neighbor : adj[i]) {
                indegree[neighbor]++;
            }
        }

        queue<int> q; // Queue to store nodes with 0 indegree
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> topo; // List to store the topological ordering
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node); // Add the current node to the topo list

            for (auto neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Edge case: If there's a cycle, the topo list will be incomplete
        if (topo.size() != V) return ans;

        // Step 3: Preprocess the TopoSort List to track each node's position
        unordered_map<int, int> topoPosition; // Map: node -> position in topological order
        for (int i = 0; i < topo.size(); i++) {
            topoPosition[topo[i]] = i;
        }

        // Step 4: Process each query: O(Q * V), Q = queries.size(), V = Vertices.
        for (int i = 0; i < qSize; i++) {
            int u = queries[i][0]; // Start node
            int v = queries[i][1]; // End node

            // Ensure u appears before v in the topological order
            int uLocation = topoPosition[u];
            int vLocation = topoPosition[v];

            // Check if v is reachable from u using DFS
            vector<int> vis(V, 0); // Visited array for DFS
            bool isReachable = dfs(u, v, vis, adj);

            // Update answer if both conditions are satisfied
            ans[i] = (uLocation < vLocation && isReachable);
        }

        return ans; // Return the final answers for all queries
    }
};
