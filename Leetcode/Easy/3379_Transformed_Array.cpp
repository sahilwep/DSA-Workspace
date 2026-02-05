/*

//  3379. Transformed Array


//  Problem Statement: 
    - You are given an integer array nums that represents a circular array. Your task is to create a new array result of the same size, following these rules:
    - For each index i (where 0 <= i < nums.length), perform the following independent actions:
        - If nums[i] > 0: Start at index i and move nums[i] steps to the right in the circular array. Set result[i] to the value of the index where you land.
        - If nums[i] < 0: Start at index i and move abs(nums[i]) steps to the left in the circular array. Set result[i] to the value of the index where you land.
        - If nums[i] == 0: Set result[i] to nums[i].
    - Return the new array result.
    - Note: Since nums is circular, moving past the last element wraps around to the beginning, and moving before the first element wraps back to the end.

 
// Example:
    Example 1:
        Input: nums = [3,-2,1,1]
        Output: [1,1,1,3]
        Explanation:
            For nums[0] that is equal to 3, If we move 3 steps to right, we reach nums[3]. So result[0] should be 1.
            For nums[1] that is equal to -2, If we move 2 steps to left, we reach nums[3]. So result[1] should be 1.
            For nums[2] that is equal to 1, If we move 1 step to right, we reach nums[3]. So result[2] should be 1.
            For nums[3] that is equal to 1, If we move 1 step to right, we reach nums[0]. So result[3] should be 3.

    Example 2:
        Input: nums = [-1,4,-1]
        Output: [-1,-1,4]
        Explanation:
            For nums[0] that is equal to -1, If we move 1 step to left, we reach nums[2]. So result[0] should be -1.
            For nums[1] that is equal to 4, If we move 4 steps to right, we reach nums[2]. So result[1] should be -1.
            For nums[2] that is equal to -1, If we move 1 step to left, we reach nums[1]. So result[2] should be 4.

 
// Observations:
    - Given array nums, consider it as circular array.
    - we have to build answer of size nums where:
        - if nums[i] = 0 => ans[i] = nums[i]
        - if nums[i] < 0: negative:
            - move left abs(nums[i]) times ans put ans[i] = nums[step]
        - if nums[i] > 0: positive:
            - move right and ans[i] = nums[step]

    // Approach:
        - To calculate the steps for negative & positive
            - For negative:
                - we will move abs(nums[i]) step & taking mod % n, so that we can stay in range
                - then we will move exactly n steps(add n) so that we can be at right place in left directions.
                - lastly mod with n, so that we can stay in range.
            - For positive:
                - we will add nums[i] times.
                - takeing mod with n, so that we will stay in range.
            - for nums[i] = 0, we will not moving anywhere.

        // Complexity:
            - TC: O(n)
            - SC: O(n)
        

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) {   // neg: go left
                int step = abs(nums[i]);
                int pos = ((i - step) % n + n) % n;
                ans[i] = nums[pos];
            } else if(nums[i] > 0) {    // positive: go right
                int step = nums[i];
                int pos = (i + step) % n;
                ans[i] = nums[pos];
            } else {    // paste the same nums[i]
                ans[i] = nums[i];
            }
        }

        return ans;
    }
};