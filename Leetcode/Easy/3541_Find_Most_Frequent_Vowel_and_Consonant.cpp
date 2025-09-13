/*

//  3541. Find Most Frequent Vowel and Consonant


//  Problem Statement: 
    -> You are given a string s consisting of lowercase English letters ('a' to 'z').
    -> Your task is to:
        -> Find the vowel (one of 'a', 'e', 'i', 'o', or 'u') with the maximum frequency.
        -> Find the consonant (all other letters excluding vowels) with the maximum frequency.
    -> Return the sum of the two frequencies.
    -> Note: If multiple vowels or consonants have the same maximum frequency, you may choose any one of them. If there are no vowels or no consonants in the string, consider their frequency as 0.
    -> The frequency of a letter x is the number of times it occurs in the string.

    
// Example:
    Example 1:
        Input: s = "successes"
        Output: 6
        Explanation:
            The vowels are: 'u' (frequency 1), 'e' (frequency 2). The maximum frequency is 2.
            The consonants are: 's' (frequency 4), 'c' (frequency 2). The maximum frequency is 4.
            The output is 2 + 4 = 6.

    Example 2:

        Input: s = "aeiaeia"
        Output: 3
        Explanation:
            The vowels are: 'a' (frequency 3), 'e' ( frequency 2), 'i' (frequency 2). The maximum frequency is 3.
            There are no consonants in s. Hence, maximum consonant frequency = 0.
            The output is 3 + 0 = 3.

// Observations: 
    -> First hash all the character,
    -> Find the most frequent vowel & consonant.


    // Complexity: 
        -> TC: O(n)
            -> n = s.size()
        -> SC: O(1)




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Using Vector only:
class Solution {
private:
    bool isVow(char ch) {return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');}
public:
    int maxFreqSum(string s) {
        int maxVow = 0;
        int maxCons = 0;

        // Step 1: hash all the values into map: // SC: O(1), because at max we will have 26 characters
        vector<int> data(26, 0);  // Represent index: 'a' => 0, 'b' => 1..
        for(auto& ch: s) {
            data[int(ch - 'a')]++;
        }

        for(int i = 0; i < 26; i++) {
            char ch = char(i + 'a');    // get the character
            int freq = data[i];
            
            if(isVow(ch)) {
                maxVow = max(maxVow, freq);
            } else {
                maxCons = max(maxCons, freq);
            }
        }
        
        return maxVow + maxCons;
    }
};


// Using map:
class Solution {
private:
    bool isVow(char ch) {return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');}
public:
    int maxFreqSum(string s) {
        int maxVow = 0;
        int maxCons = 0;

        // Step 1: hash all the values into map: // SC: O(1), because at max we will have 26 characters
        unordered_map<char, int> mp;
        for(auto& ch: s) {
            mp[ch]++;
        }

        for(auto &[ch, freq]: mp) {
            if(isVow(ch)) {
                maxVow = max(maxVow, freq);
            } else {
                maxCons = max(maxCons, freq);
            }
        }
        
        return maxVow + maxCons;
    }
};