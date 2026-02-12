/*

//  3713. Longest Balanced Substring I


//  Problem Statement: 
    - You are given a string s consisting of lowercase English letters.
    - A of s is called balanced if all distinct characters in the substring appear the same number of times.
    - Return the length of the longest balanced substring of s.

 
// Example:
    Example 1:
        Input: s = "abbac"
        Output: 4
        Explanation: The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.

    Example 2:
        Input: s = "zzabccy"
        Output: 4
        Explanation: The longest balanced substring is "zabc" because the distinct characters 'z', 'a', 'b', and 'c' each appear exactly 1 time.​​​​​​​

    Example 3:
        Input: s = "aba"
        Output: 2
        Explanation: ​​​​​​​One of the longest balanced substrings is "ab" because both distinct characters 'a' and 'b' each appear exactly 1 time. Another longest balanced substring is "ba".


// Observations:
    - We will have to return the longest substring that every characters has same frequency.
    - If we look upon the constrains "1000", we can build the nested O(n^2) solutions which is accepted anyways.

    // Approach: 
        - Try every possible substring:
            - hash the characters in 26 size a-z freq table.
            - check if we have valid balanced substring case.
        - Return the longest finding balanced substring.


        // Complexity:
            - TC: O(n^2)
            - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    bool isSame(vector<int> freq) {
        
        // Get any valid freq:
        int times = 0;
        for(int i = 0; i < 26; i++) {
            times = max(times, freq[i]);
        }

        if(times == 0) return false;

        // Check if it's same for all or not?
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;
            if(freq[i] != times) return false;
        }

        return true;
    }
public:
    int longestBalanced(string s) {
        int n = s.size();

        int longest = 1;
        for(int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                if(isSame(freq)) {
                    longest = max(longest, j - i + 1);
                }
            }
        }

        return longest;
    }
};