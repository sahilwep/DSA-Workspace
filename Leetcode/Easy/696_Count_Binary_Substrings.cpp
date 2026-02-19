/*

//  696. Count Binary Substrings


//  Problem Statement: 
    - Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
    - Substrings that occur multiple times are counted the number of times they occur.

 
// Example:
    Example 1:
        Input: s = "00110011"
        Output: 6
        Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
        Notice that some of these substrings repeat and are counted the number of times they occur.
        Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.

    Example 2:
        Input: s = "10101"
        Output: 4
        Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.



//  Observations:
    - We are given binary string s.
    - we have to return the number of non-empty substrings that have the same number of 0's and 1's
    - and all the 1's and all the 0's in these substrings are grouped consecutively.

    // Approach:
        - First we have to identify the consecutive 1's or 0's
        - and then from that we have to select from that consecutive sequences.
        - Whenever we have breaking sequences:
            - like after the '0' we got '1' or vice versa:
                - we will try to calculate the substring.

        - We will use two counting variable.
            - prev => store the previously counted sequences.
            - curr => store the currently processing sequences..

        - When (s[i] == s[i - 1]) -> increment the current counter.
        - else:
            - calculate answer  => res += min(curr, prev);          => We will take minimum, because that will give us the correct equal sequence substring.
            - set prev = curr;          => Now, previous becomes the current.
            - curr = 0;                 => set current as 0

        - We will start iterations from 1.
            - curr = 1
        - Make sure to calculate the last calculated sequence once we over with iterations.

    // Complexity:
        - TC: O(n)
        - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();

        int prev = 0;
        int curr = 1;
        int res = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                curr++;
            } else {
                res += min(curr, prev);
                prev = curr;
                curr = 1;
            }
        }

        res += min(curr, prev); // add last count.

        return res;
    }
};