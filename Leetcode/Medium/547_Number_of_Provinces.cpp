/*

//  547. Number of Provinces


//  Problem Statement: 
    -> There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
    -> A province is a group of directly or indirectly connected cities and no other cities outside of the group.
    -> You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
    -> Return the total number of provinces.


// Example:
    Example 1:
        Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
        Output: 2

    Example 2:
        Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
        Output: 3



// Observations: 
    -> Given adj matrix:
    -> Undirected graph.
    -> Given edge u -- v
    -> with DSU we can find the total number of connected components.
    

    // Normal DFS/BFS Traversal Based Solution:


        -> we are given adj matrix of undirected graph.
        -> we need to find the number of provence..

                   0 1 2
                0 [1,1,0]
                1 [1,1,0]
                2 [0,0,1]

        -> Given 1-based index

        // Complexity:
            -> TC: O(n * n) => O(n^2)
            -> SC: O(n), for visited array.


    // DSU Based Solution:
        -> First process all the edges into DSU.
        -> Last count the number of total unique ultimate parent.

        // How DSU will help us to know the total number of connected components.
            -> DSU will tells us every node ultimate parent.
            -> In other words we can count the total number of unique parent in all the graph..


        // Complexity:
            -> TC: O(n^2 * alpha(n)) => O(n), because α(N) (the inverse Ackermann function) is very close to 1 for all practical values of NN.
            -> SC: O(n^2)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/* ----------------------------------------------------------------------------------------------- */

// DSU Based Solution 2: More Cleaner & Optimal
class DisjointSet {
private:
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i < n + 1; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUltPar(int node) {
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = findUltPar(parent[node]); // with path compression.
    }
    void unionBySize(int u, int v) {
        // get ultimate parent:
        int ulp_u = findUltPar(u);
        int ulp_v = findUltPar(v);

        // Now check whether they were in same component or not?
        if(ulp_u == ulp_v) return;

        // Else connect smaller to larger:
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n);

        // Directly iterate in given matrix, no need to form edges:
        // Only Process Diagonally half of the matrix: because it's undirected graph:
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {    // Iterate only once for undirected graph
                if(grid[i][j]) {
                    // join given tow index i & j
                    ds.unionBySize(i + 1, j + 1);   // because of 1-based indexing
                }
            }
        }

        // Now Count total Number of Unique Parent:
        unordered_set<int> st;
        for(int i = 1; i < n + 1; i++) {
            st.insert(ds.findUltPar(i));
        }

        return st.size();
    }
};

/* ----------------------------------------------------------------------------------------------- */

// DSU Based Solution 1: Naive Implementations
class DisjointSet {
private:
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i < n + 1; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUltPar(int node) {
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = findUltPar(parent[node]); // with path compression.
    }
    void unionBySize(int u, int v) {
        // get ultimate parent:
        int ulp_u = findUltPar(u);
        int ulp_v = findUltPar(v);

        // Now check whether they were in same component or not?
        if(ulp_u == ulp_v) return;

        // Else connect smaller to larger:
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> edges;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    edges.push_back({i+1, j+1});
                }
            }
        }

        // Now process it with DSU:
        int edgSize = edges.size();
        DisjointSet ds(n);
        unordered_set<int> st;

        for(int i = 0; i < edgSize; i++) {
            int u = edges[i].first;
            int v = edges[i].second;

            int ulp_u = ds.findUltPar(u);
            int ulp_v = ds.findUltPar(v);

            if(ulp_u != ulp_v) {
                ds.unionBySize(u, v);
            }
        }

        // Now count ultimate parent:
        for(int i = 1; i < n + 1; i++) {
            st.insert(ds.findUltPar(i));    // find ultimate parent of all the nodes:
        }

        return st.size();
    }
};

/* ----------------------------------------------------------------------------------------------- */

// Graph DFS/BFS Based Solution:    
class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {    // DFS Traversal:
        vis[node] = 1;

        for(auto &it: adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }
    void bfs(int node, vector<vector<int>> &adj, vector<int> &vis) {    // BFS Traversal:
        queue<int> q;
        q.push(node);
        vis[node] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto &it: adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;

                    q.push(it);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // Construct Graph adj-list from given undirected graph:
        vector<vector<int>> adj(n); 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // Iterate for number of comopenents:
        vector<int> vis(n, 0);
        int comp = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                comp++;
                dfs(i, adj, vis);
                // bfs(i, adj, vis);
            }
        }

        return comp;
    }
};