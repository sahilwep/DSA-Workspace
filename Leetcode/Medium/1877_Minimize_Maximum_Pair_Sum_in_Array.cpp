/*

//  1877. Minimize Maximum Pair Sum in Array


//  Problem Statement: 
    - The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair sum in a list of pairs.
        - For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
    - Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:
        - Each element of nums is in exactly one pair, and
        - The maximum pair sum is minimized.
    - Return the minimized maximum pair sum after optimally pairing up the elements.

        
// Example:
    Example 1:
        Input: nums = [3,5,2,3]
        Output: 7
        Explanation: The elements can be paired up into pairs (3,3) and (5,2).
        The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7.

    Example 2:
        Input: nums = [3,5,4,2,4,6]
        Output: 8
        Explanation: The elements can be paired up into pairs (3,5), (4,4), and (6,2).
        The maximum pair sum is max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8.


// Observations:
    - we are given an array of even size
    - we have to pair all the element into into total n/2 groups
    - we have to compute the sum of every pair & get the maximum from all of them.
    - We have to pair every element in such a way so that the maximum_sum should minimized.

    // Approach:
        - If we sort all the elements & make pair of starting & ending elements while moving towards "n/2"
        - We will have optimal pairs of elements.
        - and from them we can take maximum among them.


    // Complexity: 
        - TC: O(n*logn)
        - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int minSum = INT_MIN;
        for(int i = 0; i < n/2; i++) {
            minSum = max(minSum, nums[i] + nums[n - 1 - i]);
        }
        
        return minSum;
    }
};