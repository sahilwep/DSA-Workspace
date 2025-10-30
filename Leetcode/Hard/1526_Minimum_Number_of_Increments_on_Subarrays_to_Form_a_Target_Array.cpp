/*

//  1526. Minimum Number of Increments on Subarrays to Form a Target Array


//  Problem Statement: 
    -> You are given an integer array target. You have an integer array initial of the same size as target with all elements initially zeros.
    -> In one operation you can choose any subarray from initial and increment each value by one.
    -> Return the minimum number of operations to form a target array from initial.
    -> The test cases are generated so that the answer fits in a 32-bit integer.

 
//  Example: 
    Example 1:
        Input: target = [1,2,3,2,1]
        Output: 3
        Explanation: We need at least 3 operations to form the target array from the initial array.
        [0,0,0,0,0] increment 1 from index 0 to 4 (inclusive).
        [1,1,1,1,1] increment 1 from index 1 to 3 (inclusive).
        [1,2,2,2,1] increment 1 at index 2.
        [1,2,3,2,1] target array is formed.

    Example 2:
        Input: target = [3,1,1,2]
        Output: 4
        Explanation: [0,0,0,0] -> [1,1,1,1] -> [1,1,1,2] -> [2,1,1,2] -> [3,1,1,2]

    Example 3:
        Input: target = [3,1,5,4,2]
        Output: 7
        Explanation: [0,0,0,0,0] -> [1,1,1,1,1] -> [2,1,1,1,1] -> [3,1,1,1,1] -> [3,1,2,2,2] -> [3,1,3,3,2] -> [3,1,4,4,2] -> [3,1,5,4,2].

        
// Observations: 
    - We are given a target array & there's an initial array with same size of target with all the value '0',
    - We need to find the minimum number of increment in initial to make inital equal to target..

    // Approach: 
        - If we think in other way around, it's simple we need to find the minimum number of operations to make given target equal to '0', it's same as initial making target..
        - Observe the given example in x-y plain
        - We will observe the mark with increasing-decreasing pattern:
            - When curr > prev => operations needed.
            - When curr <= prev => no operations needed.
        - Iterating & simply comparing the slope will give us the number of operations..


// Complexity: 
    - TC: O(n)
    - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();

        int opr = 0;
        int prev = 0;
        for(int i = 0; i < n; i++) {
            int curr = target[i];

            // If we are at increasing slop:
            if(curr > prev) {
                opr += curr - prev;     // operations need
            }

            prev = curr; 
        }

        return opr;
    }
};