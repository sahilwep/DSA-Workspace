/*

//  A. Ichihime and Triangle

// Observations: 
    * We are given a, b, c, d
    * We need to find three integer x, y, z, such that
        * a <= x <= b
        * b <= y <= c
        * c <= z <= d
    * There exist a triangle with a positive non-zero area & the length of it's sides are x, y and z


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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << b << " " << c  << " " << c << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}