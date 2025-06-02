/*

//  BS-8. Single Element in Sorted Array

//  Problem Statement: 
    -> You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
    -> Return the single element that appears only once.
    -> Your solution must run in O(log n) time and O(1) space.

 
// Example:
    Example 1:
        Input: nums = [1,1,2,3,3,4,4,8,8]
        Output: 2

    Example 2:
        Input: nums = [3,3,7,7,10,11,11]
        Output: 10



// Observations: 
    -> Given sorted array where every element appear in pairs except one.
    -> return the element which appears only once in array.
    -> Try Building the solution with Complexity O(logN)

        1  1  2  3  3  4  4  8  8 
        |           |           |
        low         mid         high


        well single element always appears in odd cnt which is 1
        and in pairs it's always appears in even sizes:

        // Example: 

        0  1  2  3  4  5  6  7  8
        1  1  2  2  3  3  5  8  8 
        |           |           |
        low         mid         high


        (1, 1)     (2, 2)    (3, 3)     (5)     (8, 8)
         |  |      |   |      |   |      |      |   |
       even odd   even odd   even odd   even   odd even     -> index


        -> If we are standing on even & on the right if same element => We are on left half of single element
        -> If we are standing on odd & on the right if same element => we are on right half of the single element.


        (even - odd) we are at leftHalf => our element is on rightHalf.
        (odd - even) we are at rightHalf => our element is on leftHalf.

                1  1  2  2  3  3  [5]  8  8 
                                   |
                                Single Element

                        Both left right is not equal, we can say it's the single element


    // Edge case: 
        -> if nums.size() == 1 => nums[0] is our answer

        -> Also for starting & ending we will have to write additional edge case inside the BS, 
            -> Solution to that is trim down the seach space & saperately check the first & last element.
            -> Start with (low = 1) & (end = n - 2)
            -> Handel nums[0] & nums[n-1] saperately.


// Complexity: 
    -> TC: O(logN)
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // edge cases:
        if(n == 1) return nums[0];  // single element
        if(nums[0] != nums[1]) return nums[0];   // first element
        if(nums[n-1] != nums[n-2]) return nums[n-1];    // last element

        int low = 1, high = n - 2;
        int ans = -1;

        while(low <= high) {
            int mid = (low + high) / 2;

            // Single element Check => [mid-1] != [mid] != [mid+1]
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]) {
                ans = nums[mid];   // single element
                break;
            }

        
            // (even - odd) we are at leftHalf => our element is on rightHalf.
            if(mid % 2 != 0 && nums[mid-1] == nums[mid] || mid % 2 == 0 && nums[mid] == nums[mid + 1]) { 
                low = mid + 1;  // moving to right side
            }
            // (odd - even) we are at rightHalf => our element is on leftHalf.
            else if(mid % 2 == 0 && nums[mid-1] == nums[mid] || mid % 2 != 0 && nums[mid+1] == nums[mid]){
                high = mid - 1;
            }
        }
        
        return ans;  // no such element present
    }
};