/*

//  Find number of closed islands


//  Problem Statement: 
    -> Given a binary matrix mat[][] of dimensions NxM such that 1 denotes land and 0 denotes water. 
    -> Find the number of closed islands in the given matrix.
    -> An island is a 4-directional(up,right,down and left) connected part of 1's.
    
    -> Note: A closed island is a group of 1s surrounded by only 0s on all the boundaries (except diagonals). 
    -> In simple words, a closed island is an island whose none of the 1s lie on the edges of the matrix.

// Example: 

    Example 1:
        Input:
        N = 5, M = 8
        mat[][] = {{0, 0, 0, 0, 0, 0, 0, 1}, 
                {0, 1, 1, 1, 1, 0, 0, 1}, 
                {0, 1, 0, 1, 0, 0, 0, 1}, 
                {0, 1, 1, 1, 1, 0, 1, 0}, 
                {1, 0, 0, 0, 0, 1, 0, 1}}
        Output: 2
        Explanation:
            mat[][] = {{0, 0, 0, 0, 0, 0, 0, 1}, 
                    {0, 1, 1, 1, 1, 0, 0, 1}, 
                    {0, 1, 0, 1, 0, 0, 0, 1}, 
                    {0, 1, 1, 1, 1, 0, 1, 0}, 
                    {1, 0, 0, 0, 0, 1, 0, 1}} 
            There are 2 closed islands. The islands in dark are closed because they are completely surrounded by 0s (water). There are two more islands in the last column of the matrix, but they are not completely surrounded by 0s. Hence they are not closed islands. 

    Example 2:

        Input:
        N = 3, M = 3
        mat[][] = {{1, 0, 0},
                {0, 1, 0},
                {0, 0, 1}}
        Output: 1
        Explanation:
            mat[][] = {{1, 0, 0},
                    {0, 1, 0},
                    {0, 0, 1}}
            There is just a one closed island.

// DUS Approach: 
    -> Connect the nodes & form multiple components.
    -> Get the details of every total components as well as invalid components
    -> Filter out invalid components from total components
    -> that will be our valid components.


// Complexity: 
    -> TC: O(n * m)
    -> SC: O(n * m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// DSU Solution:
class DSU {
private: 
    vector<int> parent, size;
public: 
    DSU (int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]); // path compression
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;  // already connected
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
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) { return (r >= 0 && r < n && c >= 0 && c < m);}
public:
    int closedIslands(vector<vector<int>>& grid, int N, int M) {
        n = grid.size(), m = grid[0].size();
        
        // Connect the nodes & form multiple components: 
        DSU ds(n * m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {   // for every land cell:
                    int cellNo = i * m + j;
                    
                    // explore in all 4 directions: 
                    for(int k = 0; k < 4; k++) {
                        int r = i + dir[k][0];
                        int c = j + dir[k][1];
                        
                        // for valid land cell:
                        if(isValid(r, c) && grid[r][c] == 1) {
                            int adjCellNo = r * m + c;
                            ds.Union(cellNo, adjCellNo);
                        }
                    }
                }
            }
        }
        
        // Get the details of valid & invalid Islands ultimate parent:
        unordered_set<int> comp;
        unordered_set<int> invalid;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {   // for every land cell:
                    int cellNo = i * m + j;
                    int par = ds.ultPar(cellNo);
                    
                    comp.insert(par);
                    if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                        invalid.insert(par);
                    }
                    
                }
            }
        }

        // Filter Out Invalid components: 
        for(auto &val: invalid) {
            comp.erase(val);
        }
        
        
        return comp.size();
    }
};