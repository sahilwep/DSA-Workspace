/*

//  A. Cipher Shifer

// Observations: 
    * we are given string s, we need to find the text of encoded cipher..
    * we are given certain rule of encoding cipher..
    * Example:
            abacabac -> ac

            aba cabac
            --- -----
             a    c

    * s[0] will always be the first the original text
    * whenever we encounter same text again, we will store that into result
    * and just after the found element we have original text again..
    * this is how we find all the text...



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
    vector<char> v;
    char c = s[0];  // first element will always be the original text
    for(int i=1;i<=n;i++){
        // if we found that text again, we have to store that character...
        if(s[i] == c){
            v.push_back(c);
            c = s[i+1]; // making next element be the next finding..
            i++;    // skipping that next element..
        }
    }

    for(auto i : v) cout << i;
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