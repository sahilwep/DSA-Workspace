/*

// Longest Common Subsequence (Part 1)

// Observations: 
    * We are given two string, & we need to find the common subsequence

// Example: 
    I/p:
        s1 = "ABCDGH"
        s2 = "AEDFHR"
    O/p: 3      -> ADH

    I/p:
        s1 = "AGGTAB"
        s2 = "GXTXAYB"
    O/p: 4      -> GTAB

    I/p:
        s1 = "XYZ"
        s2 = "XYZ"
    O/p: 3      -> XYZ

    I/p:
        s1 = "ABC"
        s2 = "XY"
    O/p: 0      -> "" empty sequence of both the string is same.


// Substring & Subsequence: 
    * Substring: we need to pick contigious characters from string.
    * Subsequence: we need to pick some character in same order that they appear
        * NOTE: In a string of length n, there can be 2^n possible subsequence.
        * Example: 
            Subsequence of "CDA"
                "", "C", "D", "A", "CD", "DA", "CA", "CDA"
                
            Subsequence of "DBA"
                "", "D", "B", "A", "DB", "BA", "DA", "DBA"


// Intrusion:
    // Recursive Solution:
        * We will start looking from back, we will match the last position of string, & if it's matched, we will decrement the size...
        
        
        * Example:
            s1 = AXYZ   -> AXY
            s2 = BAZ    -> BA   

            Output: 2   -> AZ

            * In each recursive calls, we are trying to reduce the size of string, by removing the last character of string...
            * If we get the match of characters, then only we reduce the size of string
            * If we didn't get the match of the last character, we will try to minimize the size of each string, by ignoring the last character of one string, & same if for the other string also...
            * Whichever these two cases gives us the maximum lcs we will store that result..
            * Base case: when any of the sting size is 0, we will return 

        * Recursive Calls:
                    * For last character matched, it goes for single recursive call, for unmatched character it's goes for two recursive calls.
                    * Whenever we have empty string in any recursive calls, we will return 0 to parent call 

                                                                            lcs("AXYZ", "BAZ")
                                                                                    |
                                                                            lcs("AXY", "BA")
                                                                                    |
                                            lcs("AX", "BA")---------------------------------------------------------lcs("AXY", "B")
                                                   |                                                                          |
                            lcs("A", "BA")--------------lcs("AX", "B")                                   lcs("AX", "B")------------------lcs("AX", "")
                                    |                           |                                               |
                              lcs("", "B")      lcs("A", "B")-----lcs("AX", "")                   lcs("A", "B")-----lcs("AX", "")     
                                                       |                                                  |
                                      lcs("", "B")-------------lcs("A", "")             lcs("", "B")-------------lcs("A", "")


        * Recursive Tree:

                        lcs("AXYZ", "BAZ")      -> return 2 to parent
                                |----> 1 + lcs("AXY", "BA")         -> return 1 + max(1, 0) = 2
                                                |----> 1 + lcs("AX", "BA")       -> return 1 +  max(0, 0) = 1
                                                |           |---->lcs("A", "BA")        -> return 0
                                                |           |           |----> lcs("", "B")             -> return 0
                                                |           |
                                                |           |---->lcs("AX", "B")        -> return max(0, 0) = 0
                                                |                       |---->lcs("A", "B")             -> return max(0, 0) = 0
                                                |                       |           |---->lcs("", "B")              -> return 0
                                                |                       |           |
                                                |                       |           |---->lcs("A", "")              -> return 0
                                                |                       |
                                                |                       |---->lcs("AX", "")          -> return 0
                                                |
                                                |
                                                |
                                                |---->lcs("AXY", "B")           -> return max(0, 0) = 0
                                                            |----> lcs("AX", "B")           -> return max(0, 0) = 0
                                                            |              |---->lcs("A", "B")      -> return max(0, 0) = 0
                                                            |              |           |---->lcs("", "B")       -> return 0
                                                            |              |           |
                                                            |              |           |---->lcs("A", "")       -> return 0
                                                            |              |
                                                            |              |---->lcs("AX", "")          -> return 0
                                                            |
                                                            |
                                                            |-----> lcs("AX", "")           -> return max(0, 0) = 0

        
        

        * This recursive Solutions has many overlapping sub-problems.
        * So, we can use DP to improve this solutions.

*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Normal Recursive Solution:
int lcs(string s1, string s2, int n, int m){
    // Base case:
    if(n == 0 || m == 0) return 0;  // return 0 to the parent call

    // condition when last character of each string matched:
    if(s1[n-1] == s2[m-1]){
        // call for next recursive call by minimizing the size, means removing last element from string.
        // we are adding 1, so that at each call we can get the size of maximum subsequence
        return 1 + lcs(s1, s2, n-1, m-1);
    }
    // when the last character are not matched:
    else{
        // we will call function by ignoring last character of each string, & get the maximum, means whatever the length which giving maximum we will store that.
        return  max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1));
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;

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