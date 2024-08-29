/*

// 283. Move Zeroes


// Observations: 
    * we are given an array that contains some zeroes in it, we need to remove all the zeroes from an array..
    * We need to return the new array size, which doesn't contains 0 in it.


// Intrusion: 
    // Bruteforce Approach: 
        * We can use auxilary array that can store only unique element, & then we can update the original array with non-zeros values.
        * TC: O(n)
        * AS: O(n)
    // Efficient Approach: 
        * We can use two pointer approach, & store only non-zeroes value..
            * first pointer will maintain the index of non-zeroes values
            * Second pointer will iterate over an array & compare values with first pointer.
        * TC: O(n)
        * AS: O(1)
        // Example Observations: 
            [0,1,0,3,12]    ptr = 0;

                if(arr[i] != 0){
                    arr[ptr] = nums[i]
                }

            i = 0       
                    arr[] = [0, 1, 0, 3, 12], ptr = 0
                    if(arr[i] != 0) -> false
            i = 1       
                    arr[] = [0, 1, 0, 3, 12], ptr = 0
                    if(arr[i] != 0) true
                        arr[] = [1, 1, 0, 3, 12], ptr = 1
            i = 2       
                    arr[] = [1, 1, 0, 3, 12], ptr = 1
                    if(arr[i] != 0) false
            i = 3      
                    arr[] = [1, 1, 0, 3, 12], ptr = 1
                    if(arr[i] != 0) true
                        arr[] = [1, 3, 0, 3, 12], ptr = 2
            i = 4
                    arr[] = [1, 3, 0, 3, 12], ptr = 2
                    if(arr[i] != 0) true
                        arr[] = [1, 3, 12, 3, 12], ptr = 3

            * Now, we will iterate from ptr -> nums.size() & put all the values to 0




*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // BruteForce Solution: 
    void moveZeroes_Brute(vector<int>& nums) {
        vector<int> v;  // creating auxilary array to store non-zeroes values.
        // storing non-zeroes value
        for(auto i : nums){
            if(i != 0){
                v.push_back(i);
            }
        }
        // putting non-zeroes values in nums
        int i;
        for(i=0;i<v.size();i++){
            nums[i] = v[i];
        }
        // putting rest values as 0
        for(int j=i;j<nums.size();j++){
            nums[j] = 0;
        }
    }

    // Efficient Approach: 
    void moveZeroes(vector<int> &nums){
        int ptr = 0;    // first pointer, this will contains the index of non-zeroes values.
        for(int i=0;i<nums.size();i++){
            // if array element is not equal to 0
            if(nums[i] != 0){
                nums[ptr] = nums[i];    // putting that values in pointer position.
                ptr++;  // increment the pointer position.
            }
        }
        // last putting the rest index as 0
        for(int i=ptr;i<nums.size();i++){
            nums[i] = 0;
        }
    }
};