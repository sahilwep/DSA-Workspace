/*
//  Weird Algorithm

// Observations: 
    * When n is even divide it by 2.
    * When n is odd multiply it by 3 & add 1.
    * do this until n not become 1.


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
    ll n;
    cin >> n;
    while(n >= 1){
        cout << n << " ";
        if(n == 1) break;
        (n % 2 != 0) ? n = (n *  3) + 1 : n = (n / 2);
    }
    el;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}