/*

//  896. Monotonic Array


//  Problem Statement: 
    -> An array is monotonic if it is either monotone increasing or monotone decreasing.
    -> An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
    -> Given an integer array nums, return true if the given array is monotonic, or false otherwise.


// Example:

    Example 1:
        Input: nums = [1,2,2,3]
        Output: true

    Example 2:
        Input: nums = [6,5,4,4]
        Output: true

    Example 3:
        Input: nums = [1,3,2]
        Output: false


// Observations:
    -> Find increasing, decreasing & same values & compute monotonic ordering


    // Complexity:
        -> TC: O(n)
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    bool isIncreasing(vector<int>& nums, int n) {
        for(int i = 1; i < n; i++) if(nums[i-1] > nums[i]) return false;
        return true;
    }
    bool isDecreasing(vector<int>& nums, int n) {
        for(int i = 1; i < n; i++) if(nums[i-1] < nums[i]) return false;
        return true;
    }
    bool isSame(vector<int>& nums, int n) {
        for(int i = 1; i < n; i++) if(nums[i-1] != nums[i]) return false;
        return true;
    }
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();

        if(isSame(nums, n)) return true;    // Edge case: if all elements are same

        if(isIncreasing(nums, n) && isDecreasing(nums, n) || 
        !isIncreasing(nums, n) && !isDecreasing(nums, n)) return false;

        return true;
    }
};