/*
//  A. Short Substrings



// Observations: 
    * as per the questions:
        * If a = "abac", it become a = "abbaac"
        * substring operations on "abac" makes -> "ab", "ba", "ac" -> "abbaac"
        * If we observe carefully: first & last character remains same...
        * only the character from index 1 to n-2 get duplicated..

Input: 
    abbaac
    ac
    bccddaaf
    zzzzzzzzzz
Output: 
    abac
    ac
    bcdaf
    zzzzzz

Explanations: 
    bccddaaf -> "bc", "cd", "da", "af"      -> one form of observing the data...
             -> 'b', "cc", "dd", "aa", 'f'  -> second form of observing the data...
             ->  'b', 'c', 'd', 'a', 'f'    -> removing duplicate from index 1 to n-2...
             -> final : res = "bcdaf"

// Intrusion: 
    * We can make string "res" with first char as s[0] & last char as s[n-1]
    * In between we just iterate on original string & by getting duplicate value we insert one element..
    * We increment it by 2, so that our two same consecutive will be change..

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
    string res;
    res += s[0];
    for(int i=2;i<s.size()-1;i++){
        if(s[i] == s[i-1]){
            res += s[i];
            i++;
        }else{
            res += s[i];
        }
    }
    res += s[s.size()-1];
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