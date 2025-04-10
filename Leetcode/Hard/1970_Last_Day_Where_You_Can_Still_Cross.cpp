/*

//  1970. Last Day Where You Can Still Cross


//  Problem Statement: 
    -> There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.
    -> Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).
    -> You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).
    -> Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.


// Example: 

    Example 1:

        Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
        Output: 2
        Explanation: The above image depicts how the matrix changes each day starting from day 0.
        The last day where it is possible to cross from top to bottom is on day 2.

    Example 2:

        Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
        Output: 1
        Explanation: The above image depicts how the matrix changes each day starting from day 0.
        The last day where it is possible to cross from top to bottom is on day 1.

    Example 3:

        Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
        Output: 3
        Explanation: The above image depicts how the matrix changes each day starting from day 0.
        The last day where it is possible to cross from top to bottom is on day 3.


// Observations: 
    -> We are given 1-based index grid, with all cells = '0' initially.
    -> We are also given some query cells => denotes we have to overwrite grid with ''1''
    -> We need to return the lastDay/lastQuery on which we can move from first row to last Row.

    // BruteForce Approach:  Raw BFS/DFS
        -> Get the query & process it.
        -> Alongside on every query check whether we can reach from first row to last row or not with any BFS/DSF traversal..
        -> Gives TLE, because for every query we are iterating that.

        // Complexity:
            -> TC: O((n * m) * (n * m)) => (n^2 * m^2)
            -> SC: O(n * m)


    // Better Solution: Applying Binary Search on bruteforce solution.
        -> We are processing the queries, & There's some point where we have our lastDay.
        -> we can apply binary search and find what is the last day on which we have our answer true.

        // Complexity: 
            -> TC: O(log(q) * (n * m))
                -> log q => total number of query we have.
            -> SC: O(n * m)

    // Efficient Approach: DSU Based Solution:
        -> We can think of DSU solutions, because graph is constantly changing.
        -> Also we can keep track of how much components we will have in our graph.
        -> When we are building DSU Solution, think of a solutions in reversed order.
            -> Reverse process: start with all cells flooded.
            -> Un-flood one cell at a time (backwards through the days).
            -> For each un-flooded cell, connect it to adjacent un-flooded cells via DSU.
            -> Use virtual nodes to represent the top and bottom rows and check if they become connected.

        // DSU Approach: 
            -> mark all the cell with water = '0'
            -> maintain two flag variable virTop & virBottom => which will hold the position top row / bottom row.
            -> Start from backword query, & start removing water.
                -> get the cellNo for every cell & check wether it's falls into the first or last row, & if it's then connect accordingly..
                -> While we remove water, merge the land components, by simply iterating in all 4 directions from current cell.
            -> after that when explorations completed, check if topVirtual is somehow connected with bottom virtual or not?
            -> if it's connected, then breakout right-away.
            -> else decrement the lastDay & keep looking backword query..

        // Complexity: 
            -> TC: O(n * m)
            -> SC: O(n * m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// DSU Approach: 
class DSU {
private:
    vector<int> parent, size;
public: 
    DSU (int n) {
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
};

class Solution {
private: 
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n = row , m = col;

        int total = n * m;          // total number of cells in our grid from 0 to n*m
        int topVir = total;         // this is used to track wether any components touches top row
        int bottomVir = total + 1;  // this is used to track wether any components touches bottom row
        DSU ds(total + 1);          // Create DSU of total size + 1, because this much nodes we have which we can connect.

        vector<vector<int>> grid(n, vector<int> (m, 1));    // initially mark everything with '0'
        int tQuery = cells.size();  // total query size
        int lastDay = tQuery;       // initialize last day with query size

        // Process query:
        for(int q = tQuery - 1; q >= 0; q--) {
            int i = cells[q][0] - 1, j = cells[q][1] - 1;   // get cell coordinates
            
            grid[i][j] = 0; // OverWrite cells with '0'
            int cellNo = i * m + j; // get the cell no

            // Check wether i is at 0 || i is at n - 1 => connect Virtual top/bottom accordingly.
            if(i == 0) ds.Union(cellNo, topVir);                // connect it with topVirtual
            else if(i == n - 1) ds.Union(cellNo, bottomVir);    // connet it with bottomVirtual


            // Now iterate in 4 directions & join the components of current cell with adjCells: 
            for(int k = 0; k < 4; k++) {
                int r = i + dir[k][0];
                int c = j + dir[k][1];

                if(isValid(r, c) && grid[r][c] == 0) {  // within valid Bound & should have valid cell to merge:
                    int adjCellNo = r * m + c;      // get the adjacent cell no.
                    ds.Union(cellNo, adjCellNo);    // merge with them:
                }
            }
            
            // Last check whether topVirtual & bottomVirtual is connected or not by anyPath:
            if(ds.ultPar(topVir) == ds.ultPar(bottomVir)) {
                lastDay = q;    // assign the lastDay as query dat
                break;          // break out as we don't need to iterate backword, because we get the lastDay
            }

            lastDay--;  // decrement the day, because we are processing query in reversed order:
        }
        
        return lastDay;
    }
};


// Binary Search with BFS Approach: 
class Solution {
private:
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    bool canGo(vector<vector<int>>& grid) { // This function will try to check, can we go from first row to last row ?
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));

        for(int i = 0; i < m; i++) {
            if(!grid[0][i]) {
                q.push({0, i});
                vis[0][i] = 1;
            }
        }

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            if(row == n - 1) return true;

            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(isValid(r, c) && !vis[r][c] && !grid[r][c]) {
                    vis[r][c] = 1;

                    q.push({r, c});
                }
            }
        }

        return false;   // can't reach that positions.
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n = row, m = col;
        int lastDay = 0;

        int left = 1;
        int right = cells.size();
        while(left <= right) {
            int mid = left + (right - left) / 2;    // calculate middle day

            // Create a fresh grid everytime & Flood cells till mid day:
            vector<vector<int>> grid(n, vector<int> (m, 0));
            for(int i = 0; i < mid; i++) {
                int r = cells[i][0] - 1;
                int c = cells[i][1] - 1;
                grid[r][c] = 1; 
            }

            // Now check wether we are on correct range or not?
            if(canGo(grid)) {   // if it returns true, explore right side for last day.
                lastDay = mid;
                left = mid + 1;     // try to find later day
            } else {
                right = mid - 1;    // we got false, means we have to look on left...
            }
        }

        return lastDay;
    }
};

// BruteForce Solution: TLE
class Solution {
private:
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    bool canGo(vector<vector<int>> &grid) { // This function will try to check, wether we can go from first row to last row?
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));

        for(int i = 0; i < m; i++) {
            if(!grid[0][i]) {
                q.push({0, i});
                vis[0][1] = 1;
            }
        }

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            if(row == n - 1) return true;

            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(isValid(r, c) && !vis[r][c] && !grid[r][c]) {
                    vis[r][c] = 1;

                    q.push({r, c});
                }
            }
        }

        return false;   // can't reach that positions.
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n = row, m = col;
        vector<vector<int>> grid(n, vector<int> (m, 0));

        int lastDay = 0;
        for(auto &it: cells) {
            int i = it[0] - 1, j = it[1] - 1;
            grid[i][j] = 1; // mark that cell as true; 
            
            // Now check in grid whether it's possible to reach last row:
            if(canGo(grid)) lastDay++;
            else break;
        }


        return lastDay;
    }
};