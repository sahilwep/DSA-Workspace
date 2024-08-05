/*

//  A. Ilya and Bank Account

// Observations: 
    * we are given n that is current balance of an account..
    * We can remove one digit from last or 1 from before last..
    * We have to remove one digit so that the balance is as maximum as possible in positive...

// Intrusion: 
    * for removal of last digit: n / 10
        n = 123     -> 12
    * for removal of second last digit: n / 100 * 10 + n % 10
        n = 123 
                    n/100 * 10 + (n % 10)
                    (1) * 10 + (3)
                    100 + 3
                    103


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
    int n;
    cin >> n;

    // we have to remove last or second last: 
    if(n >= 0){
        cout << n << endl;
        return;
    }
    // when we have negative number: 
    else{
        // we have two operations to perform...
        int first = n / 10; // removing last digit
        // removing second last digit.
        int second = (n / 100) * 10 + (n % 10);
        cout << max(first, second) << endl;
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