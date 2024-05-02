
/*
//  A. Soft Drinking

n  k  l  c   d   p   nl  np
3  4  5  10  8  100  3   1

Overall the friends have 4 * 5 = 20 milliliters of the drink, it is enough to make 20 / 3 = 6 toasts.
The limes are enough for 10 * 8 = 80 toasts and the salt is enough for 100 / 1 = 100 toasts. 
However, there are 3 friends in the group, so the answer is min(6, 80, 100) / 3 = 2.

    drinks = k * l;
    toast = drinks / nl;
    limes = c * d;
    salt = p / np;
    ans = min(toast, lines, salts) / n;

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
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int dri = (k*l);
    int tos = (dri/nl);
    int lim = (c*d);
    int sal = (p/np);
    int minVal = min(tos, lim);
    minVal = min(minVal, sal);
    cout << minVal/n << endl;
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}

