/*

//  3105. Longest Strictly Increasing or Strictly Decreasing Subarray


//  Problem Statement: 
    -> You are given an array of integers nums. Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing.

 
// Exapmle:

    Example 1:
        Input: nums = [1,4,3,3,2]
        Output: 2
        Explanation:
            The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].
            The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].
            Hence, we return 2.


    Example 2:
        Input: nums = [3,3,3,3]
        Output: 1
        Explanation:
            The strictly increasing subarrays of nums are [3], [3], [3], and [3].
            The strictly decreasing subarrays of nums are [3], [3], [3], and [3].
            Hence, we return 1.

    Example 3:
        Input: nums = [3,2,1]
        Output: 3
        Explanation:
            The strictly increasing subarrays of nums are [3], [2], and [1].
            The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].
            Hence, we return 3.



// Complexity: 
    -> TC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 1;
        int currLen = 1;
        bool increasing = false, decreasing = false;

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {    // increasing
                if(!increasing) {
                    currLen = 2;
                    increasing = true;
                    decreasing = false;
                }
                else {
                    currLen++;
                }
            }
            else if(nums[i] < nums[i-1]) {  // decreasing
                if(!decreasing) {
                    currLen = 2;
                    increasing = false;
                    decreasing = true;
                }
                else {
                    currLen++;
                }
            }
            else {  // equal:
                increasing = decreasing = false;
                currLen = 1;
            }

            maxLen = max(maxLen, currLen);  // get the maximum at last
        }

        return maxLen;
    }
};

