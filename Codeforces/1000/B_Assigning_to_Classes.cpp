/*
//  B. Assigning to Classes

// Observations: 
    * IF we observe carefully, we need to get the median value from both the group...
        * Both group has equal number of strength of elements...
    * We are sure that odd & even values are same in numbers...
    * Means if we sort all the values, at the position (n & n-1) will have our middle value from both the groups, i.e odd & even groups...
    * means can fetch (n & n-1) index position value from 2*n size sorted array, & we will return the absolute of these two values difference values...

// Intrusion: 
    * take all the input values & sort them...
    * return abs(v[n-1] - v[n]);

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
    ll n;
    cin >> n;
    ll idx = 2*n;

    vector<ll> v;
    int a;
    for(int i=0;i<idx;i++){
        cin >> a;
        v.PB(a);
    }
    sort(v.begin(), v.end());
    
    cout << abs(v[n-1] - v[n]) << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}