/*

// A. Diverse Substring


// Observations:
    * we are given string s, & we need to find the substring of string s,

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
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool flag = 0;
    string ans;
    for(int i=0;i<n-1;i++){
        if(s[i] != s[i+1]){
            flag = 1;
            ans += s[i];
            ans += s[i+1];
            break;
        }
    }
    if(flag){
        cout << "YES" << endl;
        cout << ans << endl;
    } else{
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