/*

//  17. Letter Combinations of a Phone Number


//  Problem Statement: 
    -> Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
    -> A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

 
// Example: 
    Example 1:
        Input: digits = "23"
        Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

    Example 2:
        Input: digits = ""
        Output: []

    Example 3:
        Input: digits = "2"
        Output: ["a","b","c"]

 
// Observations: 
    -> Store every number with their consequent characters
        {
        "2" -> "abc"
        "3" -> "def"
            .
            .
        }

    -> We can use some data-structure like map
    -> After that for every given number, we can use backtracking technique to generate possible sequence & store answer


    // Complexity: 
        -> TC: O(n * k^n)
        -> SC: O(n * k^n)
            -> n = maximum recursion depth
            -> k^n = number of answer.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    void solve(int idx, string& digit, unordered_map<char, string>& mp, string& path, vector<string>& ans) {
        if(idx == digit.size()) {
            ans.push_back(path);
            return;
        }

        for(char c: mp[digit[idx]]) {
            path.push_back(c);
            solve(idx + 1, digit, mp, path, ans);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {

        // edge cases: 
        if(digits.size() == 0) return {};

        // Step 1: storing the characters representing their numbers:
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        // Build answer: 
        vector<string> ans;
        string path = "";
        solve(0, digits, mp, path, ans);

        return ans;
    }
};