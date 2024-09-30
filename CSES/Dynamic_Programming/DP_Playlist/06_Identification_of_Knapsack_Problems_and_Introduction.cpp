/*

//   6 Identification of Knapsack Problems and Introduction 


// Knapsack 0-1: 
    * Like In Earlier, example we are given item that has some weight & value, Does'nt matter we are given value or not, if any question given with some choice, & we have a certain fix capacity, we can use knapsack.
    * Whenever we are given some choice, & we have some limit to store it on, like in our case W, then we can say we can use knapsack 0-1
    * Pattern: 
        * Whenever there is some item, & we are given some choice that we can take it or not
        * And, we are given some max capacity that store some items in it.
        * Use 0-1 knapsack there.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// bottom Up Knapsack:
int knapsack(int wt[], int val[], int W, int n){
    // matrix Initialization: 
    int t[n+1][W+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i == 0 || j == 0){
                t[i][j] = 0;
            }
        }
    }

    // Choice Diagram: Building Matrix
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(wt[i-1] <= j){
                t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][W];
}

// recursive Knapsack solutions: 
int knapsack_Recur(int wt[], int val[], int W, int n){
    if(W == 0 || n == 0){
        return 0;
    }
    if(wt[n-1] <= W){
        return max(val[n-1] + knapsack_Recur(wt, val, (W - wt[n-1]), n-1), knapsack_Recur(wt, val, W, n-1));
    }else{
        return knapsack_Recur(wt, val, W, n-1);
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