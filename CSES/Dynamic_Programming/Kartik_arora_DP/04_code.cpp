/*

//  Dice Combinations: https://cses.fi/problemset/task/1633

// Observations: 
    * We have to count the number of ways to construct sum n by throwing dice one or more time.

// Example:
    n = 3, there are 4 ways:
        1 + 1 + 1
        1 + 2
        2 + 1
        3

// Intrusion: 

            1. dp(i): No of valid ways of throwing dice such that sum = i
            2. Building a recurrence: 
                
                dp(n) = dp(i-1) + dp(i-2) + dp(i-3) +....+ dp(i-6)
                dp(n) = summation of number from x = 1 to 6: dp(i - x)
            
            3. Base case:
                1. dp(0) = 1
                2. dp of some negative numbers, let say we have number 3, we we throw 4, which is not suitable in this case.


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
#define mod 1000000007

void solve(){
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 1; // -> base case
    for(int i=1;i<n+1;i++){
        for(int x=1;x<=6;x++){
            if(x > i) break;    // when x i grater than i -> base case
            dp[i] = (dp[i] + dp[i-x]) % mod;
        }
    }

    cout << dp[n];
}


int main(){
    int t = 1;     // Change the testcase according to question...
    
    while(t--){
        solve();
    }
    
    return 0;
}