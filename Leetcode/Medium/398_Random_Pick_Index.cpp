/*

//  398. Random Pick Index


//  Problem Statement: 
    -> Given an integer array nums with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.
    -> Implement the Solution class:
        -> Solution(int[] nums) Initializes the object with the array nums.
        -> int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, then each index should have an equal probability of returning.

 
// Example:
    Example 1:
        Input
            ["Solution", "pick", "pick", "pick"]
            [[[1, 2, 3, 3, 3]], [3], [1], [3]]
        Output [null, 4, 0, 2]

        Explanation
            Solution solution = new Solution([1, 2, 3, 3, 3]);
            solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
            solution.pick(1); // It should return 0. Since in the array only nums[0] is equal to 1.
            solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.


// Observations: 
    - Implement the given statement, use map to store the nums: index
    - pick functions we will use rand() function to return the random value & round with index...
    
    // Complexity:
        - pick() O(1)
        

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    unordered_map<int, vector<int>> mp;
public:
    Solution(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
    }
    int pick(int target) {  // O(1)
        int n = mp[target].size();  // get the total index corresponding to that element
        return mp[target][rand() % n];  // use rand() function to get random index, mod with n, to round within the index size...
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */