/*

//  BS-7. Find out how many times array has been rotated



//  Problem Statement: 
    -> Given an increasing sorted rotated array arr of distinct integers. The array is right-rotated k times. Find the value of k.
    -> Let's suppose we have an array arr = [2, 4, 6, 9], so if we rotate it by 2 times so that it will look like this:
    -> After 1st Rotation : [9, 2, 4, 6]
    -> After 2nd Rotation : [6, 9, 2, 4]


// Examples:

    Input: arr = [5, 1, 2, 3, 4]
    Output: 1
    Explanation: The given array is 5 1 2 3 4. The original sorted array is 1 2 3 4 5. We can see that the array was rotated 1 times to the right.

    Input: arr = [1, 2, 3, 4, 5]
    Output: 0
    Explanation: The given array is not rotated.


// Observations: 
    -> Since we can find the minimum value from an array using binary search in O(logN)
    -> This will help us to find the rotations
    -> Rotations is clockwise -> Last element moved to first
    // Example: 
        arr = [2, 4, 6, 9]
            1st rotations: [9, 2, 4, 6]
            2nd rotations: [6, 9, 2, 4]
            3rd rotations: [4, 6, 9, 2]
                                     |
                                     minElement at index 3
            
            minElement = 2 at index 3
            So rotations is also '3'

// Complexity: 
    -> TC: O(logN)
    -> SC: O(1)


*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        
        int n = nums.size();

        int low = 0;
        int high = n-1;
        int target = INT_MAX;   // initially target as first element  || INT_MAX
        int idx = -1;           // Store the index.

        while(low <= high) {
            int mid = (low + high) / 2;

            // Optimization: if array is already sorted: 
            if(nums[low] <= nums[high]) {
                if(nums[low] < target) {
                    target = nums[low];
                    idx = low;
                }
                break;  // no need to search
            }
            
            // Check sorted half:
            if(nums[low] <= nums[mid]) {  // left half is sorted
                // get the minimum value from that search space:
                if(nums[low] < target) {
                    target = nums[low];
                    idx = low;
                }
        
                // Reject that search Space: 
                low = mid + 1;
            } 
            else {  // right half is sorted:
                // get the minimum value from that search space:
                if(nums[mid] < target) {
                    target = nums[mid];
                    idx = mid;
                }
                
                // Reject that search space:
                high = mid - 1;
            }
        }

        return idx;  // return index
        
    }
};
