/*

//  200. Number of Islands

// Problem Statement:
    * Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
    * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


// Example:

    Example 1:
        Input: grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
        ]
        Output: 1

    Example 2:
        Input: grid = [
        ["1","1","0","0","0"],
        ["1","1","0","0","0"],
        ["0","0","1","0","0"],
        ["0","0","0","1","1"]
        ]
        Output: 3




// Visualization:

    * We are given a matrix where '1' represent island, & '0' represent water
    * We need to count the total number of island from the matrix:
        * for any island which is connected to all '4' direction, will be count as the same part of that island.

                              |        
                           -  x  -       
                              |        


    * We can use any traversal algorithm, & while checking the connected componenets, we will check in all '4' direction...


// Complexity:
    * TC: O(n*m)
    * AS: O(n*m)



*/

class Solution {
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
        grid[row][col] = 1; // mark that current node as visited
        queue<pair<int, int>> q;
        q.push({row, col});

        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
            // getting the current row & col or (node)
            int row = q.front().first;
            int col = q.front().second;
            q.pop();


            // checking in all four direction from current node & marking visited if they were not.
            /*       

                                (row-1, col)
                                     |
                (row, col-1) <- (row, col) -> (row, col+1)
                                     |
                                (row+1, col)
            
            */
            // top:
            int newRow = row - 1;
            int newCol = col;
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
            grid[newRow][newCol] == '1' && !vis[newRow][newCol]){
                q.push({newRow, newCol});   // pushing new unvisited node into queue
                vis[newRow][newCol] = 1;    // marking that node as visited
            }


            // bottom:
            newRow = row + 1;
            newCol = col;
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
            grid[newRow][newCol] == '1' && !vis[newRow][newCol]){
                q.push({newRow, newCol});   // pushing new unvisited node into queue
                vis[newRow][newCol] = 1;    // marking that node as visited
            }

            // left:
            newRow = row;
            newCol = col-1;
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
            grid[newRow][newCol] == '1' && !vis[newRow][newCol]){
                q.push({newRow, newCol});   // pushing new unvisited node into queue
                vis[newRow][newCol] = 1;    // marking that node as visited
            }

            // right:
            newRow = row;
            newCol = col+1;
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
            grid[newRow][newCol] == '1' && !vis[newRow][newCol]){
                q.push({newRow, newCol});   // pushing new unvisited node into queue
                vis[newRow][newCol] = 1;    // marking that node as visited
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0)); // visited matrix

        int island = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){    // if island is not yet visited
                    island++;   // increment island count
                    bfs(i, j, vis, grid);   // calling bfs to traverse all it's connected components
                }
            }
        }

        return island;
    }
};