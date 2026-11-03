/*

//  3736. Minimum Moves to Equal Array Elements III


//  Problem Statement: 
    - You are given an integer array nums.
    - In one move, you may increase the value of any single element nums[i] by 1.
    - Return the minimum total number of moves required so that all elements in nums become equal.

 
// Example:
    Example 1:
        Input: nums = [2,1,3]
        Output: 3
        Explanation:
            To make all elements equal:
                Increase nums[0] = 2 by 1 to make it 3.
                Increase nums[1] = 1 by 1 to make it 2.
                Increase nums[1] = 2 by 1 to make it 3.
            Now, all elements of nums are equal to 3. The minimum total moves is 3.

    Example 2:
        Input: nums = [4,4,5]
        Output: 2
        Explanation:
            To make all elements equal:
                Increase nums[0] = 4 by 1 to make it 5.
                Increase nums[1] = 4 by 1 to make it 5.
            Now, all elements of nums are equal to 5. The minimum total moves is 2.

        

// Constraints:
    1 <= nums.length <= 100
    1 <= nums[i] <= 100


// Observations:
    - given nums, and we will have to return the minimum number of increment so that all the element of an array equals.
    - Implement the given statement.
    - find the max Element from an array
        - get the difference from every nums[i]
        - return the cnt;


        // Complexity:
            - TC: O(n)
            - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();

        int mxEl = *max_element(begin(nums), end(nums));

        int cnt = 0;
        for(auto &i: nums) {
            cnt += abs(mxEl - i);
        }

        return cnt;
    }
};