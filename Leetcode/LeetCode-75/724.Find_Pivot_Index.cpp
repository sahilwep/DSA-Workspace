/*

//  724. Find Pivot Index


//  Observations: 
    * We are given an array of integer nums, we need to find such index where left side sum & right side sum is equal.


// Example:

    Input: nums = [1,7,3,6,5,6]
    Output: 3
    Explanation:
    The pivot index is 3.
    Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
    Right sum = nums[4] + nums[5] = 5 + 6 = 11


    Input: nums = [1,2,3]
    Output: -1
    Explanation:
    There is no index that satisfies the conditions in the problem statement.


    Input: nums = [2,1,-1]
    Output: 0
    Explanation:
    The pivot index is 0.
    Left sum = 0 (no elements to the left of index 0)
    Right sum = nums[1] + nums[2] = 1 + -1 = 0


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        vector<int> suffix(n + 1, 0);

        // leave first index as 0
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        // leave last index as 0
        for(int i=n-1;i>=0;i--){
            suffix[i] = suffix[i+1] + nums[i];
        }

        for(int i=0;i<n;i++){
            if(prefix[i] == suffix[i+1]){
                return i;
            }
        }

        return -1;
    }
};
