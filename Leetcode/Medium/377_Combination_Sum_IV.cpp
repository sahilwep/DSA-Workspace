/*

//  377. Combination Sum IV


//  Problem Statement: 
    - Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
    - The test cases are generated so that the answer can fit in a 32-bit integer.
 
// Example:
    Example 1:

        Input: nums = [1,2,3], target = 4
        Output: 7
        Explanation:
            The possible combination ways are:
            (1, 1, 1, 1)
            (1, 1, 2)
            (1, 2, 1)
            (1, 3)
            (2, 1, 1)
            (2, 2)
            (3, 1)
            Note that different sequences are counted as different combinations.

    Example 2:
    Input: nums = [9], target = 3
    Output: 0

// Constraints:

    1 <= nums.length <= 200
    1 <= nums[i] <= 1000
    All the elements of nums are unique.
    1 <= target <= 1000

 



// Observations:
    - This looks like unbounded knapsack, it's just we will have to count total number of possible combinations we can achieve target.
    - But we will have count the different combinations.
    - as:

        Input: nums = [1,2,3], target = 4
        Output: 7
        Explanation:
            The possible combination ways are:
            (1, 1, 1, 1)
            (1, 1, 2)
            (1, 2, 1)
            (1, 3)
            (2, 1, 1)
            (2, 2)
            (3, 1)
            Note that different sequences are counted as different combinations.

        -> Here only 4 unique sequence, but it is counted 7 as different arrangement.

    // Approach:
        - We can still solve this using recursion solution:

            // Base conditions:
                -> if target == 0 = >return 1, as we find one valid arrangement.
                -> else return 0: no valid arrangement found.

            // Decision tree:
                -> if current nums[i] is less or equal to target:
                    -> include it and move
                    -> include it and dont' move

                -> else reject

                ways = 0;
                if(nums[n - 1] <= target) {
                    ways += solve(nums, target - nums[n - 1], n - 1)    // include and move
                    + solve(nums, target - nums[n - 1], n); // include but not moved.
                } else {
                    // value is grater, anyway we will have to reject this:
                    ways += solve(nums, target, n - 1)
                }

                return ways.


        -> Here it return the total number of ways, and not return he possible combinations.
        -> To generate the possible combinations:
            -> we will will have to do something else..

        -> We have format to generate premutation, general format:
            func(nums[], target, curr[]) {
                // Base case:
                if(target == 0){
                    // Found valid sequence
                    ans.push_back(curr);    // store sequence...
                    return;
                }

                if(target < 0) return;  // invalid sequence.

                // Decision tree:
                // always loop from 0 to (No, 'idx' paremeter)
                for(int i = 0; i < nums.size(); i++) {
                    curr.push_back(nums[i]);                            // choose
                    generatePermutation(nums, target - nums[i], curr);  // explore
                    curr.pop_back();                                    // backtrack
                }

            }
            --------------------------------------

        -> From this we will write our solution.
        -> we will memoize our solution, as it goes into computing subproblem again and again.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Memoization Solution: class Solution {
private:
    int n;
    vector<int> t;
    int solve(vector<int>& nums, int target) {
        // Base condition:
        if(target == 0) return 1;   // found 1 arrangement
        if(target < 0) return 0;    // not found

        if(t[target] != -1) return t[target];

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += solve(nums, target - nums[i]);
        }

        return t[target] = ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();

        t.resize(target + 1, -1);

        return solve(nums, target);
    }
};


// Recursive Solution:
class Solution_R {
private:
    int n;
    int solve(vector<int>& nums, int target) {
        // Base condition:
        if(target == 0) return 1;   // found 1 arrangement
        if(target < 0) return 0;    // not found

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += solve(nums, target - nums[i]);
        }

        return ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();

        return solve(nums, target);
    }
};