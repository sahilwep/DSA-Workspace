/*

//  2780. Minimum Index of a Valid Split



//  Problem Statement: 
    -> An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.
    -> You are given a 0-indexed integer array nums of length n with one dominant element.
    -> You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:
        -> 0 <= i < n - 1
        -> nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
    -> Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.
    -> Return the minimum index of a valid split. If no valid split exists, return -1.


// Example: 
    Example 1:
        Input: nums = [1,2,2,2]
        Output: 2
        Explanation: We can split the array at index 2 to obtain arrays [1,2,2] and [2]. 
        In array [1,2,2], element 2 is dominant since it occurs twice in the array and 2 * 2 > 3. 
        In array [2], element 2 is dominant since it occurs once in the array and 1 * 2 > 1.
        Both [1,2,2] and [2] have the same dominant element as nums, so this is a valid split. 
        It can be shown that index 2 is the minimum index of a valid split. 

    Example 2:
        Input: nums = [2,1,3,1,1,1,7,1,2,1]
        Output: 4
        Explanation: We can split the array at index 4 to obtain arrays [2,1,3,1,1] and [1,7,1,2,1].
        In array [2,1,3,1,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 > 5.
        In array [1,7,1,2,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 > 5.
        Both [2,1,3,1,1] and [1,7,1,2,1] have the same dominant element as nums, so this is a valid split.
        It can be shown that index 4 is the minimum index of a valid split.

    Example 3:
        Input: nums = [3,3,3,3,7,2,2]
        Output: -1
        Explanation: It can be shown that there is no valid split.


// Complexity:
    // Super BruteFore:
        -> TC: O(n^2)
        -> SC: O(n)
        
    // BruteFore:
        -> TC: O(n^2)
        -> SC: O(n)

    // Better Solution:
        -> TC: O(n)
        -> SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Better Solution: Because Question says both side elements should be same, So, we can directly check the element frequency from map, instead of getting the dominant again & again..
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return -1;   // single size array can't have any dominant element

        unordered_map<int, int> leftMp;
        unordered_map<int, int> rightMp;

        for(auto &it: nums) rightMp[it]++;    // hash right dominant:

        for(int i = 0; i < n; i++) {    // while iterating add values in left map & remove values from right map
            // Hash Values in maps:
            leftMp[nums[i]]++;    // add values in left map
            rightMp[nums[i]]--;   // remove values from right map
            if(rightMp[nums[i]] == 0) rightMp.erase(nums[i]);  // if frequency of (nums[i] == 0) in right map -> remove it.

            // Check dominant in left Half & right half Directly from map with comparing the nums[i]:
            int lHalfSize = i + 1;  // left subarray size:
            int rHalfSize = n - (i + 1);  // right subarray size

            if(leftMp[nums[i]] > lHalfSize / 2 && rightMp[nums[i]] > rHalfSize / 2) return i;   // we can directly look in map, because as per question both side element should be same.
        }

        return -1;
    }
};


// BruteForce Solution: with using map for left half & right half, we can only check for dominant element in map instead of whole array..
class Solution {
    int dominant(unordered_map<int, int> &mp, int size) {   // only check the map dominant element:
        
        int domVal = -1;
        int domFreq = -1;
        
        for(auto &it: mp) {
            int value = it.first;
            int freq = it.second;

            if(freq > domFreq) {
                domFreq = freq;
                domVal = value;
            }
        }

        // if the frequency is grater than the subarray size / 2 => then only valid answer
        return (domFreq > size / 2) ? domVal : -1;
    }
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return -1;   // single size array can't have any dominant element

        unordered_map<int, int> leftMp;
        unordered_map<int, int> rightMp;

        for(auto &it: nums) rightMp[it]++;    // hash right dominant:

        for(int i = 0; i < n; i++) {    // while iterating add values in left map & remove values from right map
            // Hash Values in maps:
            leftMp[nums[i]]++;    // add values in left map
            rightMp[nums[i]]--;   // remove values from right map
            if(rightMp[nums[i]] == 0) rightMp.erase(nums[i]);  // if frequency of (nums[i] == 0) in right map -> remove it.

            // Check dominant in left Half:
            int lHalfSize = i + 1;  // left subarray size:
            int left = dominant(leftMp, lHalfSize);

            // Check Dominant in right Half:
            int rHalfSize = n - (i + 1);  // right subarray size
            int right = dominant(rightMp, rHalfSize);

            // -1 check for the valid index
            if(left != -1 && left == right) return i;
        }

        return -1;
    }
};


// Super BruteForce Solution: Implement the given question step by step...
class Solution {
private: 
    int dominant(vector<int> &nums, int start, int end) {   // get the dominant number from left & right half of subarray
        unordered_map<int, int> mp;
        for(int i = start; i <= end; i++) {
            mp[nums[i]]++;  // increase the frequency:
        }

        int domNum = -1;
        int domFreq = 0;

        for(auto &it: mp) {
            int num = it.first;
            int freq = it.second;

            if(freq > domFreq) {
                domFreq = freq;
                domNum = num;
            }
        }

        int size = end - start + 1;     // size of subarray

        // if freq is not greater than subarray size / 2, then we can't return our answer.
        return (domFreq > size / 2) ? domNum : -1;  
    }
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return -1;   // single size array can't have any dominant element

        for(int i = 0; i < n; i++) {
            int left = dominant(nums, 0, i);
            int right = dominant(nums, i + 1, n - 1);

            // -1 check for valid answer, if any of the value has -1, means it fails the conditions.
            if(left != -1 && left == right) return i;
        }

        return -1;
    }
};