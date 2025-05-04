/*

//  5 01 Knapsack Bottom Up DP

//  Bottom Up: 
    * In normal Top-Down, we use to create a matrix of size [n+1][w+1], & recursively call the same function & try to find if values are not present..
    * In Bottom, up our approach will be bit different we will create a matrix of size [n+1][w+1], & iteratively find the values instead of using recursion..
        * We will start with filling base Conditions first, & then we will go with choice diagram & filling values..
        * At last we will return the last value of the matrix that were asked...

    // Bottom Up:
        * From the previous recursive solutions, we will omit the recursive calls & use table instead..
        * We will create a table or matrix, which is of dimension of those value that is changing...
            * In our case, n & W are changing..
                      
                    n = 6, W = 4

                            <--------W+1-------->
                              0   1   2   3   4 
                        0   |   |   |   |   |   |
                        1   |   |   |   |   |   |
                 ^      2   |   |   |   |   |   |
                 |      3   |   |   |   |   |   |
                n+1     4   |   |   |   |   |   |
                 |      5   |   |   |   |   |   |
                        6   |   |   |   |   |   |       matrix

        * NOTE: we are creating n+1, & W+1, because [0,0] is reserved, & elements are mapped with one index ahead
            * means first value of n is mapped with 1, not 0, & same goes with W also..

        * Now we will fill this matrix by two steps:
            * Step 1: Initialization
                *  Base Condition changes into Initialization,
                     if(W == 0 || n == 0) return 0 -> changes into: 

                            <--------W+1-------->
                              0   1   2   3   4
                        0   | 0 | 0 | 0 | 0 | 0 |   -> when n = 0
                        1   | 0 |   |   |   |   |
                 ^      2   | 0 |   |   |   |   |
                 |      3   | 0 |   |   |   |   |
                n+1     4   | 0 |   |   |   |   |
                 |      5   | 0 |   |   |   |   |
                        6   | 0 |   |   |   |   |
                              |
                         when W = 0

                        * When we have (n = 0 || w == 0) in these case we are returning '0', that's why we are filling these row & column with 0.

                * CODE: matrix Initialization:

                        int t[n+1][w+1];    

                        for(i=0;i<n+1;i++)
                            for(j=0;j<W+1;j++)
                                if(i == 0 || j == 0) t[i][j] = 0;


            * Step 2: Changing recursive calls into iterative version
                    * Now we have choice diagram that we should have to change into the iterative version:
                    * Recursive Version:
                            // Choice Diagram:
                                if(wt[n-1] <= W){
                                    max(val[n-1] + knapsack(val, wt, (W - wt[n-1]), n-1), knapsack(val, wt, W, n-1));
                                }else{
                                    knapsack(val, wt, W, n-1)
                                }

                    * We have learnt in base condition that we are changing n,W -> i,j
                    * Similarly, we will change n, w, with i, j here also.
                          
                                if(wt[n-1] <= W){
                                    t[n][W] = max(val[n-1] + t[n-1][W-wt[n-1]], t[n-1][W])
                                }else{
                                    t[n][W] = t[n-1][W]
                                }

                        * So, the iterative Code: n, W => i, j

                        for(i = 1;i<n+1;i++)
                            for(j = 1;j<W+1;j++)
                                if(wt[i-1] <= j){
                                    t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j])
                                }else{
                                    t[i][j] = t[i-1][j];
                                }
    
                        * Note: Iteration starts from 1, because (0,0) for both i & j is already filled.

                    * Now At the last when the loop over, we need to return the last value of matrix that denotes the asked question.
                    * So, we will (return t[n][w])

// Knapsack 0-1 Bottom Up:
    * First initialize the matrix, t[n+1][W+1], with one extra space
    * Second fill it with base conditions..
    * Third fill the choice diagram, by converting recursive solutions into iterative solutions..


// Observations: 
    * In this approach, first we fill the base condition, & then gradually we fill the larger solutions with the help of previous calculated solutions..
    * At the end we return the largest value of matrix, that the question asked for..
    * So, we are going from smaller to bigger -> i.e bottom Up, first we solve smallest problem, with that we are building the larger solutions.

// Complexity:
    * Complexity will be improved as we are not using recursive solution, which restrict the overhead of recursive calls in stack.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Bottom Up:
int knapsack(int wt[], int val[], int W, int n){
    // Declaring matrix of size n, & w:
    int t[n+1][W+1];

    // Filling base conditions: When (W == 0 || n == 0)
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i == 0 || j == 0) t[i][j] = 0;
        }
    }


    // Choice Diagram Code:
    // Changing (n -> i & W -> j)
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            // when wt[n-1] <= W : Two choices -> accept or reject
            if(wt[i-1] <= j){
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
            }

            // when wt[n-1] > W : reject
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    // returning maxProfit:
    return t[n][W];
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

    // Recursive Solution Call:
    cout << knapsack_Recur(weight, value, W, n) << endl;

    // // Bottom Up Call:
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