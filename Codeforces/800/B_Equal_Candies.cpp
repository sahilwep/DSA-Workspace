/*
//  B. Equal Candies


// Observations: 
    * Normal Condition we have to look about...

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
    cin >> arr[0];
    int minVal = arr[0];
    bool flag = false;
    for(int i=1;i<n;i++){
        cin >> arr[i];
        if(arr[i] < minVal){
            minVal = arr[i];
        }
        if(arr[i] != arr[i-1])  flag = true;
    }
    if(!flag){
        cout << 0 << endl;
    }else {
        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt = cnt +  arr[i] - minVal;
        }
        cout << cnt << endl;
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