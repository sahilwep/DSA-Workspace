/*

//  2294. Partition Array Such That Maximum Difference Is K


//  Problem Statement: 
    -> You are given an integer array nums and an integer k. You may partition nums into one or more subsequences such that each element in nums appears in exactly one of the subsequences.
    -> Return the minimum number of subsequences needed such that the difference between the maximum and minimum values in each subsequence is at most k.
    -> A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

//  Example: 

    Example 1:
        Input: nums = [3,6,1,2,5], k = 2
        Output: 2
        Explanation:
        We can partition nums into the two subsequences [3,1,2] and [6,5].
        The difference between the maximum and minimum value in the first subsequence is 3 - 1 = 2.
        The difference between the maximum and minimum value in the second subsequence is 6 - 5 = 1.
        Since two subsequences were created, we return 2. It can be shown that 2 is the minimum number of subsequences needed.

    Example 2:
        Input: nums = [1,2,3], k = 1
        Output: 2
        Explanation:
        We can partition nums into the two subsequences [1,2] and [3].
        The difference between the maximum and minimum value in the first subsequence is 2 - 1 = 1.
        The difference between the maximum and minimum value in the second subsequence is 3 - 3 = 0.
        Since two subsequences were created, we return 2. Note that another optimal solution is to partition nums into the two subsequences [1] and [2,3].

    Example 3:
        Input: nums = [2,2,4,5], k = 0
        Output: 3
        Explanation:
        We can partition nums into the three subsequences [2,2], [4], and [5].
        The difference between the maximum and minimum value in the first subsequences is 2 - 2 = 0.
        The difference between the maximum and minimum value in the second subsequences is 4 - 4 = 0.
        The difference between the maximum and minimum value in the third subsequences is 5 - 5 = 0.
        Since three subsequences were created, we return 3. It can be shown that 3 is the minimum number of subsequences needed.


// Observations:
    -> Let's observe with example:

        Example: [3,6,1,2,5], k = 2

            Sorted: [1, 2, 3, 5, 6], k = 2

            -> form: [1, 2, 3], [5, 6] => 2


        Example: [2,2,4,5], k = 0

            Sorted: [2, 2, 4, 5]
            
            -> form: [2, 2], [4], [5]

        // Approach: 
            -> Sort the values, 
            -> Use starting & ending pointer
                -> till the conditions satisfies, move the pointer & increase the element count in subsequence
                -> When the conditions violates, break out, & build the subsequence & ready to buid new one. 

                // Complexity: 
                    -> TC: O((N * log(N)) + N) =>  O(N * log(N)
                    -> SC: O(1)

        // Optimization: Binary Search 
            -> for every minimum value we are incrementing 'j', & we are incrementing till the last value for which the conditions satisfies.
            -> We are doing this linearly, we can optimize this by using Binary Search
            -> We are doing: 
                    nums[high] - nums[low] <= k
                    nums[high] <= nums[low] + k 
                    
                    So, To find the maximum "nums[high]", target will be "nums[low] + k"

                // Complexity: 
                    -> TC: O((N * log(N)) + (G * log(N))) =>  O(N * log(N)
                        -> G = Number of group.
                    -> SC: O(1)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Optimized: Binary Search
class Solution {
private: 
    int n;
    // binary search on answer: To find next groups starting index
    int getNext(vector<int>& nums, int k, int target) { 
        int low = 0;
        int high = n - 1;
        int ans = n;    // answer will be the nth value which is our maximum in case:

        while(low <= high) {
            int mid = (low + high) / 2;

            // If we have exceed the target, move left to find the start of the next partition where nums[j] > nums[i] + k.
            if(nums[mid] > target) {
                high = mid - 1; // candidate for next group start
                ans = mid;      // search for smaller valid index
            }
            else {  // We are in range, move right to find the starting of the next partitions.
                low = mid + 1;
            }
        }

        return ans;
    }

public:
    int partitionArray(vector<int>& nums, int k) {
        n = nums.size();

        sort(begin(nums), end(nums));   // sort the given numbers

        int i = 0;
        int ans = 0;
        
        // Iterate in nums:
        while(i < n) {
            ans++;  // increment count
            i = getNext(nums, k, nums[i] + k); // Find starting index for next groups
        }
        
        return ans;
    }
};


// Naive: Linear Search
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int i = 0, j = 0;
        int ans = 0;
        while(j < n) {
            // If Conditions satisfies:
            if(nums[j] - nums[i] <= k) {
                j++;    // move right pointers
            } 
            else {
                ans++;  // build answer:
                i = j;
                j++;
            }
        }

        ans++;  // increment the last group.
        
        return ans;
    }
};