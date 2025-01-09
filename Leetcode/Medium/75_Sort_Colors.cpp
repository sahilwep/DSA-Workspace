/*

//  75. Sort Colors

//  Problem Statement: 
    -> Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
    -> We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
    -> You must solve this problem without using the library's sort function.

//  Example:

    Example 1:
        Input: nums = [2,0,2,1,1,0]
        Output: [0,0,1,1,2,2]

    Example 2:
        Input: nums = [2,0,1]
        Output: [0,1,2]


// BruteForce: 
    -> Use nested loop Solve this problem
    -> TC: O(n^2)

// Sorting: 
    -> TC: O(n*log(n))

// Hashing:
    -> We can sort this using map
    -> TC: O(n*log(n))

// Count Sorting: 
    -> array is bound to have 3 values only.
    -> Store the frequency of every element
    -> last assign the numbers frequency times.
    -> TC: O(n)

// Dutch national flag algorithm
    ->  Problem: https://en.wikipedia.org/wiki/Dutch_national_flag_problem
    -> This problem says we are given 3 balls & we have to sort them.
    -> We will sort them by using 3 pointer low, mid & high
        -> Run loop while(mid <= high):
            -> when (nums[mid] == 0) => swap(nums[low], nums[mid]), low++, mid++;
            -> when (nums[mid] == 1) => mid++;
            -> when (nums[mid] == 2) => swap(nums[mid], nums[high]), high--;

    -> TC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Dutch national flag algorithm: TC: O(n)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};


// Efficient: O(n)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0) zero++;
            else if(nums[i] == 1) one++;
            else two++;
        }

        int k = 0;
        while(zero > 0){
            nums[k++] = 0;
            zero--;
        }
        while(one > 0){
            nums[k++] = 1;
            one--;
        }
        while(two > 0){
            nums[k++] = 2;
            two--;
        }
    }
};


// Hashing: O(n*log(n))
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> mp;
        for(auto i: nums) mp[i]++;

        int k = 0;
        for(auto i: mp){
            int element = i.first;
            for(int j=0;j<i.second;j++){
                nums[k++] = i.first;
            }
        }
    }
};

// Sorting: TC: O(n*log(n))
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(begin(nums), end(nums));
    }
};

// BruteForce Method:
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                }
            }
        }

    }
};