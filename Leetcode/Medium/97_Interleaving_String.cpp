/*

//  97. Interleaving String


//  Problem Statement: 
    - Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
    - An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:
        s = s1 + s2 + ... + sn
        t = t1 + t2 + ... + tm
        |n - m| <= 1
        The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
    - Note: a + b is the concatenation of strings a and b.

        

// Example:
    Example 1:
        Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
        Output: true
        Explanation: One way to obtain s3 is:
        Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
        Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
        Since s3 can be obtained by interleaving s1 and s2, we return true.

    Example 2:
        Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
        Output: false
        Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.

    Example 3:
        Input: s1 = "", s2 = "", s3 = ""
        Output: true

        

// Observations:
    - 
    - Given string s1, s2, and s3, find wether s3 is formed by an interleaving of s1 and s2:
    - It says that interleaving of s1 ans s2:
        - two string s and t is configured where s and t are divide into n and m substring respectively.

    // Approach 1:
        - From string s1 and s2, we will have to match the string character into s3,
        - If it's matches then only we can move, else we can't move..
        - we will have to sequentially process all the string.
        - we will have to recursively explore all the states of matching..

        // Base case:
            if we successfully explored the string, then only we can say we have found our answer:

        // Decision tree:
            if t[k - 1] == s1[n - 1] {
                // may-be-matched in s1
            }

            if(t[k - 1] == s2[m - 1]) {
                // may-be matched in s2
            }

            return false;   // not matches current with anyone...

        -> Solution get accepted, as not fall into TLE, because of very small constrains:

            // Complexity:
                - TC: O(2^(n + m))
                - SC: O(n * m)

        -> Optimization:
            - we can memoize this solution, to improve the recomputation of subproblems..
            - we have 3 variables values:
                n, m, k
                -> we will have to create dp table of n * m * m
                -> and we can memoize this recursive solution:

            // Complexity:
                - TC: O(n * m * k)
                - SC: O(n * m * k)

            -> since k is always equals to n + m, so carrying k is not necessary.
                - TC: O(n * m)
                - SC: O(n * m)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Memoization: O(n * m * k)
class Solution {
private:
    vector<vector<int>> dp;
    bool solve(string &s1, string &s2, string &t, int n, int m, int k) { 
        // Base case:
        if(n == 0 && m == 0 && k == 0) {
            return dp[n][m] = true;
        }

        // check in memo-table:
        if(dp[n][m] != -1) {
            return dp[n][m];
        }

        // Decision Tree:
        if(n > 0 && k > 0 && t[k - 1] == s1[n - 1]){
            if(solve(s1, s2, t, n - 1, m, k - 1)) return dp[n][m] = true;
        }

        if(m > 0 && k > 0 && t[k - 1] == s2[m - 1]) {
            if(solve(s1, s2, t, n, m - 1, k - 1)) return dp[n][m] = true;;
        }

        return dp[n][m] = false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();

        // Edge case: third string size not same as first + second
        if(k != n + m ) return false;

        dp.resize(n + 1, vector<int> (m + 1, -1));

        return solve(s1, s2, s3, n, m, k);
    }
};


// Memoization: O(n * m * k)
class Solution_M {
private:
    vector<vector<vector<int>>> dp;
    bool solve(string &s1, string &s2, string &t, int n, int m, int k) { 
        // Base case:
        if(n == 0 && m == 0 && k == 0) {
            return dp[n][m][k] = true;
        }

        // check in memo-table:
        if(dp[n][m][k] != -1) {
            return dp[n][m][k];
        }

        // Decision Tree:
        if(n > 0 && k > 0 && t[k - 1] == s1[n - 1]){
            if(solve(s1, s2, t, n - 1, m, k - 1)) return dp[n][m][k] = true;
        }

        if(m > 0 && k > 0 && t[k - 1] == s2[m - 1]) {
            if(solve(s1, s2, t, n, m - 1, k - 1)) return dp[n][m][k] = true;;
        }

        return dp[n][m][k] = false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();

        // Edge case: third string size not same as first + second
        if(k != n + m ) return false;

        dp.resize(n + 1, vector<vector<int>> (m + 1, vector<int> (k + 1, -1)));


        return solve(s1, s2, s3, n, m, k);
    }
};


// Recursive Solution:
class Solution_R {
private:
    bool solve(string &s1, string &s2, string &t, int n, int m, int k) { 
        // Base case:
        if(n == 0 && m == 0 && k == 0) {
            return true;
        }

        // Decision Tree:
        if(n > 0 && k > 0 && t[k - 1] == s1[n - 1]){
            if(solve(s1, s2, t, n - 1, m, k - 1)) return true;
        }

        if(m > 0 && k > 0 && t[k - 1] == s2[m - 1]) {
            if(solve(s1, s2, t, n, m - 1, k - 1)) return true;;
        }

        return false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();

        // Edge case: third string size not same as first + second
        if(k != n + m ) return false;


        return solve(s1, s2, s3, n, m, k);
    }
};