/*

//  G-31. Word Ladder - 2 | Optimized Approach for Leetcode


//  Problem Statement: 
    -> A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
        -> Every adjacent pair of words differs by a single letter.
        -> Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
        -> sk == endWord
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


class Solution {
private:
    unordered_map<string, int> mp;  // This will store the distance of each word from the beginWord.
    vector<vector<string>> ans;  // This will store all the valid transformation sequences.
    string bWord;   // This will store the beginWord.
    int sz; // This will store the length of the beginWord.

    void dfs(string word, vector<string> &seq) {
        if (word == bWord) {  // If the current word matches the beginWord:
            reverse(seq.begin(), seq.end()); // Reverse the sequence before adding it to the answer.
            ans.push_back(seq); // Add the current sequence to the answer.
            reverse(seq.begin(), seq.end()); // Re-reverse it to maintain the correct order for further recursion.
            return; // Stop further recursion.
        }
        int steps = mp[word];   // Get the distance value of the current word.

        // Perform character transformations and find valid sequences:
        for (int i = 0; i < sz; i++) {
            char original = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;

                // Check if the transformed word exists in the dictionary and if its distance value is one less than the current word's distance.
                if (mp.find(word) != mp.end() && mp[word] + 1 == steps) {  
                    seq.push_back(word); // Add the transformed word to the sequence.
                    dfs(word, seq); // Recursively call dfs with the new word and sequence.
                    seq.pop_back();  // Remove the last word to explore other possible sequences.
                }
            }
            word[i] = original; // Restore the original character.
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Step 1: Use Word Ladder 1 logic to calculate the minimum distance and store it in the map.
        
        unordered_set<string> st(wordList.begin(), wordList.end()); // Use the wordList as a set to track valid transformations and as a visited array.
        st.erase(beginWord); // Remove the beginWord from the set to avoid revisiting it.

        queue<string> q;    // Queue to perform BFS.
        q.push(beginWord);  // Push the beginWord into the queue.
        mp[beginWord] = 1;  // Initialize the distance of the beginWord as 1.
        sz = beginWord.size();

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = mp[word];  // Get the distance of the current word.

            if (word == endWord) break;  // If the endWord is reached, stop the BFS.

            // Generate all possible word transformations:
            for (int i = 0; i < sz; i++) {
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;

                    if (st.find(word) != st.end()) {  // If the transformed word is in the set:
                        st.erase(word); // Remove the transformed word from the set to mark it as visited.
                        q.push(word);   // Push the transformed word into the queue.
                        mp[word] = steps + 1;   // Update the distance of the transformed word.
                    }
                }
                word[i] = original; // Restore the original character.
            }
        }

        // Step 2: If the endWord is reachable, backtrack using DFS and store all valid sequences:
        if (mp.find(endWord) != mp.end()) {  // Check if the endWord is reachable.
            bWord = beginWord;  // Set bWord to the beginWord for DFS.
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);   // Call DFS to find all transformation sequences.
        }

        return ans; // Return the final list of sequences.
    }
};