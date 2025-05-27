/*

//  33. Search in Rotated Sorted Array



//  Problem Statement: 
    -> There is an integer array nums sorted in ascending order (with distinct values).
    -> Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
    -> Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
    -> You must write an algorithm with O(log n) runtime complexity.



// Example: 
    Example 1:
        Input: nums = [4,5,6,7,0,1,2], target = 0
        Output: 4

    Example 2:
        Input: nums = [4,5,6,7,0,1,2], target = 3
        Output: -1

    Example 3:
        Input: nums = [1], target = 0
        Output: -1



// Solution: 
    -> First check the sorted part:
    -> Secondly we will check the target lies within range.



// Complexity: 
    -> TC: O(logn)
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid] == target) return mid;

            // Check if left half is sorted?
            if(nums[low] <= nums[mid]) {
                // Target lies in left sorted half:
                if(nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            else {  // Otherwise, right half must be sorted
                // target lies in right shorted half:
                if(nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }

            }
        }

        return -1;  // not found
    }
};