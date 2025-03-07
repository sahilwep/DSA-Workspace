/*

//  2192. All Ancestors of a Node in a Directed Acyclic Graph


//  Problem Statement: 
    -> You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).
    -> You are also given a 2D integer array edges, where edges[i] = [from[i], to[i]] denotes that there is a unidirectional edge from from[i] to to[i] in the graph.
    -> Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.
    -> A node u is an ancestor of another node v if u can reach v via a set of edges.

// Example:
    Example 1:

        Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
        Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
        Explanation:
        The above diagram represents the input graph.
        - Nodes 0, 1, and 2 do not have any ancestors.
        - Node 3 has two ancestors 0 and 1.
        - Node 4 has two ancestors 0 and 2.
        - Node 5 has three ancestors 0, 1, and 3.
        - Node 6 has five ancestors 0, 1, 2, 3, and 4.
        - Node 7 has four ancestors 0, 1, 2, and 3.

    Example 2:

        Input: n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
        Output: [[],[0],[0,1],[0,1,2],[0,1,2,3]]
        Explanation:
        The above diagram represents the input graph.
        - Node 0 does not have any ancestor.
        - Node 1 has one ancestor 0.
        - Node 2 has two ancestors 0 and 1.
        - Node 3 has three ancestors 0, 1, and 2.
        - Node 4 has four ancestors 0, 1, 2, and 3.


// Observations: 
    -> We are sure that Graph is DAG.
    -> If we observe the graph carefully, we need to return the ancestors of every nodes..
    -> If we reverse the edge direction of every node, then we can simply traverse & store all the path nodes as ancestors of nodes..


// BruteForce Approach:
    -> Basic & bruteforce solution that comes into our mind in first glance:
        -> Reverse all the edges of graph.
        -> For every node use any traversal algorithm & visit their adjacent nodes..
        -> During the visit any nodes which comes into the path store it as ancestors of that node.

    // Complexity: 
        -> TC: O(V * (V + E))
        -> SC: O(V)
            -> V = total number of Nodes that we have in our graph.



// TopoSort Approach: 
    -> We are sure about the graph that it's DAG (Directed Acyclic Graph)
    -> We can perform TopoSort to find the linearOrdering, which will give us the details of every node that comes after everyOther nodes.
    // Why TopoSort: 
        -> Given graph is DAG -> Sure about no-cycle
        -> Because TopoSort Will give us linear ordering of every Node, which will let us know order in which the nodes are coming, & this details will helps us know about ancestors of every node.
    // Approach:
        -> with topo-sort format, we will maintain set of vector to store ancestors of every nodes:
            -> We will use vector<unordered_set<int>> which will store the ancestors.
        -> When we are explore adjNode of every node:
            -> ancestors[adjNode].insert(node);    // push ancestors of adjNode as Node where it's coming from.
            -> Also make sure to store all the ancestors of that "node" as ancestors of adjNode, using another for loop.

    // Complexity: 
        -> TC: O(V * V*Log(V))
            -> Building adjacency list: O(V+E) (as we iterate over edges)
            -> Computing in-degree: O(V+E) (since we traverse adjacency list)
            -> Topological Sort (BFS): O(V+E) (each node and edge is processed once)
            -> Processing ancestors: 
                -> Worst case, inserting and copying ancestors across nodes can take up to O(V^2) in dense graphs.
                -> Sorting ancestor lists takes O(V*log(V)) per node → total O(V * (V * log(V)))

        -> SC: O(V^2), In worse case Storing ancestors will store all "V - 1" nodes.
            -> Example: 
                adj[] = {{}, {0}, {0, 1}, {0, 1, 2}, {0, 1, 2, 3}, {0, 1, 2, 3, 4}, {0, 1, 2, 3, 4, 5}}
                -> This type of graph will take near to to n^2 space.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution TopoSort:
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for(auto &it: edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);    // reverse the edges:
        }

        // Process Topo-sort:

        vector<int> indegree(n, 0);
        for(int i = 0; i < n; i++) {    // Store all the incoming nodes: 
            for(auto &it: adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {    // Now insert all the "indegree = 0" nodes into queue
            if(!indegree[i]) q.push(i);
        }

        vector<unordered_set<int>> ancestors(n);    // using unorderedSet of vector to store ancestors of every node: (NOTE: we are using set to tackel insertion of duplicate nodes)
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            // Explore adjacent nodes:
            for(auto &adjNode: adj[node]) {
                // Store ancestors of adjNode & ancestors of their ancestors:
                ancestors[adjNode].insert(node); // store parent of the current adjNode

                for(auto &parent: ancestors[node]) {    // store all the ancestors of the parent Node
                    ancestors[adjNode].insert(parent);
                }

                // TopoSort part:
                indegree[adjNode]--;
                if(!indegree[adjNode]) q.push(adjNode);
            }
        }

        // Last Storing all the ancestors into 2D vector:
        vector<vector<int>> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = vector<int>(begin(ancestors[i]), end(ancestors[i]));
            sort(ans[i].begin(), ans[i].end());
        }

        return ans;
    }

};



// BruteForce Approach:
class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &anc){
        vis[node] = 1;  // visit that called node

        // Explore adjacent nodes:
        for(auto it: adj[node]){
            if(!vis[it]){   // if node is not yet visited
                anc.push_back(it);  // store it as ancestors in result.
                dfs(it, adj, vis, anc); // call another dfs to explore further.
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        // Build Graph By reversing the edges:
        vector<vector<int>> adj(n);
        for(auto i: edges){
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);    // reverse the edge:    u ----> v   TO  v ----> u
        }


        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            // DFS Call for every nodes:
            vector<int> vis(n, 0);  // vector to maintain the visited nodes during traversal
            vector<int> anc;    // store the ancestors
            dfs(i, adj, vis, anc);  // call dfs
            
            sort(begin(anc), end(anc)); // sort all the nodes so that it should be in correct order.
            ans[i] = anc;   // store it in our answer
        }

        return ans;
    }
};