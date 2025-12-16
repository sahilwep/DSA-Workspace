/*

//  448. Find All Numbers Disappeared in an Array


//  Problem Statement: 
    - Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 
// Example:
    Example 1:
        Input: nums = [4,3,2,7,8,2,3,1]
        Output: [5,6]

    Example 2:
        Input: nums = [1,1]
        Output: [2]

// Approach:    
    - Use set & find the missing values in range 1 to n
    
    // Complexity: 
        - TC: O(n)
        - SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        unordered_set<int> st(begin(nums), end(nums));
        vector<int> ans;
        for(int i = 1; i <= n; i++) {
            if(!st.count(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};