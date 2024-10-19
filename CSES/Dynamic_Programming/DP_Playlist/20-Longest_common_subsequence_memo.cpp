/*

//  Longest common subsequence: Memoization



// Problem Statement: 
    We are given two strings `s1` and `s2`, and we need to find the longest common subsequence from both strings.



// What is a Subsequence?
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


// Solution:
    * We will use Memoization Approach, to store the solution of subproblems:
    - In Memoization, we just need to create a `memo` array, so that we can store the solution of `subproblems` that are being Repetitively calls.
    - We will add few lines in our previous recursive solution: 
    - Memoization: 
        - For creating memo array/matrix: 
            - we need to look for variable(changing) values from the recursive calls.
            - Here, n &  m are changing, So, we will create our memo array with that.
            - Create a matrix of size t[n+1][m+1], one extra size of variable values.
        - Initialize matrix with '-1' or any value that is out range of given constrains.
            - This will help us to identify whether we have computed subproblem before or not?
        - In recursive Function, add a check, if the called value is already present in our matrix, we will return directly from ther without going any further recursive call to recompute the same subproblem that we have computed earlier.
            - Checks can be: if(t[n][m] != -1) return t[n][m];
        - else, if the value is not present in our matrix, we will compute these value using same recursion logic, & store the answer in table before returning it.


// Complexity:

    * Time complexity: O(n*m)
    * Space complexity:O(n*m)


// Note: 
    * During the parameter Declaration, we need to pass our memo array with reference, 
    * Otherwise it will give TLE, because if we not pass it with reference, in recursive call it will create a copy of memo array every time.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Longest Common Subsequence: Memoization
int lcs(string &s1, string &s2, int n, int m, vector<vector<int> > &t){
    if(n == 0 || m == 0) return 0;  // During the recursive calls, size is minimizing, if any of the string size become 0, we will return 0.

    // If subproblem result is already present memo array:
    if(t[n][m] != -1){
        return t[n][m]; // return directly
    }

    // If both the string characters are matched: 
    if(s1[n-1] == s2[m-1]){
        return t[n][m] = 1 + lcs(s1, s2, n-1, m-1, t);  // adding 1 to it, & going for recursive call by minimizing the size from both the string, & at last we will store the result in memo array.
    }
    // If both the string characters are not matched: 
    else{
        // going for choice & getting the maximum from them:
        return t[n][m] = max(
            lcs(s1, s2, n-1, m, t),     // first call by minimizing the size of first string
            lcs(s1, s2, n, m-1, t)      // second call by minimizing the size of second string
        );  // taking maximum from both of them, & Storing the result into memo array.
    }
}

// lcs Memoization Controller code:
int lcs_memo(string s1, string s2, int n, int m) {

    if(n == 0 || m == 0) return 0;  // case, when any of the string has size = 0, we can't have any common subsequence.

    vector<vector<int> > t(n+1, vector<int> (m+1, -1));   // initialize memo array
    
    return lcs(s1, s2, n, m, t); // call lcs() & return the result
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

    // memoization implemented lcs:
    cout << lcs_memo(s1, s2, n, m) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}