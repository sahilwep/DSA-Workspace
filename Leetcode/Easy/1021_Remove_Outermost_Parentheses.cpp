/*

//  1021. Remove Outermost Parentheses


//  Problem Statement: 
    - A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.
        - For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
    - A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty vali- d parentheses strings.
    - Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings- .
    - Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.- 

 
// Example:
    Example 1:
        Input: s = "(()())(())"
        Output: "()()()"
        Explanation: 
            The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
            After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

    Example 2:
        Input: s = "(()())(())(()(()))"
        Output: "()()()()(())"
        Explanation: 
            The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
            After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

    Example 3:
        Input: s = "()()"
        Output: ""
        Explanation: 
            The input string is "()()", with primitive decomposition "()" + "()".
            After removing outer parentheses of each part, this is "" + "" = "".

 
// Observations:
    - Given string s, which is the valid parenthesis.
    - we will have to remove the outermost parenthesis, and return the left string.
    
    // Approach:
        - For every parenthesis or group of parenthesis, we will have to remove the outermost parenthesis.
        - we will have to identify the outermost parenthesis..
        - we will use stack to process whole algorithms:
            - we can start inserting the opening parenthesis, when it's first time, when our stack is empty.
                - we will insert the opening for the first time.
                - if again it's opening, then insert to stack, as we as store in it answer..
            - when it's closing:
                - first check wether our stack has only single opening or not?
                    - if it's only one opening, then that is outermost, and should not be considered.
                - else, if size > 1, remove as we as include it in our answer..

        // Complexity:
            - TC: O(n)
            - SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();

        stack<char> st;
        string ans = "";
        for(auto &c: s) {
            if(c == '(') {  // for open:
                if(st.empty()) {    // insert it in stack for the first time:
                    st.push('('); 
                } else {    // now as stack is not empty, add that into answer, and also insert into stack.
                    ans += c;
                    st.push('(');
                }
            } else {
                if(st.size() > 1) { // if stack is not 1 size, means not only outer left: store answer, and remove that bracket from stack:
                    ans += c;
                    st.pop();
                } else {
                    st.pop();
                }
            }
        }


        return ans;
    }
};