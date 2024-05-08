/*
//  A. Word


65  A 
90  Z 

97  a
122  z

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
#define SQ(a) (a)*(a)

void solve(){
    string s;
    cin >> s;
    int uCnt = 0;
    int lCnt = 0;
    for(int i=0;i<s.size();i++){
        if(int(s[i]) >= 65 && int(s[i]) <= 90){
            uCnt++;
        } else {
            lCnt++;
        }
    }
    if(uCnt > lCnt){
        for(int i=0;i<s.size();i++){
            // converting letters into uppercase:
            if(s[i] >= 97 && s[i] <= 122){
                s[i] = s[i] - 'a' + 'A';
            }
        }
    } else {
        for(int i=0;i<s.size();i++){
            // converting letters into lowercase
            if(s[i] >= 65 && s[i] <= 90){
                s[i] = s[i] - 'A' + 'a';
            }
        }
    }
    cout << s << endl;
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}