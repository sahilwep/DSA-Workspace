/*
//  A. Beautiful Year

// Observations: 
    * Constrains of input :  1000 <= y <= 9000

// Intrusion: 
    * We will increase the input till (10000), as input max be the 9000
    * while increasing the input we wil check each number by using func check()
    * this function will check that if our number contains unique element or not, & result accordingly..


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

// TC : O(1)
bool check(int n){
    // storing the hash value of digits
    int size = log10(n) + 1;
    int hash[10] = {0};
    while(n > 0){
        int ld = n % 10;
        hash[ld] += 1;
        n = n/10;
    }
    // check the hash value: 
    for(int i=0;i<10;i++){
        if(hash[i] > 1){
            return false;
        }
    }
    return true;
}

// TC : O(n)
void solve(){
    int n;
    cin >> n;
    while(n < 10000){
        n++;
        bool res = check(n);
        if(res == true){
            cout << n << endl;
            break;
        }
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