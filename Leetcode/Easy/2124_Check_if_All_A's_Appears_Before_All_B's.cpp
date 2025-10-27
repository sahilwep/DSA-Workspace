/*

//  2124. Check if All A's Appears Before All B's


//  Problem Statement: 
    -> Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' in the string. Otherwise, return false.

 
// Example: 
    Example 1:
        Input: s = "aaabbb"
        Output: true
        Explanation:
        The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
        Hence, every 'a' appears before every 'b' and we return true.

    Example 2:
        Input: s = "abab"
        Output: false
        Explanation:
        There is an 'a' at index 2 and a 'b' at index 1.
        Hence, not every 'a' appears before every 'b' and we return false.

    Example 3:
        Input: s = "bbb"
        Output: true
        Explanation:
        There are no 'a's, hence, every 'a' appears before every 'b' and we return true.

    
// Observations: 
    -> Iterate in string 's' & check the condition, where (s[i] == 'a' && s[i-1] == 'b') return false : else return true;

    // Complexity:
        -> TC: O(n)
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        int n = s.size();

        if(n == 1) return 1;

        for(int i = 1; i < n; i++) {
            if(s[i-1] == 'b' && s[i] == 'a') return 0;
        }

        return 1;
    }
};