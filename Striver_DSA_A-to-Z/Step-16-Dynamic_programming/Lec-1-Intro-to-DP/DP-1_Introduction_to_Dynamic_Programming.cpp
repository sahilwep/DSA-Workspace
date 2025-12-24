/*

//  DP 1. Introduction to Dynamic Programming

    - Dynamic Programming can be describe as storing the answer to various sub-problems to be used later whenever required to solve main problem.
    - 
    






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