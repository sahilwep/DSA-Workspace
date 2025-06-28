/*

//  2099. Find Subsequence of Length K With the Largest Sum


//  Problem Statement: 
    -> You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.
    -> Return any such subsequence as an integer array of length k.
    -> A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 
// Example: 

    Example 1:
        Input: nums = [2,1,3,3], k = 2
        Output: [3,3]
        Explanation:
        The subsequence has the largest sum of 3 + 3 = 6.

    Example 2:
        Input: nums = [-1,-2,3,4], k = 3
        Output: [-1,3,4]
        Explanation: 
        The subsequence has the largest sum of -1 + 3 + 4 = 6.

    Example 3:
        Input: nums = [3,4,3,3], k = 2
        Output: [3,4]
        Explanation:
        The subsequence has the largest sum of 3 + 4 = 7. 
        Another possible subsequence is [4, 3].

    
// Observations: 
    -> We need to select 'k' element, that are greater among all the remaining elements.
    -> Sort in reverse order will give us top greater elements
    -> select 'k' element from there
    -> Build answer as given in nums order...


    // Complexity: 
        -> TC: O(N * log N), mostly contribute as sorting..
        -> SC: O(N), for unordered map.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BruteForce: 
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        if(k == nums.size()) return nums;   // if k is same as given nums size, return nums

        vector<int> temp = nums;    // create a copy of given nums

        // Sort & get the first 'k' elements as our valid candidate:
        sort(rbegin(temp), rend(temp));
        unordered_map<int, int> mp;
        int i = 0;
        while(k--) {
            mp[temp[i++]]++;
        }

        // Build answer in correct order from original nums: 
        vector<int> ans;
        for(auto &num: nums) {
            if(mp.count(num)) {
                cout << num << " ";
                mp[num]--;
                if(mp[num] == 0) mp.erase(num);
                ans.push_back(num);
            }
        }

        return ans;
    }
};