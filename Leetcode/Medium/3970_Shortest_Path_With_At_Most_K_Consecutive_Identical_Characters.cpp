/*

//  3970. Shortest Path With At Most K Consecutive Identical Characters


//  Problem Statement: 
    - You are given an integer n representing the number of nodes in a directed weighted graph, numbered from 0 to n - 1. This is represented by a 2D integer array edges, where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with weight wi.
    - You are also given a string labels of length n, where labels[i] is the character assigned to node i, and an integer k.
    - Return the minimum total edge weight of a path from node 0 to node n - 1 such that the concatenation of the labels of the nodes along the path contains at most k consecutive identical characters. If no valid path exists, return -1.

 
// Example:
    Example 1:
        Input: n = 3, edges = [[0,1,1],[1,2,1],[0,2,3]], labels = "aab", k = 1
        Output: 3
        Explanation:
            The optimal valid path from node 0 to node 2 is as follows:
                Use edges[2] = [0, 2, 3] to reach node 2 with a weight wi = 3.
            The corresponding concatenation of labels is "ab", which satisfies at most k = 1 consecutive identical characters. Thus, the answer is 3.

    Example 2:
        Input: n = 3, edges = [[0,1,1],[1,2,1],[0,2,3]], labels = "aab", k = 2
        Output: 2
        Explanation:
            The optimal valid path from node 0 to node 2 is as follows:
                Use edges[0] = [0, 1, 1] to reach node 1 with weight wi = 1.
                Use edges[1] = [1, 2, 1] to reach node 2 with weight wi = 1.
            The corresponding concatenation of labels is "aab", which satisfies at most k = 2 consecutive identical characters. Thus, the answer is 2.

    Example 3:
        Input: n = 3, edges = [[0,1,1],[1,2,1]], labels = "aaa", k = 2
        Output: -1
        Explanation:
        There is no valid path from node 0 to node 2 that satisfies at most k = 2 consecutive identical characters. Thus, the answer is -1.


        
// Observations:
    - Given n nodes representing the directed weighted graph given edges: {u, v, wt}
    - Also given labels: labels[i] represent the character assigned to the ith node.
    - Return the minimum total edge weight of a path form node 0 to n - 1, such that the concatenation of labels on the path is at-most k same characters.
    - If no-path exist, return -1, else return the shortest path that contains at-most k-consecutive characters.

    - In, simple, while finding the shortest path, we will try to stay within the k-limit.

    // Dijkstra's Approach:
        - We will have to find the shortest path from node 0 to n - 1, such that we didn't select same consecutive characters exceeding range 'k', and we will have to take the path that is shortest.
        - Dijkstra's depends on both {cost & consecutive}
        - While finding the shortest path from dijkstra's, we can't take consecutive characters more than 'k'
            - if node is 'a' and next node is "aa", and we have limit k = 1, then that path should be rejected.
            - Let's say we have streak:
                - which represent the consecutive characters count:
            - and we will have cost which is the summations of the edge weight:
                - and then while computing the cost, we will make sure that we will also consider the streak value.                    

                node => 0---n
                streak => 0---k

        - For every node 'i': 
            - there might be multiple states for which k varies,
                - let suppose there is a path which uses two single 'k'
                - and there is a path which contains only single 'k'
                    - and the next edge weight fully depends on the previous multiple result of k-used.
                    - So, we will use 2-D dijkstra's:
                        - for every node:
                            - we will have 'k' used.

                    
            - dijkstra's distance:
                dist[node][streak]:
                For every node we will maintain the record of cost which takes how-many consecutive characters.
 

            // Complexity:
                - TC: O(n * k + E)
                - SC: O(n * k + E)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    typedef pair<int, pair<int, int>> ppr;
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        // Build graph adj list:
        vector<vector<pair<int, int>>> adj(n);
        for(auto &it: edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Using Dijkstra's find the shortest path:
        priority_queue<ppr, vector<ppr>, greater<>> pq;
        vector<vector<int>> dist(n, vector<int> (k + 1, INT_MAX));   // we will have to take care of every nodes define states,

        pq.push({0, {0, 1}});

        // Hash all the sate of dist[0][streak] with '0', self reaching nodes cost.
        for(auto &it: dist[0]) it = 0;

        int ans = INT_MAX;
        while(!pq.empty()) {
            auto [cost, sec] = pq.top();
            int node = sec.first;
            int cons = sec.second;
            pq.pop();

            // Check if it's reaches to destinations:
            if(node == n - 1) {
                ans = min(ans, cost);
            }

            // Explore adj-nodes:
            for(auto &[v, wt]: adj[node]) {

                // Check consecutive count:
                int tempCons = cons;
                if(labels[node] == labels[v]) {
                    tempCons++;
                } else {
                    tempCons = 1;   // different characters, reset to '1'
                }

                if(tempCons > k) continue;  // if 'k' limit exceeds, skip 

                int newCost = cost + wt;    // calculate newCost
                if(newCost < dist[v][tempCons]) {
                    dist[v][tempCons] = newCost;
                    pq.push({newCost, {v, tempCons}});
                }
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};