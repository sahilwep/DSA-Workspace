/*

//  1408. String Matching in an Array

// Problem Statement:
    -> Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.
    -> A substring is a contiguous sequence of characters within a string


// Example:

    Example 1:
        Input: words = ["mass","as","hero","superhero"]
        Output: ["as","hero"]
        Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
        ["hero","as"] is also a valid answer.

    Example 2:
        Input: words = ["leetcode","et","code"]
        Output: ["et","code"]
        Explanation: "et", "code" are substring of "leetcode".

    Example 3:
        Input: words = ["blue","green","bu"]
        Output: []
        Explanation: No string of words is substring of another string.


// Complexity:
    -> TC: O(n^2)


*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> res;

        for(int i=0;i<n;i++){
            // find substring except the current element:
            string curr = words[i];
            bool isFound = false;
            for(int j=0;j<n;j++){
                if(j != i){
                    // find substring:
                    if(words[j].find(curr) != string::npos){
                        isFound = true;
                        break;
                    }
                }
            }

            // last insert that element into result:
            if(isFound){
                res.push_back(curr);
            }
        }

        return  res;
    }
};