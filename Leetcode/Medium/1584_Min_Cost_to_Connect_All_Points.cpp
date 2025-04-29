/*

//  1584. Min Cost to Connect All Points


//  Problem Statement: 
    -> You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
    -> The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
    -> Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 
// Example: 
        
    Example 1:
        Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
        Output: 20

    Example 2:
        Input: points = [[3,12],[-2,5],[-4,1]]
        Output: 18



// Observations: 
    -> given dots on x-y coordinates.
    -> find the minimum cost to connect all the dot's
    -> cost b/w two point is manhattan distance..

    // MST-DSU Kruskal's Algorithm:
        -> Step 1: Build Complete graph edges with weight as priority factor & should be stored in shorted fashion..
        -> Step 2: find the mst cost from that edges...

    // Complexity: 
        -> TC: O(V^2) -> For building complete graph.
        -> SC: O(V^2) -> For Complete graph

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// DSU: O(V)
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
        if(node == parent[node]) return node;
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


// MST-DSU Kruskal's algorithm
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();

        // Step 1: Build edges for Complete graph:
        set<pair<int, pair<int, int>>> edges;   // set will store the graph edges in sorted way -> Structure: <u: <wt, v>>
        for(int i = 0; i < V; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = 0; j < V; j++) {
                int x2 = points[j][0], y2 = points[j][1];

                int wt = abs(x2 - x1) + abs(y2 - y1);   // get the cost from two points..

                // Undirected graph => store every edges only onces..
                edges.insert({wt, {min(i, j), max(i, j)}});
            }
        }


        // Step 2: Find MST with DSU:
        DSU ds(V + 1);
        int mst = 0;
        for(auto &[wt, ed]: edges) {
            int u = ed.first, v = ed.second;
            // Check ultimate parent: 
            int ult_u = ds.ultPar(u);
            int ult_v = ds.ultPar(v);

            if(ult_u == ult_v) continue;    // skip already connected edges.
            // Else connect the edges & count the MST: 
            ds.Union(u, v);
            mst += wt;  // get the mst weight from only minimum weighted edges.
        }

        return mst;
    }
};