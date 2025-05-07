/*

//  Number Of Islands 2
 

//  Problem Link: https://www.geeksforgeeks.org/problems/number-of-islands/1

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

class Solution {
private: 
    int n, m;   // Dimensions
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // L, R, U, D
    bool isValid(int r, int c) { return (r >= 0 && r < n && c >= 0 && c < m);}
public:
    vector<int> numOfIslands(int n_, int m_, vector<vector<int>> &queries) {
        n = n_, m = m_;
        
        // DSU -> Connect the island & keep track of every island in Real time:
        vector<vector<int>> grid(n, vector<int> (m, 0));
        vector<int> ans;
        int island = 0;
        DSU ds(n * m);
        
        
        for(auto &query: queries) {
            int row = query[0];
            int col = query[1];
            
            
            // Initial Check: Check island already there or not?
            if(grid[row][col]) {    // already filled
                ans.push_back(island);
                continue;   // no need to process...
            }
            
            // else find distinct island & connect: 
            grid[row][col] = 1;             // fill it with island
            island++;                       // increment island count
            int cellNo = row * m + col;     // cell no
            
            // Explore in all 4 directions:
            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];
                
                // For every valid adj
                if(isValid(r, c) && grid[r][c] == 1) {
                    int adjCellNo = r * m + c;
                    
                    // If they both have distinct ult-parent: Connect & decrement
                    if(ds.ultPar(cellNo) != ds.ultPar(adjCellNo)) {
                        ds.Union(cellNo, adjCellNo);
                        island--;
                    }
                }
            }
            
            
            // store answer for every query:
            ans.push_back(island);
        }
        
        return ans;
    }
};