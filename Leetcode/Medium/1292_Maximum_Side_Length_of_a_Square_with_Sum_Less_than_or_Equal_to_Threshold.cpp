/*

//  1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold


//  Problem Statement: 
    - Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.


// Example:

    Example 1:
        Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
        Output: 2
        Explanation: The maximum side length of square with sum less than 4 is 2 as shown.

    Example 2:
        Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
        Output: 0


// Observations:
    - We are given grid of size n x m, and a threshold value.
    - We have to find the largest square in grid whose sum is less or equal to given threshold.
    - and we have to return the side of that square.

    // BruteForce Solution:
        - From every possible row:
            - compute the every possible square:
                - calculate their sum & if it's less or equal to the threshold, store the side of that square.
                - We need maximum side among all the squares.

            // ComplexitY:
                - TC: O(n * m * min(n, m)^3)
                - SC: O(1)
        
    // Optimizations:
        - From every possible cells, we are calculating the sum & computing them which takes approx O(n^2)
        - We can optimized this using prefix sum approach, & this will compute in constant time.

            // Grid:
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

        - Now, as we have prefix sum ready with us, we can compute the square sum in O(1) time:
        - For any two point in grid:
            - (i, j) to (r2, c2) for making possible square we can calculate the sum by:

            |*(0, 0)                                   |
            |                                          |
            |        __________                        |
            |       *(i, j)    |                       |
            |       |          |                       |
            |       |          |                       |
            |       |__________*(r2, c2)               |
            |                                          |
            |                                          |
            |                                         *|
                                                    (n - 1, m - 1)

            - We need sum from cell (i, j) to (r2, c2)
            - We can Calculate this using:
                    
                    int sum = pref[r2][c2];     => This is total sum from index(0, 0) to (r2, c2)

                    // We only need from (i, j), so remove the extra calculate sum:
                        - extra sum is in left & above from point (i, j)

                    sum -= pref[r2][j - 1];     // remove the left side sum
                    sum -= pref[i - 1][c2];     // remove the above sum

                    NOTE: as we remove this left & above we have twice remove computed the sum (i - 1, j - 1), so add that

                    sum += pref[i - 1][j - 1];  // adding left_above sums

            - NOTE while removing handel the index carefully..


        - Now We can calculate the prefix sum in O(1) constant time
        - all we need is:
            - Iterate in every cell: O(n * m):
                - Get the largest square side you can form:
                    int s = min(n - i, m - j);      // this is for making s * s side square
                    - Iterate from 1 to s:
                        - and find every sum from point (i, j) to (r2 = i + s, c2 = j + s)
                        - Compute sum.
                        - If it's less equal to threshold:
                            - store the maximum side = max(maxSide, s + 1);
                
        // Complexity:
            - This will take:
                - O(n * m) => grid iterations
                - O(min(n, m)) => for square side
                - TC: O(n * m * min(n, m))
                - SC: O(n * m)

    
    // Further Optimizations:
        - As we are linearly iterating from the point (i, j) to min(n - i, m - i) & checking sums.
        - We can do this in logarithmic time using binary search on range: (i, j) to min(n - i, m - j)
            low = 0;
            high = min(n - i, m - j);
            Compute using Binary search

        // Complexity:
            - TC: O(n * m * log(min(n, m)))
            - SC: O(n * m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Binary Search Solution:
class Solution {
private:
    int n, m;
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        n = mat.size();
        m = mat[0].size();

        // compute prefix matrix:
        vector<vector<int>> pref(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int above = (i > 0) ? pref[i - 1][j] : 0;
                int left = (j > 0) ? pref[i][j - 1] : 0;
                int topLeft = (i > 0 && j > 0) ? pref[i - 1][j - 1] : 0;
                pref[i][j] = above + left - topLeft + mat[i][j];
            }
        }

        auto sumSquare = [&](int i, int j, int r2, int c2) {
            
            // Calculate sum from the point (i, j) to (i + s, j + s)
            int sum = pref[r2][c2];  // This is total sum till the point (i + s, j + s) from point(0, 0)
            // starting point is i, j, we have to remove the sums before it.
            if(i > 0) { 
                sum -= pref[i - 1][c2];  // subtract above
            }
            if(j > 0) {
                sum -= pref[r2][j - 1];  // subtract left
            }
            if(i > 0 && j > 0) {
                sum += pref[i - 1][j - 1];  // add the remaining to compensate the sum
            }

            return sum;
        };

        // Compute squares:
        int maxSide = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int k = min(n - i, m - j);  // get the square length:

                // Using Binary search we can find the point where we have maxim sum value:
                int low = 0;
                int high = k - 1;
                while(low <= high) {
                    int mid = low + (high - low) / 2;

                    int r2 = i + mid;
                    int c2 = j + mid;
                    
                    int sum = sumSquare(i, j, r2, c2);
                    if(sum <= threshold) {
                        low = mid + 1;
                        maxSide = max(maxSide, mid + 1);
                    } else {
                        high = mid - 1;
                    }
                }
            }
        }

        return maxSide;
    }
};


// Linear Solution Solution:
class Solution {
private:
    int n, m;
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        n = mat.size();
        m = mat[0].size();

        // compute prefix matrix:
        vector<vector<int>> pref(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int above = (i > 0) ? pref[i - 1][j] : 0;
                int left = (j > 0) ? pref[i][j - 1] : 0;
                int topLeft = (i > 0 && j > 0) ? pref[i - 1][j - 1] : 0;
                pref[i][j] = above + left - topLeft + mat[i][j];
            }
        }

        auto sumSquare = [&](int i, int j, int r2, int c2) {
            
            // Calculate sum from the point (i, j) to (i + s, j + s)
            int sum = pref[r2][c2];  // This is total sum till the point (i + s, j + s) from point(0, 0)
            // starting point is i, j, we have to remove the sums before it.
            if(i > 0) { 
                sum -= pref[i - 1][c2];  // subtract above
            }
            if(j > 0) {
                sum -= pref[r2][j - 1];  // subtract left
            }
            if(i > 0 && j > 0) {
                sum += pref[i - 1][j - 1];  // add the remaining to compensate the sum
            }

            return sum;
        };

        // Compute squares:
        int maxSide = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int k = min(n - i, m - j);  // get the square length:

                // Linearly we are looking from point s = 0 to s < k
                for(int s = 0; s < k; s++) {
                    int r2 = i + s;
                    int c2 = j + s;

                    int sum = sumSquare(i, j, r2, c2);

                    if(sum <= threshold) {
                        maxSide = max(maxSide, s + 1);
                    } else {
                        break;
                    }
                }
            }
        }

        return maxSide;
    }
};

// BruteForce Solution:
class Solution {
private:
    int n, m;
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        n = mat.size();
        m = mat[0].size();

        int maxSide = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                int K = min(n - i, m - j);  // get the square length:

                // Find the every possible square & compute the sum:
                for(int k = 1; k <= K; k++) {
                    int sum = 0;
                    for(int r = 0; r < k; r++) {
                        for(int c = 0; c < k; c++) {
                            sum += mat[i + r][j + c];
                        }
                    }

                    if(sum <= threshold) {
                        maxSide = max(maxSide, k);
                    } else {
                        break;
                    }
                }
            }
        }

        return maxSide;
    }
};