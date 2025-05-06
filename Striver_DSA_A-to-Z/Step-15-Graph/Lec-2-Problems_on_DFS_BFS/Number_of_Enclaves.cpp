/*

//  1020. Number of Enclaves


//  Problem Link: https://leetcode.com/problems/number-of-enclaves/description/


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class DSU {
private: 
    vector<int> size, parent;
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
    int getSize(int x) {
        return size[ultPar(x)];
    }
};

class Solution {
public:
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        DSU ds(n * m);

        // Step 1: Connect the components: 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) { // for every island
                    int cellNo = i * m + j;

                    // Explore in all 4 directions: 
                    for(int k = 0; k < 4; k++) {
                        int r = i + dir[k][0];
                        int c = j + dir[k][1];

                        if(isValid(r, c) && grid[r][c] == 1) {
                            int adjCellNo = r * m + c;
                            ds.Union(cellNo, adjCellNo);
                        }
                    }
                }
            }
        }

        // Step get every ultimate parent  & the faulty ones with their size: 
        unordered_map<int, int> mp;
        unordered_set<int> faulty;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {   // for every island: 
                    int cellNo = i * m + j;
                    mp[ds.ultPar(cellNo)] = ds.getSize(cellNo); // store size of every ultimate parent

                    // if cell lies in faulty position: 
                    if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                        faulty.insert(ds.ultPar(cellNo));   // insert that ultimate parent:
                    }
                }
            }
        }

        // Calculate valid size:
        int size = 0;
        for(auto &[key, val]: mp) {
            if(!faulty.count(key)) {
                size += val;
            }
        }

        return size;
    }
};