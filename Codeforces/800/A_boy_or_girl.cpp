/*
//  A Boy or Girl:          https://codeforces.com/problemset/problem/236/A


// Constrains: 
    small case: (97-112) range...j
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
#define arrOut for(int i=0;i<n;i++) cout << arr[i] ;
#define el cout << endl;
#define SQ(a) (a)*(a)


void solve(){
    string s;
    cin >> s;
    int hash[123] = {0};
    for(int i=0;i<s.size();i++){
        hash[s[i]] += 1;
    }
    int cnt = 0;
    for(int i=97;i<123;i++){
        if(hash[i] > 0){
            cnt++;
        }
    }
    (cnt % 2 == 0) ? cout << "CHAT WITH HER!" << endl : cout << "IGNORE HIM!" << endl; 
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}