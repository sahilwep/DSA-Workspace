/*

//  210. Course Schedule II


// Problem Statement:
    -> There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
    -> For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
    -> Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.



// Observation: 
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
        -> Check weather it has cycle or not, if it has return result vector : else return empty vector



// Complexity:
    -> TC: O(V + E)
    -> SC: O(V)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BruteForce Solution:
class Solution {
private:
    bool isCycle(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto &it : adj[node]) {
            if (!vis[it]) {
                if (isCycle(it, adj, vis, pathVis)) return true;
            } else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }
    // Dfs function to get linear ordering:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st) {
        vis[node] = 1;
        for (auto &it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        for (auto &it : pre) {
            adj[it[1]].push_back(it[0]);
        }

        // Check for cycle
        vector<int> vis(n, 0), pathVis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (isCycle(i, adj, vis, pathVis)) return {};
            }
        }

        // If no cycle, find a valid order using topo-sort DFS implementations
        stack<int> st;
        vector<int> vis2(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis2[i]) dfs(i, adj, vis2, st);
        }

        vector<int> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};


// Kahn's algorithm Based Solution:
class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
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

        vector<int> res;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);

            for(auto it: adj[node]){    // Traverse adjacent nodes
                indegree[it]--;         // decrement the count of indegree of that current adjacent node
                if(indegree[it] == 0) q.push(it);   // if that count is 0, push that adj. node into queue
            }
        }

        // if cnt == V, means there is no-cycle & we have completed topo-sort, so return list
        if(res.size() == V) return res;  // we have complete the course, return list.
        return {};   // else can't complete course, return empty list
    }
};