/*

// 485. Max Consecutive Ones

// Observations: 
    * We are given a binary array, & we have to find the maximum consecutive 1's 

// Intrusion: 
    * We will use counter approach: 
        * if we encounter with 1, increment the counter
        * if we encounter with 0, we will make our counter = 0
        * at every iteration we will store the counter value, & return the max among all the iterations.
    * TC: O(n)
    * AS: O(1)


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int res = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                cnt++;
            }
            else{
                cnt = 0;
            }
            res = max(res, cnt);    // at the end of every iteration, we will store the maximum of counter value.
        }
        
        return res;
    }
};