/*

//  2762. Continuous Subarrays


//  Problem Statement: 
    * You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:
    * Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
    * Return the total number of continuous subarrays.
    * A subarray is a contiguous non-empty sequence of elements within an array.


// Example:

    Example 1:
        Input: nums = [5,4,2,4]
        Output: 8
        Explanation: 
        Continuous subarray of size 1: [5], [4], [2], [4].
        Continuous subarray of size 2: [5,4], [4,2], [2,4].
        Continuous subarray of size 3: [4,2,4].
        Thereare no subarrys of size 4.
        Total continuous subarrays = 4 + 3 + 1 = 8.
        It can be shown that there are no more continuous subarrays.

    Example 2:
        Input: nums = [1,2,3]
        Output: 6
        Explanation: 
        Continuous subarray of size 1: [1], [2], [3].
        Continuous subarray of size 2: [1,2], [2,3].
        Continuous subarray of size 3: [1,2,3].
        Total continuous subarrays = 3 + 2 + 1 = 6.


// Approach:

    1. Identifying the Problem Type:
    - This is a subarray-based problem, which can be efficiently solved using the sliding window technique.

    2. Counting Subarrays:
    - To count the number of subarrays, consider the following examples:
        - When there is one element:
            {1} -> Subarrays: {1}
            Total count = 1
        - When there are two elements:
            {1, 2} -> Subarrays: {1, 2}, {2}
            Total count = 2
        - When there are three elements:
            {1, 2, 3} -> Subarrays: {1, 2, 3}, {2, 3}, {3}
            Total count = 3
        - In general, for any subarray defined by indices i and j, the total number of subarrays ending at j is given by: Count = j - i + 1

    3. Checking for Continuity of Subarrays:
    - To verify whether a subarray is continuous, we need to check the absolute difference between the largest and smallest elements in the subarray.
    - If this absolute difference exceeds the given range (e.g. abs({largest} - {smallest}) <= 2), the subarray is invalid.
        
        Example:
        - Consider the array {2, 1, 2, 4}:
        - Subarray {1, 4} is invalid because the difference between the largest (4) and smallest (1) is |4 - 1| = 3, which exceeds the range.
    - Thus, for a valid subarray, the largest and smallest difference must satisfy:
        abs({largest} - {smallest}) <= 2

    4. Handling Invalid Subarrays:
    - If the condition abs({largest} - {smallest}) <= 2 is violated, increment the `i` pointer (shrink the window from the left) until the condition is restored.

    5. Challenge of Tracking Largest and Smallest Elements:
    - Removing elements while moving the `i` pointer can lead to loss of information about the largest or smallest element in the current window.
    - To handle this efficiently, we use a data structure that:
        - Maintains the order of elements.
        - Supports duplicates by tracking frequencies.

    6. Data Structure Selection:
    - An ordered map is used:
        - Keys represent the elements of the array.
        - Values store the frequency of each element.
        - The smallest and largest keys in the map can be accessed as:
        - Smallest: mp.begin()->first
        - Largest: mp.rbegin()->first

// Complexity:
    -> TC: O(n)
        -> Map size never be more than 3
        -> because of the condition given & using of while loop.
    -> AS: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        // Ordered map to track frequency of elements in the current window
        map<int, int> mp;
        int i = 0, j = 0;

        while (j < n) {
            mp[nums[j]]++;  // Add the current element to the map

            // If the absolute difference between max and min exceeds 2:
            while (abs(mp.rbegin()->first - mp.begin()->first) > 2) {
                mp[nums[i]] -= 1;           // Decrease the frequency of the element at index `i`
                if (mp[nums[i]] == 0) {     // If the frequency becomes 0:
                    mp.erase(nums[i]);      // Remove the element from the map
                }
                i++;  // Shrink the window from the left
            }

            // Count the subarrays ending at index `j`
            ans += j - i + 1;

            j++;  // Expand the window to the right
        }

        return ans;
    }
};
