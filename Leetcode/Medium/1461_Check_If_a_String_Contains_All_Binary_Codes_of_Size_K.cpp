/*

//  1461. Check If a String Contains All Binary Codes of Size K


//  Problem Statement: 
    - Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

 
// Example:
    Example 1:
        Input: s = "00110110", k = 2
        Output: true
        Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.

    Example 2:
        Input: s = "0110", k = 1
        Output: true
        Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 

    Example 3:
        Input: s = "0110", k = 2
        Output: false
        Explanation: The binary code "00" is of length 2 and does not exist in the array.

 
// Observations:
    - We are given binary string s & integer 'k'
    - We need to find wether the string constains all the substrins of binary number generated with size 'k'

    // Approach:
        - we need to generate all the 'k' size binary string and try to found in given s.
        - One thing we can easily found that:
            - we are given only two numbers 1 & 0
            - and we are given 'k' size or place on which we have to place 1/0
            - we can generate this using: (2^k)
            - Example: 
                k = 1       =>  2 total string
                    0 1
                k = 2       =>  4 total strings
                    00  10  01  11
                k = 3       =>  8 total strings
                    000 001 010 011 100 101 110 111

            - we we only need to find wether these substrings are there in s or not?
            - Instead of generating this every time, & then finding in string s
            - we can directly generate all the 'k' size substrings from s
            - and store somewhere & check wether we have exactly those(2^k) times unique strings or not.


        // Complexity:
            - TC: O(n)
            - SC: O(n)  

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int totalSubstr = 1 << k;   // similar to pow(2, k);    // shifting k bits in 
        
        // Now store all the substring of size k from string s:
        unordered_set<string> st;
        for(int i = k; i <= s.size(); i++) {    // going till s.size(), because k adds up '1'
            st.insert(s.substr(i - k, k));
        }

        return (st.size() == totalSubstr);  // if we have exactly k substring then only return true
    }
};