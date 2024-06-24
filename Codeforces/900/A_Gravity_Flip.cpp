/*
//  A. Gravity Flip


// Observations: 
    * We have given an array that contains the box & initially all the box has facing gravity downwards.
    * When the gravity pulls to right we need to find the new arrangement of box.
    * If we carefully observe, when the gravity pulls to right, the maximum height will be formed to right most..
    * if we sort all the boxes then we have to final configurations..

// Intrusion: 
    * We need to sort all the element of an array, as it will make the final configurations..
    * We can use quick sort for sorting, will take O(nlogn) complexity.

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
    cin >>n;
    vector<int> arr(n);
    arrInp;
    sort(arr.begin(), arr.end());
    for(auto i : arr) cout << i << " ";
    el;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}