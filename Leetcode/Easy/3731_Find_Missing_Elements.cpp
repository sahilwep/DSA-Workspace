/*

//  3731. Find Missing Elements


//  Problem Statement: 
    - You are given an integer array nums consisting of unique integers.
    - Originally, nums contained every integer within a certain range. However, some integers might have gone missing from the array.
    - The smallest and largest integers of the original range are still present in nums.
    - Return a sorted list of all the missing integers in this range. If no integers are missing, return an empty list.


// Example:
        Example 1:
            Input: nums = [1,4,2,5]
            Output: [3]
            Explanation: The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. Among these, only 3 is missing.

        Example 2:
            Input: nums = [7,8,6,9]
            Output: []
            Explanation: The smallest integer is 6 and the largest is 9, so the full range is [6,7,8,9]. All integers are already present, so no integer is missing.

        Example 3:
            Input: nums = [5,1]
            Output: [2,3,4]
            Explanation: The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. The missing integers are 2, 3, and 4.

// Observations:
    - We are given an array nums, and some of the numbers in that array are missing.
    - we have to find out the missing number in range of lowest_element to highest_element.

    // Approach:
        - find the max, and min elements from that array.
        - store all the given element in unordered_set
        - run a loop from low to high and find out the missing element by checking inside the unodered set.

    // Complexity:
        - TC: O(n)
        - SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {    // O(n)
        int n = nums.size();

        int low = *min_element(begin(nums), end(nums));
        int high = *max_element(begin(nums), end(nums));

        unordered_set<int> st;
        for(auto &i: nums) st.insert(i);

        vector<int> ans;
        for(int i = low; i <= high; i++) {
            if(!st.count(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};