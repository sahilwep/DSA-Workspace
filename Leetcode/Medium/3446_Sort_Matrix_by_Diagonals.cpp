/*

//  3446. Sort Matrix by Diagonals



//  Problem Statement: 
    -> You are given an n x n square matrix of integers grid. Return the matrix such that:
    -> The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
    -> The diagonals in the top-right triangle are sorted in non-decreasing order.



// Example:
    Example 1:
        Input: grid = [[1,7,3],[9,8,2],[4,5,6]]
        Output: [[8,2,3],[9,6,7],[4,5,1]]
        Explanation:
            The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:
                [1, 8, 6] becomes [8, 6, 1].
                [9, 5] and [4] remain unchanged.
            The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:
                [7, 2] becomes [2, 7].
                [3] remains unchanged.


    Example 2:
        Input: grid = [[0,1],[1,2]]
        Output: [[2,1],[1,0]]
        Explanation: The diagonals with a black arrow must be non-increasing, so [0, 2] is changed to [2, 0]. The other diagonals are already in the correct order.


    Example 3:
        Input: grid = [[1]]
        Output: [[1]]
        Explanation: Diagonals with exactly one element are already in order, so no changes are needed.

    
// Observations: 
    -> Matrix diagonal traversal: j - i

          0   1   2
        |---|---|---|
      0 | \ | \ | ↘ |
        |---|---|---|
      1 | \ | \ | ↘ |
        |---|---|---|
      2 | ↘ | ↘ | ↘ |
        |---|---|---|


          0   1   2
        |---|---|---|
      0 | 0 | 1 | 2 |
        |---|---|---|
      1 |-1 | 0 | 1 |
        |---|---|---|
      2 |-2 |-1 | 0 |
        |---|---|---|

    // Observations & approach: 
        -> Diagonal & it's down sorted in decreasing order
        -> Diagonal up sorted in increasing order
        -> First Collect the elements in map
        -> (key > 0) sort them in increasing order
        -> (key <= 0) sort them in decreasing order
            -> BUT: 
                -> (key > 0) sort them in descending order, because we will fetch using stl::vec.back() function
                -> (key <= 0) sort them in ascending order, because we will fetch using stl::vec.back() function


    // Complexity: 
        -> TC: O(n * m)
            -> Sorting will take: (n * logn), because at max length is diagonal, & it's n
            -> Overall iterations will take (n * n)
        -> SC: O(n * n)
        

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Store all the elements into map:
        unordered_map<int, vector<int>> mp; // key: <elements>
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mp[j - i].push_back(grid[i][j]);
            }
        }


        // Now Sort them according to our observations:
        for(auto& [key, val]: mp) {
            if(key <= 0) {  // diagonal & it's downwards:
                sort(begin(val), end(val));   // sort in ascending order
            } else {
                sort(rbegin(val), rend(val)); // sort in descending order
            }
        }
        
        // Initialize the elements:
        vector<vector<int>> ans(n, vector<int> (n, 0)); // Using extra space, because we don't want to play with given input.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans[i][j] = mp[j - i].back();
                mp[j - i].pop_back();
            }
        }

        return ans;
    }
};