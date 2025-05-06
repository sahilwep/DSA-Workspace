/*

//  127. Word Ladder

//  Problem Link: https://leetcode.com/problems/word-ladder/ 


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

 class Solution {
private: 
    int sz;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        sz = beginWord.size();

        unordered_set<string> st(begin(wordList), end(wordList));
        if(!st.count(endWord)) return 0;    // transformation not possible
        st.erase(beginWord);    // remove beginword from set

        queue<pair<int, string>> q;
        q.push({1, beginWord});

        while(!q.empty()) {
            auto [lvl, word] = q.front();
            q.pop();

            if(word == endWord) return lvl;


            // Word transformations: 
            for(int i = 0; i < sz; i++) {
                char origCh = word[i];

                // All possible transformation: 
                for(char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if(st.count(word)) {
                        st.erase(word);
                        q.push({lvl + 1, word});
                    }
                }

                word[i] = origCh;
            }
        }


        return 0;   // transformations not occurred
    }
};