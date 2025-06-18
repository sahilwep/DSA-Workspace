/*

//  59. Spiral Matrix II


//  Problem Statement: 
    -> Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
 
// Example: 
    Example 1:
        Input: n = 3
        Output: [[1,2,3],[8,9,4],[7,6,5]]

    Example 2:
        Input: n = 1
        Output: [[1]]

 

// Intrusion: 
    // We will use 4 pointer to iterate the matrix in spiral form:
        * left <--> right pointer
        * top <--> bottom pointer

                       left                     right
                    
               Idx--    0       1       2       3
                |
        top     0       1       2       3       4
                        
                1       5       6       7       8
                        
                2       9       10      11      12
                        
        bottom  3       13      14      15      16


            * Spiral print like: 
                    left -> right
                    top  -> bottom
                    right -> left
                    bottom -> top
                        ==> this will continue going until all the elements are not printed.

            * First Spiral:

                * First, we will print: left to right:
                        for(i = left -> right)
                            print(a[top][i])       -> here, top is fixed

                * Second, we will print top to right:
                        top++   // because we have already printed the last element in upper iterations, so we need to skip first top element i.e '3' in this case. 
                        for(i = top -> bottom)
                            print(a[i][right])  -> here, right is fixed
                    
                * Third, we will print right -> left:
                        right-- // because we need to skip the last printed element in upper iterations.
                        for(i = right -> left)
                            print(a[bottom][i]) -> here, bottom is fixed
                    
                * Fourth, we will print bottom -> top:
                        bottom--    // as we need to start printing just above the previous printed element, so that element position is in bottom.
                        for(i = bottom -> top)
                            print(a[][left])    -> here left is fixed

                        left++  -> because for next spiral start from left, so we need to move left...

            * This all the condition executes until:
                * All the element is not printed:
                    left <= right
                    top <= bottom
            

            * Edge Case: When we have only one row.
                * for single row matrix: i.e a[1][3]:
                    I/p:   
                        [1   2   3]   
                    O/p:
                        1 2 3 2 1
                    * Explanation: 
                        * from the above logic, first we will print the (left -> right)
                        * then top is increased so the (top -> bottom) will not be printed, as this condition will not be executed because {(top <= bottom), & top = bottom = 1, so when top++ => top = 2, & condition hit}.
                        * then we are printing (left -> right), But here we are not checking whether our top is in the bound of bottom or not, it will print again, so we need to fix this by using check if(top <= bottom).
                        * the for (bottom -> top), we need to check (left <= bottom)

                * Fix: we need to take care of the case: 
                    if(top <= bottom): Then only goes in right to left in matrix: 
                    if(left <= right): Then only goes in bottom to top in matrix
                  

    * TC: O(n*m)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> mat(n, vector<int> (n, 0));

        // Making 4 pointers:
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;

        int x = 1;
        while(left <= right && top <= bottom) {
            // Top left to top right:
            for(int i = left; i <= right; i++) {
                mat[top][i] = x++;
            }
            top++;  // moving top pointer down

            // Top right to bottom right:
            for(int i = top; i <= bottom; i++) {
                mat[i][right] = x++;
            }
            right--;    // moving right to left side, as we have occupied it.

            // Right -> Left:
            // bottom right to bottom left:
            // Edge case: This conditions make sure if top is less or equal to bottom, then only the loop will execute, in case of single row, when it's printed, & top will increased, it will make sure that this will not print..
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    mat[bottom][i] = x++;
                }
                bottom--;   // move bottom to up
            }

            // Bottom -> Top:
            // Edge case: This Condition will make sure when we have only one element in our row; as right is already 0, & with right-- -> it goes to -1, so this condition will restrict it to get executed..
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    mat[i][left] = x++;
                }
                left++;
            }
        
        }
        
        return mat;
    }
};