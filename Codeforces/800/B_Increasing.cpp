/*

//  B. Increasing



// Observations: 
    * get sort the array & match the conditions...


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
    int n;
    cin >> n;
    int arr[n];
    arrInp;
    if(n == 1){
        cout << "YES" << endl;
        return;
    }
    sort(arr, arr+n);
    for(int i=1;i<n;i++){
        if(arr[i] <= arr[i-1]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}