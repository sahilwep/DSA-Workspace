/*
//  A. Soccer

// Observations: 
    * If we carefully observe the test-cases when x1 > y1 && x2 > y2 || x1 < y1 && x2 < y2 -> print "YES" : else "NO"
    

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

bool istrue(int x1, int y1, int x2, int y2){
    return abs(x2 - y2) == abs(x1 - y1);
}

void solve(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    if(x1 < y1 && x2 < y2 || x1 > y1 && y2 < x2) cout << "YES"  << endl;
    else cout << "NO" << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}