/*

//  583. Delete Operation for Two Strings


//  Problem Statement:
    * Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
    * In one step, you can delete exactly one character in either string.


// Example: 
    Example 1:
        Input: word1 = "sea", word2 = "eat"
        Output: 2
        Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

    Example 2:
        Input: word1 = "leetcode", word2 = "etco"
        Output: 4




// Approach: 
    -> Find lcs from both the string.
    -> minDelete = s1.size() + s2.size() - (2*lcs)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lcs(string s1, string s2){
        int n = s1.size();
        int m = s2.size();
        if(n == 0 || m == 0) return 0;
        if(s1 == s2) return m;

        vector<vector<int>> t(n+1, vector<int> (m+1, 0));

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1] == s2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }else{
                    t[i][j] = max(
                        t[i-1][j],
                        t[i][j-1]
                    );
                }
            }
        }

        return t[n][m]; // lcs from both the string

    }
    int minDistance(string s1, string s2) {
        
        int LCS = lcs(s1, s2);

        int minDelete = s1.size() + s2.size() - (2*LCS);    // we need those element whose are not common from both the string.

        return minDelete;
    }
};