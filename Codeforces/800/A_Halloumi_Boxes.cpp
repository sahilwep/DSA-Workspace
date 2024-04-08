/*
//  A. Halloumi Boxes:      https://codeforces.com/problemset/problem/1903/A

* Constrains: 
    (1 <= k <= n<= 100)

* Here, we can at max reverse the k values to sort the array..
    * Let's forgot k for now, For sorting any array, we need at max 2 consecutive value to be compare,
    * We can say, We need 2 subarray window, then we can sort any array...
    * From this, conclusion is if (k >= 2), we can sort the values, doesn't matter how big k is, we only need k to be equal or grater than 2...
    * But for (k < 2), (i.e k == 1, as per the constrains..): 
    * There will be two case: 
            * elements are already sorted:
                * return true
            * elements are not sorted: 
                * return false, because as k=1, we can't swap two values to sort the array...
// TC : O(n)

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
#define arrOut for(int i=0;i<n;i++) cout << arr[i] << " ";
#define el cout << endl;
#define SQ(a) (a)*(a)



void solve(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    arrInp;
    // handel edge case for k == 1
    if(k == 1){
        int cnt =0;
        for(int i=1;i<n;i++){
            if(arr[i-1] > arr[i]){
                cnt++;
            }
        }
        (cnt > 0) ? cout << "No" << endl : cout << "Yes" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}