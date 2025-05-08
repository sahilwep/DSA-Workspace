/*

//  3532. Path Existence Queries in a Graph I


//  Problem Statement: 
    -> You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1.
    -> You are also given an integer array nums of length n sorted in non-decreasing order, and an integer maxDiff.
    -> An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).
    -> You are also given a 2D integer array queries. For each queries[i] = [ui, vi], determine whether there exists a path between nodes ui and vi.
    -> Return a boolean array answer, where answer[i] is true if there exists a path between ui and vi in the ith query and false otherwise.


 
// Example: 
    Example 1:
        Input: n = 2, nums = [1,3], maxDiff = 1, queries = [[0,0],[0,1]]
        Output: [true,false]
        Explanation:
            Query [0,0]: Node 0 has a trivial path to itself.
            Query [0,1]: There is no edge between Node 0 and Node 1 because |nums[0] - nums[1]| = |1 - 3| = 2, which is greater than maxDiff.
            Thus, the final answer after processing all the queries is [true, false].

    Example 2:
        Input: n = 4, nums = [2,5,6,8], maxDiff = 2, queries = [[0,1],[0,2],[1,3],[2,3]]
        Output: [false,false,true,true]
        Explanation:
            The resulting graph is:
                Query [0,1]: There is no edge between Node 0 and Node 1 because |nums[0] - nums[1]| = |2 - 5| = 3, which is greater than maxDiff.
                Query [0,2]: There is no edge between Node 0 and Node 2 because |nums[0] - nums[2]| = |2 - 6| = 4, which is greater than maxDiff.
                Query [1,3]: There is a path between Node 1 and Node 3 through Node 2 since |nums[1] - nums[2]| = |5 - 6| = 1 and |nums[2] - nums[3]| = |6 - 8| = 2, both of which are within maxDiff.
                Query [2,3]: There is an edge between Node 2 and Node 3 because |nums[2] - nums[3]| = |6 - 8| = 2, which is equal to maxDiff.
                Thus, the final answer after processing all the queries is [false, false, true, true].

// Observations: 
    -> Given n nodes from 0 to n - 1
    -> Given sorted nums {..}, & given maxDiff
    -> Given queries {u, v} => return T/F with their connectivity.
    -> Connectivity defined as: 
            abs(nums[i] - nums[j]) <= maxDiff
                [i]------[j] has undirected edge
        

    // DSU approach: 
        -> because we have to given our query answer -> DSU is the ideal to use..
        -> It's just we have to figure out the graph connectivity:
            Given nums is sorted:

                maxDiff = 2, 
                nums = [2, 5, 6, 8]
                        0  1  2  3  -> Index

                        (5 - 2) => 3 -> Wrong
                        (6 - 5) => 1 -> Connect [1]------[2]
                        (8 - 6) => 2 -> Connect [2]------[3]

                    After connection:
                            [1]------[2]-----[3]

                            [0]

        -> Now, We can easily figure out every query.
                            

// Complexity: 
    -> TC: O(n + Q)
        -> n = total number of nodes
        -> Q = Total query

    -> SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

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
        if(node == parent[node]) return parent[node];
        return parent[node] = ultPar(parent[node]);
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
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
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        vector<bool> ans;
        DSU ds(n);  // O(n)

        // Build Graph:
        for(int i = 1; i < n; i++) {    // O(n)
            if(nums[i] - nums[i-1] <= maxDiff) {
                ds.Union(i, i-1);
            }
        }

        // Build answer: 
        for(auto &it: queries) {    // O(Q)
            int u = it[0], v = it[1];
            if(ds.ultPar(u) == ds.ultPar(v)) ans.push_back(true);
            else ans.push_back(false);
        }

        return ans;
    }
};