/*

// 3254. Find the Power of K-Size Subarrays I


// Problem Statement:
    * You are given an array of integers nums of length n and a positive integer k.
    * The power of an array is defined as:
        * Its maximum element if all of its elements are consecutive and sorted in ascending order.
        * -1 otherwise.

    * You need to find the power of all subarrays of nums of size k.
    * Return an integer array results of size (n - k + 1), where results[i] is the power of nums[i..(i + k - 1)]


// Example:

    Example 1:

        Input: nums = [1,2,3,4,3,2,5], k = 3
        Output: [3,4,-1,-1,-1]

        Explanation:
        There are 5 subarrays of nums of size 3:

            [1, 2, 3] with the maximum element 3.
            [2, 3, 4] with the maximum element 4.
            [3, 4, 3] whose elements are not consecutive.
            [4, 3, 2] whose elements are not sorted.
            [3, 2, 5] whose elements are not consecutive.

    Example 2:

        Input: nums = [2,2,2,2,2], k = 4
        Output: [-1,-1]

    Example 3:

        Input: nums = [3,2,3,2,3,2], k = 2
        Output: [-1,3,-1,3,-1]



// Approach: 
    -> We will use sliding window concept.
    -> consecutive means one after another -> This makes logic super easy
    -> we just need to check whether element are consecutive in k size window or not?
    -> depending upon that we will fill our answer.



// TC: O(n)



*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> res(n-k+1, -1); // result array

        // Find the first k size sliding window:
        int consecutiveCnt = 1; // variable that check consecutive count
        for(int i=1;i<k;i++){
            if(nums[i-1]+1 == nums[i]){ // if previous element incremented by 1, & gives current element:
                consecutiveCnt++;// increment counsecutive count
            }
            else{
                consecutiveCnt = 1; // reset consecutive count
            }
        }

        // last check consecutive count & fill answer for first k size window:
        if(consecutiveCnt == k) res[0] = nums[k-1];

        // Now, shifting our window by 1,
        int i = 1;  // first pointer start from 1, because we have shifted our window by 1
        int j = k;  // second pointer start from k, as index is 0 based, & we have only iterated till (< k) less than k.

        // Process rest of the element:
        while(j < n){
            // if current element is 1 grater than the previous once:
            if(nums[j] == nums[j-1]+1){
                consecutiveCnt++;   // increment counsecutive count
            }
            else{
                consecutiveCnt = 1; // reset consecutive count
            }

            // Check Consecutive count if it's grater or equal to k, fill our i.e maximum:
            if(consecutiveCnt >= k) res[i] = nums[j];

            // increment the pointers:
            i++;
            j++;
        }

        return res;
    }
};