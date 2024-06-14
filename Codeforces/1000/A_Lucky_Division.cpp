/*
//  A. Lucky Division


// Observations: 
    * First we have to check the occurrence of 4 & 7 throughout the number, if the number digits contains 4 & 7, we can say the number is lucky..
    * else for the condition where the the digits are not 4 & 7, so in this case we have to divide it by 4 or 7, if the division is successfully done for any of them, we return the result "YES" : else "NO"

// Constrains:
    1 <= n <= 1000

    * Max n = 4 digits, so we only have to check 2 digit's combinations of 4 & 7..


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
    int temp = n;
    int digits = log10(n) + 1;
    bool flag = false;
    while(temp > 0){
        int ld = temp % 10;
        if(ld != 4 && ld != 7)  flag = true;
        temp /= 10;
    }
    if(flag){
        // if the number can be divided by any of the lucky number
        if(n % 4 == 0 || n % 7 == 0 || n % 47 == 0 || n % 74 == 0) cout << "YES";
        else cout << "NO";

    }
    else cout << "YES";
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