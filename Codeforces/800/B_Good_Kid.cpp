/*
//  B. Good Kid




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
    int arr[n];
    int smallest = INT_MAX;
    int sIndex;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i] < smallest){
            smallest = arr[i];
            sIndex = i;
        }
    }
    ll res = smallest+1;
    for(int i=0;i<n;i++){
        if(i != sIndex){
            res = res * arr[i];
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