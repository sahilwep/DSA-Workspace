/*

//  594. Longest Harmonious Subsequence


//  Problem Statement: 
    -> We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
    -> Given an integer array nums, return the length of its longest harmonious
    -> among all its possible subsequences.


// Example: 
    Example 1:
        Input: nums = [1,3,2,2,5,2,3,7]
        Output: 5
        Explanation: The longest harmonious subsequence is [3,2,2,2,3].

    Example 2:
        Input: nums = [1,2,3,4]
        Output: 2
        Explanation: The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which have a length of 2.

    Example 3:
        Input: nums = [1,1,1,1]
        Output: 0
        Explanation: No harmonic subsequence exists.



// Observations: 
    -> Sorting will groups same value together..
    -> Using two pointer we will move our pointers & compare if given conditions being followed or not?
        -> If given conditions is followed, store maximum size.


// Complexity: 
    -> TC: O(N * Log(N))
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));

        int i = 0, j = 0;
        int size = 0;
        while(j < n) {
            // check if, given conditions satisfies or not, if not move ith pointer..
            while(nums[j] - nums[i] > 1) {
                i++;    // move ith pointer..
            }

            // Store answer: 
            if(nums[j] - nums[i] == 1) {
                size = max(size, j - i + 1);
            }

            j++;    // move jth pointer..
        }

        return size;
    }
};