/*

//  3330. Find the Original Typed String I


//  Problem Statement: 
    -> Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
    -> Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.
    -> You are given a string word, which represents the final output displayed on Alice's screen.
    -> Return the total number of possible original strings that Alice might have intended to type.

 
// Example: 
    Example 1:
        Input: word = "abbcccc"
        Output: 5
        Explanation: The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and "abcccc".

    Example 2:
        Input: word = "abcd"
        Output: 1
        Explanation: The only possible string is "abcd".

    Example 3:
        Input: word = "aaaa"
        Output: 4


// Observations: 
    -> For adjacent duplicate elements, count that one..


// Complexity: 
    -> TC: O(n)
    -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int ans = 1;

        for(int i = 1; i < n; i++) {
            if(word[i-1] == word[i]) ans++;
        }

        return ans;
    }
};