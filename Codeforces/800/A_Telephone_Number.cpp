/*

//  A. Telephone Number

//  Observations: 
    * We are given a string, & we have to find whether that string is suitable for phone number or not?
    * Condition for Phone number: 
        * phone number should start with 8
        * it should atleast contains 11 digits.
    * We are allowed to remove some character from string.



*/

#include<bits/stdc++.h>
#include<algorithm>
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
#define mod 1000000007

void solve(){   
    int n;
    cin >>n;
    string s;
    cin >> s;
    int i = 0;  // count the first occurrence of '8' in string
    for(i;i<n;i++){
        if(s[i] == '8') break;
    }
    // subtracting it from size will give the remaining size of string phone number
    int val = n - i ;
    // cout << val << endl;
    (val >= 11) ? cout << "YES" : cout << "NO";
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