/*
//  A. Yes-Yes?

// Observations: 
    * We are given a string that we have to find whether it's match the given condition or not?
    * given string is the part of combinations "YesYesYes...."


// Key Observations: 
    * If we carefully observe the patter of given testcase: combination goes "YesYesYesYes...Yes"
    * So, we have to find the substring in this given combinations.
    * As given Constrains: 1 <= s <= 50
    * patterns we have to find from "Yes"
    * If we generate 18*"Yes" which falls in constrains
    * If we match the the given string in this generated string we can return "Yes" if we found.

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
    string s;
    cin >> s;
    string match = "";
    for(int i=0;i<18;i++){
        match += "Yes";
    }

    if(match.find(s) != string::npos){
        cout << "YES";
    }else{
        cout << "NO";
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