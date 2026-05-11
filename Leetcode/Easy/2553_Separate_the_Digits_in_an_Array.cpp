/*

//  2553. Separate the Digits in an Array


//  Problem Statement: 
    - Given an array of positive integers nums, return an array answer that consists of the digits of each integer in nums after separating them in the same order they appear in nums.
    - To separate the digits of an integer is to get all the digits it has in the same order.
        - For example, for the integer 10921, the separation of its digits is [1,0,9,2,1].

 
// Example: 
    Example 1:

    Input: nums = [13,25,83,77]
    Output: [1,3,2,5,8,3,7,7]
    Explanation: 
    - The separation of 13 is [1,3].
    - The separation of 25 is [2,5].
    - The separation of 83 is [8,3].
    - The separation of 77 is [7,7].
    answer = [1,3,2,5,8,3,7,7]. Note that answer contains the separations in the same order.

    Example 2:

    Input: nums = [7,1,3,9]
    Output: [7,1,3,9]
    Explanation: The separation of each integer in nums is itself.
    answer = [7,1,3,9].

// Observations:
    - Given nums, we need to separate the digits.
    
    // Approach 1:
        - Implement the given statements.
        - Get the num, extract the digits and push into answer.

        // Complexity:
            - TC: O(n * max(d))
                - d = num size
                - n = nums
            - SC: O(n)

    
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Approach 1:
class Solution {
private:
    vector<int> getDigits(int num) {
        vector<int> res;
        
        while(num > 0) {
            int ld = num % 10;
            num /= 10;

            res.push_back(ld);
        }

        reverse(begin(res), end(res));

        return res;
    }
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans;
        for(auto &num: nums) {
            vector<int> temp = getDigits(num);
            for(auto &it: temp) {
                ans.push_back(it);
            }
        }

        return ans;
    }
};