/*

//  34. Find First and Last Position of Element in Sorted Array


//  Problem Statement: 
    -> Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
    -> If target is not found in the array, return [-1, -1].
    -> You must write an algorithm with O(log n) runtime complexity.


// Example: 

    Example 1:
        Input: nums = [5,7,7,8,8,10], target = 8
        Output: [3,4]

    Example 2:
        Input: nums = [5,7,7,8,8,10], target = 6
        Output: [-1,-1]

    Example 3:
        Input: nums = [], target = 0
        Output: [-1,-1]


// Observations: 
    -> If we carefully observe the question, we have sorted array given & we have to find the first & last occurrences..
    -> We can write custom lower_bound & upper_bound to find this..


// Complexity:
    -> TC: O(logn)
    -> SC: O(logn)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Approach 2: Shorthand method:
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int lb = lower_bound(begin(nums), end(nums), target) - begin(nums);
        if(lb == n || nums[lb] != target) return {-1, -1};

        int ub = upper_bound(begin(nums), end(nums), target) - begin(nums);

        return {lb, ub - 1};
    }
};


// Approach 1: Manually writing lower & upper_bound by tweaking some logic...
class Solution {
private: 
    int lower(vector<int>& nums, int target, int n) {   // get the lower value
        int low = 0, high = n - 1;
        int ans = n;    // in worse case return last index, if not found

        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid] == target) ans = mid;  // store answer if we got

            if(nums[mid] >= target) {   // try moving left, and get the leftmost value even if we have equal case.
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
    int upper(vector<int>& nums, int target, int n) {   // get the upper value
        int low = 0, high = n - 1;
        int ans = n;    // in worse case return last index, if not found

        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid] == target) ans = mid;  // store answer if we got

            if(nums[mid] > target) {
                high = mid - 1;
            } else {    // try moving right and get the rightmost value if (arr[mid] <= target)
                low = mid + 1;
            }
        }

        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {    
        int n = nums.size();
        
        int lb = lower(nums, target, n);
        if(lb == n) return {-1, -1};
        int ub = upper(nums, target, n);

        return {lb, ub};
    }
};