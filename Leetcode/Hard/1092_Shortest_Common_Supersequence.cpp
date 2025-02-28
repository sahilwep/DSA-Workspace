/*

//  1092. Shortest Common Supersequence 

//  Problem Statement: 
    -> Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
    -> A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.


// Example:

    Example 1:

        Input: str1 = "abac", str2 = "cab"
        Output: "cabac"
        Explanation: 
        str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
        str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
        The answer provided is the shortest such string that satisfies these properties.

    Example 2:

        Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
        Output: "aaaaaaaa"


// Approach: 
    -> Find LCS store in DP table
    -> Backtrack in Dp table & store the sequences of characters...


// Complexity:
    -> TC: O(n * m)
    -> SC: O(n * m)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {

        // Find LCS:
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> t(n + 1, vector<int> (m + 1, 0));

        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < m + 1; j++) {
                if(s1[i-1] == s2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(
                        t[i-1][j],
                        t[i][j-1]
                    );
                }
            }
        }

        int lcs = t[n][m];
        int superSeq = (n - lcs) + (m - lcs) + lcs;

        // Find superSequence string:
        string ans = "";
        int i = n, j = m;
        
        while(i > 0 && j > 0) {
            if(s1[i-1] == s2[j-1]) {
                ans.push_back(s1[i-1]);
                i--;
                j--;
            }
            else{
                if(t[i-1][j] > t[i][j-1]) {
                    ans.push_back(s1[i-1]);
                    i--;
                }
                else{
                    ans.push_back(s2[j-1]);
                    j--;
                }
            }
        }

        // Store leftOver:
        while(i > 0) {
            ans.push_back(s1[i-1]);
            i--;
        }
        while(j > 0) {
            ans.push_back(s2[j-1]);
            j--;
        }
        
        reverse(begin(ans), end(ans));
        return ans;
    }
};