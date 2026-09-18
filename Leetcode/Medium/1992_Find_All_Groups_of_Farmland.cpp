/*

//  1992. Find All Groups of Farmland


//  Problem Statement: 
 - You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.
 - To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.
 - land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].
 - Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, return an empty array. You may return the answer in any order.

//  Example:

    Example 1:
        Input: land = [[1,0,0],[0,1,1],[0,1,1]]
        Output: [[0,0,0,0],[1,1,2,2]]
        Explanation:
        The first group has a top left corner at land[0][0] and a bottom right corner at land[0][0].
        The second group has a top left corner at land[1][1] and a bottom right corner at land[2][2].

    Example 2:
        Input: land = [[1,1],[1,1]]
        Output: [[0,0,1,1]]
        Explanation:
        The first group has a top left corner at land[0][0] and a bottom right corner at land[1][1].

    Example 3:
        Input: land = [[0]]
        Output: []
        Explanation:
        There are no groups of farmland.


// Observations:
    - Given grid, we will have to figure out the farmland coordinates:
        - {topleft, bottomright}
    - and return the total farmland coordinates. 
    

    // DSU Approach:
        - We can connect node 1's and form connected component.
        - and store the top-right and bottom-left coordinates all the components, and return our answer.

        // Complexity:
            - TC: O(n * m)
            - SC: O(n * m)


    // BFS/DFS Approach:
        - every cell has to visit only once.
        - for every component traversal, we will have to figure out the min(x) and min(y), and max(x), and max(y)
        - we will have to traverse in all 4 directions.

        // Complexity:
            - TC: O(n * m)
            - SC: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BFS/DFS Solution:
class Solution {
private:
    int n, m;   // grid dimension.
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // dir: left, right, above, below.
    bool isValidDim(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, vector<int>& cor) {
        vis[row][col] = 1;

        // update top-left & bottom-down:
        cor[0] = min(cor[0], row);
        cor[1] = min(cor[1], col);

        cor[2] = max(cor[2], row);
        cor[3] = max(cor[3], col);


        for(auto &[x, y]: dir) {
            int r = row + x;
            int c = col + y;

            if(isValidDim(r, c) && grid[r][c] == 1 && !vis[r][c]) {
                dfs(r, c, grid, vis, cor);
            }
        }
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> ans;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    vector<int> cor = {n + 1, m + 1, -1, -1};   // coordinates: <min<x, y>, max<x, y>>    // default value keeps out of range..
                    dfs(i, j, grid, vis, cor);

                    ans.push_back(cor);
                }
            }
        }

        return ans;
    }
};


// DSU Approach:
class DSU {
private:
    vector<int> size, parent;
public:
    DSU (int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = ultPar(parent[node]); // path compression.
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_), v = ultPar(v_);
        if(u == v) return;  // already connected.

        // Connect smaller grp to larger one:
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution_ {
private:
    int n, m;   // grid dimension.
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};    // dir: left, right, above, below.
    bool isValidDim(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}    // function to check the valid grid dimension.
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Connect nodes, and build connected components.
        DSU ds(n * m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    int cellNo = i * m + j;

                    // Explore in all 4 directions:
                    for(auto &[x, y]: dir) {
                        int r = i + x;
                        int c = j + y;

                        if(isValidDim(r, c) && grid[r][c] == 1) {
                            int adjCellNo = r * m + c;

                            ds.Union(cellNo, adjCellNo);
                        }
                    }
                }
            }
        }

        // Now, fetch every component ultimate parent, coordinates:
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    int cellNo = i * m + j;
                    int uPar = ds.ultPar(cellNo);
                    
                    if(mp.count(uPar)) {
                        // Fetch the coordinates & update top-left, and bottom-right:
                        vector<int> c = mp[uPar];
                        c[0] = min(c[0], i);    // top-x
                        c[1] = min(c[1], j);    // top-y

                        c[2] = max(c[2], i);    // bottom-x
                        c[3] = max(c[3], j);    // bottom-y

                        mp[uPar] = c; 
                    } else {
                        mp[uPar] = {i, j, i, j};
                    }
                }
            }
        }


        vector<vector<int>> ans;
        for(auto &[key, val]: mp) {
            ans.push_back(val);
        }

        return ans;
    }
};

