/*

//  213. House Robber II

//  Problem Statement: 
    - You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
    - Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
 
// Example:
    Example 1:
        Input: nums = [2,3,2]
        Output: 3
        Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

    Example 2:
        Input: nums = [1,2,3,1]
        Output: 4
        Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
        Total amount you can rob = 1 + 3 = 4.

    Example 3:
        Input: nums = [1,2,3]
        Output: 3


// Observations:
    - Robber is planning to rob a house
    - Given nums[i] = money in ith house.
    - It's just robber can't rob two adjacent house..
    - also 0th house & 'n-1' house is connected, means we have house in circle..
    
    // Approach:
        - If we loot 0th house, we can't loot (n - 1)th house.
        - If we loot (n - 1)th house we can't loot 0th house..
        - From this observations, can we say:
            - first find the robbing in range: 0 <= i <= n - 2
            - Second find the robbing in range: 1 <= i <= n - 1
            - Last get the maximum from both the options:
                -> max(option1, option2)

        - This Problem is extended version of LC - 198, it's just the houses are connected in circle.
        - We will use Recursive Solution to explore loot:
            int solve(idx, house, n) {
                ...
            }
            This function will take range 'idx' to 'n' & explore the loot process...

            // base condition:
                if(idx >= n) return 0;

            // Decision Tree:
                loot = nums[idx] + solve(idx + 2, height, n);
                skip = solve(idx + 1, height, n);

                return max(loot, skip)

            // Last in controller logic:
                int c1 = solve(0, height, n - 1);
                int c2 = solve(1, height, n);

                return max(c1, c2);     => This is our answer...


        // Complexity:
            - TC: O(2^n)
            - SC: O(n)


    // Memoization:
        - Changing values:
            idx
        - Create a memo-table of size (n + 1), because 0 <= idx <= n, one extra space for safety..
        - For every subproblem, check in memo-table, before going into the decisions tree.

        // Complexity:
            - TC: O(n)
            - SC: O(n)


    // Tabulations:
        - DP State:
            idx
        - DP Transitions:
            t[i] = max(t[i + 1], t[i + 2] + nums[i])
        - Create DP-table with size (n + 2), because we are accessing {one & two} value ahead..
        - Fill the table for base case:
            if(n >= 0):
                dp[n] = 0;
                dp[n + 1] = 0;
        - Range of loop:
            - This depends on choices:
                c1:     0 <= c1 <= n - 2
                c2:     1 <= c2 <= n - 1
            - We will have to write 2 different loop & get the choices & at last we will return max(c1, c2)

        // Complexity:
            - TC: O(n)
            - SC: O(n)
            
            
    // Space Optimization:
        - we are only caring about two previous values..
        - So we will use prev1 & prev2 & make our job done.

            // Complexity:
                - TC: O(n)
                - SC: O(n)


// Extra:
    - Explore Previous version solution.
    - LC: 198: https://github.com/sahilwep/DSA-Workspace/blob/6ce70bee4ca02aaf671d1d5af1fc4002a7621449/Leetcode/Medium/198_House_Robber.cpp

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Space Optimized:
class Solution {
    int solve(int idx, vector<int>& nums, int n) {
        
        vector<int> t(n + 2);

        int prev2 = 0;
        int prev = 0;

        for(int i = n - 1; i >= idx; i--) {
            int loot = nums[i] + prev2;
            int skip = prev;

            int curr = max(loot, skip);

            // Update prev2 & prev:
            prev2 = prev;
            prev = curr;
        }

        return prev;
    }   
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        int x = solve(1, nums, n);
        int y = solve(0, nums, n - 1);

        return max(x, y);
    }
};


// Tabulations:
class Solution {
    int solve(int idx, vector<int>& nums, int n) {
        
        vector<int> t(n + 2);

        t[n] = 0;
        t[n-1] = 0;

        for(int i = n - 1; i >= idx; i--) {
            int loot = nums[i] + t[i+2];
            int skip = t[i+1];

            t[i] = max(loot, skip);
        }

        return t[idx];
    }   
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        int x = solve(1, nums, n);
        int y = solve(0, nums, n - 1);

        return max(x, y);
    }
};


// Memoization solution: modularize
class Solution {
    vector<int> t;
    int solve(int idx, vector<int>& nums, int n) {  // single function will take range & calculate on that..
        if(idx >= n) return 0;  // no further finding

        // Check in memo table:
        if(t[idx] != -1) {
            return t[idx];
        }

        // Choices: loot(skip 1-pos) / Don't loot
        int loot = nums[idx] + solve(idx + 2, nums, n);
        int skip = solve(idx + 1, nums, n);

        int totalLoot = max(loot, skip);    // we need the maxSum from these future branches..

        return t[idx] = totalLoot;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        t.assign(n + 1, -1);
        int x = solve(1, nums, n);
        t.assign(n + 1, -1);
        x = max(x, solve(0, nums, n - 1));        

        return x;
    }
};


// Memoization Solution:
class Solution {
    int n;
    vector<int> t1, t2;
    int solve1(int idx, vector<int>& nums) {    // 1 to n - 1
        if(idx >= n) return 0;  // no further finding

        // Check in memo table:
        if(t1[idx] != -1) {
            return t1[idx];
        }


        // Choices: loot(skip 1-pos) / Don't loot
        int loot = nums[idx] + solve1(idx + 2, nums);
        int skip = solve1(idx + 1, nums);

        int totalLoot = max(loot, skip);    // we need the maxSum from these future branches..

        return t1[idx] = totalLoot;
    }
    int solve2(int idx, vector<int> &nums) {    // 0 to n - 2
        if(idx >= n - 1) return 0;  // no further finding

        // Check in memo table:
        if(t2[idx] != -1) {
            return t2[idx];
        }

        // Choices: loot(skip 1-pos) / Don't loot
        int loot = nums[idx] + solve2(idx + 2, nums);
        int skip = solve2(idx + 1, nums);

        int totalLoot = max(loot, skip);    // we need the maxSum from these future branches..

        return t2[idx] = totalLoot;

    }
public:
    int rob(vector<int>& nums) {
        n = nums.size();

        if(n == 1) return nums[0];

        t1.resize(n + 1, -1);
        t2.resize(n + 1, -1);

        return max(solve1(1, nums), solve2(0, nums));        
    }
};



// Recursive Solution:
class Solution {
    int n;
    int solve1(int idx, vector<int>& nums) {    // 1 to n - 1
        if(idx >= n) return 0;  // no further finding

        // Choices: loot(skip 1-pos) / Don't loot
        int loot = nums[idx] + solve1(idx + 2, nums);
        int skip = solve1(idx + 1, nums);

        int totalLoot = max(loot, skip);    // we need the maxSum from these future branches..

        return totalLoot;
    }
    int solve2(int idx, vector<int> &nums) {    // 0 to n - 2
        if(idx >= n - 1) return 0;  // no further finding

        // Choices: loot(skip 1-pos) / Don't loot
        int loot = nums[idx] + solve2(idx + 2, nums);
        int skip = solve2(idx + 1, nums);

        int totalLoot = max(loot, skip);    // we need the maxSum from these future branches..

        return totalLoot;

    }
public:
    int rob(vector<int>& nums) {
        n = nums.size();

        if(n == 1) return nums[0];

        return max(solve1(1, nums), solve2(0, nums));        
    }
};