/*

//  2273. Find Resultant Array After Removing Anagrams


//  Problem Statement: 
    -> You are given a 0-indexed string array words, where words[i] consists of lowercase English letters.
    -> In one operation, select any index i such that 0 < i < words.length and words[i - 1] and words[i] are anagrams, and delete words[i] from words. Keep performing this operation as long as you can select an index that satisfies the conditions.
    -> Return words after performing all operations. It can be shown that selecting the indices for each operation in any arbitrary order will lead to the same result.
    -> An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase using all the original letters exactly once. For example, "dacb" is an anagram of "abdc".
 
// Example:
    Example 1:
        Input: words = ["abba","baba","bbaa","cd","cd"]
        Output: ["abba","cd"]
        Explanation:
        One of the ways we can obtain the resultant array is by using the following operations:
        - Since words[2] = "bbaa" and words[1] = "baba" are anagrams, we choose index 2 and delete words[2].
        Now words = ["abba","baba","cd","cd"].
        - Since words[1] = "baba" and words[0] = "abba" are anagrams, we choose index 1 and delete words[1].
        Now words = ["abba","cd","cd"].
        - Since words[2] = "cd" and words[1] = "cd" are anagrams, we choose index 2 and delete words[2].
        Now words = ["abba","cd"].
        We can no longer perform any operations, so ["abba","cd"] is the final answer.

    Example 2:
        Input: words = ["a","b","c","d","e"]
        Output: ["a","b","c","d","e"]
        Explanation:
        No two adjacent strings in words are anagrams of each other, so no operations are performed.

// Observations:
    -> Using stack approach will make our problem easy to solve solve.
    -> We can use stack & insert only unique strings..
    -> We can check the same matching string by simply getting the top element from stack & match with the current word by sorting them..

    // Complexity:
        -> TC: O(n * max(k*log k))
            -> n = words.size
            -> k = word_size
        -> SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {

        stack<string> st;
        for(auto &word: words) {
            if(st.empty())  {
                st.push(word);
                continue;
            }
            
            // Compare the words:
            string w1 = st.top();
            string w2 = word;

            sort(begin(w1), end(w1));
            sort(begin(w2), end(w2));
            
            if(w1 == w2) {
                continue;
            } else {
                st.push(word);
            }
        }

        // Transfer all the words from stack to vector:
        vector<string> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(begin(ans), end(ans));
        
        return ans;
    }
};