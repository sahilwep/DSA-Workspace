/*

//  Print Matrix in snake Pattern

//  Observations: 
    * We are given array of N*N, or matrix, we need to print in snake order.

// Example:
    Input:
    N = 3 
    matrix[][] = {{45, 48, 54},
                {21, 89, 87}
                {70, 78, 15}}
    Output: 
    45 48 54 87 89 21 70 78 15 
    Explanation:
    Matrix is as below:
    45 48 54
    21 89 87
    70 78 15
    Printing it in snake pattern will lead to 
    the output as 45 48 54 87 89 21 70 78 15.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<int> snakePattern(vector<vector<int> > matrix){   
        vector<int> res;
        int n = matrix.size();

        bool flag = 1;  // using flag to print element in two way.

        for(int i=0;i<n;i++){
            if(i % 2 == 0) flag = 1;    // even times flag = true
            else flag = 0;      // odd times flag = false

            for(int j=0;j<matrix[i].size();j++){
                if(flag){
                    int x = matrix[i][j];
                    res.push_back(x);
                }
                else{
                    // for inner element if we want to print in reverse wise, we need to get the size of inner element range.
                    int innerSize = matrix[i].size();   // getting the inner size
                    int x = matrix[i][innerSize - j - 1];   // now storing the element in reverse order
                    res.push_back(x);
                }
            }
        }

        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) {
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
        vector<int> result = ob.snakePattern(matrix);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}