/*

//  3174. Clear Digits


//  Problem Statement: 
    -> You are given a string s.
    -> Your task is to remove all digits by doing this operation repeatedly:
        -> Delete the first digit and the closest non-digit character to its left.
    -> Return the resulting string after removing all digits.


// Example:
    Example 1:
        Input: s = "abc"
        Output: "abc"
        Explanation: There is no digit in the string.

    Example 2:
        Input: s = "cb34"
        Output: ""
        Explanation: First, we apply the operation on s[2], and s becomes "c4". Then we apply the operation on s[1], and s becomes "".

// Bruteforce: 
    -> Just write the given conditions using nested loop, & our job is done.
    -> TC: O(n^2)
    
    
// Efficient:
    -> If we observe carefully we need to remove digits, not single but all..
    -> And whenever we occur with any digit, we just need to make sure that we will delete the left character to it..
    -> We will just store the characters, not the digits, & whenever we will be having any digits, we will remove the latest character that we have inserted..
    -> If we use stack for this whole operations our job will be easy.
    -> TC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient:
class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();

        stack<char> st;
        for(int i = 0; i < n; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                // remove the latest character that we have pushed into stack:
                if(!st.empty()) st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        // Now at the end: insert back all character to string:
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(begin(res), end(res));
        
        return res;
    }
};

// BruteForce:
class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        string res = "";

        for(int i = 0; i < n; i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                // look back from here & delete that character:
                string temp = "";
                bool flag = true;
                for(int j = res.size() - 1; j >= 0; j--) {
                    if(flag && res[j] >= 'a' && res[j] <= 'z') {
                        flag = false;
                        continue;
                    }
                    temp += res[j];
                }
                reverse(begin(temp), end(temp));
                res = temp;
                continue;
            }
            res += s[i];
        }

        return res;
    }
};