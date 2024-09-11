/*

//  A. Cards

// Observations: 
    * We are given string s, & which was originally arrange in binary number, like "oneonezero", but it is shuffle now,
    * We have to recover the original number that was in binary.
    * Given constrains that there were maximum one

// Example: 
    Input: n = 10  s = nznooeeoer
    Output: 1 1 0
        one one zero will be extracted from this string.


// Key Observations: 
    * In one & zero, there are 'n' & 'z' which are unique in both the string.
    * All we have to count the occurrence of these character, & then generate the binary.


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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int one = 0, zero = 0;
    for(auto i : s){
        if(i == 'z') zero++;
        if(i == 'n') one++;
    }
    
    // generate binary:
    for(int i=0;i<one;i++) cout << 1 << " ";
    for(int i=0;i<zero;i++) cout << 0 << " ";
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