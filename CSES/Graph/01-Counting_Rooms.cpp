/*

//  CSES: Counting Rooms

//  Problem Statement: 
    -> You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n-times m squares, and each square is either floor or wall. 
    You can walk left, right, up, and down through the floor squares.

// Input
    -> The first input line has two integers n and m: the height and width of the map.
    -> Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).

// Output
    -> Print one integer: the number of rooms.

// Constraints: (1 <= n , m <= 1000)

// Example
    Input:
        5 8
        ########
        #..#...#
        ####.#.#
        #..#...#
        ########

    Output: 3

// Observations:
    -> we will use any traversal algorithm to traverse & find the number of rooms.

// Complexity:
    -> TC: O(n * m)
    -> SC: O(n * m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
    int n, m;
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }
private:
    void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<int>> &vis) {
        vis[row][col] = 1;

        for(int i = 0; i < 4; i++) {
            int r = row + dir[i][0];
            int c = col + dir[i][1];

            if(isValid(r, c) && !vis[r][c] && grid[r][c] == '.') {
                dfs(r, c, grid, vis);
            }
        }
    }
public:
    int countRooms(vector<vector<char>> &grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));

        int rooms = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == '.') {
                    dfs(i, j, grid, vis);
                    rooms++;
                }
            }
        }

        return rooms;
    }
};



// Driver Functions: 
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char> (m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    
    cout << obj.countRooms(grid) << endl;   
}

int main(){
    int t = 1;     // Change the testcase according to question...
    // cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}