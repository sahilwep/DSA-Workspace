/*

//  Geek and F.R.I.E.N.D.S


//  Problem Statement: 
    - Geek is hosting a contest and N students are interested in it. But some of them are friends. Geek wants to make two teams such that no two friends are on the same team.  The task is to check is it possible for the geek two make two teams or not

    - Note:
        1. All the students are numbered from 1 to N.
        2. If A is a friend of B and B is a friend of C, that doesn't mean that A is friend of C

    - Input:
        1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
        2. The first line of each test case contains two space_separated integers N and M.
        3. Next M lines contain two space-separated integers u and v, represents u is a friend of v


    - Output: For each test case, print the "yes" if possible, otherwise print "no" (without quotes). 


//  Observations:
    - No two friends should be together..

    // Approach:
        - It's something like we have to check Bipartite Graph, we can use BFS/DFS to find the bipartite of a given graph.
        - Or we can use DSU to find that wether any two friends are in same group or not?


*/

#include <bits/stdc++.h>
using namespace std;

// --------------------- DSU Way -------------------------------

class DSU {
private: 
    vector<int> size, parent;
public:
    DSU (int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]); // path compression
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;  // already connected
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};


bool f(vector<pair<int, int>> edges, int n) {
    
    // Process Edges & find out Bipartite nature of graph:
    DSU ds(2 * n);
    for(auto &[u, v]: edges) {
        if(ds.ultPar(u) == ds.ultPar(v)) return false;  // If both groups collides..

        // Make Two Group:
        ds.Union(u + n, v); // G1
        ds.Union(u, v + n); // G2
    }
    
    return true;    // graph is bipartite
}


// --------------------- DFS Way -------------------------------
bool dfs(int node, int clr, vector<vector<int>> &adj, vector<int>& colors) {
    colors[node] = clr;   // color that node
    
    for(auto &it: adj[node]) {
        if(colors[it] == -1) {  // not yet colored:
            if(!dfs(it, !colors[node], adj, colors)) return false;
        } else if (colors[it] == colors[node]) {  // already colored & having same color as parent:
            return false;   // found two adjacent node with same colors..
        }
    }
    
    return true;    // every one has separate colors.
}

bool f(vector<pair<int, int>> edges, int n) {
    
    // Build adj list:
    vector<vector<int>> adj(n);
    for(auto it: edges) {
        int u = it.first;
        int v = it.second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // Call for connected-components:
    vector<int> colors(n, -1);   // initially all are '-1', so that we can use it as visited also.
    for(int i = 0; i < n; i++) {
        if(colors[i] == -1) {
            if(!dfs(i, 0, adj, colors)) return false;
        }
    }
    
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edges.push_back({x - 1, y - 1});    // to make 0-based indexing...
    }
    
    if(f(edges, n) == true) cout << "yes\n";
    else cout << "no\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}