/*

//  Exchange matrix columns

//  Observations: 
    * You are given matrix of dimension (n1x m1), you have to exchange first column with last column.

// Example:

    Input:
        n1 = 4, m1 = 4
        matrix[][] = {{1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15,16}}
    Output: 4 2 3 1 8 6 7 5 12 10 11 9 16 14 15 13
    Explanation:
        Matrix is as follow:
        1 2 3 4
        5 6 7 8
        9 10 11 12
        13 14 15 16
        After exchanging first column with 
        last column, we have matrix as follows:
        4 2 3 1
        8 6 7 5
        12 10 11 9
        16 14 15 13

    
    Input:
        n1 = 2, m1 = 3
        matrix[][] = {{4, 3, 2},
                      {1, 5, 6}}
    Output: 2 3 4 6 5 1
        Explanation:
        Matrix is as follows:
        4 3 2
        1 5 6
        After exchanging columns matrix will be:
        2 3 4
        6 5 1


// Intrusion: 
    * Iterate i from 0 to n
    * During iterations pick start & end element of every i:
        * swap these two values. 
    * TC: O(n)
    * AS: O(1)
    

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution{
public:
    // TC: O(n)
    void exchangeColumns(vector<vector<int> > &matrix){
        for(int i=0;i<matrix.size();i++){
            // cout << *matrix[i].begin() << " " << *(matrix[i].end() - 1) << endl;
            swap( *matrix[i].begin(), *(matrix[i].end() - 1));
        }
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n1, m1;
    	cin >> n1 >> m1;
    	vector< vector<int> > matrix(n1, vector<int> (m1));
    	for(int i = 0; i < n1; i++){
    		for(int j = 0; j < m1; j++){
    			cin >> matrix[i][j];
    		}
    	}
    	Solution obj;
    	obj.exchangeColumns(matrix);
    	for(int i = 0; i < n1; i++){
    		for(int j = 0; j < m1; j++){
    			cout << matrix[i][j] << ' ';
    		}
    	}
    	cout << endl;
    }
	return 0;
}