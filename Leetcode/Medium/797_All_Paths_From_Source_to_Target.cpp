/*

//  797. All Paths From Source to Target


//  Problem Statement: 
    -> Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.
    -> The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).



Example 1:
    Input: graph = [[1,2],[3],[3],[]]
    Output: [[0,1,3],[0,2,3]]
    Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

Example 2:
    Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
    Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

 

// Observations: 
// Observations: 
    -> Given graph nodes 0 to n - 1
    -> Find the all possible path from source to destinations..

    // NOTE:  Graph is DAG

    // Approach: 
        -> We can use any traversal algorithm like DFS/BFS to find all possible path.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// DFS Approach: TC: O(2^n * n), SC: O(n)
class Solution {
private:
    int n;
    vector<vector<int>> ans;
    void dfs(int node, vector<vector<int>> &graph, vector<int> &path) {
        path.push_back(node);   // insert called node in path

        if(node == n - 1) { // If reached the destination
            ans.push_back({path});  // store that path into our answer
        }
        else {  // continue dfs for neighbors:
            for(auto &it: graph[node]) { 
                dfs(it, graph, path);
            }
        }

        path.pop_back();    // remove inserted node for other path explorations
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        
        vector<int> path;
        dfs(0, graph, path);
    
        return ans;
    }
};



// BFS Approach 1: With maintaining Visited array -> We are maintaining visited array for every node which will restrict every node to visit again & again if they have cycle or undirected graph.
class Solution {    // TC: O(2^n * n), SC: O(2^n * n)
private:
    typedef pair<int, vector<int>> pvr;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n, 0);
        vector<vector<int>> ans;

        queue<pvr> q;
        q.push({0, {0}});   // src node with list{src}
        vis[0] = 1; // mark source node as visited
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int node = it.first;
            vector<int> seq = it.second;

            for(auto &it: graph[node]) {
                if(!vis[it]) {
                    seq.push_back(it);  // push that node in our sequence.


                    if(it == n-1) { // check whether we are at last node or not?
                        ans.push_back({seq});
                    }

                    q.push({it, {seq}});    // push that node & sequence into the queue.

                    seq.pop_back(); // remove in order to find other possible sequence..

                }
            }

        }

        return ans;
    }
};


// BFS Approach 2: Without maintaining any visited array: Because Graph is DAG -> No-cycle & directed So, there's no need to maintain visited array, because we will never visit same node again in DAG
class Solution {    // TC: O(2^n * n), SC: O(2^n * n)
private:
    typedef pair<int, vector<int>> pvr;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> ans;

        queue<pvr> q;
        q.push({0, {0}});   // src node with list{src}
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int node = it.first;
            vector<int> seq = it.second;

            for(auto &it: graph[node]) {
                seq.push_back(it);  // push that node in our sequence.

                if(it == n-1) { // check whether we are at last node or not?
                    ans.push_back({seq});
                }

                q.push({it, {seq}});    // push that node & sequence into the queue.

                seq.pop_back(); // remove in order to find other possible sequence..

            }

        }

        return ans;
    }
};