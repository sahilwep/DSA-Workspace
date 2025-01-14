/*

//  G-30. Word Ladder - 2 | Shortest Paths


//  Problem Statement: 
    -> Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.
    -> Keep the following conditions in mind:
        -> A word can only consist of lowercase characters.
        -> Only one letter can be changed in each transformation.
        -> Each transformed word must exist in the wordList including the targetWord.
        -> startWord may or may not be part of the wordList.
        -> Return an empty list if there is no such transformation sequence.

    -> The first part of this problem can be found here.


// Example:

    Input:
        startWord = "der", targetWord = "dfs",
        wordList = {"des","der","dfr","dgt","dfs"}
    Output:
        der dfr dfs
        der des dfs
    Explanation:
        The length of the smallest transformation is 3.
        And the following are the only two ways to get
        to targetWord:-
        "der" -> "des" -> "dfs".
        "der" -> "dfr" -> "dfs".


    Input:
        startWord = "gedk", targetWord = "geek", 
        wordList = {"geek", "gefk"}
    Output:
        "gedk" -> "geek"




// Introduction to the Solution:
    -> The problem is to find all the shortest transformation sequences from a beginWord to an endWord using a given wordList, where each transformation changes only one letter at a time, and every intermediate word must exist in the wordList.
    -> This solution employs Breadth-First Search (BFS), which ensures that we explore all possible shortest paths level by level. Here’s a step-by-step explanation of the approach:
    -> Key Concepts and Steps:
        // Data Structures:
            -> unordered_set<string> wordSet: Efficiently checks if a word exists in the wordList and also marks words as visited by removing them.
            -> queue<vector<string>> q: Tracks sequences of words being explored. Each entry in the queue represents a potential transformation sequence.
            -> vector<string> usedOnLevel: Tracks words used at the current BFS level to ensure they are not reused in subsequent levels.
            -> vector<vector<string>> result: Stores all shortest transformation sequences.

        // BFS Initialization:
            -> Start by pushing the beginWord into the queue as the first sequence.
            -> Track the BFS level to handle transitions between levels efficiently.

        // Processing Each Level:
            -> As we process words from the queue, we generate all possible one-letter transformations for the last word in the current sequence.
            -> If a transformation exists in the wordSet, it's added to the current sequence and pushed into the queue for further exploration.
            -> To avoid revisiting words within the same level, transformations are temporarily stored in usedOnLevel and removed from the wordSet at the end of the level.

        // Checking for the endWord:
            -> If the last word in a sequence matches the endWord, the sequence is added to the result.
            -> The solution ensures that only the shortest transformation sequences are stored.

        // Backtracking:
            -> Each transformation step modifies the word temporarily, and the original word is restored after exploring all possibilities for that character.

        // Termination:
            -> BFS terminates when the queue is empty, and the result contains all valid shortest transformation sequences.



// NOTE:
    -> The `level = 0` initialization is crucial because it helps track the progression of the BFS (Breadth-First Search) through different levels of transformations. 
    -> Here's why it starts at `0`:
        1. Indicating the Starting Point: 
            - The initial level represents the starting word (`beginWord`) in the transformation sequence. At this stage, no transformations have been made.

        2. Managing Word Usage:
            - Words are removed from the `wordSet` only after they are processed at a specific level. The `level` variable helps distinguish when the BFS has moved to a new level, ensuring that words used at the previous level are removed only after processing is complete.

        3. Comparing Sequence Lengths:
            - By tracking the level, the code ensures that only the shortest sequences are stored. If the BFS advances to a new level, any transformation sequence from the previous level is shorter and can be processed separately.

        4. Clarity in BFS Logic:
            - BFS explores paths level by level. Starting at `level = 0` provides a clear baseline for incrementing levels as more transformations are explored.

    -> In short, initializing `level = 0` aligns with the BFS principle of level-order traversal and facilitates efficient word tracking and shortest sequence identification.




// Short Revision Notes:
    -> Goal: Find all shortest transformation sequences from `beginWord` to `endWord` using `wordList`, with one-letter transformations and valid intermediate words.

    -> Approach:
        1. Breadth-First Search (BFS):
           - Use a queue to explore transformation paths level by level.
           - Store each sequence in the queue as a vector of strings.
        2. Tracking Transformations:
           - Use an unordered set (`wordSet`) to efficiently check valid transformations and mark words as visited.
           - Track words used at each level in a separate list (`usedOnLevel`), removing them from the set at the end of the level.
        3. Processing:
           - For each word in the current sequence, generate all possible one-letter transformations.
           - If a valid transformation is found in `wordSet`, add it to the current sequence and push the sequence into the queue.
        4. End Condition:
    
    -> If the last word of a sequence matches `endWord`, store the sequence if it is the shortest.

    -> Key Points:
        -> Remove words from `wordSet` after they are used at a level to avoid revisiting.
        -> Restore the original word after trying all character transformations (backtracking).



//  Complexity:
    -> TC: O(n * L^2)
    -> SC: O(n & L)
        n = the number of words
        l = is the word length

*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // Create a set of words from the word list for quick access and to track visited words.
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // Queue to store sequences of words as we perform BFS.
        queue<vector<string>> q;
        q.push({beginWord}); // Initialize with a sequence containing only the start word.
        
        vector<string> usedOnLevel; // Tracks words used in the current BFS level.
        usedOnLevel.push_back(beginWord);   // push the begin word into BFS level track.
        int level = 0; // Tracks the current level of BFS.
        vector<vector<string>> result; // Stores the shortest transformation sequences.
        
        while (!q.empty()) {
            vector<string> currentSequence = q.front(); // Retrieve the front sequence in the queue.
            q.pop(); // Remove it from the queue.

            // If we move to a new BFS level:
            if (currentSequence.size() > level) {
                level++; // Increment the level.

                // Remove all words used in the previous level from the word set.
                for (const auto& word : usedOnLevel) {
                    wordSet.erase(word);
                }
                usedOnLevel.clear(); // Clear the used words for the next level.
            }

            string lastWord = currentSequence.back(); // Get the last word of the current sequence.

            // If the last word matches the endWord, process the sequence.
            if (lastWord == endWord) {
                // If result is empty, this is the first sequence of shortest length.
                if (result.empty()) {
                    result.push_back(currentSequence);
                }
                // If the current sequence length matches the previously stored sequences, add it.
                else if (result[0].size() == currentSequence.size()) {
                    result.push_back(currentSequence);
                }
            }

            // Generate all possible one-letter transformations of the last word.
            for (int i = 0; i < lastWord.size(); ++i) {
                char originalChar = lastWord[i]; // Store the original character.

                for (char c = 'a'; c <= 'z'; ++c) { // Replace with all possible characters.
                    lastWord[i] = c; // Modify the character.

                    // Check if the modified word exists in the word set.
                    if (wordSet.count(lastWord) > 0) {
                        currentSequence.push_back(lastWord); // Add the new word to the sequence.
                        q.push(currentSequence); // Push the new sequence into the queue.
                        currentSequence.pop_back(); // Backtrack to explore other transformations.

                        usedOnLevel.push_back(lastWord); // Mark the word as used for this level.
                    }
                }

                lastWord[i] = originalChar; // Restore the original word.
            }
        }

        return result; // Return all shortest transformation sequences.
    }
};




bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	
        cout << "~" << "\n";
    }

	return 0;
}


/*

*/