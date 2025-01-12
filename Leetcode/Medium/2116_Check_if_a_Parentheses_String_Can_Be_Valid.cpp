/*

//  2116. Check if a Parentheses String Can Be Valid


//  Problem Statement: 
    -> A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
        -> It is ().
        -> It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
        -> It can be written as (A), where A is a valid parentheses string.
    -> You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,
        -> If locked[i] is '1', you cannot change s[i].
        -> But if locked[i] is '0', you can change s[i] to either '(' or ')'.
    -> Return true if you can make s a valid parentheses string. Otherwise, return false.


// Example:

    Example 1:
        Input: s = "))()))", locked = "010100"
        Output: true
        Explanation: locked[1] == '1' and locked[3] == '1', so we cannot change s[1] or s[3].
        We change s[0] and s[4] to '(' while leaving s[2] and s[5] unchanged to make s valid.

    Example 2:
        Input: s = "()()", locked = "0000"
        Output: true
        Explanation: We do not need to make any changes because s is already valid.

    Example 3:
        Input: s = ")", locked = "0"
        Output: false
        Explanation: locked permits us to change s[0]. 
        Changing s[0] to either '(' or ')' will not make s valid.


// Observation: 
    -> Whenever we encounter parentheses, the first thing that comes to mind is using a stack.
    -> We can't change the brackets that are fixed, but we can modify the ones that are not fixed.
    -> We can store the fixed open brackets, and if we encounter any fixed close bracket, we can nullify it with the fixed open bracket.
    -> Additionally, we need to store variable open and close brackets so that we can match them with the fixed open brackets stored in the stack.
    -> We also need to track the indices of every fixed open bracket pushed into the stack.
    -> Furthermore, we need to keep track of variable open-close brackets to ensure we remove only those that occur after the fixed ones.


// Approach: 
    -> We will use two stacks:
        -> `open`: This will store the indices of fixed open brackets.
        -> `openClose`: This will store the indices of variable open-close brackets (i.e., those with '0').

    -> Iterate through the string:
        -> If the character is variable ('0'):
            -> Store its index in the `openClose` stack.
        -> If the character is fixed:
            -> Check if it's a '(' (open bracket). If yes, push its index into the `open` stack.
            -> If it's a ')' (close bracket):
                -> Check whether the `open` stack has any value. If yes, pop the top value to balance.
                -> If the `open` stack is empty, check the `openClose` stack for a value. If it has one, pop the value to balance.
                -> If neither stack has a value to balance the close bracket, return `false`.

    -> After the iteration is complete, check whether the `open` stack is empty:
        -> If it is empty, return `true`.
        -> Otherwise, iterate while both `open` and `openClose` are not empty. Check if the top value in the `open` stack is less than the top value in the `openClose` stack:
            -> If yes, keep popping values from both stacks.

    -> Finally, after this iteration, check if the `open` stack is empty:
        -> If it is empty, return `true`.
        -> Otherwise, return `false`.

// Complexity: 
    -> TC: O(n)
    -> SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() % 2 != 0) return 0;   // odd length string never be balanced.
        // only even length string can be balanced:

        int n = s.size();
        stack<int> open;
        stack<int> openClose;
        for(int i=0;i<n;i++){
            if(locked[i] == '0'){
                openClose.push(i);
            }else if(s[i] == '('){  // if it's fixed & open:
                open.push(i);   // push it into stack.
            }else if(s[i] == ')'){  // if it's fixed & closing:
                // Check wether we have any open in our "open" stack or not?
                if(!open.empty()){
                    open.pop();
                } 
                // If we don't have any value in our "open" stack, then check in "openClose" stack:
                else if(!openClose.empty()){    // if value exist in openClose
                    openClose.pop();    // remove value from openClose
                }
                // else if we don't have value in "openStack" & "Open" 
                else{
                    return false;   // return false, because we don't have any matching pair.
                }
            }
        }

        if(open.empty()) return true;   // If "open" stack is empty, means we have all pairs of fixed open & close.

        // Now Checking LeftOver values from "open" & "openClose" stack:
        while(!open.empty() && !openClose.empty() && open.top() < openClose.top()){
            open.pop();
            openClose.pop();
        }

        return open.empty();    // if open still not empty return false : else return true
    }
};