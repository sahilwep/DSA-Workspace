/*

//  Boundary traversal of matrix

//  Observations: 
    * We are given matrix of NxM, & we need to traverse it clockwise & print only boundary element.
    * we need to start from '0' & traverse in a circular way so that all the boundary element should be print.


// Example:

    Input:
    n = 4, m = 4
    matrix[][] =   {{1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15,16}}
    Output: 1 2 3 4 8 12 16 15 14 13 9 5
    Explanation:
    The matrix is:
    1  2  3  4
    5  6  7  8
    9  10 11 12
    13 14 15 16
    The boundary traversal is:
    1 2 3 4 8 12 16 15 14 13 9 5

    Example 2:

    Input:
    n = 3, m = 4
    matrrix[][] = {{12, 11, 10, 9},
                    {8, 7, 6, 5},
                    {4, 3, 2, 1}}
    Output: 12 11 10 9 5 1 2 3 4 8

// Key Observations: 
    * For first row we need to print all the element starting from 0 to end of that row.
    * while going down we need print only last element..
    * For last row we need to print all the element in reverse order from end to start.
    * While going up we need to print only first element..


// Intrusion: 
    * First we will print first row
    * then we will print last column from row 1 to n-2
    * then we will print last row in reverse order
    * then we will print first column from n-2 to 1 in reverse order
    * TC: O(n+m)


// Edge case: 
    * When We have (n = 1 || m == 1), we have to handel these cases explicitly.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution{
public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m){
        
        vector<int> res;

        // Edge case:
        // When we have only one column:
        if(m == 1){
            for(int i=0;i<n;i++){
                res.push_back(matrix[i][0]);
            }
            return res;
        }
        // when we have only one row:
        if(n == 1){
            for(int i=0;i<m;i++){
                res.push_back(matrix[0][i]);
            }
            return res;
        }


        // Rest case:
        // Printing first row element:
        for(int i=0;i<m;i++){
            res.push_back(matrix[0][i]);
        }
        
        // Printing the last column of matrix from 1 to n-2
        for(int i=1;i<n-1;i++){
            res.push_back(matrix[i][m-1]);
        }

        // Printing last row in reverse order:
        for(int i=m-1;i>=0;i--){
            res.push_back(matrix[n-1][i]);
        }

        // printing first column from last to first:
        for(int i=n-2;i>0;i--){
            res.push_back(matrix[i][0]);
        }

        return res;
    }
};

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++){
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++){
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i) cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}