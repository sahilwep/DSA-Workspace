/*
//  A. Ultra-Fast Mathematician


// Observations: 
    * the same value will be the "0", weather it is 0 or 1,
    * the different value will be 1

Input: 
    1010100
    0100101
Output: 
    1110001

Explanation: 
    * We have XOR Operations: 

        A  B  |   X
        ------|----
        0  0  |   0
        1  0  |   1
        0  1  |   1
        1  1  |   0


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
#define SQ(a) (a)*(a)



void solve(){
    string s, p;
    cin >> s >> p;
    string res;
    for(int i=0;i<s.size();i++){
        if(s[i] != p[i]){
           res += "1"; 
        } else {
            res += "0";
        }
    }
    cout << res << endl;
    
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}