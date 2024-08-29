/*

// 189. Rotate Array


// Observations: 
    * Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
    
// Example:

    Input: nums = [1,2,3,4,5,6,7], k = 3
    Output: [5,6,7,1,2,3,4]
        Explanation:
        rotate 1 steps to the right: [7,1,2,3,4,5,6]
        rotate 2 steps to the right: [6,7,1,2,3,4,5]
        rotate 3 steps to the right: [5,6,7,1,2,3,4]

    Input: nums = [-1,-100,3,99], k = 2
    Output: [3,99,-1,-100]
        Explanation: 
        rotate 1 steps to the right: [99,-1,-100,3]
        rotate 2 steps to the right: [3,99,-1,-100]

// Intrusion: 
    // Bruteforce Approach: 
        * rotating element one -> k times..
        * we will make a function that will rotate the element by one position
        * We will run this function k times.
        * TC: O(n^2) -> TLE

    // Efficient Approach: 
        * Example Observations: 

            Input: nums = [1,2,3,4,5,6,7], k = 3,   n = 7
            Output: [5,6,7,1,2,3,4]
            
            // Method 1: As we have to right rotate, we can use this logic:
                1 2 3 4 5 6 7   -> Original array
                1 2 3 4   5 6 7 -> split 3 place from last
                4 3 2 1   7 6 5 -> reverse (0 to n-k-1) & (n-k to n)
                4 3 2 1 7 6 5   -> reverse (0 to n)
                5 6 7 1 2 3 4   -> final array

            // Method 2: 
                1 2 3 4 5 6 7   -> Original array
                7 6 5 4 3 2 1   -> reverse(0 to n)
                7 6 5   4 3 2 1   -> split 3 places
                5 6 7   1 2 3 4   -> reverse (0 to k) & (k to n)
                5 6 7 1 2 3 4   -> final array

                

        * Example Observations: 
            Input: nums = [-1,-100,3,99], k = 2, n = 4
            Output: [3,99,-1,-100]

                -1 100 3 99
                99 3 100 -1 -> reverse (0 to n)
                3 99  -1 100    -> reverse (0 to k) & (k to n)
                3 99 -1 100    -> final array
                

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // BruteForce Approach: rotate one by k-times
    void rotateByOne(vector<int> &nums){
        int n = nums.size();
        int temp = nums[n-1];
        for(int i=n-2;i>=0;i--){
            nums[i+1] = nums[i];
        }
        nums[0] = temp;
    }
    void rotate_Brute(vector<int>& nums, int k) {
        for(int i=0;i<k;i++){
            rotateByOne(nums);
        }
    }
    // Efficient Approach: 
    void rotate(vector<int> &nums, int k){
        int n = nums.size();
        k = k % n;  // taking modulo with array size will round the rotation value in range, if k is greater than n

        // Method 1:
        // reverse(nums.begin(), nums.begin()+n-k);
        // reverse(nums.begin()+n-k, nums.end());
        // reverse(nums.begin(), nums.end());

        // Method 2: 
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    
    }

};