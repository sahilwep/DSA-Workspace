/*

//  Transpose of Matrix

//  Observations:
    * Write a program to find the transpose of a matrix of size N*N.



// Example:
    Input:
    N = 4
    mat[][] = {{1, 1, 1, 1},
            {2, 2, 2, 2}
            {3, 3, 3, 3}
            {4, 4, 4, 4}}
    Output: 
    {{1, 2, 3, 4},  
    {1, 2, 3, 4}  
    {1, 2, 3, 4}
    {1, 2, 3, 4}} 


    Input:
    N = 2
    mat[][] = {{1, 2},
            {-9, -2}}
    Output:
    {{1, -9}, 
    {2, -2}}

// Intrusion: 
    * Transpose in simple word, we need to print our matrix in column wise.
    * TC: O(n^2)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;

class Solution{   
public:  
    //Function to find transpose of a matrix.
    void transpose(vector<vector<int> >& matrix, int n){ 
        vector<vector<int> > temp(n, vector<int> (n));

        // Storing the transpose of original matrix into temp matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[i][j] = matrix[j][i];
            }
        }

        // Overwriting elements from temp to original array:
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = temp[i][j];
            }
        }
    }
};

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<vector<int> > matrix(n,vector<int>(n)); 

        for(int i=0; i<n; i++){
            for( int j=0; j<n; j++){
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        ob.transpose(matrix,n);
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j) cout<<matrix[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}