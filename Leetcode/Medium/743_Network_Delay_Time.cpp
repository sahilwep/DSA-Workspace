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


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;



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