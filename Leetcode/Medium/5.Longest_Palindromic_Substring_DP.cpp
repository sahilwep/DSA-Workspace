/*
//  5. Longest Palindromic Substring -> Using DP


//  Observations:
    * Given a string return the longest palindromic substring.

// Example:

    Input: s = "babad"
    Output: "bab"
    Explanation: "aba" is also a valid answer.

    Input: s = "cbbd"
    Output: "bb"


// Intrusion:
    * Earlier I have solved this question using Bruteforce & Two pointer Approach, But this time i am using DP to solve this particular Question:
    
    // Recursive Solution:
        - The recursion checks whether the characters at two ends of the substring `s[l:r]` are equal. 
        - If they are, we recursively check the inner substring `s[l+1:r-1]`.
        - If all characters match (i.e., left index `l` crosses or equals right index `r`), the substring is confirmed to be a palindrome.
        - If at any point characters don't match, the function returns `false` for that substring.
    
    * TC: O(2^n)

    // Memoization (Top-Down Dynamic Programming):
        - This method uses a 2D DP array `dp[l][r]` where `dp[l][r]` stores whether the substring `s[l:r]` is a palindrome.
        - The idea is to avoid recalculating the same subproblems (substrings).
        
        Example:
            s = "madam"
            Pointers: 
                    l       r
                s = m a d a m
                Checking substrings:
                    - Palindrome 1: 'a' (at position l = 2, r = 2)
                    - Palindrome 2: 'ada' (at position l = 1, r = 3)
                    - Palindrome 3: 'madam' (at position l = 0, r = 4)
                
                - Palindrome 1 (s[2:2]) is computed once.
                - For Palindrome 2 (s[1:3]), we are recalculating Palindrome 1 (s[2:2]).
                - For Palindrome 3 (s[0:4]), we are recalculating Palindrome 2 and Palindrome 1 again.
                
            - By using memoization, we store the result of each palindrome check, so we don't recompute them, thereby reducing the time complexity.

        DP Table Update:
            - `dp[l][r] = true` if substring `s[l:r]` is a palindrome.
            - For each pair of indices `(l, r)`, if `s[l] == s[r]`, we check the inner substring `s[l+1:r-1]` using the memoized result stored in `dp[l+1][r-1]`.
            - The base case is when `l >= r`, meaning we've fully checked or reduced the substring.

        * TC: O(n^2) -> Incommunicative time complexity will be O(n^2), because dp will return the solution of subproblem.


    // Bottom Up: 
        * DP Table (dp[i][j]):
            * We create a 2D DP table (dp[i][j]) where dp[i][j] is true if the substring s[i:j] is a palindrome, and false otherwise.
            * The table is initialized such that every single character is a palindrome, i.e., dp[i][i] = true for all i.

        * Filling the DP Table:
            * We begin by marking all single-character substrings as palindromes.
            * Then, we incrementally consider substrings of length 2, 3, and so on, checking if the substring s[i:j] is a palindrome by:
                * Comparing the characters at both ends s[i] and s[j].
                * If the characters are equal, check if the inner substring s[i+1:j-1] is also a palindrome (which we already computed and stored in dp[i+1][j-1]).
                * For substrings of length 2 or 3, we can directly check if the characters at both ends match (s[i] == s[j]).

        * Palindrome Check:
            * For every pair of indices (i, j) in the string, the conditions to mark dp[i][j] as true (i.e., s[i:j] is a palindrome) are:
                * s[i] == s[j]: The characters at the two ends are equal.
                * The inner substring s[i+1:j-1] must also be a palindrome, i.e., dp[i+1][j-1] == true.
                * For substrings of length 2 or 3, it's sufficient to check if s[i] == s[j] (no need for the inner substring check for length 2).

        * Updating Maximum Length:
            * As we iterate over possible substrings, each time we find a palindrome that is longer than the current longest palindrome, we update:
                * maxLen: The length of the longest palindrome found so far.
                * startIdx: The starting index of this longest palindrome.

        * Return the Result:
            * After completing the table, the longest palindrome can be identified using the startIdx and maxLen, and is returned as s.substr(startIdx, maxLen).


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int dp[1000][1000];  // DP table to store palindrome checks for substrings.
public:
    // Recursive Solution to check if substring s[l:r] is a palindrome.
    bool solve_r(string &s, int l, int r){
        // Base case: If the left index crosses or equals the right index, it's a palindrome.
        if(l >= r){
            return true;
        }
        // If characters at both ends match, recursively check the inner substring.
        if(s[l] == s[r]){
            return solve_r(s, l+1, r-1);
        }
        // If characters don't match, it's not a palindrome.
        return false;
    }

    // DP Solution: Top-down memoized approach.
    bool solve(string &s, int l, int r){
        // Base case: If the left index crosses or equals the right index, it's a palindrome.
        if(l >= r){
            return true;
        }
        
        // If this subproblem has already been solved, return the stored result.
        if(dp[l][r] != -1){
            return dp[l][r];
        }

        // If characters at both ends match, check the inner substring recursively.
        if(s[l] == s[r]){
            dp[l][r] = solve(s, l+1, r-1);  // Store the result in DP table.
            return dp[l][r];
        }

        // If characters don't match, mark the substring as non-palindromic in DP table.
        return dp[l][r] = false;
    }

    // Main function to find the longest palindromic substring in the input string.
    string longestPalindrome_Mem(string s) {
        int n = s.size();

        int maxLen = -1;   // Variable to track the maximum length of palindromic substring.
        int startIdx = 0;  // Variable to track the starting index of the longest palindrome.

        memset(dp, -1, sizeof(dp));  // Initialize DP table with -1 (uncomputed states).

        // Iterate through all possible substrings in the string.
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                // If the current substring s[i:j] is a palindrome:
                if(solve(s, i, j)){
                    // Check if its length is greater than the current max length.
                    if(j - i + 1 > maxLen){
                        maxLen = j - i + 1;  // Update maximum palindrome length.
                        startIdx = i;        // Update starting index of the palindrome.
                    }
                }
            }
        }

        // Return the longest palindromic substring using startIdx and maxLen.
        return s.substr(startIdx, maxLen);
    }

    // Dp Solution: Bottom Up approach
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int maxLen = 1;         // Maximum length of the palindrome found.
        int startIdx = 0;       // Starting index of the longest palindrome.

        // DP table where dp[i][j] will be true if substring s[i:j] is a palindrome.
        vector<vector<bool> > dp(n, vector<bool>(n, false));

        // Every single character is a palindrome (diagonal elements).
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Fill the DP table for substrings of length 2 and more.
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Check if the characters at positions j and i match.
                if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;  // Mark the substring s[j:i] as a palindrome.

                    // Update the maximum length and starting index of the palindrome.
                    if (i - j + 1 > maxLen) {
                        maxLen = i - j + 1;
                        startIdx = j;
                    }
                }
            }
        }

        // Return the longest palindromic substring using startIdx and maxLen.
        return s.substr(startIdx, maxLen);
    }
};

void solve(){
    string s;
    cin >> s;

    Solution obj;
    cout << obj.longestPalindrome(s) << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}