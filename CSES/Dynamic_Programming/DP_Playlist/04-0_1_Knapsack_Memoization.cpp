/*

// 0 - 1 Knapsack Memoization (Top-Down):


// Steps to make our recursive code into memoization:
    * In Bottom-Up we'he created matrix, So memoization(top-down) is an alternative to that, which is easy to implement, & having same performance as Bottom-up
    * We just need to add few lines in our recursive solution, & it's memoized..
    * We will create same matrix that we used to make in Bottom-up.
    * First we have to create a matrix where we are going to store the values: let the matrix be 't'
        * How do we decide, what will be our matrix dimensions:
            * Some inputs in our recursive solutions are changing(decreasing in size), & some are not changing
            * At most of the place 'n' & 'w' is changing.
            * So, we will create a matrix of these two variable whose values are changing...
                
                matrix:  t[n+1][w+1]        -> we are Creating matrix of n+1, because if we take n, then we need to store till 'n-1'

        * Initialize all the values of matrix with '-1'
            
            memset(t, -1, sizeof(t))        -> we can use memset function to fill matrix with default values.

        * Whenever we are finding some values, we always look on matrix either the value is present there or not.
            * If the values is present return directly.
            * Else: If values are not present in the matrix(means there will be '-1' at the position).
                * We will find the value & store it in memo-array
            * NOTE: We will check the values in matrix before finding it.

    * So, In Conclusion, what chances should be done in recursive Solution: 
        * First create a global matrix, or we can create it static,
        * Dimension of matrix depends on the variable values from recursive solution.
        * Size of matrix depends on the constrains of the variable values according to the question that we have given.
            * Example Let's say constrains of n & W are given that, n <= 100 & W <= 1000, 
                * So we can create a static matrix:  t[102][1002]   -> two values just to take for safety.
        * Then we will memset this matrix from parent function -> memset(t, -1, sizeof(t))
        * In recursive solution, after base case, we will check if the value that we are looking for is already present or not.
            * if we have our value in matrix, then we return the value to parent call.
            * Else we will try to find that value.
                * The recursive calls that we are using, we just have to update with t[n][w] = knapsack(....) 
        * That's it, our recursive solutions now become the Dp solutions.
    
        * Alway try to write memoization solution, because Memoization & Bottom-up have same complexity.

// Minimal Drawback: 
    * Sometimes Bottom-up works better in comparision to memoization, vice versa..
    * The only drawback is size of function call stack is increased..
    * But most of the time it's works perfectly..

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
// n <= 100 & W <= 1000
int static t[102][1002]; // matrix Initialization

// Using Memoization:
int knapsack(int wt[], int val[], int W, int n){
    // Base condition:
    if(W == 0 || n == 0){
        return 0;
    }
    // If value is already present in matrix:
    if(t[n][W] != -1){
        return t[n][W];     // return it directly without having recursive calls.
    }

    // Recursive Code:
    if(wt[n-1] <= W){
        t[n][W] = max(val[n-1] + knapsack(wt, val, (W - wt[n-1]), n-1), knapsack(wt, val, W, n-1));
        return t[n][W];
    }
    else{
        t[n][W] = knapsack(wt, val, W, n-1);
        return t[n][W];
    }
}


// Normal recursive 0 - 1 knapsack -> O(n^2)
int knapsack_Recur(int wt[], int val[], int W, int n){
    // Base condition: 
    if(n == 0 || W == 0) return 0;  // as we don't have item left or don't have capacity to store item in bag, we will return 0 as max profit.
    // Choice Diagram:
    if(wt[n-1] <= W){
        return max(val[n-1] + knapsack_Recur(wt, val, (W-wt[n-1]), n-1),  knapsack_Recur(wt, val, W, n-1)); // check for max profit getting if we include it or not?
    }
    else{
        return knapsack_Recur(wt, val, W, n-1);   // don't include
    }
}


void solve(){
    int n;
    cin >> n;
    int value[n];
    int weight[n];
    for(int i=0;i<n;i++) cin >> value[i];
    for(int i=0;i<n;i++) cin >> weight[i];

    int W;
    cin >> W;

    // // Recursive Solution Call:
    // cout << knapsack_Recur(weight, value, W, n) << endl;


    // Memoization Solution Call:
    memset(t, -1, sizeof(t));   // filling matrix with default value '-1'
    cout << knapsack(weight, value, W, n) << endl;

}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}