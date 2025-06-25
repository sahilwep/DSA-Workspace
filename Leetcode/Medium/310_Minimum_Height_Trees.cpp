/*

//  310. Minimum Height Trees


//  Problem Statement: 
    -> A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.
    -> Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).
    -> Return a list of all MHTs' root labels. You can return the answer in any order.
    -> The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.


// Example: 
    Example 1:
        Input: n = 4, edges = [[1,0],[1,2],[1,3]]
        Output: [1]
        Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.

    Example 2:
        Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
        Output: [3,4]


        
// BruteForce Solution:
    -> Given Undirected edges
    -> we have to find the minimum depth, reachable from which node
    -> If we have multiple nodes, return all of them in any order...

    
    // Approach: 
        -> Run BFS from every nodes.
        -> get the nodes which have minimum nodes count..


    // Complexity: 
        -> TC: O(V * (V + 2E))



// Efficient Solution: 
    -> Tree: A graph that contains no cycles.
    -> From the given tree graph, we need to find the Minimum Height Trees (MHTs).
    -> MHT: A node from which the tree has the smallest possible height.
        -> This simply means we cannot select a leaf node.
        -> To achieve the minimum possible depth, we need to consider nodes near the core of the tree.
    -> Try analyzing every node: 
        -> Look at the indegree of each node.
        -> Leaf nodes have an indegree of 1 (only one connection).


    // Key Observation: 
        -> When the tree has an odd number of nodes, only one root node is possible.
        -> When the tree has an even number of nodes, two root nodes are possible.


    // Intuition: 
        -> Continuously collect all current leaf nodes and eliminate them.
        -> Repeat the process: gather the next set of leaf nodes and remove them.
        -> Keep doing this until we reach the core nodes of the tree.


    // Solution: 
        -> Start by processing the leaf nodes and iteratively move towards the tree's core by eliminating them.
        -> Continuously check for leaf nodes, which have an indegree of 1.

        -> Use BFS to eliminate leaf nodes level by level until only the core remains.
        -> If we're left with 1 or 2 nodes, we break the loop and return them as the answer.
        -> This is because, in a tree with no cycles, there can be at most 2 possible root nodes when the number of nodes is even.

    // Complexity: 
        -> TC: O(V + 2E) -> BFS
        -> SC: O(V + 2E) -> adj list


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Cleaner Version: 
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // Edge case: only one node
        if(n == 1) return {0};


        // Step 1: Build graph and indegree array
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        // Step 2: Initialize queue with all leaf nodes (indegree == 1)
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if (indegree[i] == 1) q.push(i);
        }


        // Step 3: Perform level-order trimming of leaves
        while(n > 2) {
            int leafCount = q.size();
            n -= leafCount;

            while(leafCount--) {
                int leaf = q.front();
                q.pop();

                for(int neighbor : adj[leaf]) {
                    indegree[neighbor]--;

                    // If this neighbor becomes a leaf, add to queue
                    if(indegree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        // Remaining nodes in queue are the MHT roots
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};


// Efficient OverExplained Version:
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n == 1) return {0};  // only one root possible itself..
        
        // Build graph adj list & Store the indegree of every node: 
        vector<vector<int>> adj(n);
        vector<int> ind(n, 0);
        for(auto &it: edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

            ind[u]++;
            ind[v]++;
        }   

        // Store all the leaf node into queue:
        queue<int> q;
        for(int i = 0; i < n; i++) {
            // indegree = 1, is our leaf node:
            if(ind[i] == 1) {
                q.push(i);
            }
        }

        // If we have 2 or less node left, break out for root node conditions
        while(n > 2) {
            int size = q.size();    // get the each level size  
            n -= size;  // subtract the node which are processed in BFS

            // Process BFS Level-by-Level
            while(size--) {
                int u = q.front();  // get the leaf node
                q.pop();

                // explore adjacent to all the leaf nodes
                for(auto &v: adj[u]) {
                    ind[v]--;   // decrement the adjacent node indegree, as we are removing their adjacent leaf node..

                    // Now these adjacent node becomes leaf node, So push it into the queue.
                    if(ind[v] == 1) q.push(v);
                }
            }
        }

        // Last push all the remaining roots into our answer:
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};


// BruteForce Clear: 
class Solution {
private:
    int bfs(int node, vector<vector<int>>& adj, int V) {    // function to return the maximum lvl from the given graph configurations:
        vector<int> vis(V, 0);
        queue<int> q;

        q.push(node);
        vis[node] = 1;
        int lvl = 1;

        while(!q.empty()) {
            int size = q.size();
            bool isLvlFound = false;
            
            while(size--) {
                int node = q.front();
                q.pop();

                for(auto &it: adj[node]) {
                    if(!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                        isLvlFound = true;
                    }
                }
            }

            if(isLvlFound) lvl++;
        }

        cout << lvl << " ";
        return lvl;
    }
public:
    vector<int> findMinHeightTrees(int V, vector<vector<int>>& edges) {

        // Build graph adj list: Undirected graph:
        vector<vector<int>> adj(V);
        for(auto &it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // Build answer: 
        vector<int> ans;
        int minHeight = INT_MAX;
        for(int i = 0; i < V; i++) {
            int height = bfs(i, adj, V);

            if(height < minHeight) {
                minHeight = height;
                ans.clear();
                ans.push_back(i);
            } else if (height == minHeight) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};


// BruteForce Solution: 
class Solution {
private: 
    int bfsLvl(int node, vector<vector<int>>& adj, int V) {
        vector<int> vis(V, 0);
        queue<pair<int, int>> q;

        q.push({0, node});
        vis[node] = 1;

        int maxLvl = 0;
        while(!q.empty()) {
            auto [lvl, node] = q.front();
            q.pop();

            maxLvl = max(maxLvl, lvl);

            // Explore adj nodes: 
            for(auto &it: adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push({lvl + 1, it});
                }
            }
        }

        return maxLvl;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        // Build graph adj list: 
        vector<vector<int>> adj(n);
        for(auto &it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        // Get the minimum lvl for each levels:
        vector<int> lvl(n);
        for(int i = 0; i < n; i++) {
            lvl[i] = bfsLvl(i, adj, n);
        }

        // Compute answer:
        vector<int> ans;
        int minLvl = INT_MAX;   // inital assumption to compute the minimum answer

        for(int i = 0; i < n; i++) {
            if(lvl[i] < minLvl) {
                minLvl = lvl[i];
                ans.clear();
                ans.push_back(i);
            } else if(lvl[i] == minLvl) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};