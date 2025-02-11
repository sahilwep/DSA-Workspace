/*

//  1910. Remove All Occurrences of a Substring

//  Problem Statement: 
    -> Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
        -> Find the leftmost occurrence of the substring part and remove it from s.
    -> Return s after removing all occurrences of part.
    -> A substring is a contiguous sequence of characters in a string.


// Example:

    Example 1:

        Input: s = "daabcbaabcbc", part = "abc"
        Output: "dab"
        Explanation: The following operations are done:
        - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
        - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
        - s = "dababc", remove "abc" starting at index 3, so s = "dab".
        Now s has no occurrences of "abc".

    Example 2:

        Input: s = "axxxxyyyyb", part = "xy"
        Output: "ab"
        Explanation: The following operations are done:
        - s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
        - s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
        - s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
        - s = "axyb", remove "xy" starting at index 1 so s = "ab".
        Now s has no occurrences of "xy".


// BruteForce: 
    -> Find the substring part & delete from the string until we won't complete remove it from the original string.
    -> TC: O(n^2)


// Better: 
    -> Using stack we can solve this question.
    -> Insert characters into stack, & whenever we will have characters in stack which match given part, pop them out.
    -> O(n^2)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BruteForce Solution:
class Solution {
public:
    string removeOccurrences(string s, string part) {

        while(true) {
            int idx = s.find(part); // find the position of substring starting index.

            if(idx == string::npos) {   // when we won't able to find the string part, we will break out.
                break;
            }

            s.erase(idx, part.size());  // erase that part from original string.
        }

        return s;
    }
};


// Efficient Approach:

class Solution {
private:
    bool check(stack<char> &st, string &part, int m) {
        stack<char> temp = st;  // we will have to use temporary stack, because we can't modify original stack if it's not matched.

        // Now we will check from back of string, because stack store characters in reversed order.
        for(int idx = m - 1; idx >= 0; idx--) {
            if(temp.top() != part[idx]) {   // compare every characters with top characters of stack.
                return false;   // if it's not equal return false
            }

            temp.pop(); // remove characters from stack to match next characters
        }

        return true;    // else return true;
    }
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        int m = part.size();

        stack<char> st;
        for(int i = 0; i < n; i++) {
            st.push(s[i]);  // push that character into stack.

            // Check if stack length is greater to or equal to part length or not?
            // and check whether the top character of stack making part or not?
            if(st.size() >= m && check(st, part, m)) {
                // if it's true, then remove that m length characters from stack:
                for(int j = 0; j < m; j++) {
                    st.pop();   // remove that characters from stack.
                }
            }
        }

        // Now transfer character from stack to string.
        string res = "";
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(begin(res), end(res));  // reverse because in stack characters are in reversed order.

        return res;       
    }
};