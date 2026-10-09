/*

//  1541. Minimum Insertions to Balance a Parentheses String


//  Problem Statement: 
    - Given a parentheses string s containing only the characters '(' and ')'. A parentheses string is balanced if:
        - Any left parenthesis '(' must have a corresponding two consecutive right parenthesis '))'.
        - Left parenthesis '(' must go before the corresponding two consecutive right parenthesis '))'.
    - In other words, we treat '(' as an opening parenthesis and '))' as a closing parenthesis.
        - For example, "())", "())(())))" and "(())())))" are balanced, ")()", "()))" and "(()))" are not balanced.
    - You can insert the characters '(' and ')' at any position of the string to balance it if needed.
    - Return the minimum number of insertions needed to make s balanced.

// Example:
    Example 1:
        Input: s = "(()))"
        Output: 1
        Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching. We need to add one more ')' at the end of the string to be "(())))" which is balanced.

    Example 2:
        Input: s = "())"
        Output: 0
        Explanation: The string is already balanced.

    Example 3:
        Input: s = "))())("
        Output: 3
        Explanation: Add '(' to match the first '))', Add '))' to match the last '('.

// Constraints:
    1 <= s.length <= 1e5
    s consists of '(' and ')' only.


// Observations:
    - For every open bracket we will should have two closed brackets.
    - we can use stack and try solving this.
    - as when it's closing, we should make sure to pop two consecutive brackets, as valid. and if we don't have then that one will be required...
        - basically, for any open bracket we required 2 closing.
        - whenever we hit any closing, we will try get two consecutive closing.
            - if we don't have two, we will count as remaining required.
        - at end, we will check wether our stack is empty or not?
            - if it's not empty, means opening brackets are there.
                - so for every opening, we will required, two closing, so we will multiply st.size() * 2, and add it to our answer.

        // NOTE: 
            when we are checking closing bracket:
                we will have to check two conditions: if stack is empty (no opening brackets yet) OR if stack is not empty(we have opening brackets.)
                

        // Complexity:  
            - TC: O(N)
            - SC: O(N)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();

        stack<char> st;
        int req = 0;
        for(int i = 0; i < n; i++) {
            char c = s[i];

            if(c == '(') {
                st.push('(');
            } else {
                // Suppose closing, comes in but we don't have any thing in our stack:
                if(st.empty()) {
                    // Now, check if next character is also closing or not?
                    if(i + 1 < n && s[i + 1] == ')') {
                        i++;
                        req += 1;   // required one opening.
                    } else {
                        req += 2;   // 1 opening and one closing required.
                    }
                } else {    // stack is not empty:
                    // current is ')', check if next is also closing:
                    if(i + 1 < n && s[i + 1] == ')') {
                        st.pop();
                        i++;
                    } else {
                        // current is closing, but may-be next is opening or we don't have anything..
                        st.pop();   // we will remove this,
                        req += 1;   // but one closing will add to our answer.
                    }
                }
                
            }
        }
        
        // Last, check the reminding opening in stack & add it to required closing: any opening require 2, so {st.size() * 2}
        req += 2 * st.size();

        return req;
    }
};