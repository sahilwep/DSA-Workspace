/*
//  A. Array Coloring


// Observations:
    * We have to color element's of array in such a way so that the sum of their parity should be same.
    * We can only use two colors to color them...

// Intrusion: 
    * as constrains: 
        2 <= n <= 50
        1 <= a(i) <= n
    * We are sure, that the size of array will minimum 2...
    * We have to color only with two colors...
    * If we carefully observe, when we sum up all the number, if it's even, then we can color them, because we will split them..
    * else if it's odd, we can't color them..
        * Example: 
            1 2 1   => sum is 4(sum), we can color 1's & 2, makes same parity
            1 2 3   => sum is 6(sum), we can color 1 & 2, & 3, makes same parity
            1 2 3 4 => sum is 10(sum), we can color 2 & 3, & 1 & 4, makes same parity
        * likewise, any number even or odd, if it's sum is even we can split into two..
        * if sum is odd, we can't split into tow..
        * Example: 
            1 2 3 1 => sum is 7(odd), There will alway be one element left to color, which makes different parity.
            1 2 3 4 5 => sum is 15(odd), here is same case will happen, you can make any possible combination, you can't fill it by two color, & the parity of sum will always be different.

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
    int arr[n];
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    (sum % 2 == 0) ? cout << "YES" : cout << "NO";
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