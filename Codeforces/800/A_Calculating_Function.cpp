/*
//  A. Calculating Function


For a positive integer n let's define a function f:

f(n) =  - 1 + 2 - 3 + .. + ( - 1)nn

Your task is to calculate f(n) for a given integer n.

-1+2-3+4-5+6-7+8-9+....n


// naive solution: TLE for such large number 10^15
void solve(){   
   int n;
    cin >> n;
    ll res = 0;
    for(int i=1;i<=n;i++){
        if(i % 2 != 0){
            res = res -i;
        } else {
            res = res +i;
        }
    }
    cout << res << endl;
}


// efficient solution: 
9 => -1+2-3+4-5+6-7+8-9 = -5
10 => -1+2-3+4-5+6-7+8-9+10 = 5
11 => -1+2-3+4-5+6-7+8-9+10-11 = -6
12 => -1+2-3+4-5+6-7+8-9+10-11+12 = 6

x => odd => ans negative
x => even => ans positive

x = 9 -> (x/2 + 1)*-1 -> -1*(4 + 1) (we have to add 1 to odd number & multiply with -1) 
x = 10 -> x/2 -> 5 


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
#define SQ(a) (a)*(a)

void solve(){
    ll n;
    cin >> n;
    if(n % 2 != 0){
        ll res = (n/2 + 1) * -1;
        cout << res << endl;
    } else {
        ll res = n/2;
        cout << res << endl;
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