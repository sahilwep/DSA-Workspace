/*

//  3512. Minimum Operations to Make Array Sum Divisible by K


//  Problem Statement: 
    -You are given an integer array nums and an integer k. You can perform the following operation any number of times:
        - Select an index i and replace nums[i] with nums[i] - 1.
    -Return the minimum number of operations required to make the sum of the array divisible by k.

 
// Example:
    Example 1:
        Input: nums = [3,9,7], k = 5
        Output: 4
        Explanation:
            Perform 4 operations on nums[1] = 9. Now, nums = [3, 5, 7].
            The sum is 15, which is divisible by 5.

    Example 2:
        Input: nums = [4,1,3], k = 4
        Output: 0
        Explanation: The sum is 8, which is already divisible by 4. Hence, no operations are needed.

    Example 3:
        Input: nums = [3,2], k = 6
        Output: 5
        Explanation:
            Perform 3 operations on nums[0] = 3 and 2 operations on nums[1] = 2. Now, nums = [0, 0].
            The sum is 0, which is divisible by 6.

    
// Observations: 
    - We are given nums, & k, we need to find the minimum operations to create nums in a way so that it can divisible by 'k'.
    - In one operations we can make nums[i] to nums[i] - 1

    // Approach
        - sums up all the element of nums.
        - take a mod of them
        - we will get the lower bound/ remaining nums which we need to decrease in order to make our sum divisible by 'k'.


    // Complexity: 
        - TC: O(n)
        - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int sum = accumulate(begin(nums), end(nums), 0);    // get the sum of whole elements

        return sum % k; // return the needed modulo value..
    }
};