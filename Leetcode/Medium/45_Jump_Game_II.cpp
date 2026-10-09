/*

//  45. Jump Game II


//  Problem Statement: 
    - You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.
    - Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:
        0 <= j <= nums[i] and
        i + j < n
    - Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

 
// Example:
    Example 1:
        Input: nums = [2,3,1,1,4]
        Output: 2
        Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

    Example 2:
        Input: nums = [2,3,0,1,4]
        Output: 2

        
// Constraints:
    1 <= nums.length <= 104
    0 <= nums[i] <= 1000
    It's guaranteed that you can reach nums[n - 1].



// Observations:
    - Given 0-idx array of integer nums of length n, you are initially positioned at index 0.
    - Each element nums[i] represent the maxLen of jumps forward jumps from the index i,
        - if you are index i: 
            - you can jumps to index (i + j) where:
                0 <= j <= nums[i]
                i + j < n

        - return the minimum number of jumps to reach the n - 1, 
        - Test case generate in such a way we can reach t index n - 1

    // Approach:
        - we will start from the index '0'
        - for each num[i], we can jump from 1 to {(i + j) < n && j <= nums[i]} and explore the possibility..
        - We can use recursive solution explore the possibility:
            - Decision tree:
                - from every idx:
                    we can explore from 1 to (i + j) < n && j < nums[i], the given conditions.
                - basically for every recursive call, we will have to write the iterate from 1 to given conditions..
                - and explore the number of step we will take.
                - and from all the explorations, we will have to pick the path that takes the minimum steps..

            // Base Conditions:
                - we are saying: 
                    if it reaches to n - 1, means path is correct
                    So, if it reaches to n - 1, we will return 0
                    else if it's exceed we can return INT_MAX, but it would not required to write exceed "n - 1" case

            // Decision Tree:
                - for every idx:
                    i to idx + j,
                    j  <= nums[idx] 

            - We can memoize this solution, as it has repetitive subproblem which is being computed.
        
        // Complexity:
            - TC: O(N^2)
            - SC: O(N)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Tabulation Solution:
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> t(n, INT_MAX);
        t[n - 1] = 0;   // reaching here will not count in step.

        for(int i = n - 2; i >= 0; i--) {
            for(int j = 1; (i + j) < n && j <= nums[i]; j++) {
                if(t[i + j] != INT_MAX) {
                    t[i] = min(t[i], 1 + t[i + j]);    
                }
            }
        }

        return t[0];
    }
};


// Recursive + memoization:
class Solution_M {
private:
    int n;
    vector<int> t;
    int solve(int i, vector<int>& nums) {
        if(i == n - 1) return 0;

        if(t[i] != -1) return t[i];

        int step = INT_MAX - 1;
        for(int j = 1; (i + j) < n && j <= nums[i]; j++) {
            step = min(step, 1 + solve(i + j, nums));
        }

        return t[i] = step;
    }
public:
    int jump(vector<int>& nums) {
        n = nums.size();

        t.resize(n + 1, -1);

        return solve(0, nums);
    }
};


