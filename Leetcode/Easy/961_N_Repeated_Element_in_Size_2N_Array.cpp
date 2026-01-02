/*

//  961. N-Repeated Element in Size 2N Array


//  Problem Statement: 
    - You are given an integer array nums with the following properties:
        - nums.length == 2 * n.
        - nums contains n + 1 unique elements.
        - Exactly one element of nums is repeated n times.
    - Return the element that is repeated n times.

//  Example:

    Example 1:
        Input: nums = [1,2,3,3]
        Output: 3

    Example 2:
        Input: nums = [2,1,2,5,3,2]
        Output: 2

    Example 3:
        Input: nums = [5,1,5,2,5,3,5,4]
        Output: 5


// Observations: 
    - Hash the given numbers
    - Find the number that are having exactly 'n' occurrence.


    // Complexity:
        - TC: O(2*n) = O(n)
        - SC: O(n)
        

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int size = nums.size();
        int n = size/2;

        unordered_map<int, int> mp;
        for(auto &it: nums) {
            mp[it]++;
        }

        for(auto &[key, val]: mp) {
            if(val == n) {
                return key;
            }
        }

        return -1;
    }
};