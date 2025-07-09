/*

//  164. Maximum Gap | Sorting | Enumerations |


//  Problem Statement: 
    -> Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.
    -> You must write an algorithm that runs in linear time and uses linear extra space.

 
// Example: 
    Example 1:
        Input: nums = [3,6,9,1]
        Output: 3
        Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.

    Example 2:
        Input: nums = [10]
        Output: 0
        Explanation: The array contains less than 2 elements, therefore return 0.


// Observations: 
    -> For any two consecutive element, get the maximum difference..
    -> First sort the elements
    -> Get the maximum consecutive value


    // Complexity: 
        -> TC: O(n * logn)
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return 0;

        sort(begin(nums), end(nums));

        int maxDiff = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] >= nums[i-1]) {
                maxDiff = max(maxDiff, nums[i] - nums[i-1]);
            }
        }

        return maxDiff;
    }
};