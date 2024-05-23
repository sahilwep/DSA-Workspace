/*
//  A. Vasya the Hipster

// Observations: 
    * the unique pair will always will be the less number b/w red & blue
    * the remaining / 2 will be the same pair...


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
    int blue, red;
    cin >> blue >> red;
    int uniquePair = min(blue, red);
    int remainingPair = max(blue, red);
    int samePair = (remainingPair - uniquePair)/2;
    cout << uniquePair << " " << samePair << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}