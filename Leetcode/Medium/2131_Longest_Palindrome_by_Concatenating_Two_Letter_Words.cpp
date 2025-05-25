/*

//  2131. Longest Palindrome by Concatenating Two Letter Words


//  Problem Link: 
    -> You are given an array of strings words. Each element of words consists of two lowercase English letters.
    -> Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
    -> Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
    -> A palindrome is a string that reads the same forward and backward.

 
// Example: 

    Example 1:
        Input: words = ["lc","cl","gg"]
        Output: 6
        Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
        Note that "clgglc" is another longest palindrome that can be created.

    Example 2:
        Input: words = ["ab","ty","yt","lc","cl","ab"]
        Output: 8
        Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
        Note that "lcyttycl" is another longest palindrome that can be created.

    Example 3:
        Input: words = ["cc","ll","xx"]
        Output: 2
        Explanation: One longest palindrome is "cc", of length 2.
        Note that "ll" is another longest palindrome that can be created, and so is "xx".

 


// Observations: 
    -> We are given list of words & every word has exactly len = '2'.
    -> Word inside words are: 
            "aa"    -> palindrome type
        
            "ab"    -> not a palindrome type, but they have opposite pairs like: "ba"
                    "ab", "ba"
                        "abba" -> form palindrome..

    -> We have to return the length of longest palindrome we can form by concatenating the words in any order..
    
    // Key Observations: 
        -> Example:
            words = ["ab","ty","yt","lc","cl","ab","cc", "cc", "bb"]

        -> If somehow we can hash these word we can compute our results.

                    ab = 2
                    ty = 1
                    yt = 1
                    lc = 1 
                    cl = 1
                    cc = 2
                    bb = 1

        -> From the above frequency we can observe:
            -> Some words have palindromic ("cc", "bb") frequency.
            -> Some words have non-palindromic ("ab", "ty", "lc") frequency.
            -> Some words have their reversed pairs hashed into map: ("ty" & "yt"), ("lc" & "cl")

    // Solution: 
        -> Let's break this problem into multiple module & solve these individually:

        // Step 1: hash the words into map:

            words = ["ab","ty","yt","lc","cl","ab","cc", "cc", "bb"]

            map:    ab = 2
                    ty = 1
                    yt = 1
                    lc = 1 
                    cl = 1
                    cc = 2
                    bb = 1

        // Step 2: Solve palindromic pairs or same pairs:

            Palindromic pairs:
                        "cc": 2
                        "bb": 1

            -> We have odd & even frequency.
            -> Let's observe some case of odd & even Frequency:

                Case 1: "aa", "aa", "aa", "bb", "bb", "cc", "cc", "dd"
                        "aa": 3
                        "bb": 2
                        "cc": 2
                        "dd": 1

                Case 2: "aa", "aa", "aa", "bb", "bb", "bb", "cc", "cc", "dd", "dd", "ee"
                        "aa": 3
                        "bb": 3
                        "cc": 2
                        "dd": 2
                        "ee": 1
            
            -> From the above observations "Even" don't make any noise while making pairs.
                -> We can directly include the even pairs into our count.
                    cnt += (freq * 2)
            
            -> Odd Frequency should have been taken care carefully:
                -> When we include odd frequency to our pair count we have to take care of some case:
                -> Example:         
                        "aa": 3
                        "bb": 3
                        "cc": 2
                        "dd": 2
                        "ee": 1

                                dd cc bb aa aa aa bb cc dd
                        
                        -> from all the above odd frequency, we have include only one odd frequency "aa"
                        -> rest all the odd frequency like: "bb" & "ee" we have consider as even frequency:
                            -> simply treat them as:    cnt +=  ((freq - 1) * 2)
                
                -> Edge case:  "aa", "aa", "bb", "bb", "cc", "cc", "dd", "dd", "ee"

                                "aa": 2
                                "bb": 2
                                "cc": 2
                                "dd": 2
                                "ee": 1

                        -> With the above logic for this odd "ee": turn out to be '0'
                                cnt += ((freq - 1) * 2) => 0 

                        -> we need to maintain one flag to track odd frequency.
                        -> last by checking this flag we can add (cnt += 2) as middle resulting:

                                    aa bb cc dd ee dd cc bb aa
                                                --
    
        // Step 3: Solve distinct pairs or non-palindromic reversed pairs:

            -> Example: 

                words = ["ab","ty","yt","lc","cl","ab","cc", "cc", "bb"]
                map:    ab = 2
                        ty = 1
                        yt = 1
                        lc = 1 
                        cl = 1
                        cc = 2
                        bb = 1

            -> for every word: 
                -> get the reversed of it.
                -> make sure word != reversed -> to reject the palindrome case like "aa", "bb"
                -> Now try findin reversed word from map:
                    -> If reversed word is there:
                        -> Get the minimum frequency from {include =  min(word_freq, reversed_word_freq)}
                        -> include that into our count:
                            cnt += (include * 2) + (include * 2)
                                    ------------    ------------
                        for ->        word      &   reversed_word


        -> Lastly, compute the result By adding cnt from step_1 & step_2

// Complexity: 
    -> TC: O(n * l)
        -> n = number of words
        -> l = length of words
    
    -> SC: O(n * l)
    
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private: 
    // Function to compute palindrome:
    bool isPal(const string& s) {
        return s[0] == s[1];
    }
public:
    int longestPalindrome(vector<string>& words) {
        
        // Step 1: Hash words into map:
        unordered_map<string, int> mp;
        for(auto &word: words) mp[word]++;
        

        // Step 2: Compute the middle pairs:
        int midPairs = 0;
        bool isOddPairs = false;    // flag to keep track of odd frequency.

        for(auto &[word, freq]: mp) {
            if(isPal(word)) {   // for every palindrome:

                // Get Pairs count:
                if(freq % 2 == 0) {
                    midPairs += (freq * 2);
                } else {
                    midPairs += ((freq - 1) * 2);
                    isOddPairs = true;
                }
            }
        }
        
        // If odd Frequency Available:
        if(isOddPairs) midPairs += 2;   // add single pair as middle, becaus we have computed all odd as even.


        // Step 3: Now get the distinct side pairs for palindrome:
        int sideCnt = 0;
        for(auto &[word, freq]: mp) {
            // Reverse the current word & find in map:
            string revWord = word;
            reverse(begin(revWord), end(revWord));

            // If opposite word is found in map:
            if(word != revWord && mp.count(revWord)) {
                int canIncludeInPal = min(mp[revWord], mp[word]);   // the number of pairs we can include in our palindrome.

                // Now remove frequency count for (word & revWord) from map.
                mp[word] -= canIncludeInPal;
                mp[revWord] -= canIncludeInPal;

                // Add count (for word pairs) & (for reverse word pairs)
                sideCnt += (canIncludeInPal * 2) + (canIncludeInPal * 2);   
            }
        }

        // Final size of palindrome:
        int sizeOfPal = sideCnt + midPairs;
        
        return sizeOfPal;
    }
};