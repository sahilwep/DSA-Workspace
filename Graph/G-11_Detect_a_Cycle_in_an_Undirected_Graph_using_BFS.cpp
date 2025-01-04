/*


//  G-11. Detect a Cycle in an Undirected Graph using BFS


// Problem Statement: 
    * Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, 
    * check whether the graph contains any cycle or not. The Graph is represented as an adjacency list, 
    * where adj[i] contains all the vertices that are directly connected to vertex i.

    * NOTE: The adjacency list represents undirected edges, meaning that if there is an edge between vertex i and vertex j, both j will be adj[i] and i will be in adj[j].


// Example:
    Input: adj = [[1], [0,2,4], [1,3], [2,4], [1,3]] 
    Output: 1
    Explanation: 1->2->3->4->1 is a cycle.

    Input: adj = [[], [2], [1,3], [2]]
    Output: 0
    Explanation: No cycle in the graph.



//  Observations: 

    -> For this given Problem, we are usign BFS: BFS goes level wise.

                           [2]---------------[5]
                          /                     \
                        /                        \
                     [1]                          [7]
                       \                          /
                         \                      /
                          [3]-----------------[6]
                           |
                           |
                          [4]

    // Adj List:
        1 -> {2, 3}
        2 -> {1, 5}
        3 -> {1, 4, 6}
        4 -> {4}
        5 -> {2, 7}
        6 -> {3, 7}
        7 -> {5, 6}

    -> Cycle means, if we have encounter with same position, where we have started, means there is a cycle
    -> Let's say we have starting position '1'.
        -> From 1, we can goto '2' or '3', because they are at the same distance, or same level.
        -> from 2, we can go to '1' or '5', but we just come back from '1', so we will avoid that, & go to '5'
        -> Similarly, from '3' we can go to '1', '4', or '6', but we will only go on '4' and '5', because we just came from '1'.
        -> Now, from '5' we can go on '7'
        -> from '4', we don't have any extra node, so, we will stop
        -> from '6', we can go to '7'

            -> Here from 5-->7   &   6--->7, 
            -> There are two nodes who are going on the same place.
            -> we have encounter with same node from both the side, we will say cycle found.
            -> In bfs, if we have encounter same nodes from different path, we can say there is cycle, & the distance to that node is also same, because bfs grows level wise.
    
    // In simple word, we will check:
        -> While going on next node, we will make sure to not go on that node where we are coming from.
        -> If we encounter with any node two time, we will say cycle found.

    // BFS Configuration:
        -> Define a queue, & insert first node, or source node,
        -> Note: We will also add the parent node where it's came from.
            Data structure: queue<pair<int, int>> 


// Complexity:
    * TC: O(n + 2E) + O(n)
        -> For every node, we are traversing all it's adjacent nodes.
        -> Adjacent node are degree, & the summation of adjacent node is summation of degree -> 2E in undirected graph.
        -> O(n), for component thing, that we are running in for loop, because in worse case every node are single, & we may need to run for all nodes...
    * AS: O(n)


// NOTE: 
    -> In case of connected component, we need to check all the component of graph.
    -> We say a graph to have a cycle if any of the component have cycle.


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // function to detect cycle in graph component:
    bool detect(int src, vector<vector<int>> &adj, vector<int> &vis){
        vis[src] = 1;           // mark given source node as visited
        queue<pair<int, int>> q;
        q.push({src, -1});      // insert source, & parent = -1, initially
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            
            // Iterate in adjecent node & try to found any node that are already visited & not the parent -> mean a cycle.
            for(auto adjacentNode: adj[node]){
                if(!vis[adjacentNode]){             // if we have any node not visited, mark as visited
                    q.push({adjacentNode, node});   // pushing that unvisited node, & parent as current node
                    vis[adjacentNode] = 1;          // marking as visited to that current unvisited node
                }
                else if(parent != adjacentNode){    // if we got any node that is already visited, & not the parent, means we have found a cycle.
                    return true;                    // cycle found
                }
            }
        }
        
        return false;   // no cycle found
    }
    
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);  // visited array
        
        // A graph can have multiple component, so we need to iterate & check in every component of graph, whether there is any cycle or not?
        for(int i=0;i<V;i++){   // NOTE: nodes start from '0'.
            if(!vis[i]){
                if(detect(i, adj, vis)) return true;    // return true if we found any cycle.
            }
        }
        
        return false;   // return false if there is no cycle.
    }
};



int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if(ans) cout << "1\n";
        else cout << "0\n";
        cout << "~" << "\n";
    }
    return 0;
}