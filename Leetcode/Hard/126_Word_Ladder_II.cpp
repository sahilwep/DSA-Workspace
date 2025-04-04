/*

//  126. Word Ladder II


//  Problem Statement: 
    -> A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
            -> Every adjacent pair of words differs by a single letter.
            -> Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
            -> s[k] == endWord
    -> Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

        
// Example: 
    Example 1:

        Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
        Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
        Explanation: There are 2 shortest transformation sequences:
        "hit" -> "hot" -> "dot" -> "dog" -> "cog"
        "hit" -> "hot" -> "lot" -> "log" -> "cog"

    Example 2:
        Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
        Output: []
        Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.

// Observations:

    -> Given beginWord & endWord & wordlist.
    -> we need to find all the minimum transformations sequence that reaches to endWord, & return all of them...
    

    // Key Observations: 
        -> If we observe carefully the transformation cost from one word to another is '1' -> which gives us the hint of Level order Traversal BFS
        -> Now, For transforming one word to another -> we can pick every character one by one & trying transforming that with every possible alphabets..
        -> For query in wordList -> We will use set DS -> Which helps us to query string word in O(1) complexity..

    
// Approach: 
    -> Follow the step ladder 1-> Get the minimum distance.
        -> Also use map data-structure to store the node while finding the minimum distance.
    
    -> Now Backtrack the map, from end to begin to get the answer.
        -> We will use simple dfs() to backtrack & we will store the path while traversing.

    -> why this solution work:
        -> When we are traversing from backword, we know there are few correct path that gives the source node, so we will be saving ourself form un-necessary path exploration.
    -> Why we are usign map to store the nodes:
        -> We are using map, because map will store the the level & nodes that are in the correct path only
    -> Why this solution will not gives TLE:
        -> In previous solution, we were processing all the possible path to reach the destination, which will increase the overhead.    

    -> In simple un-necessary exploration of path will be restricted, & we will be saving extra space & time.


// Complexity:
    -> TC: O(N * L * P * L)
        -> N is the number of words in the wordList.
        -> L is the length of each word.
        -> P is the number of valid paths (depends on the structure of the graph formed by the wordList).

    -> SC: O(N + L)
        -> O(N) for the mp, queue, and set.
        -> O(L) for the recursive call stack and the sequence during DFS.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Optimized Solution:
class Solution {
private: 
    int sz;
    string bWord;
    vector<vector<string>> ans;
    unordered_map<string, int> mp;
    
    void solve(string word, vector<string> &seq) {  // function to backtrack & find the sequence.
        if(word == bWord) {
            reverse(begin(seq), end(seq));
            ans.push_back(seq);
            reverse(begin(seq), end(seq));
            return;
        }

        int step = mp[word];

        // Word Transformations:
        for(int i = 0; i < sz; i++) {
            char origCh = word[i];
            for(char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if(mp.count(word) && mp[word] + 1 == step) {
                    seq.push_back(word);
                    solve(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = origCh;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(begin(wordList), end(wordList));
        if(!st.count(endWord)) return {};

        st.erase(beginWord);
        queue<pair<int, string>> q;
        q.push({1, beginWord});

        mp[beginWord] = 1;
        sz = beginWord.size();        

        while(!q.empty()) {
            auto [step, word] = q.front();
            q.pop();

            if(word == endWord) break;

            for(int i = 0; i < sz; i++) {
                char origCh = word[i];
                for(char c = 'a'; c  <= 'z'; c++) {
                    word[i] = c;
                    if(st.count(word)) {
                        st.erase(word);
                        q.push({step + 1, word});
                        mp[word] = step + 1;
                    }
                }
                word[i] = origCh;
            }
        }

        // Check wether we found the endWord or not?
        if(mp.count(endWord)) {
            bWord = beginWord;
            vector<string> seq;
            seq.push_back(endWord);
            solve(endWord, seq);
        }

        return ans;
    }   
};




// BruteForce Solution: MLE
class Solution {
private: 
    int n;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        n = beginWord.size();

        unordered_set<string> st(begin(wordList), end(wordList));
        
        if(!st.count(endWord)) return {};   

        queue<vector<string>> q;
        vector<vector<string>> ans;
        vector<string> usedOnLevel;

        int level = 0;
        q.push({beginWord});
        usedOnLevel.push_back(beginWord);

        while(!q.empty()) {
            vector<string> seq = q.front();
            q.pop();

            string word = seq.back();   // get the word from back

            if(seq.size() > level) {    // if sequence size is greater than the level itself, means level just increased..
                level++;
                // clear that level words
                for(auto &it: usedOnLevel) {
                    st.erase(it);   // remove all the words from set, that are used on previous level.
                }
                usedOnLevel.clear();    // make sure to clear this usedOnLevel
            }

            // Check Answer:
            if(word == endWord) {
                // store the answer:
                if(ans.empty()) {
                    ans.push_back(seq); // store answer for the first time, this will be the shortest one.
                } 
                else if(ans[0].size() == seq.size()) {  // store other answer with same length.
                    ans.push_back(seq); // store answer.
                }
            }

            // Word Transformations:
            for(int i = 0; i < n; i++) {
                char origChar = word[i];

                // Explore possibility: 
                for(char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;

                    if(st.count(word)) {

                        seq.push_back(word);    // send it at the end of sequence.
                        q.push(seq);   // send that sequence into list.
                        seq.pop_back(); // revert it for other possibility

                        usedOnLevel.push_back(word);    // send that word into this usedOnLevel vector.
                    }
                }
                word[i] = origChar; // revert back the original character.
            }
        }

        return ans; // return all the sequences.
    }
};