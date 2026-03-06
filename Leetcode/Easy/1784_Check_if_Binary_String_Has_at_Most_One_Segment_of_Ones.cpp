/*

//  1784. Check if Binary String Has at Most One Segment of Ones


//  Problem Statement: 
    - Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

//  Example:

    Example 1:
        Input: s = "1001"
        Output: false
        Explanation: The ones do not form a contiguous segment.

    Example 2:
        Input: s = "110"
        Output: true


// Observations:
    - If our string contains the first segment of 1's starting from 0th index then we return true
    - else return false.

    // Complexity:
        - TC: O(n)
        - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();

        // if starting position has '0', not possible.
        if(s[0] == '0') return false;

        // Find the first contagious segment of '1' from index '0'
        int i = 0;
        for(; i < n; i++) {
            if(s[i] == '1') continue;
            else break; // if we got any '0' break out.
        }

        // after finding the first segment, now if any other segment available return false.
        for(; i < n; i++) {
            if(s[i] == '1') return false;
        }

        return true;    // string is good :)
    }
};