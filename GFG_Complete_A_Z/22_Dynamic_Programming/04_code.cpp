/*

// Longest Common Subsequence (Part 1)

// Observations: 
    * We are given two string, & we need to find the common subsequence

// Example: 
    I/p:
        s1 = "ABCDGH"
        s2 = "AEDFHR"
    O/p: 3      -> ADH
    
    I/p:
        s1 = "AGGTAB"
        s2 = "GXTXAYB"
    O/p: 4      -> GTAB

    I/p:
        s1 = "XYZ"
        s2 = "XYZ"
    O/p: 3      -> XYZ

    I/p:
        s1 = "ABC"
        s2 = "XY"
    O/p: 0      -> "" empty sequence of both the string is same.


// Substring & Subsequence: 
    * Substring: we need to pick contigious characters from string.
    * Subsequence: we need to pick some character in same order that they appear
        * NOTE: In a string of length n, there can be 2^n possible subsequence.
        * Example: 
            Subsequence of "CDA"
                "", "C", "D", "A", "CD", "DA", "CA", "CDA"
                
            Subsequence of "DBA"
                "", "D", "B", "A", "DB", "BA", "DA", "DBA"


// Intrusion:
    * 

*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int lcs(string s1, string s2, int n, int m){
    int lCommon = 0;
    for(int i=0;i<n;i++){
        int ptr = i;
        int cnt = 0;
        for(int j=0;j<m && ptr < n;j++){
            if(s1[ptr] == s2[j]){
                ptr++;
                cnt++;
            }
        }
        lCommon = max(cnt, lCommon);
    }

    return lCommon;
}

void solve(){
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;

    cout << lcs(s1, s2, n, m) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}