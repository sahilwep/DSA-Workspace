/*

//  35. Search Insert Position

// Problem Statement: 
    -> Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
    -> You must write an algorithm with O(log n) runtime complexity.
    
// Example: 
    Example 1:
        Input: nums = [1,3,5,6], target = 5
        Output: 2

    Example 2:
        Input: nums = [1,3,5,6], target = 2
        Output: 1

    Example 3:
        Input: nums = [1,3,5,6], target = 7
        Output: 4


//  Observations: 
    -> Given sorted array
    -> if there's target value return the index
    -> If not return the index where it would be insert in order. 
    -> Lower bound will help to achieve that with complexity O(logn)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Approach 1: 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        
        int ans = n;
        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(nums[mid] >= target)  {   // we found it, but we need to lower value, so we trim down the search space and we look towards left side.
                ans = mid;
                high = mid - 1;
            } 
            else {  // value is smaller, not found, so we look on the right side
                low = mid + 1;
            }
        }

        return ans;
    }
};

// Approach 2: 
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};