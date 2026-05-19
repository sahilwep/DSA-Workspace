/*

//  2540. Minimum Common Value


//  Problem Statement: 
    - Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
    - Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.

 
// Example:
    Example 1:
        Input: nums1 = [1,2,3], nums2 = [2,4]
        Output: 2
        Explanation: The smallest element common to both arrays is 2, so we return 2.

    Example 2:
        Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
        Output: 2
        Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is returned.

 
// Observations:
    - Given are given two sorted array, we need to find the minimum element found on both the array.

    // Approach 1: 
        - We can use hashing approach to solve this problem.
        - We can use set to store all the elements from the first array, and then hash the second array, and the first common element will be our min-element.
        
        // Complexity:
            - TC: O(n + m)
            - SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        // Hash all the elements from num1 into set.
        unordered_set<int> st;
        for(auto &num: nums1) {
            st.insert(num);
        }

        // iterate into num2, and check if any element found in set, return immidetialy if found common element.
        for(auto &num: nums2) {
            if(st.count(num)) {
                return num;
            }
        }

        return -1;  // else return -1
    }
};