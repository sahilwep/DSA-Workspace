/*

//  B. Keyboard Layouts

// Observations: 
    * We are given 26 size two string, that are matched in order, & we are also given string of random size, & we have to find the corresponding character from first string to second string, & print that answer.


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
    string a, b, c;
    cin >> a >> b >> c;
    map<char, char> mp;
    for(int i=0;i<26;i++){
        mp[a[i]] = b[i];
    }

    string res = "";
    for(int i=0;i<c.size();i++){
        char ch = c[i];
        // Upper & lower handling:
        // Upper case:
        if(ch >= 'A' && ch <= 'Z'){
            ch = ch - 'A' + 'a';    // First converting upper case into lower case, because in hashmap we have lower case value
            char val = mp[ch];      // finding into hashmap
            val = val - 'a' + 'A';  // Converting it into Upper case
            res += val;             // storing finally into result
        }
        // remaining lower case & numbers:
        // Numbers range:
        else if(ch >= '0' && ch <= '9'){
            // Storing directly into result
            res += ch;
        }
        // lowe case:
        else{
            // Finding & Storing directly
            char ch = mp[c[i]]; 
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