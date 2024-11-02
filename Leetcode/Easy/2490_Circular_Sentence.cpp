/*

// 2490. Circular Sentence

// Problem Statement:
    * A sentence is a list of words that are separated by a single space with no leading or trailing spaces.
        For example, "Hello World", "HELLO", "hello world hello world" are all sentences.

    * Words consist of only uppercase and lowercase English letters. Uppercase and lowercase English letters are considered different.

    * A sentence is circular if:
        * The last character of a word is equal to the first character of the next word.
        * The last character of the last word is equal to the first character of the first word.
        
    * For example, "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" are all circular sentences. 
    * However, "Leetcode is cool", "happy Leetcode", "Leetcode" and "I like Leetcode" are not circular sentences.

    * Given a string sentence, return true if it is circular. Otherwise, return false.


// Example:

    Example 1:

    Input: sentence = "leetcode exercises sound delightful"
    Output: true
    Explanation: The words in sentence are ["leetcode", "exercises", "sound", "delightful"].
    - leetcode's last character is equal to exercises's first character.
    - exercises's last character is equal to sound's first character.
    - sound's last character is equal to delightful's first character.
    - delightful's last character is equal to leetcode's first character.
    The sentence is circular.

    Example 2:

    Input: sentence = "eetcode"
    Output: true
    Explanation: The words in sentence are ["eetcode"].
    - eetcode's last character is equal to eetcode's first character.
    The sentence is circular.

    Example 3:

    Input: sentence = "Leetcode is cool"
    Output: false
    Explanation: The words in sentence are ["Leetcode", "is", "cool"].
    - Leetcode's last character is not equal to is's first character.
    The sentence is not circular.

 
// Intrusion:
    // Bruteforce Solution:
        * Extract every word from string, & then apply checks..
        * TC: O(n)
        * AS: O(n)


    // Efficient Solution:
        * Whenever we are encounter with " ", empty part of string, check (s[i-1] & s[i+1])
        * TC: O(n)
        * AS: O(1)


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Bruteforce Solution:
    bool isCircularSentence_Brute(string s) {
        int n = s.size();
        vector<string> res;
        // extract string from sentence.
        string temp = "";
        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                res.push_back(temp);
                temp = "";
            }
            else{
                temp += s[i];
            }
        }
        // storing last character int result:
        if(!temp.empty()){
            res.push_back(temp);
        }

        // Circular Checks:
        // check for single element:
        if(res.size() == 1){
            if(res[0][res[0].size()-1] == res[0][0]){
                return 1;   // single string
            }else{
                return 0;
            }
        }

        // check for multiple element:
        for(int i=1;i<res.size();i++){
            string last = res[i-1];
            string curr = res[i];
            if(last[last.size() -1] != curr[0]){
                return 0;
            }
        }

        // last check for last element:
        string last = res[res.size()-1];
        string first = res[0];
        if(last[last.size() - 1] != first[0]) return 0;

        return true;
    }

    // Efficient Solution:
    bool isCircularSentence(string s) {
        int n = s.size();
        // Check for single element:
        if(s.size() == 1){
            if(s[0] == s[n-1]) return 1;
            return 0;
        }

        // extract string from sentence.
        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                if(s[i-1] != s[i+1]) return 0;
            }
        }
        // last check:
        if(s[0] != s[n-1]) return 0;

        return true;
    }
};