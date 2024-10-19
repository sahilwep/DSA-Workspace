/*

//  Longest common subsequence: Tabulation



// Problem Statement: 
    We are given two strings 's1' and 's2', and we need to find the longest common subsequence from both strings.



// What is a Subsequence?
    A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements. The characters do not need to be contiguous but must appear in the same order.

    - 'Example':
        - For the string "abcde", the subsequences include "ace", "bde", and "abcde."
        - However, "aec" is not a valid subsequence because it does not follow the original order.



# Recursive Solution:

        Example
            Input: 's1 = "abcde"', 's2 = "ace"'  
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
    - 'Base Condition': When either string size becomes 0, we return 0 ('if(n == 0 || m == 0) return 0').


// Decision Tree
    - 'Matched Case': If both characters match, we minimize the size of both strings and add 1 to our count.
    - 'Unmatched Case': If characters don't match, we have two options:
        - Option 1: Minimize the size of the first string.
        - Option 2: Minimize the size of the second string.
        - We take the maximum of the two options: 'max(option1, option2)'.

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



// Problem with recursive Solution:
    * If we observe the recursive tree, we notice that the same subproblems are being computed multiple times. 
    * This results in an overlapping subproblems issue.
    * Example:


                                                                                       lcs("abc", "ac", 3, 2)
                                                                                                |
                                                                            /--------------------------------------------------------------------\
                                                            lcs("ab", "ac", 2, 2)                                                      lcs("abc", "a", 3, 1)
                                                                    |                                                                                |
                                                    /-------------------------------------------\                                            /-----------------------------------------\
                                        lcs("a", "ac", 1, 2)                                lcs("ab", "a", 2, 1)                       lcs("ab", "a", 2, 1)                   lcs("abc", "", 3, 0)
                                          /             \                                       /           \                            /                \           
                            lcs("", "ac", 0, 2)    lcs("a", "a", 1, 1)          {lcs("a", "a", 1, 1)}      lcs("ab", "", 2, 0)   {lcs("a", "a", 1, 1)}  lcs("ab", "", 2, 0)
                                                                                    |                           |                           |                   |
                                                                                    |                           |                           ...                 ...
                                                                /------------------------\                  /------------------------\      
                                                    lcs("", "a", 0, 1)      lcs("a", "", 1, 0)      lcs("", "a", 0, 1)          lcs("a", "", 1, 0)


                    
                    * Repeated Subproblem: lcs("a", "a", 1, 1) is called twice (from two different paths in the tree).
                    * It occurs once in the left subtree (left branch of lcs("ab", "a", 2, 1)) and once in the right subtree (left branch of lcs("abc", "a", 3, 1)).


    * This time we want to remove recursion entirely, means we want solve this question using iteration..


// Solution: We will use Tabulation Approach:

        - Implementation of 'Bottom-Up' is very easy once we have implemented 'Recursive Solution'.

        - 'Tabulation Implementation': 
            - 'Initialization':
                - Create a table/matrix of size: 'n+1 & m+1'
                - Table size are choosen from those values which are changing in recursive solution.
                - From the base condition when '(n == 0 || m == 0) -> return 0', means 'first row' & 'first column' filled with '0'.

            - Filling the Rest of the table based on 'decision Tree':
                - We have already filled first row & first column, so iteration will start from 'row = 1 to n+1' & 'col = 1 to m+1'
                - Replace 'n -> i' & 'm -> j'
                - Replace recursive calls with matrix name:
                    -  'lcs' -> 't[][]'
                    -  Replace 'n - 1' & 'm - 1' -> 'i - 1' & 'j - 1'
                    -  'lcs(s1, s2, n-1, m-1)' ->  't[i-1][j-1]'
                - Replace 'return' -> 't[i][j]'
                - Rest of the logic is same, no change there..

            - At, Last return the last element from the table:
                -  't[n][m]' -> This will store our solution.

// Complexity:

    * Time complexity: O(n*m)
    * Space complexity:O(n*m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Longest Common Subsequence: Tabulation
int lcs(string &s1, string &s2, int n, int m){
    if(n == 0 || m == 0) return 0;  // when any of the string is with empty size, return 0

    // Initialization:
    vector<vector<int> > t(n+1, vector<int> (m+1, 0));   // initialize memo array

    // When m = 0, we can't have any common subsequence...
    for(int i=0;i<n+1;i++){
        t[i][0] = 0;
    }
    // When n = 0, we can't have any common subsequence..
    for(int i=0;i<m+1;i++){
        t[0][i] = 0;
    }

    // Filling the rest of the table:
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            // when both the characters are common:
            if(s1[i-1] == s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            // when both the characters are not common:
            else{
                t[i][j] = max(
                    t[i-1][j],
                    t[i][j-1]
                );
            }
        }
    }

    return t[n][m];
}


// LCS: Recursive
int lcs_recur(string s1, string s2, int n, int m){
    if(n == 0 || m == 0) return 0;

    if(s1[n-1] == s2[m-1]){
        return 1 + lcs_recur(s1, s2, n-1, m-1);
    }
    else{
        return max(
            lcs_recur(s1, s2, n-1, m), 
            lcs_recur(s1, s2, n, m-1)
        );
    }
}


void solve(){
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    // // Recursion implemented lcs:
    // cout << lcs_recur(s1, s2, n, m) << endl;

    // Tabulation implemented lcs:
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