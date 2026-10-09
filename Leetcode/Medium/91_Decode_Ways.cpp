/*

//  91. Decode Ways


//  Problem Statement: 
    - You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:
        "1" -> 'A'
        "2" -> 'B'
        ...
        "25" -> 'Y'
        "26" -> 'Z'

    - However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").
    - For example, "11106" can be decoded into:
        - "AAJF" with the grouping (1, 1, 10, 6)
        - "KJF" with the grouping (11, 10, 6)
        - The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
    - Note: there may be strings that are impossible to decode.
    - Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.
    - The test cases are generated so that the answer fits in a 32-bit integer.

 
// Example:
            
    Example 1:
        Input: s = "12"
        Output: 2
        Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

    Example 2:
        Input: s = "226"
        Output: 3
        Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

    Example 3: 
        Input: s = "06"
        Output: 0
        Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06"). In this case, the string is not a valid encoding, so return 0.

 
// Constraints:

    1 <= s.length <= 100
    s contains only digits and may contain leading zero(s).
 


// Observations:
    - Given string number contains 1 to 9
    - here number represent:
        1 = A
        2 = B
        3 = C
        ...
        ...
        25 = Y
        26 = Z

    - However, while decoding the message, numbers can be represent in different ways:
    
        "25" -> this can be represent as:
            2 = B
            5 = E

            or 25 = Y

            "BE"
            "Y"

            two ways.

    - Example:
        I/p: "226"
        O/p: 3

            BZ (2 26), VF (22, 6) or BBF(2 2 6)

        I/p: 
            "06"
        O/p: 0
            06 cant be mapped to F, because leading 0 is not valid encoding..


    // Approach:
        - From the given number, we will have to pick value as corresponding 1--26
        - Everytime we will have 2 choices:

                -> include one character
                    -> increment with one
                -> include two character
                    -> increment with two
            
            - and recursively we will explore the possibility:

        -> Actually, we don't have to explore the string character, we only need to check ways to reach destinations, with one and two steps.
        
        - This solution Falls into MLE and potentially fall into TLE, as we are doing repetitive subproblem again-n-again..
        - We will have to optimize the complexity by using memo-table.
        

                TC: O(2^n)
                SC: O(2^n)

        // Better solution:
            - but before that we will have to make it better, as storing 't', is not necessary..
            - we can directly store the value, as we decoded..

                TC: O(2^n)
                SC: O(1)

        // Memoization Solution:
            - Variables values are only 'i', so we can use 1D table to memoize this.. 


                TC: O(n)
                SC: O(n)

        // Tabulations Solution:
            - We will convert our solution to tabulations
            - out last value t[n] = 1
            - and we will move from back to from in given array.
            - and simply get the previous computed values...

                TC: O(n)
                SC: O(n)


        // Space Optimizations:
            - also, we can convert our solution to space-optimizations, as it only requrired previous two states, so using two extra variables our job is done..

                TC: O(n)
                SC: O(1)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Space Optimization:
class Solution {
public:
    int numDecodings(string& s) {
        int n = s.size();

        if(s[0] == '0') return 0;

        int prev = 1;       // t[n]
        int prevPrev = 0;   // dummy

        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '0') {
                prevPrev = prev;
                prev = 0;
                continue;
            }

            int curr = prev;

            if(i + 1 < n) {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if(num >= 10 && num <= 26) {
                    curr += prevPrev;
                }
            }

            prevPrev = prev;
            prev = curr;
        }

        return prev;
    }
};



// Tabulations Solution:
class Solution_T {
public:
    int numDecodings(string& s) {
        int n = s.size();

        if(s[0] == '0') return 0;   // edge case. 

        vector<int> t(n + 1, 0);
        t[n] = 1;

        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '0') {
                t[i] = 0;
                continue;
            }

            t[i] = t[i + 1];

            if(i + 1 < n) {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if(num >= 10 && num <= 26) {
                    t[i] += t[i + 2];
                }
            }
        }

        return t[0];
    }
};




// Memoized Solution:
class Solution_M {
private:
    int n;
    vector<int> t;
    int solve(string& s, int i) {
        if(i == n) return 1;

        if(t[i] != -1) return t[i];

        int ways = (i < n && s[i] != '0') ? solve(s, i + 1) : 0;

        if(i + 1 < n && s[i] != '0') {
            int num = (s[i] - '0');
            num = (num * 10) + (s[i + 1] - '0');
            ways += (num >= 10 && num <= 26) ? solve(s, i + 2) : 0;
        }       

        return t[i] = ways;
    }
public:
    int numDecodings(string& s) {
        n = s.size();

        t.resize(n + 1, -1);

        return solve(s, 0);
    }
};




// Better: TLE
class Solution_TLE {
private:
    int n;
    int solve(string &s, int i) {
        // Find 1 ways to decode.
        if(i == n) return 1;

        // Decision Tree: Two ways -> two_jump, tow_jump
        int ways = 0;
        if(i < n && s[i] != '0') {
            ways += solve(s, i + 1);
        }

        if(i + 1 < n && s[i] != '0') {
            int num = (s[i] - '0');
            num = num * 10 + (s[i + 1] - '0');
            if(num >= 10 && num <= 26) ways += solve(s, i + 2);
        }

        return ways;
    }
public:
    int numDecodings(string& s) {
        n = s.size();

        // Edge case:
        if(s[0] == '0') return 0;

        return solve(s, 0);
    }
};



// BruteForce: MLE
class Solution_MLE {
private:
    int n;
    vector<string> ans;
    void solve(string &s, string& t, int i) {
        if(i == n) {
            ans.push_back(t);
            return;
        }

        // Decision Tree: two choices:
        if(i < n && s[i] != '0') {  // should be in bound, and should not be start with '0'
            // Get the number:
            int num = s[i] - '0';

            // Explore:
            t += ('a' + (num - 1));
            solve(s, t, i + 1); // one characters
            t.pop_back();
        }
        
        if(i + 1 < n && s[i] != '0') {  // should be in bound, and should not be start with '0'

            // Get the number:
            int num = s[i] - '0';
            num = num * 10 + (s[i + 1] - '0');

            // If it's in range: explore:
            if(num >= 10 && num <= 26) {
                t += ('a' + (num - 1));
                solve(s, t, i + 2); // two characters
                t.pop_back();
            }
        }
    }
public:
    int numDecodings(string s) {
        n = s.size();
        
        // Edge case:
        if(s[0] == '0') return 0;   // not possible to start with '0'

        string t = "";
        solve(s, t, 0);


        return ans.size();
    }
};