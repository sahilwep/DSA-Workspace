/*
//  A. Yet Another Two Integers Problem


6
5 5
13 42
18 4
1337 420
123456789 1000000000
100500 9000


a = 13, b = 42
swap => a = 42, b = 13
diff => a - b = 29
div => diff / 10 = 2;
mod => div % 10 = 2
(mod > 0) -> mod++ => 3


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
    int a, b;
    cin >> a >> b;
    if(b < a){
        swap(a, b);
    }
    ll sub = 0, sum = 0, div = 0, mod = 0;
    sub = b - a;
    div = sub / 10;
    mod = sub % 10;
    sum = div;
    if(mod > 0){
        sum++;
    }
    cout << sum  << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}