/*

// 268. Missing Number

// Observations: 
    * Given an array of size n containing distinct integer, range from (0-n)
    * return only number in the range that is missing from the range.

// Key Observations: 
    * As we are bound that values are from range (0-n)


// Intrusion: 

    // Approach 1: Using sorting
        * Sort the array, then iterate & find the missing value.
        * TC: O(nlogn)
        * AS: O(1)


    // Approach 2: Using Hashing
        * Create an hash array with default value 0, with size (n+1), because values start from 0 & goes till n,
        * Iterate in given array, & hash each element of hash array
        * Last find the frequency with 0, that will be our missing value.
        * TC: O(n)
        * AC: O(n)


*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Using Sorting-> O(nlogn)
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i] != i){
                return i;
            }
        }
        return nums.size(); // this will executes when all the element of nums are found, & last n element is missing.
    }


    // Approach 2: Using hashing -> O(n)
    int missingNumber(vector<int>& nums) {
        int n = nums.size();    // size of given array
        vector<int> v(n+1, 0);  // create hash array of size n+1

        // hashing all the value of nums into nums
        for(int i=0;i<n;i++){
            v[nums[i]]++;
        }
        
        // finding the missing values:
        int missing = -1;
        for(int i=0;i<v.size();i++){
            // missing value have frequency 0
            if(v[i] == 0){
                missing = i;
                break;
            }
        }

        return missing;
    }
};