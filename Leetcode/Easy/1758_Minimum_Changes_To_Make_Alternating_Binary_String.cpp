/*

//  1758. Minimum Changes To Make Alternating Binary String


//  Problem Statement: 
    - You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.
    - The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.
    - Return the minimum number of operations needed to make s alternating.

 
// Example:
    Example 1:
        Input: s = "0100"
        Output: 1
        Explanation: If you change the last character to '1', s will be "0101", which is alternating.

    Example 2:
        Input: s = "10"
        Output: 0
        Explanation: s is already alternating.

    Example 3:
        Input: s = "1111"
        Output: 2
        Explanation: You need two operations to reach "0101" or "1010".

// Observations:
    - We are given string s and we need return the minium cost so that string has all the adjacent bits are reversed.
    
    // Approach:
        - There are only two possibility for alternating sprigs:
            - Either it start with '1' or '0'
            - eg:
                    s = "110101"
                        here, valid possible strings are:   "101010"    OR      "010101"               

        - We need to check these two possibility for generating string & check if the string is following the converted string or not.
        - if it's not following, then we need to get the cost for every conversion.
        - from all the above two checking, we need to return the minimum cost.

    // Complexity:  
        - TC: O(n)
        - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Optoins 1: start with '0'
        // for every even check '0' and for odd check '1' & calculate cost:
        int cost1 = 0;
        for(int i = 0; i < n; i++) {   
            // Check Violations: 
            if(i % 2 == 0 && s[i] == '1') cost1++;           // even case with '1'
            else if (i % 2 != 0 && s[i] == '0') cost1++;     // odd case with '0'
        }

        // Options 2: start with '1'
        // for every even check '1' and for odd check '0' & calculate cost:
        int cost2 = 0;
        for(int i = 0; i < n; i++) {
            // Check Violations:
            if(i % 2 == 0 && s[i] == '0') cost2++;              // even index with '0'
            else if(i % 2 != 0 && s[i] == '1') cost2++;         // odd index with '1'
        }


        return min(cost1, cost2);
    }
};