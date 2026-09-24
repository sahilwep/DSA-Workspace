/*

//  3550. Smallest Index With Digit Sum Equal to Index


//  Problem Statement: 
    - You are given an integer array nums.
    - Return the smallest index i such that the sum of the digits of nums[i] is equal to i.
    - If no such index exists, return -1.

 
// Example:
    Example 1:
        Input: nums = [1,3,2]
        Output: 2
        Explanation: For nums[2] = 2, the sum of digits is 2, which is equal to index i = 2. Thus, the output is 2.

    Example 2:
        Input: nums = [1,10,11]
        Output: 1
        Explanation:
            For nums[1] = 10, the sum of digits is 1 + 0 = 1, which is equal to index i = 1.
            For nums[2] = 11, the sum of digits is 1 + 1 = 2, which is equal to index i = 2.
            Since index 1 is the smallest, the output is 1.

    Example 3:
        Input: nums = [1,2,3]
        Output: -1
        Explanation: Since no index satisfies the condition, the output is -1.


// Observations:
    - given nums
    - return smallest index i, such that sum of the digits of nums[i] is equal to i
    - if no such index exist return -1


    // Approach: 
        - implement the given statement.

    // Complexity:
        - TC: O(n * max(log10(nums[i])))
        - SC: O(1)
        - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            int num = nums[i];
            int dSum = 0;

            while(num > 0) {
                dSum += num % 10;
                num /= 10;
            }

            if(dSum == i) return i;
        }

        return -1;  // no such index found.
    }
};