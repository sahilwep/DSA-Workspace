/*
//  A. Add Odd or Subtract Even


// Observations: 
    * In one move we can change a in following ways:
        * choose any positive odd integer x(x > 0) and replace a with a+x
        * choose any positive even integer y(y > 0) and replace a with a-y
    * You can perform as many such operations as we want...
    * we can choose same number x & y in different move...


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
    int a, b;
    cin >> a >> b;
    if(a == b){
        cout << 0 << endl;
        return;
    }
    int move = 1;
    // when we have to decrement the value...

    // when we have to increment the value...
    
    if(a > b && (a-b)%2 != 0){
        move++;
    }
    else if(b > a && (b % 2)%2==0){
        move++;
    }
    cout << move << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}