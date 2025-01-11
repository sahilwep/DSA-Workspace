/*

//  1400. Construct K Palindrome Strings


//  Problem Statement: 
    -> Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.


// Example: 
    Example 1:

        Input: s = "annabelle", k = 2
        Output: true
        Explanation: You can construct two palindromes using all characters in s.
        Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"

    Example 2:

        Input: s = "leetcode", k = 3
        Output: false
        Explanation: It is impossible to construct 3 palindromes using all the characters of s.





// Observations: 
    We are given a string s and an integer k. 
    We need to check whether all characters of the string s can be used to make 'k' palindrome strings or not.

    For a string to be a palindrome:
        - Characters must appear in pairs (even counts).
        - If a character appears an odd number of times, at most one character can remain unpaired (it would occupy the center in an odd-length palindrome).

    // Example:
        s = "annabelle", k = 2
        Frequency count:
            l -> 2
            e -> 2
            b -> 1
            n -> 2
            a -> 2

        Characters with odd frequency = 1 ("b" with count 1).

        s = "leetcode", k = 3
        Frequency count:
            d -> 1
            o -> 1
            c -> 1
            t -> 1
            e -> 3
            l -> 1

        Characters with odd frequency = 5.

    // Key Conditions:
        1. If the string length equals 'k', it is possible to form k palindromes using single characters.
        2. If the string length is less than 'k', it is impossible to form k palindromes.
        3. If the string length is greater than 'k', we analyze the character frequency:

            -> Even frequency counts can always contribute to palindromes.
            -> Odd frequency counts:
                - Single occurrences (frequency = 1) contribute to the "oddFrequencyCount".
                - For characters with odd frequency > 1, we subtract 1 to make their frequency even and increment "oddFrequencyCount".

            At the end, if "oddFrequencyCount" <= k, it is possible to form k palindromes; otherwise, it is not.

        Note: Cases where the string has all odd frequencies and "oddFrequencyCount" <= k but the string length < k are already handled in the condition (s.size() < k).


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;



class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size() == k) return true;  // If the string length equals 'k', we can form k palindromes using single characters.
        if(s.size() < k) return false;  // If the string length is less than 'k', forming k palindromes is impossible.

        // Frequency array to count occurrences of each character.
        vector<int> freq(26, 0);
        for(char ch : s) {
            freq[ch - 'a']++;
        }

        int oddFrequencyCount = 0; // Tracks the count of characters with odd frequency.
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 1) oddFrequencyCount++;
            else if(freq[i] % 2 != 0) oddFrequencyCount++;
        }

        // If the number of odd frequencies is less than or equal to 'k', return true; otherwise, false.
        return oddFrequencyCount <= k;
    }
};