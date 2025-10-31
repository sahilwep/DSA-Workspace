/*

//  3229. Minimum Operations to Make Array Equal to Target


//  Problem Statement: 
    -> You are given two positive integer arrays nums and target, of the same length.
    -> In a single operation, you can select any subarray of nums and increment each element within that subarray by 1 or decrement each element within that subarray by 1.
    -> Return the minimum number of operations required to make nums equal to the array target.

 
// Example:
    Example 1:
        Input: nums = [3,5,1,2], target = [4,6,2,4]
        Output: 2
        Explanation:
            We will perform the following operations to make nums equal to target:
            - Increment nums[0..3] by 1, nums = [4,6,2,3].
            - Increment nums[3..3] by 1, nums = [4,6,2,4].

    Example 2:
        Input: nums = [1,3,2], target = [2,1,4]
        Output: 5
        Explanation:
            We will perform the following operations to make nums equal to target:
            - Increment nums[0..0] by 1, nums = [2,3,2].
            - Decrement nums[1..1] by 1, nums = [2,2,2].
            - Decrement nums[1..1] by 1, nums = [2,1,2].
            - Increment nums[2..2] by 1, nums = [2,1,3].
            - Increment nums[2..2] by 1, nums = [2,1,4].


// Observations: 
    - We are given nums & target, we need to convert the given nums into target.
    - in one operations we can select any subarray of nums, & increment or decrement any element by '1'
    - return the minimum number of operations required to make nums equal to the array target.

    // Approach: 
        - Try getting what we need
        - Example: 
            Input: nums = [3,5,1,2], target = [4,6,2,4]

                    target -> 4 6 2 2
                    nums   -> 3 5 1 4
                          --------------
                              1 1 1 2   -> Difference
                        
        - If we think in other way around: 
            diff -> [1 1 1 2]  -> this is the difference which we need to remove in order to convert nums to target..
                    
            final_Target -> [0 0 0 0]  -> we can also say we need to remove diff & make all '0' in order to convert "nums" to "target", Think in reverse way..
                
                    
        - So, we can say, if we get "diff" from {target - nums}, & diff is the value which we have to remove in order to achieve target,
        - In Simple, we are given initially diff & we have to add or subtract +1/-1 in order to achieve all '0'
        - This type of question we have already solved: "1526. Minimum Number of Increments on Subarrays to Form a Target Array"
        - Here we also do the same approach, it's just we need to take care of negative values from diff, rest are same.e.e

        // Complexity:
            -> TC: O(n)
            -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    typedef long long ll;
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = target.size();

        ll opr = 0;
        int prev = 0;
        for(int i = 0; i < n; i++) {
            int curr = target[i] - nums[i];

            // Sign change:
            if((curr > 0 && prev < 0) || (curr < 0 && prev > 0 )) {
                opr += abs(curr);
            } else if(abs(curr) > abs(prev)) {
                opr += abs(curr - prev);
            }

            prev = curr;
        }

        return opr;
    }
};