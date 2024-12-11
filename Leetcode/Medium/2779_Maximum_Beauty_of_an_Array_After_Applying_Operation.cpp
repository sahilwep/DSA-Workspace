/*

//  2779. Maximum Beauty of an Array After Applying Operation


//  Problem Statement:
    * You are given a 0-indexed array nums and a non-negative integer k.
    * In one operation, you can do the following:
        * Choose an index i that hasn't been chosen before from the range [0, nums.length - 1].
        * Replace nums[i] with any integer from the range [nums[i] - k, nums[i] + k].
    * The beauty of the array is the length of the longest subsequence consisting of equal elements.
    * Return the maximum possible beauty of the array nums after applying the operation any number of times.
    * Note that you can apply the operation to each index only once.
    * A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the order of the remaining elements.



// Example:

    Example 1:
        Input: nums = [4,6,1,2], k = 2
        Output: 3
        Explanation: In this example, we apply the following operations:
        - Choose index 1, replace it with 4 (from range [4,8]), nums = [4,4,1,2].
        - Choose index 3, replace it with 4 (from range [0,4]), nums = [4,4,1,4].
        After the applied operations, the beauty of the array nums is 3 (subsequence consisting of indices 0, 1, and 3).
        It can be proven that 3 is the maximum possible length we can achieve.

    Example 2:
        Input: nums = [1,1,1,1], k = 10
        Output: 4
        Explanation: In this example we don't have to apply any operations.
        The beauty of the array nums is 4 (whole array).



// Bruteforce Approach:
    -> This question is type of range based question:
        -> first get the range values of every nums[i]
        -> Hash all the ranges how many times they occur..
        -> return the frequency that has maximin.
        -> This gives TLE


// Efficient Solution:
    -> Break this question into intervals
    -> Sort them based on their starting point.
    -> We only need to see, before ending the first interval (a, b), whether our second interval (c, d) start or not?
        -> If (b < c), whether our second interval start before ending the first interval or not?
        -> Example:
                        Input: nums = [4,6,1,2], k = 2
                        Intervals: {(2, 6), (4, 8), (-1, 3), (0, 4)}
                        Sorted intervals:   {(-1, 3), (0, 4), (2, 6), (4, 6)}

                        -> Check whether the second interval start before ending the first interval or not?
                        -> Case:
                            ---------------
                            (-1, 3), (0, 4)
                            ---------------
                                 i    j

                                if (j < i)  -> Yes
                                result = 2

                        
                        -> Case:

                            -----------------------
                            (-1, 3), (0, 4), (2, 6)
                            -----------------------
                                 i            j
                                
                                if(j < i) -> yes
                                result = 3;
                        
                        -> Case:

                            -------------------------------
                            (-1, 3), (0, 4), (2, 6), (4, 6)
                            -------------------------------
                                 i                    j

                                if(j < i) -> No => move i pointer forward -> remove element from back

                            -----------------------
                             (0, 4), (2, 6), (4, 6)
                            -----------------------
                                 i            j
                                
                                if(j <= i) -> Yes
                                result = 3

                        -> At max we have 3 in result
                        -> This looks something like queue data-structure..
                        -> While j > i => remove element from queue
                        -> At every iteration we are getting the size of queue
                             
                            queue:
                                    --------------------
                                 <- pop                 <- push
                                    --------------------


// Intrusion: 
    -> Intervals type question, where we have some range given, where multiple values lies on that range, think of a solution based on:
        -> "Break it into Intervals, & sort them based on starting point"


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    // Function to calculate the maximum beauty value based on given conditions
    int maximumBeauty(vector<int>& nums, int k) {

        // First get all the range values of every nums[i]
        vector<pair<int, int>> range;
        for(int i = 0; i < nums.size(); i++) {
            range.push_back({nums[i] - k, nums[i] + k});
        }

        sort(begin(range), end(range)); // sort based on starting point
        int maxElement = 0;
        queue<pair<int, int>> q;

        for(int i = 0; i < range.size(); i++) {
            q.push({range[i].first, range[i].second});  // Push the current range into the queue

            // Remove ranges from the queue that do not overlap with the current range
            while(!q.empty() && q.front().second < range[i].first) {
                q.pop();
            }

            int size = q.size();
            maxElement = max(maxElement, size); // Update the maximum number of overlapping ranges
        }

        return maxElement;
    }
};



// BruteForce Solution:
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {

        // First get all the range values of every nums[i]
        vector<pair<int, int>> range;
        for(int i=0;i<nums.size();i++){
            range.push_back({nums[i]-k, nums[i]+k});
        }

        // hash all possible range:
        unordered_map<int, int> mp;
        for(int i=0;i<range.size();i++){    // this iterate in nums[i] size range: O(n)
            int start = range[i].first;
            int end = range[i].second;

            // hashing all possible ranges:     // this will again iterate in O(n) in worse case
            for(int j=start;j<=end;j++){
                mp[j]++;
            }
        }
        
        // Getting the maximum frequency from the range
        int maxNum = INT_MIN;
        for(auto i: mp){
            maxNum = max(maxNum, i.second);
        } 
    
        return maxNum;
    }
};