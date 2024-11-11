/*

//  CSES: Coin Combinations I

//  Problem statement: 
    * Consider a money system consisting of n coins. Each coin has a positive integer value. 
    * Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.

    * For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
        2+2+5
        2+5+2
        5+2+2
        3+3+3
        2+2+2+3
        2+2+3+2
        2+3+2+2
        3+2+2+2

    * Constrains: 
        1 <= n <= 100
        1 <= x <= 10^6
        1 <= coins[i] <= 10^6

    
// Problem Visualization: 
    -> We are allowed to choose any coins for infinite number of times -> Which makes this question of unbounded knapsack type.
    -> we are given sum 'x', which we have to make, & we have to find total number of ways for which we can makes our value.
    
    -> This question is very simillar to the previous question: "CSES: Minimizing Coins"
    -> In "CSES: Minimizing Coins", we were finding the subproblem that takes minimum coins, but here we need to count all the possible subproblem which will generate our ans.
    -> and that will become our answer:

    // DP State: 
            
                dp[k] = no of ways to get the sum k
    
    // DP transitions: 
                        n
                dp[k] = Σ dp[k - c[i]]
                        i=1
    
    // Base case:
            
                dp[0] = 1, There's one way to make sum 0 (by choosing no coins).
    
    // Final Subproblem:

                final subproblem -> dp[x]


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
#define mod 1000000007

// coin Combinations:
int coinCombinations(vector<int> coins, int x, int n){

    vector<int> dp(x + 1, 0);
    dp[0] = 1;  // base case

    // dp[x] = dp[x - c[i]], in order to calculate dp[x], it's depends on previous value, this is why we are starting from 1 & go up till x
    for(int i=1;i<x+1;i++){
        // we are iterating into coins, from index 0 to 'n' to find dp[i]
        for(int j=0;j<n;j++){
            // if coins value is less or equal to the 'x' we can use it else we can't
            if(coins[j] <= i){
                // transitions:
                dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
            }
        }
    }

    return dp[x];   // no of ways to construct 'x', final subproblem
}

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin >> coins[i];

    cout << coinCombinations(coins, x, n) << endl;  
    
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}