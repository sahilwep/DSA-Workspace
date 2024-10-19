/*

//  Longest common subsequence: Recursive


# Problem Statement: 
We are given two strings `s1` and `s2`, and we need to find the longest common subsequence from both strings.

## What is a Subsequence?

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements. The characters do not need to be contiguous but must appear in the same order.

- `Example`:
    - For the string "abcde", the subsequences include "ace", "bde", and "abcde."
    - However, "aec" is not a valid subsequence because it does not follow the original order.

# Recursive Solution:

        Example
            Input: `s1 = "abcde"`, `s2 = "ace"`  
            Output: 3  
        
            * We look for the common subsequence:

                    a b c d e           a c e
                    |   |   |           | | |

            * These are the matching subsequences.

            * Explanation
                If we start looking from the end:

                    a b c d e           a c e
                            |               |
                        matched          matched

            * When both characters match, we move both pointers:


                    a b c d e           a c e
                          |               |
                       Not-matched      Not-matched

                                                Current LCS = 1


            * When no match is found, we have two options: 
                1. Move the first pointer and look for a match.
                2. Move the second pointer and look for a match.

            * We continue like this until both pointers reach 0 (i.e., the string size becomes 0), and we exit the recursion.



// Observations
    - When we have a match, we add 1 to the result.
    - When there's no match, we minimize the size of the strings based on the decisions we make.
    - `Base Condition`: When either string size becomes 0, we return 0 (`if(n == 0 || m == 0) return 0`).


// Decision Tree
    - `Matched Case`: If both characters match, we minimize the size of both strings and add 1 to our count.
    - `Unmatched Case`: If characters don't match, we have two options:
        - Option 1: Minimize the size of the first string.
        - Option 2: Minimize the size of the second string.
        - We take the maximum of the two options: `max(option1, option2)`.

        - Decision Tree:

                                                                [s1, s2, n, m]
                                                                        |
                                    /----------------------------------------------------------------------------\
                                [matched]                                                                  [Not,matched]
                         call with [s1, s2, n-1, m-1] + 1(to count the match)                   Two Options call with(n-1, m-1) 
                                   |                                                                              |
                            /-----------------------\                                            /------------------------------\
                        [matched]                 [not matched]                            call[s1, s2, n-1, m]           call[s1, s2, n, m-1]
                            |                            |                                          |                                  |
                            ...                          ...                                  /-----------\                      /-----------\
                                                                                        [matched]       [not matched]       [matched]       [not matched]
                                                                                            |               |                   |               |
                                                                                            ...             ...                 ...             ...




// Complexity: `Gives TLE`

    * Time complexity: O(2^min(n,m))
    * Since every time we have two choices (match or no match), and the recursion goes until one of the strings becomes empty.
  

    * Space complexity:O(2^min(n,m))
    * Due to recursive calls and the function call stack.



// Problem
    * If we observe the recursive tree, we notice that the same subproblems are being computed multiple times. 
    * This results in an overlapping subproblems issue.
    * We will saw Memoization Solution to improve Fix TLE


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Longest Common Subsequence: Recursive:
int lcs(string s1, string s2, int n, int m){
    if(n == 0 || m == 0) return 0;

    if(s1[n-1] == s2[m-1]){
        return 1 + lcs(s1, s2, n-1, m-1);
    }
    else{
        return max(
            lcs(s1, s2, n-1, m), 
            lcs(s1, s2, n, m-1)
        );
    }
}


void solve(){
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    cout << lcs(s1, s2, n, m) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}