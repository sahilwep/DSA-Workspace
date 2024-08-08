/*
//  A. Elections

// Observations: 
    * The election that happens recently ended..
    * There where three candidate,
        * first candidate receives a votes..
        * Second candidate receives b votes..
        * third candidate receives c votes..
    * for each candidate to win how many votes they needed to win this elections..
    * We need to print how many votes are needed to win election for each candidate..

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
    ll a, b, c;
    cin >> a >> b >> c;
    ll maxVal = max(a, max(b, c));
    // if we a == max val, means a == 0, & we need to find the difference that we need to win for a, b, & c..
    // case when (a == b == c)
    if(a == b && b == c){
        cout << "1 1 1" << endl;
        return;
    }
    // when a maximum among all
    if(a == maxVal){
        // a == 0
        cout << 0 << " ";
        cout << a - b + 1 << " ";
        cout << a - c + 1 << " ";
    }
    // when b is maximum among all
    else if(b == maxVal){
        cout << b - a + 1 << " ";
        cout << 0 << " ";
        cout << b - c + 1 << " ";
    }
    // when c is maximum among all
    else if(c == maxVal){
        cout << c - a + 1 << " ";
        cout << c - b + 1 << " ";
        cout << 0 << " ";
    }
    el;
    // we are adding 1 to every value after subtraction, because that is what they need to win...
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}