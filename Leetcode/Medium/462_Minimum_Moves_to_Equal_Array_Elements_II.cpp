/*

//  462. Minimum Moves to Equal Array Elements II


//  Problem Statement: 
    - Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
    - In one move, you can increment or decrement an element of the array by 1.
    - Test cases are designed so that the answer will fit in a 32-bit integer.

 
// Example:
    Example 1:
        Input: nums = [1,2,3]
        Output: 2
        Explanation: Only two moves are needed (remember each move increments or decrements one element):
            [1,2,3]  =>  [2,2,3]  =>  [2,2,2]

    Example 2:
        Input: nums = [1,10,2,9]
        Output: 16

        

// Constraints:
    n == nums.length
    1 <= nums.length <= 1e5
    -1e9 <= nums[i] <= 1e9



// Observations:
    - given array of nums of size n, return the minimum number of moves required to make all array elements equal.
    - In one move, you can increment or decrement an element of the array by 1.
    
    // Approach:

        Example:
            1, [2], 3
            2   2   3   increment
            2   2   2   decrement


        Example:
            1, 10, 2, 9

            1, 2, 9, 10

            2  2  9 10
            3  2  9 10
            3  3  9 10
            3  3  9 9
            3  3  9 8
            3  3  8 8
            3  4  8 8
            4  4  8 8
            4  4  7 8
            4  4  7 7
            4  4  6 7
            4  4  6 6
            4  5  6 6
            5  5  6 6
            5  5  5 6
            5  5  5 5

            Even sizes:
                both middle element sum / 2
                11/2 = 5

                5 is our saturation point:

                1, 2, 9, 10

                abs(5 - 1) = 4
                abs(5 - 2) = 3
                abs(5 - 9) = 4
                abs(5 - 10) = 5
                
                total = 16 steps
            
            Odd size:
                    1, [2], 3

                    mid = 2
                    
                    abs(2 - 1) = 1
                    abs(2 - 2) = 0
                    abs(2 - 3) = 1

                    total  = 2

        - Middle is the saturation point where our value take minimum value to reach.

        - So, basically, we will have to sort the element, and then check the size of array:
            - if it's odd:
                - get the middle value:
                    and subtract abs(mid - nums[i]) and add all the values to steps.

            - if it's even:
                - get the two middle value:
                    sums them and divide by 2, that's our middle point:
                    - then subtract abs(mid - nums[i]) and add all the values to the steps.


            // Complexity
                - TC: O(n * logn)
                - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));   // sort:
        
        // Get mid:
        int mid = -1;
        if(n % 2 == 0) {
            mid = (nums[n/2 - 1] + nums[n/2]) / 2;
        } else {
            mid = nums[n/2];
        }

        // calculate steps to reach mid:
        int step = 0;
        for(auto &num: nums) {
            step += abs(mid - num);
        }

        return step;
    }
};