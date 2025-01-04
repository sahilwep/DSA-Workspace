/*

//  G-23. Detect a Cycle in Directed Graph | BFS


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




//  Kahn's Algorithm: 
    -> We will be using BFS Algorithm to solve this particular Question.
    -> As we are using BFS, we will use queue DS to solve,
    -> One extra Thing we will use is "indegree" vector to maintain the indegree of every node
        -> Indegree: Number of incoming edges to a node.



// Approach:
    1. Understanding Topological Sort:
       - Topological sort is applicable only on Directed Acyclic Graphs (DAG).
       - If there is a cycle in the graph, a topological sort cannot be performed since cyclic dependencies prevent a linear ordering of nodes.

    2. Key Idea:
       - Perform a topological sort on the given graph.
       - During the process, maintain a count of the nodes included in the topological order.

    3. Cycle Detection:
       - If the number of nodes in the topological order is less than the total number of nodes (`V`) in the graph, it indicates a cycle.
       - This is because nodes involved in a cycle cannot be included in a valid topological order.

    4. Algorithm Steps:
       - Use a graph traversal algorithm suitable for topological sorting (e.g., Kahn's Algorithm or DFS-based topological sort).
       - After completing the sort, compare the count of nodes in the topological order with `V`.
       - If the count matches `V`, the graph is a DAG (no cycles). Otherwise, the graph contains a cycle.

    5. Conclusion:
       - A cycle in the graph prevents a valid topological order.
       - If Topo sort comes out to be exactly N element, then this means it's "DAG".



// Complexity:
    -> TC: O(V + E)
    -> SC: O(V)



*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to detect cycle in a directed graph. => BFS Solution -> Kahn's Algorithm
    bool isCyclic(int V, vector<vector<int>> adj) {
        
        // Precompute Indegree:
        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){   // iterate in adjacent nodes
                indegree[it]++;     // increment nodes incoming edges
            }
        }
        
        // BFS Solution:
        // Initially insert all the nodes with indegree '0' into queue.
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        
        int cnt = 0;    // counter helps us to count the number of element in our topo-sort elements
        while(!q.empty()){          // process until queue is not empty
            int node = q.front();   // get the front node
            q.pop();                // remove that node from queue.
            cnt++;                  // count the number of node that we are processing.
            
            for(auto it: adj[node]){             // traverse all the adjacent nodes:
                indegree[it]--;                  // decrement that adjacent node value.
                if(indegree[it] == 0) q.push(it); // if indegree value become '0', push that node into queue.
            }
        }
        
        
        // Last check if cnt == V, means there is no cycle, else there is cycle
        if(cnt == V) return false;  // return false
        return true;                // else return true, as cycle
    }
};


int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
        cout << "~" << "\n";
    }

    return 0;
}