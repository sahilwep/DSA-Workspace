/*

//  3373. Maximize the Number of Target Nodes After Connecting Trees II



//  Problem Statement: 
    -> There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.
    -> You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
    -> Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.
    -> Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.
    -> Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

 
// Example: 

    Example 1:
        Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]
        Output: [8,7,7,8,8]
        Explanation:
            For i = 0, connect node 0 from the first tree to node 0 from the second tree.
            For i = 1, connect node 1 from the first tree to node 4 from the second tree.
            For i = 2, connect node 2 from the first tree to node 7 from the second tree.
            For i = 3, connect node 3 from the first tree to node 0 from the second tree.
            For i = 4, connect node 4 from the first tree to node 4 from the second tree.

    Example 2:
        Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]]
        Output: [3,6,6,6,6]
        Explanation: For every i, connect node i of the first tree with any node of the second tree.


// Observations: 
    -> This Question is very similar to the "3372. Maximize the Number of Target Nodes After Connecting Trees I"
        -> Problem: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/
        -> Solution: https://github.com/sahilwep/DSA-Workspace/blob/main/Leetcode/Medium/3372_Maximize_the_Number%20of_Target_Nodes_After_Connecting_Trees_I.cpp
    


    // BruteForce Solution: TLE
        -> It's just we have to include those node which are at even edge distance
        -> For Tree 1: 
            -> count the number of nodes which are at even distance
        -> For Tree 2:
            -> count the number of nodes which are at odd distance.



    // Optimization Idea:
        -> In any tree, if node `u` is at even distance from node `v`, 
        -> then node `v` is also at even distance from node `u`. This is due to the tree being an undirected acyclic graph
        -> Example:

            Tree (Starting from node 0
                [0]-----[1]----[2]----[3]-----[4]
                |               |              |
                1(even)     0(odd)       1(even

            -> Starting from node 0:
                -> Even distance nodes = [0, 2, 4]
                -> Total nodes = 3
            -> Starting from node 2:
                -> Even distance nodes = [0, 2, 4]
                -> Total nodes = 3

        -> This symmetry means we can:
            -> Start from any node (e.g., 0)
            -> Label all nodes with 0 (even distance) or 1 (odd distance)
            -> Count how many even/odd nodes exist
            -> For each node:
                -> If it's at even distance, it has access to `evenCount` target nodes
                -> If it's at odd distance, it has access to `oddCount` target nodes


        //  Steps for Tree 1
            // Step 1:
                -> Build the adjacency list for Tree 1

            //  Step 2:
                -> Run BFS from any node (say node 0) to mark each node as either:
                    -> 0: at even distance
                    -> 1: at odd distance
                -> Use a vector `val1` to store these flags
                
            //  Step 3:
                -> Count total even distance nodes = even1
                -> Count total odd distance nodes = odd1

            //  Step 4:
                -> For every node in Tree 1:
                    -> If it's even distance => it can target `even1` nodes
                    -> If it's odd distance  => it can target `odd1` nodes
                -> Overwrite the `val1` vector with these counts


        // Steps for Tree 2 
            // Step 5:
                -> Repeat the same BFS process for Tree 2
                -> Store the parity (even/odd) in a vector `val2`
                -> Count even2 and odd2 nodes

            // Step 6:
                -> Maximum group size in Tree 2 = max(even2, odd2)
                -> This is the best possible set of target nodes to connect


        // Final Step: Build Result
            // Step 7:
                -> For every node in Tree 1, the maximum possible target nodes = val1[i] + max(even2, odd2)
                -> Store this in result vector and return


// Complexity:
    -> TC: O(N + M) where N = nodes in Tree 1, M = nodes in Tree 2 (because we do BFS for each tree once)
    -> SC: O(N + M) for adjacency lists and visited vectors

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution: Accepted
class Solution {
private:
    // Function to mark node at even distance:
    void dist(int node, vector<vector<int>> adj, vector<int>& parity) {
        int n = adj.size();

        vector<int> vis(n, 0);
        queue<pair<int, int>> q;    // flag, node

        q.push({0, node});  // default flag as "flag = 0"
        vis[node] = 1;

        while(!q.empty()) {
            auto [flag, node] = q.front();
            q.pop();

            parity[node] = flag;

            for(auto &it: adj[node]) {
                if(!vis[it]) {
                    q.push({!flag, it});
                    vis[it] = 1;
                }
            }
        }
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;  // tree 1
        int m = edges2.size() + 1;  // tree 2


        // Step 1: Build adj list for tree 1 & 2:
        // Build graph adj list form tree 1:
        vector<vector<int>> adj1(n);
        for(auto &it: edges1) {
            int u = it[0], v = it[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        // Build graph adj list form tree 2:
        vector<vector<int>> adj2(m);
        for(auto &it: edges2) {
            int u = it[0], v = it[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }


        // Step 2: Compute even distance for tree 1:
        vector<int> even(n, 0); 
        dist(0, adj1, even);    // we can call from any node position.

        // Count the evenCnt & oddCnt & overwrite into even vector:
        int evenCnt = 0;
        int oddCnt = 0;
        for(int i = 0; i < n; i++) {
            if(even[i] == 0) evenCnt++;
            else oddCnt++;
        }
        
        for(auto &it: even) {
            if(it == 0) it = evenCnt;
            else it = oddCnt;
        }



        // Step 3: Compute maxDistance for tree 2:
        vector<int> odd(m, 0);
        dist(0, adj2, odd);
        int evenCnt2 = 0, oddCnt2 = 0;
        for(int i = 0; i < m; i++) {
            if(odd[i] == 0) evenCnt2++;
            else oddCnt2++;
        }

        int maxCnt = max(oddCnt2, evenCnt2);    // get the max dist from oddCnt & evenCnt from tree 2

        

        // Step 4: Build Answer: 
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = even[i] + maxCnt;
        }


        return ans;
    }
};



// BruteForce Solution: TLE
class Solution {
private:
    // BFS to count the even neighbour: 
    int evenNgbrCnt(int node, vector<vector<int>>& adj, vector<int>& vis, int lvl) {
        
        queue<pair<int, int>> q;

        vis[node] = 1;
        q.push({lvl, node});

        int totalEvenNgbr = 0;
        while(!q.empty()) {
            auto [lvl, node] = q.front();
            q.pop();

            if(lvl % 2 == 0) {
                totalEvenNgbr++;
            }

            for(auto &it: adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push({lvl + 1, it});
                }
            }
        }
        
        return totalEvenNgbr;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;  // tree 1
        int m = edges2.size() + 1;  // tree 2

        // Build graph adj list form tree 1:
        vector<vector<int>> adj1(n);
        for(auto &it: edges1) {
            int u = it[0], v = it[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        // Build graph adj list form tree 2:
        vector<vector<int>> adj2(m);
        for(auto &it: edges2) {
            int u = it[0], v = it[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        // Compute tree 2 levels: 
        int optimalPointFromTree2 = 0;
        for(int i = 0; i < m; i++) {
            vector<int> vis(m, 0);
            optimalPointFromTree2 = max(optimalPointFromTree2, evenNgbrCnt(i, adj2, vis, 1));   // level start from 1
        }

        // Compute tree 1 levels: 
        vector<int> tree1Lvl(n);
        for(int i = 0; i < n; i++) {
            vector<int> vis(n, 0);
            tree1Lvl[i] = evenNgbrCnt(i, adj1, vis, 0);
            cout << endl;
        }
        
        // Build Final answer: 
        vector<int> ans(n, optimalPointFromTree2);
        for(int i = 0; i < n; i++) {
            ans[i] += tree1Lvl[i];
        }

        return ans;
    }
};