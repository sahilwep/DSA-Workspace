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
    // Brute Force Solution:
        -> Iterate through each string in the vector.
        -> Sort the current string and compare it with the sorted forms of other strings.
        -> If a match is found, group them together into a result vector.
        -> Mark the processed strings to avoid duplicates.
        -> This solution results in a Time Limit Exceeded (TLE) error for larger inputs due to high time complexity.
    

    // Efficient Approach:
        -> Utilize a hash map (unordered_map) to improve time complexity.
        -> Key in the map is the sorted version of the string, which acts as a unique identifier for anagram groups.
        -> Value in the map is a list of strings that are anagrams of the key.
        -> Steps:
            1. Iterate through each string, sort it to generate a key.
            2. Use the key to group strings in the hash map.
            3. Finally, transfer all grouped anagrams from the map into the result vector.

        -> Map Structure:
                {
                "aet": ["eat", "tea", "ate"],
                "ant": ["tan", "nat"],
                "abt": ["bat"]
                }


// Complexity Analysis:

    -> Brute Force:
        TC: O(n^2 * k log k)
            -> n = size of vector & k = avg length of string.
        SC: O(n * k)

    -> Efficient Approach:
        TC: O(n * k * log k)
        SC: O(n * k)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Approach:
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n = s.size();

        // First store all the anagram into map:
        unordered_map<string, vector<string>> mp;
        for(int i=0;i<n;i++){
            string key = s[i];              // get the key
            sort(key.begin(), key.end());   // sort the key
            mp[key].push_back(s[i]);        // store that string into that key
        }

        // Now store all value from map to result:
        vector<vector<string>> res;
        for(auto i: mp){
            res.push_back(i.second);
        }

        return res;
    }
};


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