/*
A. Even Odd             https://codeforces.com/problemset/problem/318/A

// Example: 
    10 3
        n = 10

        1 3 5 7 9 2 4 6 8 10            ->  arrangement of all odd & evens are per question..

        Now if we split half n/2        -> 10/2 = 5 -> 

                        1 3 5 7 9 2 4 6 8 10
                        ---------5----------
                          odds        even
                * We can say if k is less than (n/2), then it's odd : else it's even..
                * (k * 2 - 1) : condition satisfies for all odd conditions..
                * ((k - (n+1)/2) * 2) : condition satisfies for all even condition..
                    * Here (k - (n+1)/2) will give us the position of that number
                    * then multiply with 2 will give us the exact number...

// TC : O(1)

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
    ll k, n;
    cin >> n >> k;
    // Odd case: 
    if(k <= (n+1)/2){
        cout << k * 2 - 1 << endl;
    }
    // even case:  
    else {
        cout << ((k - (n + 1)/2) * 2) << endl;
    }
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}