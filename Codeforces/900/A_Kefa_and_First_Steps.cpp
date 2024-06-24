/*
//  A. Kefa and First Steps

// Observations: 
    * We have to find the size of maximum non-descending sequence in an array.
    * straightforward implementations...

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
    arrInp;
    int solu = 1;   // if all the values fails to satisfies, we atleast have 1 element..
    int cnt = 1;    // initially count is 1
    for(int i=1;i<n;i++){
        // we have to count the number of increasing sequence..
        if(arr[i] >= arr[i-1]){
            cnt++;
        }
        // at any movement the increasing sequence condition fails, we make cnt = 1
        else{
            cnt = 1;    // making cnt = 1.
        }
        solu = max(cnt, solu);  // at the end of every iteration we will store the max value comparing the max(cnt , solu)
    }
    cout << solu << endl;
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}