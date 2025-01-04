/*

//  G-18. Bipartite Graph DFS


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


// DFS Approach:
    -> Write dfs algorithm with just maintain parent color.
    -> If color is not filled, at every recursive call we will fill with the color that is opposite of parent.
    -> else if color is same as parent color -> Return false.


// Complexity:
    -> TC: O(V + 2E)
    -> SC: O(V + 2E)

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
private:
    bool dfs(int start, int parent, vector<vector<int>> &adj, vector<int> &color){
        color[start] = parent;  // color with given parent color

        // Traverse the adjacent neighbour of given node:
        for(auto it: adj[start]){
            if(color[it] == -1){    // if any node is not colored yet?
                if(dfs(it, !color[start], adj, color) == false) return false;   // call for dfs, & if any branch return false return false immediately
            }
            // else if and adjacent node color is same as the current node color, means someone already did the color, return false immediately
            else if(color[it] == color[start]){
                return false;
            }
        }

        return true;    // else return true, for at last.
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V, -1);   // vector maintain to color nodes.

        // For multiple components of Graph:
        for(int i=0;i<V;i++){
            if(color[i] == -1){ // if any node is not colored yet:
                if(dfs(i, 0, adj, color) == false){   // check for that Component of the graph & color entire nodes of that component
                    return false;   // if this component return false, return false for whole.
                }
            }
        }

        return true;    // else return true.
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
        if(ans)  cout << "true\n";
        else cout << "false\n";

        cout << "~" << "\n";
    }
    return 0;
}