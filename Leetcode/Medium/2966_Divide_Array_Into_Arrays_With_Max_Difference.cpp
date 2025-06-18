/*

//  2966. Divide Array Into Arrays With Max Difference


//  Problem Statement: 
    -> You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.
    -> Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:
        -> The difference between any two elements in one array is less than or equal to k.
    -> Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.


//  Example: 
    Example 1:
        Input: nums = [1,3,4,8,7,9,3,5,1], k = 2
        Output: [[1,1,3],[3,4,5],[7,8,9]]
        Explanation: The difference between any two elements in each array is less than or equal to 2.

    Example 2:

        Input: nums = [2,4,2,2,5,2], k = 2
        Output: []
        Explanation: Different ways to divide nums into 2 arrays of size 3 are:
                [[2,2,2],[2,4,5]] (and its permutations)
                [[2,2,4],[2,2,5]] (and its permutations)
            Because there are four 2s there will be an array with the elements 2 and 5 no matter how we divide it. since 5 - 2 = 3 > k, the condition is not satisfied and so there is no valid division.

    Example 3:
        Input: nums = [4,2,9,8,2,12,7,12,10,5,8,5,5,7,9,2,5,11], k = 14
        Output: [[2,2,12],[4,8,5],[5,9,7],[7,8,5],[5,9,10],[11,12,2]]
        Explanation: The difference between any two elements in each array is less than or equal to 14.


//  Observations: 
    -> We are given nums of size multiples of '3'
    -> We need to divide it by 3, & which will form x numbers of list
    -> For every array, we need to make sure the difference b/w any two value is less than 'k'
    -> Return 2D vector containing answer.

    // Solution: 
        -> Sorting will help us to form such array with difference between any two elements in one array is less than or equal to k.
        -> After the array is sorted, if we check the difference of any tow adjacent element, & if it's greater than 'k', we can't form our answer
        -> Instead of checking every value in array, we can check the extreme value, (firstElement & lastElement), if it's grater than 'k', we can't form our answer..

    // Complexity: 
        -> TC: O(n * log(n))
            -> N = nums.size()
        -> AS: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Improved: 
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));   // Sort the given nums

        vector<vector<int>> ans;
        for(int i = 1; i < n; i += 3) {
            int prev = nums[i - 1];
            int curr = nums[i];
            int next = nums[i + 1];

            // Check only extrem value, if it's grater, then return empty {}
            if(next - prev > k) return {};
            ans.push_back({prev, curr, next});
        }
        
        return ans;
    }
};


// Naive Implementations: 
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));   // Sort the given nums

        vector<vector<int>> ans;
        for(int i = 1; i < n; i += 3) {
            int prev = nums[i - 1];
            int curr = nums[i];
            int next = nums[i + 1];

            // Check all three values, & if anyones exceeds return empty vector.
            if(curr - prev > k || next - curr > k || next - prev > k) return {};
            ans.push_back({prev, curr, next});
        }
        
        return ans;
    }
};