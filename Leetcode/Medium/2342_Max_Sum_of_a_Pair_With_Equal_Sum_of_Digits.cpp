/*

//  2342. Max Sum of a Pair With Equal Sum of Digits

//  Problem Statement: 
    -> You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].
    -> Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.


// Example:

    Example 1:
        Input: nums = [18,43,36,13,7]
        Output: 54
        Explanation: The pairs (i, j) that satisfy the conditions are:
        - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
        - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
        So the maximum sum that we can obtain is 54.

    Example 2:
        Input: nums = [10,12,19,14]
        Output: -1
        Explanation: There are no two numbers that satisfy the conditions, so we return -1.


// Observation:
    -> We are given an array of integers called nums.
    -> We need to find pairs of numbers from the array such that:
            - The sum of their digits is equal.
            - The sum of the numbers in the pair is the maximum among all such pairs.
    -> If no such pair exists, return -1.


// Approach:
    -> First, calculate the sum of digits for every number in the array.
    -> Use a hash map to keep track of the maximum number encountered for each digit sum.
    -> For each number:
            - Check if its digit sum already exists in the map.
            - If it exists:
            - Calculate the sum of this number and the previously stored number for the same digit sum.
            - Update the maximum sum if the current pair's sum is greater.
            - Store the larger number of the two in the map for future pairings.
            - If it doesn't exist:
            - Store the current number as the maximum for this digit sum.
    -> Finally, return the maximum sum obtained or -1 if no valid pairs are found.


// Example:
    nums = [409, 463, 523, 142]
    
    Step 1: Calculate digit sums:
        409 -> 4 + 0 + 9 = 13
        463 -> 4 + 6 + 3 = 13
        523 -> 5 + 2 + 3 = 10
        142 -> 1 + 4 + 2 = 7
    
    Step 2: Store in map and check pairs:
        - Both 409 and 463 have a digit sum of 13.
        - Sum of 409 + 463 = 872.
        - This is the maximum sum for digit sum 13.
    
    Step 3: Return 872 as the result.



// Complexity: 
    -> TC: O(n * d) => O(n)
        -> n = number of elements in the array
        -> d = maximum number of digits in any number, 
        -> O(n), because from given constrains: (1 >= nums[i] >= 10^9), numbers at max up till 9-digits.
    -> SC: O(n), because of map


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    int digitSum(int x) {   
        int sum = 0;
        while (x > 0) {
            int lastDigit = x % 10;  // Get the last digit
            sum += lastDigit;        // Add to the sum
            x = x / 10;              // Remove the last digit
        }

        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        // Map to store the maximum number encountered for each digit sum
        unordered_map<int, int> digitSumMap;

        int maxSum = -1;  // Initialize the maximum sum to -1 (default if no pairs are found)
        
        // Iterate through each number in the array
        for (int i = 0; i < n; i++) {
            int num = nums[i];  // get the number from array
            int dSum = digitSum(num);  // Calculate the digit sum of the current number

            // Check if the current digit sum is already in the map
            if (digitSumMap.find(dSum) != digitSumMap.end()) {
                // If found, get the previously stored number with the same digit sum
                int previousNum = digitSumMap[dSum];
                
                // Calculate the sum of the current and previous number
                maxSum = max(maxSum, (previousNum + num));

                // Update the map to store the larger number for future pairs
                if (num > previousNum) {
                    digitSumMap[dSum] = num;
                }
            }
            else {   
                // If not found, store the current number for this digit sum
                digitSumMap[dSum] = num;
            }
        }

        return maxSum;
    }
};