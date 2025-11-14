/*

//  70. Climbing Stairs


//  Problem Statement: 
    - You are climbing a staircase. It takes n steps to reach the top.
    - Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 
// Example: 
    Example 1:
        Input: n = 2
        Output: 2
        Explanation: There are two ways to climb to the top.
            1. 1 step + 1 step
            2. 2 steps

    Example 2:
        Input: n = 3
        Output: 3
        Explanation: There are three ways to climb to the top.
            1. 1 step + 1 step + 1 step
            2. 1 step + 2 steps
            3. 2 steps + 1 step



// Observations: 
    - we are given staircase, it takes n steps to reach the top.
    - every time we can either climb 1 or 2 steps.
    - In how many distinct ways you climb to the top.


    // Approach: 
        - Every time we can either climb 1 stair, or 2 stairs.
        - we need to find the distinct ways to reach the top
        // recursion solutions: 
        
            // Base case: 
                - we will start with n & when we reach with '0', means we reach to top.
                if(n <= 1) return 1;    // to reach at last step, we only have 1 ways

            // Decision Tree:
                - choice_1: climb 1 stairs
                - choice_2: climb 2 stairs
                - last add choice1 + choice2    => With these choices, we can generate all the distinct.

            // Complexity: 
                - TC: O(2^n)
                - SC: O(n)

            - TLE: Because of overlapping subproblems:

                solve(5)
                    ├── solve(4)
                    │     ├── solve(3)
                    │     │     ├── solve(2)
                    │     │     │     ├── solve(1) = 1   (base)
                    │     │     │     └── solve(0) = 1   (base)
                    │     │     └── solve(1) = 1         (base)
                    │     └── solve(2)
                    │           ├── solve(1) = 1         (base)
                    │           └── solve(0) = 1         (base)
                    └── solve(3)
                        ├── solve(2)
                        │     ├── solve(1) = 1         (base)
                        │     └── solve(0) = 1         (base)
                        └── solve(1) = 1               (base)

        // Memoization: 
            - Build a memo-table around variable values, (n + 1) 
            - store the subproblems, & when it's needed, return it to the calls.

            // Complexity: 
                - TC: O(n)
                - SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Space Optimizations:
class Solution {
public:
    int climbStairs(int n) {

        long long prev = 1;
        long long curr = 1;
        long long next = prev + curr;

        for(int i = 2; i <= n; i++) {
            prev = curr;
            curr = next;
            next = curr + prev;
        }

        return (int)curr;
    }
};


// Tabulations: 
class Solution {
public:
    int climbStairs(int n) {

        vector<int> t(n + 1);
        t[0] = 1;
        t[1] = 1;

        for(int i = 2; i <= n; i++) {
            t[i] = t[i-1] + t[i-2];
        }

        return t[n];
    }
};


// Memoization Solution:
class Solution {
private: 
    vector<int> t;
    int solve(int n) {
        // Base case: 
        if(n <= 1) return 1;    // to reach the last step we have only 1 ways.

        if(t[n] != -1) return t[n];

        // Decision Tree: 
        int choice1 = solve(n - 1); // take 1 step at a time.
        int choice2 = solve(n - 2); // take 2 step at a time.

        return t[n] = choice1 + choice2;   // last add all the choices, as total number of distinct ways..
    }
public:
    int climbStairs(int n) {

        t.resize(n + 1, -1);

        return solve(n);
    }
};



// Recursive Solution:
class Solution {
private: 
    int solve(int n) {
        // Base case: 
        if(n <= 1) return 1;    // to reach the last step we have only 1 ways.

        // Decision Tree: 
        int choice1 = solve(n - 1); // take 1 step at a time.
        int choice2 = solve(n - 2); // take 2 step at a time.

        return choice1 + choice2;   // last add all the choices, as total number of distinct ways..
    }
public:
    int climbStairs(int n) {

        return solve(n);
    }
};