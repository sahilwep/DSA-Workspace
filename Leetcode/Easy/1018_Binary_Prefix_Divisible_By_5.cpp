/*

//  1018. Binary Prefix Divisible By 5


//  Problem Statement: 
    - You are given a binary array nums (0-indexed).
    - We define xi as the number whose binary representation is the subarray nums[0..i] (from most-significant-bit to least-significant-bit).
        - For example, if nums = [1,0,1], then x0 = 1, x1 = 2, and x2 = 5.
    - Return an array of booleans answer where answer[i] is true if xi is divisible by 5.

 
// Example: 
    Example 1:
        Input: nums = [0,1,1]
        Output: [true,false,false]
        Explanation: The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.
        Only the first number is divisible by 5, so answer[0] is true.

    Example 2:
        Input: nums = [1,1,1]
        Output: [false,false,false]


// Observations: 
    - we are given nums, where nums[i] is the ith bits which need to divisible by 5, if it's then return true for nums[i] : false..

    // Bruteforce Approach:
        - iterate from 0 to n -1
        - while iterating get the remaining left side values & convert & check if they are divisible by 5.
        - Build answer accordingly..

        - integer overflow for larger input.
    
    // Efficient approach: 
        - we are observing bits from left to right.
        - as we move whenever we have set bits occur, we multiply the value by 2 & add bits value, and we keep going & at last we will get our value..
        - as we moving forward we only need to check wether it's divisible by 5 or not??

        // Solution:
            - we maintain curr that will always represent the current prefix value modulo 5
            - for each bit num in nums:
                - update the current value as if extending the binary number.
                - curr = curr * 2 + num
                - replace it with modulo 5, because product will have larger value...
            if( curr == 0) -> divisible by 5 : else not
        

        num = 3 (11) => cur = 3 =>false;

        num * 2 = 6 (110) => cur = (3 * 2) % 5 = 1 ~ (6 % 5 = 1) => false;

        num * 2 = 12 (1100) => cur = (1 * 2) % 5 = 2 ~ (12 % 5 = 2) => false;
        
        num * 2 + 1 = 25 (11001) => cur = (2 * 2 + 1) % 5 = 0 ~ (25 % 5 = 0) => true;

        // Complexity: 
            - TC: O(n)
            - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool> ans(n, 0);
        int curr = 0;
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            curr = curr * 2 + num;
            curr %= 5;

            ans[i] = (curr == 0) ? 1 : 0;
        }

        return ans;
    }
};