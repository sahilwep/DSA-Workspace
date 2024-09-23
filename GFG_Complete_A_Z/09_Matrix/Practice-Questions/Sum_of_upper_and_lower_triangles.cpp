/*

//  Sum of upper and lower triangles

//  Observations: 
    * Given a square matrix, & we need to find the sum of upper triangle & lower triangle
    * 


// Example:

    Input:
        N = 3 
        mat[][] = {{6, 5, 4},
                   {1, 2, 5}
                   {7, 9, 7}}
    Output: 29 32
    Explanation:
        The given matrix is
        6 5 4
        1 2 5
        7 9 7
        The elements of upper triangle are
        6 5 4
        2 5
        7
        Sum of these elements is 6+5+4+2+5+7=29.
        The elements of lower triangle are
        6
        1 2
        7 9 7
        Sum of these elements is 6+1+2+7+9+7= 32.

    Input:
        N = 2
        mat[][] = {{1, 2},
                   {3, 4}}
    Output: 7 8
    Explanation:
        Upper triangular matrix:
        1 2
        4
        Sum of these elements are 7.
        Lower triangular matrix:
        1
        3 4
        Sum of these elements are 8.


// Example Observations: 
        
        6 5 4   
        1 2 5
        7 9 7

    // Upper triangle:

                6 5 4
                  2 5
                    7

    // Lower triangle:
                6
                1 2
                7 9 7


// Intrusion:
    // Using Auxilary Array:
        * TC: O(n^2)
        * AS: O(n^2)

    // Without using Auxilary Array:
        * TC: O(n^2)
        * AS: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution{   
public:
    // Using Auxilary Array:
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n){
        vector<int> res;
        int x = 0;
        int y = 0;

        for(int i=0;i<n;i++){
            // first getting upper triangle:
            for(int j=i;j<n;j++){
                x += matrix[i][j];
            }
            // Then getting lower triangle:
            for(int j=0;j<=i;j++){
                y += matrix[i][j];
            }
        }
        res.push_back(x);
        res.push_back(y);

        return res;
    }
    // Using Auxilary Array:
    vector<int> sumTriangles_Aux(const vector<vector<int> >& matrix, int n){
        vector<int> upper;
        vector<int> lower;

        for(int i=0;i<n;i++){
            // first getting upper triangle:
            for(int j=i;j<n;j++){
                upper.push_back(matrix[i][j]);
            }

            // Then getting lower triangle:
            for(int j=0;j<=i;j++){
                lower.push_back(matrix[i][j]);
            }
        }

        vector<int> res;

        int x = 0;
        for(auto i: upper) x += i;
        res.push_back(x);
        x = 0;

        for(auto i: lower) x += i;
        res.push_back(x);

        return res;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++){
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        vector<int> result = ob.sumTriangles(matrix,n);
        for (int i = 0; i < result.size(); ++i) cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}