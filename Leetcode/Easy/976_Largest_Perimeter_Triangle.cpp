/*

//  976. Largest Perimeter Triangle


//  Problem Statement: 
    -> Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

 
// Example: 
    Example 1:
        Input: nums = [2,1,2]
        Output: 5
        Explanation: You can form a triangle with three side lengths: 1, 2, and 2.

    Example 2:
        Input: nums = [1,2,1,10]
        Output: 0
        Explanation: 
        You cannot use the side lengths 1, 1, and 2 to form a triangle.
        You cannot use the side lengths 1, 1, and 10 to form a triangle.
        You cannot use the side lengths 1, 2, and 10 to form a triangle.
        As we cannot use any three side lengths to form a triangle of non-zero area, we return 0.


// Observations:
    -> to form a valid triangle, with three sides a, b, and c (a >= b >= c), the triangle inequality states:
        a + b > c,  b + c > a,  a + c > b
    -> Since a >= b >= c, the most restrictive conditions is:
        b + c > a
    -> If this conditions satisfies, the other two automatically satisfies..
    -> we need to find largest possible perimeter, so we should try the longest sides first
    -> The key insights is if we sort the array in descending order, the first valid triangle will be our answer (largest parmenter).



    // Complexity:
        -> TC: O(n * log n)
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();

        sort(rbegin(nums), rend(nums));

        // Start checking for first largest triangle:
        for(int i = 0; i < n - 2; i++) {
            // Find valid triangle:
            if(nums[i] < nums[i + 1] + nums[i + 2]) {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        
        return 0;
    }
};