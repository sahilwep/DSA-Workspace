/*

//  A. Ambitious Kid

// Observations: 
    * We are given an array that contains some values,
    * In one operations we can either increment or decrement the value by 1
    * We have to find, In how much operations we can make our array looks like: a1*a2*a3*a4*...*an = 0

// Key observations: 
    * If we observe carefully, we can increment or decrement the given value, by one operations..
    * Increment: if our values are in negative range
    * Decrement: if our value are in positive range
    * But we have to find the absolute minimum of all of the above..
    * TC: O(N)



*/

#include<bits/stdc++.h>
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

void solve(){
    int n;
    cin >> n;
    int arr[n];
    int minOps = INT_MAX;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        minOps = min(minOps, abs(arr[i]));
    }

    cout << minOps << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}