/*

//  1768. Merge Strings Alternately


//  Observations: 
    * We are given two string, & we need to merge them..

// Example:

    Input: word1 = "abc", word2 = "pqr"
    Output: "apbqcr"
    Explanation: The merged string will be merged as so:
        word1:  a   b   c
        word2:    p   q   r
        merged: a p b q c r


    Input: word1 = "ab", word2 = "pqrs"
    Output: "apbqrs"
    Explanation: Notice that as word2 is longer, "rs" is appended to the end.
        word1:  a   b 
        word2:    p   q   r   s
        merged: a p b q   r   s



    Input: word1 = "abcd", word2 = "pq"
    Output: "apbqcd"
    Explanation: Notice that as word1 is longer, "cd" is appended to the end.
        word1:  a   b   c   d
        word2:    p   q 
        merged: a p b q c   d


// Intrusion: 
    * We will start inserting value from start into result, 
        * When size is same for both the string, we just have to iterate from start to end & insert all the values..
        * When size is different of both the string, we have to take care of left over values from largest size sting..
    * TC: O(max(a.size(), b.size())), a & b are string

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string res = "";
        int n = w1.size();
        int m = w2.size();
        int a = 0;
        // exit only when smallest among them has all values are inserted into result.
        while(a < w1.size() && a < w2.size()){
            res += w1[a];
            res += w2[a];
            a++;
        }

        // if w1 has left value:
        while(a < w1.size()){
            res += w1[a++];
        }
        // if w2 has left value:
        while(a < w2.size()){
            res += w2[a++];
        }

        return res;
    }
};