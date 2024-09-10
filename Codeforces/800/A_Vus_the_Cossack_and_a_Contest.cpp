/*
//  A. Vus the Cossack and a Contest

// Observations: 
    * There are n people, & We are given m pens & k notebook
    * We have to find whether we can distributes it among n people, we have to distribute atleast one pen & one notebook.

// Intrusion: 
    * We just have to check whether n is lesser than m & k or not?
    * If they are less than n, we can print "NO", else "YES"

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
    int n, m, k;
    cin >> n >> m >> k;
    if(m < n)   cout << "NO\n";
    else if(k < n)  cout << "NO\n";
    else cout << "YES\n";
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}