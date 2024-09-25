/*

//  Multiply the matrices


//  Observations: 
    * We have two matrix of dimension: n1xm1 & n2xm2, we need to perform matrix multiplication on these two matrices.


// Example:

    Input:
        n1 = 3, m1 = 2
        A[][] = {{4, 8},
                {0, 2}
                {1, 6}}
        n2 = 2, m2 = 2
        B[][] = {{5, 2},
                {9, 4}}
    Output: 92 40 18 8 59 26
        Explanation:
        Matrices are of size 3 x 2 and 2 x 2 which 
        results in 3 x 2 matrix with elements as:
        res[][] = {{92, 40},
                {18, 8}
                {59, 26}}

    Input:
        n1 = 1, m1 = 1
        A[][] = {2}
        n2 = 1, m2 = 1
        B[][] = {3}
    Output: 6
        Explanation: Both matrices are of size 1 x 1 
        which results in 1 x 1 matrix having element 6.


// Intrusion:
    // Matrix Multiplications: 
        matrix:
            3 7
            4 9
            
            6 2
            5 8

        Let’s consider a simple 2 × 2 matrix multiplication

        Now each of the elements of product matrix AB can be calculated as follows:

            AB11 = 3 × 6 + 7 ×5 = 53
            AB12 = 3 × 2 + 7 × 8 = 62
            AB21 = 4 × 6 + 9 × 5 = 69
            AB22 = 4 × 2 + 9 × 8 = 80

        Therefore,
            53 62
            69 80



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;

class Solution{   
public:
    //Function to multiply two matrices.
    vector<vector<int> > multiplyMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B){
        
        int n1 = A.size();
        int m1 = A[0].size();
        int n2 = B.size();
        int m2 = B[0].size();
        
        // Initialize result matrix with zeros
        vector<vector<int> > res(n1, vector<int>(m2, 0));

        // Check if multiplications is not possible
        if(m1 != n2){
            return {};   // return empty if multiplications is not possible
        }
        

        // Performing matrix Operations:
        for(int i=0;i<n1;i++){
            for(int j=0;j<m2;j++){

                for(int k=0;k<m1;k++){
                    res[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        return res;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int row, col;
        cin>> row>> col;
        vector<vector<int> > A(row); 
        for(int i=0; i<row; i++){
            A[i].assign(col, 0);
            for( int j=0; j<col; j++){
                cin>>A[i][j];
            }
        }
        cin>> row>> col;
        vector<vector<int> > B(row);
        for(int i=0; i<row; i++){
            B[i].assign(col, 0);
            for( int j=0; j<col; j++){
                cin>>B[i][j];
            }
        }
        Solution ob;
        vector<vector<int> > result = ob.multiplyMatrix(A,B);

        if(result.size() == 0) cout<<"-1";
        else{
            for (int i = 0; i < result.size(); ++i){
                for (int j = 0; j < result[0].size(); ++j){
                    cout<<result[i][j]<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}