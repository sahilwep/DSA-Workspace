/*

//  3643. Flip Square Submatrix Vertically


//  Problem Statement: 
    - You are given an m x n integer matrix grid, and three integers x, y, and k.
    - The integers x and y represent the row and column indices of the top-left corner of a square submatrix and the integer k represents the size (side length) of the square submatrix.
    - Your task is to flip the submatrix by reversing the order of its rows vertically.
    - Return the updated matrix.

 

// Example:
    Example 1:
        Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], x = 1, y = 0, k = 3
        Output: [[1,2,3,4],[13,14,15,8],[9,10,11,12],[5,6,7,16]]
        Explanation: The diagram above shows the grid before and after the transformation.

    Example 2:
        Input: grid = [[3,4,2,3],[2,3,4,2]], x = 0, y = 2, k = 2
        Output: [[3,4,4,2],[2,3,2,3]]
        Explanation: The diagram above shows the grid before and after the transformation.



// Observations:
    - Given grid of dimension n * m & given x & y index & integer 'k' range
    - In range(x, y) to (x + k - 1, y + k - 1) we have to swap rows

    // Approach:
        - We will start from the given index (x, y) & go till 'k':
        - It's just we have to carefully observe the inverted index for iterating in particular row.
        - and we will iterate only half of the list, and swapped all the values...


    // Complexity:
        - TC: O(n * m)
        - SC: O(n * m)
        - AS: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {  // TC: O(n * m)
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans = grid;
        for(int i = 0; i < k / 2; i++) {
            for(int j = y; j < y + k; j++) {
                // cout << ans[i + x][j] << " " << ans[x + k - 1 - i][j] << endl;
                swap(ans[i + x][j], ans[x + k - 1 - i][j]);
            }
            cout << endl;
        }

        return ans;
    }
};