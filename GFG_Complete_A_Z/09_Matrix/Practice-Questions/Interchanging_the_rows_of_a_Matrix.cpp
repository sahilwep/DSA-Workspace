/*

//  Interchanging the rows of a Matrix

//  Observations: 
    * We are given matrix of dimension n1xm1. Interchange its rows in-place such that the first row will become the last low.


// Example:

    Input:
        n1 = 4, m1 = 4
        matrix[][] = {{1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15,16}}
    Output: 13 14 15 16 9 10 11 12 5 6 7 8 1 2 3 4
    Explanation:
        Matrix after exchanging rows:
        13 14 15 16
        9 10 11 12
        5  6  7  8
        1  2  3  4
        Note: Output is printed row-wise linearly. 


    Input:
        n1 = 5, m1 = 3
        1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
        matrix[][] = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9},
                    {10, 11, 12},
                    {13, 14, 15}}
    Output: 13 14 15 10 11 12 7 8 9 4 5 6 1 2 3
    Explanation:
        After interchanging rows:
        13 14 15
        10 11 12
        7  8  9
        4  5  6
        1  2  3


// Intrusion: 
    * Swap first & last rows element while iterating.
    * Iterate n/2 times, & for every iterations we will swap first & last row of elements.
            for i = 0 -> n/2
                for j = 0 -> m            
                   swap(matrix[i][j], matrix[n-i-1][j]);
    * TC: O(n*m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;

class Solution{
public:
    void interchangeRows(vector<vector<int> > &matrix){
        int n = matrix.size();
        for(int i=0;i<n/2;i++){
            for(int j=0;j<matrix[i].size();j++){
                swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }

    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++){
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++){
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.interchangeRows(matrix);

        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                cout<<matrix[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}