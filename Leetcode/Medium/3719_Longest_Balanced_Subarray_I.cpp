/*

//  3719. Longest Balanced Subarray I


//  Problem Statement: 
    -> You are given an integer array nums.
    -> A is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.
    -> Return the length of the longest balanced subarray.

 
// Example: 
    Example 1:
        Input: nums = [2,5,4,3]
        Output: 4
        Explanation:
            The longest balanced subarray is [2, 5, 4, 3].
            It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [5, 3]. Thus, the answer is 4.

    Example 2:
        Input: nums = [3,2,2,5,4]
        Output: 5
        Explanation:
            The longest balanced subarray is [3, 2, 2, 5, 4].
            It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [3, 5]. Thus, the answer is 5.

    Example 3:
        Input: nums = [1,2,3,2]
        Output: 3
        Explanation:
            The longest balanced subarray is [2, 3, 2].
            It has 1 distinct even number [2] and 1 distinct odd number [3]. Thus, the answer is 3.


// Observations:
    -> Given nums, we need to find the longest balanced subarray.
    -> Balanced subarray is subarray: 
        - number of distinct even element & odd element should be equal.


    // Approach: 
        -> From every index try finding the the subarray whose follows these rules: 
            - having number of distinct odd & even element should be equal:
                - we can use something like set, which will store only unique elements,
                - When we have equal odd & even:
                    - Store the longest index difference.


        // Complexity:  
            -> TC: O(n^2)
            -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        int res = 0;
        for(int i = 0; i < n; i++) {
            set<int> odd, even;
            for(int j = i; j < n; j++) {
                if(nums[j] % 2 == 0) even.insert(nums[j]);
                else odd.insert(nums[j]);

                // Store the longest: 
                if(odd.size() == even.size()) {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }
};