/*

//  856. Score of Parentheses


//  Problem Statement: 
    - Given a balanced parentheses string s, return the score of the string.
    - The score of a balanced parentheses string is based on the following rule:
        "()" has score 1.
        AB has score A + B, where A and B are balanced parentheses strings.
        (A) has score 2 * A, where A is a balanced parentheses string.

 
// Example:
    Example 1:
        Input: s = "()"
        Output: 1

    Example 2:
        Input: s = "(())"
        Output: 2

    Example 3:
        Input: s = "()()"
        Output: 2


// Constraints:
    2 <= s.length <= 50
    s consists of only '(' and ')'.
    s is a balanced parentheses string.

 


// Observations:
    - Given balanced parenthesis string s, 
        - The score of a balanced parenthesis strins is based on the following rule:
            - () has score 1
            - AB has score A + B, where A and B are balanced parenthesis string.
            - (A) has score 2 * A, where A is balanced parenthesis string.


    // Approach:
        - we will have to find the depth of parenthesis.
        - Depth of parenthesis calculate as:
            - () => 1
            - (()) => 2 * 1
            - (()()) => 2 * 2
            - "((()())())()" => 11

                ((()())())  ()
                ((()()) ()) 
                ((() ()) ())
                ((A + B) ())
                (4 + ())
                (5) ()
                (10) ()     => 11

        - using stack, we will push the element, and when we have closing bracket:
            - fetch the top value:
                - save curr as current top.
                - remove top
                - set next-top as: max(1, 2 * curr)
        - Idea is to insert initial value, which will preserve the depth..
        - and whenever we will have close:
            - we remove current, and set previous: as max(1, 2 * curr)
        - and keep doing this until we are not iterated till all the characters.
        - as string is balanced, we will remove every value, and our first inserted value will hold the actual answer.
        
        - let say: 

            ((( ')' ()) ()) ()
            
                                    st: {0, 0, 0, 0}
                                                  |
                                                 top
                            curr = 0
                            st.pop();        st: {0, 0, 0}
                                                        |
                                                       top
                            
                            st.top += max(1, 2 * curr) 
                            st.top = 1         
                                             st: {0, 0, 1}
                                                        |
                                                        top

                    for opening: insert:
                                st: {0, 0, 1, 0}
                                              |
                                              top

                    for closed: 

                                (((')') ()) ()

                                curr = 0
                                st.pop();       st: {0, 0, 1}
                                                           |
                                                           top
                                                
                                st.top() += max(1, 2 * curr)
                                st.top() += 1
                                                st: {0, 0, 2}
                                                           |
                                                          top
                
            - This is how our  stack process the current state, and remove it and compute and save it in previous state...


            // Complexity:
                - TC: O(n)
                - SC: O(n)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        
        stack<int> st;
        st.push(0);     // this will works as to preserve original value.

        for(auto &c: s) {
            if(c == '(') {
                st.push(0);    // for every opening: insert '0'
            } else {
                int curr = st.top();    // fetch the top element
                st.pop();               // remove it from top
                st.top() += max(1, 2 * curr);
            }
        }

        return st.top();
    }
};