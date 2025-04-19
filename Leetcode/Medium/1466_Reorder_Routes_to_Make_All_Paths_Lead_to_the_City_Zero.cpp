/*

//  1466. Reorder Routes to Make All Paths Lead to the City Zero


//  Problem Statement: 
    -> There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.
    -> Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.
    -> This year, there will be a big event in the capital (city 0), and many people want to travel to this city.
    -> Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.
    -> It's guaranteed that each city can reach city 0 after reorder.

 
// Example: 
    Example 1:
        Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
        Output: 3
        Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

    Example 2:
        Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
        Output: 2
        Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).

    Example 3:
        Input: n = 3, connections = [[1,0],[2,0]]
        Output: 0


// Observations:
    -> Given n city from 0 to n - 1
    -> Connected through directed graph {u, v} denoting u --------> v
    -> We have to reach city 0 from all the others city.
    -> Some edges are in reversed order & we have to change those edges as minimum as possible...
    -> Guarantee that city 0 is reachable if we reorder the edge..


// Approach: 
    -> If we observe this graph, first create a undirected graph, & one extra directed graph.
    -> Iterate from 0 to every other nodes through undirected graph:
        -> considering the conditions: u <------ v, if there is no node from v to u then we can count those edges, & that will the edges which we should change in order to recreate the path where all nodes reaches destinations '0'.

// Complexity: 
    -> TC: O(V + 2E)
    -> SC: O(V)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int minReorder(int n, vector<vector<int>>& edges) {
        
        // Build Original Graph adj list: 
        vector<vector<int>> undAdj(n);              // undirected
        vector<unordered_set<int>> origAdj(n);      // directed
        for(auto &it: edges) {  
            // Undirected Graph Adj list:
            undAdj[it[0]].push_back(it[1]);
            undAdj[it[1]].push_back(it[0]);

            // Original directed graph adj list: 
            origAdj[it[0]].insert(it[1]);
        }

        // Explore from path '0' to all the other nodes & check for reversed edges during the traversal.
        queue<int> q;
        vector<int> vis(n, 0);

        vis[0] = 1;
        q.push(0);

        int invEdge = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();

            // explore adj nodes: 
            for(auto &v: undAdj[u]) {
                if(!vis[v]) {
                    // Check Original Reversed Edge: 
                    if(!origAdj[v].count(u)) {  // No edge found:
                        invEdge++;
                    }
                    
                    // Rest DFS logic:
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return invEdge; // return total number of inverse edge
    }   
};