/*
//  A. Goals of Victory




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
    int n;
    cin >> n;
    int res = 0;
    for(int i=0;i<n-1;i++){
        int k;
        cin >> k;
        res += k;
    }
    if(res < 0){
        res = res * (-1);   // making value positive
    } else {
        res = res * (-1);   // making value negative
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