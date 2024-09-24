/*

//  Reversing the columns of a Matrix


//  Observations: 
    * We are given a matrix of dimensions NxM, & we need to reverse it column wise i.e: c1, c2, c3, c4 -> c4, c3, c2, c2

// Example:

    Input:
    n1 = 4, m1 = 3
    matrix[][] = {{ 1,  2,  3},
                 { 5,  6,  7},
                 {11, 10,  9},
                 {13, 14, 15}}
    Output: 3 2 1 7 6 5 9 10 11 15 14 13
        Explanation:
        Array after exchanging columns:
        3 2 1
        7 6 5
        9 10 11
        15 14 13

    Input:
    n1 = 2, m1 = 5
    matrix[][] = {{ 1, 2, 3, 4, 5},
                 { 6, 7, 8, 9, 10}}
    Output: 5 4 3 2 1 10 9 8 7 6
        Explanation:
        After reversing the column of matrix
        5 4 3 2 1
        10 9 8 7 6

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution{   
public:
    // TC: O(n*m)
    void reverseCol(vector<vector<int> > &matrix){
        for(int i=0;i<matrix.size();i++){
            reverse(matrix[i].begin(), matrix[i].end());
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
            for( int j=0; j<col; j++) cin>>matrix[i][j];
        }
        
        Solution ob;
        ob.reverseCol(matrix);

        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j) cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}