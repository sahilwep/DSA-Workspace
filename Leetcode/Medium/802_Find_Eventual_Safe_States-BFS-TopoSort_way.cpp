/*

//  802. Find Eventual Safe States



//  Problem Statement: 
    -> There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
    -> A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
    -> Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

Example 1:
Illustration of graph

Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.



// Observations: 
    -> Terminal node is a node, where if there are no outgoing edges.
    -> A node is Safe node is if every possible path starting from that node leads to terminal node.
    -> Return an array containing all the safe nodes of the graph.
    -> Example:
            Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
            Output: [2,4,5,6]
            Explanation: The given graph is shown above.
            Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
            Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

                graph = [[1,2],[2,3],[5],[0],[5],[],[]]
                          0      1    2   3   4   5  6

                          -> Terminal Nodes: no outgoing path.
                                    5, 6
                          -> Safe node:  A node is Safe node is if every possible path starting from that node leads to terminal node.
                                    NOTE: Every possible path is important.
                                    2, 4, 5, 6
                                    NOTE: Terminal node is always safe node.
                            -> Rest 0, 1, 3, leads to cycle, where it's reaches itself.

    -> We are given directed graph.
            -> Eventual safe nodes are those nodes that can only reach terminal nodes (nodes with no outgoing edges) or other safe nodes.
            -> A node is unsafe if it is part of or can lead to a cycle.


    // Approach: 
        -> Reverse indegree of graph:
            -> Reversing the indegree node to out-degree, will make sure that terminal node in-degree become '0'
            -> Start with indegree = 0, as our source node, & perform plain BFS
            -> use answer vector to maintain the topo-sort finding.
            -> Last sort the answer & return .
            // Why we are Reversing the graph: 
                -> We want to use topo-sort, & we know that topo-sort required the indegree of every node..
                -> And we want to start with terminal node, becaus that is the node which we want to process first.
                -> Because terminal node will always be the safe node..
                -> And According to the question, terminal node can have multiple incoming indegree, but no-outgoing degree..
                -> So, reversing will make indegree = 0, This will make sure we will process the terminal nodes, first..
                -> And the node which were on the path of terminal node will be process after..
                -> And the nodes which lead to cycle, will never be processed..
                -> because we were maintaining indegree of every node & in every traversal we were checking the indegree, & when indegree == 0, then only we were inserting that node into queue.
                -> Rest we know very well how topo-sort works... ;)

        -> Why we are using Topo-sort ? 
            -> Topo sort only work in DAG(Directed Acyclic Graph)
                -> Also if some node has cycle, we won't consider into our result.
                -> Also Topo-sort process element in liner ordering, which help us to know about the node which are leading to terminal node...
        
        -> In-simple the nodes which were the part of cycle can never be safe node, & topo-sort only works in DAG, This is why we are using Topo-sort method.


// Complexity: 
    -> TC: O(V + E)
    -> SC: O(V + E)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        // Reverse the indegree of graph:
        vector<int> adjRev[V];
        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto it: graph[i]){
                adjRev[it].push_back(i);    // Reverse the edge: i -> it becomes it -> i
                indegree[i]++;  // increment the in-degree count
            }
        }


        // Now Perform Topo-sort
        queue<int> q;
        // Insert the node with indegree = 0, into queue:
        for(int i=0;i<V;i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);    // store those node only which are processed.

            // Explore adjacen nodes: 
            for(auto it: adjRev[node]){
                indegree[it]--; // decrement the indegree, as we processing the node
                if(indegree[it] == 0){ // If indegree becomes 0, add it to the queue(We are checking indegree[it] = 0, because we wan't to node to follow the linear ordering...)
                    q.push(it); // push it into queue.
                }
            }
        }

        sort(begin(ans), end(ans)); // sort that answer.

        return ans; // return
    }
};