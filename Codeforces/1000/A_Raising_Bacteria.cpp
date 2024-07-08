/*
//  A. Raising Bacteria

// Observations: 
    * If we carefully observe, bacteria split into half every night...
    * we will think reversely...
    * if we have the final number of bactria.
    * we can split it into two, if it's even..
    * else we can subtract 1 from it...

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
    int cnt = 0;
    while(n > 1){
        if(n % 2 == 0){
            n = n / 2 ;
        }
        else{
            n = n-1;
            cnt++;
        }
    }
    cout << (cnt + 1) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}