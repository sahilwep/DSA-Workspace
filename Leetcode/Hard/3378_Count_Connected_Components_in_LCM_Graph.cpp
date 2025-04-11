/*

//  3378. Count Connected Components in LCM Graph

//  Problem Statement:
    -> You are given an array of integers nums of size n and a positive integer threshold.
    -> There is a graph consisting of n nodes with the ith node having a value of nums[i]. 
    -> Two nodes i and j in the graph are connected via an undirected edge if lcm(nums[i], nums[j]) <= threshold.
    -> Return the number of connected components in this graph.
    -> A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
    -> The term lcm(a, b) denotes the least common multiple of a and b.

 
// Example: 
    Example 1:
        Input: nums = [2,4,8,3,9], threshold = 5
        Output: 4
        Explanation: The four connected components are (2, 4), (3), (8), (9).

    Example 2:
        Input: nums = [2,4,8,3,9,12], threshold = 10
        Output: 2
        Explanation: The two connected components are (2, 3, 4, 8, 9), and (12).


// DSU Approach: 
    -> As we have to find the total number of components, DSU can be very efficient on that.
    -> With DSU first we can connect every possible nodes which follows the given constrains.
        -> (lcm(a, b) <= threshold)
    -> Then afterwords we will find the total number of components of graph by simply looking out in given nums & checking the ultimate parent.


// Complexity: 
    -> TC: O(n^2 * log(maxVal))
        -> log(maxVal) => for lcm of two number
    -> SC: O(n + maxVal)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class DSU {
private: 
    vector<int> size, parent;
public:
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]);
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_);
        int v = ultPar(v_);

        if(u == v) return;
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
private: 
    typedef long long ll;
    ll lcm(int a, int b) {
        ll res = ll(a) * ll(b);
        res = res / ll(gcd(a, b));
        return res;
    } 
public:
    int countComponents(vector<int>& nums, int thr) {
        int n = nums.size();
        // Finding the maximum range for DSU:
        int size = *max_element(begin(nums), end(nums));   // return the address of maximum element from the nums => dereference to get the value.
        DSU ds(size + 1);

        // Connecting the nodes & forming the components from the given constrains:
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int a = nums[i], b = nums[j];
                if(lcm(a, b) <= ll(thr)) {
                    ds.Union(a, b);
                }
            }
        }

        // Count total number of components:
        int comp = 0;
        for(auto &it: nums) {
            if(ds.ultPar(it) == it) comp++;
        }

        return comp;
    }
};