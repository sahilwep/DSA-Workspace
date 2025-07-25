/*


//  3487. Maximum Unique Subarray Sum After Deletion


//  Problem Statement: 
    -> You are given an integer array nums.
    -> You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, select a of nums such that:
        -> All elements in the subarray are unique.
        -> The sum of the elements in the subarray is maximized.
    -> Return the maximum sum of such a subarray.


 
// Example: 
    Example 1:
        Input: nums = [1,2,3,4,5]
        Output: 15
        Explanation: Select the entire array without deleting any element to obtain the maximum sum.

    Example 2:

        Input: nums = [1,1,0,1,1]
        Output: 1
        Explanation: Delete the element nums[0] == 1, nums[1] == 1, nums[2] == 0, and nums[3] == 1. Select the entire array [1] to obtain the maximum sum.

    Example 3:

        Input: nums = [1,2,-1,-2,1,0,-1]
        Output: 3
        Explanation: Delete the elements nums[2] == -1 and nums[3] == -2, and select the subarray [2, 1] from [1, 2, 1, 0, -1] to obtain the maximum sum.

 

// BruteForce Solution: 
    -> Given integer array
    -> find the maximum unique subarray sum after deletions..
        -> all elements should be unique
        -> sum of the elements should be maximized..
        -> return the maximum sum of such a subarray.


    // BruteForce Approach: 
        -> get the element
        -> find the unique element found or not?
            -> check in whole array without it's original index..
        -> Skip the negative numbers

        // Complexity: 
            -> TC: O(n^2)
            -> SC: O()



    // Optimizations: 
        -> Checking unique elements can be optimized using hashmap..
        -> rest are same..

        // Complexity: 
            -> TC: O(N)
            -> SC: O(N)


*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Optimized:
class Solution {
private: 
    int getMinNegVal(vector<int>& nums) {
        bool isAllNeg = true;
        int maxNeg = nums[0];
        
        for(auto& it: nums) {
            if(it >= 0) isAllNeg = false;
            maxNeg = max(it, maxNeg);
        }

        if(!isAllNeg) return 0;
        return maxNeg;
    }
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();

        // Edge case: if single elements is there, we don't have any choices..
        if(n == 1) return nums[0];
        
        // Check all negative: 
        int val = getMinNegVal(nums);
        if(val != 0) return val;

        // Using Set to check duplicates: 
        int sum = 0;
        unordered_set<int> st;
        for(auto& it: nums) {
            if(it <= 0) continue;   // skip negative values
            
            if(!st.count(it)) {
                sum += it;
                st.insert(it);
            }
        }
        
        return sum;
    }
};



// Bruteforce: 
class Solution {
private: 
    int getMinNegVal(vector<int>& nums) {
        bool isAllNeg = true;
        int maxNeg = nums[0];
        
        for(auto& it: nums) {
            if(it >= 0) isAllNeg = false;
            maxNeg = max(it, maxNeg);
        }

        if(!isAllNeg) return 0;
        return maxNeg;
    }
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();

        // Edge case: if single elements is there, we don't have any choices..
        if(n == 1) return nums[0];
        
        // Check all negative: 
        int val = getMinNegVal(nums);
        if(val != 0) return val;


        // Rest case: 
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] <= 0) continue;   // skip that negative iterations

            // Find duplicate: 
            bool isDupFind = false;
            for(int j = 0; j < n; j++) {
                if(i != j && nums[i] == nums[j]) {    // skipping the original index where we are at.
                    isDupFind = true;
                    break;
                }
            }

            // Final check:
            if(!isDupFind) {
                sum += nums[i];
            } else {
                // Fist time we are finding duplicate elements:
                sum += nums[i]; // include that into sum
                // Now overwrite that number, with '0'
                int temp = nums[i];
                for(int j = 0; j < n; j++) {
                    if(nums[j] == temp) nums[j] = 0;
                }
            }
        }
        
        return sum;
    }
};

