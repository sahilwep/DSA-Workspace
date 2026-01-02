/*

//  DP 1. Introduction to Dynamic Programming

    - Dynamic Programming can be describe as storing the answer to various sub-problems to be used later whenever required to solve main problem.
    - When any Recursive solution has subproblems overlapping: 
        - Why not store them somewhere & directly get the answer whenever that subproblem called again..
        - How to do this:
            - we can achieve this by using something like {map, array, matrix(2d-array), 3d-array etc..}
            - It's all depends upon our usecase..

            
    // Memoization:
        - Memoization is the process of converting our recursive problem into Memoized version:
            - When we checked base case, just after that, 
                - Check if that current subproblem is explored previously or not?
                    if(dp[idx] != -1) { // we are checking with '-1', it can be anything, like the default value of our memo-table
                        return dp[idx]
                    }
                    
                - Last before returning anything in Decision tree, store the answer into memo-table:
                    - something like: return dp[idx] = ans; 


    // Tabulations:
        - Tabulations is where we remove the recursion completely & convert our solution to iterative ones.
        - It's just we need to take care of 'DP sates' & 'DP transition'
            - DP States:
                - The values/parameter in functions that are changing continuously
                - Example: for fibb, our index value changing continuously..
                    - DP State = idx
                - While Defining DP State:
                    - Observe, From what value to what value our DP state is changing..
                    - like 0 to 'n', which is the nth value of of fibb finding..
                    - Create a Table of that size, it can be 1D/2D Depending upon how many DP sates we have

            - DP Transitions:
                - This is the recursive calls we are doing in our memoization.
                - Instead of running the recursive calls & getting the answer, we simply get the values from our DP table.
                    - Something like:
                            dp[i] = dp[i-1] + dp[i-2];
                    - Instead of {return solve(i + 1) + solve(i + 2)}

            - NOTE: 
                - Fill the base cases initially into our DP table:
                    - like
                        dp[0] = 0;
                        dp[1] = 1;

                        similarly to
                            fibb(0) = 0
                            fibb(1) = 1
                        This will help us to explore the further values..
                - Define The Range of Iterations/Loop by observing what's the range of recursive calling like: (2 -- n-1)
                - And you are all set..

    // NOTE: 
        - Memoization & Tabulations is same when we are comparing in terms of time.
        - It's just Tabulations remove the extra overhead of stack space to calling every subproblem in recursive way..
        - But overall space required to solve problem will not be changed, because that's our Dp-table/memo-table.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Space Optimizations:
class Solution {
public:
    int nthFibonacci(int n) {
        
        if(n <= 1) return n;
        
        int first = 0;
        int second = 1;
        int next = first + second;
        for(int i = 2; i <= n; i++) {
            first = second;
            second = next;
            next = first + second;
        }
              
        return second;
    }
};

// Tabulations:
class Solution {
public:
    int nthFibonacci(int n) {
        
        if(n <= 1) return n;
        
        vector<int> t(n + 1, 0);
        t[0] = 0, t[1] = 1;
        
        for(int i = 2; i <= n; i++) {
            t[i] = t[i-1] + t[i-2];
        }
        
        return t[n];
    }
};



// Memoization: 
class Solution {
private: 
    vector<int> t;
    int solve(int n) {
        if(n <= 1) return n;
        
        if(t[n] != -1) return t[n];
        
        return t[n] = solve(n - 1) + solve(n - 2);
    }
public:
    int nthFibonacci(int n) {
        
        if(n <= 1) return n;
        
        t.resize(n + 1, -1);
        t[0] = 0;
        t[1] = 1;
        
        return solve(n);
    }
};


// recursion: 
class Solution {
private: 
    // Recursive way:
    int solve(int n) {
        if(n <= 1) return n;
        
        return solve(n - 1) + solve(n - 2);
    }
public:
    int nthFibonacci(int n) {
        
        if(n <= 1) return n;
        
        return solve(n);
    }
};