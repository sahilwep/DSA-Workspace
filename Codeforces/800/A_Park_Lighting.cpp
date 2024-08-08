/*

//  A. Park Lighting

// Observations: 
    * we are given n, m matrix row & column length..
    * borders of the matrix grid is considered as streets..
    * we have to find the optimal way of arrangement of lights, so that we can 


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
    int n, m;
    cin >> n >> m;

    double a = n, b = m;
    ll ans = 0;
    ans = ceil((a*b) / 2);
    cout << ans << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}