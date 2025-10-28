/*

//  3354. Make Array Elements Equal to Zero


//  Problem Statement: 
    -> You are given an integer array nums.
    -> Start by selecting a starting position curr such that nums[curr] == 0, and choose a movement direction of either left or right.
    -> After that, you repeat the following process:
        -> If curr is out of the range [0, n - 1], this process ends.
        -> If nums[curr] == 0, move in the current direction by incrementing curr if you are moving right, or decrementing curr if you are moving left.
        -> Else if nums[curr] > 0:
            -> Decrement nums[curr] by 1.
            -> Reverse your movement direction (left becomes right and vice versa).
            -> Take a step in your new direction.
    -> A selection of the initial position curr and movement direction is considered valid if every element in nums becomes 0 by the end of the process.
    -> Return the number of possible valid selections.

//  Example: 
    Example 1:
        Input: nums = [1,0,2,0,3]
        Output: 2
        Explanation:
            The only possible valid selections are the following:
                Choose curr = 3, and a movement direction to the left.
                    [1,0,2,0,3] -> [1,0,2,0,3] -> [1,0,1,0,3] -> [1,0,1,0,3] -> [1,0,1,0,2] -> [1,0,1,0,2] -> [1,0,0,0,2] -> [1,0,0,0,2] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,1] -> [0,0,0,0,0].
                Choose curr = 3, and a movement direction to the right.
                    [1,0,2,0,3] -> [1,0,2,0,3] -> [1,0,2,0,2] -> [1,0,2,0,2] -> [1,0,1,0,2] -> [1,0,1,0,2] -> [1,0,1,0,1] -> [1,0,1,0,1] -> [1,0,0,0,1] -> [1,0,0,0,1] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [1,0,0,0,0] -> [0,0,0,0,0].

    Example 2:
        Input: nums = [2,3,4,0,4,1,0]
        Output: 0
        Explanation: There are no possible valid selections.


// Observations: 
    - from every '0', we can move in left or right
        - while iterating left or right if we encounter with '0' do nothing..
        - if we encounter with {nums[i] > 0}, we can decrement it by 1 & change directions.
        - we need to find total number such decision were all the nums, getting '0'.
        - Directions: 
            dir: 
                (0 = left)
                (1 = right)

    - Do the simple implementations..

    // Complexity: 
        -> TC: O(n^2)
        -> SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    int n;
    bool isValid(int idx, vector<int> nums, int dir) {
        
        // dir: 0 -> left, 1 -> right
        while(idx >= 0 && idx < n) {
            if(nums[idx] == 0) {
                // move in the current directions, do nothing
                if(dir == 0) idx--;
                else idx++;
                continue;
            }

            // decrement the value
            nums[idx] -= 1; 

            // Switch directions: 
            if(dir == 0) {
                dir = 1;
                idx++;
            }
            else {
                idx--;
                dir = 0;
            }
        }

        // Check all zeroes:
        for(auto &it: nums) if(it != 0) return false;
        return true;
    }
public:
    int countValidSelections(vector<int>& nums) {
        n = nums.size();

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                if(isValid(i, nums, 0)) ans++;  // left dir
                if(isValid(i, nums, 1)) ans++;  // right dir
            }
        }

        return ans;
    }
};