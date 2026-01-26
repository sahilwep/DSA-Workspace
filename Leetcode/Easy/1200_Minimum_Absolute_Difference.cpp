/*

//  1200. Minimum Absolute Difference


//  Problem Statement: 
    - Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.
    - Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
        a, b are from arr
        a < b
        b - a equals to the minimum absolute difference of any two elements in arr

 
// Example:
    Example 1:
        Input: arr = [4,2,1,3]
        Output: [[1,2],[2,3],[3,4]]
        Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.

    Example 2:
        Input: arr = [1,3,6,10,15]
        Output: [[1,3]]

    Example 3:
        Input: arr = [3,8,-10,23,19,-4,-14,27]
        Output: [[-14,-10],[19,23],[23,27]]


// Observations:
    - Find the minimum diff
    - Include all the pairs with minimum diff.

    // Approach:
        - Sort the given array
        - find the minimum diff
        - Generate all the pairs with minimum diff.

    // Complexity:  
        - TC: O(n)
        - SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        // Finding minimum diff:
        int minDiff = INT_MAX;
        for(int i = 0; i < n - 1; i++) {
            int diff = nums[i + 1] - nums[i];
            minDiff = min(minDiff, diff);
        }

        // Find all the pairs with minimum diff:
        vector<vector<int>> ans;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i + 1] - nums[i] == minDiff) {
                ans.push_back({nums[i], nums[i + 1]});
            }
        }

        return ans;
    }
};