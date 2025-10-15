/*

//  3350. Adjacent Increasing Subarrays Detection II


//  Problem Statement: 
    -> Given an array nums of n integers, your task is to find the maximum value of k for which there exist two adjacent
    -> of length k each, such that both subarrays are strictly increasing. Specifically, check if there are two subarrays of length k starting at indices a and b (a < b), where:
        -> Both subarrays nums[a..a + k - 1] and nums[b..b + k - 1] are strictly increasing.
        -> The subarrays must be adjacent, meaning b = a + k.
    -> Return the maximum possible value of k.
    -> A subarray is a contiguous non-empty sequence of elements within an array.


// Example: 
    Example 1:
        Input: nums = [2,5,7,8,9,2,3,4,3,1]
        Output: 3
        Explanation:
            The subarray starting at index 2 is [7, 8, 9], which is strictly increasing.
            The subarray starting at index 5 is [2, 3, 4], which is also strictly increasing.
            These two subarrays are adjacent, and 3 is the maximum possible value of k for which two such adjacent strictly increasing subarrays exist.

    Example 2:
        Input: nums = [1,2,3,4,4,4,4,5,6,7]
        Output: 2
        Explanation:
            The subarray starting at index 0 is [1, 2], which is strictly increasing.
            The subarray starting at index 2 is [3, 4], which is also strictly increasing.
            These two subarrays are adjacent, and 2 is the maximum possible value of k for which two such adjacent strictly increasing subarrays exist.

 
// Observations: 
    - given nums of n integers.
    - find the maximum value of k for which there exist two adjacent subarray of length 'k' each.
    - both subarray are strictly increasing.
    

    // Approach:
        - we can find two increasing adjacent subarray of k size with simple single iterations.
        - we can use binary search to pass 'k' for maximum value.

    // Complexity: 
        -> TC: O(n * logn)
        -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    int n;
    bool solve(vector<int> &nums, int k) {

        int curr = 1;
        int prev = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i-1] < nums[i]) {
                curr++;
            } else {
                prev = curr;
                curr = 1;
            }

            if(curr >= k && prev >= k || curr >= (2 * k)) return true;
        }

        return false;
    }
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        n = nums.size();

        int start = 0;
        int end = n / 2;

        int ans = 0;
        while(start <= end) {
            int mid = (start + end) / 2;

            if(solve(nums, mid)) {
                start = mid + 1;
                ans = mid;
            } else {
                end = mid - 1;
            }
        }

        return ans;
    }
};