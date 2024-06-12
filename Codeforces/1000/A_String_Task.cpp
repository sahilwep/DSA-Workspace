/*
//  A. String Task


// Observations: 
    * We have to remove all the vowel from the string & for the each consonant, we have to print it with '.'

// ASCII

a = 65
A = 97


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
    string s;
    cin >> s;
    string res = "";
    for(int i=0;i<s.size();i++){
        char ch = s[i];
        if(int(ch) < 96)  ch = ch - 'A' + 'a';
        if(ch == 'a' || ch == 'o' || ch == 'y' || ch == 'e' || ch == 'u' || ch == 'i') continue;
        else{
            res += '.';
            res += ch;
        }
    }
    cout << res << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}