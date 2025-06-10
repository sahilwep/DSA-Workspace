/*

//  3442. Maximum Difference Between Even and Odd Frequency I



//  Problem Statement: 
    -> You are given a string s consisting of lowercase English letters.
    -> Your task is to find the maximum difference diff = a1 - a2 between the frequency of characters a1 and a2 in the string such that:
        -> a1 has an odd frequency in the string.
        -> a2 has an even frequency in the string.
    -> Return this maximum difference.



// Example: 

    Example 1:
        Input: s = "aaaaabbc"
        Output: 3
        Explanation:
            The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
            The maximum difference is 5 - 2 = 3.

    Example 2:
        Input: s = "abcabcab"
        Output: 1
        Explanation:
            The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.
            The maximum difference is 3 - 2 = 1.

//  Observations: 
    -> Get the maximum oddFrequency among all the characters of string.
    -> Get the minimum evenFrequency among all the characters of string.
    -> Get the diff b/w oddFreq & evenFreq & that will our result
    

    // Complexity: 
        -> TC: O(N)
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for(auto& ch: s) {
            freq[ch - 'a']++;
        }

        // Get the lowest & highest frequency: 
        int oddFreq = INT_MIN;
        int evenFreq = INT_MAX;
        for(int i = 0; i < 26; i++) {
            // For only hashed value: 
            if(freq[i] != 0) {
                if(freq[i] % 2 != 0) {  // odd the even frequency: 
                    oddFreq = max(oddFreq, freq[i]);
                } else {
                    evenFreq = min(evenFreq, freq[i]);
                }
            }
        }

        return oddFreq - evenFreq;
    }
};