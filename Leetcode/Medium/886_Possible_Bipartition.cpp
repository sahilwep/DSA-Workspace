/*

//  886. Possible Bipartition


//  Problem Statement: 
    -> We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.
    -> Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, 
    -> return true if it is possible to split everyone into two groups in this way.

 
// Example: 

    Example 1:
        Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
        Output: true
        Explanation: The first group has [1,4], and the second group has [2,3].

    Example 2:
        Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
        Output: false
        Explanation: We need at least 3 groups to divide them. We cannot put them in two groups.


// Observation:
    -> given n nodes 1 to n
    -> given edges dislikes, which specifies that these two nodes didn't need to be in same group.
    -> we need to split n nodes into two groups, such that given dislike should be followed

    // DSU Approach: 
        -> DSU will help us to distribute the given nodes into two groups.
        -> Also DSU will help us to know about the nodes ultimate parent whether they are same or not?
        -> We are given constrains of dislike 10^4, create DSU of size (2 * 1e4 + 1)
        -> Process edges & check wether they share common ultimate parent or not?
        -> if so, return false, can't split into two groups..


    // Complexity: 
        -> TC: O(K)
            -> k = dislikes.size()
        -> SC: O(n)
            -> n = total number of nodes.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class DSU {
private: 
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]);
    }
    void Union(int u, int v) {
        int ulp_u = ultPar(u);
        int ulp_v = ultPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        DSU ds(2 * 1e4 + 1);

        for(auto &it: dislikes) {
            int u = it[0], v = it[1];
            if(ds.ultPar(u) == ds.ultPar(v)) return false;  // if both the nodes falls into the same group -> return false;

            // Split both of them into two groups:
            // u => G1
            // v => G2

            ds.Union(u, v + 1e4);   // G1
            ds.Union(v, u + 1e4);   // G2
        }

        return true;
    }
};