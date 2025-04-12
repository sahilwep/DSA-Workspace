/*

//  685. Redundant Connection II

//  Problem Statement: 
    -> In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.
    -> The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. 
    -> The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.
    -> The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.
    -> Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. 
    -> If there are multiple answers, return the answer that occurs last in the given 2D-array.

// Example: 
    Example 1:

        Input: edges = [[1,2],[1,3],[2,3]]
        Output: [2,3]

    Example 2:
        Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
        Output: [4,1]



// Observations: 
    -> We are given edges [u, v] denoting directed edge from node u---->v
    -> We have to find the redundant edge
    
    // Key Observations: 
        -> Redundant => means more than one edge pointing on some node.
    
    -> Find the indegree of every node
    -> It may be possible that graph may contains cycle, then we also need to disconnect that edge which appears in edges list & falls into cycle path.


    // In Simple:
        -> Check nodes containing indegree > 1
            -> Check Cycle, if found, return the last cycle path, NOTE: we can run cycleFinding with starting node as indegreeNode
                
                     ------>[4]
                     |       ↑
                     |       |
                    [2]---->[1]
                             |
                             ↓
                            [3]

                                -> Indegree[4] = 2 & contains cycle
                                -> Remove edge {2, 1}

            -> If no cycle found, iterate in edges from backword, & return the edge which has same node as indegree > 1

                            [1]------->[2]
                             |          ↑
                             |          |
                             |          |
                            [3]---------|


        -> If all the nodes of graph has indegree 1:
            -> that's means three is a cycle for sure.
            -> Iterate in edges backwords, & find cycle, at any movement we get the cycle -> return that edge.
                -> NOTE: Make sure to send startingNode as 'v', (for directed edge u--->v), because it may be possible that u has some path which falls into cycle & 'v' didn't falls into cycle, and we may early return the edge for cycle founding..
                // Example: graph like: edge [[1,2],[2,3],[3,4],[4,1],[1,5]], explains well
                    
                    ↑ ↓ → ←

                        [2]----->[3]
                         ↑        |
                         |        |
                         |        ↓
                        [1]<-----[4]
                         |
                         |
                         ↓
                        [5]

                        -> for edge {1, 5} = {u, v}, if we send 'u', we early return our answer.
                        -> If we go find cycle with starting node = '1' this will return true & we may early return {1, 5} edge as our answer, This is why we will passs "v" instead of "u".



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// DFS Approach: 
class Solution {
private: 
    bool flag = true;           // used to store the cycle nodes
    pair<int ,int> cycleNode;   // store the last two cycle node
    // DFS function to return graph containing cycle:
    bool isCycle(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {  
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto &it: adj[node]) {
            if(!vis[it]) {
                if(isCycle(it, adj, vis, pathVis)) return true;
            } else if(pathVis[it]) {
                if(flag) {
                    flag = false;
                    cycleNode.first = node;
                    cycleNode.second = it;
                }
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int V = edges.size();
        
        // Form Graph Adj list:
        vector<vector<int>> adj(V + 1);     // 1-based indexed graph.
        vector<int> ind(V + 1, 0);          // contains indegree of every node
        int indegreeMoreThanOne = -1;       // used to store the node which contains more than 1 incoming edge.
        for(auto &it: edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);

            // Storing indegree & checking if it's grater than '1'
            ind[v]++;
            if(ind[v] > 1) {
                indegreeMoreThanOne = v;
            }
        }


        if(indegreeMoreThanOne != -1) {
            // We have found node which has indegree > 1
            // Two Options: Cycle / No-Cycle:

            // Find Cycle:
            vector<int> vis(V + 1, 0);
            vector<int> pathVis(V + 1, 0);
            if(isCycle(indegreeMoreThanOne, adj, vis, pathVis)) {
                return {cycleNode.first, cycleNode.second};
            }

            // If No Cycle found, try to get the last node which connect the graph & making indegree > 1
            for(int i = V - 1; i >= 0; i--) {   // start from last & return that node which found the same indegree node
                int u = edges[i][0], v = edges[i][1];
                if(v == indegreeMoreThanOne) {
                    return {u, v};
                }
            }
        } 
        else {
            // if indegreeMoreThanOne is not yet found, means every node has indegree 1
            // The Graph may contains cycle: 
            vector<int> vis(V + 1, 0);
            vector<int> pathVis(V + 1, 0);
            for(int i = V - 1; i >= 0; i--) {   // start from last, as we have to return the last edge:
                int u = edges[i][0], v = edges[i][1];
                if(isCycle(v, adj, vis, pathVis)) return {u, v};    // call with 'v', will make sure we will be reaching that "node" with cycle.
            }
        }

        return {-1, -1};    // Invalid Graph
    }
};