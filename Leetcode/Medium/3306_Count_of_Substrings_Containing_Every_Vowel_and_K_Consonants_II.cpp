/*

//  3306. Count of Substrings Containing Every Vowel and K Consonants II


//  Problem Statement: 
    -> You are given a string word and a non-negative integer k. 
    -> Return the total number of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

 
// Example:

    Example 1:
        Input: word = "aeioqq", k = 1
        Output: 0
        Explanation: There is no substring with every vowel.

    Example 2:
        Input: word = "aeiou", k = 0
        Output: 1
        Explanation: The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

    Example 3:
        Input: word = "ieaouqqieaouqq", k = 1
        Output: 3
        Explanation: The substrings with every vowel and one consonant are:
                        word[0..5], which is "ieaouq".
                        word[6..11], which is "qieaou".
                        word[7..12], which is "ieaouq".


// Observations: 
    -> We need to select substring that contains at least all vowel once & exactly 'k' occurrence of consonants.

    // Approach: 
        -> We will be using sliding window approach
        -> We will use unordered_map to keep track of every vowel.
        -> maintain variable that count the number of consonants occurrence.
        -> whenever we have valid window in which map size is 5 & consonants equals to k: store answer & move pointer forward.
        -> We also need to maintain the record of every consonants occurrence, because that will give the total number of substring in valid range.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Sliding Window Approach: TC: O(n)
class Solution {
private:
    bool isVowel(char ch){return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' );}
public:
    long long countOfSubstrings(string s, int k) {
        int n = s.size();
        if(k + 5 > n) return 0; // edge case: if k + vowel exceeds the number of valid window size, then there is no possible substring.

        // Process rest of the logic:
        unordered_map<char, int> mp;
        
        // Preprocessing to be able to find index of just next consonant:
        vector<int> nextCons(n);
        int lastCons = n;
        for(int i = n - 1; i >= 0; i--) {
            nextCons[i] = lastCons;
            if(!isVowel(s[i])) {
                lastCons = i;
            }
        }

        int i = 0, j = 0;
        int cons = 0;   // consonant count
        long long ans = 0;
        while(j < n) {
            // Incoming character in window:
            char ch = s[j];
            if(isVowel(ch)) {
                mp[ch]++;
            }else{
                cons++;
            }

            // Outgoing characters from window:
            // consonants must always equal to 'k'
            while(cons > k) {   // we will shrink the window, until consonant count is not equal to 'k'
                char ch = s[i];
                if(isVowel(ch)) {
                    mp[ch]--;
                    if(mp[ch] == 0) {
                        mp.erase(ch);
                    }
                }else{
                    cons--;
                }
                i++;
            }


            // valid window for answer:
            while(mp.size() == 5 && cons == k) {
                // Store the answer from that window:
                int idx = nextCons[j]; // it will tell the next consonant location:
                ans += idx - j; // this will give the total number of substring in that window

                // Now move window forward & check further:
                char ch = s[i];
                if(isVowel(ch)) {
                    mp[ch]--;
                    if(mp[ch] == 0) {
                        mp.erase(ch);
                    }
                }else{
                    cons--;
                }
                i++;
            }

            j++;
        }

        return ans;
    }
};



// BruteForce Solution: TC: O(n^2)
class Solution {
private:
    typedef long long ll;
    bool isVowel(char ch) {return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');}
    bool check(string &s, int start, int end, int k) {  // function to check given constrains follows or not?
        
        int nonVowel = 0;
        vector<bool> vowel(5, false);

        for(int i = start; i <= end; i++) {
            if(nonVowel > k) return false;

            if(!isVowel(s[i])) nonVowel++;  // increment nonVowel count, if we occur with non-vowel

            // Track all vowels:
            if(s[i] == 'a') vowel[0] = 1;
            else if(s[i] == 'e') vowel[1] = true;
            else if(s[i] == 'i') vowel[2] = true;
            else if(s[i] == 'o') vowel[3] = true;
            else if(s[i] == 'u') vowel[4] = true;
        }

        // Check if Non-Vowel exactly 'k' times or not?
        if(nonVowel != k) return 0;

        // Check all vowels are available in substring or not?
        for(int i = 0; i < 5; i++) if(vowel[i] == false) return false; // if we arn't able to complete vowel count: return false;

        return true;    // if all check passed return true
    }
public:
    long long countOfSubstrings(string s, int k) {
        int n = s.size();
        if(k + 5 > n) return 0;

        ll ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 4; j < n; j++) {    // 5 letters vowels are definitely be in answer.
                if(check(s, i, j, k)) {
                    ans++;
                } 
            }
        }


        return ans;
    }
};

