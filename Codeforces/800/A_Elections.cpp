/*
//  A. Elections

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
    long a, b, c;
    cin >> a >> b >> c;
    long mx = (a > b) ? a : b; mx = (mx > c) ? mx : c;
    bool tie = (((a == mx) + (b == mx) + (c == mx)) > 1);
    long u = (a == mx) ? tie : (mx + 1 - a);
    long v = (b == mx) ? tie : (mx + 1 - b);
    long w = (c == mx) ? tie : (mx + 1 - c);
    cout << u << " " << v << " " << w << endl;
    
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}