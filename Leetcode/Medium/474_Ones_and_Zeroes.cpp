/*

//  474. Ones and Zeroes


//  Problem Statement: 
    -> You are given an array of binary strings strs and two integers m and n.
    -> Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
    -> A set x is a subset of a set y if all elements of x are also elements of y.

 
// Example: 
    Example 1:
        Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
        Output: 4
        Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
        Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
        {"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.

    Example 2:
        Input: strs = ["10","0","1"], m = 1, n = 1
        Output: 2
        Explanation: The largest subset is {"0", "1"}, so the answer is 2.


// Observations: 
    - we are given strs, where we have some binary string containing 0's & 1's
    - we can pick those binary string & build a subsets.
    - we have choice to choose such string, as it's a subset.
    - needs at-most m-0's & n-1's in our subset.
    - we need to return such subsets having largest size, means having largest number of binary strings.
    

    // Approach:
        - We have choices  & we can choose any part of the strings. It means we can either include/reject items/binary_strings => 0/1 knapsack
        - need to maximize the total size of answer.
            - Constrains we can't go above m-0's & n-1's 
            - At max we can choose from the given "vector<string> strs".

    
    // Recursive Solution:  

            int func(vector<string> &strs, int n, int m, int size) {
                // function return the total number of included binary strings, which is our length.
                // strs is list of binary strings.
                // n = number of 1's we can choose at max.
                // m = number of 0's we can choose at max.
                // size is the size of strs..
            }

        // Base case: 
            - at max we can "size = strs.size()" binary strings
            - at max we can choose n-1's & m-0's
             
                if(size == 0) return 0; // no such string is formed.
                if(n == 0 && m == 0) return 0;
            
            - here we have choose "&&" because, it's possible that n is full & m is remains & we can have some string where we have all '0', so we can choose them...
            - This is why we have set (n == 0 "&&" m == 0) to return
        
            
        // Decision Tree: 
        
            - for every binary string.
                - z = 0, o = 0
                - Compute total number of 0's & 1's
                - let say, we have: z = x, o = y
            
            - Check 
                    // check if total number of 1's is less or equal to remaining n & similar to 0's
                    if (o <= n && z <= m) {
                        We can have two choices either include/reject
                        return max(
                            1 + solve(strs, n - o, m - z, size - 1), // include case, add 1, because we consider this binary string into our answer, also as we are includeing 0's & 1's, we need to subtract these from our given n & m capcity...
                            solve(strs, n, m, size - 1) // reject case "size - 1", because we are not considering this binary string..
                        );  // we need maximum of all these choices...
                    } else {
                        // reject only, no choices.
                        return solve(strs, n, m, size - 1); // "size - 1", because we are rejecting the item.
                    }


        // Complexity: 
            - TC: O(2^size)
            - SC: O(size)

        - Got TLE, it's just we need to look upon on optimizations, as overlapping subproblems...

        
        // Dp-Memoization:
            - We can store the recomputing subproblems by storing them & returning when it's need in future.
            - We can use memo-table to optimize the recursive solutions..
            - Writing Memoization: 
                - First look upon the varying parameters:
                    n, m, size
                - We will have to create 3 dimensions memo-table.
            - Create 3 dimensions vector/array: dp[size][n][m]
            - Before going into the decision tree, check in the memo-table, if it's already computed then directly return, without going into recursive calls...
            - After computing the results from the decision tree, store it in memo-table before returning...


            // Complexity: 
                - TC: O(Size * n * m)
                - SC: O(size * n * m)




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Memoization Solutions:
class Solution {
private: 
    vector<vector<vector<int>>> t;
    int solve(vector<string> &strs, int n, int m, int size) {
        
        // Base case: 
        if(size == 0) return 0;     // if we have explored all the elements, 
        if(n == 0 && m == 0) return 0;  // if n & m both becomes '0', we can't go beyond..

        // Check in memo-table:
        if(t[size][n][m] != -1) {
            return t[size][n][m];
        }

        // Decision Tree:

        // First count zeroes & ones.
        int o = 0, z = 0;
        for(auto &ch: strs[size-1]) {
            if(ch == '1') o++;
            else z++;
        }

        if(o <= n && z <= m) {
            // Two choices: include/reject
            return t[size][n][m] = max(
                1 + solve(strs, n - o, m - z, size - 1),    // 1 + include (one is added, because we are counting this calls.)
                solve(strs, n, m, size - 1)        // reject
            );
        } else {    // else no-choice, only reject
            return t[size][n][m] = solve(strs, n, m, size - 1);
        }
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();

        // Initializing dp-table:
        t.resize(size + 1, vector(n + 1, vector<int> (m + 1, -1)));

        return solve(strs, n, m, size);
    }
};



// Recursive Solution: 
class Solution {
private: 
    int solve(vector<string> &strs, int n, int m, int size) {
        
        // Base case: 
        if(size == 0) return 0;     // if we have explored all the elements, 
        if(n == 0 && m == 0) return 0;  // if n & m both becomes '0', we can't go beyond..

        // Decision Tree:

        // First count zeroes & ones.
        int o = 0, z = 0;
        for(auto &ch: strs[size-1]) {
            if(ch == '1') o++;
            else z++;
        }

        if(o <= n && z <= m) {
            // Two choices: include/reject
            return max(
                1 + solve(strs, n - o, m - z, size - 1),    // 1 + include (one is added, because we are counting this calls.)
                solve(strs, n, m, size - 1)        // reject
            );
        } else {    // else no-choice, only reject
            return solve(strs, n, m, size - 1);
        }
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();

        return solve(strs, n, m, size);
    }
};