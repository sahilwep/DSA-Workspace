/*
// 1662. Check If Two String Arrays are Equivalent       https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/


    Example 1:
        Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
        Output: true
        Explanation:
        word1 represents string "ab" + "c" -> "abc"
        word2 represents string "a" + "bc" -> "abc"
        The strings are the same, so return true.

    Example 2:
        Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
        Output: false

    Example 3:
        Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
        Output: true


// TC: O(n)
// AS: O(n)

*/

#include<bits/stdc++.h>
using namespace std;


bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    string s1;
    string s2;
    for(int i=0;i<word1.size();i++){
        s1 += word1[i];
    }   
    for(int i=0;i<word2.size();i++){
        s2 += word2[i];
    }
    if(s1 != s2){
        return false;
    }
    return true;
}




int main(void){

    vector<string> s1 = {"abc", "d", "defg"};
    vector<string> s2 = {"abcddefg"};

    int res = arrayStringsAreEqual(s1, s2);
    (res == 1) ? cout <<  "true" : cout <<  "false";

    return 0;
}


