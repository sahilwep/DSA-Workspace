/*

//  Matrix chain multiplication Memoization 


// Problem Statement: 
    * We are given an array that contains dimension of (n-1) matrix & we need to find the minimum cost to multiply these all matrix...


// Example:

    Input: N = 5
    arr = {40, 20, 30, 10, 30}
    Output: 26000
    Explanation: There are 4 matrices of dimension 
        40x20, 20x30, 30x10, 10x30. Say the matrices are 
        named as A, B, C, D. Out of all possible combinations,
        the most efficient way is (A*(B*C))*D. 
        The number of operations are -
        20*30*10 + 40*20*10 + 40*10*30 = 26000.


    Input: N = 4
    arr = {10, 30, 5, 60}
    Output: 4500
    Explanation: The matrices have dimensions 
        10*30, 30*5, 5*60. Say the matrices are A, B 
        and C. Out of all possible combinations,the
        most efficient way is (A*B)*C. The 
        number of multiplications are -
        10*30*5 + 10*5*60 = 4500.


// Problem:
    * We are having same problem called again & again, which overhead recursive calls, So, we will store the solution of subproblem, & return them when it's need..


// IntrusioN: 
    * DP Table Setup: dp[i][j] represents the minimum number of multiplications needed to multiply the matrices from index i to j.
    * Filling the Table: We iterate over different chain lengths l (from 2 to n-1) to ensure each possible subproblem is solved in bottom-up order. For each i and j pair (the current subproblem), we determine the best point k to split the chain and update dp[i][j] with the minimum cost for multiplying matrices from i to j.
    * Final Result: dp[1][n-1] holds the minimum cost for multiplying the entire chain.


// Complexity:
    * TC: O(N^3)    -> Quadratic
    * AS: O(N^2)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Tabulations Implementation:

// Function to compute the minimum number of multiplications needed to multiply the chain of matrices
int mcm(int arr[], int n) {
    // Create a DP table where dp[i][j] will store the minimum multiplication cost
    // for multiplying matrices from index i to j
    int dp[n][n];
    
    // Initialize the DP table with 0 as multiplying a single matrix requires 0 multiplications
    memset(dp, 0, sizeof(dp));

    // l represents the length of the matrix chain being considered, starting from 2
    for (int l = 2; l < n; l++) { // We start from length 2 because multiplying one matrix alone costs 0
        for (int i = 1; i < n - l + 1; i++) { 
            // i is the starting index of the matrix chain in the current subproblem
            int j = i + l - 1;  // j is the ending index of the matrix chain

            // Initialize dp[i][j] with a large value because we are looking for the minimum cost
            dp[i][j] = INT_MAX;
            
            // Try every possible position k to split the matrix chain from i to j
            for (int k = i; k < j; k++) {  
                // Cost to split at k:
                // dp[i][k] is the cost of multiplying matrices from i to k
                // dp[k+1][j] is the cost of multiplying matrices from k+1 to j
                // arr[i-1] * arr[k] * arr[j] is the cost of multiplying the resulting matrices
                int cost = dp[i][k] + dp[k+1][j] + (arr[i-1] * arr[k] * arr[j]);

                // Update dp[i][j] with the minimum cost obtained by trying each k
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    
    // The minimum cost to multiply the entire chain from the first matrix to the last
    return dp[1][n-1];
}


void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    // MCM Calling: i = 1 & j = n-1 -> passed
    cout << mcm(arr, n) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}