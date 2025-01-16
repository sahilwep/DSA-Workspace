/*

//  G-32. Dijkstra's Algorithm - Using Priority Queue


// Problem Statement: 
    -> Given a weighted, undirected and connected graph where you have given adjacency list adj. You have to find the shortest distance of all the vertices from the source vertex src, and return a list of integers denoting the shortest distance between each node and source vertex src.
    -> Note: The Graph doesn't contain any negative weight edge.


// Examples:

    Input: adj = [[[1, 9]], [[0, 9]]], src = 0
    Output: [0, 9]
    Explanation: The source vertex is 0. Hence, the shortest distance of node 0 is 0 and the shortest distance from node 0 to 1 is 9.


    Input: adj = [[[1, 1], [2, 6]], [[2, 3], [0, 1]], [[1, 3], [0, 6]]], src = 2
    Output: [4, 3, 0]
    Explanation:
        For nodes 2 to 0, we can follow the path 2-1-0. This has a distance of 1+3 = 4, whereas the path 2-0 has a distance of 6. So, the Shortest path from 2 to 0 is 4.
        The shortest distance from 0 to 1 is 1 .



// Approach:
    -> Why a PQ is used, or why we need a data-structure that gives the minimum number at first be used ?
        -> A priority queue (min-heap) is used in Dijkstra's algorithm because it is essential to always process the vertex with the minimum distance from the source first. 
        -> This is a fundamental requirement of the algorithm to ensure that distances to all vertices are calculated correctly and efficiently.
        -> Dijkstra's algorithm follows the greedy approach: At each step, it processes the vertex with the smallest known distance from the source. 
        -> This guarantees that when a node is processed, the shortest path to that node has already been determined.

    -> Approach:
        -> We have adjacency list: ((node, distance),(...)...)
        -> We will be using minimum heap data-structure: <distance, node>
            -> If we are storing anything in the terms of distance & node, the shorter distance will be at top.
            -> Because we need to process the shortest distance at first.
            -> If we have equal shorter distance of multiple node, then the node that has minimum value will be at the top.
        -> We will always have a distance array, which will keep of track how much distance are we taking in a path.
        -> We will be given source node,
        -> Initially mark source node as '0' distance, & rest all the distance as infinity.
        -> Now everything is simillar as BFS:
            -> Take out the top element
            -> Check their adjacent nodes:
                -> If we get any shortest distance
                -> Assign them & push into priority-queue.
        -> At last when queue is finally empty, return the distance array.



// NOTE: 
    -> Dijkstra algorithm will not work for negative weight graph
    -> Also doesn't work if there is a cycle that ends up having negative weight.
    -> Because any graph with negative weight will fall in an infinite loop.



// Complexity:
    -> TC: O(E*log(V))
        -> E = total number of edges
        -> V = number of nodes.


*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int V = adj.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;     // min heap -> priority queue
        vector<int> dist(V, INT_MAX);
        
        dist[src] = 0;  // marking source distance as '0'
        pq.push({0, src});  // pushing starting element 
        
        while(!pq.empty()){
            int dis = pq.top().first;   // get the distance
            int node = pq.top().second; // get the node
            pq.pop();   // remove that node from priority queue
            
            // Now checking adjacent nodes:
            for(auto it: adj[node]){
                int adjNode = it.first;    // get the current adjacent node
                int edgeWeight = it.second; // get the current adjacent node weight
                
                if(dis + edgeWeight < dist[adjNode]){   // previous node distance + current node edgeWeight is less than the current node distance, then we will overwrite it.
                    dist[adjNode] = dis + edgeWeight;  // now overwrite new distance to
                    pq.push({dist[adjNode], adjNode});  // push that current adj
                }
            }
        }
        
        return dist;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~" << "\n";
    }

    return 0;
}