/*

// 2914. Minimum Number of Changes to Make Binary String Beautiful

// Problem Statement:
    * You are given a 0-indexed binary string s having an even length.
    * A string is beautiful if it's possible to partition it into one or more substrings such that:
        * Each substring has an even length.
        * Each substring contains only 1's or only 0's.
    * You can change any character in s to 0 or 1.
    * Return the minimum number of changes required to make the string s beautiful.
 
// Example:

    Example 1:
    Input: s = "1001"
    Output: 2
    Explanation: We change s[1] to 1 and s[3] to 0 to get string "1100".
    It can be seen that the string "1100" is beautiful because we can partition it into "11|00".
    It can be proven that 2 is the minimum number of changes needed to make the string beautiful.

    Example 2:
    Input: s = "10"
    Output: 1
    Explanation: We change s[1] to 1 to get string "11".
    It can be seen that the string "11" is beautiful because we can partition it into "11".
    It can be proven that 1 is the minimum number of changes needed to make the string beautiful.




// Observations: 
    -> we are given binary string.
    -> we need to make it good:
        -> substring size should be even
        -> we are allowed to swap characters..

    -> Given string size is "even"
    -> If we carefully observe we are need even length of substring that is either 0 or 1
    -> And we are comparing to adjacent elements:
        check(s[i], s[i+1]) -> we are checking this two consecutive string pairs.

    -> if we iterate in string from 0 to n 
    & compare (s[i], s[i+1]) whether they are equal or not, if they are equal, we don't need any swaps.
    if they are not equal we need swaps.
    and iteration runs like: i = i + 2

                |   |   |   |   -> checks
                0 1 2 3 4 5 6 7
                1 1 0 0 0 1 1 1

                check(s[i], s[i+1]);
                Comparision: 
                    check(1, 1) -> pass
                    check(0, 0) -> pass
                    check(0, 1) -> fail => +1
                    check(1, 1) -> pass
                    
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int cnt = 0;

        for(int i=0;i<s.size()-1;i+=2){
            if(s[i] != s[i+1]) cnt++;
        }

        return cnt;
    }
};