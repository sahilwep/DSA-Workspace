/*

//  5 01 Knapsack Top Down DP

//  Observations: 
    * 




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
    cout << knapsack_Recur(weight, value, W, n) << endl;


}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}