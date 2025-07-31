/*

//  1679. Max Number of K-Sum Pairs


//  Problem Statement: 
    -> You are given an integer array nums and an integer k.
    -> In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.
    -> Return the maximum number of operations you can perform on the array.

 
// Example:
    Example 1:
        Input: nums = [1,2,3,4], k = 5
        Output: 2
        Explanation: Starting with nums = [1,2,3,4]:
        - Remove numbers 1 and 4, then nums = [2,3]
        - Remove numbers 2 and 3, then nums = []
        There are no more pairs that sum up to 5, hence a total of 2 operations.

    Example 2:
        Input: nums = [3,1,3,4,3], k = 6
        Output: 1
        Explanation: Starting with nums = [3,1,3,4,3]:
        - Remove the first two 3's, then nums = [1,4,3]
        There are no more pairs that sum up to 6, hence a total of 1 operation.

// Observations: 
    -> In one operations we can select any two number whose sum equal to 'k' & remove that pairs.
    -> We need to return total number of operations we can perfrom in given array.


    // Sorting Two pointers Approach:
        -> Sort the given nums
        -> Use two pointers approach & move according to needs and count the number of operations.

        // Complexity: 
            -> TC: O(n * logn)
            -> SC: O(1)


    // Hashsign Approach: 
        -> Use two-sum logic
        -> hash values inside the map & fetch the needed value by subtracting it form given 'k'

        // Complexity: 
            -> TC: O(n)
            -> SC: O(n)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient HashMap Approach: 
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        int ans = 0;
        for(auto& it: nums) {
            int need = k - it;

            // If needed value is present inside the map:
            if(mp[need] > 0) {
                mp[need]--;     // lower the frequency
                ans++;          // calculate in answer
            } else {
                mp[it]++;       // else hash that value
            }
        }

        return ans;
    }
};

// Sorting Two pointer approach:
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));   // sort the given list

        int i = 0;
        int j = n - 1;
        int ans = 0;

        while(i < j) {
            int sum = nums[i] + nums[j];

            if(sum == k) {
                ans++;
                i++;
                j--;
            } else if(sum > k) {
                j--;    // move right pointer to smaller the value
            } else {
                i++;    // moving left pointer towards right to find grater number
            }
        }

        return ans;
    }
};