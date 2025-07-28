/*

//  2044. Count Number of Maximum Bitwise-OR Subsets



//  Problem Statement: 
    -> Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.
    -> An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.
    -> The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).


// Example: 
    Example 1:
        Input: nums = [3,1]
        Output: 2
        Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
        - [3]
        - [3,1]

    Example 2:
        Input: nums = [2,2,2]
        Output: 7
        Explanation: All non-empty subsets of [2,2,2] have a bitwise OR of 2. There are 23 - 1 = 7 total subsets.

    Example 3:
        Input: nums = [3,2,1,5]
        Output: 6
        Explanation: The maximum possible bitwise OR of a subset is 7. There are 6 subsets with a bitwise OR of 7:
        - [3,5]
        - [3,1,5]
        - [3,2,5]
        - [3,2,1,5]
        - [2,5]
        - [2,1,5]


// Observations: 
    -> OR Property: if any bit is 1, it will make that positions as true.
    -> Try finding the OR of whole array, that will be our maximum OR subset 
    -> After try building the subset having that maximum value.
        -> Use target sum Approach DP


    // Complexity: 
        -> TC: O(2^n)
        -> SC: O(n)


    // Optimizations: 
        -> We are calculating same subset again & again, for further possible values, which is nothing but recomputation of subproblems.
        -> We can optimize this using memoization.
            -> Dp State: 
                -> Changing variables are: currentIndex & the currentOR so far
                -> These two values we can store using map
                -> All we have to do is generate unique key: for 
                -> Map will helps us to track the current index & so-far their OR operations.
                    -> map the unique key combinations by forming index & OR so-far combinations
                    -> check in map, if it's present, return else compute & hash


        // Complexity: 
            -> TC: O(n * maxOR)
            -> SC: O(n * maxOR)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Optimized DP based Solution: 
class Solution {
private: 
    unordered_map<string, int> dp;
    int countSubset(vector<int>& nums, int index, int currOR, int maxOR) {
        // Base Case:
        if(index == nums.size()) {    // when we have explored all the cases:
            return currOR == maxOR ? 1 : 0;   // return true if result become maximum value..
        }

        // Check in memo-table:
        string key = to_string(index) + '#' + to_string(currOR);    // generate key for map, from current index & OR computed so-far
        if(dp.count(key)) { // if key present -> return
            return dp[key];
        }

        // Choices: Two choices -> Accept the current || reject => Get the total found subset from them..
        int acceptCase = countSubset(nums, index + 1, currOR | nums[index], maxOR);   // accept case
        int rejectCase = countSubset(nums, index + 1, currOR, maxOR);     // reject case

        return dp[key] = acceptCase + rejectCase;   // hash the key & return
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        // Find the maximum OR value:
        int maxOR = 0;
        for(auto& it: nums) maxOR |= it;

        // Now find the number of subset doing OR operations, having that maxValue:
        return countSubset(nums, 0, 0, maxOR);
    }
};


// BruteForce Solution: 
class Solution {
private: 
    int countSubset(vector<int>& nums, int res, int maxVal, int n) {
        // Base Case:
        if(n == 0) {    // when we have explored all the cases:
            return res == maxVal ? 1 : 0;   // return true if result become maximum value..
        }

        // Choices: Two choices -> Accept the current || reject => Get the total found subset from them..
        return countSubset(nums, (res | nums[n-1]), maxVal, n - 1) +    // accept case
            countSubset(nums, res, maxVal, n - 1);  // reject case
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        // Find the maximum OR value:
        int maxVal = 0;
        for(auto& it: nums) maxVal |= it;

        // Now find the number of subset doing OR operations, having that maxValue:
        int temp = 0;
        int res = countSubset(nums, temp, maxVal, n);
        
        return res;
    }
};