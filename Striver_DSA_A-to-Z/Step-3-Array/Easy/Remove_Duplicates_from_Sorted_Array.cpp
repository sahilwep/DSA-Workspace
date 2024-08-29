/*

// Remove Duplicates from Sorted Array


// Observations: 
    * given an integer array nums sorted in non-descending order. remove the duplicates in the place, such that each unique element appears only once.
    * The relative order of the element should keep the same.
    * Then return the number of duplicate element in nums.

// Intrusion: 
    // Two pointer approach:
        * We will compare two adjacent element, because array is sorted, & duplicate values will exist adjacent to each other.
        * We will use two pointer approach: 
            * First pointer will act as index of unique elements..
                * Whenever we found a unique element while iterating, we will store that element into this pointer position.
            * Second pointer will iterate throughout the array,
                * We will use this pointer to iterate over an array, & with this pointer we will compare with previously store element.
        * Complexity:
            * TC: O(n)
            * SC: O(1)

    // Using set data Structure:
        * We can use set data-structure which stores the unique element.
        * TC: O(nlogn)
        * AS: O(n)


// Example Observations:
        arr[] = [1,1,2,2,3,3,4,4], n = 8
        ptr1 = 0

        iterate (1 -> 8)
            if(arr[i] != arr[ptr]){
                ptr++
                arr[ptr] = arr[i]
            }

        i = 1 ->  arr[] = [1,1,2,2,3,3,4,4], ptr = 0
                             ^
                        if(arr[1] != arr[0]) -> not executes
                        

        i = 2 ->  arr[] = [1,1,2,2,3,3,4,4], ptr = 0
                               ^
                        if(arr[2] != arr[0]){
                            ptr++
                            arr[1] = arr[2]
                        }
                            -> arr[] = [1,2,2,2,3,3,4,4]


        i = 3 ->  arr[] = [1,2,2,2,3,3,4,4], ptr = 1
                                 ^
                        if(arr[3] != arr[1])    -> not executes


        i = 4 ->  arr[] = [1,2,2,2,3,3,4,4], ptr = 1
                                   ^
                        if(arr[4] != arr[1]){
                            ptr++
                            arr[2] = arr[4]
                        }
                            -> arr[] = [1,2,3,2,3,3,4,4]


        i = 5 -> arr[] = [1,2,3,2,3,3,4,4], ptr = 2
                                    ^
                        if(arr[5] != arr[2])    -> not executes


        i = 6 -> arr[] = [1,2,3,2,3,3,4,4], ptr = 2
                                      ^
                        if(arr[6] != arr[2]){
                            ptr++
                            arr[3] = arr[6]
                        }
                            -> arr[] = [1,2,3,4,3,3,4,4]

        i = 7 -> arr[] = [1,2,3,4,3,3,4,4], ptr = 3
                                        ^
                        if(arr[5] != arr[2])    -> not executes


        * At Last We will return the pointer ptr.



*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Using two pointer
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;   // if array has no element, there is no duplicates
        if(n == 1) return 1;   // if array contains single element, there is no duplicates
        
        int ptr1 = 0;   // pointer 1: this will use as index of unique elements
        for(int i=1;i<n;i++){   // pointer 2 is loop 'i', which is used to compare the elements with previously stored index elements.
            // if current element is not same with previously sorted element, we will store that element.
            if(nums[i] != nums[ptr1]){
                ptr1++; // increment the counter of storing unique element position.
                nums[ptr1] = nums[i];   // storing the element.
            }
        }

        return ptr1+1;  // returning the size of unique elements  ((ptr1 + 1), because we have compute index from 0, & answer is counting index is from 1)
    }

    // Approach 2: Using set data-structure
    int removeDuplicates_Using_Set_DS(vector<int>& nums) {
        set<int> s; // using set DS
        for(auto i : nums) s.insert(i); // insert will take O(logn)
        int k = 0;
        for(auto i: s){
            nums[k++] = i;
        }
        return s.size();
    }
};