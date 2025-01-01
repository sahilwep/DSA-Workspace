/*

//  785. Is Graph Bipartite? -> DFS Solution


// Problem Statement:
    -> There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:
        -> There are no self-edges (graph[u] does not contain u).
        -> There are no parallel edges (graph[u] does not contain duplicate values).
        -> If v is in graph[u], then u is in graph[v] (the graph is undirected).
        -> The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

    -> A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
    -> Return true if and only if it is bipartite.

 
// Example: 
    Example 1:
        Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
        Output: false
        Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.

    Example 2:
        Input: graph = [[1,3],[0,2],[1,3],[0,2]]
        Output: true
        Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.

    

//  Bipartite Graph:
    -> Color the graph with two color, such that no two adjacent node have same color.
    -> If we are able to color the graph with two color then we can say it's bipartite graph.

        // Example:

            -> Let's color this graph with two color: Blue & Green

                              [G]---------[B]
                             /               \
                            /                 \
            [B]---[G]---[B]                  [G]----[B]-----[G]
                            \                 /
                             \               /
                              [G]----------[B]

            -> This Graph can be called as Bipartite Graph
        
        // Example:

            -> Again take the same color & try to color:

                               [G]
                              /    \
                            /        \
                          /            \
                [G]------[B]            [B]-----[G]-----[B]
                         |              |
                         |              |
                         [G]-----------[B]
            
            -> Not-Bipartite Graph, because two adjacent node has colored with same color.

// Properties: 
    -> Linear Graph with no-Cycle are always bipartite.
    -> Any Graph with even length Cycle is can also be bipartite.
    -> Any Graph with odd length Cycle is not bipartite.



// DFS Approach:
    -> Write dfs algorithm with just maintain parent color.
    -> If color is not filled, at every recursive call we will fill with the color that is opposite of parent.
    -> else if color is same as parent color -> Return false.


// Complexity:
    -> TC: O(V + 2E)
    -> SC: O(V + 2E)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// DFS Solution
class Solution {
private:
    bool dfs(int start, int parent, vector<vector<int>> &adj, vector<int> &color){
        color[start] = parent;  // color with given parent color

        // Traverse the adjacent neighbour of given node:
        for(auto it: adj[start]){
            if(color[it] == -1){    // if any node is not colored yet?
                if(dfs(it, !color[start], adj, color) == false) return false;   // call for dfs, & if any branch return false return false immediately
            }
            // else if and adjacent node color is same as the current node color, means someone already did the color, return false immediately
            else if(color[it] == color[start]){
                return false;
            }
        }

        return true;    // else return true, for at last.
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);   // vector maintain to color nodes.

        // For multiple components of Graph:
        for(int i=0;i<V;i++){
            if(color[i] == -1){ // if any node is not colored yet:
                if(dfs(i, 0, graph, color) == false){   // check for that component of graph & color entire nodes of that component
                    return false;   // if this component return false, return false for whole.
                }
            }
        }

        return true;    // else return true.
    }
};