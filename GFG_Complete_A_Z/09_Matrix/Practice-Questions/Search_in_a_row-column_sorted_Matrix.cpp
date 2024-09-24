/*

//  Search in a row-column sorted Matrix

//  Observations: 
    * Given a matrix nxm, where every element row & column is sorted in increasing order. and a number x.
    * Find whether the element x is present or not. Return 1 if present : else return 0



// Examples:

    Input:  matrix[][] = [[3, 30, 38],[36, 43, 60],[40, 51, 69]], x = 62
    Output: 0
    Explanation: 62 is not present in the matrix, so output is 0.

    Input: matrix[][] = [[18, 21, 27, 38, 55, 67]], x = 55
    Output: 1
    Explanation: 55 is present in the matrix.


// Intrusion:
    // Using Binary Search:
        * For every row we will use binary search, which will take (logm), & it's goes for n times, so (nlogm)
        * TC: O(nlogm)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Using Binary Search:
    bool search(vector<vector<int> > &matrix, int n, int m, int x) {
        for(int i=0;i<n;i++){
            if(binary_search(matrix[i].begin(), matrix[i].end(), x)) return 1;
        }

        return 0;
    }       
};

int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) cin >> matrix[i][j];
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.search(matrix, n, m, x)) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}
