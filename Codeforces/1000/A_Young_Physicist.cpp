/*
//  A. Young Physicist

// Observations: 
    * We have to carefully observe, instead of observing horizontally, observe the sum values vertically..
    * for each iteration the value should be 0, then only we return "YES" : else we return "NO"

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
    int n;
    cin >> n;
    int x, y, z;
    int xSum = 0, ySum = 0, zSum = 0;
    for(int i=0;i<n;i++){
        cin >> x >> y >> z;
        xSum += x;
        ySum += y;
        zSum += z;
    }
    (xSum == 0 && ySum == 0 && zSum == 0) ? cout << "YES" : cout << "NO" ;
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