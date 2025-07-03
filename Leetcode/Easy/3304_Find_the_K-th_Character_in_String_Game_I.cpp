/*

//  3304. Find the K-th Character in String Game I


//  Problem Statement: 
    -> Alice and Bob are playing a game. Initially, Alice has a string word = "a".
    -> You are given a positive integer k.
    -> Now Bob will ask Alice to perform the following operation forever:
        -> Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.
    -> For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
    -> Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.
    -> Note that the character 'z' can be changed to 'a' in the operation.

 
// Example:
    Example 1:
        Input: k = 5
        Output: "b"
        Explanation:
            Initially, word = "a". We need to do the operation three times:
                Generated string is "b", word becomes "ab".
                Generated string is "bc", word becomes "abbc".
                Generated string is "bccd", word becomes "abbcbccd".

    Example 2:
        Input: k = 10
        Output: "c"



// Observations:
    -> Start from string "a"
    -> Generate current string every time.
    -> append that generated string into our answer.
    -> return kth position of generated string.


// Complexity:
    -> TC: O(k)
    -> SC: O(k)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    string nextStr(string s) {  // function to generate next string from current string.
        for(auto &ch: s) {
            if(ch == 'z') ch == 'a';
            else ch++;
        }

        return s;
    }
public:
    char kthCharacter(int k) {

        string s = "a";
        while(s.size() <= k) {
            string next = nextStr(s);   // generate next string from the current ones.
            s += next;  // append next string in current string.
        }
        
        return s[k-1];  // return kth postion of string.
    }
};