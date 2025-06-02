/*

//   BS-5. Search Element in Rotated Sorted Array II 

//  Problem Statement: 
    -> There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
    -> Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
    -> Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
    -> You must decrease the overall operation steps as much as possible.

 
// Example: 
    Example 1:
        Input: nums = [2,5,6,0,0,1,2], target = 0
        Output: true

    Example 2:
        Input: nums = [2,5,6,0,0,1,2], target = 3
        Output: false


// Observations:
    -> given an array nums, sorted & rotated which may contains duplicates values
    -> given target, return true if it's present in list, or return false:
    -> Example:

        2   5   6   0   0   1   2           x = 0
        |           |           |
        low        mid         high

        1   0   1   1   1
        |       |       |
        low     mid     high

        (arr[low] == arr[mid] == arr[high]) -> This is the only conditions which occurs the problem
        If we can rid of this conditions, then we are easily able to solve this..
        What we can do is trim down the search space, by simply moving low & high towards mid by 1
        In simple, whenever we get these conditions, we will move our search space towards mid by 1.
        
        In Worse case: runs for O(n), when all the elements are equal
            
        Best case O(log(n))


// Complexity: 
    -> TC: O(n) Worse
    -> TC: O(logN)avg case
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid] == target) return true;

            // Case where all the pointers (low, mid, high) are same
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                // trim down search space
                low++;
                high--;
                continue;
            }

            // Check sorted ranges: 
            if(nums[low] <= nums[mid]) {  // left half is sorted
                if(target >= nums[low] && target < nums[mid]) {   
                    high = mid - 1; // search in lefthalf
                } else {
                    low = mid + 1;  // search in righthalf
                }
            } 
            else {  // right half is sorted:
                if(target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;  // search in righthalf
                } else {
                    high = mid - 1; // search in lefthalf
                }
            }
        }

        return false;   // not present
    }
};
