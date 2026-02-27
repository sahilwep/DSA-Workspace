/*

//  3123. Find Edges in Shortest Paths


//  Problem Statement: 
    - You are given an undirected weighted graph of n nodes numbered from 0 to n - 1. The graph consists of m edges represented by a 2D array edges, where edges[i] = [ai, bi, wi] indicates that there is an edge between nodes ai and bi with weight wi.
    - Consider all the shortest paths from node 0 to node n - 1 in the graph. You need to find a boolean array answer where answer[i] is true if the edge edges[i] is part of at least one shortest path. Otherwise, answer[i] is false.
    - Return the array answer.
    - Note that the graph may not be connected.

 
// Example:
    Example 1:
        Input: n = 6, edges = [[0,1,4],[0,2,1],[1,3,2],[1,4,3],[1,5,1],[2,3,1],[3,5,3],[4,5,2]]
        Output: [true,true,true,false,true,true,true,false]
        Explanation: The following are all the shortest paths between nodes 0 and 5:
                The path 0 -> 1 -> 5: The sum of weights is 4 + 1 = 5.
                The path 0 -> 2 -> 3 -> 5: The sum of weights is 1 + 1 + 3 = 5.
                The path 0 -> 2 -> 3 -> 1 -> 5: The sum of weights is 1 + 1 + 2 + 1 = 5.


    Example 2:
        Input: n = 4, edges = [[2,0,1],[0,1,1],[0,3,4],[3,2,2]]
        Output: [true,false,false,true]
        Explanation: There is one shortest path between nodes 0 and 3, which is the path 0 -> 2 -> 3 with the sum of weights 1 + 2 = 3.


// Observations:
    - We are given n nodes & list of edges
    - we need to return the ans[i] from the edges[i] list who are the part of shortest path from node '0' to node 'n-1'

    // Approach 1:    
        - First we need to find all the shortest path from node '0' to 'n-1'
            - all means, every possible path with shortest distance.
            - From that path whoever edges are contributing to shortest path, we will have to pick those..

        // Shortest path:
            - Using dijkstra's we can find the shortest path considering src = '0'.
            - During finding the shortest path, we will store the parent of every node.
                - this way we can have informations about every path leading to destinations with minimum cost.
            
            - NOTE: Single node can have multiple parent that leads to shortest path, so we instead of storing single parent, we will store multiple parent.
                    vector<vector<int>> parent(n);     => This is how our parent looks like
        
        // How to find the edges that belongs to shortest path:
            - we have 2D list of parents.
            - We can use DFS/BFS and iterate from src = "n - 1" to dst = '0'
            - And in-between we will store all the edges, somewhere, where we can query it efficiently.

        // Now we have edges that are the part of Shortest path:
            - We just need to iterate in given edges & check if that edges belongs to the shortest path list or not?
            - and we can store the answer.


        // Extra:
            - we can convert the edges into string like "u_v" & store somewhere like u_set
            - and check in O(1) time while iterating in edges.
            - Or we can encode the edge u, v    => (u * V + v) so and store them directly in u_set & efficiently query..
            - Our Fist Approach:
                - Converts the graph into Shortest path DAG
                - Using Parents, we get the multiple path which directed from dst to src, with min cost.

        // Complexity:
            - TC: O(E log V)
            - SC: O(V + E)


    // Approach 2:
        - If we carefully observe then we will found that every edge that were part of shortest path:
        - let say we have some node u, v which falls into shortest path:
            
                src......u--------v.......dst

            - Using Dijkstra's we can easily calculate the shortest path from:
                src = "0"           => say "distSrc"
                src = "n - 1"       => say "distTarget"
            - We will have two list which contains the shortest path from src = 0 & src = n - 1, and if some edge u----v falls into shortest path then it must follow this conditions:

                    distSrc[u] + wt + distTarget[v] == distSrc[n-1]         ...(I)
                                    OR  
                    distSrc[v] + wt + distTarget[u] == distSrc[n-1]         ...(II)


                Fist Condition (I) says
                    Distance from source as '0' to node[u]
                    Edge wt of edge u----v
                    Distance from source as 'n-1' to node[v]
                    is equal to distance from src '0' to destinations 'n-1'
                

                Second Conditions (II), is because we have undirected graph
                    and we are not sure that graph always have this configurations:
                        src..........u-------v.......dst
                    It can have something like:
                        src..........v-------u.......dst
                    So, it's essential to check the both conditions :)
                    So, the second conditions is for the other possibility {-_*}!
                    and this conditions says:
                        Distance from src = '0' to node 'v'
                        Edge wt of edge v----u
                        Distance from src = 'n - 1' to node 'u'
                        is equal to distance from src '0' to destinations 'n-1'

            - These Condition Should Fundamentally Valid if the edge falls into the shortest path...


        // Complexity:
            - TC: O(E log V)
            - SC: O(V + E)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Approach 1:
class Solution {
private:
    int V;
    vector<int> dist;
    vector<vector<int>> parent;
    void dijkstra(int src, vector<vector<pair<int, int>>>& adj) {
        
        dist.resize(V, INT_MAX);
        parent.resize(V);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        pq.push({0, src});
        dist[src] = 0;
        parent[src].push_back(src);

        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            for(auto &[v, wt]: adj[node]) {
                int newCost = cost + wt;

                if(newCost < dist[v]) {
                    dist[v] = newCost;
                    pq.push({newCost, v});
                    parent[v].clear();
                    parent[v].push_back(node);
                } else if(newCost == dist[v]) {
                    parent[v].push_back(node);
                }
            }
        }
    }
    void dfs(int node, vector<int> & vis, set<pair<int, int>>& st) {
        if(node == 0) return;     // reached src

        // Explore:
        for(auto &par: parent[node]) {
            int u = min(par, node);
            int v = max(par, node);
            st.insert({u, v});

            if(!vis[par]) {
                vis[par] = 1;
                dfs(par, vis, st);
            }
        }
    }
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        V = n;

        // Build graph adj list:
        vector<vector<pair<int, int>>> adj(V);
        for(auto &it: edges) {  // O(E)
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
    
        // Find shortest distance using dijkstra's
        dijkstra(0, adj);   // O(E log V)

        // Filter out the edges that were in part of shortest path:
        set<pair<int, int>> st;
        vector<int> vis(V, 0);
        dfs(V - 1, vis, st);    // O(V + E)

        // Find the edge contributing in shortest path:
        int m = edges.size();
        vector<bool> ans(m, false);
        for(int i = 0; i < m; i++) {    // O(E log E)
            int u = edges[i][0], v = edges[i][1];

            if(st.count({min(u, v), max(u, v)})) {  // edge is the part of shortest path.
                ans[i] = true;
            }
        }

        return ans;
    }
};


// Approach 2:
class Solution {
private:
    int V;
    typedef long long ll;
    vector<ll> dijkstra(int src, vector<vector<pair<int, int>>>& adj) {
        
        vector<ll> dist(V, LLONG_MAX);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            for(auto &[v, wt]: adj[node]) {
                ll newCost = cost + wt;

                if(newCost < dist[v]) {
                    dist[v] = newCost;
                    pq.push({newCost, v});
                }
            }
        }

        return dist;
    }
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        V = n;

        // Build graph adj list:
        vector<vector<pair<int, int>>> adj(V);
        for(auto &it: edges) {
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
    
        // Find shortest distance using dijkstra's  // O(E log V)
        vector<ll> distS = dijkstra(0, adj);       // shortest path from start
        vector<ll> distT = dijkstra(V - 1, adj);   // shortest path from target


        // Find the edge contributing in shortest path:
        int m = edges.size();
        vector<bool> ans(m, false);
        ll D = distS[V - 1];

        for(int i = 0; i < m; i++) {    // O(E)
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            
            if(distS[u] != LLONG_MAX && distT[v] != LLONG_MAX &&
               distS[u] + wt + distT[v] == D) {
                ans[i] = true;
            } 
            if(distT[u] != LLONG_MAX && distS[v] != LLONG_MAX &&
               distS[v] + wt + distT[u] == D) {
                ans[i] = true;
            }
        }

        return ans;
    }
};