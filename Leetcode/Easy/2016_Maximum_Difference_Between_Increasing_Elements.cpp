/*

//  2016. Maximum Difference Between Increasing Elements


//  Problem Statement: 
    -> Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].
    -> Return the maximum difference. If no such i and j exists, return -1.


// Example: 

    Example 1:
        Input: nums = [7,1,5,4]
        Output: 4
        Explanation:
        The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
        Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.

    Example 2:
        Input: nums = [9,4,3,2]
        Output: -1
        Explanation:
        There is no i and j such that i < j and nums[i] < nums[j].

    Example 3:
        Input: nums = [1,5,2,10]
        Output: 9
        Explanation:
        The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.

// Observations: 
    // BruteForce: 
        -> Apply the given statement

    // Efficient: 
        -> Thinks as in term of Commutative sum


// Complexity:
    // BruteForce: 
        -> TC: O(n^2)
        -> SC: O(1)

    // Efficient
        -> TC: O(n)
        -> SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient:
class Solution {
private: 
    bool isDecreasing(vector<int>& nums, int n) {
        for(int i = 1; i < n; i++) if(nums[i] > nums[i-1]) return false;
        return true;
    }
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();

        // Edge case: Check Decreasing: 
        if(isDecreasing(nums, n)) return -1;

        // Commutative sum Approach: 
        // process minimum 'i'
        vector<int> maxi(n, 0);
        maxi[n-1] = nums[n-1];
        for(int i = n - 2; i >= 0; i--) {
            maxi[i] = max(nums[i], maxi[i+1]);
        }

        vector<int> mini(n, 0);
        mini[0] = nums[0];
        for(int i = 1; i < n; i++) {
            mini[i] =  min(nums[i], mini[i-1]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, maxi[i] - mini[i]);
        }

        return ans;
    }
};


// BruteForce
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();

        int ans = -1;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] < nums[j]) {
                    ans = max(ans, nums[j] - nums[i]);
                }
            }
        }
        
        return ans;
    }
};