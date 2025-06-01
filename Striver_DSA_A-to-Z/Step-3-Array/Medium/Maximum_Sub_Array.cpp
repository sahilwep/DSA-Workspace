/*

//  Maximum Sub Array

// Problem Link: https://www.geeksforgeeks.org/problems/maximum-sub-array5443/1

//  Problem Statement: 
    -> Given an array of integers arr[], find the contiguous subarray with the maximum sum that contains only non-negative numbers. 
    -> If multiple subarrays have the same sum, return the one with the smallest starting index. 
    -> If the array contains only negative numbers, return -1.
    -> Note: A subarray is a contiguous non-empty sequence of elements within an array.

// Examples:

    Input: arr[] = [1, 2, 3]
    Output: [1, 2, 3]
    Explanation: In the given array, every element is non-negative, so the entire array [1, 2, 3] is the valid subarray with the maximum sum.

    Input: arr[] = [-1, 2]
    Output: [2]
    Explanation: The only valid non-negative subarray is [2], so the output is [2].

    Input: arr[] = [1, 2, 5, -7, 2, 6]
    Output: [1, 2, 5]
    Explanation: The valid non-negative subarrays are [1, 2, 5] and [2, 6]. Both have the same sum of 8, but [1, 2, 5] starts earlier, so it is the preferred subarray.



// Observations: 
    -> Given array with positive & negative value
    -> return the subarray with maximum sum contains only non-negative number
    -> If multiple subarray have same sum, return the one with the smallest starting index, OR the first subarray that occur
    -> If subarray contains only negative number return -1


// Approach: 
    -> Observe the given statement & Build solution
    -> Using two pointers we can build solution.
    -> Skip the negative number, We only need positive number subarray
    -> Handel the equal case..

    // Complexity: 
        -> TC: O(N)
        -> SC: O(N)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
  public:
    vector<int> findSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 0;
        int sum = 0;
        int maxSoFar = 0;
        
        int start = 0, end = 0; // Store as Result
        
        bool isAllNeg = true;
        while(j < n) {
            // For negative number:
            if(nums[j] < 0) {
                // reset values: 
                maxSoFar = 0;
                i = j + 1;  // move i'th pointer
            } 
            // For positive number
            else {
                isAllNeg = false;
                maxSoFar += nums[j];
                
                // Check maximum:
                if(maxSoFar > sum) {    // for grater update new ranges
                    start = i;
                    end = j;
                    sum = maxSoFar;
                } 
                else if(maxSoFar == sum) {  // for equal case:
                    // we have to retain the smallest start index:
                    // Only update if it's a continuation (same start)
                    if(start == i) {
                        end = j;
                    }
                }
            }
            j++;    // move jth pointer
        }

        if(isAllNeg) return {-1}; // all negative
        
        vector<int> ans;
        for(int i = start; i <= end && i < n; i++) {
            ans.push_back(nums[i]);
        }
        
        return ans;
    }
};