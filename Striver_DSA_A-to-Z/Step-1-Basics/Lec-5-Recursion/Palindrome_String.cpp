/*

//  Palindrome String


//  Problem Statement: 
    - You are given a string s. Your task is to determine if the string is a palindrome. A string is considered a palindrome if it reads the same forwards and backwards.

// Examples:
    Input: s = "abba"
    Output: true
    Explanation: "abba" reads the same forwards and backwards, so it is a palindrome.

    Input: s = "abc" 
    Output: false
    Explanation: "abc" does not read the same forwards and backwards, so it is not a palindrome.


// Approach:
    - Maintain two pointers start at index 0 & end at index "s.size() - 1".
    - Move with start forwards & end backwords
    - check start & end characters, if they were distinct, then return false
    - if start cross end, means palindrome.
    
    
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    bool solve(int l, int r, string& s) {
        if(l >= r) return true; // no-distinct characters found..
        if(s[l] != s[r]) return false;
        
        return solve(l + 1, r - 1, s);
    }
public:
    bool isPalindrome(string& s) {

        return solve(0, s.size() - 1, s);
    }
};