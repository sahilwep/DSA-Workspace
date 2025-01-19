/*

//  2401. Longest Nice Subarray


//  Problem Statement: 
    -> You are given an array nums consisting of positive integers.
    -> We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.
    -> Return the length of the longest nice subarray.
    -> A subarray is a contiguous part of an array.
    -> Note that subarrays of length 1 are always considered nice.

// Example: 

    Example 1:

        Input: nums = [1,3,8,48,10]
        Output: 3
        Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
        - 3 AND 8 = 0.
        - 3 AND 48 = 0.
        - 8 AND 48 = 0.
        It can be proven that no longer nice subarray can be obtained, so we return 3.

    Example 2:

        Input: nums = [3,1,5,11,13]
        Output: 1
        Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.




// Observation: 

        Input: nums = [1,3,8,48,10]
        Output: 3
        Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
        - 3 AND 8 = 0.
        - 3 AND 48 = 0.
        - 8 AND 48 = 0.
        It can be proven that no longer nice subarray can be obtained, so we return 3.

        // Binary Rep:

            1  = 000001
            3  = 000011
            8  = 001000
            48 = 110000
            10 = 001010

        -> We need to keep track of bits that are set.
        -> We can use OR to masking the bits, or will store the set bits.


        -> For adding the bits -> take OR
        -> For removing the same bits -> Take XOR: 


// Complexity: 
    -> TC: O(n)
    -> AS: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int longest = 0;
        int left = 0;
        int right = 0;
        int currBits = 0;

        while(right < n){

            while((currBits & nums[right]) != 0){
                // If overlap exist, remove the leftmost element from the window
                currBits ^= nums[left];
                left++;
            }

            // update the OR for the current number
            currBits |= nums[right];

            // Calculate the maximum length of the subarray:
            longest = max(longest, right - left + 1);

            right++;
        }

        return longest;
    }
};