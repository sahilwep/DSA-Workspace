/*

//  Spirally traversing a matrix

//  Observations: 
    * We are given a rectangular matrix, and we need to print it in spiral form.

// Example:


    Input: matrix[][] = [[1, 2, 3, 4],
                        [5, 6, 7, 8],
                        [9, 10, 11, 12],
                        [13, 14, 15,16]]
    Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
    Explanation: 
            * Iterate in spiral manner
                        [1,  2,  3,  4]
                        [5,  6,  7,  8]
                        [9, 10, 11, 12]
                        [13, 14, 15,16]



    Input: matrix[][] = [[1, 2, 3, 4],
                        [5, 6, 7, 8],
                        [9, 10, 11, 12]]
    Output: [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
    Explanation: Applying same technique as shown above, output for the 2nd testcase will be 1 2 3 4 8 12 11 10 9 5 6 7.



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
                        * the for (bottom -> top), this condition will check properly.

                * Fix: we need to take care of the case: if(top <= bottom):  Then only goes in right to left matrix:  
                  


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC: O(n*m)
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {

        vector<int> v;

        int n = matrix.size();  // rows
        int m = matrix[0].size();   // cols

        // Making four pointers:
        int left = 0, right = m-1;
        int top = 0, bottom = n-1;


        while(left <= right && top <= bottom){
            // Left -> Right:
            for(int i=left;i<=right;i++){
                v.push_back(matrix[top][i]);
            }
            top++;      // moving top to down

            // Top -> Bottom:
            for(int i=top;i<=bottom;i++){
                v.push_back(matrix[i][right]);
            }
            right--;    // moving right to left

            // Right -> Left:
            // Edge case: This conditions make sure if top is less or equal to bottom, then only the loop will execute, in case of single row, when it's printed, & top will increased, it will make sure that this will not print..
            if(top <= bottom){
                for(int i=right;i>=left;i--){
                    v.push_back(matrix[bottom][i]);
                }
                bottom--;   //  moving bottom to top
            }

            // Bottom -> Top:
            for(int i=bottom;i>=top;i--){
                v.push_back(matrix[i][left]);  
            }
            left++;     // moving left to right
        }

        return v;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int> > matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}