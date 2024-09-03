/*

// 169. Majority Element

// Observations:
    * we are given an array of size n, & we have to find the element that appears more that n/2 times

// Example: 

    Input: nums = [3,2,3]
    Output: 3

    Input: nums = [2,2,1,1,1,2,2]
    Output: 2


// Intrusion: 
    // Approach 1: Bruteforce Solution:
        * We will use nested loop, we will select element one by one and iterating in array and counting the number of times.
        * TC: O(n^2)
        * AS: O(1)

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Bruteforce Solution: O(n^2)
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int cnt = 1;    // cnt = 1, because in if condition we are saying (i != j), so we are skipping same count, so we have to assign it to 1.
            for(int j=0;j<n;j++){
                if(i != j && nums[i] == nums[j]){
                    cnt++;
                }
            }
            if(cnt > n/2){
                return nums[i];
            }
        }
        return -1;  // when we don't have any majority element
    }
};
