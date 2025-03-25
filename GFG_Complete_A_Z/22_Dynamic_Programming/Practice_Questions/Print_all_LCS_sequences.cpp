/*

//  Print all LCS sequences

//  Problem Statement: 
    -> You are given two strings s and t. Now your task is to print all longest common sub-sequences in lexicographical order.
    -> Note -  A Sub-sequence is derived from another string by deleting some or none of the elements without changing the order of the remaining elements.

// Example: 
    Example 1:

        Input: s = abaaa, t = baabaca
        Output: aaaa abaa baaa
        Explanation - Length of lcs is 4, in lexicographical order they are aaaa, abaa, baaa

    Example 2:

        Input: s = aaa, t = a
        Output: a

// Observations: 
    -> From the given string, print all the longest common subsequence.

    // Naive BruteForce: 
        -> First get the lcs size & then again find the lcs using recursion & whenever our tempstring size equal to lcsSize store that sequence into set..
        -> at last sort the value..

    // BruteForce Backtracking:
        -> With "pass by reference the temp string" => we can use backtracking technique & solve the problem.

        

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BruteForce Backtracking: 
class Solution {
private: 
    int n, m;
    unordered_set<string> ans;
    vector<vector<int>> t;
    void solve(string s1, string s2, int n, int m, string &pat, int lcsSize) {
        // When we form lcs:
        if(pat.size() == lcsSize) {
            reverse(begin(pat), end(pat));
            ans.insert(pat);
            reverse(begin(pat), end(pat));
            return;
        }
        
        // base case
        if(n == 0 || m == 0) return;    
        
        
        if(s1[n-1] == s2[m-1]) {
            pat.push_back(s1[n-1]); // push it into list.
            solve(s1, s2, n-1, m-1, pat, lcsSize);    // pass new string.
            pat.pop_back(); // remove while backtracking
        }
        else {
            // check in dp table & then only move accordingly: prone unnecessary checks
            if(t[n-1][m] == t[n][m]) solve(s1, s2, n-1, m, pat, lcsSize);
            if(t[n][m-1] == t[n][m]) solve(s1, s2, n, m-1, pat, lcsSize);
        }
    }
public:
    vector<string> all_longest_common_subsequences(string s1, string s2) {
        
        // Compute LCS:
        n = s1.size(), m = s2.size();
        t.resize(n + 1, vector<int> (m + 1, 0));
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++) {
                if(s1[i-1] == s2[j-1]) t[i][j] = 1 + t[i-1][j-1];
                else t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        
        int lcsSize = t[n][m];
        
        string temp = "";
        
        solve(s1, s2, n, m, temp, lcsSize);     // function to generate all lcs
        
        vector<string> finalAns(begin(ans), end(ans));  // transfer strings from set to vector.
        sort(begin(finalAns), end(finalAns));   // sort lexigraphically 
        
        return finalAns;
    }
};


// Super Naive BruteForce: 
class Solution {
private: 
    set<string> ans;
    void solve(string s1, string s2, int n, int m, string pat, int lcsSize) {
        if(pat.size() == lcsSize) { // whenever we have the pattern size equal to lcs size => store that sequence.
            reverse(begin(pat), end(pat));
            ans.insert(pat);
            return;
        }
        
        if(n == 0 || m == 0) return;
        
        if(s1[n-1] == s2[m-1]) {
            pat.push_back(s2[m-1]);
            solve(s1, s2, n-1, m-1, pat, lcsSize);
        }
        else {
            solve(s1, s2, n-1, m, pat, lcsSize);
            solve(s1, s2, n, m-1, pat, lcsSize);
        }
    }
public:
    vector<string> all_longest_common_subsequences(string s1, string s2) {
        
        int n = s1.size(), m = s2.size();
        
        vector<vector<int>> t(n + 1, vector<int> (m + 1, 0));
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++) {
                if(s1[i-1] == s2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        
        int lcsSize = t[n][m];
        
        string temp = "";
        solve(s1, s2, n, m, temp, lcsSize);
        vector<string> finalAns(begin(ans), end(ans));
        sort(begin(finalAns), end(finalAns));
        
        return finalAns;
    }
};

