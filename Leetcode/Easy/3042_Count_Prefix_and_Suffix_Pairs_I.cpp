/*

//  3042. Count Prefix and Suffix Pairs I


//  Problem Statement:
    -> You are given a 0-indexed string array words.
    -> Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2: isPrefixAndSuffix(str1, str2) returns true if str1 is both a prefix and a suffix of str2, and false otherwise.
    -> For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.
    -> Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.



// Example:

    Example 1:
        Input: words = ["a","aba","ababa","aa"]
        Output: 4
        Explanation: In this example, the counted index pairs are:
        i = 0 and j = 1 because isPrefixAndSuffix("a", "aba") is true.
        i = 0 and j = 2 because isPrefixAndSuffix("a", "ababa") is true.
        i = 0 and j = 3 because isPrefixAndSuffix("a", "aa") is true.
        i = 1 and j = 2 because isPrefixAndSuffix("aba", "ababa") is true.
        Therefore, the answer is 4.

    Example 2:
        Input: words = ["pa","papa","ma","mama"]
        Output: 2
        Explanation: In this example, the counted index pairs are:
        i = 0 and j = 1 because isPrefixAndSuffix("pa", "papa") is true.
        i = 2 and j = 3 because isPrefixAndSuffix("ma", "mama") is true.
        Therefore, the answer is 2.  

    Example 3:
        Input: words = ["abab","ab"]
        Output: 0
        Explanation: In this example, the only valid index pair is i = 0 and j = 1, and isPrefixAndSuffix("abab", "ab") is false.
        Therefore, the answer is 0.



// Observation: 
    -> given array of string, & we need to check weather prefix & suffix of two string that returns true.
    -> If s1 is both perrfix & suffix of s2, then return true, else false
    -> Count the total number of true case.


    //  We have to check if s1 is prefix & suffix of s2 or not?
        // BruteForce: 
            -> generate prefix & suffix of s2
            -> Check individually prefix & suffix case weather s1 is matching with anyone or not?
            -> If Yes return 1 : else return 0

            // Prefix & suffix of string:

                    aba
                    a ab aba    -> prefix

                    aba ba a -> Suffix


        // Efficient Approach:
            -> Using Two pointers:
            -> First check for prefix case:
            -> Second check for suffix case:


            // Prefix & suffix of string:

                    aba
                    a ab aba    -> prefix

                    aba ba a -> Suffix

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Approach
class Solution_Effi {
private:
    // Efficient Approach: 
    bool isPrefixAndSuffix(string &s1, string &s2){
        int n = s1.size();
        int m = s2.size();
        if(n > m) return 0; // case when s1 is grater than s2, means there is no chance of prefix value matched.

        // Check prefix:
        int j = 0;
        bool isFound1 = true;
        for(int i=0; i < n && isFound1;i++,j++){
            if(s1[i] != s2[j]){
                isFound1 = false;
            }
        }
        
        // Check Suffix:
        j = m-1;
        bool isFound2 = true;
        for(int i=n-1;i >= 0 && isFound2;i--,j--){
            if(s1[i] != s2[j]){
                isFound2 = false;
            }
        }

        if(isFound1 && isFound2) return 1;
        return 0;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();

        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                count += (isPrefixAndSuffix(words[i], words[j])) ? 1 : 0;
            }
        }

        return count;
    }
};


// BruteForce Approach:
class Solution {
private:
    // BruteForce Approach: 
    bool isPrefixAndSuffix(string &s1, string &s2){
        // Generate Prefix of s2:
        vector<string> pref(s2.size());
        pref[0] = s2[0];
        string pre = "";
        pre += s2[0];
        for(int i=1;i<s2.size();i++){
            pre += s2[i];
            pref[i] = pre;
        }

        // Generate Suffix of s2:
        vector<string> suff(s2.size());
        suff[s2.size()-1] = s2[s2.size()-1];
        string suf = "";
        suf += s2[s2.size()-1];
        for(int i=s2.size()-2;i>=0;i--){
            suf = s2[i] + suf;
            suff[i] = suf;
        }


        // Check prefix & suffix:
        bool suffFound = false;
        bool prefFound = false;

        for(int i=0;i<s2.size();i++){
            if(s1 == pref[i]) prefFound = 1;
            if(s1 == suff[i]) suffFound = 1;

            if(prefFound && suffFound) return 1;
        }

        return 0;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();

        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                count += (isPrefixAndSuffix(words[i], words[j])) ? 1 : 0;
            }
        }

        return count;
    }
};