/*
//  A. Codeforces Checking


// observations: 
    * We have to check specific character in string...
    * Easy..


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


bool findCh(char ch, string s){
    return 0;
}

void solve(){
    char ch;
    cin >> ch;
    string s = "codeforces";
    bool flag = false;
    for(int i=0;i<s.size();i++){
        if(s[i] == ch){
           flag = true;
        }
    }
    if(flag){
        cout << "YES" << endl;
    }else {
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