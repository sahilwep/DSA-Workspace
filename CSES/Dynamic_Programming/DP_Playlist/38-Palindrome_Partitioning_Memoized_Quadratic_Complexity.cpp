/*

// Palindrome Partitioning Memoized Quadratic Complexity


// Intrusion: 
    * Idea is to precompute the palindrome sequence into memo table, which will take O(n^2) complexity.
    * Then, Palindrome Partition function will take O(n^2) complexity to compute the results..
    * Overall Time Complexity = O(n^2)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Function to precompute Palindrome:
void precomputePalindromes(const string &s, vector<vector<int> > &p) {
    int n = s.size();

    // Single character substrings are palindromes
    for (int i = 0; i < n; i++) {
        p[i][i] = true;
    }

    // Two character palindromes:
    for (int i = 0; i < n - 1; i++) {
        p[i][i + 1] = (s[i] == s[i + 1]);   // if two adjacent characters are same, we will store true in palindrome memo table.
    }

    // General case for substrings longer than 2
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            p[i][j] = (s[i] == s[j]) && p[i + 1][j - 1];    // Comparing first pointers & last pointers, and based on that we are storing true only..
        }
    }
}


int palPart(const string &s, int i, int j, vector<vector<int> > &t, vector<vector<int> > &p) {
    if (i >= j) return 0;
    if (p[i][j]) return 0;  // No cuts needed if s[i...j] is already a palindrome
    if (t[i][j] != -1) return t[i][j];

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++) {
        // checking values from Palindrome memo table:
        if (p[i][k]) {  // Only partition if s[i...k] is a palindrome
            int right = (t[k + 1][j] != -1) ? t[k + 1][j] : palPart(s, k + 1, j, t, p);
            ans = min(ans, 1 + right);
        }
    }

    return t[i][j] = ans;
}



void solve(){
    // Inputs:
    string s;
    cin >> s;

    // Initialization & Pre-computation
    int n = s.size();
    vector<vector<int> > t(n+1, vector<int> (n+1, -1));
    vector<vector<int> > p(n+1, vector<int> (n+1, -1));
    
    precomputePalindromes(s, p);  // Precompute all palindromic substrings
    
    cout << palPart(s, 0, n - 1, t, p) << endl;

}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}