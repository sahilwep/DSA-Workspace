/*

//  3097. Shortest Subarray With OR at Least K II


// Problem Statement:
    -> We are given an array nums of non-negative and and integer 'k'
    -> And array is called special if the bitwise 'OR' or all it's elements is atleast 'k'.
    -> atleast k means  ->   (elements >= k)
    -> Return the length of the shortest special non-empty 'subarray' of nums, or return -1, if there is no special subarray exist.


// Visualization: 
    * Given an array nums of non-negative integers and an integer k,
    * we need to find the length of the shortest non-empty subarray such that the bitwise OR of all its elements is at least k. 
    * If no such subarray exists, we should return -1.


    // Approach Explanation:
        * Bit Manipulation Fundamentals:
            * The bitwise OR operation combines bits from two binary numbers such that if either bit is 1, the result is 1.
            * Our goal is to find a subarray whose bitwise OR result is greater than or equal to k.
    
        * Sliding Window Technique:
            * We'll use a two-pointer approach (sliding window) to efficiently explore potential subarrays without recalculating the OR from scratch for each possible subarray.
            * The window expands by moving the right pointer and contracts by moving the left pointer to minimize the subarray size.
    
        * Bit Frequency Array:
            * We maintain a bitFreq array to keep track of the frequency of set bits (1s) at each bit position (from 0 to 31).
            * This helps in updating the OR value efficiently as elements enter or leave the window.
    
        * Functions Used:
            * updateFreq(): This function increments or decrements the count of set bits at each bit position as elements are added to or removed from the window.
            * getNumber(): This function reconstructs a number using the bit frequency array, simulating the current OR value of elements in the window.


// Complexity: 
    * TC: O(n)
    * AS: O(1)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    // This function updates the bit frequency of a given number in the bitFreq array.
    // It increments or decrements the count of set bits for each bit position based on the 'value' provided.
    void updateFreq(vector<int>& bitFreq, int number, int value) {
        for(int i = 0; i < 32; i++) {
            // Check if the i-th bit in 'number' is set (i.e., 1)
            if(number & (1 << i)) {
                // Update the bit frequency at index 'i' by adding 'value' (+1 to increment or -1 to decrement)
                bitFreq[i] += value;
            }
        }
    }

    // This function calculates a number from the bit frequency array.
    // It returns a number whose bits are set according to the bit frequencies > 0.
    int getNumber(vector<int>& bitFreq) {
        int num = 0;  // Initialize the resulting number to 0
        long long pow = 1; // Start with 2^0, i.e., 1

        // Iterate over each bit position
        for(int i = 0; i < 32; i++) {
            // If the frequency of this bit position is greater than 0, set the bit in 'num'
            if(bitFreq[i] > 0) {
                num += pow;
            }
            // Update the power of 2 for the next bit position (2^1, 2^2, ..., 2^31)
            pow *= 2;
        }

        return num; // Return the resulting number
    }

public:
    // This function finds the minimum length of a special subarray with bitwise OR >= k.
    int minimumSubarrayLength(vector<int>& nums, int k) {
        // Edge case: If k is 0, any single-element subarray is valid, so return 1
        if(k == 0) return 1;

        int n = nums.size(); // Size of the input array
        int shortest = INT_MAX; // Initialize the shortest subarray length to maximum possible value
        int left = 0, right = 0; // Two pointers for sliding window approach
        int currOR = 0; // Current bitwise OR of the window
        vector<int> bitFreq(32); // Bit frequency array to track bit counts for current window

        // Expand the window by moving the right pointer
        while(right < n) {
            // Add nums[right] to the current window and update bit frequencies
            updateFreq(bitFreq, nums[right], 1);
            currOR |= nums[right]; // Update the current OR value

            // Try to shrink the window from the left while maintaining the condition currOR >= k
            while(left <= right && currOR >= k) {
                // Update the minimum subarray length found
                shortest = min(shortest, (right - left + 1));

                // Remove nums[left] from the window and update bit frequencies
                updateFreq(bitFreq, nums[left], -1);
                // Recalculate the current OR value based on updated bit frequencies
                currOR = getNumber(bitFreq);

                // Move the left pointer to reduce the window size
                left++;
            }

            // Move the right pointer to expand the window
            right++;
        }

        // Return the result: -1 if no valid subarray is found, otherwise the shortest length
        return (shortest == INT_MAX) ? -1 : shortest;
    }
};
