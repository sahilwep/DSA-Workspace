/*

//  1446. Consecutive Characters


//  Problem Statement: 
    - The power of the string is the maximum length of a non-empty substring that contains only one unique character.
    - Given a string s, return the power of s.

//  Example: 

    Example 1:
        Input: s = "leetcode"
        Output: 2
        Explanation: The substring "ee" is of length 2 with the character 'e' only.

    Example 2:
        Input: s = "abbcccddddeeeeedcba"
        Output: 5
        Explanation: The substring "eeeee" is of length 5 with the character 'e' only.


// Observations: 
    - given string s
    - we need to return the maximum length repeating character from the given string..

    // Approach:
        - use counting approach for adjacent elements...
        - Counting the adj characters, if they were same, then counter increases.
        - If the adjacent characters are not same:
            - store the previous count, by comparing the previous max..


    // Complexity: 
        - TC: O(n)
        - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int n = s.size();

        if(n == 1) return 1; // edge case when we have only single character string..

        // Rest:
        int cnt = 1;
        int maxLen = 1;
        for(int i = 1; i < n; i++) {
            if(s[i-1] == s[i]) {
                cnt++;
            } else {
                maxLen = max(cnt, maxLen);
                cnt = 1;
            }
        }

        // edge case:
        maxLen = max(cnt, maxLen);  // if it's has only 2 same characters
        
        return maxLen;
    }
};