/*

//  868. Binary Gap


//  Problem Statement: 
    - Given a positive integer n, find and return the longest distance between any two adjacent 1's in the binary representation of n. If there are no two adjacent 1's, return 0.
    - Two 1's are adjacent if there are only 0's separating them (possibly no 0's). The distance between two 1's is the absolute difference between their bit positions. For example, the two 1's in "1001" have a distance of 3.

 
// Example:
    Example 1:
        Input: n = 22
        Output: 2
        Explanation: 22 in binary is "10110".
        The first adjacent pair of 1's is "10110" with a distance of 2.
        The second adjacent pair of 1's is "10110" with a distance of 1.
        The answer is the largest of these two distances, which is 2.
        Note that "10110" is not a valid pair since there is a 1 separating the two 1's underlined.

    Example 2:
        Input: n = 8
        Output: 0
        Explanation: 8 in binary is "1000".
        There are not any adjacent pairs of 1's in the binary representation of 8, so we return 0.

    Example 3:
        Input: n = 5
        Output: 2
        Explanation: 5 in binary is "101".


// Observations:
    - We given number n
    - we need to the distance b/w two consecutive 1's
    - we need to return the largest distance found.

    // Approach:
        - First we will convert the given num into binary string of size 32
        - then we can iterate & find the longest distance.

        // Complexity:
            - TC: O(1)
            - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    string getBinary(int n) {
        string s = "";
        for(int i = 1; i <= 32; i++) {
            s += to_string((n & 1));
            n >>= 1;
        }

        reverse(begin(s), end(s));

        return s;
    }
public:
    int binaryGap(int n) {
        
        string s = getBinary(n);
        
        // Find first 1's
        int i = 0;
        for(; i < 32; i++) {
            if(s[i] == '1') break;
        }

        // Find the longest 1's
        int ans = 0;
        int cnt = 0;
        for(; i < 32; i++) {
            if(s[i] == '0') {
                cnt++;
            } 
            else {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }

        return ans;
    }
};