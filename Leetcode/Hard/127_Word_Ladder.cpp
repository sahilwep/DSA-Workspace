/*

//  127. Word Ladder


//  Problem Statement: 
    -> A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
        -> Every adjacent pair of words differs by a single letter.
        -> Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
        -> s'k' == endWord
    -> Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 
// Example: 

    Example 1:
        Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
        Output: 5
        Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

    Example 2:
        Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
        Output: 0
        Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.


// Observations: 
    -> Given beginWord & endWord & wordlist.
    -> we need to find the minimum transformations sequence so that we can reach from startWord to endWord.
    
    // Key Observations: 
        -> If we observe carefully the transformation cost from one word to another is '1' -> which gives us the hint of Level order Traversal BFS
        -> Now, For transforming one word to another -> we can pick every character one by one & trying transforming that with every possible alphabets..
        -> For query in wordList -> We will use set DS -> Which helps us to query string word in O(1) complexity..



    // Complexity: 
        -> TC: O(n * l) => Same as BFS
            -> n = number of words
            -> l => max len of word in wordlist.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// BFS Approach: 
class Solution {
private: 
    int n;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        n = beginWord.size();

        unordered_set<string> st(begin(wordList), end(wordList));   // for faster query in WordList

        // Edge Case: 
        if(st.find(endWord) == st.end()) return 0;  // check if endWord doesn't exit => Transformations is not possible.
        st.erase(beginWord);    // after looking we don't need the start word -> remove it from the set.

        // Process LOT: 
        queue<pair<int, string>> q; // Structure: <steps, word>
        
        q.push({1, beginWord}); // push the first beginWord with step = 1

        while(!q.empty()) {
            auto [steps, word] = q.front();
            q.pop();

            if(word == endWord) return steps;   // at any movement if we encounter with the endWord => return steps immediately..


            // Word Transformations: 
            for(int i = 0; i < n; i++) {    // start chaning every characters
                char origChar = word[i];    // preserve the original characters

                // Possible Changes a - z: 
                for(char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;

                    if(st.count(word)) {    // check in set if it's exist:
                        st.erase(word);     // remove that from set.

                        q.push({steps + 1, word});  // push it into queue.
                    }
                }

                // revert back the original word for other possibility.
                word[i] = origChar; 
            }
        }

        return 0;   // not possible..
    }
};