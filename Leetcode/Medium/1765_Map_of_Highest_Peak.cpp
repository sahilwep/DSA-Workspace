/*

//  1765. Map of Highest Peak


//  Problem Statement: 
    -> You are given an integer matrix isWater of size m x n that represents a map of land and water cells.
        -> If isWater[i][j] == 0, cell (i, j) is a land cell.
        -> If isWater[i][j] == 1, cell (i, j) is a water cell.

    -> You must assign each cell a height in a way that follows these rules:
        -> The height of each cell must be non-negative.
        -> If the cell is a water cell, its height must be 0.
        -> Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).

    -> Find an assignment of heights such that the maximum height in the matrix is maximized.
    -> Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.


// Example:

    Example 1:

        Input: isWater = [[0,1],[0,0]]
        Output: [[1,0],[2,1]]
        Explanation: The image shows the assigned heights of each cell.
        The blue cell is the water cell, and the green cells are the land cells.

    Example 2:

        Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
        Output: [[1,1,0],[0,1,1],[1,2,2]]
        Explanation: A height of 2 is the maximum possible height of any assignment.
        Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.

    




// Observation: 
    -> For water => 1
    -> For land = 0
    -> Each cell height must be non-negative & if cell is water, it's height must be '0'
    -> Any two adjacent cell must be an absolute height difference at most '1'. 


    // According to the question:
        -> Water must be '0'
        -> And the absolute difference must be '1'

        -> We will have to return new matrix which contains the height of every island & water.
            -> One thing which we are sure about is height of water: '0'
            -> & their surrounding will be of absolute difference of '1'
            -> It's better if we process every water first & then we will process the rest.
            -> We are processing every cell on by one, so we will use BFS for that.

                queue structure : <height, row, col>


// Complexity: 
    TC: O(n * m)
    SC: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Solve this using BFS
class Solution {
private:
    vector<vector<int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    // directions: (0, 0)   : left      right     up      down
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> ans(n, vector<int> (m, INT_MAX)); 
        queue<pair<int, pair<int, int>>> q;

        // Process water first:
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j] == 1){ // if we have water:
                    ans[i][j] = 0;  // overwriting the water index with '0'
                    q.push({0, {i, j}});   // pushing that water with height '0'
                }
            }
        }

        // BFS: 
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int islandH = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // Traverse all the adjacent 4 directions:
            for(int i=0;i<4;i++){
                int r_ = row + dir[i][0];
                int c_ = col + dir[i][1];

                // Check valid bound: 
                if(r_ >= 0 && r_ < n && c_ >= 0 && c_ < m){
                    if(isWater[r_][c_] == 0){   // if that element is  the land:
                        int newHeight = islandH + 1;  // this will be our new heigth of this adjacent island.
                        if(newHeight < ans[r_][c_]){    // update if new height is less than the previous once, then update it.
                            ans[r_][c_] = newHeight;    // update

                            q.push({newHeight, {r_, c_}});  // push into queue.
                        }   
                    }
                }
            }
        }

        return ans; // return ans;
    }
};