/*

//  1559. Detect Cycles in 2D Grid


//  Problem Statement: 
    -> Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.
    -> A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.
    -> Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.
    -> Return true if any cycle of the same value exists in grid, otherwise, return false.

 
// Example:
    Example 1:
        Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
        Output: true
        Explanation: There are two valid cycles shown in different colors in the image below:

    Example 2:
        Input: grid = [["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
        Output: true
        Explanation: There is only one valid cycle highlighted in the image below:

    Example 3:
        Input: grid = [["a","b","b"],["b","z","b"],["b","b","a"]]
        Output: false



// BFS Approach:
    -> We can use BFS:
        -> Iterate in all 4 direction & try to find the node that is already visited.
        -> If the element is already visited & we are iterating the same type of node then we can say it's circle.
        -> We need to take care of parent node, because we don't want to visit the same node from where we are coming.
        -> we can use queue Data Structure:
                queue<<row, col>, <parentRow, parentCol>>> 

    // Complexity:
        -> TC: O(n*m)
        -> SC: O(n*m)


// DFS Approach:

// DFS Approach: 
    -> Explore all possible direction:
    -> Check valid Bound range, if element is not visited yet & same type of element -> Then iterate further.
    -> If element is already visited & same type & it's not the parent means we found the cycle.
    -> In simple, need to take care of parentRow, from where we are coming.

    // Example:
            a  a  a
            a  b  a
            a  a  a

        -> Index:

            (0, 0)   (0, 1)  (0, 2)
            (1, 0)   (1, 1)  (1, 2)
            (2, 0)   (2, 1)  (2, 2)


        -> Calls Stack:

                            dfs(0, 0, -1, -1):  
                                |
                                |--->dfs(1, 0, 0, 0):
                                |       |
                                |       |----> dfs(2, 0, 1, 0)
                                |               |
                                |               |----> dfs(2, 1, 2, 0)
                                |                       |
                                |                       |----> dfs(2, 2, 2, 1)
                                |                               |
                                |                               |----> dfs(1, 2, 2, 2)
                                |                                       |
                                |                                       |----> dfs(0, 2, 1, 2)
                                |                                               |
                                |                                               |----> dfs(0, 1, 0, 2)
                                |                                                       |
                                |                                                       |----> dfs(0, 0, 0, 1)  -> Return true 
                                |                                                       
                                |                                                       
                                |--->dfs(0, 1, 0, 0)    -> Never goes for this call, because above calls return true, & if any call return true, it will return true to their parent.



    // Complexity:
        -> TC: O(V + 2E)
        -> SC: O(V + 2E)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// DFS Approach:
class Solution_DFS {
private:
    int delRow[4] = {-1, +1, 0, 0};
    int delCol[4] = {0, 0, -1, +1};
    bool solve(int row, int col, int pRow, int pCol, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[row][col] = 1;  // mark current node as visited
        int n = grid.size();
        int m = grid[0].size();

        // Explore the adjacent nodes:
        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            // Check Valid bound:
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m){
                // Check node is not visited & same type of node:
                if(!vis[nRow][nCol] && grid[nRow][nCol] == grid[row][col]){
                    // visit that node:
                    if(solve(nRow, nCol, row, col, grid, vis) == true) return true; // return true if it's found a cycle
                }
                // if node is already visited & same type of node && it's not the parent node, means we got a cycle
                else if(vis[nRow][nCol] && grid[nRow][nCol] == grid[row][col] && !(nRow == pRow && nCol == pCol)){
                    return true;    // cycle found, return true in this case.
                }
            }
        }

        return false;   // else return false
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0)); // visited matrix


        // Checking for Multiple Components:
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){ // if node is not visited yet?
                    if(solve(i, j, -1, -1, grid, vis) == true) return true;   // cycle found
                }
            }
        }

        return false;   // no cycle found
    }
};


// BFS Approach:
class Solution_BFS {
private:
    int delRow[4] = {-1, +1, 0, 0};
    int delCol[4] = {0, 0, -1, +1};
    bool solve(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int, int>, pair<int, int>>> q;
        q.push({{row, col}, {-1, -1}});
        vis[row][col] = 1;  // mark current node as visited

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int parRow = q.front().second.first;
            int parCol = q.front().second.second;
            q.pop();

            // iterate & check all the adjacent elements:
            for(int i=0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                // Check Bound:
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m){
                    // Check node is not visited & same Type of node: push it into queue & mark as visited
                    if(!vis[nRow][nCol] && grid[nRow][nCol] == grid[row][col]){
                        q.push({{nRow, nCol}, {row, col}});      // push that element into queue.
                        vis[nRow][nCol] = 1;                    // mark as visited
                    }
                    // if element is already visited & not the parent && same type of node: return true;
                    else if(vis[nRow][nCol] && !(nRow == parRow && nCol == parCol) && grid[nRow][nCol] == grid[row][col] ){
                        return true;
                    }
                }
            }
        }

        return false;   // no cycle found.
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0)); // visited matrix

        // Checking for Multiple Components:
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){ // if node is not visited yet?
                    if(solve(i, j, grid, vis) == true) return true;   // cycle found
                }
            }
        }

        return false;   // no cycle found
    }
};