/*

//  3355. Zero Array Transformation I


//  Problem Statement: 
    -> You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].
    -> For each queries[i]:
        -> Select a subset of indices within the range [li, ri] in nums.
        -> Decrement the values at the selected indices by 1.
    -> A Zero Array is an array where all elements are equal to 0.
    -> Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.
 
// Example: 

    Example 1:
        Input: nums = [1,0,1], queries = [[0,2]]
        Output: true
        Explanation:
            For i = 0:
                Select the subset of indices as [0, 2] and decrement the values at these indices by 1.
                The array will become [0, 0, 0], which is a Zero Array.

    Example 2:
        Input: nums = [4,3,2,1], queries = [[1,3],[0,2]]
        Output: false
        Explanation:
            For i = 0:
                Select the subset of indices as [1, 2, 3] and decrement the values at these indices by 1.
                The array will become [4, 2, 1, 0].
            For i = 1:
                Select the subset of indices as [0, 1, 2] and decrement the values at these indices by 1.
                The array will become [3, 1, 0, 0], which is not a Zero Array.

// Observations: 
    -> given nums of len n
    -> given queries {li, ri}
    -> for each queries: 
        -> select subset {li, ri} in nums
        -> decrement the value at the selected indices by 1
    -> zero array is an array where all the element are equal to 0
    -> return "true" if it's possible to transform nums into a zero array after processing all the queries sequentially.
    -> Otherwise return "false"

    // Range Update Operations => Array Difference Technique 
        -> Array Difference Technique will help us to update range: 
            -> Create an array with same length of given nums with default value '0'
            -> For any given query: {left[i], right[i]}
                arr[left] += UpdateValue;
                arr[right + 1] -= UpdateValue
                NOTE: make sure to update these array value within the range..
            -> Now Create prefix sum from these Updation.

        -> Rest we can perfrom the computation based on this prefix sum...


// Complexity:  
    -> TC: O(N + Q)
        -> N = nums.size()
        -> Q = Query.size()

    -> SC: O(N)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // Array Diff Technique ---------------
        // Step 1: Populate queryUpdate with queries: 
        vector<int> queryUpdate(n, 0);
        for(auto &it: queries) {
            int l = it[0], r = it[1];
            if(l < n) queryUpdate[l] += 1;
            if((r + 1) < n) queryUpdate[r + 1] -= 1;
        }
        
        // Step 2: Build Prefix Sum:
        for(int i = 1; i < n; i++) {
            queryUpdate[i] = queryUpdate[i-1] + queryUpdate[i];
        }

        // Now Check given question Conditions: 
        for(int i = 0; i < n; i++) {
            if(nums[i] > queryUpdate[i]) return false;
        }

        return true;    // all the nums values will be converted to zero array
    }
};

