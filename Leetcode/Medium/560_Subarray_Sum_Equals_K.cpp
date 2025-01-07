/*

//  560. Subarray Sum Equals K

//  Problem Statement:
    -> Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
    -> A subarray is a contiguous non-empty sequence of elements within an array.

// Example:

    Example 1:
        Input: nums = [1,1,1], k = 2
        Output: 2

    Example 2:
        Input: nums = [1,2,3], k = 3
        Output: 2


// Complexity: 
    -> O(n)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        // Initialize with sum = 0 occurring once to handel case when a subarray itself equal to 'k'
        mp[0] = 1;

        int cnt = 0;
        int prefSum = 0;
        for(int i=0;i<n;i++){
            // Calculate PrefSum:
            prefSum += nums[i];

            // Check (PrefSum - k) is in map or not?
            int checkVal = prefSum - k;
            if(mp.find(checkVal) != mp.end()){
                cnt += mp[checkVal];    // count that subset
            }

            mp[prefSum]++;  // at end insert prefix sun in map
        }

        return cnt;
    }
};