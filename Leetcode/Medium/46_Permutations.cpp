/*

//  46. Permutations | Backtracking


//  Problem Statement: 
    -> Given an array nums of distinct integers, return all the possible
    -> You can return the answer in any order.

// Example: 

    Example 1:
        Input: nums = [1,2,3]
        Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

    Example 2:
        Input: nums = [0,1]
        Output: [[0,1],[1,0]]

    Example 3:
        Input: nums = [1]
        Output: [[1]]


// Observations: 
    -> From the given list, we need to generate all the permutations.
    -> Generate all the permutations & return them in any order..
    -> Try using a pointer which start from 0 & goes up till n-1
        -> inside that start a loop & swap i to n values
        -> After swapping revert the values to backtrack & find the next possible permutations..


    // Complexity: 
        -> TC: O(n! * n)
            -> O(n!) => all permutations
            -> O(n) => recursion stack
        -> SC: O(n! * n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    vector<vector<int>> st;
    void solve(vector<int>& nums, int i, int n) {
        if(i == n) {    // if ith pointer reaches to end -> Store answer & return
            st.push_back(nums);
            return;
        }

        // Explore all further swapping possibility in permutate manner:
        for(int index = i; index < n; index++) {
            swap(nums[index], nums[i]);
            solve(nums, i + 1, n);
            swap(nums[index], nums[i]); // revert it back, for backtracking & applying next possibility..
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        solve(nums, 0, n);

        return st;
    }
};

