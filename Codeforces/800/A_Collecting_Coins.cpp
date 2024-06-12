/*
//  A. Collecting Coins


// Observations: 
    * We have to divide among the 3 persons...
    * If we carefully observe we will find the pattern...
    * we have to make all elements equal to max value...
    * Then we can split remaining value among all..


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
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    int maxVal = max(a, max(b, c));
    int remVal = 0;
    remVal += (maxVal - a);
    remVal += (maxVal - b);
    remVal += (maxVal - c);
    int res = n - remVal;
    if(res < 0){
        cout << "NO" << endl;
    }else{
        // cout << res << endl;
        (res % 3 == 0) ? cout << "YES" << endl : cout << "NO" << endl;
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