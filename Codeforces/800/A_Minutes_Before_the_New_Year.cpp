/*
//  A. Minutes Before the New Year

// Observations: 
    * We have to check how much minute remaining to become new year...
    * We have given current time, we have to check when it will become 00:00-> means new year day..
    * We can convert remaining hours in minute & add it to the remaining minute..


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
    int h, m;
    cin >> h >> m;
    int hourMin = (23 - h) * 60;
    int minRem = 60 - m;
    cout << hourMin + minRem << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}