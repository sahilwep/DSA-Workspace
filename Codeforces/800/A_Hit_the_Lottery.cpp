/*
//  A. Hit the Lottery



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
    ll n;
    cin >> n;
    int cnt = 0;
    while(n != 0){
        if(n - 100 >= 0){
            n = n - 100;
            cnt++;
        } else if(n - 20 >= 0){
            n = n - 20;
            cnt++;
        } else if(n - 10 >= 0){
            n = n - 10;
            cnt++;
        } else if(n - 5 >= 0){
            n = n - 5;
            cnt++;
        } else if(n - 1 >= 0){
            n = n - 1;
            cnt++;
        }
    }
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