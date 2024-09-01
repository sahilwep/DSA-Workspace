/*

// 2 Sum Problem:

// Observations: 
    * we are given an array nums & integer 'target', we need to find two index values that sum up and equal to 'target'.
    * We need to return two index in vector.


// Intrusion: 
    // Bruteforce Approach: 
        * We will use nested loop approach, & try to find two index which sum up target.
        * TC: O(n^2)
    


*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        int n = nums.size();
        for(int i=0;i<n;i++){
            bool isFound = 0;
            for(int j=0;j<n;j++){
                if(i != j && nums[i] + nums[j] == target){
                    v.push_back(i);
                    v.push_back(j);
                    isFound = 1;
                    break;
                }
            }
            if(isFound){
                break;
            }
        }

        return v;
    }
};