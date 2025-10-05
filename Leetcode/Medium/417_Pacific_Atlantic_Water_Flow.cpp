/*

//  417. Pacific Atlantic Water Flow

//  Problem Statement: 
    -> There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
    -> The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
    -> The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
    -> Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.


    Example 1:
        Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
        Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
        Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
            [0,4]: [0,4] -> Pacific Ocean 
                [0,4] -> Atlantic Ocean
            [1,3]: [1,3] -> [0,3] -> Pacific Ocean 
                [1,3] -> [1,4] -> Atlantic Ocean
            [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
                [1,4] -> Atlantic Ocean
            [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
                [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
            [3,0]: [3,0] -> Pacific Ocean 
                [3,0] -> [4,0] -> Atlantic Ocean
            [3,1]: [3,1] -> [3,0] -> Pacific Ocean 
                [3,1] -> [4,1] -> Atlantic Ocean
            [4,0]: [4,0] -> Pacific Ocean 
                [4,0] -> Atlantic Ocean
            Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

    Example 2:
        Input: heights = [[1]]
        Output: [[0,0]]
        Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.

 

// Observations:
    -> n * m grid, with grid[i][j] = height of the cell of given grid.
    -> left & top => Ocean1
    -> right & bottom => Ocean2
    -> we need to find the cells coordinates that can flow to both the ocean.
    
    // Approach: 
        - for each individual cell:
            - process any bfs/dfs to iterate in all 4 directions & try to find out wether water can be flown on both the ocean or not?
                - We can use some flag which will tell us that wether we are reachable on both the ocean or not?
            - Note when we are exploring the water from one cell to another -> their water level will be changed, means if we are at some cell value 5 & we are going to 3, now our new water level will be 3

        -> This solution Gives TLE
            -> TC: O(n^2 * m^2)
            -> SC: O(n * m)



    // Optimization: 
        // Idea: 
            -> Instead of thinking like going higher to lower cells -> think opposite & go lower to highest cell.
        // Approach:
            -> If we carefully analyze the the cells that are able to reach both the ocean, are the once that create a border from both the ocean
            -> means rest of the cells which are the once who reaches only one ocean or reaches no ocean.
            // Example:
                -> Ocean-1 Pacific Ocean:
                    - If we start from boundary cell & looking for the higher growing cells, & marking all the cells as reachable from pacific
                -> Ocean-2 Atlantic Ocean:
                    - If we start from the boundary cell & looking for the higher growing cell & marking all the cells as reachable from atlantic
                - At the end we will have some cells that are the part of both the ocean (atlantic & pacific) & we can extract those ones..

        // Complexity: 
            -> TC: O(n * m)
            -> SC: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Optimized Solution:
class Solution {
private:
    int n, m;   // dimensions of grid.
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};     // dir: left, right, up, down
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}   // to check valid bound:
    void solve(int row, int col, vector<vector<int>>& heights, vector<vector<int>> &vis) {    // DFS to visit all the higher values cells & mark them visited.

        vis[row][col] = 1;

        // Explore In all 4 directions:
        for(int i = 0; i < 4; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];

            if(isValid(r, c) && !vis[r][c] && heights[r][c] >= heights[row][col]) {
                solve(r, c, heights, vis);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();


        vector<vector<int>> pacific(n, vector<int> (m, 0));
        vector<vector<int>> atlantic(n, vector<int> (m, 0));

        // Explore from Pacific: top, left
        for(int i = 0; i < m; i++) solve(0, i, heights, pacific);   // top
        for(int i = 0; i < n; i++) solve(i, 0, heights, pacific);   // left

        // Explore from Atlantic: bottom, right
        for(int i = 0; i < m; i++) solve(n-1, i, heights, atlantic);    // bottom
        for(int i = 0; i < n; i++) solve(i, m-1, heights, atlantic);    // right

        // Get the cells that are in both pacific & atlantic:
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // Cells that are reachable to both the ocean:
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};




// BruteForce Solution:
class Solution {    // DFS
private:
    int n, m;   // dimensions of grid.
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};     // dir: left, right, up, down
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}   // to check valid bound:
    void solve(int row, int col, vector<vector<int>>& heights, vector<vector<int>> &vis) {    // DFS to visit all the higher values cells & mark them visited.

        vis[row][col] = 1;

        // Explore In all 4 directions:
        for(int i = 0; i < 4; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];

            if(isValid(r, c) && !vis[r][c] && heights[r][c] >= heights[row][col]) {
                solve(r, c, heights, vis);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();


        vector<vector<int>> pacific(n, vector<int> (m, 0));
        vector<vector<int>> atlantic(n, vector<int> (m, 0));

        // Explore from Pacific: top, left
        for(int i = 0; i < m; i++) solve(0, i, heights, pacific);   // top
        for(int i = 0; i < n; i++) solve(i, 0, heights, pacific);   // left

        // Explore from Atlantic: bottom, right
        for(int i = 0; i < m; i++) solve(n-1, i, heights, atlantic);    // bottom
        for(int i = 0; i < n; i++) solve(i, m-1, heights, atlantic);    // right

        // Get the cells that are in both pacific & atlantic:
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // Cells that are reachable to both the ocean:
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};


// BFS:
class Solution {
private:
    int n, m;   // dimensions of grid.
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};     // dir: left, right, up, down
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}   // to check valid bound:
    void solve(int row, int col, vector<vector<int>>& heights, vector<vector<int>> &vis) {    // DFS to visit all the higher values cells & mark them visited.

        vis[row][col] = 1;

        // Explore In all 4 directions:
        for(int i = 0; i < 4; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];

            if(isValid(r, c) && !vis[r][c] && heights[r][c] >= heights[row][col]) {
                solve(r, c, heights, vis);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();


        vector<vector<int>> pacific(n, vector<int> (m, 0));
        vector<vector<int>> atlantic(n, vector<int> (m, 0));

        // Explore from Pacific: top, left
        for(int i = 0; i < m; i++) solve(0, i, heights, pacific);   // top
        for(int i = 0; i < n; i++) solve(i, 0, heights, pacific);   // left

        // Explore from Atlantic: bottom, right
        for(int i = 0; i < m; i++) solve(n-1, i, heights, atlantic);    // bottom
        for(int i = 0; i < n; i++) solve(i, m-1, heights, atlantic);    // right

        // Get the cells that are in both pacific & atlantic:
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // Cells that are reachable to both the ocean:
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};