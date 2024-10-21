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
    
    // Difference b/w lcs & substring:
        * In lcs, when whe dont' have match -> we were going for two possibility max(n-1, m-1) & from these we were matching the common elements..
        * But here, in substring when we don't have match -> the count is break -> means return 0, & we will have to go for other possibility.


// Recursive SolutioN:
    * When we have (n == 0 || m == 0) -> return 0
    * Also, when we have s1[n-1] != s[m-1] -> return 0, because we don't have any matched
    * If we got a matched, we will add 1 to our result & go for recursive call by minimizing the size of both the string.
        * if(s1[n-1] == s2[m-1]) ->  return 1 + func(s1, s2, n-1, n-2)
    * From the main controller code of recursive calls:
    * We will iterate in nested (n x m) -> i = 1 to i <= n & j = 0 to  j <= m   -> this is because in recursive solution we are matching one element before i.e {s1[n-1] == s2[m-1]}   
        * call this recursive function by replacing (n -> i & m -> j) 
        * At every iteration, we will try to find the maximum from all the finding..
    * At last, return the result.

    * TC: O(n*m*min(n,m))   -> TLE


// Problem with Recursive Solution:
    * We were computing same subproblem many times, which increase overhead in recursive call stack.
    * We can fix this using DP Approach.

*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Recursive Solution: Longest Common Substring
int longestCommonSubstr(string s1, string s2, int n, int m){
    // when size of any string is 0, return 0.
    if(n == 0 || m == 0) return 0;

    // When we have match case:
    if(s1[n-1] == s2[m-1]){
        return (1 + longestCommonSubstr(s1, s2, n-1, m-1)); // increment counter by 1 & go for further recursive call by minimizing the size.
    }
    else{   //  (s1[n-1] != s2[m-1]) -> when any of the character is not equal
        return 0;
    }
}


// Longest Common Subsequence: Recursive -> For comparision purpose
int lcs_recur(string s1, string s2, int n, int m){
    if(n == 0 || m == 0) return 0;      // if we don't have match -> return 0

    if(s1[n-1] == s2[m-1]){
        return 1 + lcs_recur(s1, s2, n-1, m-1); // if we have match -> Add 1 to counter & call for next match by minimizing the size of both the string.
    }
    else{
        // When we don't have match:
        return max(
            lcs_recur(s1, s2, n-1, m),  // minimizing the size of first string
            lcs_recur(s1, s2, n, m-1)   // minimizing the size of second string
        );  // take maximum from both of them
    }
}


void solve(){
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    // Recursive Solution:
    int res = 0;
    // start iteration from i = 1, & to till (i <= n), because in recursive code we were comparing one element before, i.e s1[n-1]
    for(int i=1;i<=n;i++){
        // start iteration from j = 1, & to till (i <= m), because in recursive code we were comparing one element before, i.e s2[m-1]
        for(int j=1;j<=m;j++){
            res = max(res, longestCommonSubstr(s1, s2, i, j));  // replace n -> i and m -> j
        }
    }

    cout << res << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}

