/*

//  Longest Common Substring

//  Problem Statement: 
        * We are given two string s1, & s2, we need to find the longest common substring from it.


// Substring:
        * A substring is a contiguous sequence of characters within a string.
        * All characters of the substring must appear consecutively in the original string.
        * Example:
            For the string "abcde", the substrings include "a", "abc", "cde", 
            but not "ace" because the characters are not consecutive.



// Example:

    Input: s1 = “GeeksforGeeks”, s2 = “GeeksQuiz” 
    Output : 5 
    Explanation:
    The longest common substring is “Geeks” and is of length 5.

    Input: s1 = “abcdxyz”, s2 = “xyzabcd” 
    Output : 4
    Explanation:
    The longest common substring is “abcd” and is of length 4.

    Input: s1 = “abc”, s2 = “” 
    Output : 0.



// Observations: 
    // How to identify question is of LCS type:
        * In subsequence, we are allowed to skip some of the character while matching common elements.
        * means, we can break few elements, & find the common elements in LCS:
        * Example: 
                s1 = a b c d e    s2 = a b e
                     | |     |         | | |

                LCS: abe -> 3   This can be discontinuous
        
        * But, here we can't skip any item, in between
        * Example:
                s1 = a b c d e    s2 = a b e
                     | |               | |
                
                longest Common Subarray: ab -> 2
            
                -> Here, the elements cannot be discontinuous

                * If we observe Carefully
                
                    s1 = a b c d e    s2 = a b e
                         
                    Common substrings: ab, e    -> These are the common substring, from these we will choose longest one, i.e ab -> 2

                    We will choose maximum from all the common substring.

    // Similarities with lcs:
        * we have given two input, s1, & s2, & from this we have to find longest common.
        * similarly, we are given two string s1, & s3, and from here we have to find longest common.
        * It's just In lcs, we were finding subsequence, but from here we are finding subarray.
        * Output format is also same, there in lcs we were returning the size in int, Here also we will have to return the size of LC-substring in int.


// Problem with the Recursive Solution:
    * If we carefully observe, the same subproblems are computed multiple times, leading to inefficiencies.
    * Example:
        Consider strings s1 = "abab" and s2 = "abxb":
           
                                               LCS(4, 4)   -> compare 'b' and 'b' -> match
                                                 |
                                            1 + LCS(3, 3) -> compare 'a' and 'x' -> no match
                                                 /   \
                                       LCS(2, 3)    LCS(3, 2)  
                                         |            |
                               compare 'b' and 'x'   compare 'a' and 'b' -> no match
                                      /     \            /    \
                              LCS(1, 3)  LCS(2, 2)  LCS(2, 2)  LCS(3, 1) 
                                 |          |          |         |
                            compare 'a'  compare 'b'  compare 'b' compare 'a'
                            and 'x'     and 'b' -> match  and 'b' -> match and 'a'
                               /    \        |         |          |
                            LCS(0, 3)  LCS(1, 2)  1 + LCS(1, 1)  1 + LCS(2, 0)
                               |           |          |             |
                            base case    compare 'a'  compare 'a'  base case
                              return 0   and 'b' -> no match  and 'a' -> match
                                           /   \           |       
                                     LCS(0, 2)  LCS(1, 1)  1 + LCS(0, 0)
                                       |           |          |
                                    base case    compare 'a'  base case
                                      return 0  and 'a' -> match return 0
                                                  |
                                            1 + LCS(0, 0)
                                                  |
                                               base case
                                               return 0


    * Overlapping Subproblems:
        * Notice that LCS(2, 2) is computed twice, first in the branch from LCS(2, 3) and then again from LCS(3, 2). 
        * This subproblem overlaps and will be recomputed unnecessarily without memoization.


// Top-Down Memoization Approach:
    * To optimize the recursive solution using Top-Down Dynamic Programming (DP), we can make a few changes.
    * We need to create a memoization array to store the results of subproblems. Whenever a subproblem is called, 
    * we check the memo array and return the stored result if it has been computed previously.
    * If the subproblem has not been solved before, we compute it, store the result in the memo array, and then return the value to the parent call.
    * Time Complexity: O(n * m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Top-Down Memoization Solution: Longest Common Substring:
int longestCommonSubstring_memo(string s1, string s2, int n, int m, vector<vector<int> > &t){
    // when size of any string is 0, we will return 0.
    if(n == 0 || m == 0) return 0;

    // If the value already present in our memo array, return directly
    if(t[n][m] != -1){
        return t[n][m];
    }

    // When we have match:
    if( s1[n-1] == s2[m-1] ){
        return t[n][m] = (1 + longestCommonSubstring_memo(s1, s2, n-1, m-1, t));
    }
    else{
        return t[n][m] = 0; // If we don't have match, return 0
    }
}


int longestCommonSubstr(string s1, string s2, int n, int m){
    if(n == 0 || m == 0) return 0;

    // Creation of memo array:
    vector<vector<int> > t(n+1, vector<int> (m+1, -1));     // initialize memo array with -1

    int res = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            res = max(res, longestCommonSubstring_memo(s1, s2, i, j, t));
        }
    }

    return res;
}


void solve(){
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    // Top-Down Dp Solution:
    cout << longestCommonSubstr(s1, s2, n, m) << endl;

}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}

