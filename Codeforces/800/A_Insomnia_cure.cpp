/*
//  A. Insomnia cure


// Observations: 
    * for every position is given, we have to check d place
    * We can check multiples..
    * i = 1 -> i = d
    * i % k, l, m, n  = 0 (check) if it's divisible or not ?

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
    int k, l, m, n, d;
    cin >> k >>l >> m >>n >>d;
    int res = 0;
    // if(k == 1 || l == 1 || m == 1 || n == 1){
    //     cout << d << endl;
    //     return;
    // }
    for(int i=1;i<=d;i++){
        if( i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) res++;
        // if((i%k != 0) && (i%l != 0) && (i%m != 0) && (i%n != 0)) res--;  Initially res = d for this condition..
    }
    cout << res << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}