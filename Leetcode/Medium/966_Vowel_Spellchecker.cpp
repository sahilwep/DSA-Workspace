/*

//  966. Vowel Spellchecker


//  Problem Statement: 
    -> Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.
    -> For a given query word, the spell checker handles two categories of spelling mistakes:
        -> Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
            Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
            Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
            Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
        -> Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
            Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
            Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
            Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
    -> In addition, the spell checker operates under the following precedence rules:
        -> When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
        -> When the query matches a word up to capitalization, you should return the first such match in the wordlist.
        -> When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
        -> If the query has no matches in the wordlist, you should return the empty string.
    -> Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].

    
// Example:
    Example 1:
        Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
        Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]

    Example 2:
        Input: wordlist = ["yellow"], queries = ["YellOw"]
        Output: ["yellow"]


// Observations:
    -> To match the given word we have two things to consider:
        -> When query exactly matches a word in the wordlist -> you should return the same word block
        -> When the query matches a word up to capitalization, you should return the first such match in the worlist
        -> When the query matches a word up to vowel error, you should return the first such match in the wordlist.
        -> If the query has no matched in the wordlist, you should return the empty string.


        // Capitalization:
            -> If any query matches a word in the wordlist(case-insensitive)
            -> Query would return with the same case as the case in the wordlist:
                // Example:
                    wd:"yellow"     q:"Yellow"      Correct:"yellow"
                    wd:"Yellow"     q:"yellow"      Correct:"Yellow"


        // Vowel Error: 
            -> If after replacing the vowels {'a', 'e', 'i', 'o', 'u'} of the query word with any vowel individually.
            -> It matches a word in the wordlist(case-insensitive), then query word is returned with the same case as the match in the wordlist.
                // Example:
                    wd:"YellOw"     q:"Yollow"      Correct:"YellOw"
                    wd:"YellOw"     q:"yeellow"     correct:""
                    wd:"YellOw"     q:"yllw"        correct:""


        // Approach:
            -> Create a Separate function to check every conditions:
            -> First we will check the same word from wordlist.
            -> Second we will check the Capitalize case
            -> Third we will check the vowel error.
            -> If above cases passes, we skip the later on checking else if fails, we will store empty string.
            -> last return answer, where ans[i] satisfies query[i].
            -> This Gives TLE

            // Complexity:
                -> TC: O(query.size() * wordlist.size() * max(word.size()))
                -> SC: O(wordlist.size())
 
        // Optimization:
            -> We are checking every conditions on-by-one & Everytime we are iterating in whole wordlist, What if somehow we can optimize the query operations..
            -> Something like preprocessing the wordlist for every separate case
            
            // Preprocess wordlist into three sections:
                -> Same Word: exact match
                    -> We can use some set, which store all the wordlist word, & directly find the matched word.
                -> Capitalize map:
                    -> This store all the lowerCase of wordlist & store the first only word from wordlist.
                -> VowMap:  
                    -> De-vowel string, & this should be first original.
                -> Each query is resolved in O(word_length) instead of scanning entire wordlist.

        
            // Complexity:
                -> TC: O(wordlist.size() * maxWordLength + queries.size() * maxWordLength)
                -> SC: O(wordlist.size() * maxWordLength)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    bool isVow(char &ch) {return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');}  // TC: O(1)
    string makeLower(string &s) {   // TC: O(word.size())
        string temp = "";
        for(auto &ch: s) {
            if(ch < 'a') {
                temp.push_back(ch - 'A' + 'a');
            } else {
                temp.push_back(ch);
            }
        }
        
        return temp;
    }
    string isCapFound(vector<string>& wordlist, string &s) {    // TC: O(wordlist.size() * max(word.size()))
        // Make all the characters into lowerCase of given string:
        string temp = makeLower(s);

        // Now Iterate in wordlist & try making all the word in lower & try match with it:
        for(auto &word: wordlist) {
            if(word.size() != temp.size()) continue;
            string w1 = makeLower(word);
            if(w1 == temp) return word; // return word
        }

        return "";  // return empty string
    }
    bool bothVow(char a, char b) {  // TC: O(1)
        return isVow(a) && isVow(b);
    }
    string isVowErr(vector<string>& wordlist, string &s) {  // TC: O(wordlist.size() * max(word.size()))
        string temp = makeLower(s);
        int n = temp.size();

        for(auto &word: wordlist) {
            string w1 = makeLower(word);

            if(w1.size() != n) continue;

            // Now check each character by character for vowelError:
            bool vowErr = true;
            for(int i = 0; i < n; i++) {
                if(w1[i] == temp[i]) continue;

                // Mismatched only allowed if they are vowel: It is NOT the case that both are vowels.
                if(!bothVow(w1[i], temp[i])) { // if both are vowel: false, else true
                    vowErr = false;   // mismatch is not allowed
                    break;        // reject this word
                }
            }
            
            if(vowErr) {
                return word;    // valid vowel error matched
            }
        }

        return "";
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n = queries.size();

        // Preprocess Wordlist: // SC: O(wordlist.size())
        unordered_set<string> st;
        for(auto &s: wordlist) st.insert(s);

        vector<string> ans(n, "");
        for(int i = 0; i < n; i++) {   //  TC: O(query.size() * wordlist.size() * max(word.size()))
            string s = queries[i];

            // Step 1: Check for same Matched word:
            if(st.count(s)) {   // TC: O(max(word.size()))
                ans[i] = s;
                continue;
            }

            // Step 2: Check for Captivation:
            string val = isCapFound(wordlist, s);   // TC: O(wordlist.size() * max(word.size()))
            if(val != "") {
                ans[i] = val;
                continue;
            }

            // Step 3: Check for Vowel Error:
            string vals = isVowErr(wordlist, s);  // TC: O(wordlist.size() * max(word.size()))
            if(vals != "") {
                ans[i] = vals;
                continue;
            }

            // word not found in wordlist:
            ans[i] = "";    // make it empty string.
        }


        
        return ans;
    }
};