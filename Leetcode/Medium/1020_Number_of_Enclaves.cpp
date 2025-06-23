/*

//  1020. Number of Enclaves


// Problem Statement:
    * You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
    * A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
    * Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
 

// Example:
    Example 1:
        Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
        Output: 3
        Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

    Example 2:
        Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
        Output: 0
        Explanation: All 1s are either on the boundary or can reach the boundary.


// Observations:
    -> We need to find the number of land which can walk of the grid.



// Approach:
    -> we can start iteration from the every boundary of the grid & mark all the connected lands.
    -> we can use dfs traversal to mark all adjacent connected lands.
    -> Afterwords, we can count those lands which were not visited, & return the count of that.



// Complexity:
    -> TC: O(n * m)
    -> SC: O(n * m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// DSU Approach: Complexity: n * m
class DSU {
private: 
    vector<int> size, parent;
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
    int getSize(int x) {return size[ultPar(x)];}
};

class Solution {
private: 
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
public:
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        // Connect the nodes & form graph components: 
        DSU ds(n * m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {   // for every island:
                    int cellNo = i * m + j; // get the cell no

                    // Explore in all 4 directions: 
                    for(int k = 0; k < 4; k++) {
                        int r = i + dir[k][0];
                        int c = j + dir[k][1];

                        if(isValid(r, c) && grid[r][c] == 1) {
                            int adjCellNo = r * m + c;  // get the adjacent cell no.

                            ds.Union(cellNo, adjCellNo);    // connect
                        }
                    }
                }
            }
        }

        // Get the valid & faulty components: 
        unordered_set<int> comp;
        unordered_set<int> faulty;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    int cellNo = i * m + j;
                    int cellUltPar = ds.ultPar(cellNo);

                    comp.insert(cellUltPar);
                    if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                        faulty.insert(cellUltPar);
                    }
                }
            }
        }
        

        // return the valid components size:
        int validComp = 0;
        for(auto &val: comp) {
            if(!faulty.count(val)) {
                validComp += ds.getSize(val);
            }
        }

        return validComp;
    }
};




// DFS Approach
class Solution_DFS {
private:
    vector<int> delRow = {-1, +1, 0, 0};
    vector<int> delCol = {0, 0, -1, +1};
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis){
        vis[row][col] = 1;  // mark as visited

        int n = grid.size();
        int m = grid[0].size();

        // iterate in all possible 4 directions:
        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            // Check bound, is-land, not-visited yet
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && !vis[nRow][nCol]){
                dfs(nRow, nCol, grid, vis);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        // Iterate in first & last row:
        for(int i=0;i<m;i++){
            // first row:
            if(grid[0][i] == 1 && !vis[0][i]){
                dfs(0, i, grid, vis);
            }
            // last row:
            if(grid[n-1][i] == 1 && !vis[n-1][i]){
                dfs(n-1, i, grid, vis);
            }
        }

        // Iterate in first & last col:
        for(int i=0;i<n;i++){
            // first col:
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(i, 0, grid, vis);
            }
            // last col:
            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                dfs(i, m-1, grid, vis);
            }
        }

        // Last check for unvisited 1's & count them:
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};



// BFS Approach:
class Solution_BFS {
private:
    vector<int> delRow = {-1, +1, 0, 0};
    vector<int> delCol = {0, 0, -1, +1};
    void bfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;    // use queue DS -> queue<row, col>
        q.push({row, col});         // push the given nodes:
        vis[row][col] = 1;          // mark that given node as visited

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // iterate & check in all the 4-directions;
            // Check Bound, is-land, not-visited Yet
            for(int i=0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && !vis[nRow][nCol]){
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        // Iterate in first & last row:
        for(int i=0;i<m;i++){
            // first row:
            if(grid[0][i] == 1 && !vis[0][i]){
                bfs(0, i, grid, vis);
            }
            // last row:
            if(grid[n-1][i] == 1 && !vis[n-1][i]){
                bfs(n-1, i, grid, vis);
            }
        }

        // Iterate in first & last col:
        for(int i=0;i<n;i++){
            // first col:
            if(grid[i][0] == 1 && !vis[i][0]){
                bfs(i, 0, grid, vis);
            }
            // last col:
            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                bfs(i, m-1, grid, vis);
            }
        }

        // Last check for unvisited 1's & count them:
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};