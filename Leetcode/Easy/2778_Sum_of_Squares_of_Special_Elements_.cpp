/*

//  2778. Sum of Squares of Special Elements 

//  Problem Statement: 
    - You are given a 1-indexed integer array nums of length n.
    - An element nums[i] of nums is called special if i divides n, i.e. n % i == 0.
    - Return the sum of the squares of all special elements of nums.

 
// Example:
    Example 1:
        Input: nums = [1,2,3,4]
        Output: 21
        Explanation: There are exactly 3 special elements in nums: nums[1] since 1 divides 4, nums[2] since 2 divides 4, and nums[4] since 4 divides 4. 
        Hence, the sum of the squares of all special elements of nums is nums[1] * nums[1] + nums[2] * nums[2] + nums[4] * nums[4] = 1 * 1 + 2 * 2 + 4 * 4 = 21.  

    Example 2:
        Input: nums = [2,7,1,19,18,3]
        Output: 63
        Explanation: There are exactly 4 special elements in nums: nums[1] since 1 divides 6, nums[2] since 2 divides 6, nums[3] since 3 divides 6, and nums[6] since 6 divides 6. 
        Hence, the sum of the squares of all special elements of nums is nums[1] * nums[1] + nums[2] * nums[2] + nums[3] * nums[3] + nums[6] * nums[6] = 2 * 2 + 7 * 7 + 1 * 1 + 3 * 3 = 63. 

//  Observations:
    - Given n size array 1-based
    - if (n % i == 0) then calculate the square of the current nums[i]
    - and at last accumulate all the square that we have calculated.
    - Implement the given statement.
    
    // Complexity:
        - TC: O(n)
        - SC: O(1)




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();

        int i = 1;
        int sum = 0;
        for(auto &num: nums) {
            if(n % i == 0) sum += num * num;
            i++;
        }

        return sum;
    }
};