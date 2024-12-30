
/*

// 694. Number of Distinct Islands


//  Problem Statement:
    -> Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).


// Example:
    Example 1:
        Input:
            grid[][] = {{1, 1, 0, 0, 0},
                        {1, 1, 0, 0, 0},
                        {0, 0, 0, 1, 1},
                        {0, 0, 0, 1, 1}}
        Output: 1

        Explanation:
            grid[][] = {{1, 1, 0, 0, 0}, 
                        {1, 1, 0, 0, 0}, 
                        {0, 0, 0, 1, 1}, 
                        {0, 0, 0, 1, 1}}
        Same colored islands are equal.
        We have 2 equal islands, so we 
        have only 1 distinct island.

    Example 2:
        Input:
            grid[][] = {{1, 1, 0, 1, 1},
                        {1, 0, 0, 0, 0},
                        {0, 0, 0, 0, 1},
                        {1, 1, 0, 1, 1}}
        Output: 3

        Explanation:
            grid[][] = {{1, 1, 0, 1, 1}, 
                        {1, 0, 0, 0, 0}, 
                        {0, 0, 0, 0, 1}, 
                        {1, 1, 0, 1, 1}}
        Same colored islands are equal.
        We have 4 islands, but 2 of them
        are equal, So we have 3 distinct islands.






// Observations:
    -> We need to find the number of distinct island
    -> two island is considered to be distinct, if and only if one island is equal to other, not(rotated or reflected)
    -> Somehow we need to find the number of island which are not same, if we can store the shape of every island then or jub is done.
    -> How we can store the shape of island:
        
        Example:
        
            1 1 0 0 0
            1 0 0 0 0
            0 0 0 1 1
            0 0 0 1 0
            
            -> We have two island.
            -> but, how we can store shape.
        
        -> We can use data-structure like set => which store only unique elements.
        -> But how we can store the shape of island, if we can figure the way to store shape, our job is done.
            
            Let's write the index of grid:
            
                          0 1 2 3 4
                        0 1 1 0 0 0
                        1 1 0 0 0 0
                        2 0 0 0 1 1
                        3 0 0 0 1 0
                    
                    
                        -> Now write all the index of all the shapes:
                            
                            1st
                                1(0, 0)     1(0, 1)
                                
                                1(1, 0)
                        
                            2nd
                                1(2, 3)     1(2, 4)
                                
                                1(3, 3)
                                
                        -> We can say
                        
                                {(0, 0) (0, 1) (1, 0)} -> Something in this directions store a vector or a list.    --- List I
                                
                                {(2, 3) (2, 4) (3, 3)} -> If we store this, they will not match                     --- List II
                            
                        -> How we can store these so that they will match.
                        
                                we have started from (0, 0) & goes to (0, 1), 
                                then we have started from (0, 0) & goes to (1, 0)
                                
                            -> we can say (0, 0) is our base.
                                
                                similarly for other one,
                                
                            -> we can say (2, 3) is our base.
                            
                                So, whatever is the base: if we do
                                    node   -  base  = new_value
                                    (2, 3) - (2, 3) = (0, 0)
                                    (2, 4) - (2, 3) = (0, 1)
                                    (3, 2) - (2, 3) = (1, 0)
                                        
                                    Now, if we write this in a list, they will come out to be:
                                        {(0, 0) (0, 1) (1, 0)}
                                
                                
                                Similarly if we check for list I, base = (0, 0)
                                    
                                    (0, 0) - (0, 0) = (0, 0)
                                    (0, 1) - (0, 0) = (0, 1)
                                    (1, 0) - (0, 0) = (1, 0)
                                    
                                    Now if we write in a list, they will be come out to be the same.
                                        {(0, 0) (0, 1) (1, 0)}  -> This list is same as list I.

                        -> Now we can use bfs/dfs and visit all the parts of island
                        
                                
                        NOTE: what if we are given island something like this:
                                
                                    1 1 1 1 1 1
                                    1 1 1 1 0 0
                                    1 1 1 0 0 0
                                    1 1 0 0 0 0
                                    1 0 0 0 0 0
                                    
                                
                                make sure to follow same order to visit every part of the grid:
                                
                                just make sure to follow an order -> If we are first going right, then down, then left then up
                                make sure to follow this order for everyone.
                                    
                                          |
                                        - * - 
                                          |
                                
                                If we are following particular traversal DFS, follow it throughout.
                                So, that the list ordering stays same for everyone.
                    
                    
                            Conclusion:
                                follow the same order to traverse for everyone.
                                subtract the base address to get the list & store in set
                                last return the sizeof set.


                        // Rest of the logic is same as number of island


// Complexity:
    * TC: O(n * m * log (set length) + (n * m))
        -> O(n * m log u), u = number of unique island shapes.
    * SC: O(n x m)


*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &vec, int row0, int col0){
        vis[row][col] = 1;                          // mark that current node as visited
        vec.push_back({row - row0, col - col0});    // store the result in vec by subtracting the current coordinates with base coordinates.
        
        int n = grid.size();
        int m = grid[0].size();
        
        // all 4 directions:
        int delRow[] = {-1, +1, 0, 0};
        int delCol[] = {0, 0, -1, +1};
        
        // check in all 4 directions:
        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            // check bound range, weather they are island & they were not visited yet.
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && !vis[nRow][nCol]){
                dfs(nRow, nCol, grid, vis, vec, row0, col0);
            }
        }
    }
public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0)); // visited array.
        set<vector<pair<int, int>>> st;                 // set of vector to store the shape of islands.
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    int row0 = i;                           // base coordinates
                    int col0 = j;                           // base coordinates
                    vector<pair<int, int>> vec;             // create a vector, to store the shape
                    dfs(i, j, grid, vis, vec, row0, col0);  // cal dfs
                    st.insert(vec);                         // last store that vec into set.
                }
            }
        }
        
        return st.size();   // last return the size of set
    }
};


int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
    cout << "~" << "\n";
}
}