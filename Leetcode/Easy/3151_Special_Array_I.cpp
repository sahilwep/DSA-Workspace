/*

//  3151. Special Array I


//  Problem Statement: 
    -> An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
    -> You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

// Example:

    Example 1:
        Input: nums = [1]
        Output: true
        Explanation: There is only one element. So the answer is true.

    Example 2:
        Input: nums = [2,1,4]
        Output: true
        Explanation: There is only two pairs: (2,1) and (1,4), and both of them contain numbers with different parity. So the answer is true.

    Example 3:
        Input: nums = [4,3,1,6]
        Output: false
        Explanation: nums[1] and nums[2] are both odd. So the answer is false.


// Complexity:
    -> TC: O(n)
    -> AS: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Approach 1:
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 1) return true;
        
        // First find the starting position parity:
        int startParityEven = 0;
        int startParityOdd = 0;
        if(nums[0] % 2 == 0){
            startParityEven = 0;
            startParityOdd = 1;
        }else{
            startParityOdd = 0;
            startParityEven = 1;
        }
        
        // Now simply check the parity is valid in their position or not?
        int n = nums.size();
        while(startParityEven < n){
            if(nums[startParityEven] % 2 != 0){
                return false;
            }
            startParityEven += 2;
        }
        while(startParityOdd < n){
            if(nums[startParityOdd] % 2 == 0){
                return false;
            }
            startParityOdd += 2;
        }

        return true;
    }
};


// Approach 2:
class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 1) return true;
        for(int i=1;i<nums.size();i++){
            if( nums[i-1] % 2 == 0 && nums[i] % 2 == 0 || nums[i-1] % 2 != 0 && nums[i] % 2 != 0 ){
                return false;
            }
        }
        return true;
    }
};