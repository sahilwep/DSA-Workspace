/*

//  CSES: Minimizing Coins

//  Problem Statement:
    * Consider a money system consisting of n coins. 
    * Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
    
    * For example, 
        if the coins are {1,5,7} and the desired sum is 11, 
        an optimal solution is 5+5+1 which requires 3 coins.
    
    * Constrains:

            1 <= n <= 100
            1 <= x <= 10^6
            1 <= coins[i] <= 10^6

// Visualization: 

        // Unbounded Knapsack:
            -> We are allowed to choose items infinite number of times..

                                                [Item]
                                                  |
                            [item <= knapsack]--------------[item > knapsack]
                                    |                               |
                        -----------------------                 [Reject]
                        |                     |
                    [Include]              [Reject]


                If we Include any item in our knapsack, we can use it again, means it's not processed yet.
                If the item is rejected, means we don't want to include it further, means it's processed.
                So,
                            [Include] -> Not-Processed
                            [Reject]  -> Processed
        
        // Problem Statement:

                -> We are given an array of coins(items), & sum of coins(knapsack)
                -> We need to minimize the number of coins, in order to make our result equal to sum if possible, else return -1

            // We will be solving this question using Tabulations approach:
                -> Create a dp table of t[n+1][sum+1]
        
            // Base case: Think smallest valid input
                                
                                n = size of array, sum = given sum of coins that we have to make

                    if(sum == 0 && n == 0):
                        => No coins need
                        so, t[0][0] = 0
                    
                    if(sum == 0 && n > 0):
                        if sum = 0, we don't need any coins, to make sum = 0, because from the constrains,  1 <= coins[i] <= 10^6
                        so, t[i][0] = 0

                    if(sum > 0 && n == 0):
                        if we have some sum value grater than '0', & we are given empty bag of coins: 
                            This is clearly incorrect because it's impossible to make any positive sum without any coins.
                            Hence, we initialize these cells to very large number (INT_MAX - 1), which acts as a signal that it's impossible to form the sum using zero coins.
                            Why INT_MAX - 1 instead of INT_MAX?:
                                we choose INT_MAX - 1 to prevent overflow when we add 1 in the recurrence relations.
                                If we used INT_MAX and added 1 to it, it would overflow and cause errors, so we subtract 1 to avoid that situations.
                        so, t[0][i] = INT_MAX - 1

                    So Base cases in recursive format:
                        if(sum == 0 && n == 0) return 0
                        if(sum == 0 && n > 0) return 0;
                        if(sum > 0 && n == 0) return INT_MAX-1;


            // Rest of the logic is of Unbounded knapsack.

            // Last we need to take care of condition, which we used "INT_MAX - 1"  as a signal for impossible case.
                    return (t[n][sum] == INT_MAX) ? -1 : t[n][sum];



// Complexity: 
    * TC: O(n*sum)
    * AS: O(n*sum)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long

// Solved using unbounded knapsack:
int minCoins(vector<ll> val, ll sum, ll n){
    vector<vector<int> > t(n+1, vector<int> (sum+1, 0));

    // Initialize first column (sum = 0, 0 coins needed)
    for(int i=0;i<n+1;i++){
        t[i][0] = 0;
    }

    // Initialize first row (sum > 0, no coins available)
    for(int j=1;j<sum+1;j++){
        t[0][j] = INT_MAX - 1;  // Use INT_MAX - 1 to avoid overflow
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            // if item size is less or equal to knapsack value: 
            if(val[i-1] <= j){
                // Two choice: Include(Not-processed) / Reject(Processed)
                t[i][j] = min(
                    1 + t[i][j-val[i-1]],   // include(Not-processed), adding 1, so that we can count the number of coins.
                    t[i-1][j]   // reject(processed)
                    );
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][sum] == INT_MAX - 1 ? -1 : t[n][sum];
}

void solve(){
    ll n, sum;
    cin >> n >> sum;
    vector<ll> val(n);
    for(int i=0;i<n;i++) cin >> val[i];

    cout << minCoins(val, sum, n) << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}