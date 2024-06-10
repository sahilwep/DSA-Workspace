/*
//  B. Honest Coach


// observations: 
    * we have to find the min diff of the number, if we carefully observe..

// Intrusion: 
    * We cna sort the array..
    * After sorting the array we can compare the {arr[i] - arr[i-1]}, & find the min of throughtout


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
    sort(arr.begin(), arr.end());
    int res = INT_MAX;
    for(int i=1;i<n;i++){
        int temp = arr[i] - arr[i-1];
        res = min(res, temp);
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