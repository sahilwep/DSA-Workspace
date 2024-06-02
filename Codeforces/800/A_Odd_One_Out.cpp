/*
//  A. Odd One Out

// Intrusion: 
    * Using hashing in unordered map...

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
    for(int i=0;i<3;i++) cin >> arr[i];

    unordered_map<int, int> mp;
    for(int i=0;i<3;i++) mp[arr[i]]++;
    
    for(auto it = mp.begin();it != mp.end();it++){
        if(it->second == 1){
            cout << it->first << endl;
            break;
        }
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