/*
//  A. Buy a Shovel


// Observations: 
    l = 117, r = 3
    117*9(i) = 1053
            1053 % 10 => 3, which is equal to r, so return i.

    l = 15, r = 2
    15*2(i) = 30
            30 % 10 => 0, return 0.

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

void solve(){
    int l, r;
    cin >> l >> r;
    for(int i=1;i<=9;i++){
        if((l*i)%10==r || (l*i)%10 == 0){
            cout << i << endl;
            return;
        }
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