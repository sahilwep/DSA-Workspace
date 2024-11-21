/*

//  2257. Count Unguarded Cells in the Grid



// Problem Statement:
    * You are given two integers m and n representing a 0-indexed m x n grid. 
    * You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

    * A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. 
    A cell is guarded if there is at least one guard that can see it.
    * Return the number of unoccupied cells that are not guarded.


// Example: 
    Example 1:
        Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
        Output: 7
        Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
        There are a total of 7 unguarded cells, so we return 7.

    Example 2:
        Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
        Output: 4
        Explanation: The unguarded cells are shown in green in the above diagram.
        There are a total of 4 unguarded cells, so we return 4.


// Visualization: 
        // Observations: 
            -> m X n => Represent 2D matrix, in which we have, guards coordinates, & walls coordinates
            -> Guards can look in all the four direction {N-S, E-W},

                            |
                          --G--
                            |

            -> We are also given wall coordinates, 
            -> Wall are used to block guard visual in certain direction in which they are facing...


        // Approach:

            // Initial Configurations:
                -> Create 2D grid of size mXn, with default unvisited value : '-1'
                -> Fill the given guards with '1'
                -> Fill the given wall with '0'

            // All we need to do is, fill the value with 'guard' in every direction until we don't hit any wall.
            
                |  1 |  0 | -1 | -1 | -1 | -1 | 
                | -1 |  1 | -1 | -1 |  0 | -1 |  
                | -1 | -1 |  0 |  1 | -1 | -1 |  
                | -1 | -1 | -1 | -1 | -1 | -1 | 
                                            m X n 
            


            -> Guards: '1', walls: '0'
                
                | [1]|  0 | -1 | -1 | -1 | -1 | 
                | -1 | [1]| -1 | -1 |  0 | -1 |  
                | -1 | -1 |  0 | [1]| -1 | -1 |  
                | -1 | -1 | -1 | -1 | -1 | -1 | 
                                            m X n 
            
            -> Select coordinates of every guards (row,col)
                -> iterate (top, down, left, right), & fill '1' at every place of '-1', until we don't hit '0'
                -> NOTE: every iteration should be in bound.

            -> Traversal: 
                    0    1    2    3    4    5
               0 | [1]|  0 | -1 | -1 | -1 | -1 | 
               1 | -1 | [1]| -1 | -1 |  0 | -1 |  
               2 | -1 | -1 |  0 | [1]| -1 | -1 |  
               3 | -1 | -1 | -1 | -1 | -1 | -1 | 
                                            m X n 

                                col
                                |
                start = [1]->(2,3)
                              | 
                              row
                            
                // Fill bottom from current starting position: 
                    for(int i=row;i<=bottom;i++){
                        if(grid[i][col] == 0) break;
                        grid[i][col] = 1;
                    }


                // Fill top from current starting position: 
                    for(int i=row;i>=0;i--){
                        if(grid[i][col] == 0) break;
                        grid[i][col] = 1;   // else guard can reach
                    }



                // Fill right from current starting position: 
                    for(int i=col;i<=right;i++){
                        if(grid[row][i] == 0) break;
                        grid[row][i] = 1;   // guard can reach
                    }

                

                // Fill left from current starting position: 
                    for(int i=col;i>=left;i--){
                        if(grid[row][i] == 0) break;   // wall check
                        grid[row][i] = 1;  // guard can reach
                    }

            

            -> This will be the final configuration, 

                | [1]|  0 | -1 | [1]| -1 | -1 | 
                | [1]| [1]| [1]| [1]|  0 | -1 |  
                | [1]| [1]|  0 | [1]| [1]| [1]|
                | [1]| [1]| -1 | [1]| -1 | -1 | 


            -> Count the number of '-1', throughout the grid.
                count = '7'


// Intrusion: 
    -> Perform initial configuration, fill walls, guards, & grid with default value '-1'
    -> Now, start from every guards coordinates & start filling the grid element in every direction until we hit any wall or out of bound to that grid.


// Complexity:
    * O(n*m)            -> filling '-1' & grid creating.
    * O(guard.size())   -> Iterating in guard to store their position in grid.
    * O(wall.size())    -> Iterating in wall to store their position in grid.
    * O(guard.size()*(n+m)))    -> Iterating in guard : & for every element we are iterating 1 grid row + 1 grid col, in worse case.
        
        * Overall TC:  O(n*m)+ O(guard.size()) + O(wall.size()) + O(guard.size()*(n+m)))



// Testcase: 
1   // testcase:
4 6 // m, n
3 3 // Guards, walls
0 0 // Guards
1 1 // Guards
2 3 // Guards
0 1 // Walls
2 2 // Walls
1 4 // Walls


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef size_t s_t;  // use during string traversal
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);
#define mod 1000000007

// Function to fill all 4th direction in grid:
void fillWithGuards(vector<vector<int> > &grid, int row, int col){
    // we have every guard coordinates, start filling in all the four direction of grind:
    // Grid Bound: we can reach up till these grid bounds.
    int top = 0;
    int bottom = grid.size()-1; // col size
    int left = 0;
    int right = grid[0].size()-1;   // row size

    // NOTE: Wall is represented by '0'

    // Fill left from current starting position: 
    for(int i=col;i>=left;i--){
        if(grid[row][i] == 0) break;   // wall check
        grid[row][i] = 1;  // guard can reach
    }


    // Fill right from current starting position: 
        for(int i=col;i<=right;i++){
            if(grid[row][i] == 0) break;
            grid[row][i] = 1;   // guard can reach
        }


    // Fill top from current starting position: 
        for(int i=row;i>=0;i--){
            if(grid[i][col] == 0) break;
            grid[i][col] = 1;   // else guard can reach
        }


    // Fill bottom from current starting position: 
        for(int i=row;i<=bottom;i++){
            if(grid[i][col] == 0) break;
            grid[i][col] = 1;
        }

}

// Function to count the number of unvisited blocks:
int countUnguarded(int m, int n, vector<vector<int> > &guard, vector<vector<int> > &walls){
    // Initial Configurations: 
    // Creation of 2D Grid.
    vector<vector<int> > grid(m, vector<int> (n, -1));  // fill all unvisited '-1'
    // fill grid guards:
    for(int i=0;i<guard.size();i++){    // coordinates (first,second) in every 'i' position
        grid[guard[i][0]][guard[i][1]] = 1;    // 1 represent guards.
    }
    // fill grid walls:
    for(int i=0;i<walls.size();i++){
        grid[walls[i][0]][walls[i][1]] = 0;     // 0 represent walls
    }


    // Intermidiate Traversal & filling all the fourth direction with guards, if we don't encounter with any walls.
    // Starting from:
    for(int i=0;i<guard.size();i++){
        fillWithGuards(grid, guard[i][0], guard[i][1]);
    }

    // last count the number of unvisited blocks by counting '-1' in grid.
    int cnt = 0;
    for(auto it: grid){
        for(auto i : it){
            if(i == -1) cnt++;
        }
    }
    
    return cnt;
}

void solve(){
    int m, n;
    cin >> m >> n;
    int g, w;
    cin >> g >> w;

    vector<vector<int> > guard(g, vector<int>());
    vector<vector<int> > walls(w, vector<int>());
    
    for(int i=0;i<g;i++){   // input of guards.
        int a, b;
        cin >> a >> b;  // input of coordinates

        guard[i].push_back(a);
        guard[i].push_back(b);
    }
    

    for(int i=0;i<w;i++){   // input of wall.
        int a, b;
        cin >> a >> b;  // input of coordinates

        walls[i].push_back(a);
        walls[i].push_back(b);
    }

    cout << countUnguarded(m, n, guard, walls);

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}