/*

//  2785. Sort Vowels in a String



//  Problem Statement: 
    -> Given a 0-indexed string s, permute s to get a new string t such that:
        -> All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, then t[i] = s[i].
        -> The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
    -> Return the resulting string.
    -> The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in lowercase or uppercase. Consonants comprise all letters that are not vowels.

 

// Example:
    Example 1:
        Input: s = "lEetcOde"
        Output: "lEOtcede"
        Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.

    Example 2:
        Input: s = "lYmpH"
        Output: "lYmpH"
        Explanation: There are no vowels in s (all characters in s are consonants), so we return "lYmpH".


// Observations: 

        Input: s = "lEetcOde"
        Output: "lEOtcede"

            s       =   l E e t c O d e
            vowels  =   E e O e

            sort in nodescending order: in ASCII format: 

                        A = 65

                        a = 97

            -> Fist we have to sort the uppercase & then lowercase
            -> Then insert those character to their intended position..
                    
        // Complexity: 
            -> TC:  O(n * logn)
            -> SC:  O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    bool isVow(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'O' || c == 'U');
    }
public:
    string sortVowels(string s) {
        vector<int> upper;
        vector<int> lower;
        for(auto &c: s) {
            if(isVow(c)) {
                // Check upper or lower:
                if(c >= 97) {   // Lower caes:
                    lower.push_back(c);
                } else { // upper case:
                    upper.push_back(c);
                }
            }
        }

        // Sort Upper & lower case characters:
        sort(rbegin(upper), rend(upper));
        sort(rbegin(lower), rend(lower));


        // Build answer:
        string ans = s;
        int n = s.size();
        
        // First insert Upper_case:
        int i = 0;
        for(; i < n && !upper.empty(); i++) {
            if(isVow(ans[i])) {
                ans[i] = upper.back();
                upper.pop_back();
            }
        }


        // Then, insert Lower_case:
        for(; i < n && !lower.empty(); i++) {
            if(isVow(ans[i])) {
                ans[i] = lower.back();
                lower.pop_back();
            }
        }

        return ans;
    }
};