/*

//  3903. Smallest Stable Index I


//  Problem Statement: 
    - You are given an integer array nums of length n and an integer k.
    - For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).
    - In other words:
        - max(nums[0..i]) is the largest value among the elements from index 0 to index i.
        - min(nums[i..n - 1]) is the smallest value among the elements from index i to index n - 1.
    - An index i is called stable if its instability score is less than or equal to k.
    - Return the smallest stable index. If no such index exists, return -1.

 
// Example:
    Example 1:
        Input: nums = [5,0,1,4], k = 3
        Output: 3
        Explanation:
            At index 0: The maximum in [5] is 5, and the minimum in [5, 0, 1, 4] is 0, so the instability score is 5 - 0 = 5.
            At index 1: The maximum in [5, 0] is 5, and the minimum in [0, 1, 4] is 0, so the instability score is 5 - 0 = 5.
            At index 2: The maximum in [5, 0, 1] is 5, and the minimum in [1, 4] is 1, so the instability score is 5 - 1 = 4.
            At index 3: The maximum in [5, 0, 1, 4] is 5, and the minimum in [4] is 4, so the instability score is 5 - 4 = 1.
            This is the first index with an instability score less than or equal to k = 3. Thus, the answer is 3.

    Example 2:
        Input: nums = [3,2,1], k = 1
        Output: -1
        Explanation:
            At index 0, the instability score is 3 - 1 = 2.
            At index 1, the instability score is 3 - 1 = 2.
            At index 2, the instability score is 3 - 1 = 2.
            None of these values is less than or equal to k = 1, so the answer is -1.

    Example 3:
        Input: nums = [0], k = 0
        Output: 0
        Explanation: At index 0, the instability score is 0 - 0 = 0, which is less than or equal to k = 0. Therefore, the answer is 0.


// Observations:
    - given nums and integer k
    - we have to return the index i for which:
        - max(num[0...i]) - min(nums[i...n-1]) <= k
    - We will have to implement the given statement.


    // Complexity:
        - TC: O(n^2)
        - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        int maxEl = nums[0];
        for(int i = 0; i < n; i++) {
            maxEl = max(maxEl, nums[i]);    // max(nums[0...i])
            // Find the minEl from i to n - 1:
            int minEl = nums[i];
            for(int j = i; j < n; j++) {    // min(nums[i...n-1])
                minEl = min(minEl, nums[j]);
            }

            // Get the answer:
            if(maxEl - minEl <= k) return i;
        }



        return -1;
    }
};