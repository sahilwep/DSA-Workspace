/*

//  215. Kth Largest Element in an Array


//  Problem Statement: 
    -> Given an integer array nums and an integer k, return the kth largest element in the array.
    -> Note that it is the kth largest element in the sorted order, not the kth distinct element.
    -> Can you solve it without sorting?


// Example: 

    Example 1:
        Input: nums = [3,2,1,5,6,4], k = 2
        Output: 5


    Example 2:
        Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
        Output: 4

// Observation: 

        [3,2,1,5,6,4], k = 2
        6 5 4 3 2 1 -> Sorted
          |
          kth

        [3,2,3,1,2,4,5,5,6], k = 4
        
        6 5 5 4 3 3 2 2 1   -> Sorted
              |
              kth


    -> We will be using priority heap.
    -> We will use max-heap
    -> priority heap store element in sorted fashion.


// Complexity:
    -> TC: O(k * log(n))
    -> SC: O(n)
        -> k = times search into heap.
        -> log(n), used to get the element from queue, as it stored into shorted fashion.
    -> BUT, in worse case: TC = O(n * log(n)), because we have to build priority queue.



*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> pq;
        for(auto &i: nums) pq.push(i);  // O(n)

        int i = 1;
        while(i <= k){ // runs at-most k times: O(k)
            if(i == k) break;
            pq.pop();
            i++;
        }

        int kthValue = pq.top();

        return kthValue;
    }
};