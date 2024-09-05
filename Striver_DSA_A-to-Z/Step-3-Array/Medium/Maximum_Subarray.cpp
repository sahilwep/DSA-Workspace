/*

// 53. Maximum Subarray


// Observations: 
    * We are given an array, we need to find the maximum sum of subarray that has largest value.


// Kadane's Algorithm: 
    * The idea is of kadane's algorithm is to maintain a variable "maxEndingHere" that store the maximum sum contigious subarray ending ending at the current index.
    * And a variable "maxSoFar" that stores the sum of contagious subarray found so far.
    * Everytime there is positive sum value in maxEndingHere, compare it with "maxSoFar" and update "maxSoFar" if it's is grater than "maxSoFar".
    // Intrusion behind the algorithm:
        * Subarray with negative sum will be discarded(by assigning max_ending_here = 0 in code).
        * We will carry subarray till it gives positive sum.

// Example Observations: 
        a[] = {-2, -3, 4, -1, -2, 1, 5, 3}

    Variables:
        maxEndingHere: This will track the maximum sum of the subarray that ends at the current position.
        maxSoFar: This will store the maximum sum found so far in the entire array.

    Step-by-Step Execution:

        Initial Values:
            maxEndingHere = 0
            maxSoFar = INT_MIN (This is a placeholder for the smallest possible integer value.)

        Iteration 1 (i = 0, a[0] = -2):
            maxEndingHere = maxEndingHere + a[0] = 0 + (-2) = -2
            maxSoFar = max(maxSoFar, maxEndingHere) = max(INT_MIN, -2) = -2
            Since maxEndingHere is negative, reset it to 0: maxEndingHere = max(maxEndingHere, 0) = max(-2, 0) = 0

        Iteration 2 (i = 1, a[1] = -3):
            maxEndingHere = maxEndingHere + a[1] = 0 + (-3) = -3
            maxSoFar = max(maxSoFar, maxEndingHere) = max(-2, -3) = -2
            Again, reset maxEndingHere to 0: maxEndingHere = max(maxEndingHere, 0) = max(-3, 0) = 0

        Iteration 3 (i = 2, a[2] = 4):
            maxEndingHere = maxEndingHere + a[2] = 0 + 4 = 4
            maxSoFar = max(maxSoFar, maxEndingHere) = max(-2, 4) = 4
            maxEndingHere remains positive: maxEndingHere = max(maxEndingHere, 0) = max(4, 0) = 4

        Iteration 4 (i = 3, a[3] = -1):
            maxEndingHere = maxEndingHere + a[3] = 4 + (-1) = 3
            maxSoFar = max(maxSoFar, maxEndingHere) = max(4, 3) = 4
            maxEndingHere remains positive: maxEndingHere = max(maxEndingHere, 0) = max(3, 0) = 3

        Iteration 5 (i = 4, a[4] = -2):
            maxEndingHere = maxEndingHere + a[4] = 3 + (-2) = 1
            maxSoFar = max(maxSoFar, maxEndingHere) = max(4, 1) = 4
            maxEndingHere remains positive: maxEndingHere = max(maxEndingHere, 0) = max(1, 0) = 1

        Iteration 6 (i = 5, a[5] = 1):
            maxEndingHere = maxEndingHere + a[5] = 1 + 1 = 2
            maxSoFar = max(maxSoFar, maxEndingHere) = max(4, 2) = 4
            maxEndingHere remains positive: maxEndingHere = max(maxEndingHere, 0) = max(2, 0) = 2

        Iteration 7 (i = 6, a[6] = 5):
            maxEndingHere = maxEndingHere + a[6] = 2 + 5 = 7
            maxSoFar = max(maxSoFar, maxEndingHere) = max(4, 7) = 7
            maxEndingHere remains positive: maxEndingHere = max(maxEndingHere, 0) = max(7, 0) = 7

        Iteration 8 (i = 7, a[7] = 3):
            maxEndingHere = maxEndingHere + a[7] = 7 + 3 = 10
            maxSoFar = max(maxSoFar, maxEndingHere) = max(7, 10) = 10
            maxEndingHere remains positive: maxEndingHere = max(maxEndingHere, 0) = max(10, 0) = 10

    Final Result:
        The maximum sum of a subarray is maxSoFar = 10.
    Subarray:
        The subarray that gives this maximum sum is [4, -1, -2, 1, 5, 3], which sums to 10.


// Why Kadane's Algorithm Works:
    * Positive Accumulation:
        * The algorithm efficiently accumulates positive contributions to the subarray's sum while discarding negative subarrays that would diminish the overall sum.
    * Reset Mechanism: 
        * The resetting of maxEndingHere ensures that we do not carry forward negative sums, which helps in identifying potential new subarrays that might yield a higher sum.
    * Greedy Approach: 
        * By always comparing the current maximum (maxEndingHere) to the global maximum (maxSoFar), the algorithm greedily chooses the highest possible sum at each step.
    * This makes Kadane's Algorithm both intuitive and powerful for finding the maximum sum subarray in O(n) time, where n is the size of the array.

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSoFar = INT_MIN;
        int maxEndingHere = 0;
        
        for(int i=0;i<n;i++){
            // at every iteartion we will add arr[i] into maxEndingHere
            maxEndingHere += nums[i];
            
            // at every time we will sotre the maximum value in maxSoFar
            maxSoFar = max(maxSoFar, maxEndingHere);
            
            // If values of maxEndingHere goes negative, it will assign as '0'
            maxEndingHere = max(maxEndingHere, 0);
        }
        
        return maxSoFar;
    }
};