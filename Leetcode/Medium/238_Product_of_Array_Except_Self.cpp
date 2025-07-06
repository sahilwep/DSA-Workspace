/*

//  238. Product of Array Except Self


//  Problem Statement: 
    -> Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
    -> The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
    -> You must write an algorithm that runs in O(n) time and without using the division operation.



// Example: 
    Example 1:
        Input: nums = [1,2,3,4]
        Output: [24,12,8,6]

    Example 2:
        Input: nums = [-1,1,0,-3,3]
        Output: [0,0,9,0,0]


// Observations: 
    -> we are given an array
    -> for each index generate the product from left & right side, except itself..

// BruteForce: 
    -> use left & right hand side product for every index.

    // Complexity:
        -> TC: O(n ^2)
        -> SC: O(1)


// Efficient: 
    -> Use prefix & suffix product array & build answer for every index..

    // Complexity:
        -> TC: O(N)
        -> SC: O(N)


// Efficient Improved: 
    -> Use prefix & product array & maintain suffix variable & with that build answer for every index..

    // Complexity:
        -> TC: O(N)
        -> SC: O(N)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Optimized: 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // Build prefix product:
        vector<int> pref(n);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i-1] * nums[i];
        }

        // Build answer & maintain one suffix variable:
        vector<int> ans(n);
        int suffix = nums[n-1];
        ans[n-1] = pref[n-2];
        for(int i = n - 2; i > 0; i--) {
            ans[i] = pref[i-1] * suffix;
            suffix *= nums[i];
        }
        ans[0] = suffix;

        return ans;      
    }
};

// Efficient Solution:
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        // Build prefix product:
        vector<int> pref(n);
        pref[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pref[i] = pref[i-1] * nums[i];
        }

        // Build suffix Products:
        vector<int> suff(n);
        suff[n-1] = nums[n-1];
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] * nums[i];
        }

        // Build answer:
        vector<int> ans(n);
        ans[0] = suff[1];
        ans[n-1] = pref[n-2];
        for(int i = 1; i < n - 1; i++) {
            ans[i] = pref[i - 1] * suff[i + 1];
        }

        return ans;      
    }
};


// BruteForce Solution: TC: O(N^2) => TLE 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            // Find left side product
            int left = 1;
            for(int j = 0; j < i; j++) {
                left *= nums[j];
            }

            // Find right side product
            int right = 1;
            for(int j = n - 1; j > i; j--) {
                right *= nums[j];
            }

            // Build answer: 
            ans[i] = left * right;
        }

        return ans;      
    }
};