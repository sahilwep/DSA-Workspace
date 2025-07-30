/*

//  2419. Longest Subarray With Maximum Bitwise AND


//  Problem Statement: 
    -> You are given an integer array nums of size n.
    -> Consider a non-empty subarray from nums that has the maximum possible bitwise AND.
        -> In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
    -> Return the length of the longest such subarray.
    -> The bitwise AND of an array is the bitwise AND of all the numbers in it.
    -> A subarray is a contiguous sequence of elements within an array.

 
// Example: 

    Example 1:
        Input: nums = [1,2,3,3,2,2]
        Output: 2
        Explanation:
        The maximum possible bitwise AND of a subarray is 3.
        The longest subarray with that value is [3,3], so we return 2.

    Example 2:
        Input: nums = [1,2,3,4]
        Output: 1
        Explanation:
        The maximum possible bitwise AND of a subarray is 4.
        The longest subarray with that value is [4], so we return 1.

        

// Observations: 
    -> AND Property: 
        -> maximum AND is the maximum number itself, Because if we take any smaller number AND with maximum number, the value will be decremented.
        -> In simple we need to find the maximum number in an array
        -> Find the contigious occurrence of that maximum number, that will our result.



// Complexity: 
    -> TC: O(N)
    -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Solution: 
class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int maxVal = *max_element(begin(nums), end(nums));  // the maximum AND we can get is the maximum number itself.
        int longest = 0;
        int cnt = 0;

        for(auto& it: nums) {
            if(it == maxVal) {  // if we get contigious maximum value count that & that will be our longest subarray
                cnt++;
                longest = max(longest, cnt);
            } else {
                cnt = 0;
            }
        }

        return longest;
    }
};