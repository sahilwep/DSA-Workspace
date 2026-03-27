/*

//  1361. Validate Binary Tree Nodes


//  Problem Statement: 
    - You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], 
    - return true if and only if all the given nodes form exactly one valid binary tree.
    - If node i has no left child then leftChild[i] will equal -1, similarly for the right child.
    - Note that the nodes have no values and that we only use the node numbers in this problem.

 
// Example:
    Example 1:
        Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
        Output: true

    Example 2:
        Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
        Output: false

    Example 3:
        Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
        Output: false




// Observation:
    - We are asked to find the given tree is binary tree or not?
    - we are given n nodes.
    - We are given left_child & right_child, for every node i
    - In Binary Tree:
        - Every node has one parent.
        - Indegree will help us to find the ancestors.
            - Any node that violates the rule of binary tree, single parent (indegree <= 1): return false.
            - Example:

                    [0]
                    /
                   ↙  
                  [1]   [2]
                   \     /
                    ↘   ↙
                     [3]

        - DSU Will help us compute the binary tree:
            - If tree has cycle.
            - Using indegree, we can compute the multiple parent.
            - It can be possible that tree can be separated in multiple components.

                                      [0]
                                      / \
                                    ↙     ↘
                                  [1]     [2]

                                      [3]
                                      / \
                                    ↙     ↘
                                  [4]     [5]

            - Using DSU we can find the total number of components.
                - If graph is distributed in multiple components => return false.

    // Complexity:
        - TC: O(n)
        - SC: O(n)
            - n = total number of nodes.



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


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
        return parent[node] = ultPar(parent[node]); // path compression.
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;  // already connected.

        // connect smaller group to larger ones:
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
    int getSize(int x) {    // func to return each nodes ultimate parent size.
        return size[ultPar(x)];
    }
};

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        

        DSU ds(n + 1);
        vector<int> indegree(n, 0);

        for(int u = 0; u < n; u++) {    // TC: O(n)
            int v1 = leftChild[u];
            int v2 = rightChild[u];

            // Connecting left:
            if(v1 != -1) {
                if(indegree[v1] >= 1) return false;                 // already connected
                if(ds.ultPar(u) == ds.ultPar(v1)) return false;      // cycle

                indegree[v1]++;
                ds.Union(u, v1);
            }

            // Connecting right:
            if(v2 != -1) {
                if(indegree[v2] >= 1) return false;                 // already connected
                if(ds.ultPar(u) == ds.ultPar(v2)) return false;     // cycle

                indegree[v2]++;
                ds.Union(u, v2);
            }
        }

        // Last check, if all the nodes are in same component & forming binary tree or not?
        int comp = 0;
        for(int i = 0; i < n; i++) {    // TC: O(n)
            if(ds.ultPar(i) == i) comp++;
            if(comp > 1) return false;
        }

        return true;    // all the configurations goes well.
    }
};