/*

//  1930. Unique Length-3 Palindromic Subsequences


//  Problem Observation: 
    -> Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
        -> Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
            -> A palindrome is a string that reads the same forwards and backwards.
            -> A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
    -> For example, "ace" is a subsequence of "abcde".



// Example:

    Example 1:
        Input: s = "aabca"
        Output: 3
        Explanation: The 3 palindromic subsequences of length 3 are:
        - "aba" (subsequence of "aabca")
        - "aaa" (subsequence of "aabca")
        - "aca" (subsequence of "aabca")

    Example 2:
        Input: s = "adc"
        Output: 0
        Explanation: There are no palindromic subsequences of length 3 in "adc".

    Example 3:
        Input: s = "bbcbaba"
        Output: 4
        Explanation: The 4 palindromic subsequences of length 3 are:
        - "bbb" (subsequence of "bbcbaba")
        - "bcb" (subsequence of "bbcbaba")
        - "bab" (subsequence of "bbcbaba")
        - "aba" (subsequence of "bbcbaba")

 
// BruteForce Approach:
    -> Use nested loop to build given constrains & check palindrome.
    -> TC: O(n^3)


// Efficient Approach:

        I/p: s = "abaca"
        O/p: 3

            a b a c a
            0 1 2 3 4

        -> For 3 character palindrome, we need to fill first & last position:
                _ _ _ 

        -> In middle we can fill anything, which will always make palindrome.

                a b a c a
                | 

                a _ [_]            
            -> Now we have to find same character at last position.
                a b a c a
                |   |

                a _ a

                -> Here we can have one palindrome
                
                    "aba"
                    a b a c a
                    |       |
                
                -> Here we can fill anything b/w these two 'a' -> & that much palindrome we can have.
                    -> Possible Palindrome:
                        "aba", "aaa", "aca"

                    -> We have 3 palindrome here, but we have already found "aba", and we need only unique ones.
            -> So, we will always take rightmost character to form palindrome, which will remove the chance of duplicate.

        -> If we have example:

                "abaaca"

                        a b a a c a
                        |         |

                -> Tota possible Palindrome:
                    "aba", "aaa", "aaa", "aca",
                                   ---
                                    |
                            This one is duplicate, so we will use some set{} of characters which will store only unique values.
                
                        {b, a, c}   -> Size = 3,
                        -> At last we will return the set size.

        -> If we have example:

                s = "abcab"
            
            -> Then possible palindromes:

                a b c a b
                |     |
                    "aba", "aca"
                
                a b c a b
                  |     |
                    "bca", "bab"
            

        -> Everytime we wil iterate from last & check the number of sequence:
        -> NOTE: The difference b/w match characters should be grater or equal to 3, because we need 3 size palindrome.

    -> We need to find left most & right most occurrence of every character from string -> We can use set, which only store unique 26 characters.
    -> store the number of unique middle elements, which we can do with set.
    -> Last we will count the size of set & return the counter.

    // Complexity:
        -> TC: O(n), because O(26 * n) -> O(n)
        -> SC: O(1), because 26 size space.
    
    
    // Extra: 
        -> We can optimize this solution by precomputing leftmost & rightmost index & when we needed we only iterate and find those values.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Optimized Efficient Approach:
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        // Precompute leftmost & rightmost indices:
        vector<pair<int, int>> indices(26, {-1, -1}); // 26 size, because of lower letter only
        for(int i=0;i<n;i++){   // iterate in string:
            char ch = s[i];     // get the character.
            int idx = ch - 'a';     // a = 0, b = 1,..

            if(indices[idx].first == -1) {    // inserting leftmost index for every character, for the first time only.
                indices[idx].first = i;
            }
            
            indices[idx].second = i;  // inserting rightmost index for every character.
        }


        // Now iterate & find first & last occurrence of every characters:
        int res = 0;
        for(int i=0;i<26;i++){  // TC: O(26) times runs

            // Get leftmost & rightmost indices:
            int leftIdx = indices[i].first;
            int rightIdx = indices[i].second;


            // if we don't have leftmost index, means that character is not in our string.
            if(leftIdx == -1) continue;


            // Now, find middle characters b/w left most & right most index & store unique characters: 
            unordered_set<char> st;
            for(int mid = leftIdx + 1; mid <= rightIdx - 1; mid++){ // TC: O(n)
                st.insert(s[mid]);
            }

            // last add those possible palindrome into result counter.
            res += st.size();
        }

        return res;
    }
};


// Efficient Approach:
class Solution {
public:
    // Approach 1:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        // Store only unique characters of string: 
        unordered_set<char> letters;
        for(auto i: s) letters.insert(i);


        // Now iterate in these letters & find first & last occurrence of every characters:
        int res = 0;
        for(auto letter: letters){  // TC: O(26) times runs
            int leftIdx = -1;
            int rightIdx = -1;

            for(int i=0;i<n;i++){   // TC: O(n)
                // when we got match:
                if(letter == s[i]){ 
                    if(leftIdx == -1){  // store left index only once when first occur.
                        leftIdx = i;
                    }

                    rightIdx = i;   // store right index everytime so that at last we can have last index
                }
            }

            // Now, find middle characters b/w left most & right most index & store unique characters: 
            unordered_set<char> st;
            for(int mid = leftIdx + 1; mid <= rightIdx - 1; mid++){ // TC: O(n)
                st.insert(s[mid]);
            }

            // last add those possible palindrome into result counter.
            res += st.size();
        }

        return res;
    }
};


// BruteForce Solution: Iterative 
class Solution {
    int isPal(string s){
        int i = 0, j = s.size()-1;
        while(i < j){
            if(s[i++] != s[j--]) return 0;
        }
        return 1;
    }
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        int cnt = 0;

        set<string> st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    string temp = string() + s[i] + s[j] + s[k];
                    if(isPal(temp)){
                        st.insert(temp);
                    }
                }
            }
        }

        return st.size();
    }
};

// BruteForce: Recursive
class Solution {
private:
    int n;
    unordered_set<string> st;
    bool isPal(string &s) {
        int left = 0;
        int right = s.size() - 1;
        while(left <= right) {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void solve(string &s, string seq, int idx) {
        if(seq.size() == 3) {   // if we get 3 size, store & return..
            if(isPal(seq)) {
                st.insert(seq);
            }
            return;
        }
        
        if(idx < 0) return; // if we exhaust of characters..

        // Decision Tree:   Two choices -> accept / reject
        solve(s, seq + s[idx], idx - 1);
        solve(s, seq, idx - 1);
    }
public:
    int countPalindromicSubsequence(string s) {
        n = s.size();

        string seq = "";
        solve(s, seq, n - 1);
        
        return st.size();
    }
};