/*

//  2176. Count Equal and Divisible Pairs in an Array

//  Problem Statement: 
    -> Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) 
    -> where 0 <= i < j < n, such that nums[i] == nums[j] and (i * j) is divisible by k.

// Example: 

    Example 1:
        Input: nums = [3,1,2,2,2,1,3], k = 2
        Output: 4
        Explanation:
        There are 4 pairs that meet all the requirements:
        - nums[0] == nums[6], and 0 * 6 == 0, which is divisible by 2.
        - nums[2] == nums[3], and 2 * 3 == 6, which is divisible by 2.
        - nums[2] == nums[4], and 2 * 4 == 8, which is divisible by 2.
        - nums[3] == nums[4], and 3 * 4 == 12, which is divisible by 2.

    Example 2:
        Input: nums = [1,2,3,4], k = 1
        Output: 0
        Explanation: Since no value in nums is repeated, there are no pairs (i,j) that meet all the requirements.

// BruteForce Solution: 
    -> Implement the given statements.
    -> TC: O(n^2)
    -> SC: O(1)

// Efficient Solution: 
    -> Using map, we can store the valid same value indexes & then later-on we can compare the count of valid pairs.
    -> TC: O(n), in Avg case
        -> Still O(n^2) in worse case if all the values are same.
    -> SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution:
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp; // store {nums[i], <indices>}
        int pairs = 0;

        for(int i = 0; i < n; i++) {
            if(mp.count(nums[i])) {  // found
                for(auto &j: mp[nums[i]]) { // count the valid pairs of indices
                    if(!((i * j) % k)) pairs++;
                }
            }
            // Last store the nums
            mp[nums[i]].push_back(i);  // store the indices
        }

        return pairs;
    }
};


// BruteForce Solution:
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int n = nums.size();

        int pairs = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) if(nums[i] == nums[j] && !((i * j) % k))  pairs++;
        }

        return pairs;
    }
};