/*
//  A. Expression


// Observations: 
    * We just have to perform every possible operations that can perform on (a, b, c) by '*' and '+'
    * All the possible operations are given in constrains...


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
    int a, b, c;
    cin >> a >> b >> c;
    int res = 0;
    res = max((a + b + c), res);
    res = max(((a + b) * c), res);
    res = max((a * (b + c)), res);
    res = max((a * b * c), res);
    
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