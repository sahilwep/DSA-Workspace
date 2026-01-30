/*

//  1365. How Many Numbers Are Smaller Than the Current Number


//  Problem Statement: 
    - Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
    - Return the answer in an array.
 
// Example:
    Example 1:
        Input: nums = [8,1,2,2,3]
        Output: [4,0,1,1,3]
        Explanation: 
        For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3). 
        For nums[1]=1 does not exist any smaller number than it.
        For nums[2]=2 there exist one smaller number than it (1). 
        For nums[3]=2 there exist one smaller number than it (1). 
        For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).

    Example 2:
        Input: nums = [6,5,4,8]
        Output: [2,1,0,3]

    Example 3:
        Input: nums = [7,7,7,7]
        Output: [0,0,0,0]

// Observations:
    - We are given nums, for each nums[i] we have to find out how many numbers are in the array smaller than it.
    
        // BruteForce Approach:
            - Nested approach, for every nums[i], find count the smaller numbers.

            // Complexity:
                - TC: O(n^2)
                - SC: O(1)


        // Counting Sort Approach:
            - We can find the count of smaller numbers for every every numbers using count sort.
            - First we will hash every numbers.
            - Then we can compute the prefix sum for every numbers.
            - Once we have the prefix sum, we can easily compute the smaller number behind that nums..

            // Complexity:
                - TC: O(n + maximumNums) => O(n), as maximum nums is 101 as per the constrains.
                - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// counting sort:
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(101, 0);
        for(auto &num: nums) {  // store freq
            freq[num]++;
        }

        // Build prefix sum:
        for(int i = 1; i < 101; i++) {
            freq[i] += freq[i - 1];
        }

        // Build ans:
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                ans[i] = 0;
            } else {
                ans[i] = freq[nums[i] - 1];
            }
        }
        

        return ans;
    }
};


// Bruteforce:
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && nums[j] < nums[i]) cnt++;
            }
            
            ans[i] = cnt;
        }

        return ans;
    }
};