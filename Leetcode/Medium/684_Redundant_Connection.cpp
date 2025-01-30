/*

//  684. Redundant Connection


//  Problem Statement: 
    -> In this problem, a tree is an undirected graph that is connected and has no cycles.
    -> You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
    -> Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
 

// Examples: 
    Example 1:

        Input: edges = [[1,2],[1,3],[2,3]]
        Output: [2,3]

    Example 2:

        Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
        Output: [1,4]

// Observations: 
    -> We are given tree of size 'n-1' nodes, where we have given one extra edges that make a cycle of the structure..
    -> We need to find that edge, which made the cycle, & remove that edge from the graph to make tree a single components
    -> we need to return that edge what was last in input, which were from cycle.
    -> If there's no edge that connects tree to a cycle, we will return empty vector.


// Approach: 
    -> we can start building the graph, while we check whether that node is reachable or not, Using any traversal algorithm BFS/DFS.
    -> If that node is reachable, means that will be our edge that connects two nodes & form cycle, & We will return that edges.
    -> We can use any traversal algorithm like BFS/DFS to find dest node wether present or not?

// Complexity: 
    -> TC: O(n^2)
    -> SC: O(n),    due to visited array.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
    bool dfs(int start, int dest, vector<vector<int>> &adj, vector<int> &vis){
        if(start == dest) return 1;

        vis[start] = 1;

        for(auto it: adj[start]){
            if(!vis[it]){
                if(dfs(it, dest, adj, vis)) return true;
            }
        }

        return false;
    }
    bool bfs(int start, int dest, vector<vector<int>> &adj, vector<int> &vis){    // in worse case, TC: O(n), visiting every nodes at-max once
        if(start == dest) return 1;

        vis[start] = 1;  // mark that node as visited.
        queue<int> q;
        q.push(start);   // push that starting node, & parent as -1, in queue
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            if(node == dest) return true;

            // Check their adjacent nodes:
            for(auto adjNode: adj[node]){
                if(!vis[adjNode]){
                    vis[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
        
        return false;

    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        // Build Adj list:
        vector<vector<int>> adj(V+1);

        for(auto it: edges){    // TC: O(n * n) = O(n^2)
            int u = it[0];
            int v = it[1];

            // Query everytime & build graph:
            vector<int> vis(V+1, 0);
            // bool isRedundant = bfs(u, v, adj, vis);  
            bool isRedundant = dfs(u, v, adj, vis);
            
            if(!isRedundant){
                adj[u].push_back(v);
                adj[v].push_back(u);
            }else{
                return {u, v};
            }
        }

        return {};
    }
};