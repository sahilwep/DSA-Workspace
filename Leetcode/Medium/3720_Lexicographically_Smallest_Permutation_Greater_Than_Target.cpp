/*

//  3720. Lexicographically Smallest Permutation Greater Than Target


//  Problem Statement: 
    -> You are given two strings s and target, both having length n, consisting of lowercase English letters.
    -> Return the lexicographically smallest
    -> of s that is strictly greater than target. If no permutation of s is lexicographically strictly greater than target, return an empty string.
    -> A string a is lexicographically strictly greater than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b.


//  Example: 
    Example 1:
        Input: s = "abc", target = "bba"
        Output: "bca"
        Explanation:
            The permutations of s (in lexicographical order) are "abc", "acb", "bac", "bca", "cab", and "cba".
            The lexicographically smallest permutation that is strictly greater than target is "bca".

    Example 2:
        Input: s = "leet", target = "code"
        Output: "eelt"
        Explanation:
            The permutations of s (in lexicographical order) are "eelt", "eetl", "elet", "elte", "etel", "etle", "leet", "lete", "ltee", "teel", "tele", and "tlee".
            The lexicographically smallest permutation that is strictly greater than target is "eelt".

    Example 3:
        Input: s = "baba", target = "bbaa"
        Output: ""
        Explanation:
            The permutations of s (in lexicographical order) are "aabb", "abab", "abba", "baab", "baba", and "bbaa".
            None of them is lexicographically strictly greater than target. Therefore, the answer is "".


// BruteForce Solution: 
    -> Generate all the permutations.
    -> Sort them to make all of them in order..
    -> from that permutations: compare it with target.
    -> IF we found any just grater => return that, else return empty string..
    ->  MLE
        -> factorial growth (O(n!))

    
    // Optimization: 
        - While generating the permutations, we will try to avoid useless branch, where we have lesser values..
        - We can consider only those part where, we have either: equal or grater
        - To optimize, we use "backtracking with pruning", where we only explore branches that can potentially lead to a valid greater permutation.
        - The idea is to gradually build our result string `curr`, one character at a time, and skip exploring any branches that are definitely smaller than `target`.
        - When we generate the permutation, it's just the character placing is changed, the frequency of total characters should not be changed..
                eg:     s = "abc"
                        perm: "abc", "acb", "bac", "bca", "cab", "cba"

                    -> These all we can generate from given 's'
                    -> What i want to say, position of characters will be changed, the frequency will not be changed..


        - Now we need smallest permutations, which will be just grater than the given target:
                eg: s = "abc",   target = "bba"

                    map {a: 1, b: 1, c: 1}

                        answer: _ _ _   -> It will be of same size of string s.
                        
                        ans[0]: 
                            {target[0] = b}
                            it can either be 'b' or grater than 'b', In simple (ans[i] >= target[i])
                            check we have 'b' in original string 's' "yes", then use it..
                                ans[0] = 'b'
                                map {a: 1, b: 0, c: 1}      (Decrement: mp[b])
                        
                        ans[1]: 
                            {target[1] = b}
                            it can either be 'b' or grater than 'b',
                            Check we have 'b' in original string 's' "NO", 
                            Check for just next character, 'c' "yes" 
                                ans[1] = 'b'
                                map{a: 1, b: 0, c: 0}       (Decrement: mp[c])
                            
                        ans[2]: 
                            {target[2] = a}
                            it can either be 'a' or grater than 'a',
                            Check we have 'a' in original string 's' "Yes", Use it
                                ans[1] = 'a'
                                map{a: 0, b: 0, c: 0}       (Decrement: mp[a])
                            
                            answer: "bba"   -> this is the permutation of s, which is just grater than the given "target"

    // Approach:
        -> Step 1: 
            We first store the frequency of each character in `s`, since any valid permutation must use the same set of characters with the same frequencies.

        -> Step 2:
            We define a recursive function `solve(curr, target, freq, idx)` that tries to build all possible permutations of `s` using the available frequencies.
                - [curr] : holds the current partially formed string.
                - [idx]  : is the current index we are filling in.
                - [freq] : keeps track of which characters are still unused.

        -> Step 3:
            At each recursive step, we iterate over all possible characters from 'a' to 'z'. If a character’s frequency is zero, it’s already used — we skip it.

            Before using any character, we check:
                - Whether the prefix formed so far matches the prefix of `target`.
                - If the prefixes are equal and the next character we are about to place is **less than** the corresponding target character, then placing it would make the overall string smaller — such branches are skipped early.

        -> Step 4:
            We continue this process recursively, placing characters one by one. 
            Once we form a complete string (`curr.size() == target.size()`), we compare it with the target.
                - If `curr` is lexicographically greater, we record it as the answer and mark `isAnswerFound = true` to stop further exploration.

        -> Step 5:
            During recursion, we also backtrack:
                - Remove the last added character.
                - Restore its frequency count.
              This allows us to explore other possible valid character choices.

        // Key Points:
            - The algorithm uses frequency counting to handle repeated characters correctly.
            - Prefix-based pruning avoids generating all permutations, improving efficiency.
            - Once an answer is found, we immediately stop searching further.


        // Complexity: 
            -> TC: O(n! * n), but it's more optimized, as we reject branches with our define constrains..
            -> SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Optimized Solution: 

class Solution {
private: 
    int n;
    string ans;
    bool isAnswerFound = false;
    void solve(string &curr, string &target, vector<int> &freq, int idx) {
        if(isAnswerFound) return;    // answer is already, found, return back..

        if(idx == (int)target.size()) {
            if(curr.compare(target) > 0) {  // compare func gives 3 output(-1(lesser), 0(equal), 1(greater))
                isAnswerFound = true;
                ans = curr;
            }

            return;
        }

        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;
            char ch = (char)(i + 'a');

            // Check prefix matching efficiently:
            bool isPrefixEqual = true;
            for(int j = 0; j < idx; j++) {
                if(curr[j] != target[j]) {
                    isPrefixEqual = false;
                    break;
                }
            }

            // if we have matching prefix & current character is lesser than the target, avoid that branch..
            if(isPrefixEqual && ch < target[idx]) continue;
            
            curr.push_back(ch);
            freq[i]--;
            solve(curr, target, freq, idx + 1);
            curr.pop_back();
            freq[i]++;
        }
    }
public:
    string lexGreaterPermutation(string s, string target) {
        n = s.size();

        vector<int> freq(26, 0);
        for(auto &ch: s) {
            freq[ch - 'a']++;
        }

        // Generate all the given string:
        string curr = "";
        solve(curr, target, freq, 0);

        return (isAnswerFound) ? ans : "";    // return answer string, if answer is found, else return empty string..
    }
};
 


// BruteForce Solution:
class Solution {
private: 
    int n;
    vector<string> perm;
    string tar;
    void solve(int idx, string &s) {    // Generate Permutations:
        if(idx == n) {
            perm.push_back(s);
        }

        // For every index Try Generating permutations, by Swapping...
        for(int i = idx; i < n; i++) {
            swap(s[i], s[idx]);
            solve(idx + 1, s);  // Stack call for next index.
            swap(s[i], s[idx]);
        }
    }
public:
    string lexGreaterPermutation(string s, string target) {
        n = s.size();
        tar = target;

        // Generate permutations:
        solve(0, s);

        sort(begin(perm), end(perm));   // sort them to make it in order.

        // Debugging:
        // for(auto &it: perm) cout << it << " ";
        // cout << endl;

        // Compre the generated with target:
        for(auto &str: perm) {
            for(int i = 0; i < n; i++) {
                if(str[i] == target[i]) continue;   // if it's equal, go for next character comparision.
                if(str[i] > target[i]) return str;  // if it's just grater than target, return that as our answer.
                else break; // if it's lesser, no need to check further, break out...
            }
        }

        return "";
    }
};