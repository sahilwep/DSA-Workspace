/*
//  B. Queue at the School

// Observations:

Input: 
    5 1
    BGGBG
output: 
    GBGGB
Explanation: 
    t = 1, every boy will let the girl behind them, come forward.
        B G G B G => G B G G B
        ---   ---


Input: 
    5 2
    BGGBG
output: 
    GBGGB
Explanation: 
    t = 1, every boy will let the girl behind them, come forward.
        B G G B G => G B G G B
        ---   ---
    t = 2
        G B G G B => G G B G B



// intrusion: 
    * t = times, represent how many times we have to perform all the operations..
    * n = size, of string.
    * perform the swapping operation, if we have G, behind B

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
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    for(int i=0;i<t;i++){
        for(int j=0;j<n-1;j++){
            if(s[j] == 'B' && s[j+1] == 'G') swap(s[j], s[j+1]), j++;
        }
    }
    cout << s << endl;
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}