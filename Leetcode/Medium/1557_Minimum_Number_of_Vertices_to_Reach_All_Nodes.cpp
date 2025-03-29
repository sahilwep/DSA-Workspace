/*

//  1557. Minimum Number of Vertices to Reach All Nodes


//  Problem Statement:
    -> Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [from[i], to[i]] represents a directed edge from node from[i] to node toi.
    -> Find the smallest set of vertices from which all nodes in the graph are reachable. 
    -> It's guaranteed that a unique solution exists.
    -> Notice that you can return the vertices in any order.

 
// Exapmle:

    Example 1:

        Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
        Output: [0,3]
        Explanation: It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5]. So we output [0,3].

    Example 2:

        Input: n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
        Output: [0,2,3]
        Explanation: Notice that vertices 0, 3 and 2 are not reachable from any other node, so we must include them. Also any of these vertices can reach nodes 1 and 4.

// Observation:
    -> If we carefully observe, the node which has indegree = 0, is our answer, easy right 😁

    

// Complexity:  
    -> TC: O(E + V)
    -> SC: O(V)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        vector<int> indegree(n, 0); // get the indegree of every node

        for(auto &it: edges) {
            indegree[it[1]]++;
        }
        
        vector<int> res;
        // Find the node which has "indegree =  0"
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                res.push_back(i);   // nodes stores in sorted fashion, as we are iterating from 0 to n-1
            }
        }   

        return res;
    }
};