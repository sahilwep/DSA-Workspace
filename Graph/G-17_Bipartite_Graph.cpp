/*

//  G-17. Bipartite Graph BFS

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

#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    bool solve(int start, vector<vector<int>> &adj, vector<int> &color){
        
        queue<int> q;       // Using Queue DS
        q.push(start);      // push the starting element of current Component into queue.
        color[start] = 0;   // color it with default '0' starting color.
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            // Check adjacent Nodes:
            for(auto it: adj[node]){
                if(color[it] == -1){            // if any adjacent node no yet colored:
                    color[it] = !color[node];   // Color it with opposite color of current node
                    q.push(it);                 // push it into queue.
                    
                }
                // If adjacent node is having same color, someone did color it on some other path
                else if(color[it] == color[node]){
                    return false;   // return false immediately
                }
            }
        }
        
        return true;    // else return true
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V, -1);   // color vector with default value -1, & we will filled it with 0/1
        
        // For Multiple Component of Graph:
        for(int i=0;i<V;i++){
            if(color[i] == -1){ // if not yet colored:
                if(solve(i, adj, color) == false){
                    return false;   // return false
                }
            }
        }
        
        return true;    // else return true for multiple components
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
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~" << "\n";
    }
    return 0;
}

