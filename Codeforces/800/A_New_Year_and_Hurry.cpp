/*
//  A. New Year and Hurry


// Observations: 
    * We are at : 20:00, & we have to make it till 23:59....
    * means, we only have 4 hrs left, means 240 minute....
    * Every question has taking i*5 minutes to complete...

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
    int n, l;
    cin >> n >> l;  
    int k = 240 - l;    // subtract to find the left timing to solve questions...
    int solve = 0;  // this is used to compute the operations of solving questions..
    int cnt = 0;    
    for(int i=1;i<=n;i++){
        solve = solve + i*5;    // at every iterations, we multiply with 5, & add with previous result...
        if(solve > k) break;    // condition when solving taking more than the travel minute..
        cnt++;  // increase questions solve counter
    }
    cout << cnt << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}