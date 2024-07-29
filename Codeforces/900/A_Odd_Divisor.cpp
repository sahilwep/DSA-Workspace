/*

//  A. Odd Divisor

// Observation:
    * we are given integer n, we have to check if n has odd divisor, 
    * grater than one(does there exist such number x(x > 1) that n is divisible by x and x is odd)

    * If n is odd -> YES, 3, 5, 7, 9, 11...
    * if n is even:
        Prime factorizations: 2^a * 3^b * 5^c * 7^d * 11^e...
            power >= 0
            * Observations:  all the prime factors except 2 are odd!!
            * after removing all the 2s ; if i am left with some num > 1 then we have odd divisors
            * whether the number has prime factor apart from only 2, then it's odd divisor.
            * any of these prime factors apart from 2, at least have power 1, because if all has power 0, then it's not have prime factors..
                3^b * 5^c * 7^d * 11^e...
                * because if power is 0, it will make that number 1, & we have constrains not to choose 1...
                * if atleast one have power 1 atleast, we will have odd prime factors..
            * Conclusion: 
                * we can't insert 2^a, value, because number should not be power of 2..
                * number should be in range 3^b * 5^c * 7^d * 11^e...
                    * Power should be atleast 1, means (power >= 1)
            * So we can say we have to check whether the number is of power of 2 or not?
                if(2 ^ num) : "NO"
                else : "YES"

// Bit-magic:
    * how to check any number is of power of 2 or not?
    * we just have to do and operations b/w ((num &(num-1)) == 0) if it's 0, means "NO" : "YES"

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
    ll n;
    cin >> n;
    if((n & (n-1)) == 0) cout << "NO" << endl;
    else cout << "YES" << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}