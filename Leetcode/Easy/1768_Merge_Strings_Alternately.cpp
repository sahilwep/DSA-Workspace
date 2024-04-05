/*
// 1768. Merge Strings Alternately          https://leetcode.com/problems/merge-strings-alternately/description/?envType=study-plan-v2&envId=leetcode-75

    Example 1:
        Input: word1 = "abc", word2 = "pqr"
        Output: "apbqcr"
        Explanation: The merged string will be merged as so:
        word1:  a   b   c
        word2:    p   q   r
        merged: a p b q c r

    Example 2:
        Input: word1 = "ab", word2 = "pqrs"
        Output: "apbqrs"
        Explanation: Notice that as word2 is longer, "rs" is appended to the end.
        word1:  a   b 
        word2:    p   q   r   s
        merged: a p b q   r   s

    Example 3:
        Input: word1 = "abcd", word2 = "pq"
        Output: "apbqcd"
        Explanation: Notice that as word1 is longer, "cd" is appended to the end.
        word1:  a   b   c   d
        word2:    p   q 
        merged: a p b q c   d

// Approach: 
    * we can use pointer i, which start from 0 & finish until it reaches to max size of both the strings.
    * till i < strings, we can store the each character inside the result string...


// TC : O(n)
// AS : O(n)

*/

#include<bits/stdc++.h>
using namespace std;

string mergeAlternately(string s1, string s2) {
    string res;
    int i = 0;
    while(i < s1.size() || i < s2.size()){
        if( i < s1.size()){
            res += s1[i];
        }
        if(i < s2.size()){
            res += s2[i];
        }
        i++;
    }
    return res;
}

int main(void){

    string s1,s2;
    cin >> s1 >> s2;

    cout << mergeAlternately(s1, s2) ;

    return 0;
}