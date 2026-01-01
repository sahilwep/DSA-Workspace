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
        - Iterate from backwords:
            - Check if current idx is n-1: Only increment that
            - Check if current value is "10"
                - make that as '0'
                - if(idx > 0): prevValue++;
                - else: we are 0th idx & current value is '10'
                    - push '0' at last of digit
                    - make curr value as 1


        // Edge case:
            [9, 9]              ->      [1, 0, 0]
            [1, 9, 9, 9, 9]     ->      [2, 9, 9, 9, 9]

        
        // Complexity:
            - TC: O(digits.size())
            - SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    typedef long long ll;
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for(int i = n - 1; i >= 0; i--) {
            if(i == n - 1) {
                digits[i]++;     // increment last digit
            }

            if(digits[i] == 10) {
                digits[i] = 0;   // set current value as '0'
                
                if(i != 0) {    // if we are not at the 0th index:
                    digits[i-1]++;
                } else {    // edge case when 0th index is also '10'
                    digits.push_back(0);   // add 0 to last
                    digits[i] = 1;
                }
            } 
        }

        return digits;
    }
};