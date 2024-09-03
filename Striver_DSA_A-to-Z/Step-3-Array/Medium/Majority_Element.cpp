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
    
    // Approach 2: using Hashing: 
        * we will sort the array & return n/2th element, that element will be our majority element.
        * TC: O(nlogn)
        * AS: O(1)

    // Approach 3: Using hashing:
        * hash all the values in an array, & if the element is garter than (n/2) return that.
        * TC: O(n)
        * AS: O(n)
    
    // Approach 4: Using Moore Voting Algorithm
        * This algorithm works on the constrains that the element should appears more than n/2 times.
        * If elements appears more than n/2, this algorithm definitely will works, because in whatever arrangement we will have the most occurring element.
        * Steps: 
            * first we will find the most occurring element.
            * Second we will find how many times it's appears in an array.
            * If that appears more than n/2 we will return that element else we will return (-1), which means not found.
        * TC: O(n)
        * AS: o(1)

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
    // Using Sorting:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];   // returning the n/2th element
    }
    // Using Hashing:
    int majorityElement(vector<int>& nums) {
        // hash the values in 
        unordered_map<int, int> mp;
        for(auto i : nums){
            mp[i]++;
        }
        int n = nums.size();
        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->second > n/2) return i->first;
        }

        return -1;  // as there is no majority element.
    }

    // Using Moore Voting Algorithm: O(n)
    int majorityElement_E(vector<int>& arr) {
        // first step to find the most occurring elements
        int n = arr.size();
        int res = 0;    //position 
        int count = 1;  //setting the counter 1, at starting.
        for(int i=1;i<n;i++){
            // Condition to increase frequency, if element has occurring..
            if(arr[i] == arr[res]){
                count++;    
            }
            else {
                count--;    // else decreasing the counter...
            }
            // Changing the (arr[res])-> element that we are comparing...
            if(count == 0){
                res = i;    // making the candidate as new current (arr[i])->element.
                count = 1;  // reseting the counter..
            }
        }
        // Second step is to finding the frequency of that element.
        count = 0;  // resiting the counter
        for(int i=0;i<n;i++){
            if(arr[i] == arr[res]){
                count++;
            }
        }
        // Checking the condition if that element is less than or equal n/2, we return -1
        if(count <= n/2){
            return 0;
        }
        return arr[res];    // returning the most occurring element..
    }
};
