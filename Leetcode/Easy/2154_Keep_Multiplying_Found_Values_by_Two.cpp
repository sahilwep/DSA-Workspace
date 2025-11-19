/*

//  2154. Keep Multiplying Found Values by Two


//  Problem Statement: 
    - You are given an array of integers nums. You are also given an integer original which is the first number that needs to be searched for in nums.
    - You then do the following steps:
        - If original is found in nums, multiply it by two (i.e., set original = 2 * original).
        - Otherwise, stop the process.
        - Repeat this process with the new number as long as you keep finding the number.
    - Return the final value of original.

 
// Example: 
    Example 1:
        Input: nums = [5,3,6,1,12], original = 3
        Output: 24
        Explanation: 
        - 3 is found in nums. 3 is multiplied by 2 to obtain 6.
        - 6 is found in nums. 6 is multiplied by 2 to obtain 12.
        - 12 is found in nums. 12 is multiplied by 2 to obtain 24.
        - 24 is not found in nums. Thus, 24 is returned.

    Example 2:
        Input: nums = [2,7,9], original = 4
        Output: 4
        Explanation:
        - 4 is not found in nums. Thus, 4 is returned.

// Observations:
    - From the original value, we will keep multiplying it by 2, & trying finding the value inside the nums.
    - we need to return the last not found value...

    // BruteForce:
        - Every time multiply by 2 & find in nums.

        // Complexity:  
            - TC: O(n^2)
            - SC: O(1)

    // Optimizations: 
        - Use set for lookup, which will take O(1) complexity.

        // Complexity:  
            - TC: O(n)
            - SC: O(1)




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Bruteforce Solution: 
class Solution {
private: 
    bool isFound(vector<int> &nums, int x) {
        for(auto &it: nums) if(it == x) return true;
        return false;
    }
public:
    int findFinalValue(vector<int>& nums, int original) {
        
        int val = original;
        while(isFound(nums, val)) {
            val *= 2;
        }

        return val;
    }
};

// Optimal Solution: 
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        
        unordered_set<int> st;
        for(auto &it: nums) {
            st.insert(it);
        }

        int val = original;
        while(st.find(val) != st.end()) {   // at worse case TC: O(n) 
            val *= 2;
        }

        return val;
    }
};