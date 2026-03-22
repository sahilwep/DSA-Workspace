/*

//  1727. Largest Submatrix With Rearrangements


//  Problem Statement: 
    - You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
    - Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.

 
// Example:
    Example 1:
        Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
        Output: 4
        Explanation: You can rearrange the columns as shown above.
        The largest submatrix of 1s, in bold, has an area of 4.

    Example 2:
        Input: matrix = [[1,0,1,0,1]]
        Output: 3
        Explanation: You can rearrange the columns as shown above.
        The largest submatrix of 1s, in bold, has an area of 3.

    Example 3:
        Input: matrix = [[1,1,0],[1,0,1]]
        Output: 2
        Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.


// Observations:
    - Given matrix of dimensions n * m
    - We are allowed to rearrange column of matrix in any order.
    - we will have to return the largest sub-matrix within where every element of submatrix is 1 after reordering the columns optimally.


    // Approach:
        - If we carefully observe, we an swap the columns,
        - and if we count every consecutive 1's from rows & observe carefully, then we can easily found how we can approach this problem.
        - Let's observe this using examples:

    - Example:
            0 0 1
            1 1 1
            1 0 1

        - If we make counts of ever 1's by columns wise:

            0 0 1
            1 1 2
            2 0 3

        - If we sort them in decreasing order.
            
            1 0 0
            2 1 1
            3 2 0

        - For every row if se sort them, 
        - above of them from current col 1's freq will not change.
        - because it's counting is starting from the above top 1's finding.

            1 0 0
            Here, above the 1's there's is nothing

            2 1 0
            Here, above the two there is single 1's which makes it '2'

            3 2 0
            Here above the 3 there is two 1's which makes it '3'


        - Now for every row: 
            - we will enumerate and find the largest sub-matrix:

        // Another example:

            0 0 1 0 
            1 1 1 1 
            1 0 1 1

            After counting:

                0 0 1 0 
                1 1 2 1 
                2 0 3 2 

            After sorting:

                1 0 0 0 
                2 1 1 1 
                3 2 2 0 

            largest submatrix: 2 * 3 = 6
                
            For this row: 3 2 2 0 

                    for the index 2 - we have '2' as height
                        height = 2, because it's current minimum as we already sorted.
                        base = 3, because we have consecutive non-zero values.

                        mat = 3 * 2

                    whenever it's '0', we have to reset base to '1'
                    
    
        - So, logically after sorting we swap the cols, not rows.
        - We are not caring what's below the current row as of now.
        - and this way, we can easily calculate the largest sub-matrix.


        // Complexity:
            - TC: O(n * (m + m*logm))
            - SC: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;



// Using less space:
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Find the largest matrix:  
        int largest = 0;
        vector<int> grid(m, 0);
        for(int i = 0; i < n; i++) {    // get every row
            // First calculate the above 1's:
            if(i > 0) { // we will skip 1's row:
                for(int j = 0; j < m; j++) {
                    if(matrix[i][j] == 1 && matrix[i - 1][j] >= 1) {    // curr is '1', previous is already computed
                        matrix[i][j] += matrix[i - 1][j];
                    }
                }
            }


            // Put the 1's count of matrix int grid:
            for(int j = 0; j < m; j++) grid[j] = matrix[i][j];

            sort(rbegin(grid), rend(grid)); // sort them in descending order      O(m * logm)

            // Find largest sub-Matrix:
            int base = 1;
            for(int j = 0; j < m; j++) {
                if(grid[j] == 0) {   // whenever it's 0: break
                    break;      // because values are sorted, there's is no further values to be found.
                } else {
                    int matSize = grid[j] * base;       // as values is sorted means previous all the values are grater.
                    largest = max(largest, matSize);    // store the largest matrix.

                    base++; // increase base
                }
            }
        }

        return largest;
    }
};


// Using auxilary space:
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // First build 1's count matrix column wise:        TC: O(n * m)
        vector<vector<int>> grid(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++) grid[0][i] = matrix[0][i];   // fill the first row

        for(int i = 0; i < m; i++) {    // fill the rest:
            for(int j = 1; j < n; j++) {
                if(matrix[j][i] == 1) {
                    grid[j][i] = grid[j - 1][i] + 1;
                }
            }
        }
        
        // Find the largest matrix:  // TC: O(n * (m*logm))
        int largest = 0;
        for(int i = 0; i < n; i++) {    // get every row
            sort(rbegin(grid[i]), rend(grid[i])); // sort them in descending order      O(m * logm)

            // Find largest sub-Matrix:
            int base = 1;
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {   // whenever it's 0: break
                    break;      // because values are sorted, there's is no further values to be found.
                } else {
                    int matSize = grid[i][j] * base;    // as values is sorted means previous all the values are grater.
                    largest = max(largest, matSize);    // store the largest matrix.

                    base++; // increase base
                }
            }
        }

        return largest;
    }
};