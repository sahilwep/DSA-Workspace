/*

//  2492. Minimum Score of a Path Between Two Cities


//  Problem Statement: 
    -> You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distance[i]. The cities graph is not necessarily connected.
    -> The score of a path between two cities is defined as the minimum distance of a road in this path.
    -> Return the minimum possible score of a path between cities 1 and n.

// Note:
    -> A path is a sequence of roads between two cities.
    -> It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
    -> The test cases are generated such that there is at least one path between 1 and n.

 
// Example:

    Example 1:

        Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
        Output: 5
        Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
            It can be shown that no other path has less score.

    Example 2:

        Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
        Output: 2
        Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.


// Observations: 
    -> We are given undirected weighted graph.
    -> we need to find the minimum edge weight from all the part that leads to source(1) to dest(n)
    -> If we observe carefully, we can easily cost with any graph traversal algorithm..
    

    // BFS/DFS Approach:
        -> We can use any traversal algorithm and find the weight of node which comes in the traversal:

        NOTE: We need to compare all the edgeWeight even if the node is already visited, means there can be some edge weight which may miss-out, so we need to take care of that also..

        // Complexity BFS/DFS: 
            -> TC: O(n + m)
            -> SC: O(n + m)

    // Key Observations:
        -> If we are starting from node 1 & explore all the path that leads to destinations 'n', and we find the smallest edge weight, let say 'x'.
        -> And there is another edge b/w two nodes whose weight is lesser than the 'x', So, we can't choose this even if it's lesser than 'x', because this can be distinguished as another part of the whole graph..
        -> In Simple, Graph can have multiple components, So, we need to choose those components only whose contains path 1 to n & from that components we need to choose the smallest edge weight.


    // DSU Approach:
        -> If we carefully observe this question, this can easily be solved using DSU, because we need to check the minimum edge weight in a single component that contains src(1) & dst(n)
        // Approach:
            -> First connected all the graph nodes u & v with union.
            -> Then get the ultimate parent of node (1), which is our source.
            -> Then one more time process all the edges & store the minimum edge weight which were the part of source ultimate parent.

        // Complexity: 
            -> TC: O(n⋅α(n)) ≈ O(n)
            -> SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// DSU Solutions:
class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = ultPar(parent[node]);
    }
    void Union(int u, int v) {
        int ulp_u = ultPar(u);
        int ulp_v = ultPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        DisjointSet ds(n);

        // first connect all the components:
        for(auto &it: roads) {
            int u = it[0], v = it[1];
            ds.Union(u, v);
        }

        int ulpOfSrc = ds.ultPar(1);  // get the ultimate parent of Src node '1'
        
        // Now get the Minimum edge weight by comparing the ultimate parent of source node:
        int ans = INT_MAX;
        
        for(auto &it: roads) {
            int u = it[0], v = it[1], wt = it[2];

            // Find Ultimate parent of u OR v any:
            int ulp_u = ds.ultPar(u);

            // Store the answer with comparing ultimate parent of source:
            if(ulp_u == ulpOfSrc) {
                ans = min(ans, wt); // store the minimum weight:
            }
        }

        return ans;
    }
};


/* -------------------------------------------------------------------------------- */

// DFS/BFS Solutions:
class Solution {
private:
    int bfs(int node, vector<vector<pair<int, int>>> adj, vector<int> &vis) {   // BFS Solution Accepted.
        
        queue<int> q;

        q.push(node);
        vis[node] = 1;

        int ans = INT_MAX;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto &it: adj[node]) {
                int v = it.first, wt = it.second;
                ans = min(ans, wt); // store answer doesn't matter it's visited or not, if it's the part of the component, store the answer.
                // If node is not yet visited, visit them & store it in queue
                if(!vis[v]) {
                    vis[v] = 1;

                    q.push(v);
                }
            }
        }

        return ans;
    }
    int dfs(int node, vector<vector<pair<int, int>>> adj, vector<int> &vis) {   // DFS Solution: Gives MLE
        vis[node] = 1;

        int ans = INT_MAX;

        for(auto &it: adj[node]) {
            if(!vis[it.first]) {
                ans = min(ans, dfs(it.first, adj, vis));    // get the minimum from all the child calls.
            }
            ans = min(it.second, ans);  // last compare it with node weight that are already visited..
        }

        return ans;
    }   
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto &i: roads) {
            int u = i[0], v = i[1], wt = i[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> vis(n + 1, 0);
        int ans = bfs(1, adj, vis);
        // int ans = dfs(1, adj, vis);

        return ans;
    }
};