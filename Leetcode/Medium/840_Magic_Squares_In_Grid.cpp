/*

//  840. Magic Squares In Grid


//  Problem Statement: 
    - A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
    - Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?
    - Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

 
// Example:
    Example 1:
        Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
        Output: 1
        Explanation: 
            The following subgrid is a 3 x 3 magic square:
            while this one is not: In total, there is only one magic square inside the given grid.

    Example 2:
        Input: grid = [[8]]
        Output: 0



//  Observations: 
    -> Distinct number 3x3 grid filled with.
    -> number from 1 to 9, such that each row, col, and both diagonal all have the same sum.
    -> We have to check wether numbers  are in range 1 to 9 or not & they should be unique.
    -> We have to check the Horizontal & vertical sums, as they needs to be same.
    -> Last we need to check diagonal sums
    -> If all the above conditions satisfies, we can increase the finding..

    // Approach:
        - For every (row, col):
            - Try finding 3x3 matrix which follows:
                - element in range 1 to 9
                - Unique elements
                - rows Sums are equals & col sums are equal, and diagonal sums are equal
                - all the above sum should be equal.
            - Last count the magic matrix, if all the above conditions, satisfies..

    
    -> Example:
            [1,1,1,1,1]
            [1,1,1,1,1]
            [1,1,1,1,1]
            [1,1,1,1,1]
        
        => 0, because all the magic square are of same values, we need distinct numbers.

    // Complexity:
        - TC: O(n * m)
            - because for every time we only compare 3x3 which near to O(1) & sums up into => (n * m (3x3)) => (n * m * 9) => (n * m)
        - SC: O(1)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Solution:
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        for(int i = 0; i < n - 2; i++) {    // for every rows:
            for(int j = 0; j < m - 2; j++) {    // for every cols:
                // Now Try selecting 3x3 grid:
                bool isValid = true;
                
                // First Check: Unique valeus:
                unordered_set<int> st;  // used to get all the unique values:
                for(int row = i; row < i + 3; row++) {
                    for(int col = j; col < j + 3; col++) {
                        int val = grid[row][col];
                        if(val < 1 || val > 9 || st.count(val)) {  // range from 1 to 9
                            isValid = false;
                            break;
                        }
                        st.insert(grid[row][col]);
                    }
                }

                if(!isValid) continue;

                // Now Check Sums:
                // Horizontally
                vector<int> h;
                for(int row = i; row < i + 3; row++) {
                    int sum = 0;
                    for(int col = j; col < j + 3; col++) {
                        sum += grid[row][col];
                    }
                    h.push_back(sum);
                }

                // Vertically:
                vector<int> v;
                for(int col = j; col < j + 3; col++) {
                    int sum = 0;
                    for(int row = i; row < i + 3; row++) {
                        sum += grid[row][col];
                    }
                    v.push_back(sum);
                }

                // // Calculate Diagonal: Direct3x3
                // int d1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
                // int d2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];

                // Calculate 3x3 Diagonal via loop:
                int d1 = 0;
                for(int k = 0; k < 3; k++) {    // from (0, 0) to (n -1, m -1)
                    d1 += grid[i + k][j + k];
                }
                
                int d2 = 0;
                for(int k = 0; k < 3; k++) {
                    d2 += grid[i + k][j + 2 - k];   // from (0, m-1) to (n - 1, 0)
                }

                int target = v[0];  // this is our sum value:
                for(int k = 0; k < 3; k++) {
                    if(target != h[k] || target != v[k]) {  // check horizontal & vertical:
                        isValid = false;
                        break;
                    }
                }
                
                if(!isValid) continue;

                // Check diagonal sum:
                if(d1 != target || d2 != target) continue;

                // Found Magic Square:
                ans++;
            }
        }

        return ans;
    }
};