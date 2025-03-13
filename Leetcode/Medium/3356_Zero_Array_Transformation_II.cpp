/*

//  3356. Zero Array Transformation II


//  Problem Statement: 
    -> You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, val[i]].
    -> Each queries[i] represents the following action on nums:
        -> Decrement the value at each index in the range [li, ri] in nums by at most val[i].
        -> The amount by which each value is decremented can be chosen independently for each index.
    -> A Zero Array is an array with all its elements equal to 0.
    -> Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.

 
// Example: 

    Example 1:
        Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]
        Output: 2
        Explanation:
            For i = 0 (l = 0, r = 2, val = 1):
                Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
                The array will become [1, 0, 1].
            For i = 1 (l = 0, r = 2, val = 1):
                Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
                The array will become [0, 0, 0], which is a Zero Array. Therefore, the minimum value of k is 2.

    Example 2:
        Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]
        Output: -1
        Explanation:
                For i = 0 (l = 1, r = 3, val = 2):
                    Decrement values at indices [1, 2, 3] by [2, 2, 1] respectively.
                    The array will become [4, 1, 0, 0].
                For i = 1 (l = 0, r = 2, val = 1):
                    Decrement values at indices [0, 1, 2] by [1, 1, 0] respectively.
                    The array will become [3, 0, 0, 0], which is not a Zero Array.

        

// Observations: 
    ->  Given an array of integer of length n
    -> given queries[i] = {l[i], r[i], val[i]}
    -> Each queries[i] represents the following actions on nums:
            -> decrement the value at each index in the range {l[i] r[i]} in nums bt AT MOST val[i]
            -> The amount by which each value decremented can be choosen independently.
    
    -> Return the minimum possible non-negative value of 'k', such that after processing the first 'k' queries in sequence, nums become a zero. 
    -> if no such k query exit return '-1'

    // BruteForce Solution: 
        -> Apply all the given conditions & given constrains with stdrightforword implementations.
        // Complexity:
            -> TC: O(Q * n)
            -> SC: (1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Bruteforce Solution:
class Solution {
private:
    bool allZeroes(vector<int> &nums) { // TC: O(n)
        for(auto &it: nums) {
            if(it != 0) return 0;
        }
        return 1;
    }
    void decrementRange(vector<int> &nums, int l, int r, int val) {  // decrement by 1: TC: O(n)
        for(int i = l; i <= r; i++) {
            nums[i] -= val;
        }
        // Now for all negative value in range (l, r): make them '0'
        for(int i = l; i <= r; i++) {
            if(nums[i] < 0) nums[i] = 0;
        }
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        // Edge case: initially if given nums is zero array:
        if(allZeroes(nums)) return 0;

        int qSize = queries.size();

        int k = 0;
        for(int i = 0; i < qSize; i++) {    // O(Q) * (O(n) + O(n)) => O(Q * n)
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            // Now perform queries:
            decrementRange(nums, l, r, val);     // O(n)
            k++;

            // Last check if nums become zero or not?
            if(allZeroes(nums)) return k;   // O(n)
        }

        // last check out of the Scope:
        for(auto &it: nums) cout << it << " ";
        cout << endl;
        return (allZeroes(nums)) ? k : -1;
    }
};