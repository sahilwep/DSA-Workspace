/*

//  3346. Maximum Frequency of an Element After Performing Operations I


//  Problem Statement: 
    -> You must perform an operation numOperations times on nums, where in each operation you:
    -> You are given an integer array nums and two integers k and numOperations.
        -> Select an index i that was not selected in any previous operations.
        -> Add an integer in the range [-k, k] to nums[i].
    -> Return the maximum possible
    -> of any element in nums after performing the operations.

 
// Example:
    Example 1:
        Input: nums = [1,4,5], k = 1, numOperations = 2
        Output: 2
        Explanation:
            We can achieve a maximum frequency of two by:
                Adding 0 to nums[1]. nums becomes [1, 4, 5].
                Adding -1 to nums[2]. nums becomes [1, 4, 4].

    Example 2:
        Input: nums = [5,11,20,20], k = 5, numOperations = 1
        Output: 2
        Explanation:
            We can achieve a maximum frequency of two by:
            Adding 0 to nums[1].

// Observations: 
    - We are given an array nums, where we can perform at most numOperations operations.
    - In one operation, we can choose an index i and change nums[i] to any value within range [nums[i] - k, nums[i] + k].
    - Our goal is to maximize the frequency of any integer in the array after performing at most numOperations.
    - In simpler terms — we want to make as many numbers as possible equal to the same value,
    - given that each number can shift up to ±k units, but we can only modify numOperations elements in total.


    // Solution: 
        - The solution uses a combination of frequency counting and prefix sums to achieve near-linear time complexity.
        - First, we compute a frequency array that stores how many times each number appears in the input. 
        - Then, we build a prefix sum array from this frequency data. 
        - The prefix sum allows us to quickly determine how many elements fall within any numerical range [L, R] in constant time.

        - For each potential target value i, we check how many elements can be converted into i by using the range [i – k, i + k]. 
        - This total count represents the pool of numbers that can potentially match the target after adjustment. 
        - Out of these, we can modify at most numOperations elements, so we calculate the maximum achievable frequency as the current frequency of i plus the minimum of (convertible elements, numOperations). 
        - Iterating over all possible targets gives us the global maximum frequency.



// Complexity:
    -> TC: O(maxEL + n), n = size of nums
    -> SC: O(maxEl)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        
        int n = nums.size();
        int maxEl = *max_element(begin(nums), end(nums));
        vector<int> freq(maxEl + 1, 0);
        for(auto &it: nums) freq[it]++;

        vector<int> cSum(maxEl + 1, 0);
        cSum[0] = freq[0];
        for(int i = 1; i < maxEl + 1; i++) {
            cSum[i] = cSum[i-1] + freq[i];
        }

        int maxFreq = 0;
        for(int i = 0; i < maxEl + 1; i++) {
            if(cSum[i] == 0) continue;

            int low = max(0, i - k);
            int high = min(i + k, maxEl);

            int totalCnt = cSum[high] - (low > 0 ? cSum[low - 1] : 0);

            int targetCnt = cSum[i] - (i > 0 ? cSum[i-1]: 0);

            int needConversion = totalCnt - targetCnt;

            int maxPossibleFreq = targetCnt + min(needConversion, numOperations);

            maxFreq = max(maxFreq, maxPossibleFreq);
        }

        return maxFreq;
    }
};