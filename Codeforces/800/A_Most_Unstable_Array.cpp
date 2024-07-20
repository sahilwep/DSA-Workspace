/*

//  A. Most Unstable Array

// Observations: 
    * for single place, _ we have absolute difference is 0.
    * For two places, _ _ if we put one number and one 0, then the absolute difference will be maximum.
    * for more than two places, let say 5 -> _ _ _ _ _ -> 0 2 0 3 0 -> absolute diff will be 10, which is double of 5.
    * We can say for more than two places we can have max absolute difference twice of places..


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
    ll n, m;
    cin >> n >> m;
    if(n == 1) cout << 0 << endl;   // for only one number max absolute difference will be 0
    else if(n == 2) cout << m << endl;  // for two number max absolute difference will be that number itself if we put one 0
    else cout << 2*m << endl;   // for more than 2 number we have max absolute difference twice of than number
    
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}