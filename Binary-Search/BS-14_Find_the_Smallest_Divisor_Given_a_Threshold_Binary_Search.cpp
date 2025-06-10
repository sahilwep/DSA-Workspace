/*

//   BS-14. Find the Smallest Divisor Given a Threshold | Binary Search 


//  Problem Statement:
    -> Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
    -> Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
    -> The test cases are generated so that there will be an answer.

 
// Example: 
    Example 1:
        Input: nums = [1,2,5,9], threshold = 6
        Output: 5
        Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
        If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 

    Example 2:
        Input: nums = [44,22,33,11,1], threshold = 5
        Output: 44


// Observations: 
    -> Given an array & threshold value
    -> We have to choose a number divisor, on which dividing every number of array & sums up the result, we exactly get <= threshold value, then the conditions is true
    -> We have to find the smallest divisor on which the condition satisfies..
    -> We can start with range (1, to max_element) & try checking out conditions.
        -> starting range is 1, because dividing everything with 1 will give us maximum sum.
        -> Ending range is maxElement, because dividing everything with that number will give us the minimum sum.
    -> Start iterating in range (1 to maxElement) & try out finding the minimum valid answer for which our conditions satisfies.    

        // Binary Search Solution: 
            -> Checking the above conditions with  binary search will improve the complexity.


    // Complexity: 
        -> TC: O(log(max_element(nums) * N))
            -> N = nums.size();
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution: Binary Search
class Solution {
private: 
    bool isDivisible(vector<int>& nums, int thr, int div) {     // function to check the given conditions: 
        int sum = 0;
        for(auto& num: nums) {
            double temp = (double)num / (double)div;
            sum += ceil(temp);
        }

        return (sum <= thr);
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int low = 1;    // lowest value, which will gives us maximum sum
        int high = *max_element(begin(nums), end(nums));    // hightest value, which will give us lowest sum

        int ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;

            // divisible, return true: move left to get smaller value
            if(isDivisible(nums, threshold, mid)) {
                ans = mid;  // update answer 
                high = mid - 1; // look for more smaller value.
            } else {    // get false: move right to get true:
                low = mid + 1;
            }
        }

        return ans; 
    }
};


// BruteForce Solution: Linear Search
class Solution {
private: 
    bool isDivisible(vector<int>& nums, int thr, int div) {      // function to check the given conditions: 
        int sum = 0;
        for(auto& num: nums) {
            double temp = (double)num / (double)div;
            sum += ceil(temp);
        }

        return (sum <= thr);
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int low = 1;    // lowest value, which will gives us maximum sum
        int high = *max_element(begin(nums), end(nums));    // hightest value, which will give us lowest sum
        
        int ans = -1;
        for(int i = low; i <= high; i++) {
            if(isDivisible(nums, threshold, i)) {
                ans = i;
                break;
            }
        }

        return ans; 
    }
};