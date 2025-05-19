/*

//  827. Making A Large Island

//  Problem Link: https://leetcode.com/problems/making-a-large-island/description/


// Observations: 
    -> Given grid with 0's & 1's
    -> From largest island by converting one 0 to 1
    -> return the size of largest island

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

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
    int getSize(int x) {
        return size[ultPar(x)];
    }
};

class Solution {
private: 
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        // Step 1: Connect the component & form island:
        DSU ds(n * m);
        bool water = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {    // for every island:
                    int cellNo = i * m + j;

                    // Explore in all 4 directions: 
                    for(int k = 0; k < 4; k++) {
                        int r = i + dir[k][0];
                        int c = j + dir[k][1];

                        if(isValid(r, c) && grid[r][c]) {
                            int adjCellNo = r * m + c;
                            ds.Union(cellNo, adjCellNo);
                        }
                    }
                }

                if(!grid[i][j]) {
                    water = true;
                }
            }
        }

        // If there's no water:
        if(!water) return (n * m);

        // Step 2: Process every '0' & try to form largest possible island:
        int maxIsland = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(!grid[i][j]) {   // for every water:
                    
                    // Explore all the possible islands:
                    set<int> st;
                    for(int k = 0; k < 4; k++) {
                        int r = i + dir[k][0];
                        int c = j + dir[k][1];

                        // within valid constrains & valid island:
                        if(isValid(r, c) && grid[r][c]) {
                            int adjCellNo = r * m + c;
                            st.insert(ds.ultPar(adjCellNo));    // store every island ultimate parent into set.
                        }
                    }
                    int tempSize = 1;
                    for(auto &it: st) {
                        tempSize += ds.getSize(it);
                    }

                    maxIsland = max(tempSize, maxIsland);
                }
            }
        }

        return maxIsland;
    }
};