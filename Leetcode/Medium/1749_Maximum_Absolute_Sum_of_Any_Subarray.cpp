/*

//  1749. Maximum Absolute Sum of Any Subarray

//  Problem Statement: 
    -> You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).
    -> Return the maximum absolute sum of any (possibly empty) subarray of nums.
    -> Note that abs(x) is defined as follows:
        -> If x is a negative integer, then abs(x) = -x.
        -> If x is a non-negative integer, then abs(x) = x.

 

// Example:
    Example 1:
        Input: nums = [1,-3,2,3,-4]
        Output: 5
        Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.

    Example 2:
        Input: nums = [2,-5,1,-4,3,-2]
        Output: 8
        Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0,maxi=INT_MIN;
        int n=nums.size(),i=0;
        while(i<n){
            sum+=nums[i];
            maxi=max((sum),maxi);
            if(sum<0){
                sum=0;
            }
            i++;
        }

        i=0,sum=0;
        int mini=INT_MAX;
        while(i<n){
            sum+=nums[i];
            mini=min((sum),mini);
            if(sum>0){
                sum=0;
            }
            i++;
        }

        return max(abs(maxi),abs(mini));

        
        
    }
};