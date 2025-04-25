/*

//  2799. Count Complete Subarrays in an Array


//  Problem Statement: 
    -> You are given an array nums consisting of positive integers.
    -> We call a subarray of an array complete if the following condition is satisfied:
        -> The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
    -> Return the number of complete subarrays.
    -> A subarray is a contiguous non-empty part of an array.

 
// Example: 
    Example 1:
        Input: nums = [1,3,1,2,2]
        Output: 4
        Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].

    Example 2:
        Input: nums = [5,5,5,5]
        Output: 10
        Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.

 
// Observations: 
    -> Given nums >= 0
    -> Complete subarray: 
        -> Number of distinct element in subarray is equal to the number of distinct element in the whole array.
    
    -> Return the number of complete subarray.

    // Bruteforce Approach:

        Input: nums = [1,3,1,2,2]
        Output: 4
        Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].


            [1,3,1,2,2]

                -> Number of distinct element in subarray is equal to the number of distinct element in the whole array.

                -> First find the distinct element in array: 
                    = 3

                -> Now try forming subarray that contains 3 atleast unique element: 
                    [1,3,1,2,2]
                     | 
                     ij

                    [1,3,1,2,2]
                     | |
                     i j


                    [1,3,1,2,2]
                     |   |
                     i   j


                    [1,3,1,2,2]
                     |     |        -> +1
                     i     j




                    [1,3,1,2,2]
                     |       |        -> +2
                     i       j



                                [1,3,1,2,2]
                                   |   |        -> +1
                                   i   j


                                [1,3,1,2,2]
                                 |       |        -> +1 
                                 i       j



                    [1,3,1,2,2]
                       |     |        -> +1
                       i     j



        -> Now try forming subarray that contains 3 atleast unique element: 
                    [1,3,1,2,2,2,2,2]
                     | 
                     ij

                    [1,3,1,2,2,2,2,2]
                     | |
                     i j


                    [1,3,1,2,2,2,2,2]
                     |   |
                     i   j


                    [1,3,1,2,2,2,2,2]
                     |     |                -> +1
                     i     j


                    [1,3,1,2,2,2,2,2]
                     |       |              -> +1
                     i       j
 

                    [1,3,1,2,2,2,2,2]
                     |         |            -> +1
                     i         j


                    [1,3,1,2,2,2,2,2]
                     |           |          -> +1
                     i           j


                    [1,3,1,2,2,2,2,2]
                     |             |        -> +1
                     i             j


                    [1,3,1,2,2,2,2,2]
                       |           |        -> +1
                       i           j


                    [1,3,1,2,2,2,2,2]
                       |         |          -> +1
                       i         j


                    [1,3,1,2,2,2,2,2]
                       |       |            -> +1
                       i       j


                    [1,3,1,2,2,2,2,2]
                       |     |              -> +1
                       i     j

                    [1,3,1,2,2,2,2,2]
                       |   |                -> +1
                       i   j


                -> Total = 10

// Complexity: 
    -> TC: O(n^2)
    -> SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        // First count the total number of unique element in an array: 
        unordered_set<int> unique;
        for(auto &it: nums) unique.insert(it);
        
        int uniq = unique.size();   // total number of unique element: 

        // Use map to store unique element: 
        int subArray = 0;
        for(int i = 0; i < n; i++) {
            set<int> st;    // set used to form new subarray of uniq size every time
            for(int j = i; j < n; j++) {
                st.insert(nums[j]);
                if(st.size() == uniq) { // count subarray every time.
                    subArray++;
                }
            }
        }

        return subArray;
    }
};