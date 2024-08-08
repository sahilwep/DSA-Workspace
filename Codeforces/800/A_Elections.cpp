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

    * we are adding 1 to every value after subtraction, because that is what they need to win...

0 3 4
Answer: 5 2 0

0 5 5
Answer: 6 1 1



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
    long a, b, c;
    cin >> a >> b >> c;
    if(a == b && b == c){
        cout << "1 1 1" << endl;
        return;
    }
    long mx = max(a, max(b, c));

    bool tie = ((a == mx) + (b == mx) + (c == mx) > 1); // used to find how many value are equal to maxValue, if there wll more than two value, we store 1, else 0
    
    // compare & print the results:
    long u = (a == mx) ? tie : (mx + 1 - a);
    long v = (b == mx) ? tie : (mx + 1 - b);
    long w = (c == mx) ? tie : (mx + 1 - c);
    cout << u << " " << v << " " << w << endl;
    
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}