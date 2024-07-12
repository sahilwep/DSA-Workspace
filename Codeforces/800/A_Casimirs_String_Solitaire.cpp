/*

//  A. Casimir's String Solitaire

// Observations: 
    * Combinations are :  A & B, B & C
    * IF we carefully observe, we are deleting some characters in string...
    * with A, we are deleting B
    * with C, we are deleting B
    * means we need to count all the characters..
    * If B = A + C, we say "YES" : else we say "NO"



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
    string s;
    cin >> s;
    ll a(0), b(0), c(0);
    for(auto i : s){
        a += (i == 'A');
        b += (i == 'B');
        c += (i == 'C');
    }
    
    cout << ((b == a + c) ? "YES" : "NO") << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}