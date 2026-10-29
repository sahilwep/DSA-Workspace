/*

//  3543. Maximum Weighted K-Edge Path


//  Problem Statement: 
    - You are given an integer n and a Directed Acyclic Graph (DAG) with n nodes labeled from 0 to n - 1. This is represented by a 2D array edges, where edges[i] = [ui, vi, wi] indicates a directed edge from node ui to vi with weight wi.
    - You are also given two integers, k and t.
    - Your task is to determine the maximum possible sum of edge weights for any path in the graph such that:
        - The path contains exactly k edges.
        - The total sum of edge weights in the path is strictly less than t.
    - Return the maximum possible sum of weights for such a path. If no such path exists, return -1.

 
// Example:
    Example 1:
        Input: n = 3, edges = [[0,1,1],[1,2,2]], k = 2, t = 4
        Output: 3
        Explanation:
            The only path with k = 2 edges is 0 -> 1 -> 2 with weight 1 + 2 = 3 < t.
            Thus, the maximum possible sum of weights less than t is 3.


    Example 2:
        Input: n = 3, edges = [[0,1,2],[0,2,3]], k = 1, t = 3
        Output: 2
        Explanation:
            There are two paths with k = 1 edge:
                0 -> 1 with weight 2 < t.
                0 -> 2 with weight 3 = t, which is not strictly less than t.
            Thus, the maximum possible sum of weights less than t is 2.


    Example 3:
        Input: n = 3, edges = [[0,1,6],[1,2,8]], k = 1, t = 6
        Output: -1
        Explanation:
            There are two paths with k = 1 edge:
                0 -> 1 with weight 6 = t, which is not strictly less than t.
                1 -> 2 with weight 8 > t, which is not strictly less than t.
            Since there is no path with sum of weights strictly less than t, the answer is -1.




// Observations:
    - Given n node from 0 to n- 1
    - Given DAG: no cycle in our graph
    - given edges {u, v, wt} directed edge 
    - Given two integer k and t
    - we have to determine the maximum possible sum of the edge weight fro any path in the graph such that, path contains exactly k edges.
    - the total sum of edge weight in the path is strictly less than t.
    - return the maximum possible sum of weights for such a path. if no such exist, return -1.


    // Approach:
        - Given DAG, means we never fall into cycle.
        - and we will have to find the maximum possible sum: 
            - with exactly k edges.
            - and edge weights on path strictly less than 't'


        - Given constrains:
            1 <= n <= 300


        - So, we can write dfs for find the maximum sum, with given conditions.
        - we will have to write dfs with given conditions.
        - as given graph is DAG, we don't required visited, because we never falls into cycle.


            int solve(int node, int k, int t, adj) {
                if(k == 0) {
                    return 0;
                }
            
                int pathSum = 0;
                // explore adj-neighbors:
                for(auto &[v, wt]: adj[node]) {
                    if(k > 0 && wt < t) {
                        pathSum = max(pathSum, wt + dfs(v, k - 1, t, adj);
                    }
                }

                return pathSum;
            }

        - Something like that.


        [0]-----3---->[1]
    
            k = 22
            t = 217


            n = 4
            edges = [[0,1,4],[0,2,3],[1,2,9],[2,3,5],[0,3,5]]
            k = 2
            t = 11


         |----------------------5-------|
         |                              |
        [0]----4---->[1]                |
         |            |                 |
         |            9                 |
         |            |                 |
         |            V                 V
         |-----3----->[2]-------5----->[3]


        - Correction: 
            - We will have to get have to choose the path only for which we have: 
                - total sum in that path should be < 't'


        - Got TLE:
            - as recomputing the same subproblem
            - we cam memoize the operations:
                - our variable values:
                    - node: goes up till n
                    - k:    goes up till k
                    - sum: goes up till t 


            int dp[n][k][sum]
                This gives MLE:
                    - as Solution, exceed the range.

                - we will have to optimize the memory as well:

            - We can use map to store the dp states.
        
            // Complexity:
                - TC: O(n * k * t)
                - SC: O(n * k * t)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Accepted:
class Solution {
private:
    unordered_map<string, int> mp;
    int dfs(int node, int k, int sum, int t, vector<vector<pair<int, int>>>& adj) {
        if(k == 0) return 0;   // no-need to look forward:
        
        // Check-in-memo table:
        string key = "";
        key += to_string(node);
        key += '_';
        key += to_string(k);
        key += '_';
        key += to_string(sum);
        if(mp.count(key)) {
            return mp[key];
        }

        // Explore adj-neighbors:
        int pathSum = INT_MIN;
        for(auto &[v, wt]: adj[node]) {
            if(k > 0 && sum + wt < t) {
                pathSum = max(pathSum,  wt + dfs(v, k - 1, sum + wt, t, adj)); 
            }
        }

        return mp[key] = pathSum;
    }
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        
        // Build Graph adj list:
        vector<vector<pair<int, int>>> adj(n);
        for(auto &i: edges) {
            adj[i[0]].push_back({i[1], i[2]});
        }

        // Find maximum sum from every possible nodes:
        int sum = -1;
        for(int i = 0; i < n; i++) {
            sum = max(sum, dfs(i, k, 0, t, adj));
        }

        return sum;
    }
};


// MLE:
class Solution {
private:
    vector<vector<vector<int>>> dp;
    int dfs(int node, int k, int sum, int t, vector<vector<pair<int, int>>>& adj) {
        if(k == 0) return 0;   // no-need to look forward:
        
        if(dp[node][k][sum] != -1) {
            return dp[node][k][sum];
        }

        // Explore adj-neighbors:
        int pathSum = INT_MIN;
        for(auto &[v, wt]: adj[node]) {
            if(k > 0 && sum + wt < t) {
                pathSum = max(pathSum,  wt + dfs(v, k - 1, sum + wt, t, adj)); 
            }
        }

        return dp[node][k][sum] = pathSum;
    }
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        
        // Build Graph adj list:
        vector<vector<pair<int, int>>> adj(n);
        for(auto &i: edges) {
            adj[i[0]].push_back({i[1], i[2]});
        }

        // initialize dp table:
        dp.resize(n + 1, vector<vector<int>> (k + 1, vector<int>(t + 1, -1)));


        // Find maximum sum from every possible nodes:
        int sum = -1;
        for(int i = 0; i < n; i++) {
            sum = max(sum, dfs(i, k, 0, t, adj));
        }

        return sum;
    }
};



// Recursive: TLE:
class Solution {
private:
    int dfs(int node, int k, int sum, int t, vector<vector<pair<int, int>>>& adj) {
        if(k == 0) return 0;   // no-need to look forward:
        
        // Explore adj-neighbors:
        int pathSum = INT_MIN;
        for(auto &[v, wt]: adj[node]) {
            if(k > 0 && sum + wt < t) {
                pathSum = max(pathSum,  wt + dfs(v, k - 1, sum + wt, t, adj)); 
            }
        }

        return pathSum;
    }
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        
        // Build Graph adj list:
        vector<vector<pair<int, int>>> adj(n);
        for(auto &i: edges) {
            adj[i[0]].push_back({i[1], i[2]});
        }

        // Find maximum sum from every possible nodes:
        int sum = -1;
        for(int i = 0; i < n; i++) {
            sum = max(sum, dfs(i, k, 0, t, adj));
        }

        return sum;
    }
};