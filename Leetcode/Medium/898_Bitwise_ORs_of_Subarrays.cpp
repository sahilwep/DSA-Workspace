/*

//  898. Bitwise ORs of Subarrays


//  Problem Statement: 
    -> Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
    -> The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.
    -> A subarray is a contiguous non-empty sequence of elements within an array.


// Example: 
    Example 1:
        Input: arr = [0]
        Output: 1
        Explanation: There is only one possible result: 0.

    Example 2:
        Input: arr = [1,1,2]
        Output: 3
        Explanation: The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
        These yield the results 1, 1, 2, 1, 3, 3.
        There are 3 unique values, so the answer is 3.

    Example 3:
        Input: arr = [1,2,4]
        Output: 6
        Explanation: The possible results are 1, 2, 3, 4, 6, and 7.
        

// Observations: 
    -> Given nums of positive integer
    -> We need to all the possible subarray & compute OR of them
    -> We need to return all the unique OR of subarray.

    // BruteForce:       
        -> Use nested loop to generate all possible subarray.
        -> Generate all the possible subarray & store their OR result, & find the total number of unique OR results on all possible OR's

        // Complexity:
            -> TC: O(n)
            -> SC: O(1)


    // Efficient Solution: 
        ->




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Solution: 


// Bruteforce Solution: 
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            int temp = 0;
            for(int j = i; j < n; j++) {
                temp |= nums[j];
                
                st.insert(temp);
            }
        }

        return st.size();
    }
};
