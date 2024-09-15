/*

//  B. Turtle Math: Fast Three Task

//  Observations: 




*/

#include<bits/stdc++.h>
#include<algorithm>
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
#define mod 1000000007


void solve(){
    int n;
    cin >> n;
    int sum = 0;
    map<ll, ll> mp;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        mp[k%3]++;
        sum += k;
    }
    
    if(sum % 3 == 0){
        cout << 0 << endl;
    }
    else if(sum % 3 == 2 || (sum % 3 == 1) && mp[1]){
        cout << 1 << endl;
    }else{
        cout << 2 << endl;
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