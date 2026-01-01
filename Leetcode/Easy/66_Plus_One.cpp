/*

//  66. Plus One


//  Problem Statement: 
    - You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
    - Increment the large integer by one and return the resulting array of digits.

 
// Example:
    Example 1:
        Input: digits = [1,2,3]
        Output: [1,2,4]
        Explanation: The array represents the integer 123.
        Incrementing by one gives 123 + 1 = 124.
        Thus, the result should be [1,2,4].

    Example 2:
        Input: digits = [4,3,2,1]
        Output: [4,3,2,2]
        Explanation: The array represents the integer 4321.
        Incrementing by one gives 4321 + 1 = 4322.
        Thus, the result should be [4,3,2,2].

    Example 3:
        Input: digits = [9]
        Output: [1,0]
        Explanation: The array represents the integer 9.
        Incrementing by one gives 9 + 1 = 10.
        Thus, the result should be [1,0].


// Observations: 
    - We need to extract digits & increment the last digit & return the whole value ans vector<int> ans.

    // Approach:
        - Get the digits[i] & store it into as whole number grouping.
        - add + 1 into num.
        - extract digit by digit & push it into answer.
        - reverse the answer list.
        
        // Complexity:
            - TC: O(digits.size() + log10(num))
            - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int num = 0;
        for(auto &i: digits) {
            num = (num * 10) + i;
        }

        num += 1;   // add last value.
        
        vector<int> ans;
        while(num > 0) {
            ans.push_back(num % 10);    // push last digit.
            num /= 10;                  // remove the last digit.
        }

        reverse(begin(ans), end(ans));  // reverse the answer, so that it should be in order.

        return ans;
    }
};