/*

//  Printing Maximum Subarray


//  Problem Statement: 
    -> Given an integer array nums, print the maximum sub subarray.

    
// Example: 
    Example 1:

        Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
        Output: 4 -1 2 1 
        Explanation: The subarray [4,-1,2,1] has the largest sum 6.

    Example 2:

        Input: nums = [1]
        Output: 1
        Explanation: The subarray [1] has the largest sum 1.

    Example 3:

        Input: nums = [5,4,-1,7,8]
        Output: 5,4,-1,7,8
        Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

// Observations: 
    -> Use Three pointer to find the starting & ending locations of subarray.
    -> Fist pointer is used to find the first starting range.
    -> Second pointer is being updated with first pointer value whenever we are incrementing the subarray sum
    -> Third pointer is being update whenever we find the new element that is contributing in subarray result.


    // Complexity: 
        -> TC: O(n)
        -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int ans = nums[0];
        int maxEnding = nums[0];
        int start = 0, end = 0, s = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] > maxEnding + nums[i]) {
                maxEnding = nums[i];
                s = i;
            } else {
                maxEnding += nums[i];
            }
            
            if(ans < maxEnding) {
                ans = maxEnding;
                start = s;
                end = i;
            }
        }

        for(int i = start; i <= end; i++) cout << nums[i] << " ";

        return ans;
    }
};