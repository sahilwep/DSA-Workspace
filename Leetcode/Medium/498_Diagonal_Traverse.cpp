/*

//  498. Diagonal Traverse


//  Problem Statement: 
    -> Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 
// Example:
    Example 1:
        Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
        Output: [1,2,4,7,5,3,6,8,9]

    Example 2:
        Input: mat = [[1,2],[3,4]]
        Output: [1,2,3,4]


// Approach 1:
    -> Iterate in matrix: 
        
            -> When we have to traverse diagonally upwards in matrix: (i + j)

                    |---|---|---|---|---|---|
                    | ↗ | ↗ | ↗ | ↗ | ↗ | ↗ |
                    |---|---|---|---|---|---|
                    | / | / | / | / | / | ↗ |
                    |---|---|---|---|---|---|
                    | / | / | / | / | / | ↗ |
                    |---|---|---|---|---|---|
                    | / | / | / | / | / | ↗ |
                    |---|---|---|---|---|---|
                    | / | / | / | / | / | ↗ |
                    |---|---|---|---|---|---|


            -> When we have to traverse diagonally downwards in matrix: (i - j)

                    |---|---|---|---|---|---|
                    | \ | \ | \ | \ | \ | ↘ |
                    |---|---|---|---|---|---|
                    | \ | \ | \ | \ | \ | ↘ |
                    |---|---|---|---|---|---|
                    | \ | \ | \ | \ | \ | ↘ |
                    |---|---|---|---|---|---|
                    | \ | \ | \ | \ | \ | ↘ |
                    |---|---|---|---|---|---|
                    | ↘ | ↘ | ↘ | ↘ | ↘ | ↘ |
                    |---|---|---|---|---|---|


    -> Idea is to iterate in matrix & store the items in diagonally.
    -> Once we have the items for every diagonal lines, we can build answer, according to the given conditions..
    -> Example:
                      0   1   2  
                    |---|---|---|
                  0 | 1 | 2 | 3 |
                    |---|---|---|
                  1 | 4 | 5 | 6 |
                    |---|---|---|
                  2 | 7 | 8 | 9 |
                    |---|---|---|

                    Diagonal upwards ↗ : (i + j) 
                        Iteration in order for(0 -> n - 1) {
                                             for(0 -> m - 1) {
                                                    // logic
                                                }
                                            }


                    element     =>      index   =   key
                        x       =>      i + j   =    z
                        1       =>      0 + 0   =    0
                        2       =>      0 + 1   =    1
                        3       =>      0 + 2   =    2
                        4       =>      1 + 0   =    1
                        5       =>      1 + 1   =    2
                        6       =>      1 + 2   =    3
                        7       =>      2 + 0   =    2
                        8       =>      2 + 1   =    3
                        9       =>      2 + 2   =    4

                -> Use some vector of `map` & store elements in key order:
                    key     ->      <element>
                    0       ->      {1}
                    1       ->      {2, 4}
                    2       ->      {3, 5, 7}
                    3       ->      {6, 8}
                    4       ->      {9}

                -> Once we have these elements, we can build our answer, by reversing the list after every iterations of map:

    // Complexity: 
        -> TC: O(n * m)
        -> AS: O(n * m)



// Approach 2: 
    -> we have to diagonally iterate in matrix, & print out the result.

            [[1,2,3]
            ,[4,5,6]
            ,[7,8,9]]


            [[1,  2,  3,  4,  5]
            ,[6,  7,  8,  9,  10]
            ,[11, 12, 13, 14, 15]]

        Matrix can be of any dimensions:
            n => rows
            m => cols
            
        Stop: 
            -> reaches to (n-1 && m-1) OR {ans.size() < n * m}
        
        Use flag which denotes either we are moving upwards or downwards & also used to change directions if we reaches to directions change points: 
            -> change direction if it reaches to Directions change coordinates
            -> true = up
            -> false = down
        
        Visual representations of movements:

                                          (-2, 2)
                                         /   
                                    (-1, 1) (row-1, col+1)
                                   /
                            (0, 0) Base coordinates (row, col)
                            /  
        (row+1, col-1)(1, -1) 
                       / 
                 (2, -2)


        Directions Change:
            -> Going Up: {move to right}
                -> We can have 3 cases:
                    -> Either we hit the right wall (col == m - 1):
                        - Go down => row++
                        - change directions
                    -> Or we hit top wall (row == 0):
                        - move right => col++
                        - change directions
                    -> Else, we are in b/w the path:
                        - go upwards-right => row-- && col++
                        - no need to change directions


            -> Going Down: {move to left}
                -> We can have 3 cases:
                    -> Either we hit the down wall (row == n - 1):
                        - go right => col++
                        - change directions
                    -> Or we hit the left wall (col == 0):
                        - move down => row+1
                        - Change directions
                    -> Else, we are in b/w the path:
                        -> go downwards-left => row++ && col--
                        -> no need to change directions


    // Complexity: 
        -> TC: O(n * m)
        -> AS: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Approach 2:
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> ans;
        int row = 0, col = 0;
        bool up = true;

        while(ans.size() < n * m) {
            ans.push_back(mat[row][col]);
            
            if(up) {  // going up
                // move up right:
                if(col == m - 1) {      // hit right wall -> move down & change directions
                    row++;
                    up = false;
                } else if(row == 0) {   // hit top wall -> move right & change directions
                    col++;
                    up = false;
                } else {                // in b/w the path -> just move upwards, no need to change directions
                    row--;
                    col++;
                }
            } else {    // go down
                // move down-left:
                if(row == n - 1) {      // hit the bottom wall -> move right & change directions
                    col++;
                    up = true;
                } else if(col == 0) {   // hit the left wall -> move down & change directions
                    row++;
                    up = true;
                } else {                // in b/w the path -> just move downwards, no need to change directions..
                    row++;
                    col--;
                }
            }
        }

        return ans; // return answer
    }
};



// Approach 1: Using Map & diagonal Iterations logic
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        map<int, vector<int>> mp;
        // Fill map using (i + j);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        // Traverse in map & build answer:
        vector<int> ans;
        bool flip = true;   // we will flip for every iterations
        for(auto &[key, val]: mp) {
            if(flip) {
                reverse(begin(val), end(val));
                for(auto& i: val) {
                    ans.push_back(i);
                }
                flip = !flip;
            } else {
                for(auto& i: val) {
                    ans.push_back(i);
                }
                flip = !flip;
            }
        }

        return ans;
    }
};
