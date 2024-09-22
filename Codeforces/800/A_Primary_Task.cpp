/*

//  A. Primary Task

//  Observations:
    * We are given string, we need to find for which string the exponential sign is missed.


*/

#include<bits/stdc++.h>
#include<algorithm>
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
#define mod 1000000007

void solve(){
    string s;
    cin >> s;
    int n = s.size();

    if(n >= 3 && s[0] == '1' && s[1] == '0'){
        if((n == 3 && s[2] > '1') || (n > 3 && s[2] > '0' )){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    else{
        cout << "NO" << endl;
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