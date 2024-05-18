/*
//  A. Divisibility Problem


// Naive solution: Time limit exceed
void solve(){
    int a, b;
    cin >> a >> b;
    int res = 0;
    while( a % b != 0){
        a++;
        res++;
    }
    cout << res << endl;
}

// TLE for such large input size: 

// Observations: 

    if(a%b == 0) return 0
    else {
        res = a % b
        res = b - res;
        return res;
    }


a = 10, b = 4
    res = 10 % 4 = 2
    res = 4 - 2 = 2

a = 13, b = 9
    res = 13 % 9 = 4
    res = 9 - 4 = 5

a = 100, b = 13
    res = 100 % 13 = 9
    res = 13 - 9 = 4

    * We can say, How many times we can increase a number X, i.e X is divisible by Y.
    * We can take modulo of : X % Y = Z
    * Now we can subtract from y : Y - Z = K(times we have to increase X).


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


// TC : O(1)
void solve(){
    ll a, b;
    cin >> a >> b;
    if(a % b == 0) cout << 0 << endl;
    else {
        int k = a % b;
        k = b - k;
        cout << k << endl;
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