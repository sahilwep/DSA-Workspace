/*

//  645. Set Mismatch


//  Problem Statement: 
    - You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
    - You are given an integer array nums representing the data status of this set after the error.
    - Find the number that occurs twice and the number that is missing and return them in the form of an array.

 
// Example:
    Example 1:
        Input: nums = [1,2,2,4]
        Output: [2,3]

    Example 2:
        Input: nums = [1,1]
        Output: [1,2]


// Efficient Solution:
    - We can use something like Freq vector & hash all the values from 1 to n
    - Then we check which value is missing & repeated.
    - We can return that:
    
    // Complexity:
        - TC: O(n)
        - SC: O(n)


// Maths Based Solution For only Sorted Values:
    for 1 to n Ideal Sum is:
        ideal sum: 1+2+3+4 = 10     OR (n * (n + 1))/2


    Let say we have [1, 2, 2, 4]:
        for given: 
            currSum = 1+2+2+4 = 9
            IdealSum = 10  
            dup = 2 
            (currSum < idealSum) {
                extra = idealSum % currSum
                extra = 10 % 9 = 1
                missing = dup + extra
                return (dup, missing)
            }

    Let say we have [1, 2, 4, 4]:
        for given:
            currSum = 1+2+4+4 = 11
            IdealSum = 10
            dup = 4
            (currSum > idealSum) {
                extra = currSum % idealSum = 11 % 10 = 1
                missing = dup - extra = 4 - 1 = 3
                return (dup, missing)
            }
    -> This Works only if we have sorted values:



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Freq Based Solution:
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(n + 1, 0);
        for(auto &it: nums) freq[it]++;

        vector<int> ans(2, 0);
        for(int i = 1; i <= n; i++) {
            if(freq[i] == 2) ans[0] = i;
            if(freq[i] == 0) ans[1] = i;
        }
        
        return ans;
    }
};

// Sorted Nums maths Based Solution:
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));   // works for only sorted values:

        int idealSum = 0;
        int totalSum = 0;
        int dup = 1;    // considering default dup as '1', because duplicate matching start from 'idx 1'
        for(int i = 0; i < n; i++) {
            idealSum += i + 1;
            totalSum += nums[i];
            if(i > 0 && nums[i] == nums[i - 1]) {   // finding duplicates:
                dup = nums[i];
            }
        }

        vector<int> ans;
        if(totalSum < idealSum) {
            return {dup, dup + (idealSum % totalSum)};
        }

        return {dup, dup - (totalSum % idealSum)};
    }
};