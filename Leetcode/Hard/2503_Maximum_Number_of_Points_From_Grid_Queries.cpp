/*

//  2503. Maximum Number of Points From Grid Queries


//  Problem Statement: 
    -> You are given an m x n integer matrix grid and an array queries of size k.
    -> Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:
        -> If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
        -> Otherwise, you do not get any points, and you end this process.
    -> After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.
    -> Return the resulting array answer.

// Example: 

    Example 1:
        Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
        Output: [5,8,1]
        Explanation: The diagrams above show which cells we visit to get points for each query.

    Example 2:
        Input: grid = [[5,2,1],[1,1,2]], queries = [3]
        Output: [0]
        Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.

// Observations: 
    -> given grid of n x m contains grid[i][j]  &  should be (grid[i][j] < queries[i]), then only we can move to adjacent cells.
    -> we need to find the maximum cell we can traverse in every query from starting point (0, 0).


// BruteForce Solution: 
    -> If we Think from bruteForce approach: 
        -> calling BFS from (0, 0) for every query & checking how many valid cell we can process, will make our job done..
    -> Falls Into TLE: 
    
    // Complexity: 
        -> TC: O(Q * (n * m))
            -> Q = Query size
            -> n * m = BFS traversal.
        -> SC: O((n * m) + Q)
            -> N * m visited grid
            -> Q for building answer

// DSU Solution: 
    // Why DSU ? 
        -> Given question has queries, & we need to check how many cell we can traverse from (0, 0) for every query.
        -> DSU will help us to build multiple components along the grid & with getSize(grid(0, 0)) we can track the size for every query.

    // Approach: 
        -> DSU Required bit modifications with grid & queries itself.
        // Sorting Queries: 
            -> we can build every queries answer in sorted fashion, this will help us to track & process grid[i][j] values in order & merging cells will be more logical...
            -> We can use map to store every query answer and later-on when we build our answer, we can fetch the value from map according the original queries list
            -> NOTE: make tempQueries & then sort it & process..


        // Sorting Matrix:
            -> sorting matrix according to their value will help us to process it more optimally, & this will improve our time complexity..
            -> Sorting required flattening the matrix:
                // Flatten Matrix: 
                    -> Create 1D vector of size(n * m) & store the values from matrix:
                    -> Structure: vector<tuple<int, int, int>> => <value, i, j>
            
            // QUESTION: You might be wondering but sorting & processing will loss the track of query size?

                // Example: 
                        grid: 

                               0   1   2
                           0 | 1,  10, 4| 
                           1 | 19, 3,  5| 
                           2 | 4,  9,  5| 

                    Well you might be thinking if we sort this grid according to the value.
                    and let say our query = 6

                    Then value (1(0, 0), 3(1, 1), 4(2, 0), 4(0, 2), 5(1, 2), 5(2, 2)) will be processed IN DSU, right?

                    Yes, it will processed but, all of them are not connected with '1' which is at (0, 0).
                    Because at max we can go 4 direction from every cell (right, left, up, down).
                    And from (0, 0) as per the query, we can't go anywhere, because neighbors have larger value than query.
                    But sill our DSU components are processed & formed...
                
            -> Simple Solution is: whenever we are storing the size of every query:
                -> We will always store the size of cell(0), because:
                -> During the query, if any cell connected with cell(0), we can get the accurate size.
                    
        // Rest Logic:
            -> Rest logic is simple: 
                -> process query: 
                -> merge them with query & matrix... 

    // Complexity: 
        -> TC: O(Q + n * m)
            -> (n * m) inside the query will only runs at only once, because 'i' initalized outside the queries.
            -> also we are processing every cells only ones.
        
        -> SC: O((n * m) + Q)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// DSU Approach:
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
    int getSize(int x) {
        return size[ultPar(x)];
    }
};

// Accepted:
class Solution {
private: 
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        n = grid.size(), m = grid[0].size();
        
        // Flatten the given grid:
        vector<tuple<int, int, int>> mat(n*m);   // dimensions (0 to n*m);
        int k = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mat[k++] = {grid[i][j], i, j};  // Structure: <value, i, j>
            }
        }

        // Sort flatten grid mat, & queries
        sort(begin(mat), end(mat));
        vector<int> qTemp = queries;
        sort(begin(qTemp), end(qTemp));


        // Now Process every query & Build Components
        DSU ds(n * m);
        unordered_map<int, int> qmp;  // used to store every query comopenent size.
        int i = 0;  // placing i at outer scope will not call redundantly from'0'...
        for(auto &query: qTemp) {
            if(qmp.count(query)) continue;  // If query already processed, skip: 

            // While mat has value lesser than the query connect the Components: 
            for(i; i < n*m; i++) {

                // Get values:
                int cellVal = get<0>(mat[i]);
                int row = get<1>(mat[i]);
                int col = get<2>(mat[i]);

                if(cellVal >= query) break;    // if cell value exceeds the query break out.
                int cellNo = row * m + col;     // get cell no

                // Explore 4 directions & connect valid components: 
                for(int dirIdx = 0; dirIdx < 4; dirIdx++) {
                    int r = row + dir[dirIdx][0];
                    int c = col + dir[dirIdx][1];

                    if(isValid(r, c) && grid[r][c] < query) {   // within valid bound & cell should be lesser than the give query:
                        int adjCellNo = r * m + c;      // get the adj cell no
                        ds.Union(cellNo, adjCellNo);    // merge them
                    }
                }
            }

            // store every query component size which is linked to starting cell = (0) into map:
            if(grid[0][0] >= query) {   // if grid cell exceeds query skip it with '0'
                qmp[query] = 0; // is size is greater then '0'
            } else {
                qmp[query] = ds.getSize(0);    // get the component size & should be connected to cell '0
            }
        }

        // Now build answer from query map:
        vector<int> ans;
        for(auto &query: queries) {
            ans.push_back(qmp[query]);
        }

        return ans;
    }
};


// BFS Solution: TLE
class Solution {
private: 
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    int maxPoints(vector<vector<int>>& grid, int k) {

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        q.push({0, 0});
        vis[0][0] = 1;

        int totalCnt = 0;
        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            totalCnt++; // increment every cell count

            // Explore 4 directions: 
            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(isValid(r, c) && !vis[r][c]) {
                    if(grid[r][c] < k) {
                        vis[r][c] = 1;

                        q.push({r, c});
                    }
                }
            }
        }

        return totalCnt;
    }
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        n = grid.size(), m = grid[0].size();
        int qSize = queries.size();

        vector<int> ans;
        for(auto &it: queries) {
            if(it < grid[0][0]) {
                ans.push_back(0);
            } else {
                ans.push_back(maxPoints(grid, it));
            }
        }

        return ans;
    }
};