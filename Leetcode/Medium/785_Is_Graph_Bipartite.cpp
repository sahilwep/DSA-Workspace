/*

//  785. Is Graph Bipartite?


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


// Algorithm:
    -> We will check the bipartite graph or not using BFS:
    -> We will be using normal BFS algorithm
        -> It requires queue DS.
        -> It requires visited array, but instead of visited, we will use color array, which is equal to the total nodes.
        -> And filled with '-1', means not colored yet.
        -> We will try to color it with '0' or '1'


// Intrusion:
    -> Instead of using visited array, we will use color array that will make our job done.
    -> Use BFS Algo:
        -> Get the starting node & push it into queue:
            -> Iterate until queue is not empty:
                -> Get the queue front node:
                -> pop that front node from the queue:
                -> Explore the adjacent node of that front node
                    -> If that node is not colored yet: 
                        -> Colored it with opposite color of queue front node
                        -> Push it into queue.
                    -> Else if that node is same is with queue front node
                        -> Return false, because someone already colored it with some other path.
            -> If queue is empty finally & false condition is not hit, return true.

    -> NOTE: 
        -> We have to check this for multiple components.
        -> For multiple components we can use loop & iterate in all node that is not being colored yet.
        -> If any components is returning false, return false : else return true.


// Complexity:
    * TC: O(V + E) -> Takes BFS
    * SC: O(V) -> Color array


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Solved using BFS:
class Solution {
private:
    bool solve(int start, vector<vector<int>> &adj, vector<int> &color){
        
        queue<int> q;       // usign QUEUE DS
        q.push(start);      // push starting node of current component
        color[start] = 0;   // mark starting default color as '0'

        while(!q.empty()){  // while queue is not empty
            int node = q.front();
            q.pop();

            // Check adjacent nodes:
            for(auto it: adj[node]){
                if(color[it] == -1){            // if any adjacent node is not being colored yet?
                    color[it] = !color[node];   // color it with opposite of node color
                    q.push(it);                 // push that node into queue
                }
                // If adjacent node is having same color, someone did color it on some other path
                else if(color[it] == color[node]){
                    return false;   // return false in this case.
                }
            }
        }

        return true;    // else return true for current component of graph
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();       // total number of nodes
        vector<int> color(V, -1);   // Color array
        

        // Check for Multiple Components:
        for(int i=0;i<V;i++){
            if(color[i] == -1){ // if any node of any component is not being colored yet?
                if(solve(i, graph, color) == false){  // if that component result false
                    return false;   // return false for entire components
                }
            }
        }

        return true;    // else return true.
    }
};