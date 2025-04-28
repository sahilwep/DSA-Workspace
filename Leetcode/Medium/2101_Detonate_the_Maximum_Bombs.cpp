/*

//  2101. Detonate the Maximum Bombs


//  Problem Statement: 


// Observations: 
    -> Let' observe this in graph way: 
        B1 = (x1, y1), B2 = (x2, y2)

        -> Shortest Distance from two point on x-y coordinates..

                Distance => sqrt((x2-x1)^2 + (y2-y1)^2)


    -> one bomb will detonated other if and only if other lies in ther radius.
    -> In simple if distance b/w B1 & B2 = X & B1 radius is grater than X then only B2 will detonated..
            Two bomb => B1 & B2
                B1 radius R
                Distance from both B1 & B2 => D

                If(R > D) => B1 will detonated B2

    -> This denotes there is only one way relations for detonating other bomb...
    -> We can consider this as directed Graph.

    // Build Graph Adj List: 

        Problem: [[2,1,3],[6,1,4]]
                    B1      B2


                -> we have coordinates (x1, y1, radius)
                -> We can build 

            For Every Bombs: 
                B1 & B2
                Get Distance => sqrt((abs(x2-x1)^2 + abs(y2-y1)))
                compare it with their radius.
                & build adj list
    

    // Approach: 
        -> Build Adj list
            -> TC: O(V^2)
        -> Run dfs/bfs from every node & find the maximum bomb/node count..
            -> TC: O(V * (V + E))


    // Complexity: 
        -> TC: O(V^3)
        -> SC: O(V^2)                         


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    int dfs(int node, vector<vector<int>>& adj, vector<int> &vis) {
        vis[node] = 1;
        int cnt = 1;

        for(auto &it: adj[node]) {
            if(!vis[it]) {
                cnt += dfs(it, adj, vis);
            }
        }

        return cnt;
    }
    int bfs(int node, vector<vector<int>>& adj, vector<int> &vis) {
        queue<int> q;
        int cnt = 0;
        
        vis[node] = 1;
        q.push(node);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            cnt++;

            for(auto &it: adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return cnt;
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int V = bombs.size();   // total number of nodes..

        // Build Adj list: 
        vector<vector<int>> adj(V);

        for(int i = 0; i < V; i++) {
            int x1 = bombs[i][0], y1 = bombs[i][1];
            double r1 = (double)bombs[i][2];
            for(int j = i + 1; j < V; j++) {
                // Get distance:
                int x2 = bombs[j][0], y2 = bombs[j][1];
                double r2 = (double)bombs[j][2];

                double D = sqrt(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2));

                // directed edge
                if(r1 >= D) adj[i].push_back(j);    // u ------> v
                if(r2 >= D) adj[j].push_back(i);    // u <------ v
            }
        }

        // Find the maximum number of nodes we can reach from any of the node...
        int ans = 0;
        for(int i = 0; i < V; i++) {
            vector<int> vis(V, 0);

            ans = max(ans, dfs(i, adj, vis));
            // ans = max(ans, bfs(i, adj, vis));
        }

        return ans;
    }
};