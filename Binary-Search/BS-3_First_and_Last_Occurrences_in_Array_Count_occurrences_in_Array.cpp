/*

//   BS-3. First and Last Occurrences in Array | Count occurrences in Array 


// First and Last Occurrences in Array  ------------------------------------------------------------------

//  Problem link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
//  Problem Statement: 
    -> Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
    -> If target is not found in the array, return [-1, -1].
    -> You must write an algorithm with O(log n) runtime complexity.


// Example: 
    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]

    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]

    Input: nums = [], target = 0
    Output: [-1,-1]

// Observations: 
    -> If we observe carefully, we will have to return the first & the last occurrence of the value if it's there.
    -> first occurrence we can return with lower_bound
    -> last occurrence we can return with (upper_bound - 1)

// Complexity:  
    -> TC: O(logn)
    -> SC: O(1)

    



// Count occurrences in Array -------------------------------------------------------------------------------

//  Problem Link: https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
//  Problem Statement: 
    -> Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

// Examples:
    Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
    Output: 4
    Explanation: target = 2 occurs 4 times in the given array so the output is 4.

    Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
    Output: 0
    Explanation: target = 4 is not present in the given array so the output is 0.

    Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
    Output: 3
    Explanation: target = 12 occurs 3 times in the given array so the output is 3.

// Observations: 
    -> Same as above, we will just have to count the frequency.
    -> We can simply do the index difference & find out the frequency.

// Complexity:  
    -> TC: O(logn)
    -> SC: O(1)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// First and Last Occurrences in Array -------------------------------------------------
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


// Count occurrences in Array  -------------------------------------------------
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        
        int n = arr.size();
        
        int lb = lower_bound(begin(arr), end(arr), target) - begin(arr);    // get the first occurrence index
        if(lb == n) return 0;
        
        int ub = upper_bound(begin(arr), end(arr), target) - begin(arr) - 1;    // get the last occurrence index
        
        
        return ub - lb + 1;
    }
};
