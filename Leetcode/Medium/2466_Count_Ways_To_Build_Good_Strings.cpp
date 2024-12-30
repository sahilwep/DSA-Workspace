/*

//  2466. Count Ways To Build Good Strings

// Problem Statement:
    -> We are given the integers 'zero', 'one', 'high', and 'low', we can construct a string by starting with an empty string, and then at each step perform either of the following:
        -> Append the character '0' 'zero' times
        -> Append the character '1' 'one' times
    
    -> This can be performed any number of times.
    -> A good string is a string constructed by the above process having a length between 'low' and 'high' inclusive.
    -> Return the number of different good string that can be constructed satisfying these properties. Since the answer can be large, return it modulo '10e9+7'



// Observations:
    -> We can start with "" empty string
    -> at one time we can insert '0' zero times or '1' one time.
    -> Length of string: 
        low <= s.size() <= high
    -> Then this can be a good string, 
    -> Return the number of good string.
    // Example:

        Input: low = 2, high = 3, zero = 1, one = 2
        Output: 5

                // Decision Tree: Break into two: either fill with 1's or fill with 0's

                                    " "     Starting we have empty string
                                  1/    \0
                                  /      \
                                 /        \
                                /          \
                             "11"           "0"
                           1/   \0         1/   \0
                           /     \         /     \
                       "1111"    "110"   "011"    "00"
                         x      1/   \0   / \    1/  \0 
                                /     \   ..    "001" "000"
                           "11011"    "1100"     / \    / \
                             x           x      ...     ....

                
                -> This is how our recursion tree will break,
                -> We will count all those string size whose in bound low & high, and return the sum to parent call.
                -> One things we can observe, once string size is reaches the high bound, and for further breaking of decision, it will return '0'

                -> Repeating Subproblems:
                    -> We don't need to focus on string, we just need to focus on string size.
                    -> If we compute for every branch, when branch string size is same the resultant will also be same.
                    -> So, instead of focusing on string itself, we need to focus on string size, 
                    -> and when same string size recomputing, we will return that answer immediately, without further breaking into recursion calls.
                    -> We can use memoization approach to solve this problem of recomputation.
        
                -> Memoization Approach:
                    -> We will create a memo table of size: high+1, that's the max size string we need to string, because anything beyond the high size it's not the good string.
                    -> Result can be found when we call function with solve(0), because initially string length is '0' or empty string.
                    -> And we will count it until the given condition satisfies.
                    -> And result will return to the parent call.


        // Reclusive Solution TC: O(2^n)
        // Memoization Solution TC: O(n) -> Because we are solving all the subproblems only once.
        // SC: O(n) -> Due to recursion calls in stack + memoization table.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Memoization Approach:
class Solution {
private:
    int mod = 1000000007;
    int H, L, Z, O;
    int solve(int len, vector<int> &t){
        // base condition: 
        if(len > H) return 0;   // when length size exceed the given range, return '0'

        // Checking in memo table:
        if(t[len] != -1) return t[len];

        // checking for valid string size or not?
        bool addOne = false;
        if(len >= L && len <= H){
            addOne = true;
        }

        int appendZero = solve(len + Z, t);  // append zero to the previous length
        int appendOne = solve(len + O, t);   // append one to the previous length

        return t[len] = (addOne + appendZero + appendOne) % mod;   // Store the solution & return the computation result to parent call.
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        H = high;
        L = low;

        Z = zero;
        O = one;

        vector<int> t(high+1, -1);  // dp table

        return solve(0, t); // call with 0, as string size is empty, & with memo table
    }
};


// Recursive Solution:
class Solution {
private:
    int mod = 1000000007;
    int H, L, Z, O;
    int solve(int len){
        // base condition: 
        if(len > H) return 0;   // when length size exceed the given range, return '0'

        // checking for valid string size or not?
        bool addOne = false;
        if(len >= L && len <= H){
            addOne = true;
        }

        int appendZero = solve(len + Z);  // append zero to the previous length
        int appendOne = solve(len + O);   // append one to the previous length

        return (addOne + appendZero + appendOne) % mod;   // last return the computation result to parent call.
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        H = high;
        L = low;

        Z = zero;
        O = one;

        return solve(0); // call with 0, as string size is empty
    }
};