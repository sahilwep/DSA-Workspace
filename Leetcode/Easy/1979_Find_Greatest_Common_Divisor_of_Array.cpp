/*

//  1979. Find Greatest Common Divisor of Array


//  Problem Statement: 
    - Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.
    - The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.


// Example:
    Example 1:
        Input: nums = [2,5,6,9,10]
        Output: 2
        Explanation:
        The smallest number in nums is 2.
        The largest number in nums is 10.
        The greatest common divisor of 2 and 10 is 2.

    Example 2:
        Input: nums = [7,5,6,8,3]
        Output: 1
        Explanation:
        The smallest number in nums is 3.
        The largest number in nums is 8.
        The greatest common divisor of 3 and 8 is 1.

    Example 3:
        Input: nums = [3,3]
        Output: 3
        Explanation:
        The smallest number in nums is 3.
        The largest number in nums is 3.
        The greatest common divisor of 3 and 3 is 3.

 
    // Approach:
        - Problem is straightforward asking gcd of smallest number, and largest number.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(*max_element(begin(nums), end(nums)), *min_element(begin(nums), end(nums)));
    }
};

