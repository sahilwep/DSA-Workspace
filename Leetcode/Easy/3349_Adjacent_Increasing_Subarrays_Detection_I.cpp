/*

//  3349. Adjacent Increasing Subarrays Detection I


//  Problem Statement: 
    -> Given an array nums of n integers and an integer k, determine whether there exist two adjacent
    -> of length k such that both subarrays are strictly increasing. Specifically, check if there are two subarrays starting at indices a and b (a < b), where:
        -> Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
        -> The subarrays must be adjacent, meaning b = a + k.
    -> Return true if it is possible to find two such subarrays, and false otherwise.

 
// Example: 
    Example 1:
        Input: nums = [2,5,7,8,9,2,3,4,3,1], k = 3
        Output: true
        Explanation:
            The subarray starting at index 2 is [7, 8, 9], which is strictly increasing.
            The subarray starting at index 5 is [2, 3, 4], which is also strictly increasing.
            These two subarrays are adjacent, so the result is true.

    Example 2:
        Input: nums = [1,2,3,4,4,4,4,5,6,7], k = 5
        Output: false


// Observations:
    -> nums of size n, given k, determine there exist two adjacent subarray of length 'k' 
    -> both subarray are strictly increasing, & they should be adjacent

    // Approach: 
        -> Maintain two variable prev & curr, which will hold the length of increasing sequence..
        -> In single pass we can compute the prev & current length.
        -> Whenever we have (nums[i-1] < nums[i]) => increment curr
        -> else: => set prev = curr, & curr = 1 & move forward
        -> Check if (prev >= k && curr >= k) OR (curr >= 2 * k) --> return true;
        -> else return false;

// Complexity:  
    -> TC: O(N)
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int prev = 0;
        int curr = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i - 1] < nums[i]) {
                curr += 1;
            } else {
                prev = curr;
                curr = 1;
            }
            
            // if both subarray is greater than 'k' OR we found a subarray which is twice of given 'k'
            if(curr >= k && prev >= k || curr >= (k * 2)) {
                return true;
            }
        }

        return false;
    }
};