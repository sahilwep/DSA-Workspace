/*

//  386. Lexicographical Numbers


//  Problem Statement: 
    -> Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
    -> You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

 
// Example: 
    Example 1:
        Input: n = 13
        Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]

    Example 2:
        Input: n = 2
        Output: [1,2]

// Solution: 
    -> for lexigraphically sorted, first convert int to string & then generate all the numbers, & while storing answer, convert from string to int.

    // Complexity: 
        -> TC: O(N)
        -> SC: O(N)

// Optimal Solution: SC: O(1) -> Space optimized
    -> We have to print all the number in lexigraphically order: 
        -> Example: 
            n = 25
                
                1 12 13 14 15 2 21 22 23 24 25 3 4 5 6 7 8 9

    -> Try writing recursive solution: 
        -> Pick every number
            -> Try printing all the number with that 
            -> Example: 
                    1
                    |
                -------------------------
                |   |   |   |   |       |
                10  11  12  13  14..... 19
                |
            -------...
            |    |  ...
            100 101  ...

            Similarly we can do for all the rest of numbers.
    
    -> While we moving forward, we won't go further, we will return when our number range hits.

    // Complexity: 
        -> TC: O(n)
        -> SC: O(number of digits) -> O(log_base10(n))
            -> If we make recursive diagram, at max we can go up to the depth of the tree, & that is our number of digits...


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Optimized: Recursive Solution
class Solution {
private: 
    void solve(int num, vector<int> &nums, int n) {
        if(num > n) {
            return; // dont' go further, return
        }
        nums.push_back(num);    // store the current called answer

        // Generate sequence from 1 to 9: 
        for(int i = 0; i <= 9; i++) {
            int newNum = num * 10 + i;  // include the next level number form num:
            solve(newNum, nums, n);
        }
    }
public:
    vector<int> lexicalOrder(int n) {

        vector<int> ans;
        for(int i = 1; i <= 9; i++) {
            solve(i, ans, n);
        }

        return ans;
    }
};

// BruteForce:
class Solution {
public:
    vector<int> lexicalOrder(int n) {

        set<string> st;
        for(int i = 1; i <= n; i++) {
            st.insert(to_string(i));
        }

        vector<int> ans;
        for(auto&it: st) {
            ans.push_back(stoi(it));
        }

        return ans;
    }
};