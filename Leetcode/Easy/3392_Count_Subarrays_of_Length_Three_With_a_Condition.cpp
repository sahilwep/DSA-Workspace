/*

//  3392. Count Subarrays of Length Three With a Condition


//  Problem Statement: 
    -> Given an integer array nums, return the number of
    -> of length 3 such that the sum of the first and third numbers equals exactly half of the second number.


// Example: 
    Example 1:
        Input: nums = [1,2,1,4,1]
        Output: 1
        Explanation: Only the subarray [1,4,1] contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.

    Example 2:
        Input: nums = [1,1,1]
        Output: 0
        Explanation: [1,1,1] is the only subarray of length 3. However, its first and third numbers do not add to half the middle number.

// Complexity: 
    -> TC: O(n)
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            // array size lesser than 3 => no subarray
            if(nums.size() <= 2) return 0;
            int n = nums.size();
    
            // First Calculate 3 size window:
            int subArray = 0;
            double sumFL = 0;
            double sumM = 0;
    
            // if(sumFL == (sumM / 2)) subArray++;
    
            for(int i = 2; i < n; i++) {
                sumFL = nums[i - 2] + nums[i];
                sumM = nums[i-1] / 2.00;
    
                if(sumFL == sumM) subArray++;
            }
    
            return subArray;
        }
    };