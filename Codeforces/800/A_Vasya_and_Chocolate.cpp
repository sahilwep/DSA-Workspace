/*

//  A. Vasya and Chocolate  


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
#define mod 1000000007



void solve(){
    ll s, a, b, c;
    cin>>s>>a>>b>>c;

    ull ans,can_buy,div;

    div = can_buy = ans = 0;
    can_buy = s/c;
    div = can_buy/a;
    ans = (div*a) + (div*b);
    ans +=(can_buy%a);

    cout<<ans<<endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}