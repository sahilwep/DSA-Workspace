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

    // Approach 2: 
        - As the values are sorted, so we can solve this without using any auxilary space.
        - We can use two iterators, that iterate in both the array.
        - If the values are equal then we can return immediate, as it's the minimum-common value.
        - else we will move the pointer by comparing both the values.

        // Complexity:
            - TC: O(n + m)
            - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Approach 2:
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(nums1[i] == nums2[j]) {  // If values are equal, return immediately as it's the minimum common value.
                return nums1[i];
            }

            // move the smaller pointer forward, to get equal value, if there's any.
            if(nums1[i] < nums2[j]) i++;
            else j++;
        }

        return -1;  // else return invalid.
    }
};

// Approach 1:
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