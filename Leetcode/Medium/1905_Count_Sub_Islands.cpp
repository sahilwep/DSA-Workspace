/*

//  1905. Count Sub Islands

//  Problem Statement: 
    -> You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.
    -> An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.
    -> Return the number of islands in grid2 that are considered sub-islands.

 
// Example:

    Example 1:
        Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
        Output: 3
        Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
        The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

    Example 2:
        Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
        Output: 2 
        Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
        The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.


// Observations: 
    -> Grid2 has island which needs to be present in grid1, So, we need to count all of them..
    -> We need to flag those islands of grid2 which are not present in grid1.
    -> We can run any traversal & check that conditions where we are encounter with Invalid visit.

    // DFS Impl.
        -> Check for every visit, whenever we encounter with island it should be match with grid1, also. & unvisited, in grid2
        -> we don't need to track the visit in grid1, because we are only concern about the condition where grid1 need only island.
        -> Also whenever we get the condition where grid1 has water & grid2 has island, & then we are returning false, first we need to make sure that all the island part should be visited..

    // NOTE: When we are hading the case where we have violations of conditions, we can't directly return "false", because we need to check all the possible conditions where we get the flag again...


// Complexity: 
    -> TC: O(n * m)
        -> Because with "vis" grid, we are visiting every cell at-max once..
    -> SC: O(n * m)
        -> Because of "vis" grid.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
    int n = 0, m = 0;   // dimension of grid
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    // Dir: (0, 0)              left    right       up      down
    bool isValid(int row, int col) {    // function to check valid boundary of every cell position.
        return (row >= 0 && row < n && col >= 0 && col < m);
    }
    void dfsVisit(int row, int col, vector<vector<int>>& grid2, vector<vector<int>>& vis){
        vis[row][col] = 1;  // mark as visited

        for(int i = 0; i < 4; i++){
            int r_ = row + dir[i][0];   // new row
            int c_ = col + dir[i][1];   // new col

            // Check valid Range && not yet visited & land:
            if(isValid(r_, c_) && !vis[r_][c_] && grid2[r_][c_] == 1) {
                dfsVisit(r_, c_, grid2, vis);
            }
        }
    }
    bool dfs(int row, int col, vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<int>>& vis) {
        vis[row][col] = 1;  // mark visited for grid2

        bool isValidSub = true; // flag which is used to highlight the invalid cells of sub-islands.

        // Check all possible directions: 
        for(int i = 0; i < 4; i++){
            int r_ = row + dir[i][0];   // new row
            int c_ = col + dir[i][1];   // new col

            // Check valid Range && not yet visited:
            if(isValid(r_, c_) && !vis[r_][c_]) {
                // when both are island: Check further..
                if(grid1[r_][c_] == 1 && grid2[r_][c_] == 1){
                    if(!dfs(r_, c_, grid1, grid2, vis)){    // if we got false from the parent call of DFS:
                        dfsVisit(r_, c_, grid2, vis);   // first visit all part of the grid.
                        isValidSub = false; // then mark that flag as false.
                    } 
                }
                // at anytime we encounter with condition when grid2 has island & grid1 has water, we change that flag as false.
                else if(grid1[r_][c_] == 0 && grid2[r_][c_] == 1) {   // the only condition which restrict grid2 to stop visiting further for sub-island conditions.
                    // When-ever we got the flag, we need to make sure all the part of island marked as visited & then return false:
                    dfsVisit(r_, c_, grid2, vis);   // first visit all part of the grid.
                    isValidSub = false; // then mark that flag as false.
                }
            }
        }

        return isValidSub;  // return flag.
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid2.size();
        m = grid2[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        int subIsland = 0;

        // For multiple components:
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j]){
                    if(grid1[i][j] && grid2[i][j]){
                        if(dfs(i, j, grid1, grid2, vis)){
                            subIsland++;    // if result from componenets are true, then only we can increment the island count.
                        }
                    }
                }
            }
        }


        return subIsland;
    } 
};