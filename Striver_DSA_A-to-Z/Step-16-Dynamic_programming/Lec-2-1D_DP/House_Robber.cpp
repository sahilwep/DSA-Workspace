/*

//  198. House Robber


//  Problem Statement: 
    - You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
    - Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 
// Example:
    Example 1:
        Input: nums = [1,2,3,1]
        Output: 4
        Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
        Total amount you can rob = 1 + 3 = 4.

    Example 2:
        Input: nums = [2,7,9,3,1]
        Output: 12
        Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
        Total amount you can rob = 2 + 9 + 1 = 12.


// Observations:
    - Robber can rob house along the street.
        - Each house has certain amount of money.
        - It's just if he rob the current house, he can't rob just after that, because alarm system is connected..
    - We need to find the maximum amount he can rob.

    // Approach:
        - Here we robber have choices from every idx:
            - Either rob & skip 1 pos
            - Skip that house..
        - We can recursively write the logic to explore all the possibility according to the given constrains..

        - For every idx:
            // Base case:
                if(idx >= n) return '0' // no further robbing, out of bound..

            // Decision Tree:
                loot = nums[idx] + solve(idx + 2);  // add current money into our answer, & skip just connected house & explore further..
                skip = solve(idx + 1);  // skip the current house & explore the next house..

                    -> This will make sure we will never loot two adjacent house..

                return max(loot, skip);     -> from every branch get the max loot we can get from future branches...
        
            // Complexity:
                - TC: O(2^n)    -> Two choices.
                - SC: O(n)      -> recursive calls depth, Exploring all the house

        // Memoization:
            - Subproblem called multiple times, because at any idx, it may be possible that we have already solve, & we are exploring it again..
            - Variable values:
                idx
                create memo-table of idx ranging size (0 - (n - 1))

            - Simply check in memo-table before exploring any future calls.


        // Tabulations:
            - Remove the Recursive calls:
                - DP State: 
                    idx
                - Transitions:
                    t[i] = max(nums[idx] + t[i+2], t[i+1])

            - Range (n - 1) to '0'
            - It's just create dp table of size (n + 2), so that there's no problem of accessing t[i+2] || t[i-1] from [n-1] idx
            - return t[0]
            - Base case:
                t[n] = 0
                t[n + 1] = 0
                because from recursion: if(idx >= n) return '0'

        // Space Optimization:
            - We are only carrying about the previous & prevPrevious value, and from them we are building the solution..
            - So instead of using the dp table, we can use two variable prev1, prev2,  & make our job done..
            

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Space Optimization:
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int prev = 0;
        int prev2 = 0;
        
        // recursive calls start from (n - 1) till '0'
        for (int idx = n - 1; idx >= 0; idx--) {
            int loot = nums[idx] + prev2;
            int skip = prev;
            int curr = max(loot, skip);

            // Update prev2 & prev
            prev2 = prev;
            prev = curr;
        }

        return prev;    // return prev
    }
};



// Tabulations:
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n + 2, 0);    // create (n + 2), because if we are idx (n - 1) & if we choose that, then we have to skip next index & get value from that curr->next->next idx, just to prevent out-of-bound
        
        // Fill base case: if(idx >= n) return 0
        t[n] = 0;
        t[n + 1] = 0;

        // recursive calls start from (n - 1) till '0'
        for (int idx = n - 1; idx >= 0; idx--) {
            int loot = nums[idx] + t[idx + 2];
            int skip = t[idx + 1];
            t[idx] = max(loot, skip);
        }

        return t[0];    // starting value t[0], will contains our answer..
    }
};

// Memoization:
class Solution {
private:
    int n;
    vector<int> t;
    int solve(int idx, vector<int>& nums) {
        if(idx >= n) return 0;  // no further finding

        if(t[idx] != -1) return t[idx];

        // Choices: loot(skip 1-pos) / Don't loot
        int loot = nums[idx] + solve(idx + 2, nums);
        int skip = solve(idx + 1, nums);

        int totalLoot = max(loot, skip);    // we need the maxSum from these future branches..

        return t[idx] = totalLoot;
    }
public:
    int rob(vector<int>& nums) {
        n = nums.size();

        t.resize(n + 2, -1);
        return solve(0, nums);
    }
};


// Recursive:
class Solution {
private:
    int n;
    int solve(int idx, vector<int>& nums) {
        if(idx >= n) return 0;  // no further finding

        // Choices: loot(skip 1-pos) / Don't loot
        int loot = nums[idx] + solve(idx + 2, nums);
        int skip = solve(idx + 1, nums);

        int totalLoot = max(loot, skip);    // we need the maxSum from these branches..

        return totalLoot;
    }
public:
    int rob(vector<int>& nums) {
        n = nums.size();

        return solve(0, nums);
    }
};