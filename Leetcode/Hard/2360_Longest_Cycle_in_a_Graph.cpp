/*

//  2360. Longest Cycle in a Graph


//  Problem Statement: 
    -> You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
    -> The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.
    -> Return the length of the longest cycle in the graph. If no cycle exists, return -1.
    -> A cycle is a path that starts and ends at the same node.

 
// Example: 
    Example 1:
        Input: edges = [3,3,4,2,3]
        Output: 3
        Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
        The length of this cycle is 3, so 3 is returned.

    Example 2:
        Input: edges = [2,-1,3,1]
        Output: -1
        Explanation: There are no cycles in this graph.

 
// Observations: 
    -> Given directed graph, we need to find the largest size cycle from the given edges.


    // DFS Approach: 
        -> We know how to find the cycle Using DFS
        -> it's just we have to find total number of nodes falls into the cycle path.
        -> We have to return the maximum length of cycle..

        // Let's See how we can find cycle length using DFS:
            
            Example: 
                Input: edges = [3,3,4,2,3]
                Output: 3
                Explanation: The longest cycle in the graph is the cycle: 2 -> 4 -> 3 -> 2.
                The length of this cycle is 3, so 3 is returned.


                [0]-------->[3]<---[4]
                             ↑ \    ↑
                             |   ↘  |
                            [1]   [2]

            -> We will use another vector "depth" which will store the depth for every node from starting node:

                    depth[n] = {0}  -> Initially all 0's
            
            -> Let's run dfs with '0'
                    dfs(0, adj, vis, pathVis, depth):

                        vis[0] = 1
                        pathVis[0] = 1
                        Explore adj:
                            (!vis[3]):
                                depth[3] = depth[0] + 1 = 1
                                dfs(3)

                         0           1
                        [0]-------->[3]<---[4]
                                    ↑ \    ↑
                                    |   ↘  |
                                    [1]   [2]

                    dfs(3, adj, vis, pathVis, depth):

                        vis[3] = 1
                        pathVis[3] = 1
                        Explore adj[3]:
                            (!vis[2]):
                                depth[2] = depth[3] + 1 = 2
                                dfs(2)


                         0           1
                        [0]-------->[3]<---[4] 
                                    ↑ \    ↑
                                    |   ↘  | 2
                                    [1]   [2]


                    dfs(2, adj, vis, pathVis, depth):

                        vis[2] = 1
                        pathVis[2] = 1
                        Explore adj[2]:
                            (!vis[4]):
                                depth[4] = depth[2] + 1 = 3
                                dfs(4)

                         0           1       3
                        [0]-------->[3]<---[4] 
                                    ↑ \    ↑
                                    |   ↘  | 2
                                    [1]   [2] 

                    dfs(4, adj, vis, pathVis, depth):

                        vis[4] = 1
                        pathVis[4] = 1
                        Explore adj[4]:
                            (3): Already visited
                            (3): Also path Visited
                                -> Store Cycle depth:
                                    cycleLen = depth[node] - depth[adjNode] + 1
                                    cycleLen = depth[4] - depth[3] + 1
                                    cycleLen = 3 - 1 + 1 => 3
        
        -> Now, we only need to iterate in multiple component, & find the maximum depth of cycle.

        
// Complexity: 
    -> TC: O(n)
    -> SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Approach 3: Using Counter -> Accepted
class Solution {
private: 
    int n;
    int longest = -1;
    // DFS to detect cycle and calculate its length
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited, vector<int>& depth) {
        visited[node] = 1;
        pathVisited[node] = 1;

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                // Increase depth for next node
                depth[neighbor] = depth[node] + 1;
                dfs(neighbor, adj, visited, pathVisited, depth);
            } 
            // Found a back edge indicating a cycle
            else if(pathVisited[neighbor]) {
                int cycleLength = depth[node] - depth[neighbor] + 1;
                longest = max(longest, cycleLength);
            }
        }

        // Backtrack: unmark the current node from the path
        pathVisited[node] = 0;
    }

public:
    int longestCycle(vector<int>& edges) {
        n = edges.size();

        // Convert edge list into an adjacency list representation
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                adj[i].push_back(edges[i]);
            }
        }

        // Visited arrays and depth tracker
        vector<int> visited(n, 0);      // Marks nodes already fully processed
        vector<int> pathVisited(n, 0);  // Tracks nodes currently in the recursion stack
        vector<int> depth(n, 0);        // Stores depth of each node from the starting point

        // Run DFS on each component
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, pathVisited, depth);
            }
        }

        return longest;
    }
};


// Approach 2: TLE
class Solution {
private:
    int n;
    bool isCycle(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis,
                 vector<int>& path, unordered_set<int>& cycleNodes) {
        vis[node] = 1;
        pathVis[node] = 1;
        path.push_back(node);

        for (auto& neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (isCycle(neighbor, adj, vis, pathVis, path, cycleNodes))
                    return true;
            }
            else if (pathVis[neighbor]) {
                // Cycle detected: extract all nodes from neighbor to current node
                auto it = find(path.rbegin(), path.rend(), neighbor);
                while (it != path.rend()) {
                    cycleNodes.insert(*it);
                    ++it;
                }
                return true;
            }
        }

        path.pop_back();
        pathVis[node] = 0;
        return false;
    }

public:
    int longestCycle(vector<int>& edges) {
        n = edges.size();

        // Build adjacency list
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1)
                adj[i].push_back(edges[i]);
        }

        vector<int> vis(n, 0);
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> pathVis(n, 0);
                vector<int> path;
                unordered_set<int> cycleNodes;

                isCycle(i, adj, vis, pathVis, path, cycleNodes);

                // Update answer with the length of this cycle (if any)
                if (!cycleNodes.empty()) {
                    ans = max(ans, (int)cycleNodes.size());
                }
            }
        }

        return ans;
    }
};


// Approach 1: TLE
class Solution {
private: 
    int n;
    bool flag;
    bool isCycle(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis, set<int>& st) {
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto &it: adj[node]) {
            if(!vis[it]) {
                if(isCycle(it, adj, vis, pathVis, st)) {
                    if(flag) {
                        if(st.count(it)) flag = false;
                        st.insert(it);
                    }
                    return true;
                }
            } 
            else if(pathVis[it]) {
                if(flag) {
                    if(st.count(it)) flag = false;
                    st.insert(it);
                }
                return true;
            }
        }

        // Node which not fall into cycle:
        pathVis[node] = 0;
        return false;
    }
public:
    int longestCycle(vector<int>& edges) {
        n = edges.size();

        // Build adj List: 
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            if(edges[i] == -1) continue;
            adj[i].push_back(edges[i]);
        }


        // Find cycle in multiple Components: 
        vector<int> vis(n, 0);
        bool isCycleFound = false;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                vector<int> pathVis(n, 0);
                set<int> st;
                flag = true;
                if(isCycle(i, adj, vis, pathVis, st)) {
                    isCycleFound = true;
                }

                // Find cycle length:
                ans = max((int)(st.size()) ,ans);
            }
        }

        if(!isCycleFound) return -1;    // no cycle in any of the components:
        
        return ans;
    }
};
