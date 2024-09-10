/*

//  B. Symmetric Encoding


// Observations: 
    * We are given string s, which encoded in certain arrangements:
        * First we have use auxilary array to store the character in alphabet order,
        * Encoding start with character replaced with symmetric arrangement elements.

// Example Observations: 

    // s = codeforces   -> serofedsoc

            * Sorted: ccdeefoors  -> Contains Duplicates
            * Remove Duplicates: cdefors
            * Hashed:
                c -> s
                d -> r
                e -> o
                f -> f
                s -> c
                r -> d
                o -> e
                f -> f

            * replacing each character from hashed map:

                Original:   codeforces
                Encrypted:  serofedsoc


*/

#include<bits/stdc++.h>
#include<string>
#include<unordered_map>
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

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    // using set, to store unique character in sorted order from string.
    set<char> st;
    for(auto i : s){
        st.insert(i);
    }
    // transferring element from set to string.
    string s1 = "";
    for(auto i : st){
        s1 += i;
    }

    // Using unordered_map to store hash the corresponding characters..
    unordered_map<char, char> mp;
    for(int i=0;i<s1.size();i++){
        mp.insert(make_pair(s1[i], s1[s1.size()-1-i]));
    }

    // Finally printing the result:
    string res = "";
    for(int i=0;i<s.size();i++){
        res += mp[s[i]];
    }
    
    cout << res << "\n";
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}