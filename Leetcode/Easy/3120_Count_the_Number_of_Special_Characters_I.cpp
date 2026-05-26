/*

//  3120. Count the Number of Special Characters I


//  Problem Statement: 
    - You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.
    - Return the number of special letters in word.

 
// Example:
    Example 1:
        Input: word = "aaAbcBC"
        Output: 3
        Explanation: The special characters in word are 'a', 'b', and 'c'.

    Example 2:
        Input: word = "abc"
        Output: 0
        Explanation: No character in word appears in uppercase.

    Example 3:
        Input: word = "abBCab"
        Output: 1
        Explanation: The only special character in word is 'b'.

// Observations:
    - Hash the Upper & lower case characters & then check if they appears or not?

    // Complexity:
        - TC: O(n)
        - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();

        vector<int> upper(26, 0), lower(26, 0);
        for(int i = 0; i < n; i++) {
            if(word[i] >= 'a' && word[i] <= 'z') {  // hash lower:
                lower[word[i] - 'a']++;
            } else {    // hash upper:
                upper[word[i] - 'A']++;
            }
        }

        // Build answer:
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if(upper[i] != 0 && lower[i] != 0) {
                ans += 1;
            }
        }

        return ans;
    }
};