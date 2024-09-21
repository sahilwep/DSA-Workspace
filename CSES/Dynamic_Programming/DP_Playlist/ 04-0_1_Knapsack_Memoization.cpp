/*

// 0 - 1 Knapsack Memoization:




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Normal recursive 0 - 1 knapsack -> O(n^2)
int knapsack(int wt[], int val[], int W, int n){
    // Base condition: 
    if(n == 0 || W == 0) return 0;  // as we don't have item left or don't have capacity to store item in bag, we will return 0 as max profit.
    // Choice Diagram:
    if(wt[n-1] <= W){
        return max(val[n-1] + knapsack(wt, val, (W-wt[n-1]), n-1),  knapsack(wt, val, W, n-1)); // check for max profit getting if we include it or not?
    }
    else{
        return knapsack(wt, val, W, n-1);   // don't include
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