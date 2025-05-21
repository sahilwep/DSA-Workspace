/*

//  126. Word Ladder II

//  Problem Link: https://leetcode.com/problems/word-ladder-ii/description/


// Observations:
    -> Given beginWord & endWord
    -> Given wordList
    -> Find all the transformation sequence.

    // Approach: 
        -> first find the word & the level on which they transform
        -> Backtrack & generate all the sequence..

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    vector<vector<string>> ans;
    unordered_map<string, int> mp;
    string bWord;
    int sz;
    void dfs(string word, vector<string>& seq) {
        if(word == bWord) {
            reverse(begin(seq), end(seq));
            ans.push_back(seq);
            reverse(begin(seq), end(seq));
            return;
        }

        int step = mp[word];

        for(int i = 0; i < sz; i++) {
            char origCh = word[i];
            for(char c = 'a'; c <= 'z'; c++) {
                word[i] = c;

                if(mp.count(word) && mp[word] + 1 == step) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = origCh;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        // Step 1: Find the transformation sequence words:
        unordered_set<string> st(begin(wordList), end(wordList));
        if(!st.count(endWord)) return ans; // return empty string
        st.erase(beginWord);

        queue<string> q;

        mp[beginWord] = 1;
        q.push(beginWord);
        sz = beginWord.size();

        while(!q.empty()) {
            string word = q.front();
            q.pop();

            int step = mp[word];

            if(word == endWord) break;  // found

            // Word Transformations: 
            for(int i = 0; i < sz; i++) {
                char origCh = word[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if(st.count(word)) {
                        st.erase(word);
                        mp[word] = step + 1;
                        q.push(word);
                    }
                }
                word[i] = origCh;
            }
        }

        if(mp.count(endWord)) {
            bWord = beginWord;
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
    
        return ans;
    }
};