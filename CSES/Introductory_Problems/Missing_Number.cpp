/*
//  Missing Number

// Observations:
    * We need to find the missing number from 1 to n..
    * Input will contains n-1 numbers.
    * Constrains: 
        * 2 <= n <= 2*10^5

// Intrusion: 
    * We can hash all the value..
    * once we hashed all the value, we can check which index has 0 value, means which element is not hashed...
    * then we can return that index...

// Complexity: 
    * O(n)

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
    vector<int> arr(n);
    for(int i=0;i<n-1;i++)  cin >> arr[i];   // input n-1 elements
    
    // Using hashing: 
    vector<int> hash(n+1, 0); // initializing vector of size n+1, & default value '0'
    for(int i=0;i<n-1;i++){
        hash[arr[i]]++;     // hashed array..
    }
    // traversing to hash, to find hte 
    for(int i=1;i<n+1;i++){
        if(hash[i] == 0){
            cout << i << endl;
        }
    }
}

int main(){
    int t = 1;     // Change the testcase according to question...

    
    while(t--){
        solve();
    }
    
    return 0;
}