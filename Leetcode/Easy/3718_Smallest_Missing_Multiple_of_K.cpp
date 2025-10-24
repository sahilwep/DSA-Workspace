/*

//  3718. Smallest Missing Multiple of K


//  Problem Statement: 
    -> Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.
    -> A multiple of k is any positive integer divisible by k.


// Example:
    Example 1:
        Input: nums = [8,2,3,4,6], k = 2
        Output: 10
        Explanation:
        The multiples of k = 2 are 2, 4, 6, 8, 10, 12... and the smallest multiple missing from nums is 10.

    Example 2:
        Input: nums = [1,4,7,10,15], k = 5
        Output: 5
        Explanation:
        The multiples of k = 5 are 5, 10, 15, 20... and the smallest multiple missing from nums is 5.


// Complexity: 
    -> TC: O(n)
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) { // TC: O(n + 100/k) == O(n)
        
        // use Unordered set to get all the unique numbers
        unordered_set<int> st;
        for(auto &it: nums) {   // TC: O(n)
            st.insert(it);
        }

        // Find the smallest multiple of k
        int i = k;
        for(; i <= 100; i += k) {   // TC: O(100/k)
            if(!st.count(i)) return i;  // TC: O(1)
        }

        return i;   // else return last range
    }
};