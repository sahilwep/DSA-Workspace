/*
//  A. Maximum Increase


// Observations: 
    * We have to count the longest increasing sub-sequence of an array..

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
    vector<int> arr(n);
    for(int i=0;i<arr.size();i++) cin >> arr[i];
    int maxSize = 1;
    int cnt = 1;
    for(int i=1;i<arr.size();i++){
        if(arr[i] > arr[i-1]){
            cnt++;
        }else{
            cnt = 1;
        }
        maxSize = max(cnt, maxSize);
    }
    cout << maxSize << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}