/*

//  3223. Minimum Length of String After Operations


//  Problem Statement:
    -> You are given a string s.
    -> You can perform the following process on s any number of times:
        -> Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
        -> Delete the closest character to the left of index i that is equal to s[i].
        -> Delete the closest character to the right of index i that is equal to s[i].
    -> Return the minimum length of the final string s that you can achieve.

    

// Example:

    Input: s = "abaacbcbb"
    Output: 5

    Explanation: We do the following operations:
        Choose index 2, then remove the characters at indices 0 and 3. The resulting string is s = "bacbcbb".
        Choose index 3, then remove the characters at indices 0 and 5. The resulting string is s = "acbcb".


    Input: s = "aa"
    Output: 2
    Explanation: We cannot perform any operations, so we return the length of the original string.



// Observation:
    
    Given a string "s", the goal is to minimize the length of the string by removing pairs of characters 
    from both ends such that they are equal. 
    
    Example:
    a b a a c b c b b
    0 1 2 3 4 5 6 7 8

    Explanation of the leftHash (lHash) and rightHash (rHash):
        - lHash: Tracks indices of characters from the left side of the string.
        - rHash: Tracks indices of characters from the right side of the string.

        For the above string:
            rHash:
                a: 3 2 0
                b: 8 7 5 1
                c: 6 4

            lHash:
                a: 0
                b: 
                c: 

        Process:
            i = 0 ('a'):
                - 'a' is not in lHash:
                    - Push 'a' into lHash.
                    - Remove 'a' from rHash.

            i = 1 ('b'):
                - 'b' is not in lHash:
                    - Push 'b' into lHash.
                    - Remove 'b' from rHash.

            i = 2 ('a'):
                - 'a' is in lHash:
                    - Check if 'a' exists in rHash.
                    - If the last occurrence of 'a' in rHash matches the current index, remove it.
                    - If there are other occurrences, pop the indices from rHash, overwrite them 
                        with a special marker '$', and process the current index.

            i = 3 ('$'):
                - Skip as it is a marked character.

            i = 4 ('c'):
                - Process similarly...

    Dry Run:
        For the string "aaaaa":
        a a a a a
        0 1 2 3 4

        rHash:
            a: 4 3 2 1 0

        i = 0 ('a'):
            - Push 'a' into lHash.
            - Remove the last index of 'a' from rHash.

        ...

        The logic identifies and removes pairs iteratively.

// Approach:
    1. Maintain two hashes:
        - leftHash (lHash): Tracks indices of characters processed from the left side.
        - rightHash (rHash): Tracks indices of characters from the right side before processing.

    2. Preprocess the string to populate rHash:
        - Traverse the string from right to left.
        - For each character, push its index into the corresponding bucket in rHash.
    
    3. Iterate through the string:
        - For each character `s[i]`:
            a. If `s[i]` exists in lHash:
                - Check if `s[i]` also exists in rHash.
                - Remove indices from rHash that are less than or equal to the current index `i`.
                - If rHash is still non-empty:
                    - Pop indices from both rHash and lHash.
                    - Overwrite the characters at those indices with a special marker '$'.
                    - Push the current index into lHash for future processing.
            
            b. If `s[i]` does not exist in lHash:
                - Push the current index into lHash.
                - Check if the last occurrence in rHash matches the current index.
                    - If so, remove it from rHash.
    
    4. At the end, count characters in the string that are not marked ('$') and return the count.


// Time Complexity:
    - Preprocessing rHash: O(n)
    - Processing the string: O(n)
    - Final count: O(n)
    Overall: O(n)


// Space Complexity:
    - Space used by lHash and rHash: O(26), which is constant for English lowercase letters.
    Overall: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int minimumLength(string s) {
        if (s.size() <= 2) return s.size();

        // Initialize left and right hash tables for tracking indices of characters.
        vector<vector<int>> rHash(26); // Right hash to store indices from the end.
        vector<vector<int>> lHash(26); // Left hash to store indices from the start.

        // Populate the right hash by traversing the string from right to left.
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            rHash[s[i] - 'a'].push_back(i);
        }

        // Traverse the string from left to right.
        for (int i = 0; i < n - 1; i++) {
            // Skip if the character is already marked as processed ('$').
            if (s[i] == '$') continue;

            // Check if the character exists in the left hash.
            if (!lHash[s[i] - 'a'].empty()) {
                // Check if the character also exists in the right hash.
                if (!rHash[s[i] - 'a'].empty()) {
                    // Remove indices from rHash that are less than or equal to the current index.
                    while (!rHash[s[i] - 'a'].empty() && rHash[s[i] - 'a'].back() <= i) {
                        rHash[s[i] - 'a'].pop_back();
                    }

                    // If there are remaining indices in rHash, process them.
                    if (!rHash[s[i] - 'a'].empty()) {
                        int overWriteRightIdx = rHash[s[i] - 'a'].back(); // Get the closest right index from rHash.
                        int overWriteLeftIdx = lHash[s[i] - 'a'].back(); // Get the leftmost index from lHash.

                        // Remove the indices from both rHash and lHash.
                        rHash[s[i] - 'a'].pop_back();
                        lHash[s[i] - 'a'].pop_back();

                        // Overwrite the characters at these indices with a marker ('$').
                        s[overWriteRightIdx] = '$';
                        s[overWriteLeftIdx] = '$';

                        // Push the current index into lHash to process it later.
                        lHash[s[i] - 'a'].push_back(i);
                    }
                }
            } else {
                // If the character is not present in lHash, add its index.
                lHash[s[i] - 'a'].push_back(i);

                // Check if the character exists in rHash and is at the same index.
                if (!rHash[s[i] - 'a'].empty() && rHash[s[i] - 'a'].back() == i) {
                    rHash[s[i] - 'a'].pop_back(); // Remove the matching index from rHash.
                }
            }
        }

        // Count the characters in the string that are not marked ('$').
        int ans = 0;
        for (auto ch : s) {
            if (ch != '$') ans++;
        }

        return ans;
    }
};