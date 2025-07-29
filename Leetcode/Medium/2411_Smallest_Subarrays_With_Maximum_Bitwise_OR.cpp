/*

//  2411. Smallest Subarrays With Maximum Bitwise OR


//  Problem Statement: 
    -> You are given a 0-indexed array nums of length n, consisting of non-negative integers. For each index i from 0 to n - 1, you must determine the size of the minimum sized non-empty subarray of nums starting at i (inclusive) that has the maximum possible bitwise OR.
        -> In other words, let Bij be the bitwise OR of the subarray nums[i...j]. You need to find the smallest subarray starting at i, such that bitwise OR of this subarray is equal to max(Bik) where i <= k <= n - 1.
    -> The bitwise OR of an array is the bitwise OR of all the numbers in it.
    -> Return an integer array answer of size n where answer[i] is the length of the minimum sized subarray starting at i with maximum bitwise OR.
    -> A subarray is a contiguous non-empty sequence of elements within an array.

 
// Example: 
    Example 1:
        Input: nums = [1,0,2,1,3]
        Output: [3,3,2,2,1]
        Explanation:
        The maximum possible bitwise OR starting at any index is 3. 
        - Starting at index 0, the shortest subarray that yields it is [1,0,2].
        - Starting at index 1, the shortest subarray that yields the maximum bitwise OR is [0,2,1].
        - Starting at index 2, the shortest subarray that yields the maximum bitwise OR is [2,1].
        - Starting at index 3, the shortest subarray that yields the maximum bitwise OR is [1,3].
        - Starting at index 4, the shortest subarray that yields the maximum bitwise OR is [3].
        Therefore, we return [3,3,2,2,1]. 

    Example 2:
        Input: nums = [1,2]
        Output: [2,1]
        Explanation:
        Starting at index 0, the shortest subarray that yields the maximum bitwise OR is of length 2.
        Starting at index 1, the shortest subarray that yields the maximum bitwise OR is of length 1.
        Therefore, we return [2,1].


// Observations: 
    -> We are given an array with positive integers
    -> we need to find maximum possible Bitwise OR from an array.
    -> We need to return an array having, arr[i] is the size of minimum sized subarray starting at index 'i' with maximum bitwise OR


    // BruteForce Approach: 
        -> Maximum possible bitwise OR value is => take bitwise OR of whole array
        -> Try finding subarray for every index, and whenever we get maximum bitwise value, break out & store the size.

        // Complexity:
            -> TC: O(n^2)
            -> AS: O(1)





*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// BruteForce Solution:
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        // Generate BitWise OR for every index from right to left:
        int maxORVal = 0;
        vector<int> maxOR(n);
        for(int i = n - 1; i >= 0; i--) {
            maxORVal |= nums[i];
            maxOR[i] = maxORVal;
        }

        // Generate answer: 
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            int currMaxOR = maxOR[i];   // get the current maximum OR for this current index.

            // Find the size of subset having currMaxOR:
            int size = 0;
            int temp = 0;
            for(int j = i; j < n; j++) {
                temp |= nums[j];
                size++;

                if(temp == currMaxOR) break;
            }

            ans[i] = size;  // Store the size of subarray for this current index.
        }
        
        return ans;    
    }
};