/*

//  207. Course Schedule

// Problem Statement:
    -> numCourse labeled from '0' to 'numCourse - 1'
    -> Given prerequisites, where preres[i] = [a[i], b[i]]
        -> You must take course b[i] first if you want to take course a[i].
    
    -> Example:
        the pair: [0, 1], indicates that to take course '0' you have to first take course '1'.

    -> Return true if you can finish all course otherwise return false.


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
        -> Check weather it has cycle or not, if it has return false : else return true


// Complexity:
    -> TC: O(V + E)
    -> SC: O(V)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

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