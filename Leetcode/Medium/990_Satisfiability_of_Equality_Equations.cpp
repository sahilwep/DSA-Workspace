/*

//  990. Satisfiability of Equality Equations


//  Problem Statement: 
    -> You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and 
    -> takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.
    -> Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

 
// Example: 
    Example 1:
        Input: equations = ["a==b","b!=a"]
        Output: false
        Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
        There is no way to assign the variables to satisfy both equations.

    Example 2:
        Input: equations = ["b==a","a==b"]
        Output: true
        Explanation: We could assign a = 1 and b = 1 to satisfy both equations.


// Observations: 
    -> Given equations:
        -> {x == y} & {X != y}, we have to check satisfies conditions for the given equations
        -> If all the given equations satisfies, return true else return false
        -> equations[i] is of length 4


    // Approach 1: DSU Solutions  => More Efficient
        -> First connect all the given "==" conditions
        -> Then check "!=" for all the given conditions, if it's already connected, return false: else return true

        // Complexity: 
            -> TC: O(equations.size()) 
            -> SC: O(1)


    // Approach 2: DFS/BFS Solutions: 
        -> First we have to build adj list: for "==" conditions
        -> Second check all the "!=" case for u & v reachable or not using any DFS / BFS.
        
        // Complexity: 
            -> TC: O(equations.size() + (26 * E))
                -> equations.size() = For build adj list
                -> 26 node in total we have
                -> E = number of edges with conditions "!="
            -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Approach 1: DSU Solutions
class DSU {
private: 
    vector<int> size, parent;
public: 
    DSU (int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node; 
        return parent[node] = ultPar(parent[node]);  // path compression..
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;  // already connected
        // Connect smaller component to larger ones
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        
        DSU ds(26); // because given characters are of alphabets 26 letters

        // Step 1: Connect all the given statement that has "==" equations
        for(auto& s: equations) {
            int u = s[0] - 'a';
            int v = s[3] - 'a';
            char eq = s[1];
            // Connect that node u & v:
            if(eq == '=') {
                ds.Union(u, v);
            }
        }

        // Step 2: Check the given Statement that has "!=" equations: 
        for(auto& s: equations) {
            int u = s[0] - 'a';
            int v = s[3] - 'a';
            char eq = s[1];
            // If given conditions is saying both should not be in same components: 
            if(eq == '!') {
                if(ds.ultPar(u) == ds.ultPar(v)) return false;  // Conditions given conditions fails here..
            }
        }

        return true;    // all conditions satisfies
    }
};


//  Approach 2: BFS/DFS Solutions

class Solution {
private: 
    bool dfs(int node, int dst, vector<vector<int>>& adj, vector<int>& vis) {
        if(node == dst) return true;
        vis[node] = 1;  // mark that node as visited

        // Explore neighbors:
        for(auto& it: adj[node]) {
            if(!vis[it]) {
                if(dfs(it, dst, adj, vis)) return true;
            }
        }

        return false;   // never reaches to destinations.
    }
    bool bfs(int node, int dst, vector<vector<int>>& adj, vector<int>& vis) {
        queue<int> q;

        q.push(node);
        vis[node] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            if(node == dst) return true;    // Reaches to destinations.

            // Explore neighbors: 
            for(auto& it: adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return false;   // never reaches to destinations
    }
public:
    bool equationsPossible(vector<string>& equations) {

        // Step 1: Build Adj list: 
        vector<vector<int>> adj(26);    // at max we can have 26 nodes
        for(auto& s: equations) {
            int u = s[0] - 'a';
            int v = s[3] - 'a';
            char eq = s[1];
            // Connect that node u & v:
            if(eq == '=') {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        // Step 2: Try visiting all the restricted nodes: 
        for(auto& s: equations) {
            int u = s[0] - 'a';
            int v = s[3] - 'a';
            char eq = s[1];
            // Connect that node u & v:
            if(eq == '!') {
                vector<int> vis(26, 0);
                if(bfs(u, v, adj, vis)) return false;   // path is possible, conditions fails here
                // if(dfs(u, v, adj, vis)) return false;   // path is possible, conditions fails here
            }
        }

        return true;    // all conditions satisfies
    }
};