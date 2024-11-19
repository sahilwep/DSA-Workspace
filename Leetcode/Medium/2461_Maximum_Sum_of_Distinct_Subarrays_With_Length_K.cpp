/*

//  2461. Maximum Sum of Distinct Subarrays With Length K




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


#define ll long long

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        ll ans = 0;
        ll currWin = 0;

        unordered_set<int> st;

        int i = 0;
        int j = 0;

        while(j < n){
            // Check if nums[j] is already present in current window nums[i...j]

            while(st.count(nums[j])){
                currWin -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            currWin += nums[j];
            st.insert(nums[j]);

            if(j-i+1 == k){
                ans = max(ans, currWin);
                currWin -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            j++;
        }


        return ans;
    }
};