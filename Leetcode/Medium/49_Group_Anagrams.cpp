/*

//  49. Group Anagrams


// Problem Statement:
    * Given an array of strings strs, group the anagrams together. You can return the answer in any order.
 

// Example:
    Example 1:
        Input: strs = ["eat","tea","tan","ate","nat","bat"]
        Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
        Explanation:
            There is no string in strs that can be rearranged to form "bat".
            The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
            The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

    Example 2:
        Input: strs = [""]
        Output: [[""]]

    Example 3:
        Input: strs = ["a"]
        Output: [["a"]]


// Approach:
    // BruteForce Solution:
        -> get the string portion from vector, Sort them
        -> Check the further part of vector, if it's matched by sorting, then all of them into result.
        -> When that string is included into result, mark them with some symbol so that we can't include & check it again..



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BruteForce Solution:
class Solution_ {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n = s.size();
        vector<vector<string>> res;


        for(int i=0;i<n;i++){                       // Iterate in string:
            if(s[i] == "__") continue;              // if we have certain pattern reject the check process
            string temp = s[i];                     // getting the string & store in temp
            sort(temp.begin(), temp.end());         // sort the temp string
            vector<string> tempRes;                 // 1D vector that maintain the result
            tempRes.push_back(s[i]);                // storing into tempRes
            for(int j=i+1;j<n;j++){                 // iterate the further part of string vector
                string next = s[j];                 // get the string that we want to match
                sort(next.begin(), next.end());     // sort them
                if(temp == next){                   // if it's equal to temp
                    tempRes.push_back(s[j]);        // store in our result
                    s[j] = "__";                    // mark that string so that we can't process it further
                }
            }

            res.push_back(tempRes);                 // last store the 1-D tempResult into 2-D result
        }

        return res;
    }
};