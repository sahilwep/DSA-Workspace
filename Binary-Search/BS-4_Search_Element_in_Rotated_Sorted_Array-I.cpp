/*

//  BS-4. Search Element in Rotated Sorted Array - I

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
    -> First identify the sorted half
        -> is it the lefthalf or the righthalf
    -> Then check the target lies with the range low---mid || high---mid

            [4  5  6  7  0  1  2]       x = 1
             |        |         |
             low     mid       high


// Complexity: 
    -> TC: O(logN)
    -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();

        int low = 0;
        int high = n - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(arr[mid] == target) return mid;

            // Check Sorted range: 
            if(arr[low] <= arr[mid]) {  // left half is sorted:
                if(arr[low] <= target && target < arr[mid]) {
                    high = mid - 1; // search in left space
                } else {
                    low = mid + 1;  // search in right space
                }
            } 
            else {  // right half is sorted:
                if(arr[mid] < target &&  target <= arr[high]) {
                    low = mid + 1;  // search in right space
                } else {
                    high = mid - 1; // search in left space
                }
            }
        }

        return -1;  // not found
    }
};