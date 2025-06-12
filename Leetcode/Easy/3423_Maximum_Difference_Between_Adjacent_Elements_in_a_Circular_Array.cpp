/*

//  3423. Maximum Difference Between Adjacent Elements in a Circular Array

//  Problem Statement: 
    -> Given a circular array nums, find the maximum absolute difference between adjacent elements.
    -> Note: In a circular array, the first and last elements are adjacent.
 
// Example:
    Example 1:
        Input: nums = [1,2,4]
        Output: 3
        Explanation: Because nums is circular, nums[0] and nums[2] are adjacent. They have the maximum absolute difference of |4 - 1| = 3.

    Example 2:
        Input: nums = [-5,-10,-5]
        Output: 5
        Explanation: The adjacent elements nums[0] and nums[1] have the maximum absolute difference of |-5 - (-10)| = 5.

//  Observations: 
    -> For circular array round the index with given nums range & find the maxDiff.


// Complexity: 
    -> TC: O(n)
    -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;
        for(int i = 0; i < 2*n; i++) {
            int curr = nums[i % n];
            int next = nums[(i + 1) % n];
            ans = max(ans, abs(curr - next));
        }

        return ans;
    }
};