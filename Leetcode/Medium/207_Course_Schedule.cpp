/*

//  207. Course Schedule

// Problem Statement:
    -> numCourse labeled from '0' to 'numCourse - 1'
    -> Given prerequisites, where preres[i] = [a[i], b[i]]
        -> You must take course b[i] first if you want to take course a[i].
    
    -> Example:
        the pair: [0, 1], indicates that to take course '0' you have to first take course '1'.

    -> Return true if you can finish all course otherwise return false.


// Efficient Solution Topo-Sort: 
    -> If we can co-relate it with Topological Sort
    -> In Topological sort, if there is a directed node u to v, then u must occur before v
    -> Also Topological sort only work with DAG -> Directed acyclic Graph

    // Now Corelate with question:
        -> Given numCourse = Number of nodes
                0 to n-1 => Total Nodes

        -> We are given a list of prerequisites: [[a[i], b[i]]]
                must take b[i] first if we want to take a[i]
                similarly, u = b[i] -> v = a[i]
                must take u -> v, must take u before v


    // Conclusion: 
        -> Build Graph
        -> Use Topo-sort
        -> Check weather it has cycle or not, if it has return false : else return true


    // Complexity:
        -> TC: O(V + E)
        -> SC: O(V)



// BruteForce Solution: 
    -> use any traversal algorithm & traverse & find whether we reach destinations or not?
    -> It may be possible we may fall into cycle -> In that case we return false, because we are given that all given course should be completed.
        -> First we should check the cycle in graph, if graph has no-cycle -> We are good to go.
    -> NOTE: IT may be possible that graph has no-cycle, but there is no-valid path to complete the course u -> v

    -> NOTE: It may be possible graph has multiple components, so we need to take care of that also.
    
    // Complexity:
        -> TC: O(V + E) + O(pre.size() * (V + E)) => O(pre.size() * (V + E))
        -> SC: O(V + E)




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BruteForce Solution:
class Solution {
private:
    bool isCycle(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis) {    // find cycle in directed graph:
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto &it: adj[node]) {
            if(!vis[it]) {
                if(isCycle(it, adj, vis, pathVis)) return true;
            }
            // if visited & pathVisited
            else if(pathVis[it]) {  // if node is already visited & it's also path-visited, means someone has already explored that path.
                return true;    // cycle found.
            }
        }

        pathVis[node] = 0;  // unmark that path which has no-cycle in it way...
        return false;   // no cycle found:
    }
    // NOTE: If path is directed & no cycle: DAG => no need to maintain visited array
    bool isPossible(int node, int dst, vector<vector<int>> &adj) {    // check if there is a path from 'u' to 'v'
        if(node == dst) return true;

        for(auto &it: adj[node]) {
            if(isPossible(it, dst, adj)) return true;
        }

        return false;
    }   
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        // Build Graph: 
        vector<vector<int>> adj(n);
        for(auto &it: pre) {    // given order [u, v] => node v ----> u
            int u = it[0], v = it[1];
            adj[v].push_back(u);    // directed graph.
        }

        // Check Cycle:
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(isCycle(i, adj, vis, pathVis)) return false; // if cycle is found, we can't finish the course...
            }
        }

        // Now, check path u ----> v is reachable or not?
        for(auto &it: pre) {
            int u = it[0], v = it[1];
            if(!isPossible(v, u, adj)) return false;    // if we arn't able to reach destinations, return false;
        }
        
        return true;
    }
};





// Efficient Solution: Topo-Sort
class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        // Generate Graph Nodes;
        vector<vector<int>> adj(V);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        // Topo sort:
        // Process Indegree
        vector<int> indegree(V, 0);
        for(int i=0;i<V;i++){
            for(auto it: adj[i]) indegree[it]++;
        }

        queue<int> q;
        for(int i=0;i<V;i++) if(indegree[i] == 0) q.push(i); 

        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto it: adj[node]){    // Traverse adjacent nodes
                indegree[it]--;         // decrement the count of indegree of that current adjacent node
                if(indegree[it] == 0) q.push(it);   // if that count is 0, push that adj. node into queue
            }
        }

        // if cnt == V, means there is no-cycle & we have completed topo-sort, so return 1
        if(cnt == V) return 1;  // we have complete the course.
        return 0;   // else can't complete course.
    }
};