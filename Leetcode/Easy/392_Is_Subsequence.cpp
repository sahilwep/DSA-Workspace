/*

//  392. Is Subsequence


//  Problem Statement:
    * Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
    * A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. 
    * (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 
// Example:
    Example 1:
        Input: s = "abc", t = "ahbgdc"
        Output: true

    Example 2:
        Input: s = "axc", t = "ahbgdc"
        Output: false



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) return 1; // if s is empty, return true as subsequence found as empty string
        if(t.empty()) return 0; // if t is empty, return false, because s is not empty, & t is empty, means there is no possible way we can match.


        for(int i=0;i<t.size();i++){
            if(t[i] == s[0]){
                int ptr = i;
                string temp = "";
                for(int j=0;j<s.size();j++){
                    // if string is matched with pattern, store & increment the pointer..
                    if(ptr < t.size() && t[ptr] == s[j]){
                        temp += t[ptr];
                        ptr++;
                    }else{
                        // if string pattern is not matched, increment ptr until we not get the match
                        while(ptr < t.size() && t[ptr] != s[j]){
                            ptr++;
                        }
                        temp += t[ptr]; // store the result.
                        ptr++;  // increment the pointer for next case.
                    }

                    if(ptr >= t.size()) break;  // if pointer exceed the bound, break out the iteration
                }
                if(temp == s) return true;
            }
        }

        return false;
    }
};