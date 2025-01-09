/*

//  2185. Counting Words With a Given Prefix



//  Problem Statement:
    -> You are given an array of strings words and a string pref.
    -> Return the number of strings in words that contain pref as a prefix.
    -> A prefix of a string s is any leading contiguous substring of s.

 

// Example: 

    Example 1:

        Input: words = ["pay","attention","practice","attend"], pref = "at"
        Output: 2
        Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".

    Example 2:

        Input: words = ["leetcode","win","loops","success"], pref = "code"
        Output: 0
        Explanation: There are no strings that contain "code" as a prefix.



// Complexity: 
    -> TC: O(n*m)
        n = len of words
        m = len of prefix


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(auto i: words){
            // Find prefix:
            bool isFound = true;
            for(int j=0;j<pref.size();j++){
                if(i.size() < j || pref[j] != i[j]){
                    isFound = false;
                    break;
                }
            }
            if(isFound) count++;
        }

        return count;
    }
};