/*

//  1351. Count Negative Numbers in a Sorted Matrix


//  Problem Statement: 
    -> Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.
 

// Example: 
    Example 1:
        Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
        Output: 8
        Explanation: There are 8 negatives number in the matrix.

    Example 2:
        Input: grid = [[3,2],[1,0]]
        Output: 0

//  Observations: 
    -> Iterate in row
        -> for every row, try finding the last positive index
        -> Count the negative values & build answer.


        [4,   3,  2, -1]
        [3,   2,  1, -1]
        [1,   1, -1, -2]
        [-1, -1, -2, -3]


// Complexity:
    -> TC: O(N * log(M))
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int neg = 0;

        for(int i = 0; i < n; i++) {    // TC: O(n * log(m))
            // find negative in range (0...m-1)
            int low = 0;
            int high = m - 1;
            int ans = -1;
            while(low <= high) {
                int mid = (low + high) / 2;

                if(grid[i][mid] >= 0) {  // found +ve
                    low = mid + 1;
                    // cout << grid[i][mid] << " " << mid << endl;
                    ans = mid;
                } else {
                    high = mid - 1;
                }
            }

            if(ans != -1) {
                neg +=  m - ans - 1;   // count negative numbers
            } else {
                neg += m;
            }
        }
        
        return neg;
    }
};