/*

//  G-33. Dijkstra's Algorithm - Using Set


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
    -> Why we are using set?
        -> Set will store only unique data in sorted fashion.
        -> set store everything in ascending fashion.



// NOTE: 
    -> Dijkstra algorithm will not work for negative weight graph
    -> Also doesn't work if there is a cycle that ends up having negative weight.
    -> Because any graph with negative weight will fall in an infinite loop.



*/
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int V = adj.size();

        set<pair<int, int>> st; // we will be using set to perfrom Dijkstra
        vector<int> distance(V, INT_MAX);   // this will maintain distance from source node to every other node.

        st.insert({0, src});    // insert source node & their distance '0' into set.
        distance[src] = 0;      // mark that source node distance as '0'

        
        while(!st.empty()){ // while set is not empty
            auto it = *st.begin();  // get that pair from set.
            int node = it.second;   // get the node.
            int dist = it.first;    // get the node distance.
            st.erase(it);           // remove that pair from set

            // Explore adjacent nodes:
            for(auto it: adj[node]){
                int adjNode = it.first; // get the adjacent node
                int edgeWeight = it.second; // get the distance from node to adjacent node.

                if(dist + edgeWeight < distance[adjNode]){  // if node distance & current edge weight is lesser than thier adjacent node distance, then we can update.
                    // if it's exist in set:
                    if(distance[adjNode] != INT_MAX){
                        st.erase({distance[adjNode], adjNode}); // This ensures that the set always contains the most up-to-date distance for each node
                    }
                    distance[adjNode] = dist + edgeWeight;  // update the new shortest distance
                    st.insert({distance[adjNode], adjNode});    // insert this node & distance into set
                }
            }
        }

        return distance;    // return that distance.
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

        for (int i = 0; i < V; i++) cout << res[i] << " ";
        cout << endl <<  "~" << "\n";
    }

    return 0;
}