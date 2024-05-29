/*
//  A. Division?




For Division 1: 1900≤rating
For Division 2: 1600≤rating≤1899
For Division 3: 1400≤rating≤1599
For Division 4: rating≤1399


*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F firsts
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);

// For Division 1: 1900≤rating
// For Division 2: 1600≤rating≤1899
// For Division 3: 1400≤rating≤1599
// For Division 4: rating≤1399

void solve(){
    int n;
    cin >> n;
    if(n >= 1900) cout << "Division 1" << endl;
    else if(n <= 1899 && n >= 1600) cout << "Division 2" << endl;
    else if(n <= 1599 && n >= 1400) cout << "Division 3" << endl;
    else if(n <= 1399) cout << "Division 4" << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}