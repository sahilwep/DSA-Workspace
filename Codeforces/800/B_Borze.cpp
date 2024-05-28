/*
//  B. Borze


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
    string res = "";
    for(int i=0;i<s.size();i++){
        if(s[i] == '-' && s[i+1] == '-'){
            res += '2';
            i += 1;
        }else if(s[i] == '-' && s[i+1] == '.'){
            res += '1';
            i += 1;
        }else if(s[i] == '.'){
            res += '0';
        }
    }
    cout << res << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}