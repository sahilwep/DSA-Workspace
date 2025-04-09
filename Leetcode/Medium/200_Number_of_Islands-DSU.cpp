/*

//  200. Number of Islands DSU


//  Problem Statement: 

// Problem Statement:
    -> Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
    -> An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


// Example:

    Example 1:
        Input: grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
        ]
        Output: 1

    Example 2:
        Input: grid = [
        ["1","1","0","0","0"],
        ["1","1","0","0","0"],
        ["0","0","1","0","0"],
        ["0","0","0","1","1"]
        ]
        Output: 3




// Visualization:

    -> We are given a matrix where '1' represent island, & '0' represent water
    -> We need to count the total number of island from the matrix:
        -> for any island which is connected to all '4' direction, will be count as the same part of that island.

                              |        
                           -  x  -       
                              |        


    // DSU Approach: 

        -> If we observe this question carefully, it's asking how many multiple components the whole graph has.
        -> we can count total numer of components, by simply merging every two adjacent cells.
        -> It's just we are given two things (row, col) => how we can generate every cell with unique ID: 

            // How to get the grid cell numbers & add it into the DSU: 
                -> For every cell we have coordinates (row, col) & We need only one unique number which we can connect with other cells
                -> Because In DSU we need two value for two cells:
                    -> How to assign Unique Number to every cell

                        n = 4   => rows
                        m = 5   => cols

                              0   1   2   3   4
                            _____________________
                        0   | 0 | 1 | 2 | 3 | 4 |
                            |---|---|---|---|---|
                        1   | 5 | 6 | 7 | 8 | 9 |
                            |---|---|---|---|---|
                        2   | 10| 11| 12| 13| 14|
                            |---|---|---|---|---|
                        3   | 15| 16| 17| 18| 19|
                            ---------------------

                            for grid (n * m) => 4 * 5 => 20 (0 to 19)

                            let say cell(row = 1, col = 3) => 8

                                Formula for every cell: row * m + col
                                                (1, 3) => 1 * 5 + 3 => 8

                -> With this logic we can generate unique cell numbers.

        -> Now, Simply we can iterate in grid, & if we have any land, we will try to iterate in all 4 directions & merge them if adjacent cells are also land.


// Complexity:
    -> TC: O(n*m)
    -> SC: O(n*m)

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
    int numIslands(vector<vector<char>>& grid) {
        
        n = grid.size(), m = grid[0].size();

        // Step 1: merge all the node together & form multiple components:
        DSU ds(n * m);
        set<int> totalComp;

        // First connect all the nodes together
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    int cellNo = i * m + j;
                    // Explore all 4 directions & connect island togethers:
                    for(int k = 0; k < 4; k++) {
                        int r = i + dir[k][0];
                        int c = j + dir[k][1];

                        if(isValid(r, c) && grid[r][c] == '1') {
                            int adjCellNo = r * m + c;
                            ds.Union(cellNo, adjCellNo);
                        }
                    }
                }
            }
        }

        // Count the total number of ultimate parent in graph for every island.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1') {
                    int cellNo = i * m + j;
                    totalComp.insert(ds.ultPar(cellNo));
                }
            }
        }

        return totalComp.size();    // total this much unique ultimate parent we are having in our graph.
    }
};