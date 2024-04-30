/*
//  How Much Does Daytona Cost?         



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
    int n, k;
    cin >> n >> k;
    int arr[n];
    arrInp;
    bool flag = false;
    for(int i=0;i<n;i++){
        if(arr[i] == k){
            flag = true;
            break;
        }
    }
    if(!flag){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}