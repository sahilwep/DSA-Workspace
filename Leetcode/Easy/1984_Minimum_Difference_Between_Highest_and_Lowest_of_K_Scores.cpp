/*

//  1984. Minimum Difference Between Highest and Lowest of K Scores


//  Problem Statement: 
    - You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.
    - Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.
    - Return the minimum possible difference.

 
// Example:

    Example 1:
        Input: nums = [90], k = 1
        Output: 0
        Explanation: There is one way to pick score(s) of one student:
        - [90]. The difference between the highest and lowest score is 90 - 90 = 0.
        The minimum possible difference is 0.

    Example 2:
        Input: nums = [9,4,1,7], k = 2
        Output: 2
        Explanation: There are six ways to pick score(s) of two students:
        - [9,4,1,7]. The difference between the highest and lowest score is 9 - 4 = 5.
        - [9,4,1,7]. The difference between the highest and lowest score is 9 - 1 = 8.
        - [9,4,1,7]. The difference between the highest and lowest score is 9 - 7 = 2.
        - [9,4,1,7]. The difference between the highest and lowest score is 4 - 1 = 3.
        - [9,4,1,7]. The difference between the highest and lowest score is 7 - 4 = 3.
        - [9,4,1,7]. The difference between the highest and lowest score is 7 - 1 = 6.
        The minimum possible difference is 2.


// Observations:
    - we have to select k elements from nums & take diff from maximum_num & minimum_sum
    - we have to return the minimum diff.

    // Approach:
        - After sorting we will have a window of k elements where we can take diff from last & first.
        - We will have to return the minimum among all the windows.

        // Complexity:
            - TC: O(n*logn)
            - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));
        int start = 0;
        int end = k - 1;

        int minDiff = INT_MAX;
        while(end < n) {
            int diff = nums[end] - nums[start];
            minDiff = min(minDiff, diff);

            start++;
            end++;
        }

        return minDiff;
    }
};