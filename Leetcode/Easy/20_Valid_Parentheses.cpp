/*

//  20. Valid Parentheses


//  Problem Statement:
    -> Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    -> An input string is valid if:
        -> Open brackets must be closed by the same type of brackets.
        -> Open brackets must be closed in the correct order.
        -> Every close bracket has a corresponding open bracket of the same type.

 
// Example: 

    Example 1:

        Input: s = "()"
        Output: true

    Example 2:

        Input: s = "()[]{}"
        Output: true

    Example 3:

        Input: s = "(]"
        Output: false

    Example 4:

        Input: s = "([])"
        Output: true


// Observations:
    - given string s, and just characters '(' ')' '{' '}' '[' ']'
    - Input string is valid if:
        - open bracket must be closed by the same type or brackets.
        - open bracket must be closed in the correct order.
        - Every close bracket has a corresponding open bracket of the same type:

        // Complexity:
            - TC: O(n)
            - SC: O(n)

            
*/

#include<bits/stdc++.h>
#include<algorithm>


class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        string t = "";
        for(auto &c: s) {
            if(c == '(' || c == '{' || c == '[') {
                t.push_back(c);
            } else {
                // We will have to check the previous:
                if(t.empty()) return false; // as it comes closeing without opening.
                char last = t[t.size() - 1];
                if(last == '(' && c  == ')' || last == '{' && c == '}' || last == '[' && c == ']') t.pop_back();
                else return false;
            }
        }

        return (t.empty()) ? true : false;
    }
};

using namespace std;
class Solution {
public:
    bool isValid(string x) {
        int n = x.size();   // getting the size of string.
        stack<char> s;  // creating the stack

        // Iterate throughout the string.
        for(int i=0;i<n;i++){
            // storing all the opening bracket
            if(x[i] == '{' || x[i] == '[' || x[i] == '('){
                s.push(x[i]);   // pushing into stack
                continue;   // no need to check further, so continue this iterations.
            }
            // edge case: when we have number of closing bracket is > opening brackets
            if(s.empty()){
                return false;
            }
            char top = s.top();     // fetching the top element of stack
            // comparing top element with closing element..
            if(top == '{' && x[i] == '}' || top == '[' && x[i] == ']' || top == '(' && x[i] == ')' ){
                s.pop();    // removing if it's same as closing bracket..
            }
            // if it's not get matched we return false
            else{
                return false;
            }
        }
        return s.empty();   // return 1 if we have all the character removed successfully from stack.

    }
};