/*

//  3583. Count Special Triplets


//  Problem Statement: 
    - You are given an integer array nums.
    - A special triplet is defined as a triplet of indices (i, j, k) such that:
        0 <= i < j < k < n, where n = nums.length
        nums[i] == nums[j] * 2
        nums[k] == nums[j] * 2
    - Return the total number of special triplets in the array.
    - Since the answer may be large, return it modulo 109 + 7.

 
// Example:
    Example 1:
        Input: nums = [6,3,6]
        Output: 1
        Explanation: The only special triplet is (i, j, k) = (0, 1, 2), where:
            nums[0] = 6, nums[1] = 3, nums[2] = 6
            nums[0] = nums[1] * 2 = 3 * 2 = 6
            nums[2] = nums[1] * 2 = 3 * 2 = 6

    Example 2:
    Input: nums = [0,1,0,0]
    Output: 1
    Explanation: The only special triplet is (i, j, k) = (0, 2, 3), where:
        nums[0] = 0, nums[2] = 0, nums[3] = 0
        nums[0] = nums[2] * 2 = 0 * 2 = 0
        nums[3] = nums[2] * 2 = 0 * 2 = 0

    Example 3:
    Input: nums = [8,4,2,8,4]
    Output: 2
    Explanation: There are exactly two special triplets:
        (i, j, k) = (0, 1, 3)
            nums[0] = 8, nums[1] = 4, nums[3] = 8
            nums[0] = nums[1] * 2 = 4 * 2 = 8
            nums[3] = nums[1] * 2 = 4 * 2 = 8
        (i, j, k) = (1, 2, 4)
            nums[1] = 4, nums[2] = 2, nums[4] = 4
            nums[1] = nums[2] * 2 = 2 * 2 = 4
            nums[4] = nums[2] * 2 = 2 * 2 = 4

    

// Observations: 
    - We have to find how many triplets are found, nums[i] == 2*nums[j] == nums[k], i < j < k
        - We need to find x == 2*y == x
                          i  <  j  <  k

    - we can easily find any (nums[k] * 2) is already seen or not for any index k, using map by hashing the values..
    - it's just we need to find right hand side value:
        - It's simple initially hash all the values into right_mp
    - After, while iterating remove values from right map & add values into left_map & check...
    - Idea is simple, first we will hash all the values into right_map, once we have all the values, while iterate from 0th index, we remove the values from right_map, & check if {target = nums[i] * 2} values exist into our both the map or not?

    - Example:

                nums: 8 4 2 8 4
                        right_hash{8:2, 4:2, 2:1}
                        ans = 0
                
                nums[0] = 8:
                        right_hash[nums[0]]--   => right_hash{8:1, 4:2, 2:1}
                        target = nums[0] * 2 = 16
                            if(left_hash.count(target) && right_hash.count(target)) {
                                // false    -> skip
                            }
                        left_hash[nums[0]]++    => left_hash{8:1}


                nums[1] = 4:
                        right_hash[nums[1]]--   => right_hash{8:1, 4:1, 2:1}
                        target = nums[1] * 2 = 8
                            if(left_hash.count(target) && right_hash.count(target)) {
                                // true:
                                ans = ans + (left_hash[target] * right_hash[target]) % mod;
                                ans = 0 + (1 * 1) % mod = 1
                                ans = 1
                            }
                        left_hash[nums[1]]++    => left_hash{8:1, 4:1}

                        
                nums[2] = 2:
                        right_hash[nums[2]]--   => right_hash{8:1, 4:1, 2:0}
                        target = nums[2] * 2 = 4
                            if(left_hash.count(target) && right_hash.count(target)) {
                                // true:
                                ans = ans + (left_hash[target] * right_hash[target]) % mod;
                                ans = 1 + (1 * 1) % mod
                                ans = 1 + 1 = 2
                            }
                        left_hash[nums[2]]++    => left_hash{8:1, 4:1, 2:1}
                        

                nums[3] = 8:
                        right_hash[nums[3]]--   => right_hash{8:0, 4:1, 2:0}
                        target = nums[3] * 2 = 16
                            if(left_hash.count(target) && right_hash.count(target)) {
                                // false
                            }
                        
                        left_hash[nums[3]]++    => left_hash{8:2, 4:1, 2:1}

                nums[4] = 4:
                        right_hash[nums[4]]--   => right_hash{8:0, 4:0, 2:0}
                        target = nums[4] * 2 = 8
                            if(left_hash.count(target) && right_hash.count(target)) {
                                // true:
                                ans = ans + (left_hash[target] * right_hash[target]) % mod;
                                ans = 2 + (1 * 0) % mod
                                ans = 1 + 0 = 2
                            }
                        
                        left_hash[nums[3]]++    => left_hash{8:2, 4:2, 2:1}

    // Complexity:  
        - TC: O(n)
        - SC: O(n)




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Approach: Clean 
class Solution {
private: 
    typedef long long ll;
    int mod = 1e9 + 7;
public:
    int specialTriplets(vector<int>& nums) {

        // Hash all the values of given nums into right_mp
        unordered_map<int, int> right_mp;
        for(auto &num: nums) {
            right_mp[num]++;
        }

        // Now Iterate & hash left_mp values & process the finding:
        int ans = 0;
        unordered_map<int, int> left_mp;
        for(auto &num: nums) {
            right_mp[num]--; 

            // Now Check values in left & right map:
            int left = left_mp[2 * num];
            int right = right_mp[2 * num];
            ans = (ans + (1LL * left * right) % mod) % mod;

            left_mp[num]++;
        }

        return ans;
    }
};


// Efficient Approach:
class Solution {
private: 
    typedef long long ll;
    int mod = 1e9 + 7;
public:
    int specialTriplets(vector<int>& nums) {

        // Hash all the values of given nums into right_mp
        unordered_map<int, ll> right_mp;
        for(auto &num: nums) {
            right_mp[num]++;
        }

        // Now Iterate & hash left_mp values & process the finding:
        int ans = 0;
        unordered_map<int, ll> left_mp;
        for(auto &num: nums) {
            // remove the value from right mp for every num:
            right_mp[num]--; 
            if(right_mp[num] == 0) right_mp.erase(num);

            // Now Check values in left & right map:
            int target = num * 2;  // nums[i]
            if(left_mp.count(target) && right_mp.count(target)) {
                ans = (ans + (1LL * left_mp[target] * right_mp[target]) % mod) % mod;
            }

            left_mp[num]++;
        }

        return ans;
    }
};

// Better Approach: O(n^2)

class Solution {
private:    
    int mod = 1e9 + 7;
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            int target = num * 2;

            // For every {nums[i] * 2} count left & right, & then sums up into our answer..
            // count left:
            int left = 0;
            for(int j = i - 1; j >= 0; j--) {
                if(nums[j] == target) left++;
            }

            // count right:
            int right = 0;
            for(int j = i + 1; j < n; j++) {
                if(nums[j] == target) right++;
            }

            // Calculate answer:
            ans = (ans + (left * right) % mod ) % mod;
        }

        return ans;
    }
};


// BruteForce Approach: O(n^3)
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(nums[i] == nums[j] * 2 && nums[k] == nums[j] * 2) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};