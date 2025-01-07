/*

// KMP Algorithm: 


// Question:
    -> Pattern Searching (KMP-Algorithm) [GeeksforGeeks]

// Problem Statement:
    -> Given two strings: a text string `txt` and a pattern string `pat`. 
    -> The task is to return the indices of all occurrences of the pattern string in the text string (0-based indexing). 
    -> If the pattern does not occur in the text, return an empty list.

// Key Notes:
    -> Use 0-based indexing while returning the indices.
    -> Pattern matching must be efficient compared to brute force solutions.

// Brute Force Solution:
    -> Time Complexity: O(n * m), where n = txt.size() and m = pat.size().
    -> This is achieved by iterating through `txt` and trying to match `pat` starting at every position.
    -> TC: O(n * m)


// Optimized Solution: Knuth-Morris-Pratt (KMP) Algorithm
    -> Time Complexity: O(n + m)
    -> The KMP algorithm avoids unnecessary re-comparison by using a helper array called the Longest Prefix Suffix (LPS) array.
    -> Steps:
       1. Compute the LPS array for the pattern string.
       2. Use the LPS array to efficiently search for the pattern in the text by skipping redundant comparisons.

    -> TC: O(n + m)


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void computeLPS(string &pat, vector<int> &LPS, int m) {
        int len = 0; // Length of the previous longest prefix which is also a suffix
        LPS[0] = 0;  // Base case: No proper prefix exists for a single character

        int i = 1; // Start from the second character
        while (i < m) {
            if (pat[i] == pat[len]) { // Characters match
                len++;
                LPS[i] = len; // Store the length of the prefix
                i++;
            } else { // Characters do not match
                if (len != 0) {
                    // Backtrack to the previous LPS value
                    len = LPS[len - 1];
                } else {
                    // No prefix exists, so LPS[i] = 0
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }

public:
    vector<int> search(string &pat, string &txt) {
        int n = txt.size();
        int m = pat.size();
        vector<int> res; // Stores the indices of pattern matches

        // Step 1: Compute the LPS array for the pattern
        vector<int> LPS(m, 0);
        computeLPS(pat, LPS, m);

        // Step 2: Use the LPS array to search for the pattern in the text
        int i = 0; // Index for txt
        int j = 0; // Index for pat

        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == m) {
                // Pattern found, record the starting index
                res.push_back(i - m);
                // Backtrack j using the LPS array
                j = LPS[j - 1];
            } else if (i < n && txt[i] != pat[j]) {
                // Mismatch after j matches
                if (j != 0) {
                    // Backtrack j using the LPS array
                    j = LPS[j - 1];
                } else {
                    // Move to the next character in txt
                    i++;
                }
            }
        }

        return res;
    }
};

int main() {
    int t; // Number of test cases
    cin >> t;
    while (t--) {
        string txt, pat; // Input text and pattern strings
        cin >> txt >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, txt); // Call the KMP search function

        // Output the result
        if (res.empty()) {
            cout << "[]" << endl; // No matches found
        } else {
            for (int index : res) {
                cout << index << " "; // Print all match indices
            }
            cout << endl;
        }
    }
    return 0;
}
