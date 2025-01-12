/*

//  3417. Zigzag Grid Traversal With Skip


//  Problem Statement:
    -> You are given an m x n 2D array grid of positive integers.
    -> Your task is to traverse grid in a zigzag pattern while skipping every alternate cell.
    -> Zigzag pattern traversal is defined as following the below actions:
        -> Start at the top-left cell (0, 0).
        -> Move right within a row until the end of the row is reached.
        -> Drop down to the next row, then traverse left until the beginning of the row is reached.
        -> Continue alternating between right and left traversal until every row has been traversed.

    -> Note that you must skip every alternate cell during the traversal.
    -> Return an array of integers result containing, in order, the value of the cells visited during the zigzag traversal with skips.

 
// Example:

    Example 1:
        Input: grid = [[1,2],[3,4]]
        Output: [1,4]

    Example 2:
        Input: grid = [[2,1],[2,1],[2,1]]
        Output: [2,1,2]

    Example 3:
        Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
        Output: [1,3,5,7,9]


    Example 4: 
        [1,2,1,3]
        [5,15,7,3]
        [10,4,14,12]

     Output: 1 1 15 3

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> res;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i % 2 == 0){     // for even row:
                    if(j % 2 == 0){ // place in even places:
                        res.push_back(grid[i][j]);
                    }
                }
                else{   // for odd Row: 
                    if(m % 2 == 0){ // check size & if size is even then,
                        if(j % 2 == 0){ // place element at even place only
                            res.push_back(grid[i][m-j-1]);
                        }
                    }else{  // when size is odd:
                        if(j % 2 != 0){ // place element at ode places only.
                            res.push_back(grid[i][m-j-1]);
                        }
                    }
                }
            }
        }

        return res;
    }
};