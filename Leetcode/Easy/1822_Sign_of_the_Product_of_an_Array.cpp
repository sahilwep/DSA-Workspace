/*

//  1822. Sign of the Product of an Array


//  Problem Statement: 
    -> Implement a function signFunc(x) that returns:
        -> 1 if x is positive.
        -> -1 if x is negative.
        -> 0 if x is equal to 0.
    -> You are given an integer array nums. Let product be the product of all values in the array nums.
    -> Return signFunc(product).

    
 
// Example:
    Example 1:
        Input: nums = [-1,-2,-3,-4,3,2,1]
        Output: 1
        Explanation: The product of all values in the array is 144, and signFunc(144) = 1

    Example 2:
        Input: nums = [1,5,0,2,-3]
        Output: 0
        Explanation: The product of all values in the array is 0, and signFunc(0) = 0

    Example 3:
        Input: nums = [-1,1,-1,1,-1]
        Output: -1
        Explanation: The product of all values in the array is -1, and signFunc(-1) = -1



// Observations: 
    -> Count negative count, if it's even sign is +ve, else sign is -ve
    -> track any '0' occurrence in list, if there's any, return '0'

    // Complexity: 
        -> TC: O(n)
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int negCnt = 0;
        bool isZero = false;
        for(auto &it: nums) {
            if(it < 0) negCnt++;
            if(it == 0) isZero = true;
        }

        if(isZero) return 0;

        return (negCnt % 2 != 0) ? -1 : 1;
    }
};