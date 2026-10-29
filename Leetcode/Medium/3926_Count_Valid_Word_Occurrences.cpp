/*

//  3926. Count Valid Word Occurrences



//  Problem Statement: 
    - You are given an array of strings chunks. Concatenate all strings in chunks in order to form a string s.
    - You are also given an array of strings queries.
    - A joiner hyphen is a hyphen character '-' in s whose previous and next characters both exist and are lowercase English letters.
    - A word is a maximal substring of s consisting only of lowercase English letters and joiner hyphens.
    - All other characters, including spaces and hyphens that are not joiner hyphens, are treated as separators.
    - Return an integer array ans, where ans[i] is the number of times queries[i] appears as a word in s.



//  Example:
    Example 1:
        Input: chunks = ["hello wor","ld hello"], queries = ["hello","world","wor"]
        Output: [2,1,0]
        Explanation:
            After concatenating all strings in chunks, s = "hello world hello".
            The words are "hello", "world", and "hello".
            The substring "wor" appears inside "world", but it is not a full word.

    Example 2:
        Input: chunks = ["a-b a--b ","a-","b"], queries = ["a-b","a","b"]
        Output: [2,1,1]
        Explanation:
            After concatenating all strings in chunks, s = "a-b a--b a-b".
            In "a-b", the hyphen is a joiner hyphen because it is between two lowercase English letters, so "a-b" is one word.
            In "a--b", neither hyphen is a joiner hyphen, so it is split into the words "a" and "b".
            Therefore, the words are "a-b", "a", "b", and "a-b".

    Example 3:
        Input: chunks = ["-cat dog- mouse"], queries = ["cat","dog","mouse","cat-dog"]
        Output: [1,1,1,0]
        Explanation:
            After concatenating all strings in chunks, s = "-cat dog- mouse".
            The leading hyphen before "cat" and the trailing hyphen after "dog" are not joiner hyphens, so they are separators.
            The words are "cat", "dog", and "mouse".


// Observations:
    - given chunks:
        - we will have to concenating all the string.
        - and then, from the queries, we will have to return the number of occurrence of that word.

    // Approach:
        - concenating the given chunk
        - after that store it in map
        - and then return the query word frequency.


        // Complexity:
            - TC: O(n + q)
            - SC: O(n)
                - n = total length of chunks
                - q = query size.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        
        // Concatenate and build original string:
        string s = "";
        for(auto &word: chunks) {
            for(auto &ch: word) {
                s += ch;
            }
        }

        // Fiter out the string:
        int n = s.size();
        if(s[0] == '-') s[0] = ' ';
        if(s[n - 1] == '-') s[n - 1] = ' ';
        for(int i = 1; i < n; i++) {
            if(s[i - 1] == '-' && s[i] == '-') {   // consecutive --
                s[i - 1] = ' ';
                s[i] = ' ';
            }
            else if(s[i - 1] == ' ' && s[i] == '-') {
                s[i] = ' ';
            }
            else if(s[i - 1] == '-' && s[i] == ' ') {
                s[i - 1] = ' ';
            }
        }

        // hash characters:
        unordered_map<string, int> mp;
        string t = "";
        for(auto &ch: s) {
            if(ch == ' ') {
                if(!t.empty()) mp[t]++;
                t = "";
            } else {
                t += ch;
            }
        }

        if(!t.empty()) mp[t]++;

        // Build answer:
        vector<int> ans;
        for(auto &q: queries) {
            if(mp.count(q)) {
                ans.push_back(mp[q]);
            } else {
                ans.push_back(0);
            }
        }

        return ans;
    }
};