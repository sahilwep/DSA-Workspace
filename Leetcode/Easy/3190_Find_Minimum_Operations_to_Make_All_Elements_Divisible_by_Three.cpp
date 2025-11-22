/*

//   3190. Find Minimum Operations to Make All Elements Divisible by Three


Example 1:
    Input: nums = [1,2,3,4]
    Output: 3

    Explanation:

        All array elements can be made divisible by 3 using 3 operations:

            Subtract 1 from 1.
            Add 1 to 2.
            Subtract 1 from 4.

Example 2:
    Input: nums = [3,6,9]
    Output: 0


// Observations: 
    - given nums, we need to make all the nums[i] to divisible by 3
    - we need to return the minimum number of operations to make nums all elements divisible by 3.
    
    // Approach: 
        -> 1 2 [3] 4 5 [6] 7 8 [9], 10, 11, [12], 13, 14, [15], 16, 17, [18]
        -> One thing we can observe that if the number is not divisible by 3:
            -> it required exactly 1 steps to add/subtract so that it being able to divisible by 3
        
        -> In simple:
            -> if(nums[i] % 3 == 0) skip : else add '1' operations_cost

    // Complexity: 
        - TC: O(n)
        - SC: O(1)



*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int opr = 0;
        for(auto &it: nums) {
            if(it % 3 != 0) opr++;
        }

        return opr;
    }
};