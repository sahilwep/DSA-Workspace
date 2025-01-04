/*

//  G-22. Kahn's Algorithm | BFS


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

    -> Let's use BFS Algorithm with some modification & observe the working:

        // Example: Indegree of every node:

                        [5]----->[0]<------[4]
                        |                   | 
                        |                   |
                        ↓                   ↓
                        [2]----->[3]------>[1]

                                adj[] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}}  -> adjacent nodes
                                         0   1    2    3     4       5

            Indegree[] = {2, 2, 1, 1, 0, 0}
                          0  1  2  3  4  5      -> Nodes
                
        -> Topo-Sort: If there is an edge b/w u & v, 'u' appear before 'v' in linear ordering.
        
        -> Since '5' & '4' do not have any incoming edges, we can place '5' or '4' at the staring in the linear ordering.
        -> Initially there will always be a node whose Indegree will be 0

    // STEP 1: Insert all node with Indegree = '0' into queue.
                queue = {5, 4}

        -> Now '4' and '5' would be having edge to someone, so they were getting into someone, so take out: 
        -> We can take any, but for now take '4' out first:
                '4' was into someone, so take out '4'
                    4 -> {0, 1}

                            res = {4}
                    0:
                        Reduce the indegree:
                        Indegree[] = {1, 2, 1, 1, 0, 0} -> indegree will reduce
                                      0  1  2  3  4  5      -> Nodes
                        -> After removeing out, from indegree, check is the indegree is having '0' -> NO
                            
                    1: 
                        Reduce the indegree:
                        Indegree[] = {1, 1, 1, 1, 0, 0} -> indegree will reduce
                                      0  1  2  3  4  5      -> Nodes
                        -> After removeing out, from indegree, check is the indegree is having '0' -> NO
                    
                    -> '4' is done: queue = {5}

        -> Now take out 5:
            '5' will be in our linear ordering:
                    5 -> {0, 2}

                            res = {4, 5}
                    0: 
                        Reduce the indegree:
                        Indegree[] = {0, 1, 1, 1, 0, 0} -> indegree will reduce
                                      0  1  2  3  4  5      -> Nodes
                        -> After removeing out, from indegree, check is the indegree is having '0' -> YES, so will take this '0' and put this into queue.
                
                    2:
                        Reduce the indegree:
                        Indegree[] = {0, 1, 0, 1, 0, 0} -> indegree will reduce
                                      0  1  2  3  4  5      -> Nodes
                        -> After removeing out, from indegree, check is the indegree is having '0' -> YES, so will take this '2' and put this into queue.
                
                    -> '5' is done: queue = {0, 2}
        
        -> Now take out 0:
            '0' will be in our linear ordering:
                    0 -> {}

                            res = {4, 5, 0}
                    
                    -> '0' is done: queue = {2}
        
        -> Now take out 2:
            '2' will be in our linear ordering:
                    2 -> {3}

                            res = {4, 5, 0, 2}
                    3:
                        Reduce the indegree:
                        Indegree[] = {0, 1, 0, 0, 0, 0} -> indegree will reduce
                                      0  1  2  3  4  5      -> Nodes
                        -> After removeing out, from indegree, check is the indegree is having '0' -> YES, so will take this '3' and put this into queue.

                    -> '2' is done: queue{3}
        
        -> Now take out 3:
            '3' will be in our linear ordering:
                    3 -> {1}

                            res = {4, 5, 0, 2, 3}
                    
                    1:
                        Reduce the indegree:
                        Indegree[] = {0, 0, 0, 0, 0, 0} -> indegree will reduce
                                      0  1  2  3  4  5      -> Nodes
                        -> After removeing out, from indegree, check is the indegree is having '0' -> YES, so will take this '1' and put this into queue.

                    -> '3' is done: queue{1}
        
        -> Now take out 1:
            '1' will be in our linear ordering:
                    1 -> {}
                            res = {4, 5, 0, 2, 3, 1}
                    
                    -> '1' is done: queue {} -> empty, break out.

        
        Final Linear Ordering: res = {4, 5, 0, 2, 3, 1}


    // In simple:
        -> Initialize Indegree & fill indegree of every node
        -> First insert all nodes whose indegree '0'
        -> process until queue is not empty:
            -> get the node:
            -> store it into result.
            -> Process their adjacent nodes:
                -> reduce the number of indegree of that adjacent node.
                -> if this adjacent node indegree becomes '0' store it into queue.

        -> Last return the result.


    // How to find Indegree:
        -> Example:
            there is a edge going from 2 to 3
            2 -> 3, here 2 is connected to 3, 
            we can say indegree of '3' is increased.

        -> Traverse in adjacent nodes, & whatever is there, just do: indegree[adj[i]]++




// Problem Statement:
    -> Given an adjacency list for a Directed Acyclic Graph (DAG) where adj[u] contains a list of all vertices v such that there exists a directed edge u -> v. Return topological sort for the given graph.
    -> Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
    -> Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be 1 else 0.



*/

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int V = adj.size();
        
        // process indegree of every node:
        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++){   // for every node:
            for(auto it: adj[i]){   // for every adjacent connected nodes:
                indegree[it]++;     // increment their indegree
            }
        }
        
        
        // Now BFS: 
        // Initially insert all nodes into queue, whose indegree initially '0'
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        vector<int> res;    // contains topo sort result
        
        while(!q.empty()){          // process queue until it's not empty:
            int node = q.front();   // get the front node
            q.pop();                // remove that node from queue.
            res.push_back(node);    
            
            // Explore adjacent nodes & compute result:
            for(auto it: adj[node]){
                indegree[it]--;         // decrement the indegree value from that node, as node is done now.
                if(indegree[it] == 0){  // check if indegree of that node is '0', push it into queue.
                    q.push(it);         // push it into queue.
                }
            }
        }
        
        return res; // last return the result.
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
        cout << "~" << "\n";
    }
    return 0;
}