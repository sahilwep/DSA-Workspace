/*

//  2264. Largest 3-Same-Digit Number in String

//  Problem Statement: 
    -> You are given a string num representing a large integer. An integer is good if it meets the following conditions:
        -> It is a substring of num with length 3.
        -> It consists of only one unique digit.
    -> Return the maximum good integer as a string or an empty string "" if no such integer exists.
    -> Note:
        -> A substring is a contiguous sequence of characters within a string.
        -> There may be leading zeroes in num or a good integer.

 
// Example: 
    Example 1:
        Input: num = "6777133339"
        Output: "777"
        Explanation: There are two distinct good integers: "777" and "333".
        "777" is the largest, so we return "777".

    Example 2:
        Input: num = "2300019"
        Output: "000"
        Explanation: "000" is the only good integer.

    Example 3:
        Input: num = "42352338"
        Output: ""
        Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.

// Observations: 
    -> Find the longest 3 digit repeating character, and if we have multiple 3 digit characters, return the largest one.


// Approach: 
    -> Using counter count the 3 digit repeating character
    -> return the largest 3 digit character from string num

    // Complexity: 
        -> TC: O(n)
        -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();

        int cnt = 1;
        string res = "";
        for(int i = 1; i < n; i++) {
            if(num[i-1] == num[i]) {
                cnt++;
            } else {
                cnt = 1;
            }

            // Check the string length of 3:
            if(cnt >= 3) {
                if(res == "") {
                    res += num[i];
                } else {
                    string curr = "";
                    curr += num[i];
                    res = max(res, curr);
                }
            }
        }

        // Make our result as length of '3':
        if(!res.empty()) {
            res += res[0];
            res += res[0];
        }

        return res;
    }
};