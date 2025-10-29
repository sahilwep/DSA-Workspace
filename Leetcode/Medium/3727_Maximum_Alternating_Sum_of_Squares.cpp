/*

//  3727. Maximum Alternating Sum of Squares


//  Problem Statement: 
    -> You are given an integer array nums. You may rearrange the elements in any order.
    -> The alternating score of an array arr is defined as:
        -> score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ...
    -> Return an integer denoting the maximum possible alternating score of nums after rearranging its elements.

 
// Example: 
    Example 1:
        Input: nums = [1,2,3]
        Output: 12
        Explanation:
            A possible rearrangement for nums is [2,1,3], which gives the maximum alternating score among all possible rearrangements.
            The alternating score is calculated as:
            score = 22 - 12 + 32 = 4 - 1 + 9 = 12

    Example 2:
        Input: nums = [1,-1,2,-2,3,-3]
        Output: 16
        Explanation:
            A possible rearrangement for nums is [-3,-1,-2,1,3,2], which gives the maximum alternating score among all possible rearrangements.
            The alternating score is calculated as:
            score = (-3)2 - (-1)2 + (-2)2 - (1)2 + (3)2 - (2)2 = 9 - 1 + 4 - 1 + 9 - 4 = 16


// Observations: 
    - If we observe carefully, Only way we can get maximum possible is: LargerVal - MinimumVal
    - From this idea, we can build our answer..
    - When we square negative value, it become positive.
    - To make value as maximum as possible
    - We will get maxVal - minVal => gives minimum diff as possible.
        sum += nums[lastVal] - nums[firstVal] + ...
    - This will gives us maximum values as possible...

    // Approach: 
        - First make all the given (nums[i] > 0) positive
        - Sort all the values..
        - After that iterate half of the nums
        - get (lastElement - FirstElement) & compute & add it into our answer...
        - Iterate forward & sums up all the values:

        // Edge case: 
            - If we have total even count of elements in nums, everything works fine.
            - If we have odd sets of value, we will overCount/overProcess n/2th value
            - So, simple adds up after computing by checking nums size, if it's odd, then adds up: pos(nums[n/2], 2) into our answer...


// Complexity: 
    -> TC: O(n*logn)
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        // make all the numbers as positive:
        for(auto &it: nums) if(it < 0) it *= -1;

        sort(begin(nums), end(nums));   // sort all the values..


        // Generate answer:
        long long ans = 0;
        int i = 0;
        while(i < n/2) {
            int first = nums[i];
            int last = nums[n-i-1];
            
            ans += pow(last, 2) - pow(first, 2);
            i++;
        }

        // for odd numbers of values, add middle value, as it eliminated
        if(n % 2 != 0) {
            ans += pow(nums[n/2], 2);
        }

        return ans;        
    }
};