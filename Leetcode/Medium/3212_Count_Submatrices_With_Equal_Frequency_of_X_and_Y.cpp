/*

//  3212. Count Submatrices With Equal Frequency of X and Y


//  Problem Statement: 
    - Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of that contain:
        grid[0][0]
        an equal frequency of 'X' and 'Y'.
        at least one 'X'.

 
// Example:
    Example 1:
        Input: grid = [["X","Y","."],["Y",".","."]]
        Output: 3

    Example 2:
        Input: grid = [["X","X"],["X","Y"]]
        Output: 0
        Explanation: No submatrix has an equal frequency of 'X' and 'Y'.

    Example 3:
        Input: grid = [[".","."],[".","."]]
        Output: 0
        Explanation: No submatrix has at least one 'X'.


// Observations:
    - We are given grid contains "x", "y", "."
    - we have to find all the possible sub-matrix that contains equal frequency of 'x' and 'y'
    - grid[0][0] should always be included.
    - There should be atleast 1 'x' in that submatrix.


        // Approach:
            - One Thing we are sure that we have to include grid[0][0],
                - this means we have to try build all possible submatrix from (0, 0)

            - Second thing is, we have to contains 'x' and 'y' with equal frequency:
                - If we represent:
                    x = 1
                    y = -1

                        So, this way we can know:
                        If some submatrix contains 5-x and 5-y, then whole (x + y) = 0
                        or, if some submatrix contains 4-x and 5-y, then whole = -1, so we can know this grid no equal frequency.

                    '.' can be represent by '0', as it's has no effect on frequency

                    - Now from the grid: 
                        x   y   .
                        y   .   .
                    
                    - It can represented by:

                         1  -1   0
                        -1   1   0

                    - Now if we take 2D prefix sum of whole matrix:

                        1    0    0 
                        0   -1   -1 

                    - This way we can find that cell(i, j) has equal frequency:
                        
                        cell:
                            (0, 1) has equal frequency
                            (0, 2) has equal frequency
                            (1, 0) has equal frequency
            
                - Now, we need to make sure that in every '0', we atleast have one 'x',
                    - because it can be possible due to '.' we can have '0', so we can differentiate by:
                    - We can create another 2D prefix count of every 'x' appearance

                        1   1   1 
                        1   1   1 

                - Now, for every cell we can check either we have atleast one 'x' or not?


        // Complexity:
            - TC: O(n * m)
            - SC: O(n * m)
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    int n, m;
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Compute Prifix Sum & count prefix for x:
        vector<vector<int>> pref(n, vector<int> (m, 0));    // prefix sum to count the frequency, occurrence and making the sum '0'
        vector<vector<int>> cnt(n, vector<int> (m, 0));     // cnt is for counting 'x' occurrence, so that we can check the valid submatrix.

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // Compute prefix Sum:
                int val = 0;    // default as '.' = 0
                if(grid[i][j] == 'X') { // X = 1
                    val = 1;
                } else if(grid[i][j] == 'Y') {  // Y = -1
                    val = -1;
                }

                // Compute for prefix Sum for frequency:
                int left = (j > 0) ? pref[i][j - 1] : 0;                    // compute left side sum
                int top = (i > 0) ? pref[i - 1][j] : 0;                     // compute above sum
                int topLeft = (i > 0 && j > 0) ? pref[i - 1][j - 1] : 0;    // compute extra counted top_left
                pref[i][j] = left + top - topLeft + val;                    // Compute prefix: left + above - ExtraCounted_top_left + current_cell_val


                // Compute 'X' cnt:
                int x = (grid[i][j] == 'X') ? 1 : 0;
                left = (j > 0) ? cnt[i][j - 1] : 0;
                top = (i > 0) ? cnt[i - 1][j] : 0;
                topLeft = (i > 0 && j > 0) ? cnt[i - 1][j - 1] : 0;
                cnt[i][j] = top + left - topLeft + x;
            }
        }

        // Debugging:
        // for(auto &it: pref) {
        //     for(auto &i: it) cout << i << " ";
        //     cout << endl;
        // }
        // cout << endl;
        // for(auto &it: cnt) {
        //     for(auto &i: it) cout << i << " ";
        //     cout << endl;
        // }


        // Build answer:
        int matrix = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // If pref[i][j] = 0, means equal frequency of 'X' and 'Y'
                // cnt[i][j] > 0, just to check atleast one 'X'
                if(pref[i][j] == 0 && cnt[i][j] > 0) {
                    matrix++;
                }
            }
        }


        return matrix;
    }
};

