/*

//  819. Most Common Word


//  Problem Statement: 
    - Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.
    - The words in paragraph are case-insensitive and the answer should be returned in lowercase.
    - Note that words can not contain punctuation symbols.

 
// Example:
    Example 1:
        Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
        Output: "ball"
        Explanation: 
        "hit" occurs 3 times, but it is a banned word.
        "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
        Note that words in the paragraph are not case sensitive,
        that punctuation is ignored (even if adjacent to words, such as "ball,"), 
        and that "hit" isn't the answer even though it occurs more because it is banned.

    Example 2:
        Input: paragraph = "a.", banned = []
        Output: "a"

 
// Observations:
    - Given paragraph & banned words
    - We have to find the word from paragraph that has maximum frequency and not falls into the banned words.
    
    // Approach:
        - Extract the words from the paragraph.
        - hash them into the map
        - get the word from map that not falls into the banned-word & have maximum frequency.

        // Complexity:   
            - TC: O(n + m)
            - SC :O(n + m)
                n = paragraph.size()
                m = banned_word.size()



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int n = paragraph.size();

        unordered_map<string, int> mp;
        string s = "";
        for(auto &ch: paragraph) {
            if(isalpha(ch)) {
                s += tolower(ch);
            } else {
                if(!s.empty()) {
                    mp[s]++;
                    s = "";
                }
            }
        }

        if(!s.empty()) {
            mp[s]++;
        }

        unordered_set<string> st(begin(banned), end(banned));

        int maxFreq = 0;
        string ans = "";

        for(auto &[key, val]: mp) {
            if(!st.count(key)) {
                if(maxFreq < val) {
                    ans = key;
                    maxFreq = val;
                }
            }
        }

        return ans;
    }
};