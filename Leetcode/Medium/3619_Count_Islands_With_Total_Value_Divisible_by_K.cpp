/*

//  3619. Count Islands With Total Value Divisible by K


//  Problem Statement: 
    - You are given an m x n matrix grid and a positive integer k. An island is a group of positive integers (representing land) that are 4-directionally connected (horizontally or vertically).
    - The total value of an island is the sum of the values of all cells in the island.
    - Return the number of islands with a total value divisible by k.

 
// Example:
    Example 1:
        Input: grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5
        Output: 2
        Explanation: The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.

    Example 2:
        Input: grid = [[3,0,3,0], [0,3,0,3], [3,0,3,0]], k = 3
        Output: 6
        Explanation: The grid contains six islands, each with a total value that is divisible by 3.


//  Observations:

    - Given grid of size n x m and k
    - island are 4 directionally connected.
    - grid[i][j] > 0: island
        - get the sum of every island:
        - return the total number of island that their sum are divisible by 'k'.


    // BFS/DFS Approach:
        - we can iterate and find the sum of every Island in grid using dfs/bfs
        - and then check whether sum is divisible by k or not?
        - and then return the total number of such islands.

        // Complexity:
            - TC: O(n * m)
            - SC: O(n * m)


    // DSU approach:
        - connect the island > 0
        - afterwords fetch every components sum
        - return the total number of component that their sum divisible is by k.

        // Complexity:
            - TC: O(n * m)
            - SC: O(n * m)  


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// DSU Solution:
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

class Solution {
private:
    int n, m;
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValidDim(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        // Connect nodes, and form connected components:
        DSU ds(n * m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] > 0) {
                    int cellNo = i * m + j;

                    // Explore adj-neighbour in all 4 directions:
                    for(auto &[x, y]: dir) {
                        int r = i + x;
                        int c = j + y;

                        if(isValidDim(r, c) && grid[r][c] > 0) {
                            int adjCellNo = r * m + c;

                            ds.Union(cellNo, adjCellNo);
                        }
                    }
                }
            }
        }

        // Find out every components sum:
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] > 0) {
                    int cellNo = i * m + j;
                    int uPar = ds.ultPar(cellNo);

                    mp[uPar] += (grid[i][j] % k);
                }
            }
        }

        // Count the total number of components that their sum divisible by 'k'
        int ans = 0;
        for(auto &[node, sum]: mp) {
            if(sum % k == 0) ans++;
        }

        return ans;
    }
}; 


// BFS/DFS Solution:
class Solution {
private:
    int K;
    int n, m;   // grid dimension.
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};    // dir: left, right, above, below.
    bool isValidDim(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;

        // Explore adj-neighbors:
        int sum = grid[row][col];
        for(auto &[x, y]: dir) {
            int r = row + x;
            int c = col + y;

            if(isValidDim(r, c) && grid[r][c] > 0 && !vis[r][c]) {
                sum += (dfs(r, c, grid, vis) % K);  // this will round off the value sum valud to k
            }
        }

        return sum;
    }
    int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        
        queue<pair<int, int>> q;

        q.push({row, col});
        vis[row][col] = 1;

        int sum = 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [row, col] = q.front();
                q.pop();

                sum += (grid[row][col] % K);

                // Explore adj-neighbors:
                for(auto &[x, y]: dir) {
                    int r = row + x;
                    int c = col + y;

                    if(isValidDim(r, c) && grid[r][c] > 0 && !vis[r][c]) {
                        vis[r][c] = 1;
                        q.push({r, c});
                    }
                }
            }
        }

        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        K = k;

        // Explore and count total island divisible by k:
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // if(grid[i][j] > 0 && !vis[i][j] && dfs(i, j, grid, vis) % k == 0) ans++;
                if(grid[i][j] > 0 && !vis[i][j] && bfs(i, j, grid, vis) % k == 0) ans++;
            }
        }

        return ans;
    }
};


