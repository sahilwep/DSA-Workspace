/*

//  3108. Minimum Cost Walk in Weighted Graph


//  Problem Statement: 
    -> There is an undirected weighted graph with n vertices labeled from 0 to n - 1.
    -> You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.
    -> A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.
    -> The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.
    -> You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.
    -> Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.

//  Example: 

    Example 1:
        Input: n = 5, edges = [[0,1,7],[1,3,7],[1,2,1]], query = [[0,3],[3,4]]
        Output: [1,-1]
        Explanation:
            To achieve the cost of 1 in the first query, we need to move on the following edges: 0->1 (weight 7), 1->2 (weight 1), 2->1 (weight 1), 1->3 (weight 7).
            In the second query, there is no walk between nodes 3 and 4, so the answer is -1.

    Example 2:
        Input: n = 3, edges = [[0,2,7],[0,1,15],[1,2,6],[1,2,1]], query = [[1,2]]
        Output: [0]
        Explanation:
            To achieve the cost of 0 in the first query, we need to move on the following edges: 1->2 (weight 1), 2->1 (weight 6), 1->2 (weight 1).


// Observations: 
    -> Given n nodes from 0 to "n - 1"
    -> We are given edges with their weights, edges[i] = {u, v, wt}
    -> we are given query query[i] = {u, v}, we need to find the minimum cost b/w the path u & v, if there is path b/w them, else '-1'
    -> Note we can visit same nodes and vertices any number of times.
    -> COST(u, v): (u)---w1 & w2 & w3...wn---(v)


// AND Observations: 

            0 0 => 0
            0 1 => 0
            1 0 => 0
            1 1 => 1

        -> Only both 1's are 1's else rest of them are '0'

        // How to preserve the any number with AND Operations:

                X & -1 = X

                (-1) = 11111111111111111111111111111111
                
                AND with any number will preserve that number: 
                
                Eg. 
                x = 6
                
                (-1) = 11111111111111111111111111111111
                (6)  = 00000000000000000000000000000110  AND
                --------------------------------------------
                       00000000000000000000000000000110

        // Another Property: 

            (A & B & C) <= min(A, B, C)

            Example:

                A = 14  (in binary: 1110)
                B = 11  (in binary: 1011)
                C =  9  (in binary: 1001)


                Step 1: Bitwise AND

                    Compute A & B & C:

                    A = 1110  
                    B = 1011  
                    C = 1001  
                    ------------
                    A & B & C = 1000  (which is 8 in decimal)

                Step 2: Minimum of A, B, C

                    min(A, B, C) = min(14, 11, 9) = 9
                
                Step 3: Compare

                    A & B & C = 8
                    min(A, B, C) = 9

                    So, 8 <= 9 True


        // More we perform AND operations over weights, the lower the result becomes —
            -> so including all edges in a component gives the minimum walk cost.

            // Important Insight:
                ->  ANDing more edges = smaller cost → best possible cost.
                ->  Repeating edges is allowed (walk), so we can AND all weights in the component.
            
            // Example: 
                    n = 4
                    edges = {
                        {0, 1, 6},    // 110
                        {1, 2, 2},    // 010
                        {2, 3, 4}     // 100
                    }

                    queries = {{0, 2},{0, 3},{1, 3}}

                             6         2        4
                        [0]------[1]-------[2]---------[3]

                    {0, 2}:
                            Normal Path: 0 - 1 - 2
                                Cost: 6 & 2 => 2

                            Best Path:  0 - 1 - 2 - 3 - 2
                                Cost: 6 & 2 & 4 & 4 => 0

                                If we have taken normal path, then the cost will be more & for this path cost is decreased, with simple property, more and with more number => lesser the number it gets...

                    {1, 2}: 
                            Possible best paths: 
                                1 - 0 - 1 - 2 - 3 - 2   => Cost: 6 & 6 & 2 & 4 & 4 = 0
                                1 - 2 - 3 - 2           => Cost: 2 & 4 & 4 = 0

                                we can take any of them

                    {1, 3}: 
                             Possible best paths: 
                                1 - 0 - 1 - 2 - 3 - 2   => Cost: 6 & 6 & 2 & 4 & 4 = 0
                                1 - 2 - 3           => Cost: 2 & 4 = 0


            // Another Example Walk:

                Imagine the following edges:
                    0 → 1 with weight 6 (110)
                    1 → 2 with weight 2 (010)
                    2 → 3 with weight 4 (100)

                If you're looking for a walk from 0 → 3, you can loop around and use all the edges, and the AND of the edge weights will be:
                    6 & 2 & 4 = 0 (000)


// DSU Approach: 
    -> DSU Will help us to track the components, we can easily identify whether there is any path b/w the given query {u, v}
    -> If there's a path, we can calculate the path with AND Operations: 
    -> The best possible cost (minimum) of a walk b/w the tow nodes is the bitwise AND of all the edge weights in their components.


    // Complexity: 
        // Optimized DSU: 
            -> TC: O(N + E + Q)
                -> E = Edges
                -> Q = Query
                -> N = number of nodes
            -> SC: O(N)

        // Naive DSU: 
            -> TC: O( N + E + Q * E)
            -> SC: O(N + E)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// DSU Approach:
class DSU {
private:
    vector<int> parent, size;
public:
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = ultPar(parent[node]);
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

// Optimized DSU: 
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        int qSize = query.size();

        // Step 1: Merge the components: 
        DSU ds(n);  // TC: O(N)
        for(auto &it: edges) {  // TC: O(E)
            int u = it[0], v = it[1];

            ds.Union(u, v);
        }

        // Step 2: Store Ultimate parent & their corresponding edge weights AND's:
        unordered_map<int, int> mp; // structure: <ultPar:(w1 & w1 & w3...wn)>
        for(auto &it: edges) {      // TC: O(E)
            int u = it[0], wt = it[2];

            int node = ds.ultPar(u);

            if(!mp.count(node)) {           // If that node not found in map:
                mp[node] = wt;              // store it form the first time.
            } else {
                mp[node] = mp[node] & wt;   // else: perfrom & with their previous values.
            }
        }

        // Build Answers: 
        vector<int> ans;
        for(auto &it: query) {  // TC: O(Q)
            int u = it[0], v = it[1];

            if(ds.ultPar(u) != ds.ultPar(v)) ans.push_back(-1); // for different Component:
            else ans.push_back(mp[ds.ultPar(u)]);   // For Same Component
        }

        return ans;
    }
};

// Naive DSU: 
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) { // TC: O(N + E + Q * E)
        int qSize = query.size();

        // Step 1: Merge the components: 
        DSU ds(n);  // TC: O(N)
        for(auto &it: edges) {  // TC: O(E)
            int u = it[0], v = it[1];

            ds.Union(u, v); // TC: O(alpha(n)) => O(1)
        }

        // Step 2: Store Ultimate parent & their corresponding all edge weights:
        unordered_map<int, unordered_set<int>> mp;  // structure: <ultPar: <w1, w2, w3,....wn>>
        for(auto &it: edges) {  // TC: O(E)
            int u = it[0], wt = it[2];

            mp[ds.ultPar(u)].insert(wt);
        }

        
        // Step 3: Build Answer
        vector<int> ans;
        for(auto &it: query) {  // TC: O(Q * E)
            int u = it[0], v = it[1];

            if(ds.ultPar(u) != ds.ultPar(v)) ans.push_back(-1); // for different component
            else {  // For same componenet: Calculate minimum cost on that path:
                int cost = -1;   // -1 will preserve our initial value, as: (x & -1 = x)
                for(auto &i: mp[ds.ultPar(u)]) {    // TC: O(E), in worse case
                    cost &= i;
                }

                ans.push_back(cost);
            }
        }

        return ans;
    }
};