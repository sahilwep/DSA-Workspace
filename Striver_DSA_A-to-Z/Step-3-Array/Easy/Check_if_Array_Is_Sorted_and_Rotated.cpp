/*

// 1752. Check if Array Is Sorted and Rotated

// Observations: 
    * We are given an array of size n. return true if array was originally sorted in non-decreasing order, than rotate some of it's position(including zero), otherwise return false.
    * Non-decreasing order -> ascending order
    * There may be duplicate in an array:

// Example

    Input: nums = [3,4,5,1,2]
    Output: true
        Explanation: [1,2,3,4,5] is the original sorted array.
        You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].

    Input: nums = [2,1,3,4]
    Output: false
        Explanation: There is no sorted array once rotated that can make nums.

    Input: nums = [1,2,3]
    Output: true
        Explanation: [1,2,3] is the original sorted array.
        You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.

// Intrusion: 
    * We have to find how many time the array is breaking the ascending order, if it's breaking just once, means array was sorted, otherwise return false.
    * we have to find how many times array was breaking the ascending order.
    * after getting the counter of ascending order breaking how many times, we can compare the first & last element,
        * If last element is grater than the first element, we will increment the counter.
        * Because, as we have given the edge case we can rotate the (array by position 0) : rotate some of it's position(including zero)


// Note: 
    * Edge case: 
        * We have to count the steps of rotation for 0 position -> because this is also one of the count where the array can be rotated by 0 position.
        * After this we can count by checking the condition, for ascendingBreakCount...
        * When array contains duplicate values throughout the array, then we will return 1.
            * Because it can be rotated by 0 position.


// Complexity: 
    * TC: O(n)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ascendingBreakCount(vector<int>& nums){
        int cnt = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] < nums[i-1]){
                cnt++;
            }
        }
        return cnt;
    }
    bool check(vector<int>& nums) {
        // getting the count how many times the ascending order is breaking.
        int cnt = ascendingBreakCount(nums);

        // comparing the fist & last element, as given condition that array can be rotate some of it's position(including zero).
        if(nums[0]  < nums[nums.size()-1]) cnt++;

        // Condition when counter is less than 1, means there is counter violations, non of the condition executes -> array contains duplicate values.
        if(cnt <= 1) return 1;

        // else return 1
        return 0;
    }
};