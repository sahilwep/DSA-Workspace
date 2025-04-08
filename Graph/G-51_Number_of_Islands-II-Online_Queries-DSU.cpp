/*


//  G-51. Number of Islands - II - Online Queries - DSU


//  Problem Statement: 
    -> You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. 
    -> Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. 
    -> The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell 
    -> matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
    -> Note : An island means group of 1s such that they share a common side.

    Example 1:

        Input: n = 4
        m = 5
        k = 4
        A = {{1,1},{0,1},{3,3},{3,4}}

        Output: 1 1 2 2
            Explanation:
                0.  0 0 0 0 0
                    0 0 0 0 0
                    0 0 0 0 0
                    0 0 0 0 0

                1.  0 0 0 0 0
                    0 1 0 0 0
                    0 0 0 0 0
                    0 0 0 0 0

                2.  0 1 0 0 0
                    0 1 0 0 0
                    0 0 0 0 0
                    0 0 0 0 0

                3.  0 1 0 0 0
                    0 1 0 0 0
                    0 0 0 0 0
                    0 0 0 1 0

                4.  0 1 0 0 0
                    0 1 0 0 0
                    0 0 0 0 0
                    0 0 0 1 1


    Example 2:

        Input: n = 4
        m = 5
        k = 4
        A = {{0,0},{1,1},{2,2},{3,3}}

        Output: 1 2 3 4

            Explanation:
                0.  0 0 0 0 0
                    0 0 0 0 0
                    0 0 0 0 0
                    0 0 0 0 0

                1.  1 0 0 0 0
                    0 0 0 0 0
                    0 0 0 0 0
                    0 0 0 0 0

                2.  1 0 0 0 0
                    0 1 0 0 0
                    0 0 0 0 0
                    0 0 0 0 0

                3.  1 0 0 0 0
                    0 1 0 0 0
                    0 0 1 0 0
                    0 0 0 0 0

                4.  1 0 0 0 0
                    0 1 0 0 0
                    0 0 1 0 0
                    0 0 0 1 0

// Observations:

    // DSU Approach: 
        -> DSU will helps us to get the total number of island in realTime, because we can keep track of how many component are there in our graph.
        -> For every Query given (row, col):
            -> Initially assume every cell as independet island & increment the component counter.
            -> Now for every cell we can iterate in all 4 directions & check: 
                -> If any directions components is not connected yet with the current cell/island:
                    -> connect them & decrement the island count.
                -> Similarly check it will all directions & if it's the different components, connect & decrement the

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
    

// Complexity: 
    -> TC: O(k * α(n * m)) => O(k)
        -> k is for query
        -> α(n * m) will be linear practically...
    -> SC: O(n * m + k)
        -> (n * m) for dsu
        -> k for answer

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
        int u = ultPar(u_);
        int v = ultPar(v_);
        
        if(u == v) return;
        
        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += v;
        }
    }
};

class Solution {
private: 
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
public:
    vector<int> numOfIslands(int n_, int m_, vector<vector<int>> &operators) {
        n = n_, m = m_;
        
        DSU ds(n * m);  // size of dsu
        vector<vector<int>> vis(n, vector<int> (m, 0)); // size of visited grid
        
        int cnt = 0;    // maintain the count of island
        vector<int> ans;    // maintain the count of island for every query.
        
        for(auto &it: operators) { // for every query:
            int row = it[0];
            int col = it[1];
            
            if(vis[row][col]) { // if that cell is already visited
                ans.push_back(cnt); // directly insert the count value.
                continue;
            }

            // Else part: if it's not not explored earlier:
            vis[row][col] = 1;  // mark that cell as visited
            cnt++;              // assume the cell itself as a alone island.
            
            
            // Now check in all 4 directions & if we are able to find any islands, join them..
            for(int i = 0; i < 4; i++) {
                int adjRow = row + dir[i][0];   // get the adjacent row
                int adjCol = col + dir[i][1];   // get the adjacent col
                
                if(isValid(adjRow, adjCol)) { // Check adjacent row & col, lies in valid bound:
                
                    if(vis[adjRow][adjCol] == 1) {              // Only if adjacent cell is already computed / visited.
                        
                        // Formula to get CellNo: (row * m + col)
                    
                        int cellNo = row * m + col;             // This will give us the cell number of original (row,col).
                        int adjCellNo = adjRow * m + adjCol;    // This will give us the adj cell number.
                        
                        // Now check wether they have already in 
                        if(ds.ultPar(cellNo) != ds.ultPar(adjCellNo)) {     // if they are in different components:
                            ds.Union(cellNo, adjCellNo);    // join them together
                            cnt--;                          // subtract count as we are connecting two different component together.
                        }
                    }   
                }
            }
            
            ans.push_back(cnt);  // last push answer for every given query.
        }
        
        return ans;
    }
};
