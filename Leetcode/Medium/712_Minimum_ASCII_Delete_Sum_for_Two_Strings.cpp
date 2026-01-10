/*

//  712. Minimum ASCII Delete Sum for Two Strings


//  Problem Statement: 
    - Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

// Example:
    Example 1:
        Input: s1 = "sea", s2 = "eat"
        Output: 231
        Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
        Deleting "t" from "eat" adds 116 to the sum.
        At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

    Example 2:
        Input: s1 = "delete", s2 = "leet"
        Output: 403
        Explanation: Deleting "dee" from "delete" to turn the string into "let",
        adds 100[d] + 101[e] + 101[e] to the sum.
        Deleting "e" from "leet" adds 101[e] to the sum.
        At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
        If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.


// Observations:
    - We are given string s1 & s2
        - We have to delete some character from s1 & s2, so that their sum should be minimum as possible..
        - To make string s1 equal to s2

    - We have delete those character that are not matching from s1 & s2, in simple:
        - This give us the sign of LCS:
        - But here we have to delete those character who's ASCII value is minimum as possible.
        - So While finding the LCS:
            - We will find the common characters that has Larger ASCII value:
            - SO that after finding LCS: we can delete those characters whose ASCII value is minimum after summations

        - First find LCS based on ASCII value:
        - Then simply deleted characters are:
            - (n - lcs) + (m - lcs) => (n + m) - (2*lcs)

    - For LCS: https://github.com/sahilwep/DSA-Workspace/blob/main/DP-Aditya-Verma/19-Longest_common_subsequence_Recursive.cpp
    - It's just we have to add the character ascii value instead of adding 1 while we have matched characters.
    

// Complexity:
    // Recursive:
        - TC: O(2^(n * m))
        - SC: O(n * m)
    
    // Memoization:
        - TC: O(n * m)
        - SC: O(n * m)

    // Tabulation:
        - TC: O(n * m)
        - SC: O(n * m)

    // Space Optimization:
        - TC: O(n * m)
        - SC: O(m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Space Optimization:
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        // LCS: with store the string that has maximum ascii Values:
        vector<int> prev(m + 1, 0);
        for(int i = 1; i < n + 1; i++) {
            vector<int> curr(m + 1, 0);
            for(int j = 1; j < m + 1; j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    curr[j] = (int)(s1[i - 1]) + prev[j - 1];
                } else {
                    curr[j] = max(
                        prev[j],
                        curr[j - 1]
                    );
                }
            }
            prev = curr;
        }

        // Now iterate in string s1 & s2 and sums them up
        int sum = 0;
        for(auto &ch: s1)  sum += (int)(ch);
        for(auto &ch: s2)  sum += (int)(ch);
        
        
        return sum - (2 * prev[m]);
    }
};


// Tabulations:
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        // LCS: with store the string that has maximum ascii Values:
        vector<int> prev(m + 1, 0);
        for(int i = 1; i < n + 1; i++) {
            vector<int> curr(m + 1, 0);
            for(int j = 1; j < m + 1; j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    curr[j] = (int)(s1[i - 1]) + prev[j - 1];
                } else {
                    curr[j] = max(
                        prev[j],
                        curr[j - 1]
                    );
                }
            }
            prev = curr;
        }

        // Now iterate in string s1 & s2 and sums them up
        int sum = 0;
        for(auto &ch: s1)  sum += (int)(ch);
        for(auto &ch: s2)  sum += (int)(ch);
        
        
        return sum - (2 * prev[m]);
    }
};

// Memoization:
class Solution {
private:
    vector<vector<int>> t;
    int solve(int n, int m, string& s1, string& s2) {
        if(n == 0 || m == 0) return 0;

        if(t[n][m] != -1) return t[n][m];

        // Decision tree:
        if(s1[n - 1] == s2[m - 1]) {
            return t[n][m] = (int)(s1[n - 1]) + solve(n - 1, m - 1, s1, s2);
        } else {
            return t[n][m] = max(
                solve(n - 1, m, s1, s2),
                solve(n, m - 1, s1, s2)
            );
        }
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        t.resize(n + 1, vector<int> (m + 1, -1));

        int lcs = solve(n, m, s1, s2);

        // Now iterate in string s1 & s2 and sums them up
        int sum = 0;
        for(auto &ch: s1)  sum += (int)(ch);
        for(auto &ch: s2)  sum += (int)(ch);
        
        
        return sum - (2 * lcs);
    }
};


// Recursive Solution:
class Solution {
private:
    int solve(int n, int m, string& s1, string& s2) {
        if(n == 0 || m == 0) return 0;

        // Decision tree:
        if(s1[n - 1] == s2[m - 1]) {
            return (int)(s1[n - 1]) + solve(n - 1, m - 1, s1, s2);
        } else {
            return max(
                solve(n - 1, m, s1, s2),
                solve(n, m - 1, s1, s2)
            );
        }
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        int lcs = solve(n, m, s1, s2);

        // Now iterate in string s1 & s2 and sums them up
        int sum = 0;
        for(auto &ch: s1)  sum += (int)(ch);
        for(auto &ch: s2)  sum += (int)(ch);
        
        
        return sum - (2 * lcs);
    }
};