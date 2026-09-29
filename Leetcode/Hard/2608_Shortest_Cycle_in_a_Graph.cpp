/*

//  2608. Shortest Cycle in a Graph


//  Problem Statement: 
    - There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1. The edges in the graph are represented by a given 2D integer array edges, where edges[i] = [ui, vi] denotes an edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
    - Return the length of the shortest cycle in the graph. If no cycle exists, return -1.
    - A cycle is a path that starts and ends at the same node, and each edge in the path is used only once.

 
// Example:
    Example 1:
        Input: n = 7, edges = [[0,1],[1,2],[2,0],[3,4],[4,5],[5,6],[6,3]]
        Output: 3
        Explanation: The cycle with the smallest length is : 0 -> 1 -> 2 -> 0 

    Example 2:
        Input: n = 4, edges = [[0,1],[0,2]]
        Output: -1
        Explanation: There are no cycles in this graph.

    // Constraints:
        2 <= n <= 1000
        1 <= edges.length <= 1000
        edges[i].length == 2
        0 <= ui, vi < n
        ui != vi
        There are no repeated edges.




// Observations:
    - Given node n from 1 to n - 1
    - Given edges {u, v}, undirected graph.
    - we will have to find the shortest length of cycle

    // Approach:
        - First thing is that we will have to find the cycle in undirected graph.
            - we can find cycle using BFS/DFS or DSU
        - While finding the cycle, we also need to find the cycle length.
        - And, from all the cycle, we will have to return the cycle that has min-length.


        // DSU Approach:
            - using DSU we can find the cycle, but the problem is that when we have given graph and edge like:

                        [0]-----------[1]------------[2]
                         |             |
                         |             |
                         |             |
                        [3]-----------[4]


                    and given edges are like:
                            {{0, 1}, {1, 2}, {1, 4}, {4, 3}, {3, 0}}
                                - now even if we maintain the count for every component connecting together, and when we encounter with cycle, we arn't sure with cycle length, as
                                - it may be possible that we first proceed to join some useless edge like: {1---2}, which has no-role in cycle formations..
                                - So, logically we can find the cycle, But length is not sure that is correct or not?
                
                -> DSU Fails to compute the correct length of cycle..
            
        // BFS Approach:
            - Using BFS we can start with any node: 
                - and it's easy to print the level of every node..
                    - as BFS grows level-wise..
                        - Let say we start with node '0':
                        - level of graph is:

                                0           1           2
                                [0]---------[1]--------[2]
                                 |           |
                                 |           |
                                [3]---------[4]2
                                1

                        - so if we encounter with cycle:
                        - we can find the length of cycle, using this informations..

            - But we can't be sure that smallest cycle length can be found only node '0', so we will have to try with every possible node:
                - means, we will find cycle form starting node as every possible nodes..

            - Finding Cycle in Undirected graph:
                - We used to maintain parent & using that informations we used to check wether we encounter with cycle or not?
                    - So, let's say we are exploring the adjacent_neighbors:
                        - and "ngbr" node is already visited, & it's not the parent of current node:
                            - This is the exact condition of cycle.

            - Concluding, we will start from every node:
                - and try finding the cycle:
                    - if we encounter with cycle:
                        - we will compute the cycle length using:
                            cycleLen = level[node] + level[adjNode] + 1;

                            - This works as, if we observe:
                                we are now at the current node, which level we know, as exploring..
                                and adjNode 'ngbr' level is already computed, as it's already visited..
                                So, we will add them and '1' is for connecting current & adjNode 'ngbr'.

            - It can be possible that graph is distributed in connected components, and multiple components has cycle:
                - so, we don't need to handdel that case, as they only asked for smallest length cycle, and it can be found in any component, we just have to return their length.

        // Complexity:
            - constrains:
                    1 <= E <= 1000
                    1 <= n <= 1000

            - in worse case: 
                - for every node we are exploring every other nodes:
                    O(n^2)

                    1000 * 1000 => 1000000, that is accepttable
            
                    TC: O(n^2 + E)
                    SC: O(n + E)


    // Edge case:
        - It is possible that multiple cycle can be found in same components..
        - So, from all the cycle founding, we will have to return the cycle that has min_length.


            [1] ------------------- [2] ------------------- [8]
             |                     /   \                     / |
             |                    /     \                   /  |
             |                   /       \                 /   |
             |                  /         \               /    |
     _______[6________________[0]          \             /     |
    |        | \               /            \           /      |
    |        |  \             /              \         /       |
    |        |   \           /                \       /        |
    |        |    \         /                  \     /         |
    |        |     \       /                    \   /          |
    |       [4] ---- [3] ------------------------ [5]          |
    |        |\___________________________________/            |
    |        |                                                 |
    |        |                                                 |
    |       [9]                                                |
    |                                                          |
    |__________________________________________________________|
        


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    int bfs(int node, vector<vector<int>>& adj, int n) {
        
        // Initialize BFS Components:
        queue<pair<int, int>> q;    // <node, parent>
        vector<int> vis(n, 0);      // for visited
        vector<int> level(n, 0);    // this will contains the level for each nodes..

        // Push Src nodes:
        q.push({node, -1});
        vis[node] = 1;
        level[node] = 0;

        int lvl = 0;                    // used to assign the level for every node.
        int cycleLen = INT_MAX;         // it is possible that multiple cycle found in single component, so we will have to return the minimum one.


        while(!q.empty()) {
            int size  = q.size();

            // Process level-by-level
            while(size--) { 
                auto [node, parent] = q.front();
                q.pop();

                // Explore adj-neighbors:
                for(auto &ngbr: adj[node]) {
                    
                    // not visited yet:
                    if(!vis[ngbr]) {
                        q.push({ngbr, node});                       // push that node into queue
                        vis[ngbr] = 1;                              // mark it as visited
                        level[ngbr] = lvl + 1;                      // Update the adjNode early as we will have to return the first cycle hit..
                    } else if(parent != ngbr) {
                        // Cycle Conditions: 
                        int len = level[node] + level[ngbr] + 1;    // CycleLen = currentLvl + nextLvl + 1 => total size.
                        cycleLen = min(cycleLen, len);              // It can be possible that single compnonent has multiple cycle, So from all the cycle, we will have to return the min_length of cycle.
                    }
                }                
            }

            lvl++;
        }

        return cycleLen;  // return the cycle with min_Length.
    }
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {

        // Build Graph adj List:
        vector<vector<int>> adj(n);
        for(auto &i: edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }


        // From every possible nodes, find the cycle with min_length:
        int minLen = INT_MAX;
        for(int i = 0; i < n; i++) {
            minLen = min(minLen, bfs(i, adj, n));
        }

        return (minLen == INT_MAX) ? -1 : minLen;
    }
};

