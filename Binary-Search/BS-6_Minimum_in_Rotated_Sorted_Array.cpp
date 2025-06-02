/*

//  BS-6. Minimum in Rotated Sorted Array

//  Problem Statement: 
    -> Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
        -> [4,5,6,7,0,1,2] if it was rotated 4 times.
        -> [0,1,2,4,5,6,7] if it was rotated 7 times.
    -> Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
    -> Given the sorted rotated array nums of unique elements, return the minimum element of this array.
    -> You must write an algorithm that runs in O(log n) time.

 
// Example: 

    Example 1:
        Input: nums = [3,4,5,1,2]
        Output: 1
        Explanation: The original array was [1,2,3,4,5] rotated 3 times.

    Example 2:
        Input: nums = [4,5,6,7,0,1,2]
        Output: 0
        Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

    Example 3:
        Input: nums = [11,13,15,17]
        Output: 11
        Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 



// Observations: 
    -> We are given sorted rotated array, but we are unaware about the target value, which is our minimum value
    -> Example: 

        4   5   6   7   0   1   2
        |           |           |
        low        mid         high



    // Approach 1: 
        -> Set target as minimum among all the pointers & then look for the comparision..
        -> As array is given, first check the sorted range & then look for answer as we were doing in rotated arrays..



    // Approach 2: 
        -> For any sorted half: 
            -> We are sure that minimum value is found on the starting point of that particular searchSpace.
            -> We can set that minimum as our answer & reject that search space & look for another search space.



    // Optimization: 
        -> If given array is already sorted, say if(arr[low] <= arr[high]) => compare "arr[low]" with previous finding & return the minimum among them.



// Complexity: 
    -> TC: O(logN)
    -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Approach 2:
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int high = n-1;
        int target = nums[0];   // initially target as first element  || INT_MAX

        while(low <= high) {
            int mid = (low + high) / 2;

            // Optimization: if array is already sorted: 
            if(nums[low] <= nums[high]) {
                target = min(target, nums[low]);
                break;  // no need to search
            }
            
            // Check sorted half:
            if(nums[low] <= nums[mid]) {  // left half is sorted
                target = min(target, nums[low]);    // get the minimum value from that search space:
                // Reject that search Space: 
                low = mid + 1;
            } 
            else {  // right half is sorted:
                target = min(target, nums[mid]);    // get the minimum value from that search space:
                // Reject that search space:
                high = mid - 1;
            }
        }

        return target;  // return target value
    }
};


// Approach 1: 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int high = n-1;
        int target = nums[0];   // initially target as first element of an array.

        while(low <= high) {
            int mid = (low + high) / 2;

            // Get target as minimum value among all the three pointer (low, mid, high) & previous findings..
            target = min(target, min(nums[low], min(nums[mid], nums[high])));
            
            // Check sorted half:
            if(nums[low] <= nums[mid]) {  // left half is sorted
                if(target >= nums[low] && target < nums[mid]) { // if target lies within left half
                    high = mid - 1;
                } else {
                    low = mid + 1;  // else search in right half
                }
            } 
            else {  // right half is sorted:
                if(target > nums[mid] && target <= nums[high]) {    // if target lies within right half
                    low = mid + 1;
                } else {
                    high = mid - 1; // else search in left half
                }
            }
        }

        return target;  // return target value
    }
};