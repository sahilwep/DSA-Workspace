/*
//  A. Is your horseshoe on the other hoof?

// Observations: 
    * we have 4 dress, where we have to find how many value we need to make them all unique..

Input= => Output
    1 7 3 3 => here we need 1, to make all of them unique
    7 7 7 7 => here we need 3, to make all fo them unique.

    * we can store the frequency of each element into map, & then we can subtract the map size with 4.

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
    int n = 4;
    unordered_map<int, int> m;  // initialize to store the frequency.
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
        m[arr[i]]++;    // storing frequency.
    }
    cout << n-m.size() << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}