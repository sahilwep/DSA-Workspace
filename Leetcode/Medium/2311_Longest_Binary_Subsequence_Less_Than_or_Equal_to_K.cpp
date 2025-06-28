/*

//  2311. Longest Binary Subsequence Less Than or Equal to K


//  Problem Statement: 
    -> You are given a binary string s and a positive integer k.
    -> Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.
        -> Note:
            -> The subsequence can contain leading zeroes.
            -> The empty string is considered to be equal to 0.
            -> A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

    
// Example: 

    Example 1:
        Input: s = "1001010", k = 5
        Output: 5
        Explanation: The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010", as this number is equal to 2 in decimal.
        Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
        The length of this subsequence is 5, so 5 is returned.

    Example 2:
        Input: s = "00101001", k = 1
        Output: 6
        Explanation: "000001" is the longest subsequence of s that makes up a binary number less than or equal to 1, as this number is equal to 1 in decimal.
        The length of this subsequence is 6, so 6 is returned.

// Observations: 
    -> We are given string s, & integer "k"
    -> we have to build longtest substring, such that it should be less than equal to 'k'
    -> Including all 0's will not effect any in total number
    -> Start including 1's & check while including it, wether the value exceeds 'k' or not?
        -> if it exceeds k, break out
        -> else increment

    -> Example: 
        s = "1001010", k = 5

                1    0     0     1     0     1     0
                2^6  2^5   2^4   2^3   2^2   2^1   2^0

        -> We can include all 0's which will not effect much on string s.
        -> We will start iterating from right side.
            -> We will start including 1's from right side & check wether its lesser than given 'k' or not?
                -> we can do (power >>= 1) for every iteration to move value: 2^0 => 2^1 => 2^2...
                -> Given constrains:  (1 <= k), So we can set, power = 1

// Complexity: 
    -> TC: O(N)
    -> SC: O(1)
        
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int zeroes = 0, ones = 0;
        long value = 0, power = 1;

        // Count all 0's:
        for(auto &ch: s) if(ch == '0') zeroes++;

        // Starting from least significant bit: Process 1's
        for(int i = n - 1; i >= 0; i--) {
            // For every 1's
            if(s[i] == '1') {
                if(power + value > k) continue; // Check if (2^x + prevValue) > k, then skip this..

                // Else: 
                value += power; // add power to values.
                ones++;         // increment ones
            }


            power <<= 1; // Now increment power bits with every iterations: 2^0 -> 2^1 -> 2^2 ...


            if(power > k) break;    // if power become more than the given 'k', break out no need to check further..
        }

        return zeroes + ones;   // return total size of the sub-string. 
    }
};