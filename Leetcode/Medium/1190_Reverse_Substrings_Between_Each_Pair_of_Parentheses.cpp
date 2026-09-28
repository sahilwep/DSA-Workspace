/*

//  1190. Reverse Substrings Between Each Pair of Parentheses


//  Problem Statement: 
    - You are given a string s that consists of lower case English letters and brackets.
    - Reverse the strings in each pair of matching parentheses, starting from the innermost one.
    - Your result should not contain any brackets.

//  Example:

    Example 1:
        Input: s = "(abcd)"
        Output: "dcba"

    Example 2:
        Input: s = "(u(love)i)"
        Output: "iloveu"
        Explanation: The substring "love" is reversed first, then the whole string is reversed.

    Example 3:
        Input: s = "(ed(et(oc))el)"
        Output: "leetcode"
        Explanation: First, we reverse the substring "oc", then "etco", and finally, the whole string.

// Observations:
    - Given strings s, and given parenthesis
    - we will have to fetch the part of parenthesis, and reverse it and keep going until we reverse the whole string..
    - We can use stack to process the string, and make our intended answer..


    // Complexity:
        - TC: O(n^2)
        - SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        stack<char> st;
        for(int i = 0; i < n; i++) {
            if(s[i] == ')') {
                // Fetch the string from the stack:
                string temp = "";   // used to store temporary string.
                while(st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }

                st.pop();   // this is to remove '('

                // Now push it again into stack:
                for(auto &i: temp) {
                    st.push(i);
                }

                continue;   // skip everything after that.
            }

            st.push(s[i]);
        }

        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(begin(ans), end(ans));  // last reverse to get everything in order...

        return ans;
    }
};