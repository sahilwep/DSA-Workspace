/*

//  704. Binary Search


//  Problem Statement: 
    -> Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
    -> You must write an algorithm with O(log n) runtime complexity.


// Example: 
    Example 1:
        Input: nums = [-1,0,3,5,9,12], target = 9
        Output: 4
        Explanation: 9 exists in nums and its index is 4

    Example 2:
        Input: nums = [-1,0,3,5,9,12], target = 2
        Output: -1
        Explanation: 2 does not exist in nums so return -1


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// STL: 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        return (idx != n && nums[idx] == target) ? idx : -1;
    }
};


// Recursive Solution:
class Solution {
private: 
    int solve(vector<int>& nums, int low, int high, int target) {
        // Base case: 
        if(low > high) return -1;   // element not found

        // Recursive Statements:
        int mid = low + (high - low) / 2;

        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) {
            return solve(nums, mid + 1, high, target);
        } else {
            return solve(nums, low, mid - 1, target);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
    
        return solve(nums, 0, n - 1, target);
    }
};

// Iterative Solution:
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) {
                low = mid + 1;  // move right
            } else {
                high = mid - 1;  // move left
            }
        }
        
        return -1;  // value not found
    }
};