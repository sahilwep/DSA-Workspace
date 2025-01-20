/*

//  743. Network Delay Time


//  Problem Statement: 
    -> You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
    -> We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
 

// Example:
    Example 1:

        Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
        Output: 2

    Example 2:

        Input: times = [[1,2,1]], n = 2, k = 1
        Output: 1

    Example 3:

        Input: times = [[1,2,1]], n = 2, k = 2
        Output: -1


// Observation: 
    -> we are given n nodes from 1 to n.
    -> We are also given times, a list of time travel as directed edges:
        time[i] = {u[i], v[i], w[i]},
                u[i] = source node
                v[i] = dest node
                w[i] = weight
    
    -> We will start from node 'k'
    -> and we will have to find the minimum time to it takes for all the n nodes to receive the signal.
    -> If it's impossible to reach the signal, return '-1'

        // Cases:
                Input: times = [[1,2,1]], n = 2, k = 2
                Output: -1

                    [1]-------->[2]
                        1
                        
                        since the direction is from 1 to 2
                        and we are starting from '2', it's impossible to reach at '1'
                        so minimum time is not calculated yet, so return -1


    -> Now Coming back:
            -> We are given directed graph.
            -> We will have to calculate the minimum time.
            -> We are given source node.
            -> Destination is not given, we will have to process all the nodes.
            -> Once all the node is processed and we will have the time taken by them.
            -> We can return the maximum among the list, because that's the minimum time to reach every nodes.
            -> NOTE: if any node time has not yet calculated, then return '-1', as not possible to reach.

            -> We can solve this by using dijkstra:
            -> But we will use simple queue BFS which will make our job done.



// Normal BFS Based solution: 
    -> We will use BFS based solution..
    -> We will use priority queue to compute the distance from source node to every other node...
    -> TC: O(V * E), because we are traversing all the possible edges for every vertices.




// Dijkstra's Solution: 
    -> We will use time parameter to consider as our minimum cost to reach every nodes..
    -> We will use priority queue to solve this.
    -> We are given weight of every edges, & we need to calculate the distance from source to every other nodes.
    -> While using dijkstra's we will consider the edge weight to be our main parameter that we will minimize.
    -> priority queue structure: <distance, node>
    -> now every time the distance will be increased when we trave any (u ---> v), their edge weight will be added.
    -> and, in priority queue the lowest distance will be processed first, kind of greedy somehow..
    // Complexity: 
        -> TC: O(E * log(V))
            -> Extracting the minimum node takes O(logV), from priority queue.
            -> Each edge is relaxed once, resulting in O(E * log(V)) for all edges combined.
        -> SC: O(V)


    // NOTE: 
        -> You might be wondering that we have directed graph, 
            so the distance from (u -----> v) is fixed:
            distance to reach 'v' is distance[u] + edge weight, But NO
            because we can have multiple directed path from (u -----> v),
            May be it's not directly connected, but may be it's connected somehow with some other node.
            Example:
                                    18
                            u --------------> v
                            |                 ^
                            ---------> x -----|
                                2           3
                
                here u -> v = 18
                     u -> x = 2
                     x -> v = 3
                
                so, with other possible path, u -> v, via some other path takes only '5'
        
        This is why we need greedy approach to choose path that is minimum....
        and this is why We have used dijkstra's to perfrom solve this particular question.        

        Dijkstra's algorithm processes nodes in order of their current shortest distance using a priority queue (min-heap).
        The BFS solution processes nodes in a simple queue, which doesn't guarantee the shortest distance is always processed first. This causes redundant work.

*/          

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Dijkstra's based Solution:
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Construct the adjacency list to represent the graph:
        vector<pair<int, int>> adj[n+1]; // n+1, because it's start from 1 till n
        for(auto it: times){
            int u = it[0];  // source node
            int v = it[1];  // dest node
            int wt = it[2]; //weight

            // now push it into adj:
            adj[u].push_back({v, wt});
        }

        vector<int> dist(n + 1, INT_MAX);    // this will store the distance of every signal reaching to all the other nodes.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // pq structure: 
        
        pq.push({0, k});    // push source node with cost '0'
        dist[k] = 0;  // mark that src distance as '0' to reach src.

        // Dijkstra's Algorithm:
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int steps = it.first;
            int node = it.second;

            // Explore adjacent node of nodes:
            for(auto it: adj[node]){
                int v = it.first;
                int wt = it.second;

                // If the total time taken to reach 'neighbourNode' through 'node' is less than
                // the current recorded distance to 'neighbourNode', update the distance
             
                // If the total time taken to reach adjacent node through node is lesser than the current recorded distance to adjacent node, then update the new distance.
                if(steps + wt < dist[v]){
                    dist[v] = steps + wt;   // update new distance
                    pq.push({dist[v], v});  // push it into queue.
                }
            }
        }


        // Last check the minCost:
        int minCost = *max_element(dist.begin()+1, dist.end()); // get the maximum value from index 1 to n, that will our minimum time.

        return minCost == INT_MAX ? -1 : minCost;   // last return minCost if value is not INT_MAX
    }
};


// Normal BFS Solution:
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times[0].size();

        vector<int> signal(n + 1, INT_MAX);    // this will store the minimum time to reach signal to all the nodes
        queue<pair<int, int>> q;    // this will store the nodes that we are processing:    structure = {node, time}
        
        q.push({k, 0}); // push starting given source node into queue with time = 0
        signal[k] = 0;  // mark that src signal reach at '0' sec.


        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int node = it.first;
            int time = it.second;

            // Iterate in all the times value, because we have multiple edges going from a single node
            for(const auto &it: times){
                int u = it[0];
                int v = it[1];
                int weight = it[2];

                if(u == node){  // verify that we are at source & get the correct source.
                    if(time + weight < signal[v]){     // if new weight is less than the current explored path
                        signal[v] = time + weight;  // update new signal weight
                        q.push({v, time + weight});   // push that into queue
                    }
                }
            }
        }

        // Last check the minCost:
        int minCost = 0;
        for(int i=1;i<n+1;i++){
            if(signal[i] == INT_MAX) return -1;     // straight away return -1
            minCost = max(minCost, signal[i]);      // get the maximum value from this signal.
        }

        return minCost;
    }
};