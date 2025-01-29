/*

//  1462. Course Schedule IV


//  Problem Statement: 
    -> There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.
        -> For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
    -> Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.
    -> You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.
    -> Return a boolean array answer, where answer[j] is the answer to the jth query.

 

// Example: 

    Example 1:
        Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
        Output: [false,true]
        Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
        Course 0 is not a prerequisite of course 1, but the opposite is true.

    Example 2:
        Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
        Output: [false,false]
        Explanation: There are no prerequisites, and each course is independent.

    Example 3:
        Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
        Output: [true,true]


// Observations: 
    1. Dependencies:
        -> The prerequisites define a directed graph where an edge (a -> b) means "a must be completed before b."

    2. Indirect Dependencies:
        -> If course 'a' is a prerequisite for course 'b', and course 'b' is a prerequisite for course 'c', then course 'a' is also a prerequisite for course 'c'.
        -> This implies transitive closure in the graph.

    3. Key Subtasks:
        -> Determine if a path exists from course 'u' to course 'v' in the graph for each query.
        -> Ensure we account for direct and indirect dependencies.


// Approach 1:
    -> We can directly check the prerequisites for every query, by using any dfs/bfs Algorithm...
    // Complexity: 
        -> TC: O(V + E)
        -> SC: O(V)



// Approach 2: Pre-process Queuing calls:
    -> Pre-process the query for dfs calls for every query:
    -> We can make a 2-D Grid of size n * n, where n = total number of nodes,
    -> & for every two different nodes, we will call dfs/bfs & store the answer into result.
    // Complexity:
        -> TC: O(n³) + O(E) + O(Q) ≈ O(n³) (assuming E and Q are relatively smaller than n³ in worst case).
        -> AS: O(n^2), to store the answer of dfs queries.


// Approach 3: Topo-sort, Kahn's Algorithms
    -> we need to find the query, & for every source, we need to find whether we are able to reach the dest or not?
    -> Topo-sort will give us the linear ordering of graph, which will tell's us which node coming first befor which node..
    -> We can take leverage of that...
    -> But the problem, lies, when we need to check for all previous nodes, is they reachable or not?
    -> Example:
        -> Consider '*' as directed edge.

                [1]------------*[0]
                 \              *
                  \            /
                    \        /
                      \     /
                        * /
                        [2]

        TOPO-Sort Ordering: {1, 2, 0}

            -> For '0', we need to check whether we are {1, 2} is the part of that or not?
            -> When we have long ordering, we will be needed to iterate back & find whether that node is reachable or not?
            -> Also when have some graph like:

                    Input
                        numCourses = 4
                        prerequisites = [[2,3],[2,1],[0,3],[0,1]]
                        queries = [[0,1],[0,3],[2,3],[3,0],[2,0],[0,2]]

                    Output: [true,true,true,false,false,false]

                                 /--------[0]----------\
                        [1]<-----                       ----->[3]
                                 \--------[2]----------/


                Topo-sort valid possible ordering:
                        0 → 2 → 1 → 3
                        2 → 0 → 1 → 3
                        0 → 2 → 3 → 1
                        2 → 0 → 3 → 1

            -> In this case, when some nodes are independet to others, we need to make sure we will store all the dependent nodes...
            -> for query: [2, 0], [0, 2], when we are comparing with topo-sort ordering, in some case we have true, & in some we have false.
            -> So, we need to make sure to store the dependent nodes for every nodes & then we will perfrom valid query:
            -> Example: 
                    {0} -> {}
                    {1} -> {0, 2}
                    {3} -> {0, 2}
                    {2} -> {}

                We need to store our data like this, So that we can access source & destination in O(1)

                    unordered_map<int, unordered_set<int>> data

                By using these, we can query in O(1), once we complete with topo-sort:

    // Complexity:
        -> TC: O(V^2 + E + Q)
        -> SC: O(V^2 + E + Q)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Approach 3: Topo-sort, Kahn's Algorithms
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        // Build Graph Adjacency list & indegree of nodes: TC: O(E)
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto it: prerequisites){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);    //  u ----> v
            indegree[v]++;
        }

        // Apply Topo-sort, TC: O(V + E)
        // Get the nodes having indegree = 0
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0) q.push(i);
        }


        unordered_map<int, unordered_set<int>> mp;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &ngbr: adj[node]){ // O(V)
                mp[ngbr].insert(node);  // insert the parent node into neighbors.
                // find the prerequisites of node as well and by transitivity, they are prereq of ngbr node as well.
                for(auto &preq: mp[node]){ // insert all the parent of parents nodes as well, from map, TC: O(V)
                    mp[ngbr].insert(preq); 
                }

                // Topo-sort Logic:
                indegree[ngbr]--;
                if(indegree[ngbr] == 0) q.push(ngbr);
            }
        }


        // // Print the nodes & their dependency: Debug
        // for(auto i: mp){
        //     cout << i.first << ": ";
        //     for(auto it: i.second){
        //         cout << it << " ";
        //     }
        //     cout << endl;
        // }


        // Last Query:
        int Q = queries.size();
        vector<bool> ans(Q, false);

        for(int i=0;i<Q;i++){   // for every query:
            int src = queries[i][0];
            int dest = queries[i][1];

            bool reachable = mp[dest].count(src);    // check for destination, whether source is present or not?
            ans[i] = reachable;
        }

        return ans;
    }
};


// Approach 2: Pre-process Queuing calls:
class Solution {
private:
    bool dfs(int src, int dest, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[src] = 1;   // mark that source node as visited
        if(src == dest) return true;    // whenever we reaches the source to destinations return 1;
        
        // Check adjacent nodes:
        for(auto it: adj[src]){
            if(!vis[it]){ 
                if(dfs(it, dest, adj, vis)) return true;    // if we get true, only then return true
            }
        }

        return false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        // Build Graph Adjacency list:
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);    //  u ----> v
        }

        // Pre-Process the DFS Queries Calls: TC: O(n^2)
        vector<vector<bool>> grid(numCourses, vector<bool> (numCourses, false));
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<numCourses;j++){
                if(i != j){
                    vector<bool> vis(numCourses, false);
                    grid[i][j] = dfs(i, j, adj, vis);
                }
            }
        }

        int Q = queries.size();
        vector<bool> ans(Q, false);

        for(int i=0;i<Q;i++){   // for every query:
            int src = queries[i][0];
            int dest = queries[i][1];

            ans[i] = grid[src][dest];   // get the answer in O(1)
        }

        return ans;
    }
};


// Approach 1: Using BFS/DFS
class Solution {
private:
    bool dfs(int src, int dest, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[src] = 1;   // mark that source node as visited
        if(src == dest) return true;    // whenever we reaches the source to destinations return 1;
        
        // Check adjacent nodes:
        for(auto it: adj[src]){
            if(!vis[it]){ 
                if(dfs(it, dest, adj, vis)) return true;    // if we get true, only then return true
            }
        }

        return false;
    }
    bool bfs(int src, int dest, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[src] = 1;   // mark starting node as visited
        if(src == dest) return true;    // if src == dest, return true.

        queue<int> q;
        q.push(src);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == dest) return true;   // if we reach to answer, return true.

            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;    // mark that visited
                    q.push(it); // push it into queue.
                }
            }
        }

        return false;   // else return false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        // Build Graph Adjacency list:
        vector<vector<int>> adj(numCourses);
        for(auto it: prerequisites){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);    //  u ----> v
        }

        int Q = queries.size();
        vector<bool> ans(Q, false);

        for(int i=0;i<Q;i++){
            int src = queries[i][0];
            int dest = queries[i][1];
            
            vector<bool> vis(numCourses, false);
            // bool isFound = dfs(src, dest, adj, vis);
            bool isFound = bfs(src, dest, adj, vis);

            ans[i] = isFound;
        }

        return ans;
    }
};
