/*

//  1391. Check if There is a Valid Path in a Grid


//  Problem Statement: 
    -> You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:
        -> 1 which means a street connecting the left cell and the right cell.
        -> 2 which means a street connecting the upper cell and the lower cell.
        -> 3 which means a street connecting the left cell and the lower cell.
        -> 4 which means a street connecting the right cell and the lower cell.
        -> 5 which means a street connecting the left cell and the upper cell.
        -> 6 which means a street connecting the right cell and the upper cell.
    -> You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.
    -> Notice that you are not allowed to change any street.
    -> Return true if there is a valid path in the grid or false otherwise.

    
// Example: 
    Example 1:

        Input: grid = [[2,4,3],[6,5,2]]
        Output: true
        Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).

    Example 2:

        Input: grid = [[1,2,1],[1,2,1]]
        Output: false
        Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)

    Example 3:

        Input: grid = [[1,1,2]]
        Output: false
        Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).



// BFS Approach: 
    -> From the given grid, we need to find whether we can reach from (0, 0) to (n-1, m-1) from the given grid.
    -> give grid cells has number assigned: 
        -> 1, 2, 3, 4, 5, 6 telling where it can go..
            1: L R
            2: U D
            and so on...

    -> If we observe carefully, every grid cell has 2 directions.
        -> One will be from where we are coming.
        -> and other will be where we are going.

    
    -> If we observe carefully, we can solve this question with piece of cake..
    -> 1st: 
        -> For every current cell: 
            -> get all the directions it can go.
            -> make sure it should be in valid grid range.
            -> example: if grid[row][col] = 2 => it can go Up & down, So, up & down should be in valid grid range.
            -> Check, the directions should not be visited, because, we are coming from some other cell & we want to go some other cell.
    
    -> 2nd: 
        -> For every adjNeighbors:
            -> Now get all the directions of adjNeighbors it can go
            -> now check is there any path to go from original node to adjNode.
            -> We can check this by simply comparing the two opposite directions: 
                L -> R
                R -> L
                U -> D
                D -> U

                -> If we carefully observe the two opposite directions coordinates:
                -> if we sum up the coordinates of two opposite directions, we will get '0'
    

    -> IF 1st & 2nd Conditions are valid, we can traverse : else we can't
    -> At any movement if we reach destinations => return true.

        
    // Complexity: 
        -> TC: O(N * M)
        -> SC: O(N * M)




// DSU Approach: 
    -> With DSU we can easily solve this problem: 
        -> It's just we have to check first cell & last cell of grid after merging...
    -> Simillar to previous Implementation via BFS, we have to implement this DSU solution...

        
    // Complexity: 
        -> TC: O(N * M)
        -> SC: O(N * M)

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
        }
        else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

class Solution {
private: 
    int n, m;
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    vector<pair<int, int>> getDir(int x) {
        if(x == 1) return {{0, -1}, {0, 1}};
        else if(x == 2) return {{-1, 0}, {1, 0}};
        else if(x == 3) return {{0, -1}, {1, 0}};
        else if(x == 4) return {{0, 1}, {1, 0}};
        else if(x == 5) return {{0, -1}, {-1, 0}};
        else return {{0, 1}, {-1, 0}};
    }
    bool isAllowed(int x1, int y1, int x2, int y2) {
        return (x1 + x2 == 0 && y1 + y2 == 0);
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        DSU ds(n * m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vector<pair<int, int>> dir = getDir(grid[i][j]);    // get current cell Directions
                int cellNo = i * m + j;

                // Iterate in current cell direction: 
                for(auto &[dx, dy]: dir) {
                    
                    // Get adjNeighbors (row, col)
                    int row = dx + i;
                    int col = dy + j;

                    if(isValid(row, col)) { // check valid bound:
                        vector<pair<int, int>> adjDir = getDir(grid[row][col]);    // get adjCell directions:
                        
                        // Iterate in adj Cell Directions:
                        for(auto &[dx2, dy2]: adjDir) {
                            if(isAllowed(dx, dy, dx2, dy2)) {
                                int ngbrCellNo = row * m + col;
                                
                                ds.Union(cellNo, ngbrCellNo);   // merge them

                                break;  // once valid, no need to check other directions..
                            }
                        }
                    }
                }
            }
        }

        // Last check: if first & last cell is conencted or not => denotes there is a path.
        return (ds.ultPar(0) == ds.ultPar(n * m - 1));
    }
};


// BFS Approach:
class Solution {
private:
    int n, m;

    // Directions: Left, Right, Up, Down
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    // Check grid bounds
    bool isValid(int r, int c) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }

    // Return valid directions based on the current cell's street type
    vector<pair<int, int>> getDirections(int streetType) {
        vector<pair<int, int>> directions;

        switch(streetType) {
            case 1: directions = {{0, -1}, {0, 1}}; break;       // Left, Right
            case 2: directions = {{-1, 0}, {1, 0}}; break;       // Up, Down
            case 3: directions = {{0, -1}, {1, 0}}; break;       // Left, Down
            case 4: directions = {{0, 1}, {1, 0}}; break;        // Right, Down
            case 5: directions = {{0, -1}, {-1, 0}}; break;      // Left, Up
            case 6: directions = {{0, 1}, {-1, 0}}; break;       // Right, Up
        }

        return directions;
    }

    // Check if two directions are exact opposites (i.e., connection is valid)
    bool isEntryAllowed(int dx1, int dy1, int dx2, int dy2) {
        return (dx1 + dx2 == 0 && dy1 + dy2 == 0);
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        // Special case: single cell
        if(n == 1 && m == 1) return true;

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        // Start BFS from top-left cell
        visited[0][0] = 1;
        q.push({0, 0});

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            // If we've reached the destination, path is valid
            if(row == n - 1 && col == m - 1) return true;

            // Get valid directions for the current cell
            vector<pair<int, int>> possibleDirs = getDirections(grid[row][col]);

            for(auto &[dx, dy] : possibleDirs) {
                int nextRow = row + dx;
                int nextCol = col + dy;

                if(isValid(nextRow, nextCol) && !visited[nextRow][nextCol]) {
                    // Check if the adjacent cell can connect from this direction
                    vector<pair<int, int>> adjDirs = getDirections(grid[nextRow][nextCol]);
                    for(auto &[dx2, dy2] : adjDirs) {
                        if(isEntryAllowed(dx, dy, dx2, dy2)) {
                            visited[nextRow][nextCol] = 1;
                            q.push({nextRow, nextCol});
                            break; // No need to check further directions
                        }
                    }
                }
            }
        }

        // If we exit the loop, path wasn't found
        return false;
    }
};
