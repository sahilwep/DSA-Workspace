/*

//  A. Arithmetic Array

// Observations: 
    * for array to be good, mean value should be 1,
    * We can append any positive value to the end of array, we need to find that what is the minimum number of operations required to make array good.

// Key observations: 
    * If the array size is grater that the sum of all array element, we only need 1 step to make it's mean value 1
    * else we need (sum - length) operations to make it equal..


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
    arrInp;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    if(sum < n){
        cout << 1 << endl;
    }
    else{
        cout << sum - n << endl;
    }
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}