/*

//  921. Minimum Add to Make Parentheses Valid


//  Problem Statement: 
    - A parentheses string is valid if and only if:
        - It is the empty string,
        - It can be written as AB (A concatenated with B), where A and B are valid strings, or
        - It can be written as (A), where A is a valid string.
    - You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
        - For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
    - Return the minimum number of moves required to make s valid.

// Example:
    Example 1:
        Input: s = "())"
        Output: 1

    Example 2:
        Input: s = "((("
        Output: 3

 
// Constraints:
    1 <= s.length <= 1000
    s[i] is either '(' or ')'.


// Observations:
    - Given string, we will have to find the minimum number of parenthesis, so that our string is valid parenthesis..

    // Approach:
        - when we have opening: 
            - insert into stack
        - when we have close:
            - first check if top element is opening or not?
                - if it's opening: then only we remove.
                - else we will have to insert the closing into stack.

        - last return the size of stack, which is the required number of parenthesis we need to make whole string valid.


        // Complexity:
            -> TC: O(n)
            -> SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();

        stack<char> st;
        for(auto &c: s) {
            if(c == '(') {
                st.push('(');
            } else {
                if(!st.empty() && st.top() == '(') st.pop();
                else st.push(')');
            }
        }
        
        return st.size();
    }
};