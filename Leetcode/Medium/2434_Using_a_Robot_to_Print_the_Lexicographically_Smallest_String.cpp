/*

//  2434. Using a Robot to Print the Lexicographically Smallest String


//  Problem Statement: 
    -> You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:
        -> Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
        -> Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
    -> Return the lexicographically smallest string that can be written on the paper.

 
// Example: 

    Example 1:
        Input: s = "zza"
        Output: "azz"
        Explanation: Let p denote the written string.
        Initially p="", s="zza", t="".
        Perform first operation three times p="", s="", t="zza".
        Perform second operation three times p="azz", s="", t="".

    Example 2:
        Input: s = "bac"
        Output: "abc"
        Explanation: Let p denote the written string.
        Perform first operation twice p="", s="c", t="ba". 
        Perform second operation twice p="ab", s="c", t="". 
        Perform first operation p="ab", s="", t="c". 
        Perform second operation p="abc", s="", t="".

    Example 3:
        Input: s = "bdda"
        Output: "addb"
        Explanation: Let p denote the written string.
        Initially p="", s="bdda", t="".
        Perform first operation four times p="", s="", t="bdda".
        Perform second operation four times p="addb", s="", t="".



// Problem Overview:
    -> We are given a string `s`. A robot can perform two operations to help build the lexicographically smallest string:
        1. Remove the first character from string `s` and push it to another string `t`.
        2. Remove the last character from string `t` and append it to the final result (written on paper).
    -> The goal is to determine the lexicographically smallest string that can be written on paper using these operations.


    // Key Observations:
        -> We are effectively simulating a queue-to-stack-to-result transfer:
            -> Characters from `s` are transferred to a stack `t`.
            -> Characters from `t` can be popped (in reverse order) and added to the result string.
            
        -> To construct the lexicographically smallest string:
            -> We should always prioritize placing the smallest available character into the result.
            -> At each step, we must compare the top of stack `t` with the smallest character still remaining in `s`.
            -> If the top of `t` is less than or equal to the smallest remaining character in `s`, we should pop it from `t` into the result.

    // Approach:
        1. Count the frequency of each character in the original string `s`.
        2. Use a helper function to retrieve the lexicographically smallest character that still exists in the unprocessed part of `s`.
        3. Use a stack `t` to simulate the temporary buffer:
            -> For each character in `s`:
                -> Push it onto `t`.
                -> Decrease its frequency count.
                -> While the top of `t` is smaller than or equal to the current smallest remaining character in `s`, pop it and append it to the result.
        4. After processing all characters from `s`, pop and append any remaining characters in `t` to the result.

        
    -> This greedy approach ensures that at each step, we are making the best decision possible to build the smallest result.


// Complexity:
    -> TC: O(N)
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private: 
    char smallest(vector<int>& freq) {  // TC: O(26) => O(1)
        for(int i = 0; i < 26; i++) {   // this will check lexigraphically smallest remaining character.
            if(freq[i] > 0) {
                return ('a' + i); // return that character by converting from int to char
            }
        }

        return 'a'; // else return 'a' as our smallest one.
    }
public:
    string robotWithString(string s) {  // TC: O(n)
        int n = s.size();

        string res = "";
        stack<char> st;
        vector<int> freq(26);

        // Step 1: Count the frequency of each character: 
        for(auto& ch: s) {
            freq[ch - 'a']++;
        }

        // Step 2: Build the answer:
        for(auto& ch: s) {
            st.push(ch);    // push that character into stack
            freq[ch - 'a']--;   // decrement the frequency of that character.

            // remove from stack to result if stack top <= smallest remaining character:
            while(!st.empty() && st.top() <= smallest(freq)) {
                res += st.top();
                st.pop();
            }
        }

        // Store the leftOver: 
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }
};