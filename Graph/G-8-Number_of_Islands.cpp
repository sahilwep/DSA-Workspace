/*


//  Number of Islands:

// Problem Statement:
    * Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). 
    * Find the number of islands.

    * Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.



// Visualization:

    * We are given a matrix where '1' represent island, & '0' represent water
    * We need to count the total number of island from the matrix:
        * for any island which is connected to all '8' direction, will be count as the same part of that island.

                            \ | /      
                           -  x  -       
                            / | \        

             // Instead of Checking all the direction individually, we can use loop for row & col & check:
                
                    // For left to right: (-1, 0, +1) -> COL
                           (-1)  (0)   (+1)
                             \   |    /      
                           (-1)- x(0) -(+1)
                             /   |    \       
                           (-1)  (0)   (+1)
        
                    // For top to down: (-1, 0, +1) -> ROW
                           (-1)  (-1)   (-1)
                             \   |    /      
                           (0)- x(0) -(0)
                             /   |    \       
                           (+1)  (+1)   (+1)
            
                    for(delRow = -1; delRow <= +1; delRow++){
                        for(delCol = -1; delCol <= +1; delCol++){
                            ... conditions...
                        }
                    }
  

    * We can use any traversal algorithm, & while checking the connected componenets, we will check in all '8' direction...


// Complexity:
    * TC: O(n*m)
    * AS: O(n*m)

// Testcase:
1
4 2
0 1
1 0
1 1
1 0

*/

#include<bits/stdc++.h>
using namespace std;

void bfs(int row, int col, vector<vector<int> > &vis, vector<vector<char> > &grid){
    vis[row][col] = 1;          // mark that current node as visited
    queue<pair<int, int> > q;   // data structure to store row & col in queue
    q.push({row, col});         // push the first row & col

    int n = grid.size();
    int m = grid[0].size();
    

    while(!q.empty()){
        // getting the current row & col or (node)
        int row = q.front().first;
        int col = q.front().second;
        q.pop();    // removing that front node from queue.

        // traversing all the 8 direction of current node & marking visited if they were not.
        for(int delRow = -1; delRow <= 1; delRow++){
            for(int delCol = -1; delCol <= 1; delCol++){
                int newRow = row + delRow;  // new row
                int newCol = col + delCol;  // new col
                // checking for valid conditions: (in-range, should be island, not-visited)
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                grid[newRow][newCol] == '1' && !vis[newRow][newCol]){
                    q.push({newRow, newCol});   // pushing new unvisited node into queue
                    vis[newRow][newCol] = 1;    // marking that node as visited
                }
            }
        }
    }
}

int numIslands(vector<vector<char> >& grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int> > vis(n, vector<int> (m, 0)); // visited matrix

    int island = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j] == '1'){    // if island is not yet visited, & it should be island
                island++;   // increment island count
                bfs(i, j, vis, grid);   // calling bfs to traverse all it's connected components
            }
        }
    }

    return island;
}


int main(){
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char> > grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        cout << numIslands(grid) << '\n';
    }

    return 0;
}