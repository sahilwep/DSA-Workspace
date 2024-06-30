/*
//  B. Blank Space

// Observations: 
    * we need to find the contigious '0' series..



*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef size_t s_t;  // use during string traversal
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
    int n;
    cin >> n;
    int arr[n];
    arrInp;
    int res = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 0) cnt++;
        else cnt = 0;
        res = max(res, cnt);
    }
    cout << res <<endl;
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}