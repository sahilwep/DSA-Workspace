/*

//  1254. Number of Closed Islands

//  Problem Statement: 
    -> Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
    -> Return the number of closed islands.



// Example:

    Example 1:

        Input: grid = [[1,1,1,1,1,1,1,0],
                    [1,0,0,0,0,1,1,0],
                    [1,0,1,0,1,1,1,0],
                    [1,0,0,0,0,1,0,1],
                    [1,1,1,1,1,1,1,0]]
        Output: 2
        Explanation: Islands in gray are closed because they are completely surrounded by water (group of 1s).

    Example 2:

        Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
        Output: 1

    Example 3:

        Input: grid = [[1,1,1,1,1,1,1],
                    [1,0,0,0,0,0,1],
                    [1,0,1,1,1,0,1],
                    [1,0,1,0,1,0,1],
                    [1,0,1,1,1,0,1],
                    [1,0,0,0,0,0,1],
                    [1,1,1,1,1,1,1]]
        Output: 2


// Observations: 
    -> Closed islands are those islands, which were totally surrounded by water fro all the outer directions, (left, right, up, down).
    -> The island that were the part of the boundary cells we can't consider them as closed islands, because, they were not closed by water..

// DSU Approach:
    -> First we will find total number of multiple components in our graph.
    -> Then we can iterate & the the components which falls into faulty line, which is nothing but the boundary cells.
    -> Now we will eliminate fault components from the total components & return remaining componenet as our answer.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

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


class Solution {
private:    
    int n, m;
    int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
public:
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        // Step 1: merge all the node together & form multiple components:
        DSU ds(n * m);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!grid[i][j]) {
                    int cellNo = i * m + j;

                    // Explore all 4 directions & connect island togethers:
                    for(int k = 0; k < 4; k++) {
                        int r = i + dir[k][0];
                        int c = j + dir[k][1];

                        if(isValid(r, c) && !grid[r][c]) {
                            int adjCellNo = r * m + c;
                            ds.Union(cellNo, adjCellNo);
                        }
                    }
                }
            }
        }

        // Step 2: Get all the Components: Including Faulty ones.
        unordered_set<int> allComp;
        unordered_set<int> faultyComp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cellNo = i * m + j;
                if(!grid[i][j]) {
                    allComp.insert(ds.ultPar(cellNo));  // get all the components
                }
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {  // keep track of faulty components:
                    faultyComp.insert(ds.ultPar(cellNo));
                }
            }
        }

        // Step 3: Count the valid Components that were not the part of faulty components.
        int closedIslands = 0;
        for(auto &comp: allComp) {
            if(!faultyComp.count(comp)) {   // get the island that were not the part of faulty components.
                closedIslands++;
            }
        }

        return closedIslands;
    }
};