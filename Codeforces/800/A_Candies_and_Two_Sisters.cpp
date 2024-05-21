/*
//  A. Candies and Two Sisters

// Constrains: 
    * There are n candies, & we have to divide among X & Y, 
    * we have to divide the candies, in such a ways that x < y  & x + y = n

// Observations: 
    * If we observe for odd number of candies, we get our constrains satisfies by (n/2)
    * For even number of candies, we have to do ((n-1) / 2)

1, 2 == 0

3 => 1 ways n/2
4 => 1 ways (n-1)/2
5 => 2 ways n/2
6 => 2 ways (n-1)/2
7 => 3 ways n/2
8 => 3 ways (n-1)/2
9 => 4 ways n/2
10 => 4 ways (n-1)/2

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



void solve(){
    int n;
    cin >> n;
    int cnt = 0;
    if(n == 1 || n == 2){
        cout << 0 << endl;
        return;
    }
    if(n % 2 == 0){
        cout << (n-1) / 2 << endl;
    } else {
        cout << n / 2 << endl;
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