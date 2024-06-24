/*
//  A. X Axis


// Observations: 
    * Straightforward operations..
    * We just have to follow the given condition & code it..

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
    int arr[3];
    for(int i=0;i<3;i++){
        cin >> arr[i];
    }
    sort(arr, arr+3);
    int mid = arr[1];
    cout <<  abs(arr[0] - mid) + abs(arr[1] - mid) + abs(arr[2] - mid) << endl;
 
}
 
int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}