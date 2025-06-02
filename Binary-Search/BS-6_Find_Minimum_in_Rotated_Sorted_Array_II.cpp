/*

//  BS-6: Find Minimum in Rotated Sorted Array II -> Contains Duplicate


//  Problem Statement: 
    -> Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:
        -> [4,5,6,7,0,1,4] if it was rotated 4 times.
        -> [0,1,4,4,5,6,7] if it was rotated 7 times.
    -> Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
    -> Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.
    -> You must decrease the overall operation steps as much as possible.


// Example: 

    Example 1:
        Input: nums = [1,3,5]
        Output: 1

    Example 2:
        Input: nums = [2,2,2,0,1]
        Output: 0


// Observations: 
    -> First thing is we are unaware about the target value, which we have to search
        -> We can search this using Binary Seach for unknown target 
        -> Question: Minimum in Rotated Sorted Array
        -> Solution: https://github.com/sahilwep/DSA-Workspace/blob/main/Binary-Search/BS-6_Minimum_in_Rotated_Sorted_Array.cpp


    -> Then we have to take care of duplicate case
        -> For duplicate case we will handel it by simply shrinking the search space..
        -> Question: Search Element in Rotated Sorted Array II 
        -> Solution: https://github.com/sahilwep/DSA-Workspace/blob/main/Binary-Search/BS-5_Search_Element_in_Rotated_Sorted_Array-II.cpp

    -> By handling these two things we can solve the questions.


// Complexity: 
    -> TC: O(logN)
    -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int low = 0, high = n - 1;
        int target = INT_MAX;


        while(low <= high) {
            int mid = (low + high) / 2;


            // Get target as minimum value among all the three pointer (low, mid, high) & previous findings =>  Unknown Target Finding
            target = min(target, min(nums[low], min(nums[mid], nums[high])));


            // Case where all the pointers (low, mid, high) are same    =>  Handling Duplicate case
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                // trim down search space
                low++;
                high--;
                continue;
            }

            // Check sorted ranges
            if(nums[low] <= nums[mid]) {  // left half is sorted
                // reject the left half:
                low = mid + 1;
            } 
            else {  // right half is sorted:
                // reject the right half
                high = mid - 1;
            }
        }
        
        return target;
    }
};