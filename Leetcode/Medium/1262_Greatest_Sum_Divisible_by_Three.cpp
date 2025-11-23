/*

//  1262. Greatest Sum Divisible by Three


//  Problem Statement: 
    - Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

 
// Example:
    Example 1:
        Input: nums = [3,6,5,1,8]
        Output: 18
        Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).

    Example 2:
        Input: nums = [4]
        Output: 0
        Explanation: Since 4 is not divisible by 3, do not pick any number.

    Example 3:
        Input: nums = [1,2,3,4,4]
        Output: 12
        Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).


// Observations: 
    - given nums, we can choose any elements & sums them up, Then the sum must be divisible by 3
    - we need to return the maximum sum.

    // BruteForce Solution: 
        - Using recursive solution, generate all possible sums..
        - Then store the maximum sum into our answer which is divisible by 3.
        - Then return the maximum answer.

            - base case: 
                if (idx < 0):
                    if(sum % 3 == 0) return sum
                    else return 0
            - Decision Tree:
                take = solve(nums, idx - 1, sum + nums[idx]);
                skip = solve(nums, idx - 1, sum);
                return max(take, skip)
                
        - This Comes up with TLE:
            - Memoize as we are recomputing the sub-problem again n again..
            - Variable Values: (idx & sum)
            - Problem is sum becomes larger & larger..
            - Instead of sum we will compute over it's remainder values..
                // Key Observations: 
                - If we compute the remainder of (anY_NUm % 3), we only have these 3 values: {0 1 2}

            dp[n][r]    -> r belongs to {0, 1, 2}

        - We can convert this memoization solution to  Tabulations.
        

        - Complexity: 
            - TC: O(n * 3) = O(n)
            - SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Tabulations: 
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp(n + 1, vector<int> (3, INT_MIN));

        // Fill the base case table:
        dp[n][0] = 0;
        dp[n][1] = INT_MIN;
        dp[n][2] = INT_MIN;

        for(int i = n - 1; i >= 0; i--) {
            for(int rem = 0; rem < 3; rem++) {
                int newRem = (rem + nums[i]) % 3;
                int take = nums[i] + dp[i + 1][newRem];
                int skip = dp[i + 1][rem];

                dp[i][rem] = max(take, skip);
            }
        }

        return dp[0][0];
    }
};


// Memoization:
class Solution {
private:
    vector<vector<int>> dp;
    int solve(vector<int> &nums, int idx, int r) {
        // Base case:
        if(idx < 0) {
            if(r == 0) return 0;
            else return INT_MIN;
        }

        if(dp[idx][r] != INT_MIN) return dp[idx][r]; // check in memo table, & return value directly...


        int skip = solve(nums, idx - 1, r);
        int take = nums[idx] + solve(nums, idx - 1, (r + nums[idx]) % 3);

        // return maximum:
        return dp[idx][r] =  max(take, skip);
    }
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        
        dp.resize(n + 1, vector<int> (3, INT_MIN));

        return solve(nums, n - 1, 0);
    }
};


// Recursive: 
class Solution {
private:
    int solve(vector<int> &nums, int idx, int r) {
        // Base case:
        if(idx < 0) {
            if(r == 0) return 0;
            else return INT_MIN;
        }

        int skip = solve(nums, idx - 1, r);
        int take = nums[idx] + solve(nums, idx - 1, (r + nums[idx]) % 3);

        // return maximum:
        return max(take, skip);
    }
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();

        return solve(nums, n - 1, 0);
    }
};




// -------------------------- Old Solution ----------------------

// Memoization:
class Solution {
private:
    vector<vector<int>> dp;
    int solve(vector<int> &nums, int idx, int r) {
        // Base case:
        if(idx < 0) {
            if(r == 0) return 0;
            else return INT_MIN;
        }

        if(dp[idx][r] != INT_MIN) return dp[idx][r]; // check in memo table, & return value directly...

        // Skip:
        int skip = solve(nums, idx - 1, r);

        // Take:
        int newR = (r - nums[idx] % 3 + 3) % 3;
        int take = solve(nums, idx - 1, newR);
        if(take != INT_MIN) take += nums[idx];

        // return maximum:
        return dp[idx][r] =  max(take, skip);
    }
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        
        dp.resize(n + 1, vector<int> (3, INT_MIN));

        return solve(nums, n - 1, 0);
    }
};


// Recursive: 
class Solution {
private:
    int solve(vector<int> &nums, int idx, int sum) {
        // Base case:
        if(idx < 0) {
            if(sum % 3 == 0) return sum;
            else return 0;
        }

        int take = solve(nums, idx - 1, sum + nums[idx]);
        int skip = solve(nums, idx - 1, sum);

        return max(take, skip);
    }
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        
        return solve(nums, n - 1, 0);
    }
};


// Recursive Naive:
class Solution {
private:
    int ans = 0;
    void solve(vector<int> &nums, int idx, int sum) {
        if(sum % 3 == 0) {
            ans = max(ans, sum);
        }
        if(idx < 0) return;

        solve(nums, idx - 1, sum + nums[idx]);
        solve(nums, idx - 1, sum);
    }
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        
        solve(nums, n - 1, 0);

        return ans;
    }
};