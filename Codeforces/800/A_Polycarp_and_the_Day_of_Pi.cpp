/*

//  A. Polycarp and the Day of Pi

// Observations; 
    * we have max constrains size is 30,
    * Also we have been given 30 characters correct PI values "314159265358979323846264338327"
    * We just have to match each characters...

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
    string res = "314159265358979323846264338327";  // as it is given in test case & maximum n will be upto 30 characters..
    int cnt = 0;
    for(int i=0;i<res.size();i++){
        if(s[i] == res[i]) cnt++;
        else break;
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