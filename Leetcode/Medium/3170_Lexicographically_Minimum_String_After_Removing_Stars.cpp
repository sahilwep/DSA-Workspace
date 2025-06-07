/*

//  3170. Lexicographically Minimum String After Removing Stars


//  Problem Statement: 
-> You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.
-> While there is a '*', do the following operation:
    -> Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
-> Return the resulting string after removing all '*' characters.

 
// Example: 
    Example 1:
        Input: s = "aaba*"
        Output: "aab"
        Explanation: We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.

    Example 2:
        Input: s = "abc"
        Output: "abc"
        Explanation: There is no '*' in the string.


// Observations: 
    -> We are given a string contains '*'
    -> We have to remove all the stars from the string:
        -> for every stars check it's first smallest character & remove that from our answer.
        
    // BruteForce Approach: 
        -> Maintain a vector flagged which will keep track of every removed characters from string.
        -> For every '*' iterate from 0 to that index & get the index of last smallest character, & mark as flagged
        -> Now at last build answer by iterating in flagged & make sure to remove every '*' while iterating..



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BruteForce Solution: 
class Solution {
public:
    string clearStars(string s) {
        int n = s.size();

        vector<bool> flagged(n, 1);
        for(int i = 0; i < n; i++) {
            if(s[i] == '*') {
                // For every '*' find it's rightMost minimum:
                char min = 'z';
                int idx = -1;
                for(int j = 0; j < i; j++) {
                    if(s[j] == '*') continue;   // skip stars.
                    // if we got any lesser value && that value is not yet visited.
                    if(min >= s[j] && flagged[j] == 1) {   // get the rightmost minimum before stars 
                        min = s[j];
                        idx = j;
                    }
                }

                // minimum found:
                if(idx != -1) {
                    flagged[idx] = 0;   // mark idx as invalid index in flagged
                }
                flagged[i] = 0; // also mark * as invalid index
            }
        }

        // Build answer: 
        string ans = "";
        for(int i = 0; i < n; i++) {
            if(flagged[i] == 1) {
                ans += s[i];
            }
        }

        return ans;
    }
};