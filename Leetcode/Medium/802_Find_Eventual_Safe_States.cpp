/*

//  802. Find Eventual Safe States


//  Problem Statement:: 
    -> There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
    -> A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
    -> Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 
// Example:
    Example 1:
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
    -> A node is a terminal node, that has outgoing degree = 0
    -> Safe node is a node that reaches to terminal node & have no-cycle occurred.
    -> In simple word safe node is a node that leads to terminal node & there is other path found in between that leads to cycle.
    -> Anyone that are the part of cycle can never be safe node.
        
        // Example:

            [1]---->[2]------>[3]----->[4]
                      ↑        |        |
                     [8]       ↓        ↓
                     |  ↖     [7]----->[5]---->[6]
                     ↓    \
                    [9]-->[10]

            Input:
                    [0]----->[1]
                    | ↖     / | 
                    |   \ /   |     [6]
                    ↓ ↙   \   ↓
                    [2]     [3]
                     |
                     ↓
                    [5]<----[4]


            Output:
                2 4 5 6
            Explanation:
                The given graph is shown above.
                Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them. 
                Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

        // Conclusion:
            -> Anyone that who is a part of cycle can never be safe node.
            -> Anyone that leads to a cycle can never be safe node.
            -> Everyone else can be safe node.
            -> The whole problem can be solve by figuring out which node is the part of cycle & which node that leads to a cycle.

// Approach:
    -> We know that how we can find a cycle usign DFS
        -> We maintain two things "visited" & 'pathVisited' & solve the problem
    -> Using Same thing we can modify a bit to find the solution.
    -> When recursive call ends and will not fall into any cycle, we will store that node as safe node.
    -> When we get the cycle we directly return without unmark the pathVisited for that node.
    -> And anytime a node leads to that path, that will immediately know & mark themself as not safe node.

// Complexity:
    -> TC: O(V + 2E)
    -> SC: O(V + 2E)


*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    bool solve(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, vector<int> &check){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        // Check adjacent nodes:
        for(auto it: adj[node]){
            if(!vis[it]){   // if adj node is not visited yet?
                if(solve(it, adj, vis, pathVis, check) == true){    // if recursive call return cycle, mark that node as not safeNode
                    check[node] = 0;    // mark source node as not safeNode
                    return true;        // return true for cycle
                }
            }
            else if(pathVis[it]){   // if adj node is visited & pathVis[it] is also visited, means cycle found
                check[node] = 0;    // mark source node as not safeNode
                return true;        // return true for cycle
            }
        }

        check[node] = 1;    // mark as safeNode if it's not fall into cycle
        pathVis[node] = 0;  // unmark for pathVis
        return false;       // return false for no cycle found.
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);

        // Explore Multiple Components:
        for(int i=0;i<V;i++){
            if(!vis[i]){
                solve(i, graph, vis, pathVis, check);
            }
        }
        vector<int> safeNode;
        for(int i=0;i<V;i++) if(check[i] == 1) safeNode.push_back(i);
        return safeNode;
    }
};