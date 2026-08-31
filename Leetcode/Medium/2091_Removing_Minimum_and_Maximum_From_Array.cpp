/*

//  2091. Removing Minimum and Maximum From Array


//  Problem Statement: 
    - You are given a 0-indexed array of distinct integers nums.
    - There is an element in nums that has the lowest value and an element that has the highest value. We call them the minimum and maximum respectively. Your goal is to remove both these elements from the array.
    - A deletion is defined as either removing an element from the front of the array or removing an element from the back of the array.
    - Return the minimum number of deletions it would take to remove both the minimum and maximum element from the array.

//  Example:

    Example 1:
        Input: nums = [2,10,7,5,4,1,8,6]
        Output: 5
        Explanation: 
        The minimum element in the array is nums[5], which is 1.
        The maximum element in the array is nums[1], which is 10.
        We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
        This results in 2 + 3 = 5 deletions, which is the minimum number possible.

    Example 2:
        Input: nums = [0,-4,19,1,8,-2,-3,5]
        Output: 3
        Explanation: 
        The minimum element in the array is nums[1], which is -4.
        The maximum element in the array is nums[2], which is 19.
        We can remove both the minimum and maximum by removing 3 elements from the front.
        This results in only 3 deletions, which is the minimum number possible.

    Example 3:
        Input: nums = [101]
        Output: 1
        Explanation:  
        There is only one element in the array, which makes it both the minimum and maximum element.
        We can remove it with 1 deletion.


// Observations:
    - Given nums, we have to pick minimum and maximum element from the array.
    - integer in nums are distinct..
    - we will have to remove that from the nums.
        - considering that any element from '0th' index to any min or max should be removed, similarly for land index n
        - we will have to find out the minimum removal..

        // Approach:
            - Find the min and max and max position
            - after that find out the min removal from left or right..
            - First find out the element position:
                - both element is in left, so we will remove till maxPos + 1
                - both element is in right, so we will remove till n - minPos
                - both element are separated in left and right
                    - we will split left and right;
                        (minPos + 1) + (n - maxPos)

                - From all the possibility, we will take min..

        // Complexity:
            - TC: O(n)
            - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 1;
        if(n == 2) return 2;

        // Get min and max El element:
        int minPos = 0;
        int maxPos = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[minPos]) minPos = i;
            if(nums[i] > nums[maxPos]) maxPos = i;
        }

        // make minPos to smaller position:
        if(minPos > maxPos) swap(minPos, maxPos);

        // remove from the left:
        int left = maxPos + 1;

        // remove both from the right:
        int right = n - minPos;

        // remove min From left and max from right:
        int both = (minPos + 1) + (n - maxPos);

        return min({left, right, both});
    }
};