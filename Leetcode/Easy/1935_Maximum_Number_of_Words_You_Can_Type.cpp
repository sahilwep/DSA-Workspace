/*

//  1935. Maximum Number of Words You Can Type


//  Problem Statement: 
    -> There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.
    -> Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.

 
// Example:

    Example 1:
        Input: text = "hello world", brokenLetters = "ad"
        Output: 1
        Explanation: We cannot type "world" because the 'd' key is broken.

    Example 2:
        Input: text = "leet code", brokenLetters = "lt"
        Output: 1
        Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.

    Example 3:
        Input: text = "leet code", brokenLetters = "e"
        Output: 0
        Explanation: We cannot type either word because the 'e' key is broken.


// Solution:
    -> Write a Solution that check any x number of separated word with ' ', & add up the word if it has no brokenLetters....
    -> Easy to implement
    -> Constrains define range {0-26} -> Even if we take u_set, it will take only O(26) -> O(1) complexity for query in broken word...

    // Complexity
        -> TC: O(N), N = text.size()
        -> SC: O(1)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    int n;
    bool isBrokenWordFound(int &i,  string &text, unordered_set<char> &st) {
        bool found = false;
        for(; i < n; i++) {
            if(text[i] == ' ') {
                i++;             // increment the ith position, either it will fall into TLE
                break;          // Only breaks out when the word is finishes..
            } 
            if(st.count(text[i])) {
                found = true;
            }
        }

        return found;
    }
public:
    int canBeTypedWords(string text, string brokenLetters) {
        n = text.size();
        
        unordered_set<char> st;
        for(auto &ch: brokenLetters) st.insert(ch);
        
        int typeWord = 0;

        // Iterate & Found typeable word for any number of space ' ', not limited to 2 only.
        int i = 0;
        while(i < n) {
            if(!isBrokenWordFound(i, text, st)) typeWord++; // If No-broken word found, then only adds up into answer..
        }

        return typeWord;
    }
};