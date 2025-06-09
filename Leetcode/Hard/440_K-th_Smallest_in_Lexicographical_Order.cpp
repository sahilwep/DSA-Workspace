/*

//  440. K-th Smallest in Lexicographical Order


//  Problem Statement: 
    -> Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

 
// Example: 
    Example 1:
        Input: n = 13, k = 2
        Output: 10
        Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.

    Example 2:
        Input: n = 1, k = 1
        Output: 1

// Solution: 
    -> Given two integers n and k, return the k-th smallest number in lexicographical (dictionary) order among the numbers from 1 to n.
        For example:
            n = 13 → Lexicographical order: 1, 10, 11, 12, 13, 2, 3, ..., 9
            k = 2  → Output: 10
    
    -> High-Level Idea

            Imagine a prefix tree (Trie) of numbers:

                      ""
                   / / \ ... \
                  1  2   3     9
                 /        \
               10         ...
              /  \
            100  101 ...

    -> We want to traverse this tree in lexicographical order, and find the k-th number.
    -> Rather than building the full tree, we simulate traversal using smart counting.
    
    -> countSteps(n, prefix1, prefix2)
    -> This function counts how many numbers lie between prefix1 and prefix2 in lexicographical order within the limit n.

    Example:
        countSteps(n=100, prefix1=1, prefix2=2) counts:

        All numbers starting with "1" (1, 10, 11, ..., 19)
        It also considers deeper levels like 100, 101, ... but ensures values ≤ n.

        It calculates:
            steps += min(n + 1, prefix2) - prefix1;
            prefix1 *= 10;
            prefix2 *= 10;

        This effectively counts how many numbers exist with prefix = prefix1, prefix1*10, prefix1*100, etc., without exceeding n.

    

    // Complexity: 
        -> TC: O(logN * logN)
        -> SC: O()


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient:
class Solution {
private: 
    typedef long long l;

    // Helper function to count how many numbers lie between two prefixes
    int countSteps(int n, l prefix1, l prefix2) {
        int steps = 0;

        // Count how many valid numbers lie in the lexicographical range
        // [prefix1, prefix2) up to n
        while (prefix1 <= n) {
            // In each level of the tree, we count how many valid numbers exist
            // under the current prefix range
            steps += min((l)(n + 1), prefix2) - prefix1;

            // Move to the next depth level by appending 0 to both prefixes
            prefix1 *= 10;
            prefix2 *= 10;
        }

        return steps;
    }

public:
    int findKthNumber(int n, int k) {
        int curr = 1; // Start with the first number in lexicographical order
        k--;          // We already count '1' as the first number

        // Repeat until we find the k-th number
        while (k > 0) {
            // Count how many numbers lie in the subtree starting with 'curr'
            // and ending before 'curr + 1' (i.e., next sibling prefix)
            int steps = countSteps(n, curr, curr + 1);

            if (steps <= k) {
                // If the entire subtree rooted at 'curr' has fewer or equal numbers
                // than k, we skip this subtree and move to the next sibling
                curr++;
                k -= steps;  // We skipped 'steps' numbers
            } else {
                // If k-th number lies inside the current subtree,
                // we go deeper into this subtree (i.e., next digit level)
                curr *= 10;  // Move to the child prefix
                k--;         // We count this move as one step closer
            }
        }

        // When k == 0, 'curr' is the k-th number
        return curr;
    }
};


// Better: TLE
class Solution {
private: 
    typedef long long ll;
    int res;
    void solve(int num, int& k, int n) {
        if(num > n) return;

        k--;    // visiting the number
        if(k == 0) {
            res = num;
            return;
        }

        for(ll i = 0; i <= 9; i++) {
            ll newNum = (ll)num * (ll)10 + i;
            if(newNum > n) return;  // prune further search
            solve(newNum, k, n);
        }
    }
public:
    int findKthNumber(int n, int k) {

        for(int i = 1; i <= 9; i++) {
            solve(i, k, n);
        }

        return res;
    }
};


//  Brute: TLE
class Solution {
public:
    int findKthNumber(int n, int k) {

        set<string> st;
        for(int i = 1; i <= n; i++) {
            st.insert(to_string(i));
        }

        for(auto& it: st) {
            k--;
            if(k == 0) return stoi(it);
        }

        return 0;
    }
};