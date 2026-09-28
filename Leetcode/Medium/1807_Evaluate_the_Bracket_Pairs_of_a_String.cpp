/*

//  1807. Evaluate the Bracket Pairs of a String


//  Problem Statement: 
    - You are given a string s that contains some bracket pairs, with each pair containing a non-empty key.
        - For example, in the string "(name)is(age)yearsold", there are two bracket pairs that contain the keys "name" and "age".
    - You know the values of a wide range of keys. This is represented by a 2D string array knowledge where each knowledge[i] = [keyi, valuei] indicates that key keyi has a value of valuei.
    - You are tasked to evaluate all of the bracket pairs. When you evaluate a bracket pair that contains some key keyi, you will:
        - Replace keyi and the bracket pair with the key's corresponding valuei.
        - If you do not know the value of the key, you will replace keyi and the bracket pair with a question mark "?" (without the quotation marks).
    - Each key will appear at most once in your knowledge. There will not be any nested brackets in s.
    - Return the resulting string after evaluating all of the bracket pairs.


//  Example:
        Example 1:
            Input: s = "(name)is(age)yearsold", knowledge = [["name","bob"],["age","two"]]
            Output: "bobistwoyearsold"
            Explanation:
            The key "name" has a value of "bob", so replace "(name)" with "bob".
            The key "age" has a value of "two", so replace "(age)" with "two".

        Example 2:
            Input: s = "hi(name)", knowledge = [["a","b"]]
            Output: "hi?"
            Explanation: As you do not know the value of the key "name", replace "(name)" with "?".

        Example 3:
            Input: s = "(a)(a)(a)aaa", knowledge = [["a","yes"]]
            Output: "yesyesyesaaa"
            Explanation: The same key can appear multiple times.
            The key "a" has a value of "yes", so replace all occurrences of "(a)" with "yes".
            Notice that the "a"s not in a bracket pair are not evaluated.

        
// Observations:
    - Given strins, and part of brackets.
    - which we have to fetch from the knowledge, and place it to that place..
        - if key is not found, we will have to place it with "?"
        - else we will have to replace it with given knowledge..

    // Complexity:
        - TC: O(n)
        - SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();

        unordered_map<string, string> mp;
        for(auto &i: knowledge) {
            mp[i[0]] = i[1];
        }

        // Now process string s, and build answer:
        string ans = "";
        bool flag = false;
        string key = "";
        for(int i = 0; i < n; i++) {
            // Marking "(" & ")" for activating flag:
            if(s[i] == '(') {
                flag = true;
                continue;
            } 

            if(s[i] == ')') {
                if(!key.empty()) {
                    // Now find that into mp:
                    if(mp.count(key)) {
                        ans += mp[key];
                    } else {
                        ans += '?';
                    }
                }

                flag = false;   // deactivating flag.
                key = "";   // making key as empty
                continue;
            }

            // If flag is activated: store the sequence:
            if(flag == true) {
                key += s[i];
                continue;   // skip everything else..
            }

            ans += s[i];
        }

        return ans;
    }
};