/*

//  G-10. Rotten Oranges



// Problem Statement: 
    * You are given an m x n grid where each cell can have one of three values:
        0 representing an empty cell,
        1 representing a fresh orange, or
        2 representing a rotten orange.

    * Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
    * Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
    * If this is impossible, return -1.



// Example:

    Example 1:
        Input: grid = [[2,1,1]
                      ,[1,1,0]
                      ,[0,1,1]]
        Output: 4


    Example 2:
        Input: grid = [[2,1,1]
                      ,[0,1,1]
                      ,[1,0,1]]
        Output: -1
        Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.


    Example 3:
        Input: grid = [[0,2]]
        Output: 0
        Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

    


// Observation:
    0 => empty cell
    1 => fresh orange
    2 => rotten orange

    -> we need to check whether it' possible to rotten all the fresh orange in minimum second.
    -> If it's possible, then we can mark all fresh orange to rotten and we will return that minimum time, else we will return '-1'
    -> from any given nodes we can move in all 4 direction(up, down, left, right)
    
    -> For moving nodes one by one, it's better to use BFS -> Level wise traversal.
    
    -> We need to start filling all the fresh orange of rotten neighbour at the same time.
        -> means, initially we need to get all the location of rotten oranges..

    -> Then we start iterate all the rotten neighbors at the same time.


// Complexity:
    * TC: O(n*m) 
    * AS: O(n*m)

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Step 1: Getting all the rotten oranges location & pushed into queue:
        //         DS: <<row, col>, time>
        queue<pair<pair<int, int>, int>> q;

        int vis[n][m];      // visited array
        int cntFresh = 0;   // variable to count the number of fresh oranges
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 2){
                    q.push({{i, j}, 0});    // push element into queue, with initial sec = 0
                    vis[i][j] = 2;          // mark in visited matrix also
                }else{
                    vis[i][j] = 0;          // else mark all with '0'
                }
                if(mat[i][j] == 1){         // count the fresh oranges:
                    cntFresh++;
                }
            }
        }
        
        // Step 2: fill the neighbour by marking them, & pushing their neighbors into queue.
        // possible 4 direction where we have to check:
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        int tm = 0;     // variable to handel time
        int cnt = 0;    // to handel leftover oranges.
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            
            tm = max(tm, t);    // getting maximum time.
            q.pop();            // removing front element from queue
            
            // now check possible 4 direction:
            for(int i=0;i<4;i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && 
                vis[nRow][nCol] == 0 && mat[nRow][nCol] == 1 ){
                    q.push({{nRow, nCol}, t + 1});
                    vis[nRow][nCol] = 2;    // mark it as rotten
                    cnt++;  // count the number of pushed oranges
                }
            }
        }
        
        // Last check for leftover oranges:
        if(cntFresh != cnt){
            return -1;
        }
        
        return tm;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends