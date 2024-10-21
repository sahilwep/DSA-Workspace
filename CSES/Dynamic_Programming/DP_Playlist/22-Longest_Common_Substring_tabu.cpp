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



// Bottom-Up DP Solution:
    * Initialization:
        * Initialize a table t[n+1][m+1], where n and m are the lengths of the two strings, which are continuously changing.

    * Base Case:
        * Fill the base values:
            * When n == 0 or m == 0, there is no common substring, so we set these values to 0.
            * Fill the first row and the first column with 0s, as they represent the cases where one string is empty.

    * Filling the Table:
        * Option 1: If the characters match, update the table by adding 1 to the previous diagonal value (t[n-1][m-1]). This keeps track of the length of the current matching substring.
        * Option 2: If the characters don't match, set the value to 0 (since the longest common substring ends here). 
        * Keep track of the maximum value in the table, as it represents the length of the longest common substring found so far.
        * In Simple word:
            * Replace n -> i & m -> j
            * Replace function call with t[][]
            * When We don't have match => t[i][j] = 0
            * When we have match => t[i][j] = 1 + t[i-1][j-1] 
                * At every match condition we will take maxSofar = max(maxSofar, t[i][j])


    * Table Visualization:
        * The table is filled row by row, comparing characters of both strings and updating the values based on matches and mismatches.
                   
                   s1 = abab   s2 = abxb

                                <-------s2.size()------------->
                    index           0    1     2     3     4   -> j-index
                    	                 a     b     x     b
            |       i = 0   	|  0  |  0  |  0  |  0  |  0  |
        s1.size()   i = 1   a	|  0  |  1  |  0  |  0  |  0  |
            |       i = 2   b	|  0  |  0  |  2  |  0  |  1  |
            |       i = 3   a	|  0  |  1  |  0  |  0  |  0  |
            |       i = 4   b	|  0  |  0  |  2  |  0  |  2  |



    * At the end, we need to return the maximum length of the substring.
        * The longest common substring can occur anywhere within the table, not necessarily at t[n][m].
        * To handle this, we maintain a variable that stores the maximum value encountered during the table traversal.
        * Whenever a match occurs, we compare the current length of the substring with the maximum value found so far and update the variable accordingly.
        * Finally, we return the value stored in this variable, which represents the length of the longest common substring.
        * Example:
                 s1 = abcdgh   s2 = acdghr

                                     a     c     d     g     h     r
                        	|  0  |  0  |  0  |  0  |  0  |	 0  |  0  |
                        a	|  0  |  1  |  0  |  0  |  0  |	 0  |  0  |
                        b	|  0  |  0  |  0  |  0  |  0  |	 0  |  0  |
                        c	|  0  |  0  |  2  |  0  |  0  |	 0  |  0  |
                        d	|  0  |  0  |  0  |  3  |  0  |	 0  |  0  |
                        g	|  0  |  0  |  0  |  0  |  4  |	 0  |  0  |
                        h	|  0  |  0  |  0  |  0  |  0  |	{5} |  0  |

                * Here, we can see, if we return t[n][m] -> 0
                * But maximum found from this table is 5
                * This is why we will maintain a variable that will get maximum so far..

    * TC: O(n*m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Bottom-Up Tabulation Solution: Longest Common Substring:
int longestCommonSubstr(string s1, string s2, int n, int m){
    if(n == 0 || m == 0) return 0;

    // Initialization:
    vector<vector<int> > t(n+1, vector<int> (m+1));

    // Filing the first row & first column -> because when any one of the string is empty we can't have any common subarray
    for(int i=0;i<n+1;i++) t[i][0] = 0;
    for(int i=0;i<m+1;i++) t[0][i] = 0;


    // Filling the rest of the table:
    int maxSoFar = 0;   // minimum value can be 0, because 0 means we don't have any match.
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            // When we have match:
            if(s1[i-1] == s2[j-1]){
                t[i][j] = 1 + t[i-1][j-1];  // adding 1 to result from diagonally previous element -> same as recursive solution, we were adding 1 & call by minimizing the size from both the string.
                maxSoFar = max(maxSoFar, t[i][j]);  // at every match we will store the maximum so far.
            }
            // When we don't have match:
            else{
                t[i][j] = 0;    // set 0, because we don't have match...
            }
        }
    }

    return maxSoFar;
}


// Recursive Solution: Longest Common Substring
int longestCommonSubstr_recur(string s1, string s2, int n, int m){
    // when size of any string is 0, return 0.
    if(n == 0 || m == 0) return 0;

    // When we have match case:
    if(s1[n-1] == s2[m-1]){
        return (1 + longestCommonSubstr_recur(s1, s2, n-1, m-1)); // increment counter by 1 & go for further recursive call by minimizing the size.
    }
    else{   //  (s1[n-1] != s2[m-1]) -> when any of the character is not equal
        return 0;
    }
}


void solve(){
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    // Bottom-Up Dp Solution:
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

