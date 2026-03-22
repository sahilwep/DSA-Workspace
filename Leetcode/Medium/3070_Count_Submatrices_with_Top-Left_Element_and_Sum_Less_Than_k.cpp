/*

//  3070. Count Submatrices with Top-Left Element and Sum Less Than k



//  Problem Statement: 
    - You are given a 0-indexed integer matrix grid and an integer k.
    - Return the number of that contain the top-left element of the grid, and have a sum less than or equal to k.

 

// Example:
    Example 1:
        Input: grid = [[7,6,3],[6,6,1]], k = 18
        Output: 4
        Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.

    Example 2:
        Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
        Output: 6
        Explanation: There are only 6 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 20.


// Observations:
    - Given grid of size n * m, and integer 'k'
    - We need to find the all the submatrix from (0,0) to (i, j) sum that is less than equal 'k'
        - we will count that submatrix.

    // BruteForce Solution:
        - For every index (i, j):
            - compute sum from (0, 0) to (i, j)

        - This will take O(n * m) for every cell O(n * m) => O(n^2 * m^2)

        // Complexity:
            - TC: O(n^2 * m^2)
            - SC: O(1)

    // Efficient Solution:
        - From every index (i, j), we required sum from (0, 0):
            - If we somehow compute the sum from (0, 0) to every index, then we can fetch the sum in O(1)
            - Prefix sum will help us in that case:
            - We are working in 2D grid, so we need to build prefix Sum for 2D grid:

            // Example Grid:

                [1,1,3,2,4,3,2]
                [1,1,3,2,4,3,2]
                [1,1,3,2,4,3,2]

                - For every cells prefix grid is:

                         0 1 2  3  4 5 6          
                      0 [1 1 3  2  4 3 2]
                      1 [1 1 3 [2] 4 3 2]
                      2 [1 1 3  2  4 3 2]

                    for cell(1, 3) = '2'
                    prefix sum is summations of these elements:

                            1 1 3  2
                            1 1 3 [2]

                                            1 + 1 + 3 + 2 + 1 + 1 + 3 + 2 = 14
                            
                        for this (1, 3):
                            - we are taking above sums(0, 3)
                                    
                                        1 1 3 2

                            - we are taking previous sum(1, 2)

                                        1 1 3
                                        1 1 3

                            - This {1 1 3} being computed twice:
                                - This is nothing but (i - 1, j - 1) => (0, 2)
                    - In simple:
                        - while building prefix sum:
                            - add above value  += pref[i - 1][j];
                            - add prev value   += pref[i][j - 1];
                            - subtract overcounted value -= pref[i - 1][j - 1];
                            - Add current cell value which you are in: mat[i][j]
                        - and that how we can make the whole prefix sum 2D grid.
                                
                            
                    // pref-Grid:
                        1 2 5 7 11 14 16 
                        2 4 10 14 22 28 32 
                        3 6 15 21 33 42 48 

        // Complexity:
            - TC: O(n * m)
            - SC: O(n * m)


        
// Extra:
    - Problem:  1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
    - Ref: https://github.com/sahilwep/DSA-Workspace/blob/main/Leetcode/Medium/1292_Maximum_Side_Length_of_a_Square_with_Sum_Less_than_or_Equal_to_Threshold.cpp

    
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// 2D-Prefix Solution:
class Solution {
private:
    int n, m;
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {    // O(n^2 * m^2)
        n = grid.size();
        m = grid[0].size();

        // Make Prefix sum of 2D Grid & get sum for every index every time:
        vector<vector<int>> pref(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                // For every cell get the left, above & above_left value
                int left = (j > 0) ? pref[i][j - 1] : 0;
                int above = (i > 0) ? pref[i - 1][j] : 0;
                int aboveLeft = (i > 0 && j > 0) ? pref[i - 1][j - 1] : 0;

                pref[i][j] = left + above - aboveLeft + grid[i][j];
            }
        }


        // Compute the total number of grid:
        int subMat = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // Calculate sum till (i, j) from (0, 0):
                int sum = pref[i][j];

                if(sum <= k) subMat++;
            }
        }

        return subMat;
    }
};


// BruteForce Solution:
class Solution {
private:
    int n, m;
    int getSum(vector<vector<int>>& grid, int n, int m) {
        int sum = 0;

        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                sum += grid[i][j];
            }
        }

        return sum;
    }
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {    // O(n^2 * m^2)
        n = grid.size();
        m = grid[0].size();

        int subMat = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // Calculate sum till (i, j) from (0, 0):
                int sum = getSum(grid, i, j);

                // cout << sum << " " << i << ", " << j << endl;

                if(sum <= k) subMat++;
            }
        }

        return subMat;
    }
};