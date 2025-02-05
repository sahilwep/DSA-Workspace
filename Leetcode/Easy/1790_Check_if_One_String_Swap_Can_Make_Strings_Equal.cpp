/*

//  1790. Check if One String Swap Can Make Strings Equal


//  Problem Statement: 
You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.


// Example: 
    Example 1:
        Input: s1 = "bank", s2 = "kanb"
        Output: true
        Explanation: For example, swap the first character with the last character of s2 to make "bank".

    Example 2:
        Input: s1 = "attack", s2 = "defend"
        Output: false
        Explanation: It is impossible to make them equal with one string swap.

    Example 3:
        Input: s1 = "kelb", s2 = "kelb"
        Output: true
        Explanation: The two strings are already equal, so no string swap operation is required.


// BruteForce Solution: 
    -> Swap every position
    -> Check whether it's equal to s2.
    -> Last revert it back to original.
    -> TC: O(n^2)


// Efficient Approach:
    -> use tow pointer & identify two different position in an array, 
    -> also maintain the counter, & we need exactly 2 position if the string is swapped...
    -> And we can compare those tow position, then we can say it's possible, else not...
    -> TC: O(n)




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution:
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        if(s1 == s2) return 1;

        int pos1 = -1, pos2 = -1;
        int cnt = 0;

        for(int i=0;i<n;i++){
            if(s1[i] != s2[i]) {

                if(pos1 == -1) {    // this will make sure the first position update only once.
                    pos1 = i;
                }
                pos2 = i;
                cnt++;
            }
        }

        // Condition for true case:
        if(cnt == 0) return 1;
        if(cnt == 2) {
            // if (s1[pos1] == s2[pos2] && s1[pos2] == s2[pos1]) return 1;
            // or:
            swap(s1[pos1], s1[pos2]);
            if(s1 == s2) return 1;
        }

        return 0;   // else return false
    }
};


// BruteForce Solution: