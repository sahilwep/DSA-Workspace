/*
//  A. Linear Keyboard

// Observations: 
    * we need to find the minimum time taken by the user to write the string s on keyword k.
    * We are given keyword k & string s, we have to find the absolute difference b/w the characters of string..
    
// Intrusion:
    * First we will hash all the character of string k in map.
    * Second we will fetch the position of string s from map..

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
    string k, s;
    cin >> k >> s;
    map<char, int> mp;

    for(int i=0;i<k.size();i++){
        mp[k[i]] = i + 1;   // hashing keywords characters sequentially
    }

    int ans = 0;
    for(int i=0;i+1<s.size();i++){
        // cout << mp[s[i]] << " " << mp[s[i+1]] << endl;
        ans += abs(mp[s[i]] - mp[s[i+1]]);
    }
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