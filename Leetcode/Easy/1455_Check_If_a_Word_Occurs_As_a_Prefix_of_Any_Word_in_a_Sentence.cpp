/*

//  1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence


// Problem Statement:
    * Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.
    * Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.
    * A prefix of a string s is any leading contiguous substring of s.

// Example: 

    Example 1:
        Input: sentence = "i love eating burger", searchWord = "burg"
        Output: 4
        Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.

    Example 2:
        Input: sentence = "this problem is an easy problem", searchWord = "pro"
        Output: 2
        Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.

    Example 3:
        Input: sentence = "i am tired", searchWord = "you"
        Output: -1
        Explanation: "you" is not a prefix of any word in the sentence.

 

// Extra: 

    -> I was trying to use string.find() & comparing with npos to get match string, but this function only return first occurrence of substring, So testcase like this can be failed.. :(
    Testcase:
        sentence = "pillow love winstontang i pillow corona you errichto love"
        searchWord = "i"


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string s, string sW) {
        s = ' ' + s;

        int pos = -1;
        for(int i=1;i<s.size();i++){
            if(s[i-1] == ' ' && s[i] == sW[0]){
                int ptr = i;
                int size = 0;
                for(int j=0;j<sW.size();j++){
                    if(sW[j] != s[ptr]){
                        break;
                    }else{
                        size++;
                    }
                    ptr++;
                }
                if(size == sW.size()){
                    pos = i;
                    break;
                }
            }
        }
        if(pos == -1) return -1;

        int cnt = 0;
        for(int i=0;i<pos;i++){
            if(s[i] == ' ') cnt++;
        }

        return cnt;
    }
};