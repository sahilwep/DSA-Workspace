/*
//  B. Triple

// Observations: 
    * we have to print that element that appears 3 times..

// Intrusion: 
    * we can use hashing..

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef size_t s_t;  // use during string traversal
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
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto i =mp.begin();i!=mp.end();i++){
        if(i->second >= 3){
            cout << i->first << endl;
            return;
        }
    }
    cout << -1 << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}