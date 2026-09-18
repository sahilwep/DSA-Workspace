/*

//  433. Minimum Genetic Mutation


//  Problem Statement: 
    - A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
    - Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.
        - For example, "AACCGGTT" --> "AACCGGTA" is one mutation.

    - There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.
    - Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.
    - Note that the starting point is assumed to be valid, so it might not be included in the bank.

 
// Example:
    Example 1:
        Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
        Output: 1

    Example 2:
        Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
        Output: 2


// Observations:
    - given start and end string
    - and bank of strings
    - we can change any character to {A, C, G, T} only
    - and we will have to find the minimum number of transformations to reach from start to end.


    // BFS Approach:
        - we can use BFS to solve as every change cost takes only 1, so throughout it's constant, and BFS will help us to find the min-change overall, as constant wt throught.
        - it's just we will have to figure out the word transformations from the given startword and endword.
        - we can put the given bank into the unordered_set for O(1) time query.
        - for word transformations:
            - start with every character, and change to the given character, and try findin that into the set, as if it's found in that, we will push it into the BFS queue.
            - and explore it further.


        // Complexity:
            - TC: O(n * m)
            - SC: O(n)

                n = total words in bank
                m = size of given string.
 

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int minMutation(string startWord, string endWord, vector<string>& words) {
        int n = startWord.size();
        
        // push all the words into the set:
        unordered_set<string> st(begin(words), end(words)); // this work as visited also.

        // Edge case: if end-word is not found in words: can't be transformed:
        if(!st.count(endWord)) return -1;

        // Now perform BFS: word-transformations:
        vector<char> ch = {'A', 'C', 'G', 'T'};

        queue<string> q;
        int level = 0;
        q.push({startWord});

        while(!q.empty()) {
            int size = q.size();
            
            while(size--) {
                string word = q.front();
                q.pop();

                // If we reach end-word return the level.
                if(word == endWord) return level;

                // Word-transformations:
                for(int i = 0; i < n; i++) {
                    char c = word[i];
                    
                    // Every possible conversion: 
                    for(auto &val: ch) {
                        word[i] = val;

                        if(st.count(word)) {
                            st.erase(word);
                            q.push(word);
                        }
                    }

                    word[i] = c;    // revert it back to explore other possibility.
                }
            }

            level++;
        }

        return -1;  // not possible to transform
    }
};