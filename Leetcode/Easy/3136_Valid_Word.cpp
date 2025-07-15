/*

//  3136. Valid Word


//  Problem Statement: 
    -> A word is considered valid if:
        -> It contains a minimum of 3 characters.
        -> It contains only digits (0-9), and English letters (uppercase and lowercase).
        -> It includes at least one vowel.
        -> It includes at least one consonant.
    -> You are given a string word.
    -> Return true if word is valid, otherwise, return false.
    -> Notes:
        -> 'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
        -> A consonant is an English letter that is not a vowel.

 
// Example: 
    Example 1:
        Input: word = "234Adas"
        Output: true
        Explanation:
        This word satisfies the conditions.

    Example 2:
        Input: word = "b3"
        Output: false
        Explanation:
        The length of this word is fewer than 3, and does not have a vowel.

    Example 3:
        Input: word = "a3$e"
        Output: false
        Explanation:
        This word contains a '$' character and does not have a consonant.


// Approach: 
    -> Implement the following conditions
    

    // Complexity: 
        -> TC: O(n)
        -> SC: O(1)
            -> n = s.size()


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private: 
    bool isVow(char ch) {
        if(ch >= '0' && ch <= '9') return false;    // Edge case

        for(auto& i: {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}) {
            if(ch == i) return true;
        }

        return false;
    }
    bool isCons(char ch) {
        if(ch >= '0' && ch <= '9') return false;    // Edge case

        for(auto& i: {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}) {
            if(ch == i) return false;
        }

        return true;
    }
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;

        bool vowel = false;
        bool consonant = false;
        bool special = false;

        for(auto& ch: word) {
            if(ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
                if(isVow(ch)) vowel = true;
                if(isCons(ch)) consonant = true;
            } else {
                special = true;
            }
        }

        if(special) return false;
        if(vowel == true && consonant == true) return true;
        return false;
    }
};