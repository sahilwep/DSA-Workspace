/*

//  Rotate by 90 degree

//  Observations: 
    * Given square matrix N*N. The task is to rotate it by 90 degree in anti clockwise directions without using extra space.


// Example

    Input:
    N = 3 
    matrix[][] = {{1, 2, 3},
                {4, 5, 6}
                {7, 8, 9}}
    Output: 
    Rotated Matrix:
    3 6 9
    2 5 8
    1 4 7

    Input:
    N = 2
    matrix[][] = {{1, 2},
                {3, 4}}
    Output: 
    Rotated Matrix:
    2 4
    1 3


// Example Observations:
        Input:            Output:
        1 2 3       =>    3 6 9
        4 5 6       =>    2 5 8
        7 8 9       =>    1 4 7

            temp[i][j] = matrix[j][n-i-1]

// Intrusion: 
    // Using Auxilary array to rotate array by 90 degree.
        * TC: O(n*n)
        * AS: O(n*n)
    

    // Rotate without using auxilary array.
        1 2 3       =>    3 6 9
        4 5 6       =>    2 5 8
        7 8 9       =>    1 4 7

        Reverse row wise & column wise


        // Example:
                Matrix: 1  2  3  4 
                        5  6  7  8 
                        9  10 11 12 
                        13 14 15 16 

                Output: 4  8 12 16 
                        3  7 11 15 
                        2  6 10 14 
                        1  5  9 13

                // Step to perform:

                    * First reverse every row:

                        4  3  2  1
                        8  7  6  5
                        12 11 10 9 
                        16 15 14 13 

                    * swap row with column => Transpose of matrix

                        4  8  12 16
                        3  7  11 15
                        2  6  10 14
                        1  5  9  13
                    
                    * NOTE: To move value from row to column wise: 
                        * We can use this logic: 
                        i = 0 -> n
                            j = i + 1 -> n
                                swap(arr[i][j], arr[j][i])

        * TC: O(n)
        * AS: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution{   
public:
    // Without using Auxilary array:
    void rotateby90(vector<vector<int> >& matrix, int n){
        // First rotate every rows of array:
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }

        // Reverse row with column:
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

    }


    // Using Auxilary Array:
    void rotateby90_Aux(vector<vector<int> >& matrix, int n){

        vector<vector<int> > temp(n, vector<int> (n));  // Auxilary space to perform all the operations

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[i][j] = matrix[j][n-i-1];

            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = temp[i][j];
            }
        }
        temp.clear();
    } 
};


int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++){
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++){
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.rotateby90(matrix, n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}