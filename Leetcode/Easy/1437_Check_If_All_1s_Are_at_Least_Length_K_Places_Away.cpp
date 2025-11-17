/*

//  1437. Check If All 1's Are at Least Length K Places Away


//  Problem Statement: 
    - Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.

//  Example: 
    Example 1:
        Input: nums = [1,0,0,0,1,0,0,1], k = 2
        Output: true
        Explanation: Each of the 1s are at least 2 places away from each other.

    Example 2:
        Input: nums = [1,0,0,1,0,1], k = 2
        Output: false
        Explanation: The second 1 and third 1 are only one apart from each other.

// Observations: 
    - It's just we need to get the zeroes count & whenever we get 1's we will check the given constrains..

    // Complexity: 
        - TC: O(n)
        - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {

        int zCnt = 1e5 + 1; // setting zero count range as constrains boundary.
        for(auto &it: nums) {
            if(it == 1) {
                if(zCnt < k) return false;
                zCnt = 0;   // reset zero count
            } else {
                zCnt++;
            }
        }
        
        return true;
    }
};