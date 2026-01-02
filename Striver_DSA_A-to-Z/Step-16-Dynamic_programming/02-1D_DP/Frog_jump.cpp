/*

//  Frog Jump

//  Problem Statement: 
    - Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the last stair. 
    - From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. 
    - The cost of a jump is the absolute difference in height between the two stairs. 
    - Determine the minimum total cost required for the frog to reach the last stair.

    Example:
        Input: heights[] = [20, 30, 40, 20]
        Output: 20
        Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
        jump from stair 0 to 1: cost = |30 - 20| = 10
        jump from stair 1 to 3: cost = |20 - 30| = 10
        Total Cost = 10 + 10 = 20

        Input: heights[] = [30, 20, 50, 10, 40]
        Output: 30
        Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
        jump from stair 0 to 2: cost = |50 - 30| = 20
        jump from stair 2 to 4: cost = |40 - 50| = 10
        Total Cost = 20 + 10 = 30

// Observations: 
    - We are given height[i] this represent height of i-th stair 
        - From starts from the first stairs & have to reach last step.
        - It can either jumps (i + 1), or (i + 2) steps from the current step
        - We need to find the minimum cost required to frog reach last stairs.
            - Cost will be computed as:
                -> cost = abs(height[i] - height[i+1]) || abs(height[i] - height[i+2]) depending on what we choose..
    
    // Bruteforce Approach:
        - From every index 'i' we have options to trave:
            - (i + 1) step
            - (i + 2) step.
        - Recursion will helps us to explore the possibility:
            - Starting from the index '0' & goes up till n - 1:
                - If we are at last index: 'n - 1' -> no need to explore further return '0' as further exploration cost.

            - Choices:
                oneJump = solve(idx + 1, height) + abs(height[i] + height[i + 1]);
                if(idx < height.size() - 2) {   // because we are exploring the two ahead..
                    twoJump = solve(idx + 2, height) + abs(height[i] - height[i + 2]);
                }

                return min(oneJump, twoJump);    => From that current idx: we will return the minimum cost get so-far in future calls.
            
            - NOTE: Our Recursive function is designed from '0' to 'n - 1'.
                - If we want to start from the index 'n - 1' & travel backwords, in that case we need to reverse our base case & iterating logic, so that we can travel backwords..
            
            // Complexity: 
                - TC: O(2^n)
                    - Because we have two branch to travel.
                - SC: O(n)
                    - Because we are exploring the '0' to 'n-1' in depth.

                -> This falls into TLE, because we are recomputing the same subproblems multiple times..

    // Memoization:
        - Memoize the current recursive Solution:
            - DP State: variable values which are continuously changing in every recursive calls.
                - 'idx'
                - Range of 'idx': (0 - (n - 1)) -> 
            - memo-table size: (n + 1), which is size of heights

        // Complexity:
            - TC: O(n)
            - SC: O(n)

    // Tabulations
        - Convert the recursive solution to the Iterative one:
            - Base case:
                - t[0] = 0;
            - Iterate Case:
                - Start from i = 1 & goes up to (n - 1);
                    - OneStep = t[i-1] + abs(height[i] - height[i-1]);
                    - if(i > 1): twoStep = t[i-2]  + abs(height[i] - height[i - 2]);
                    - t[i] = min(oneStep, twoStep)  => Get the minimum from the explorations..

            - Last return the t[n-1] => last computed value, which holds our solution.
        
        // Complexity: 
            - TC: O(n)
            - SC: O(n)

    // Space Optimization:
        - We are only caring about the prev & prev2 values..
        - so instead of maintaining the whole dp-table, we can only use these two variables, makes our job done.
        - It's just, after all the operations in Every iterations:
            - update: 
                prev2 = prev1
                prev1 = curr

                NOTE: curr is our current idx min(oneStep, twoStep)

        // Complexity:
            - TC: O(n)
            - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Space Optimization:
class Solution {
private:
    vector<int> t;
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        
        int prev2 = 0;
        int prev = 0;
        for(int i = 1; i < n; i++) {
            int oneStep = prev + abs(height[i] - height[i-1]);
            int twoStep = (i > 1) ? prev2 + abs(height[i] - height[i-2]) : INT_MAX;
            
            int curr = min(oneStep, twoStep);
            
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
};


// Tabulations:
class Solution {
private:
    vector<int> t;
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        
        t.resize(n + 1, 0);
        t[0] = 0;
        for(int i = 1; i < n; i++) {
            int oneStep = t[i-1] + abs(height[i] - height[i-1]);
            int twoStep = (i > 1) ? t[i-2] + abs(height[i] - height[i-2]) : INT_MAX;
            t[i] = min(oneStep, twoStep);
        }
        
        return t[n-1];
    }
};


// Memoization: Exploring from (n - 1 -> 0)
class Solution {
    vector<int> t;
    int solve(int idx, vector<int>& height) {
        if(idx == 0) return 0;  // reached at last idx -> 0, no need to explore further
        
        if(t[idx] != -1) return t[idx];
        
        int oneJump = solve(idx - 1, height) + abs(height[idx] - height[idx - 1]);
        int twoJump = (idx > 1) ? solve(idx - 2, height) + abs(height[idx] - height[idx - 2]): INT_MAX;
        
        return t[idx] = min(oneJump, twoJump);
    }
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        
        t.resize(n + 1, -1);
        
        return solve(n - 1, height);
    }
};

// Memoization:  Exploring from (0 -> n - 1)
class Solution {
    vector<int> t;
    int solve(int idx, vector<int>& height) {
        if(idx == height.size() - 1) return 0;  // if we are at last idx -> 0, not need to go-forward
        
        if(t[idx] != -1) return t[idx];
        
        int oneJump = solve(idx + 1, height) + abs(height[idx] - height[idx + 1]);
        int twoJump = (idx < height.size() - 2) ? solve(idx + 2, height) + abs(height[idx] - height[idx + 2]): INT_MAX;
        
        return t[idx] = min(oneJump, twoJump);
    }
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        
        t.resize(n + 1, -1);
        
        return solve(0, height);
    }
};


// Recursive:
class Solution {
    int solve(int idx, vector<int>& height) {
        if(idx == height.size() - 1) return 0;  // if we are at last idx -> 0, not need to go-forward
        
        int oneJump = solve(idx + 1, height) + abs(height[idx] - height[idx + 1]);
        int twoJump = (idx < height.size() - 2) ? solve(idx + 2, height) + abs(height[idx] - height[idx + 2]): INT_MAX;
        
        return min(oneJump, twoJump);
    }
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        
        return solve(0, height);
    }
};