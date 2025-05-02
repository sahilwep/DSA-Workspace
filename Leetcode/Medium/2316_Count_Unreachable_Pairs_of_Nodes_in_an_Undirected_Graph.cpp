/*

//  2316. Count Unreachable Pairs of Nodes in an Undirected Graph


//  Problem Statement: 
    -> You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
    -> Return the number of pairs of different nodes that are unreachable from each other.

 

// Example: 
    Example 1:
        Input: n = 3, edges = [[0,1],[0,2],[1,2]]
        Output: 0
        Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.

    Example 2:
        Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
        Output: 14
        Explanation: There are 14 pairs of nodes that are unreachable from each other:
        [[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
        Therefore, we return 14.


// Observations: 
    -> Given n nodes & edges {u, v} => Undirected graph
    -> Find the total number of pairs of different nodes that are unreachable from each other.

    // Example: 

                Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
                Output: 14
                
                <Ultimate parent : size>
                    0            :  4
                    3            :  1
                    1            :  2

                
            -> Total Pairs: 

                -> All possible size pairs: (4 * 1) + (4 * 2) + (2 * 1)


            // Efficient way to find pairs:  Use Running Sum to Count Unreachable Pairs

                rem = 7 => Total number of nodes
                sum = 0
                    4:
                        rem = 7 - 4 = 3
                        sum += 3 * 4 = 12
                    1:
                        rem = 3 - 1 = 2
                        sum += 2 * 1 = 12 + 2 => 14
                    2:
                        rem = 2 - 2 = 0
                        sum += 0 * 1 = 14

    // DSU Solution: 
        -> connect nodes & form components
        -> get the size of every components & generate pairs.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Way: TC: O(V + E)
class DSU {
private:
    vector<int> parent, size;
public:
    DSU (int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]); // path compression
    }   
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;  // already connected components
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
    int getSize(int x) {
        return size[ultPar(x)];
    }
};

class Solution {
typedef long long ll;
public:
    long long countPairs(int n, vector<vector<int>>& edges) {

        DSU ds(n);

        // Step 1: merge node & form Components
        for(auto &it: edges) {
            ds.Union(it[0], it[1]);
        }
        
        // Step 2: get the total size of every components: 
        vector<int> compSize;
        for(int i = 0; i < n; i++) {
            if(ds.ultPar(i) == i) compSize.push_back(ds.getSize(i));
        }

        // Generate all possible pairs from compSize:
        int rem = n;
        ll ans = 0;
        int cSz = compSize.size();
        for(int i = 0; i < cSz; i++) {
            rem = rem - compSize[i];
            ans += (ll)compSize[i] * rem;
        }
        
        return ans;
    }
};



// BruteForce: 
class DSU {
private:
    vector<int> parent, size;
public:
    DSU (int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]); // path compression
    }   
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;  // already connected components
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
    int getSize(int x) {
        return size[ultPar(x)];
    }
};

class Solution {
typedef long long ll;
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DSU ds(n);

        // Step 1: merge node & form Components
        for(auto &it: edges) {
            ds.Union(it[0], it[1]);
        }
        
        // Step 2: get the total size of every components: 
        vector<int> compSize;
        for(int i = 0; i < n; i++) {
            if(ds.ultPar(i) == i) compSize.push_back(ds.getSize(i));
        }

        // Generate all possible pairs from compSize:
        int cmpSize = compSize.size();
        ll ans = 0;
        for(int i = 0; i < cmpSize; i++) {
            for(int j = i + 1; j < cmpSize; j++) {
                ans += ((ll)compSize[i] * (ll)compSize[j]);
            }
        }
        
        return ans;
    }
};