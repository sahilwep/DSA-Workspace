/*

//  2529. Maximum Count of Positive Integer and Negative Integer


//  Problem Statement: 
    -> Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.
    -> In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
    -> Note that 0 is neither positive nor negative.

 

// Example: 
    Example 1:
        Input: nums = [-2,-1,-1,1,2,3]
        Output: 3
        Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.

    Example 2:
        Input: nums = [-3,-2,-1,0,0,1,2]
        Output: 3
        Explanation: There are 2 positive integers and 3 negative integers. The maximum count among them is 3.

    Example 3:
        Input: nums = [5,20,66,1314]
        Output: 4
        Explanation: There are 4 positive integers and 0 negative integers. The maximum count among them is 4.


// Approach: 
    -> NOTE: '0' is not counted in positive or negative..
    -> Count positive & negative & return maximum among them.

    // Complexity:
        -> TC: O(n)
        -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Solution: O(n)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int negCnt = 0, posCnt = 0;
        for(auto &it: nums) {
            if(it == 0) continue;
            else if(it > 0) posCnt++;
            else negCnt++;
        }

        return max(negCnt, posCnt);
    }
};
