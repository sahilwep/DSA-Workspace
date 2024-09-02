/*

// 2 Sum Problem:

// Observations: 
    * we are given an array nums & integer 'target', we need to find two index values that sum up and equal to 'target'.
    * We need to return two index in vector.


// Intrusion: 
    // Bruteforce Approach: 
        * We will use nested loop approach, & try to find two index which sum up target.
        * TC: O(n^2)
    
    // Efficient Approach: 
        * We will use hashmap in this approach, 
        * As we have to find two element that sum up the target, if we think in that way: 
            * target - arr[i] -> (arr[j] we will look this in map)
            * if that values exist, we will return the current index, i.e the index on which the current element is found using hashmap i.e map[target - arr[i]]
            * else we will return {-1, -1}
        * TC: O(n)
        * AS: O(n)

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Using hashing:  O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp; // declaring map

        for(int i=0;i<n;i++){
            int need = target - nums[i];    // getting the needed value, by subtracting arr[i] it from the target. 
            // if the needed value found in the map, we will return the indexes
            if(mp.find(need) != mp.end()){
                return {mp[need], i};   // returning the index.
            }
            // hashing the index & the value into the hashmap.
            mp[nums[i]] = i;
        }

        return {-1, -1};
    }

    // Bruteforce Approach:  O(n^2)
    vector<int> twoSum_Brute(vector<int>& nums, int target) {
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