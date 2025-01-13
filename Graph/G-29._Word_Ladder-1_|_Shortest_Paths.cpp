/*

//  G-29. Word Ladder - I | Shortest Paths


//  Problem Statement:
    -> Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.
    -> Keep the following conditions in mind:
        -> A word can only consist of lowercase characters.
        -> Only one letter can be changed in each transformation.
        -> Each transformed word must exist in the wordList including the targetWord.
        -> startWord may or may not be part of the wordList
    -> The second part of this problem can be found here.
    -> Note: If no possible way to transform sequence from startWord to targetWord return 0


// Example:
    Input:
        wordList = {"des","der","dfr","dgt","dfs"}
        startWord = "der", targetWord= "dfs",
    Output: 3
        Explanation:
        The length of the smallest transformation
        sequence from "der" to "dfs" is 3
        i,e "der" -> "dfr" -> "dfs".


    Input:
        wordList = {"geek", "gefk"}
        startWord = "gedk", targetWord= "geek", 
    Output: 2
        Explanation:
        gedk -> geek


    Input: 
        wordList = {"poon", "plee", "same", "poie","plea","plie","poin"}
        startWord = "toon", targetWord= "plea",
    Output: 7 
        Explanation:
        toon -> poon -> poin -> poie -> plie -> plee -> plea 

  

// Approach: 
    -> We aim to solve the problem using Breadth-First Search (BFS), as BFS explores level by level and ensures the shortest path is found. Here's the step-by-step approach:

    1. Breadth-First Search (BFS):
        - BFS is used because it guarantees that the first time we encounter the target word, it will be at the minimum path length. This is due to BFS's nature of exploring all nodes at the current level before moving to the next level.

    2. Initialization:
        - Start with the `startWord` and set its initial distance as `1` (since it's the starting point).
        - Use a queue to manage the BFS traversal. Each element in the queue will be a pair containing the current word and its corresponding transformation steps.
        - Store all words from the `wordList` in an unordered set for quick lookups and to prevent revisiting words.

    3. Character Substitution:
        - For each word, attempt to replace each character (one at a time) with every possible character from 'a' to 'z'.
        - After each substitution, check if the newly formed word exists in the word list (using the set).

    4. Processing Matching Words:
        - If the new word exists in the set:
            - Add it to the queue with an incremented step count (indicating another transformation has been made).
            - Remove the word from the set to mark it as visited, ensuring it won't be revisited.

    5. Target Word Check:
        - At every step, compare the current word with the `targetWord`. If they match, return the number of steps as it represents the shortest transformation sequence.

    6. Edge Case Handling:
        - If the `queue` becomes empty and the `targetWord` hasn't been reached, it means no valid transformation sequence exists. In this case, return `0`.

    7. Set for Visited Words:
        - Using a set ensures that each word is processed only once, preventing infinite loops and redundant calculations.

    -> This approach is efficient due to BFS and the use of an unordered set for fast lookups.

// Complexity:
    -> TC: O(n * l)
    -> SC: O(n * l)
        -> n = word length
        -> l - maximum length of word in the list.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {

        queue<pair<string, int>> q;
        q.push({startWord, 1}); // Start with the initial word and distance of 1
        
        unordered_set<string> st(wordList.begin(), wordList.end()); // Convert wordList into an unordered set for efficient lookup
        
        if (st.find(targetWord) == st.end()) return 0;  // If the target word is not in the word list, return 0 (no transformation possible)
        st.erase(startWord); // Remove startWord to avoid revisiting it
        
        // Perform BFS
        while (!q.empty()) {
            string word = q.front().first;  // Current word being processed
            int steps = q.front().second;  // Number of steps taken so far
            q.pop(); // Remove the processed element from the queue
            
            // If the current word matches the target word, return the number of steps
            if (word == targetWord) return steps;
            
            // Transform each character in the word
            for (int i = 0; i < word.size(); i++) {
                char originalChar = word[i]; // Save the original character
                
                // Replace the current character with all possible letters from 'a' to 'z'
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    
                    // If the transformed word exists in the set
                    if (st.find(word) != st.end()) {
                        q.push({word, steps + 1}); // Add it to the queue with incremented steps
                        st.erase(word); // Mark the word as visited by removing it from the set
                    }
                }
                
                // Restore the original character before moving to the next position
                word[i] = originalChar;
            }
        }
        
        return 0;   // If the queue is exhausted and no transformation sequence is found, return 0
    }
};


int main() {
    int tc;
    cin >> tc; // Number of test cases
    while (tc--) {
        int n;
        cin >> n;
        vector<string> wordList(n);
        
        for (int i = 0; i < n; i++) cin >> wordList[i];
        
        string startWord, targetWord;
        cin >> startWord >> targetWord;
        
        Solution obj;
        int ans = obj.wordLadderLength(startWord, targetWord, wordList);
        cout << ans << "\n";
    }
    return 0;
}
