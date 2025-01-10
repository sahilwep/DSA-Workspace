/*

//  916. Word Subsets


// Problem Statement:
    -> You are given two string arrays words1 and words2.
    -> A string b is a subset of string a if every letter in b occurs in a including multiplicity.
        -> For example, "wrr" is a subset of "warrior" but is not a subset of "world".
    -> A string a from words1 is universal if for every string b in words2, b is a subset of a.
    -> Return an array of all the universal strings in words1. You may return the answer in any order.

 
// Example:
    Example 1:
        Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
        Output: ["facebook","google","leetcode"]

    Example 2:
        Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
        Output: ["apple","google","leetcode"]



// Optimization:
    ->  We need to check whether the required characters exist with sufficient frequency while iterating through words1:

        Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
        Output: ["facebook","google","leetcode"]

    -> First, store the frequency of characters for all strings in words2.
    -> Then, while iterating through words1, hash the string frequencies and compare them with the aggregated frequency requirements from words2.

        -> Problem:
            If we directly store the frequencies from words2, certain issues might arise:

                Input:
                    words1 = ["amazon","apple","facebook","google","leetcode"]
                    words2 = ["lo","eo"]
                Output: ["google","leetcode"]

                Here, the frequency count for words2 is:

                    l = 1
                    o = 2
                    e = 1

                However, "leetcode" is included in the output even though it does not satisfy the frequency requirement for 'o'.

            Another Example:

                Input:
                    words1 = ["amazon","apple","facebook","google","leetcode"]
                    words2 = ["e","oo"]
                    
                Output: ["facebook","google"]

                Here, the frequency count for words2 is:
                    e = 1
                    o = 2

                Only words with at least 2 'o' characters and 1 'e' character are included in the result.

        // Solution: 

            To solve this issue, while aggregating the frequency requirements for words2, we will store the maximum frequency required for each character across all strings in words2.

            Example:
                Input:
                    words1 = ["amazon","apple","facebook","google","leetcode"]
                    words2 = ["lo","eo"]
                Output: ["google","leetcode"]

                The updated frequency count for words2 becomes:

                    l = 1
                    o = 1
                    e = 1

                Here, 'o' is updated to 1 because, across all strings in words2, 'o' appears a maximum of 1 time in any string.



// Complexity:
    -> TC: O( m * l2 ​+ n * l1​)

        -> m: Number of strings in w2.
        -> l2​: Average length of strings in w2.
        -> n: Number of strings in w1.
        -> l1​: Average length of strings in w1.



*/
#include<bits/stdc++.h>
using namespace std;


// Clean & Optimized Code:
class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        vector<int> freq(26, 0);    // This is the final freq array for w2

        for(int i=0;i<w2.size();i++){
            string s = w2[i];
            vector<int> tempFreq(26, 0);    // tempFreq for every string of w2
            for(int j=0;j<s.size();j++){
                tempFreq[s[j] - 'a']++;
            }

            // everytime store the maximum freqCount from every string in final freq:
            for(int j=0;j<26;j++){
                freq[j] = max(freq[j], tempFreq[j]);
            }
        }


        vector<string> res;
        for(int i=0;i<w1.size();i++){   // last iterate in w1 & check:
            // get the string of w1 & store the frequency:
            string s = w1[i];
            vector<int> tempFreq(26, 0);
            for(int j=0;j<s.size();j++){
                tempFreq[s[j] - 'a']++;
            }

            // Now compare it with original freq Count if it's less then return false for that string:
            bool flag = true;
            for(int j=0;j<26;j++){
                if(freq[j] != 0){
                    if(tempFreq[j] < freq[j]){
                        flag = false;
                        break;
                    }

                }
            }

            if(flag) res.push_back(s);  // storing that string who satisfy the condition.
        }

        return res;
    }
};


// Accepted Solution Using map:
class Solution_Accepted {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
        map<char, int> mp1;
        for(int i=0;i<w2.size();i++){
            string s = w2[i];
            unordered_map<char, int> tmp;
            for(auto j: s){
                tmp[j]++;
            }

            // everytime store the maximum freqCount from every character:
            for(auto i: tmp){
                char ch = i.first;
                int freq = i.second;
                if(mp1.find(ch) != mp1.end()){
                    mp1[ch] = max(mp1[ch], freq);
                }
                else{
                    mp1[ch] = freq;
                }
            }
        }

        vector<string> res;
        for(int i=0;i<w1.size();i++){
            string s = w1[i];
            unordered_map<char, int> mp2;
            for(auto j: s) mp2[j]++;

            // After that check Weather mp2 had all character in mp1 or not?
            bool flag = true;
            for(auto j: mp1){
                char ch = j.first;
                int times = j.second;
                if(mp2.find(ch) == mp2.end()){
                    flag = false;
                }
                else{
                    if(mp2[ch] < times){
                        flag = false;
                    }
                }
            }
            if(flag){
                res.push_back(s);
            }
        }

        return res;
    }
};


// BruteForce Solution: 
class Solution_Brute {
private:
    bool findSubset(string &s1, string &s2){
        // Hash Every string charcters & found:
        unordered_map<char, int> mp1;
        for(auto i: s1) mp1[i]++;
        unordered_map<char, int> mp2;
        for(auto i: s2) mp2[i]++;
        
        for(auto i: mp2){
            int ch = i.first;
            int times = i.second;
            
            if(mp1.find(ch) == mp1.end()){
                return false;
            }
            else{
                if(mp1[ch] < times){
                    return false;
                }
            }
        }

        return true;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;

        for(int i=0;i<words1.size();i++){
            bool flag = true;
            for(int j=0;j<words2.size();j++){
                flag = findSubset(words1[i], words2[j]);
                if(!flag) break;
            }
            if(flag){
                res.push_back(words1[i]);
            }
        }

        return res;
    }
};