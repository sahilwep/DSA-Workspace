/*

//  G-21. Topological Sort Algorithm | DFS



// Topological Sort:
    -> It only exist in only DAG, Directed Acyclic graph that has no cycle.
    -> Linear ordering of vertices such that if there is an edge b/w 'u' & 'v', such that 'u' always appears before 'v' in that ordering.

    // Why it only exist in DAG:
        -> For undirected -> we can have node path both ways, but as per topological sort, there should be directed path & u appear before 'v'
        -> For Cyclic:
                if we have cycle in our grapH:

                    [1]------>[2]
                      ↖        |
                        \      |
                          \    ↓
                             [3]
                            
                
                Graph directions: 1-> 2, 2->3, 3->1
                Topological-Sort: 1, 2, 3, '1'
                            all satisfy but ordering of '1' is not valid here as 'u' appear before 'v'




// Problem Statement:
    -> Given an adjacency list for a Directed Acyclic Graph (DAG) where adj[u] contains a list of all vertices v such that there exists a directed edge u -> v. Return topological sort for the given graph.
    -> Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
    -> Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be 1 else 0.




// Examples:

    Input: adj = [[], [0], [0], [0]] 

    Output: 1
    Explanation: The output 1 denotes that the order is valid. Few valid Topological orders for the given graph are:
    [3, 2, 1, 0]
    [1, 2, 3, 0]
    [2, 3, 1, 0]

    Input: adj = [[], [3], [3], [], [0,1], [0,2]]

    Output: 1
    Explanation: The output 1 denotes that the order is valid. Few valid Topological orders for the graph are:
    [4, 5, 0, 1, 2, 3]
    [5, 2, 4, 0, 1, 3]




// Approach
    -> we will use stack to perform topological, While using DFS
    -> whenever DFS calls ends, store that node into stack
    -> At last, we will store the stack element into a vector and return that vector as a result of Topological shot


Complexity
    -> TC: O(V + E) for directed graph


*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, stack<int> &st, vector<int> &vis){
        vis[node] = 1;  // mark that node as visited
        
        // Traverse adjacent nodes:
        for(auto it: adj[node]){
            if(!vis[it]){   // if adjacent node is not visited
                dfs(it, adj, st, vis);  // call for dfs
            }
        }
        
        // last store that node into stack
        st.push(node);
    }
public:
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int V = adj.size();
        
        vector<int> vis(V, 0);
        stack<int> st;
        
        // Check for Multiple Components:
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, adj, st, vis);
            }
        }
        
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        return res;
    }
};




int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}