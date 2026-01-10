/*

//  2359. Find Closest Node to Given Two Nodes


//  Problem Statement: 
    -> You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
    -> The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.
    -> You are also given two integers node1 and node2.
    -> Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.
    -> Note that edges may contain cycles.


// Example: 

    Example 1:
        Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
        Output: 2
        Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
        The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.

    Example 2:
        Input: edges = [1,2,-1], node1 = 0, node2 = 2
        Output: 2
        Explanation: The distance from node 0 to node 2 is 2, and the distance from node 2 to itself is 0.
        The maximum of those two distances is 2. It can be proven that we cannot get a node with a smaller maximum distance than 2, so we return node 2.


// Observations: 
        -> You are given a directed graph represented by an edges array, where edges[i] is the node that node i points to. If edges[i] == -1, it means there is no outgoing edge from node i.
        -> Two nodes node1 and node2 are also given.
        -> You need to return the index of the node that is reachable from both node1 and node2, such that:
            -> The maximum of the two distances (from node1 and node2 to that node) is minimized.
            -> If there are multiple such nodes, return the one with the smallest index.
            -> If no such node exists, return -1.
        -> Note: The graph may contain cycles.


    // Approach: 
        -> Convert the edges array to an adjacency list.
            -> Although each node has at most one outgoing edge, representing the graph as an adjacency list simplifies traversal.
        
        -> Run BFS from node1 to compute the shortest distance to all reachable nodes and store it in dist1.
        -> Run BFS from node2 to compute the shortest distance to all reachable nodes and store it in dist2.
        
        -> Compare nodes reachable from both node1 and node2:
            -> For each node i, if it is reachable from both sources (dist1[i] != -1 && dist2[i] != -1):
                -> Compute max(dist1[i], dist2[i]) — the worst-case distance from either node.
                -> Keep track of the node with the smallest such max-distance.
                -> If there's a tie, choose the node with the smallest index.
        -> Return the result node index. If no such node is found, return -1.



// Complexity: 
    -> TC: O(V + E)
    -> SC: O(V)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient BFS & DFS:
class Solution {
private:
    int n;
    vector<int> bfs(int node, vector<vector<int>>& adj) {   // BFS to compute distance:

        vector<int> dist(n, -1);
        queue<int> q;

        q.push(node);


        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            bool isNewLvlFound = false;

            while(size--) {
                int node = q.front();
                q.pop();

                dist[node] = level;

                for(auto &it: adj[node]) {
                    if(dist[it] == -1) {    // not yet explored:
                        q.push(it);
                        dist[it] = level;
                        isNewLvlFound = true;
                    }
                }
            }

            if(isNewLvlFound) level++;
        }

        return dist;
    }
    void dfs(int node, int depth, vector<vector<int>>& adj, vector<int>& dist) {    // DFS to compute distance:
        dist[node] = depth;

        for(auto &ngbr: adj[node]) {
            if(dist[ngbr] == -1) {
                dfs(ngbr, depth + 1, adj, dist);
            }
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        
        // Build Graph adj list:
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            if(edges[i] != -1) {
                adj[i].push_back(edges[i]);
            }
        }

        // Get the shortest distance from both the nodes Using BFS:
        // vector<int> dist1 =  bfs(node1, adj);
        // vector<int> dist2 =  bfs(node2, adj);

        // Get the shortest distance from both the nodes Using DFS:
        vector<int> dist1(n, -1), dist2(n, -1);
        dfs(node1, 0, adj, dist1);
        dfs(node2, 0, adj, dist2);

        // Now compare from shortest distance & find the node having smallest distance to reach both the node:
        int value = INT_MAX;
        int commonNode = -1;   // initially not reachable to any node:
        for(int i = 0; i < n; i++) {
            if(dist1[i] != -1 && dist2[i] != -1)  {
                int shortestDis = max(dist1[i], dist2[i]);
                if(shortestDis < value) {
                    value = shortestDis;
                    commonNode = i;
                }
            }
        }

        return commonNode;
    }
};





// Clean BFS: 
class Solution {
private: 
    int V;
    vector<int> bfs(int src, vector<vector<int>>& adj) {  // return the minimum reachable distance from src to all the other nodes:

        vector<int> dist(V, -1);
        vector<int> vis(V, 0);
        queue<int> q;
        int level = 0;

        q.push(src);
        vis[src] = 1;
        dist[src] = 1;

        while(!q.empty()) {
            int size = q.size();
            bool isNewLvlFound = false;

            while(size--) {
                int node = q.front();
                q.pop();

                dist[node] = level;

                for(auto& ngbr: adj[node]) {
                    if(!vis[ngbr]) {
                        vis[ngbr] = 1;
                        q.push(ngbr);
                        isNewLvlFound = true;
                    }
                }
            }

            if(isNewLvlFound) level++;
        }

        return dist;
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        V = edges.size();
        
        // Build Graph adj list for directed graph:
        vector<vector<int>> adj(V);
        for(int i = 0; i < V; i++) {
            if(edges[i] != -1) {
                adj[i].push_back(edges[i]);
            }
        }

        // Find shortest Distance for node1:
        vector<int> dist1 = bfs(node1, adj);

        // Find shortest Distance from node2:
        vector<int> dist2 = bfs(node2, adj);

        // Compare both the distance & if it's reachable get the minimum:
        int assumedCost = INT_MAX;
        int nearestNode = -1;
        for(int i = 0; i < V; i++) {
            if(dist1[i] == -1 || dist2[i] == -1) continue; // skip unreachable nodes
            int reachingCost = max(dist1[i], dist2[i]); // get the maximum from both:
            if(reachingCost < assumedCost) {
                nearestNode = i;
                assumedCost = reachingCost;
            }
        }

        return nearestNode;
    }
};


// Old Submission:
class Solution {
private: 
    // Function to return the distance of every reachable node from the given source node
    void bfs(int node, vector<vector<int>>& adj, vector<int>& dist, int V) {    // TC: O(V + E)

        queue<pair<int, int>> q;

        dist[node] = 0;
        q.push({0, node});  // lvl, node
        
        while(!q.empty()) {
            auto [lvl, node] = q.front();
            q.pop();

            dist[node] = lvl;

            for(auto &it: adj[node]) {  // iterate in adj nodes
                if(dist[it] == -1) {    // If not visited:
                    dist[it] = 1;
                    q.push({lvl + 1, it});
                }
            }
        }
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int V = edges.size();

        // Build Graph adj list: 
        vector<vector<int>> adj(V);
        for(int i = 0; i < V; i++) {    // given directed graph:    // TC: O(V)
            if(edges[i] != -1) {
                adj[i].push_back(edges[i]);
            }
        }

        // Find nearest distance from node 1:
        vector<int> dist1(V, -1);
        bfs(node1, adj, dist1, V);  // TC: O(V + E)

        // Find nearest distance from node 1:
        vector<int> dist2(V, -1);
        bfs(node2, adj, dist2, V);


        // Compute the minimum distance node, reachable to node1 & node2:
        int ans = INT_MAX;
        int ansIdx = -1;
        for(int i = 0; i < V; i++) {
            // If node i reachable from both node1 & node 2:
            if(dist1[i] != -1 && dist2[i] != -1) {
                int currMax = max(dist1[i], dist2[i]);
                if(currMax < ans) {
                    ans = currMax;
                    ansIdx = i;
                }
            }
        }
        
        if(ansIdx == -1) return -1;   // not reachable
        return ansIdx;  // return the smallest index
    }
};