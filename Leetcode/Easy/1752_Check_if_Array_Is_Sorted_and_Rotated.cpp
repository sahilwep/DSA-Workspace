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
    -> We have to find whether the array is sorted and rotated or not?
        -> Rotations can be '0' times, means nothing will be changed..
        -> And sorted in non-increasing order, means ascending order.
        -> if we observe the question carefully, if Array is rotated once, twice, thrice or any number of times the increasing sequence change at max only once.
        -> Because if array is sorted, then there will only be one time when the increasing sequence will change.
        -> But if the increasing order changed more than once, we can say that array is not sorted.
        -> In simple we can check the aray and if we got the change only once, we can say array is rotated & sorted, if more than that, then we can say the given conditions are not valid.
        -> We can use any counter variable that will count the change in sequence..
        -> Edge Case: if array is sorted, but rotated by '0', then the sequence will not be changed..
            -> So, after checking the above conditions, we will check the if array[0] < arrray[array.size()-1], then we will increase the counter..

        -> At last, when everything is done, we will return true if count is less or equal to (<= 1), 
        -> because of the case throughout the duplicate elements, because in that case, counter will never be increased.



// Complexity: 
    * TC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        
        int cnt = 0;
        for(int i=1;i<n;i++){   
            if(nums[i] < nums[i-1]){
                cnt++;
            }
        }
        
        // If someone has made '0' rotations:
        if(nums[0] < nums[n-1]){
            cnt++;
        }

        return (cnt <= 1);  // for any number of rotations, we at-max have only one smaller value if the array is sorted.
    }
};