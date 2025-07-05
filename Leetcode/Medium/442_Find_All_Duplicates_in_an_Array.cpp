/*

//  442. Find All Duplicates in an Array


//  Problem Statement: 
    -> Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.
    -> You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

 
// Example: 
    Example 1:
        Input: nums = [4,3,2,7,8,2,3,1]
        Output: [2,3]

    Example 2:
        Input: nums = [1,1,2]
        Output: [1]

    Example 3:
        Input: nums = [1]
        Output: []



// Observations: 
    -> Given integer nums, return the duplicate element from an array...


// BruteForce: 
    -> sort the given values.
    -> store the adjacent duplicate element into ans & return.

    // Complexity: 
        -> TC: O(n * log(n))
        -> AS: O(1)


// Efficient solution
    -> Hash the given value int map.
    -> store the values having freq > 1
    
    // Complexity: 
        -> TC: O(N)
        -> AS: O(N)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BruteForce Solution: 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));   // Sort the given array.

        
        vector<int> ans;
        for(int i = 1; i < n; i++) {
            if(nums[i-1] == nums[i]) ans.push_back(nums[i]);
        }

        return ans;
    }
};


// Efficient Solution: 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        // Hash the given array into map.
        unordered_map<int, int> mp;
        for(auto& it: nums) {
            mp[it]++;
        }

        // Build Answer:
        vector<int> ans;
        for(auto& [key, val]: mp) {
            // Fetch the value having freq > 1
            if(val > 1) ans.push_back(key);
        }

        return ans;
    }
};