/*
//  A. Bachgold Problem


// Observations: 
    * IF we carefully observe this question, we have to return the prime numbers that makes the sum n.
    * also we have to return how many prime numbers are there...

    * If we observe any number which broken into prime numbers is:
            5 -> 2, 3   -> all primes...    -> 2 digits
            6 -> 2, 2, 2    --> all primes...   -> 3 digits
            ..
            ..
            11 -> 2, 2, 2, 2, 3 -> all primes...     -> 5 digits
            12 -> 2, 2, 2, 2, 2, 2 -> all primes..      -> 6 digits
            ..
            ..
            21 -> 2, 2, 2, 2, 2, 2, 2, 2, 2, 3 -> all primes..          -> 10 digits
            22 -> 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, -> all primes...         -> 11 digits
        
    * Means we can say we only have to return 2 & 3...
    * Also if we carefully observe for even numbers, we have to return only 2
    * For odd numbers we have to return one 3, & rest 2's...
    * the number of digits we have to print is (n/2)

    * Constrains: 2 <= n <= 10^5


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

// return prime: 
// bool isPrime(int n){
//     if(n == 1) return false;
//     if(n == 2 || n == 3) return true;
//     if(n % 2 == 0 || n % 3 == 0) return false;
//     for(int i=5;i*i<=n;i+=6){
//         if(n % i == 0 || n % (i+2) == 0) return false;
//     }
//     return true;
// }

void solve(){
    int n;
    cin >> n;
    if(n % 2 == 0){
        cout << n/2 << endl;
        for(int i=1;i<=n/2;i++) cout << 2 << " ";
    }
    else{
        cout << n/2 << endl;
        for(int i=1;i<n/2;i++) cout << 2 <<" ";
        cout << 3 << " ";
    }
    el;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}