/*

//  1513. Number of Substrings With Only 1s


//  Problem Statement: 
    - Given a binary string s, return the number of substrings with all characters 1's. 
    - Since the answer may be too large, return it modulo 109 + 7.
 

// Example: 
    Example 1:
        Input: s = "0110111"
        Output: 9
        Explanation: There are 9 substring in total with only 1's characters.
            "1" -> 5 times.
            "11" -> 3 times.
            "111" -> 1 time.

    Example 2:
        Input: s = "101"
        Output: 2
        Explanation: Substring "1" is shown 2 times in s.

    Example 3:
        Input: s = "111111"
        Output: 21
        Explanation: Each substring contains only 1's characters.

        
// Observations: 
    - One thing we can observe that the number of contigious ones:
        - if we have to count the total number of subarray formed from contigious ones are: ((n + 1) * n)/ 2
        - Example:
            s = "0110111"
                   2   3

                "11" 
                    => 2 * 3 / 2 => 3

                "111" 
                    => 3 * 4 / 2 => 6

        // Approach: 
            - we will apply {n * (n + 1)/2} formula for all the contigious 1's...
            - every time when we hit the 0's we will compute subarray..

    // Complexity: 
        - TC: O(n)
        - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    typedef long long ll;
public:
    int numSub(string s) {
        int n = s.size();

        ll subCnt = 0;
        ll cnt = 0;
        ll mod = 1e9 + 7;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') cnt++;
            else {
                subCnt = (subCnt + (cnt * (cnt + 1) / 2) % mod) % mod;
                cnt = 0;
            }
        }
        
        // Compute the remaining ones:
        subCnt = (subCnt + (cnt * (cnt + 1) / 2) % mod) % mod;


        return (int)subCnt;
    }
};