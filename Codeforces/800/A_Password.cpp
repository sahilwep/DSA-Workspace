/*

//  A. Password


// Observations: 
    * monocarp has forgotten his password, password contains 4 digit from 0-9 (Note that it can start with 0)
    * Password has exactly two different digits.
    * each of these digits exactly appears two times in password
    * we have to calculate the different sequence of 4 digits that could be the password for the for monocarp.
    * Password should follow all the given constrains:


// Test-case: 
    * we are given n different integer that he remember, that were not used in password:

// Key Observations: 
    * Password is of 4 digits
    * It contains exactly two different digits, each appearing twice.
    * Edge case: When all digits are excluded

// Intrusion: 
    * First we can choose two digits that appear in password: C(10-n, 2)
        * Since n are prohibited, the remaining 10 - n are allowed
    * Second choose position that will be taken by the first one: C(4, 2)
    * The answer is product of these two


// Example: 
    n = 8
    -> 0 1 2 4 5 6 8 9

            left values: 3, 7
            Possible combinations: 
                    3377, 3737, 7373, 3773, 7337, 7733
            
            // According to the observations: 
                    C(10-8, 2) * C(4, 2)
                    C(2, 2) * C(4, 2)
                    1 * 6 => 6

    n = 1
    -> 8
            left values: 0 1 2 3 4 5 6 7 9


                we are left with 9 values: 
                out of which we have to arrange it in 4 possible position.

                C(10-1, 2) * c(4, 2)
                36 * 6 => 216


// Permutations & Combinations: 
    * permutations: nPr => n!/(n-r)!
    * Combinations: nCr => n!/[(n-r)!*r!]



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

ll fact(ll x){
    ll res = 1;
    for(ll i=1;i<=x;i++){
        res = res * i;
    }
    return res;
}

ll C(ll x, ll y){
    return fact(x) / (fact(x - y) * fact(y));
}

void solve(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
    }

    cout << C(10 - n, 2) * C(4, 2) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}