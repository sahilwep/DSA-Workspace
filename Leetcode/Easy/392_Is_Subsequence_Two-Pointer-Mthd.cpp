/*

//  392. Is Subsequence


//  Problem statement:
    * Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
    * A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 
// Example: 

    Example 1:
        Input: s = "abc", t = "ahbgdc"
        Output: true

    Example 2:
        Input: s = "axc", t = "ahbgdc"
        Output: false

 

// Approach: 
    * Solving this question using two pointer approach, will make us easy to implement:
        -> i => string t
        -> j => string s
        
        -> Increment j only when you have match case
        -> Else increment i only..

        -> last check if the size is equal to the j pointer or not?
            -> If the size is equal to the j pointer means we have successfully find the subsequence of given pattern.
            -> In that case return true, else return false.


// Complexity: 
    * TC: O(n)
    * AS: O(1)



*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;  // string t pointer
        int j = 0;  // string i pointer

        while(i < t.size() && j < s.size()){    // iterate until any of the pointer not reach to their string size.
            if(t[i] == s[j]){   // if both the string pattern is matched.
                i++;
                j++;
            }
            else{
                i++;    // else only increase second pointer..
            }
        }

        if(j == s.size()) return true;  // last compare j pointer with s size, if it's equal means we got the pattern, else return false
        return false;
    }
};

