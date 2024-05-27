/*
//  A. Little Nikita



// Observation: 
    * Exactly after n move, can we build m move
    * if we leas move to build the tower, then we can't make it.
    * But if we have more move to make the tower, then we have to check that after exactly last of n move can be able to make or not..


15 10
at 10 we are able to make, but we have 5 move left.
5 (odd) -> we can't make

14 10
at 10 we are able to make, but we have 4 move left.
4 even -> we can make, as we go two up & two down..

15 11 
at 11 we are able to make, but we have 4 move left.
4 even -> we can make, as we go two up & two down..

14 11
at 11 we are able to make, but we have 3 move left.
3 odd -> we can't make

at all the possible odd & even condition, only even remaining number we can make...

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
    int n, m;
    cin >> n >> m;
    // if we have more move to build the tower,
    if(n >= m){
        if((n - m) % 2 == 0){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    // We know if we have less move to build the tower, then we can't make
    else {
        cout << "No" << endl;
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