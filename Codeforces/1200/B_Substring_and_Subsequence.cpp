/*
//  B. Substring and Subsequence

// Observations: 
    * we are given two string a & b in lowercase.
    * We have to find minimum possible length of string that contains a as substring & b is subsequence
    * Subsequence: a substring of string which can obtained by removing several(possibly zero) characters from original string.
        * Example: s = abac
           a, b, c, ab, aa, ac, ba, bc, abc, aac, bac and abac
    * Substring: a substring is contigious sequence of string.
        * Example: s = abac
           a, b, c, ab, ba, ac, aba, bac and abac


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

bool isStr(string s, char c){
    for(int i=0;i<s.size();i++){
        if(s[i] == c){
            return 1;
        }
    }
    return 0;
}


void solve(){
    string s1, s2;
    cin >> s2 >> s2;
    string res = s1;
    for(int i=0;i<s2.size();i++){
        bool isFind = isStr(s1, s2[i]);
        if(!isFind){
            res += s2[i];
        } 
    }
    cout << res.size() << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}