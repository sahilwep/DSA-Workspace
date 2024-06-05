/*
//  A. Maximum GCD


// observations: 
    * We have given n, we have to find the maximum possible gcd of integer pair
        * We have to find the maximum value of gcd(a,b), where (a <= b <= n)


// Intrusion: 
    * If we carefully observe the numbers, gcd of two number is always the half time the maximum number among them...
    * so we can say that we can return n/2 simply...



*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);

// GCD: 
int gcd(int a, int b){
    if(a == 0){
        return b;
    }
    return gcd(b % a, a);
}

void solve(){
    int n;
    cin >> n;

    // Naive solution: Gives TLE
    // int res = 0;
    // for(int i=1;i<=n;i++){
    //     for(int j=i+1;j<=n;j++){
    //         int solu = gcd(i, j);
    //         res = max(res, solu);
    //     }
    // }
    // cout << res << endl;

    // efficient solution: 
    cout << n/2 << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}