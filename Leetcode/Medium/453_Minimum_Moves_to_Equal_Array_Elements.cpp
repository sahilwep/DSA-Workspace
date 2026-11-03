/*

//  453. Minimum Moves to Equal Array Elements


//  Problem Statement: 
    - Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
    - In one move, you can increment n - 1 elements of the array by 1.

 

// Example:
    Example 1:
        Input: nums = [1,2,3]
        Output: 3
        Explanation: Only three moves are needed (remember each move increments two elements):
        [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

    Example 2:
        Input: nums = [1,1,1]
        Output: 0

 
// Constraints:
    n == nums.length
    1 <= nums.length <= 1e5
    -1e9 <= nums[i] <= 1e9
    The answer is guaranteed to fit in a 32-bit integer.


// Observations:
    - given nums of size n,
    - we will have to return the minimum number of moves required to make all array element equal.
    - In one move: we can increment n-1 element of the array by 1.

    // Approach:
        - If we observe carefully:
            - we always greedy pick the minimum value at every move and left the max value, if we have more than one maximum value, we keep it as it is.
            - If we compute the difference b/w all the element from the minimum value:
                - that's exactly the number of moves required to make all array element equal.

        - In other words: increasing n - 1 elemnets by 1 is the same as decreasing one element by 1, because only the gaps b/w element that matters.
        - Our goal becomes bringing every element down to the smallest value, since the minimum can never be pushed lower than the rest.
        - Each element x therefore needs x - min moves, and the answer is the sum of these differences.

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

        int minEl = *min_element(begin(nums), end(nums));
        
        int cnt = 0;
        for(auto &num: nums) {
            cnt += num - minEl;
        }

        return cnt;
    }
};
