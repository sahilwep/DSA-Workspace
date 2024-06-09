/*
//  A. Love Story


// Observations: 
    * simple string check..

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
    string s;
    cin >> s;
    int cnt = 0;
    if(s[0] != 'c') cnt++;
    if(s[1] != 'o') cnt++;
    if(s[2] != 'd') cnt++;
    if(s[3] != 'e') cnt++;
    if(s[4] != 'f') cnt++;
    if(s[5] != 'o') cnt++;
    if(s[6] != 'r') cnt++;
    if(s[7] != 'c') cnt++;
    if(s[8] != 'e') cnt++;
    if(s[9] != 's') cnt++;
    cout << cnt << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}