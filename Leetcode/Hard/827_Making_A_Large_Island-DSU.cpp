/*

// 827. Making a Large Island - DSU


//  Problem Statement: 
    -> You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
    -> Return the size of the largest island in grid after applying this operation.
    -> An island is a 4-directionally connected group of 1s.
 

// Example:
    Example 1:
        Input: grid = [[1,0],[0,1]]
        Output: 3
        Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

    Example 2:
        Input: grid = [[1,1],[1,0]]
        Output: 4
        Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

    Example 3:
        Input: grid = [[1,1],[1,1]]
        Output: 4
        Explanation: Can't change any 0 to 1, only one island with area = 4.

 
// Observations: 
    -> We are given a grid where 1-> land & 0-> water
    -> We can change at-max one water cell to land..
    -> We need to find the maximum area of land by converting one water to land

    
// DSU Solution:
    // Why DSU?
        -> If we consider grid island as components, DSU will help us to merge them & track the total number of islands..
        -> Also, with DSU we can get the size of every components, & with simply iterating in 4 directions, we can compute the maximum island area.

    // DSU Approach: 
        -> First connect the cells & form the components in grid
            -> For every '1' -> iterate in 4 directions & join with adjacent 1's
            -> we can get every cellNo with formula: (cellNo = row * m + col)

        -> Second, iterate one more time in grid, for every 0's, check it's adjacent lands.
            -> Store their ultimate parent in set & calculate all those ultimate parent size.
            -> from all the computations store the maximum ones.


    // Complexity: 
        -> TC: O(n * m * alpha(n * m)) => O(n * m)
        -> SC: O(n * m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class DSU {
private: 
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
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
    int getSize(int x) {
        return size[ultPar(x)];    // return the size of every group ultimate parent.
    }
};

class Solution {
private: 
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // Directions:  left, right, up, down
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();


        // Step 1: Connect the components & form the islands
        DSU ds(n*m);            // DSU of size (n * m) handel all the cells from (0 to (n*m - 1))
        bool isWater = false;   // flag used to check if grid has no water(0)
        for(int i = 0; i < n ; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {  // for every 1's

                    int cellNo = i * m + j;     // get the cell no, {Formula of cellNo = row * m + col}

                    // Explore all 4 directions & merge it:
                    for(int k = 0; k < 4; k++) {
                        int r = i + dir[k][0];
                        int c = j + dir[k][1];

                        if(isValid(r, c) && grid[r][c]) {
                            int adjCellNo = r * m + c;      // get the adjCellNo
                            ds.Union(cellNo, adjCellNo);    // merge them
                        }
                    }

                }
                if(!grid[i][j]) isWater = true;
            }
        }

        // Edge case: if grid has no '0':
        if(!isWater) {
            return n * m;   // return size of grid as our maximum island
        }


        // Step 2: Now find the maxIsland by simply changing '0' to 1's & finding out maximum area
        int larIsland = 1;  // maxArea of island, at minimum it's 1, because we have options to convert it.
        for(int i = 0; i < n ; i++) {
            for(int j = 0; j < m; j++) {
                if(!grid[i][j]) {   // for every 0's

                    unordered_set<int> adjCells;    // set used to store ultimate parent of all the adjacent nodes
                    for(int k = 0; k < 4; k++) {
                        int r = i + dir[k][0];
                        int c = j + dir[k][1];

                        if(isValid(r, c) && grid[r][c]) {   // for every valid 1's
                            int adjCellNo = r * m + c;
                            adjCells.insert(ds.ultPar(adjCellNo));  // store ultimate parent or valid cells inside the set
                        }
                    }

                    // Now calculate total island size:
                    int tempIsland = 1;
                    for(auto &cell: adjCells) {
                        tempIsland += ds.getSize(cell);
                    }

                    larIsland = max(larIsland, tempIsland); // storing maximum area among all the possible conversion.
                }
            }
        }

        return larIsland;
    }
};