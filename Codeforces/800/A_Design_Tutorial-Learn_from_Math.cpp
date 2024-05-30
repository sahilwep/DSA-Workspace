/*
//  A. Design Tutorial: Learn from Math


// Observations: 
    * As per the question, we have to find two such number that are not prime & their sum makes the given number N.
    * We have to print those numbers

    Input: 
        12
        15
    Output: 
        4 8
        6 9
    Explanation: 
        12 -> 4 + 8, & (4, 8) are composite numbers
        15 -> 6 + 9, & (6, 9) are composite numbers

// Pattern: 
    * We need both number as not prime..
    * We can check both number for prime conditions..
    for 12 : 
        11 -> (11,  (12 % 11 = 1)), => true, false
        10 -> (10,  (12 % 10 = 2)), => false, true
        9 -> (9,  (12 % 9 = 3)), => false, true
        8 -> (8,  (12 % 8 = 4)), => false, false        -> condition for return...

// NOTE :  0 & 1 are neither prime and nor composite.


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

bool isPrime(int n){
    if(n <= 1) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5;i*i<=n;i=i+6){
        if(n % i == 0 || n % (i+2) == 0) return false;
    }
    return true;
}

void solve(){
    int n;
    cin >> n;
    // we can start from n-1 & go up till 0, in between we definitely found two composite number that makes sum as n
    for(int i=n-1;i>0;i--){
        // edge case when (n % i == 1), and we know "1" is neither prime or nor composite, so we have to skip this...
        if(n % i != 1){ 
            bool flag1 = isPrime(i);    // if this flag gets false, makes case for composite number
            bool flag2 = isPrime(n%i);  // if this flag gets false, makes case for composite number
            // if both numbers are composite, then we can print the some of them..
            if(flag1 == false && flag2 == false){
                cout << n % i << " " << i << endl;  // printing two composite number
                break;
            }
        }
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