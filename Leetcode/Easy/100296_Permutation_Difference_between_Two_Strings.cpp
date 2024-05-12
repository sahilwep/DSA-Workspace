/*
//  100296. Permutation Difference between Two Strings




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
    string s, t;
    cin >> s >> t;
    int res = 0;
    for(int i =0;i<s.size();i++){
        for(int j=0;j<t.size();j++){
            if(s[i] == t[j]){
                res = res +  abs(i - j);
            }
        }
    }
    cout << res << endl;
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}