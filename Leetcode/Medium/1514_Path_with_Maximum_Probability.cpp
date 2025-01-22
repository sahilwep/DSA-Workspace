
/*

//  1514. Path with Maximum Probability


//  Problem Statement: 
    -> You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
    -> Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
    -> If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.


// Example: 

    Example 1:
        Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
        Output: 0.25000
        Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

    Example 2:
        Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
        Output: 0.30000

    Example 3:
        Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
        Output: 0.00000
        Explanation: There is no path between 0 and 2.


// Observations:
        -> We are given undirected weighted graph.
        -> Graph can have multiple components.
        -> We are given source node & destination node.
        -> for every node we are given edges.
            -> We need to convert these edges into the graph adjacency list.
        -> for every edges we are given some floating values.
        -> We need to find the maximum probability of success to go from start to end.
        -> We can solve this question by using Dijkstra's algorithm:
            -> because we need to choose such path which have maximum probability.
            -> we can use max_heap. => Structure: <prob, node>
            -> for distance of source node = 1.0
            -> Also, when we are inserting the source node in max heap, we will insert insert '1.0' as source dist, Because:
                -> for finding the probability, we were multiplying the edge weights, & multiplying any value with '1', will not change the overall probability.
                -> Also if we have inserted with '0', then the probability will always be '0'.
            -> Last we will return the distance of destination node.
            -> NOTE: we will declare distance vector for every node value as '0.0', because we need maximum value, & also, the constrains min value is '0'.

// Complexity: 
    -> TC: O(E * log(V)), more precise: O((E + V) * log(V))
    -> AS: O(V + E)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int src, int dest) {

        // Build graph:
        vector<vector<pair<int, double>>> adj(n);
        int edgSize = edges.size();
        for(int i=0;i<edgSize;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // Now coming back to Dijkstra's:
        priority_queue<pair<double, int>> pq;  // declare priority queue with maxProb, node.
        vector<double> dis(n, 0.0);    // declare distance vector of size 'n' nodes with min value, as we need max only.

        // insert source node:
        pq.push({1.0, src});  // insert source node into priority queue, with prob = 1.0, because if we pushed '0', any number can be multiply with that number will result as '0', this is why we have pushed '1', which will preserve the result.
        dis[src] = 1.0;   // marking distance of source node as '1.0'

        while(!pq.empty()){ // while priority queue is not empty.
            auto it = pq.top();
            pq.pop();

            double prevProb = it.first;
            int node = it.second;

            for(auto it: adj[node]){    // explore the adjacent nodes:
                int currNode = it.first;
                double currProb = it.second;

                double newProb = currProb * prevProb;   // get the new probability value

                // Now check if new probability value is grater than the distance of current node:
                if(newProb > dis[currNode]){
                    dis[currNode] = newProb;    // update it

                    pq.push({newProb, currNode});   // insert it into queue
                }
            }
        }

        return (dis[dest] == 0.0) ? 0.0 : dis[dest];   // return distance of destination node.
    }
};