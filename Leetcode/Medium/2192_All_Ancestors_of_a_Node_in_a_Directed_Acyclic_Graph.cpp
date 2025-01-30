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


// Approach:
    -> We can use dfs/bfs to get the nodes ancestors
    -> After we need to sort them, so that we can return it in order.


// Complexity:
    -> TC: O(V + E)
    -> SC: O(V)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &anc){
        vis[node] = 1;

        // Explore adjacent nodes:
        for(auto it: adj[node]){
            if(!vis[it]){
                anc.push_back(it);  // store the ancestors in result.
                dfs(it, adj, vis, anc);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Build Graph: 
        vector<vector<int>> adj(n);
        for(auto i: edges){
            int u = i[0];
            int v = i[1];
            adj[v].push_back(u);    // reverse the edge:
        }


        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            // Normal DFS Call for every nodes:
            vector<int> vis(n, 0);
            vector<int> anc;    // store the ancestors
            dfs(i, adj, vis, anc);  // dfs call
            
            sort(begin(anc), end(anc));
            ans[i] = anc;
        }

        return ans;
    }
};