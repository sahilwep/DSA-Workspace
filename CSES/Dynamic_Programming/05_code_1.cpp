/*

//  CSES: Coin Combinations II


// Problem Statement: 
    * Consider a money system consisting of n coins. Each coin has a positive integer value. 
    * Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.

    * For example, if the coins are {2,3,5} and the desired sum is 9, there are 3 ways:
        2+2+5
        3+3+3
        2+2+2+3

    * Constraints
        1 <= n <= 100
        1 <= x <= 10^6
        1 <= c[i] <= 10^6



// Visualization: 

        // DP state:


        // Transitions: 


        // Base case:


        // Final State:




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef size_t s_t;  // use during string traversal
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);
#define mod 1000000007


int coinCombination_2(vector<int> &coins, int x, int n){
    
    vector<int> dp(x + 1, 0);

    dp[0] = 1;  // base case

    // exploring subproblems:
    for(int i=1;i<x+1;i++){
        // Iteration in coins[i]
        for(int j=0;j<n;j++){
            // coins is less or equal to subproblem:
            if(coins[j] <= i){
                dp[i] = (dp[i] + dp[i-coins[j]]) % mod;
            }
        }
    }

    return dp[x];  // return the dp[x], final answer
}

void solve(){
    int n, x;
    cin >> n >> x;
    vector<ll> coins(n);

    for(int i=0;i<n;i++) cin >> coins[i];

    cout << coinCombination_2(coins, x, n) << endl;
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}