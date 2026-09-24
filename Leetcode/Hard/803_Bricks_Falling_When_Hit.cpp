/*

//  803. Bricks Falling When Hit


//  Problem Statement: 
    - You are given an m x n binary grid, where each 1 represents a brick and 0 represents an empty space. A brick is stable if:
        - It is directly connected to the top of the grid, or
        - At least one other brick in its four adjacent cells is stable.
    - You are also given an array hits, which is a sequence of erasures we want to apply. Each time we want to erase the brick at the location hits[i] = (rowi, coli). The brick on that location (if it exists) will disappear. Some other bricks may no longer be stable because of that erasure and will fall. Once a brick falls, it is immediately erased from the grid (i.e., it does not land on other stable bricks).
    - Return an array result, where each result[i] is the number of bricks that will fall after the ith erasure is applied.
    - Note that an erasure may refer to a location with no brick, and if it does, no bricks drop.

//  Example:

        Example 1:
            Input: grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
            Output: [2]
            Explanation: Starting with the grid:
                [[1,0,0,0],
                [1,1,1,0]]
                We erase the underlined brick at (1,0), resulting in the grid:
                [[1,0,0,0],
                [0,1,1,0]]
                The two underlined bricks are no longer stable as they are no longer connected to the top nor adjacent to another stable brick, so they will fall. The resulting grid is:
                [[1,0,0,0],
                [0,0,0,0]]
                Hence the result is [2].

        Example 2:

            Input: grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
            Output: [0,0]
            Explanation: Starting with the grid:
                [[1,0,0,0],
                [1,1,0,0]]
                We erase the underlined brick at (1,1), resulting in the grid:
                [[1,0,0,0],
                [1,0,0,0]]
                All remaining bricks are still stable, so no bricks fall. The grid remains the same:
                [[1,0,0,0],
                [1,0,0,0]]
                Next, we erase the underlined brick at (1,0), resulting in the grid:
                [[1,0,0,0],
                [0,0,0,0]]
                Once again, all remaining bricks are still stable, so no bricks fall.
                Hence the result is [0,0].

 

// Observations:
    - given n x m grid:
        - grid[i][j] = 1 => denotes have brick
        - grid[i][j] = 0 => empty space

    - brick is stable if:
        - it is directly connected to the top of the grid or
        - at least one other brick in it's four adjacent cell is stable.

    // BruteForce Solution:L    
        - for every hit:
            - remove that particular cell.
            - iterate from the first row: and explore all the touch cells, and mark them visited.
            - and remaining leftover 1's will fall obviously.
            - eg:
                if [0,0] is removed:

                    0   0   0
                    1   1   1

                all 3 will fall

        - bruteforce solution will falls into tle.

            // Complexity:
                - TC: O(n^4 * m^4)
                - SC: O(n * m)


    // DSU Approach:
        - we will have to optimize the solution, to better time complexity..
        - DSU will help us to track the connected component in real time.
        - we will have to figure out how we can track of the total number of connected component in real time by disconnecting the nodes..

        1   0   0   1
        1   1   0   1
        1   0   1   1
        0   1   1   1


    - When Optimizing with DSU: 
        - we will use the simillar trick that we used to solve earlier problem leetcode 1970
        - we will process the query in reversed order.
        - we will require one extra cell-> for the "roof" top row connectivity.
            - DSU is good in connecting nodes and building connected components and gives us the informations in realtime.
            - Now, how we can compute the query and get the track of component which is in realtime.

        - If we reversely process the query:
            - first thing we will be required is the DSU component at the time when all the previous brick is removed.
                - so we will first remove all the brick from the hits.
                - and form connected components.
                - also, during components formation, we will make sure to maintain the "roof" cell:
            - Now, we will process the query from the back:
                - first we will compute the before:
                    - which is the total number of nodes at the time after the hit logically.
                    - this information will help us to compute the total number of brick falls.
                - Now from the current query:
                    - we will fill grid with 1:
                        - and iterate in all 4 directions:
                            - and connect the current cell with every 1's explored in path.

                
                - once it's done, now we will have updated component details.
                - calculate the "after":
                    - which is nothing but the total number of bricks connected before hit logically..

                - now, the difference b/w the before and after is total number of brick falls at that current query.
            

            - It's just bit confisoing, to do all that, it will work as we process...


        - concluding:
            - first we will have to remove all the brick from the grid.
                - keep the information of removed brick..
            - now using DSU, connect nodes, and form connected components.
            - once we build all this:
                - start from the back of hits:
                    - calculate the size of roof: before
                    - fill the grid for current hit, and connect that cell in all 4 directions.
                    - now calculate the size of roof: after
                    - get the diff: after - before => this much brick is fall.


    

        // Complexity:
            - TC: O(n * m)
            - SC: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Better solution:
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

        // connect smaller grp to larger one:
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
    int n, m;   // grid dimensions.
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};    // dir: left, right, above, below.
    bool isValidDim(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}    // function to validate the grid dimensions.
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        n = grid.size();
        m = grid[0].size();

        // Initially remove all the hits from the grid:
        vector<vector<int>> removed(n, vector<int> (m, 0)); // Keep the information of every removed brick
        for(auto &i: hits) {
            int r = i[0], c = i[1];
            if(grid[r][c] == 1){
                grid[r][c] = 0;
                removed[r][c] = 1;
            }

        }

        // Now compute the DSU and form connected components:
        int roof = n * m;   //  require one extra for the top Row: topRow = (n * m)
        DSU ds((n * m) + 1);  // total cell: {0 to (n*m-1)}

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    int cellNo = i * m + j;

                    // explore in all 4 directions & connect it with the same land cell:
                    for(auto &[x, y]: dir) {
                        int r = i + x;
                        int c = j + y;


                        if(isValidDim(r, c) && grid[r][c] == 1) {
                            int adjCellNo = r * m + c;

                            ds.Union(cellNo, adjCellNo);
                        }
                    }

                    // we will have to connect every i == 0, with roof
                    if(i == 0) {
                        ds.Union(cellNo, roof);
                    }
                }
            }
        }


        // Now, process the query in reversed order & fill the grid and get the informations of every current cell:
        vector<int> ans(hits.size());
        for(int i = hits.size() - 1; i >= 0; i--) {
            int row = hits[i][0];
            int col = hits[i][1];

            // This hit didn't actually remove a brick, thefor nothing should be restore:
            if(!removed[row][col]) {
                ans[i] = 0;
                continue;
            }

            // Step 1: before restoring, calculate how many brick are currently connected with roof:
            int before = ds.getSize(roof);
            
            
            // Step 2: restore the current brick:
            grid[row][col] = 1;
            int cellNo = row * m + col;

            if(row == 0) {  // if it's the first row: connect it with the roof:
                ds.Union(cellNo, roof);
            }

            // now connect to it's neighbors in all 4 directions:
            for(auto &[x, y]: dir) {
                int r = row + x;
                int c = col + y;

                if(isValidDim(r, c) && grid[r][c] == 1) {
                    int adjCellNo = r * m + c;

                    ds.Union(cellNo, adjCellNo);
                }
            }

            // Step 3: After Restoring + connection, check how much roof component grows:
            int after = ds.getSize(roof);

            // after - before include the brick just we removed, therefore subtract 1, max(0, ...) haddels the case where the restored brick itself doesn't make any other brick connected to the roof
            ans[i] = max(0, after - before - 1);

        }

        return ans;
    }
};





// BruteForce Solution:
class Solution_ {
private:
    int n, m;   // grid dimension.
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};    // dir: left, right, above, below.
    bool isValidDim(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;

        for(auto &[x, y]: dir) {
            int r = row + x;
            int c = col + y;

            if(isValidDim(r, c) && !vis[r][c] && grid[r][c] == 1) {
                dfs(r, c, grid, vis);
            }
        }
    }
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        n = grid.size();
        m = grid[0].size();

        vector<int> ans;
        for(auto &k: hits) {
            int row = k[0], col = k[1];

            // unmark that cell:
            grid[row][col] = 0;

            // start from the first row & visit all the cells:
            vector<vector<int>> vis(n, vector<int> (m, 0));
            for(int i = 0; i < m; i++) {
                if(grid[0][i] == 1 && !vis[0][i]) {
                    dfs(0, i, grid, vis);
                }
            }

            // now count the 1's that are not visited & also update as these brick will fall:
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] == 1 && !vis[i][j]) {
                        cnt++;
                        grid[i][j] = 0; // these bricks will fall..
                    }
                }
            }

            ans.push_back(cnt);
        }
        
        return ans;
    }
};