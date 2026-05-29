/*

//  3300. Minimum Element After Replacement With Digit Sum


//  Problem Statement: 
    - You are given an integer array nums.
    - You replace each element in nums with the sum of its digits.
    - Return the minimum element in nums after all replacements.

//  Example:

        Example 1:
            Input: nums = [10,12,13,14]
            Output: 1
            Explanation: nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.

        Example 2:
            Input: nums = [1,2,3,4]
            Output: 1
            Explanation: nums becomes [1, 2, 3, 4] after all replacements, with minimum element 1.

        Example 3:
            Input: nums = [999,19,199]
            Output: 10
            Explanation: nums becomes [27, 10, 19] after all replacements, with minimum element 10.

 
// Observations:
    - We need to calculate the digit sum of every element, and return the minimum among them.
    
    // Complexity:
        - TC: O(n)
        - SC: O(1)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class Solution {
    int digitSum(int n) {
        int ans = 0;

        while(n > 0) {
            ans += n % 10;
            n /= 10;
        }

        return ans;
    }
public:
    int minElement(vector<int>& nums) {
        int ans = digitSum(nums[0]);

        for(auto &num: nums) {
            ans = min(ans, digitSum(num));
        }

        return ans;
    }
};