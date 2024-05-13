/*
//  A. Nearly Lucky Number


// we have to count the number of '4' & '7', if they are 4 or 7, then yes : else no

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
    int cnt = 0;
    for(auto i : s) if(i == '4' || i == '7') cnt++;
    if(cnt == 4 || cnt == 7) cout << "YES" << endl;
    else cout << "NO" << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}