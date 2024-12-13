/*

//  2593. Find Score of an Array After Marking All Elements

//  Problem Statement:
    * You are given an array nums consisting of positive integers.
    * Starting with score = 0, apply the following algorithm:
        * Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
        * Add the value of the chosen integer to score.
        * Mark the chosen element and its two adjacent elements if they exist.
        * Repeat until all the array elements are marked.
    * Return the score you get after applying the above algorithm.

// Example:

    Example 1:
        Input: nums = [2,1,3,4,5,2]
        Output: 7
        Explanation: We mark the elements as follows:
        - 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
        - 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
        - 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
        Our score is 1 + 2 + 4 = 7.

    Example 2:
        Input: nums = [2,3,5,1,3,2]
        Output: 5
        Explanation: We mark the elements as follows:
        - 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
        - 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
        - 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
        Our score is 1 + 2 + 2 = 5.



// Approach:
    // BruteForce Approach:
        -> find smallest element everytime & mark them & their adjacent element as marked.
        -> Mark these element with specific value -> INT_MAX
        -> So that we can ignore them..


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// BruteForce Solution:
class Solution_Brute{
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for(int i=0;i<nums.size();i++){
            // find the minimum element:
            int minVal = INT_MAX;
            int idx = -1;
            for(int j=0;j<nums.size();j++){
                if(nums[j] < minVal){
                    minVal = nums[j];
                    idx = j;
                }
            }

            // Update that element & their adjacent once:
            if(minVal != INT_MAX){
                ans += nums[idx];
                nums[idx] = INT_MAX;
                if(idx > 0){
                    nums[idx-1] = INT_MAX;
                }
                if(idx < n-1){
                    nums[idx+1] = INT_MAX;
                }
            }else{
                break;
            }
        }

        return ans;
    }
};